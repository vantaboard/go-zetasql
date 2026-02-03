package install

import (
	"errors"
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"strings"
)

const (
	// DefaultVersion is the default GoogleSQL artifact version (go-zetasql module version).
	// Override with InstallOptions.Version.
	DefaultVersion = "v0.0.0"
	modulePath     = "github.com/vantaboard/go-googlesql"
)

// InstallOptions configures the installer.
type InstallOptions struct {
	// CacheDir is where to download and extract artifacts. Default: platform cache (e.g. ~/.cache/go-zetasql).
	CacheDir string
	// Version is the go-zetasql version (e.g. v0.1.0). Used for download URL and cache path. Default: DefaultVersion.
	Version string
	// BaseURL is the base URL for downloads (e.g. GitHub releases). Default: empty (use GitHub API).
	BaseURL string
	// SkipIfPresent skips download if cache already has the correct version for this platform.
	SkipIfPresent bool
	// Verbose enables log output.
	Verbose bool
}

// Installer downloads and installs pre-built GoogleSQL artifacts.
type Installer struct {
	opts    *InstallOptions
	version string
}

// NewInstaller returns an installer with the given options. Defaults are applied.
func NewInstaller(opts *InstallOptions) *Installer {
	if opts == nil {
		opts = &InstallOptions{}
	}
	version := opts.Version
	if version == "" {
		version = DefaultVersion
	}
	if !strings.HasPrefix(version, "v") {
		version = "v" + version
	}
	return &Installer{opts: opts, version: version}
}

// Version returns the version the installer uses.
func (i *Installer) Version() string {
	return i.version
}

// Install downloads the tarball for the current GOOS/GOARCH and extracts it to the cache dir.
// Returns the path to the extracted ccall tree (cache/<version>/<platform>/ccall).
func (i *Installer) Install() (string, error) {
	cacheDir, err := i.cacheDir()
	if err != nil {
		return "", err
	}
	platform := platformString()
	extractDir := filepath.Join(cacheDir, i.version, platform)
	ccallDir := filepath.Join(extractDir, "ccall")

	if i.opts.SkipIfPresent {
		if _, err := os.Stat(filepath.Join(ccallDir, "go-zetasql")); err == nil {
			i.log("Using cached artifact", "path", ccallDir)
			return ccallDir, nil
		}
	}

	urls := i.getDownloadURLs()
	if len(urls) == 0 {
		return "", fmt.Errorf("no download URL for %s", platform)
	}
	i.log("Downloading GoogleSQL artifact", "version", i.version, "platform", platform)
	body, err := downloadTarball(urls)
	if err != nil {
		return "", err
	}
	if err := os.MkdirAll(extractDir, 0o755); err != nil {
		return "", fmt.Errorf("create extract dir: %w", err)
	}
	if err := extractTarGz(body, extractDir); err != nil {
		return "", err
	}
	if _, err := os.Stat(ccallDir); err != nil {
		return "", fmt.Errorf("extract did not produce ccall dir at %s: %w", ccallDir, err)
	}
	i.log("Downloaded and extracted", "path", ccallDir)
	return ccallDir, nil
}

// InstallToModule runs Install() then ensures modDir/internal/ccall exists, either as a symlink to the cache or a copy.
func (i *Installer) InstallToModule(modDir string) error {
	ccallDir, err := i.Install()
	if err != nil {
		return err
	}
	internalCcall := filepath.Join(modDir, "internal", "ccall")
	if err := os.MkdirAll(filepath.Dir(internalCcall), 0o755); err != nil {
		return fmt.Errorf("create internal dir: %w", err)
	}
	info, err := os.Lstat(internalCcall)
	if err == nil {
		if info.Mode()&os.ModeSymlink != 0 {
			linkDest, _ := os.Readlink(internalCcall)
			if linkDest == ccallDir {
				i.log("internal/ccall already linked to cache", "path", internalCcall)
				return nil
			}
		}
		if err := os.RemoveAll(internalCcall); err != nil {
			return fmt.Errorf("remove existing internal/ccall: %w", err)
		}
	}
	if err := os.Symlink(ccallDir, internalCcall); err != nil {
		return fmt.Errorf("symlink internal/ccall to cache: %w", err)
	}
	i.log("Linked internal/ccall to cache", "target", internalCcall)
	return nil
}

func (i *Installer) cacheDir() (string, error) {
	if i.opts.CacheDir != "" {
		return i.opts.CacheDir, nil
	}
	home, err := os.UserHomeDir()
	if err != nil {
		return "", fmt.Errorf("user home dir: %w", err)
	}
	switch runtime.GOOS {
	case "windows":
		return filepath.Join(home, "AppData", "Local", "go-zetasql"), nil
	case "darwin":
		return filepath.Join(home, "Library", "Caches", "go-zetasql"), nil
	case "linux":
		return filepath.Join(home, ".cache", "go-zetasql"), nil
	default:
		return filepath.Join(home, ".cache", "go-zetasql"), nil
	}
}

func platformString() string {
	switch runtime.GOOS {
	case "windows":
		return "windows-amd64"
	case "darwin":
		if runtime.GOARCH == "arm64" {
			return "darwin-arm64"
		}
		return "darwin-amd64"
	case "linux":
		if runtime.GOARCH == "arm64" {
			return "linux-arm64"
		}
		return "linux-amd64"
	default:
		return runtime.GOOS + "-" + runtime.GOARCH
	}
}

func (i *Installer) getDownloadURLs() []string {
	platform := platformString()
	name := fmt.Sprintf("zetasql-%s-%s.tar.gz", platform, i.version)
	if i.opts.BaseURL != "" {
		base := strings.TrimSuffix(i.opts.BaseURL, "/")
		return []string{base + "/" + name}
	}
	return []string{
		fmt.Sprintf("https://github.com/vantaboard/go-googlesql/releases/download/%s/%s", i.version, name),
	}
}

func (i *Installer) log(msg string, args ...any) {
	if i.opts.Verbose {
		if len(args) > 0 {
			fmt.Fprintf(os.Stderr, "[go-zetasql install] "+msg+" %v\n", args...)
		} else {
			fmt.Fprintln(os.Stderr, "[go-zetasql install] "+msg)
		}
	}
}

// ResolveModuleDir returns the directory of the go-zetasql module (e.g. in GOMODCACHE).
// It runs "go list -m -f '{{.Dir}}' github.com/vantaboard/go-googlesql" from the current directory.
func ResolveModuleDir() (string, error) {
	// Run from current dir so that if the user's project has go-zetasql in go.mod, we get that module's path.
	out, err := runGoList(modulePath, "{{.Dir}}")
	if err != nil {
		return "", fmt.Errorf("resolve go-zetasql module dir: %w", err)
	}
	dir := strings.TrimSpace(string(out))
	if dir == "" {
		return "", errors.New("go list returned empty Dir for go-zetasql")
	}
	return dir, nil
}

func runGoList(mod string, format string) ([]byte, error) {
	cmd := exec.Command("go", "list", "-m", "-f", format, mod)
	return cmd.Output()
}
