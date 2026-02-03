package main

import (
	"io"
	"io/fs"
	"os"
	"path/filepath"
	"runtime"
	"strings"

	cp "github.com/otiai10/copy"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

func cacheDir() string {
	return filepath.Join(pkgDir(), "cache")
}

func externalDir() string {
	return filepath.Join(cacheDir(), "external")
}

func execrootDir() string {
	return filepath.Join(cacheDir(), "execroot")
}

// discoverOutDir finds the bazel-out/.../bin directory under the single execroot.
// Bazel execroot name and config (e.g. k8-fastbuild) can vary.
func discoverOutDir() string {
	entries, err := os.ReadDir(execrootDir())
	if err != nil {
		panic(err)
	}
	var foundBin string
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		root := filepath.Join(execrootDir(), e.Name(), "bazel-out")
		_ = filepath.Walk(root, func(path string, info fs.FileInfo, err error) error {
			if err != nil || info == nil || !info.IsDir() || filepath.Base(path) != "bin" {
				return nil
			}
			foundBin = path
			return filepath.SkipAll
		})
		if foundBin != "" {
			return foundBin
		}
	}
	panic("no execroot/bazel-out/.../bin found under " + execrootDir())
}

func outExternalDir() string {
	return filepath.Join(discoverOutDir(), "external")
}

// discoverOutTree finds the workspace output dir under bin (e.g. googlesql or zetasql).
func discoverOutTree(binDir string) string {
	_, err := os.ReadDir(binDir)
	if err != nil {
		panic(err)
	}
	for _, name := range []string{"googlesql", "zetasql"} {
		p := filepath.Join(binDir, name)
		if st, err := os.Stat(p); err == nil && st.IsDir() {
			return name
		}
	}
	panic("no googlesql or zetasql dir under " + binDir)
}

var copyExternalLibMap = map[string]string{
	"icu/source":                "icu",
	"json":                      "json",
	"flex":                      "flex",
	"com_google_absl/absl":      "absl",
	"com_google_protobuf/src":   "protobuf",
	"com_googlesource_code_re2": "re2",
}

var copyOutExternalLibMap = map[string]string{
	"com_google_googleapis": "googleapis",
}

func main() {
	opt := cp.Options{
		AddPermission: 0o755,
		Skip: func(src string) (bool, error) {
			info, err := os.Stat(src)
			if err != nil {
				return false, err
			}
			if info.IsDir() {
				return false, nil
			}
			switch filepath.Base(src) {
			case "BUILD", "BUILD.bazel":
				return false, nil
			}
			switch filepath.Ext(src) {
			case ".h", ".hh", ".cc", ".c", ".inc":
				return false, nil
			}
			return true, nil
		},
	}
	for src, dst := range copyExternalLibMap {
		cp.Copy(
			filepath.Join(externalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	for src, dst := range copyOutExternalLibMap {
		cp.Copy(
			filepath.Join(outExternalDir(), src),
			filepath.Join(ccallDir(), dst),
			opt,
		)
	}
	// Upstream repo may have inner dir googlesql/ or zetasql/ (legacy)
	srcRoot := filepath.Join(pkgDir(), "googlesql")
	inner := "googlesql"
	if _, err := os.Stat(filepath.Join(srcRoot, "googlesql")); err != nil {
		if _, err := os.Stat(filepath.Join(srcRoot, "zetasql")); err == nil {
			inner = "zetasql"
		}
	}
	cp.Copy(
		filepath.Join(srcRoot, inner),
		filepath.Join(ccallDir(), "zetasql"),
		opt,
	)
	// Bazel output is under workspace-name/ (googlesql or zetasql); copy into ccall as zetasql/ for repo layout
	outDir := discoverOutDir()
	outTree := discoverOutTree(outDir)
	if err := filepath.Walk(
		filepath.Join(outDir, outTree),
		func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info == nil || info.IsDir() {
				return nil
			}
			if (info.Mode() & fs.ModeSymlink) != 0 {
				return nil
			}
			fileName := filepath.Base(path)
			lastChar := fileName[len(fileName)-1]
			if lastChar == 'h' || lastChar == 'c' {
				idx := strings.LastIndex(path, outTree)
				if idx < 0 {
					return nil
				}
				trimmedPath := "zetasql" + path[idx+len(outTree):]
				dstFile := filepath.Join(ccallDir(), trimmedPath)
				src, err := os.Open(path)
				if err != nil {
					return err
				}
				defer src.Close()
				dst, err := os.Create(dstFile)
				if err != nil {
					return err
				}
				defer dst.Close()
				if _, err := io.Copy(dst, src); err != nil {
					return err
				}
			}
			return nil
		},
	); err != nil {
		panic(err)
	}
}
