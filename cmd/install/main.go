package main

import (
	"flag"
	"fmt"
	"log"
	"os"

	"github.com/vantaboard/go-googlesql/install"
)

func main() {
	version := flag.String("version", install.DefaultVersion, "GoogleSQL artifact version (e.g. v0.1.0)")
	cacheDir := flag.String("cache-dir", "", "Cache directory for downloaded artifacts (default: platform cache)")
	baseURL := flag.String("base-url", "", "Base URL for downloads (overrides GitHub releases)")
	skipIfPresent := flag.Bool("skip-if-present", true, "Skip download if cache already has the correct version")
	verbose := flag.Bool("verbose", false, "Print progress")
	flag.Parse()

	if env := os.Getenv("ZETASQL_CACHE_DIR"); env != "" && *cacheDir == "" {
		*cacheDir = env
	}
	if env := os.Getenv("ZETASQL_DOWNLOAD_BASE_URL"); env != "" && *baseURL == "" {
		*baseURL = env
	}
	// Default version: use module version when available (consumer's go.mod), else DefaultVersion.
	if *version == install.DefaultVersion {
		if v := install.ResolveModuleVersion(); v != "" {
			*version = v
		}
	}

	opts := &install.InstallOptions{
		CacheDir:      *cacheDir,
		Version:       *version,
		BaseURL:       *baseURL,
		SkipIfPresent: *skipIfPresent,
		Verbose:       *verbose,
	}
	inst := install.NewInstaller(opts)

	modDir, err := install.ResolveModuleDir()
	if err != nil {
		log.Fatalf("could not resolve go-zetasql module dir: %v", err)
	}
	if err := inst.InstallToModule(modDir); err != nil {
		log.Fatalf("could not install GoogleSQL artifact: %v", err)
	}
	if *verbose {
		fmt.Fprintln(os.Stderr, "[go-zetasql install] Done. internal/ccall is linked to cache.")
	}
}
