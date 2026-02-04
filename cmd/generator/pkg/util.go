package pkg

import (
	"os"
	"path/filepath"
	"runtime"
	"strings"
)

func pkgDir() string {
	_, file, _, _ := runtime.Caller(0)
	return filepath.Dir(file)
}

func repoRootDir() string {
	path, _ := filepath.Abs(filepath.Join(pkgDir(), "..", "..", ".."))
	return path
}

func internalDir() string {
	return filepath.Join(repoRootDir(), "internal")
}

func ccallDir() string {
	return filepath.Join(internalDir(), "ccall")
}

// toSourceDirFromLibName returns the path under ccall/ where the lib's source lives.
// The updater copies the main tree to go-googlesql, so "zetasql" maps there.
func toSourceDirFromLibName(lib string) string {
	if lib == "zetasql" {
		return filepath.Join(ccallDir(), "go-googlesql")
	}
	return filepath.Join(ccallDir(), lib)
}

func existsFile(path string) bool {
	_, err := os.Stat(path)
	return err == nil
}

func goPkgPath(base, pkg string) string {
	// Output import path uses go-googlesql (not go-zetasql) to match Go imports.
	if strings.HasPrefix(base, "zetasql") {
		suffix := base[len("zetasql"):]
		if suffix == "" {
			return "go-googlesql/" + pkg
		}
		return "go-googlesql" + suffix + "/" + pkg
	}
	// Source tree is under ccall/go-googlesql, so parsed paths can have base "go-googlesql/..."; do not add another "go-" prefix.
	if strings.HasPrefix(base, "go-googlesql") {
		if base == "go-googlesql" {
			return "go-googlesql/" + pkg
		}
		return base + "/" + pkg
	}
	newPath := []string{}
	for _, path := range strings.Split(base, "/") {
		if path == "internal" {
			newPath = append(newPath, "go_internal")
		} else {
			newPath = append(newPath, path)
		}
	}
	return "go-" + filepath.Join(filepath.Join(newPath...), pkg)
}

func normalizeGoPkgPath(name string) string {
	splitted := strings.Split(name, "/")
	base := filepath.Join(splitted[:len(splitted)-1]...)
	pkg := splitted[len(splitted)-1]
	return goPkgPath(base, pkg)
}

// ccallIncludePath returns the path under ccall/ for C++ #include (e.g. "dep/export.inc").
// On disk we have "absl/...", "protobuf/...", "go-googlesql/...", not "go-absl/...".
func ccallIncludePath(basePkg, pkg string) string {
	if strings.HasPrefix(basePkg, "absl") || strings.HasPrefix(basePkg, "protobuf") ||
		strings.HasPrefix(basePkg, "re2") || strings.HasPrefix(basePkg, "icu") ||
		strings.HasPrefix(basePkg, "json") || strings.HasPrefix(basePkg, "googleapis") ||
		strings.HasPrefix(basePkg, "flex") {
		if pkg == "" {
			return basePkg
		}
		return basePkg + "/" + pkg
	}
	return goPkgPath(basePkg, pkg)
}

// pkgNameToCCallIncludePath returns the path under ccall/ for root_bind.cc #include.
// Uses actual ccall layout (absl/..., go-googlesql/...) so export.inc and bridge files are found.
func pkgNameToCCallIncludePath(pkgName string) string {
	splitted := strings.Split(pkgName, "/")
	base := filepath.Join(splitted[:len(splitted)-1]...)
	pkg := splitted[len(splitted)-1]
	return ccallIncludePath(base, pkg)
}
