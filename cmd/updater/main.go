package main

import (
	"fmt"
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

// discoverBazelOut finds the bazel-out directory under the single execroot (e.g. execroot/workspace/bazel-out).
func discoverBazelOut() string {
	entries, err := os.ReadDir(execrootDir())
	if err != nil {
		panic(err)
	}
	for _, e := range entries {
		if !e.IsDir() {
			continue
		}
		root := filepath.Join(execrootDir(), e.Name(), "bazel-out")
		if st, err := os.Stat(root); err == nil && st.IsDir() {
			return root
		}
	}
	panic("no execroot/.../bazel-out found under " + execrootDir())
}

// discoverOutDir finds a bazel-out/.../bin directory that contains workspace output (zetasql or googlesql).
// Prefer config-specific output (e.g. k8-fastbuild/bin) over host/bin, which often has fewer generated files.
func discoverOutDir() string {
	root := discoverBazelOut()
	var foundBin string
	_ = filepath.Walk(root, func(path string, info fs.FileInfo, err error) error {
		if err != nil || info == nil || !info.IsDir() || filepath.Base(path) != "bin" {
			return nil
		}
		// Skip host/bin; prefer config-specific output (e.g. k8-fastbuild/bin) which has the full generated tree.
		if filepath.Base(filepath.Dir(path)) == "host" {
			return nil
		}
		// Prefer a bin that has zetasql or googlesql with content (e.g. proto/).
		for _, name := range []string{"zetasql", "googlesql"} {
			protoDir := filepath.Join(path, name, "proto")
			if st, err := os.Stat(protoDir); err == nil && st.IsDir() {
				foundBin = path
				return filepath.SkipAll
			}
		}
		// Fallback: use first non-host bin we find.
		if foundBin == "" {
			foundBin = path
		}
		return nil
	})
	if foundBin != "" {
		return foundBin
	}
	panic("no bazel-out/.../bin (with zetasql or googlesql) found under " + root)
}

func outExternalDir() string {
	return filepath.Join(discoverOutDir(), "external")
}

// discoverOutTree finds the workspace output dir under bin (zetasql; googlesql after upstream rename ~2026).
func discoverOutTree(binDir string) string {
	_, err := os.ReadDir(binDir)
	if err != nil {
		panic(err)
	}
	for _, name := range []string{"zetasql", "googlesql"} {
		p := filepath.Join(binDir, name)
		if st, err := os.Stat(p); err == nil && st.IsDir() {
			return name
		}
	}
	panic("no zetasql (or googlesql) dir under " + binDir)
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
	// Upstream uses zetasql/ (not renamed to googlesql until ~2026). Copy to go-googlesql so Go import path internal/ccall/go-googlesql matches.
	srcRoot := filepath.Join(pkgDir(), "googlesql")
	inner := "zetasql"
	if _, err := os.Stat(filepath.Join(srcRoot, "zetasql")); err != nil {
		inner = "googlesql"
	}
	cp.Copy(
		filepath.Join(srcRoot, inner),
		filepath.Join(ccallDir(), "go-googlesql"),
		opt,
	)
	// Copy generated headers and sources from bazel-out (bin and genfiles) into ccall/go-googlesql/.
	// Generated files (e.g. resolved_ast.h, *.pb.h) are required for the CGo build.
	copyBazelOutToCcall := func(outDir string) {
		outTree := discoverOutTree(outDir)
		treePath := filepath.Join(outDir, outTree)
		if _, err := os.Stat(treePath); err != nil {
			return
		}
		var copied int
		_ = filepath.Walk(treePath, func(path string, info fs.FileInfo, err error) error {
			if err != nil || info == nil || info.IsDir() {
				return nil
			}
			if (info.Mode() & fs.ModeSymlink) != 0 {
				return nil
			}
			fileName := filepath.Base(path)
			lastChar := fileName[len(fileName)-1]
			if lastChar != 'h' && lastChar != 'c' {
				return nil
			}
			idx := strings.LastIndex(path, outTree)
			if idx < 0 {
				return nil
			}
			trimmedPath := "go-googlesql" + path[idx+len(outTree):]
			dstFile := filepath.Join(ccallDir(), trimmedPath)
			if err := os.MkdirAll(filepath.Dir(dstFile), 0o755); err != nil {
				return err
			}
			src, err := os.Open(path)
			if err != nil {
				return err
			}
			dst, err := os.Create(dstFile)
			if err != nil {
				src.Close()
				return err
			}
			_, err = io.Copy(dst, src)
			src.Close()
			dst.Close()
			if err == nil {
				copied++
			}
			return err
		})
	}
	copyBazelOutToCcall(discoverOutDir())
	// Some Bazel setups put generated protos in genfiles.
	bazelOut := discoverBazelOut()
	_ = filepath.Walk(bazelOut, func(path string, info fs.FileInfo, err error) error {
		if err != nil || info == nil || !info.IsDir() || filepath.Base(path) != "genfiles" {
			return nil
		}
		copyBazelOutToCcall(path)
		return filepath.SkipAll
	})

	// Fail fast if required generated files are missing (avoids opaque C++ errors later in make build).
	requiredFiles := []string{
		"go-googlesql/resolved_ast/resolved_ast.h",
		"go-googlesql/proto/internal_error_location.pb.h",
	}
	var missing []string
	for _, rel := range requiredFiles {
		if _, err := os.Stat(filepath.Join(ccallDir(), rel)); err != nil {
			missing = append(missing, rel)
		}
	}
	if len(missing) > 0 {
		for _, m := range missing {
			fmt.Fprintln(os.Stderr, "updater: missing required file:", m)
		}
		fmt.Fprintln(os.Stderr, "updater: required generated files missing after copy; run 'make export' and ensure Bazel built targets that produce resolved_ast.h (and other generated headers).")
		os.Exit(1)
	}
}
