package pkg

import (
	"bufio"
	"bytes"
	"embed"
	"fmt"
	"go/format"
	"io/fs"
	"log"
	"os"
	"path/filepath"
	"sort"
	"strings"
	"text/template"
)

var (
	bazelSupportedLibs = []string{"zetasql", "absl"}
	includeDirs        = []string{"protobuf", "gtest", "icu", "re2", "json", "googleapis", "flex/src", "go-googlesql"}
)

type Generator struct {
	buildFileParser               *BuildFileParser
	cfg                           *Config
	bridge                        *Bridge
	importSymbol                  *ImportSymbol
	libMap                        map[string]*Lib
	pkgMap                        map[string]Package
	importSymbolPackageMap        map[string]Package
	containsConflictSymbolFileMap map[string]ConflictSymbol
	containsAddSourceFileMap      map[string]SourceConfig
	pkgToAllDeps                  map[string][]string
	internalExportNames           []string
	templates                     embed.FS
}

func NewGenerator(cfg *Config, bridge *Bridge, importSymbol *ImportSymbol, templates embed.FS) *Generator {
	containsConflictSymbolFileMap := map[string]ConflictSymbol{}
	for _, sym := range cfg.ConflictSymbols {
		sym := sym
		containsConflictSymbolFileMap[sym.File] = sym
	}
	containsAddSourceFileMap := map[string]SourceConfig{}
	for _, src := range cfg.AddSources {
		src := src
		containsAddSourceFileMap[src.File] = src
	}
	pkgMap := map[string]Package{}
	for _, pkg := range bridge.Packages {
		pkg := pkg
		pkgMap[pkg.Name] = pkg
	}
	importSymbolPackageMap := map[string]Package{}
	for _, pkg := range importSymbol.Packages {
		pkg := pkg
		importSymbolPackageMap[pkg.Name] = pkg
		pkgMap[pkg.Name] = pkg // merge import symbols to package map
	}
	return &Generator{
		buildFileParser:               NewBuildFileParser(cfg),
		cfg:                           cfg,
		bridge:                        bridge,
		importSymbol:                  importSymbol,
		templates:                     templates,
		containsConflictSymbolFileMap: containsConflictSymbolFileMap,
		containsAddSourceFileMap:      containsAddSourceFileMap,
		importSymbolPackageMap:        importSymbolPackageMap,
		pkgMap:                        pkgMap,
	}
}

func (g *Generator) Generate() error {
	parsedFiles, err := g.createParsedFiles()
	if err != nil {
		return err
	}
	g.libMap = g.createLibMap(parsedFiles)
	pkgToAllDeps, err := g.createAllDependencyMap(parsedFiles)
	if err != nil {
		return err
	}
	g.pkgToAllDeps = pkgToAllDeps
	internalExportNames, err := g.protobufInternalExportNames(parsedFiles)
	if err != nil {
		return err
	}
	g.internalExportNames = internalExportNames
	if err := g.ensureExportIncForAllDeps(parsedFiles); err != nil {
		return err
	}
	for _, parsedFile := range parsedFiles {
		if err := g.generate(parsedFile); err != nil {
			return err
		}
	}
	dummyGo, err := g.templates.ReadFile("templates/dummy.go.tmpl")
	if err != nil {
		return err
	}
	for _, dir := range append(includeDirs, "go-googlesql", "absl") {
		dirPath := filepath.Join(ccallDir(), dir)
		if _, err := os.Stat(dirPath); os.IsNotExist(err) {
			continue
		}
		if err := filepath.Walk(dirPath, func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return err
			}
			if info.IsDir() {
				if err := os.WriteFile(filepath.Join(path, "dummy.go"), dummyGo, 0o600); err != nil {
					return err
				}
			}
			return nil
		}); err != nil {
			return err
		}
	}
	// Headers use #include "zetasql/base/..."; create go-googlesql/zetasql -> . so that -I go-googlesql finds them.
	zetasqlLink := filepath.Join(ccallDir(), "go-googlesql", "zetasql")
	if _, err := os.Stat(filepath.Join(ccallDir(), "go-googlesql")); err == nil {
		if _, err := os.Lstat(zetasqlLink); err != nil && os.IsNotExist(err) {
			_ = os.Symlink(".", zetasqlLink)
		}
	}
	if err := g.createStubHeaders(); err != nil {
		return err
	}
	return nil
}

// createStubHeaders creates minimal stub headers for deps that may not be present in the ccall copy
// (e.g. farmhash, differential-privacy algorithms) so the C++ build can complete.
func (g *Generator) createStubHeaders() error {
	stubs := []struct {
		path string
		body string
	}{
		{
			path: "farmhash.h",
			body: `// Stub for farmhash when not copying com_google_farmhash external.
#ifndef FARMHASH_STUB_H_
#define FARMHASH_STUB_H_
#include <cstdint>
#include <cstring>
namespace farmhash {
inline uint32_t Hash32(const char* s, size_t len) { (void)s; return static_cast<uint32_t>(len); }
inline uint64_t Hash64(const char* s, size_t len) { (void)s; return static_cast<uint64_t>(len); }
inline uint64_t Fingerprint64(const char* s, size_t len) { (void)s; return static_cast<uint64_t>(len); }
}
#endif
`,
		},
		{
			path: "algorithms/partition-selection.h",
			body: `// Stub for differential-privacy partition-selection when not copying external.
#ifndef ALGORITHMS_PARTITION_SELECTION_STUB_H_
#define ALGORITHMS_PARTITION_SELECTION_STUB_H_
namespace differential_privacy {
template <typename T>
class PartitionSelection { public: bool ShouldKeep(double) const { return true; } };
template <typename T>
class LaplacePartitionSelection : public PartitionSelection<T> {
 public:
  bool ShouldKeep(double epsilon) const { (void)epsilon; return true; }
};
}
#endif
`,
		},
		{
			path: "algorithms/algorithm.h",
			body: `// Stub for differential-privacy algorithm when not copying external.
#ifndef ALGORITHMS_ALGORITHM_STUB_H_
#define ALGORITHMS_ALGORITHM_STUB_H_
#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace differential_privacy {

template <typename T>
struct AnonymousResult {
  T value = {};
};

template <typename T>
T GetValue(const AnonymousResult<T>& r) {
  return r.value;
}

template <typename T>
class Algorithm {
 public:
  virtual ~Algorithm() = default;
  void AddEntry(T) {}
  virtual absl::StatusOr<AnonymousResult<T>> PartialResult() {
    return AnonymousResult<T>{};
  }
};

}  // namespace differential_privacy
#endif
`,
		},
		{
			path: "algorithms/bounded-mean.h",
			body: `// Stub for differential-privacy bounded-mean when not copying external.
#ifndef ALGORITHMS_BOUNDED_MEAN_STUB_H_
#define ALGORITHMS_BOUNDED_MEAN_STUB_H_
#include "absl/status/statusor.h"
#include "algorithms/algorithm.h"
#include <memory>

namespace differential_privacy {

template <typename T>
class BoundedMean : public Algorithm<T> {
 public:
  double Mean() const { return 0; }
  class Builder {
   public:
    Builder& SetEpsilon(double) { return *this; }
    Builder& SetLower(T) { return *this; }
    Builder& SetUpper(T) { return *this; }
    absl::StatusOr<std::unique_ptr<Algorithm<T>>> Build() {
      return std::make_unique<BoundedMean>();
    }
  };
};

}  // namespace differential_privacy
#endif
`,
		},
	}
	for _, s := range stubs {
		fullPath := filepath.Join(ccallDir(), s.path)
		if err := os.MkdirAll(filepath.Dir(fullPath), 0o755); err != nil {
			return err
		}
		if err := os.WriteFile(fullPath, []byte(s.body), 0o600); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) createParsedFiles() ([]*ParsedFile, error) {
	var parsedFiles []*ParsedFile
	for _, lib := range bazelSupportedLibs {
		srcPath := toSourceDirFromLibName(lib)
		if err := filepath.Walk(srcPath, func(path string, info fs.FileInfo, err error) error {
			if err != nil {
				return fmt.Errorf("unexpected error in walk: %w", err)
			}
			switch filepath.Base(path) {
			case "BUILD", "BUILD.bazel":
				f, err := g.buildFileParser.Parse(path)
				if err != nil {
					return err
				}
				parsedFiles = append(parsedFiles, f)
			}
			return nil
		}); err != nil {
			return nil, err
		}
	}
	return parsedFiles, nil
}

func (g *Generator) createLibMap(parsedFiles []*ParsedFile) map[string]*Lib {
	cclibMap := map[string]*Lib{}
	for _, parsedFile := range parsedFiles {
		for _, cclib := range parsedFile.cclibs {
			srcPkgName := fmt.Sprintf("%s/%s", cclib.BasePkg, cclib.Name)
			cclibMap[srcPkgName] = cclib
		}
	}
	for _, dep := range g.cfg.Dependencies {
		cclibdeps := make([]Dependency, 0, len(dep.Deps))
		for _, d := range dep.Deps {
			cclibdeps = append(cclibdeps, Dependency{
				BasePkg: d.Base,
				Pkg:     d.Pkg,
			})
		}
		cclibMap[fmt.Sprintf("%s/%s", dep.Name, dep.Name)] = &Lib{
			BasePkg: dep.Name,
			Name:    dep.Name,
			Deps:    cclibdeps,
		}
	}
	return cclibMap
}

func (g *Generator) createAllDependencyMap(parsedFiles []*ParsedFile) (map[string][]string, error) {
	pkgToAllDeps := map[string][]string{}
	for pkgName, lib := range g.libMap {
		pkgMap := map[string]struct{}{}
		if err := g.resolveDeps(pkgMap, lib); err != nil {
			return nil, err
		}
		sorted := []string{}
		for k := range pkgMap {
			lib, exists := g.libMap[k]
			if exists {
				if len(lib.Sources) == 0 || lib.headerOnly() {
					continue
				}
			}
			sorted = append(sorted, k)
		}
		sort.Strings(sorted)
		pkgToAllDeps[pkgName] = sorted
	}
	return pkgToAllDeps, nil
}

func (g *Generator) resolveDeps(pkgMap map[string]struct{}, lib *Lib) error {
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	for _, dep := range lib.Deps {
		dep := dep
		depPkgName := fmt.Sprintf("%s/%s", dep.BasePkg, dep.Pkg)
		if _, exists := pkgMap[depPkgName]; exists {
			continue
		}
		lib, exists := g.libMap[depPkgName]
		if exists {
			if err := g.resolveDeps(pkgMap, lib); err != nil {
				return err
			}
		}
	}
	pkgMap[pkgName] = struct{}{}
	return nil
}

func (g *Generator) protobufInternalExportNames(parsedFiles []*ParsedFile) ([]string, error) {
	internalExportNames := []string{}
	for _, path := range g.cfg.ProtobufInternalExportNameFiles {
		internalExportName, err := g.headerPathToInternalExportName(filepath.Join(ccallDir(), path))
		if err != nil {
			if os.IsNotExist(err) {
				internalExportName = "GOOGLE_PROTOBUF"
			} else {
				return nil, err
			}
		}
		internalExportNames = append(internalExportNames, internalExportName)
	}
	for _, parsedFile := range parsedFiles {
		for _, ccproto := range parsedFile.ccprotos {
			for _, header := range ccproto.Headers {
				headerPath := filepath.Join(ccallDir(), ccproto.BasePkg, header)
				internalExportName, err := g.headerPathToInternalExportName(headerPath)
				if err != nil {
					if os.IsNotExist(err) {
						internalExportName = "GOOGLE_PROTOBUF"
					} else {
						return nil, err
					}
				}
				internalExportNames = append(internalExportNames, internalExportName)
			}
		}
	}
	return internalExportNames, nil
}

func (g *Generator) headerPathToInternalExportName(path string) (string, error) {
	f, err := os.Open(path)
	if err != nil {
		return "", err
	}
	defer f.Close()
	scanner := bufio.NewScanner(f)
	for scanner.Scan() {
		text := scanner.Text()
		if strings.HasPrefix(text, "#define PROTOBUF_INTERNAL_EXPORT") {
			splitted := strings.Split(text, " ")
			return splitted[1][len("PROTOBUF_INTERNAL_EXPORT_"):], nil
		}
	}
	if err := scanner.Err(); err != nil {
		return "", err
	}
	return "", fmt.Errorf("failed to find PROTOBUF_INTERNAL_EXPORT in %s", path)
}

func (g *Generator) generate(f *ParsedFile) error {
	for _, lib := range f.cclibs {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := g.generateExportInc(lib); err != nil {
			return err
		}
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBindGO(outputDir, lib); err != nil {
			return err
		}
	}
	for _, lib := range f.ccprotos {
		outputDir := filepath.Join(ccallDir(), goPkgPath(lib.BasePkg, lib.Name))
		if err := g.generateExportInc(lib); err != nil {
			return err
		}
		if err := g.generateBindCC(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeExternH(outputDir, lib); err != nil {
			return err
		}
		if err := g.generateBridgeCCInc(outputDir); err != nil {
			return err
		}
		if err := g.generateBridgeInc(outputDir, lib); err != nil {
			return err
		}
	}
	if err := g.generateRootBridgeIncForZetasqlPackages(); err != nil {
		return err
	}
	if err := g.generateRootBindCC(filepath.Join(ccallDir(), "go-googlesql")); err != nil {
		return err
	}
	if err := g.generateRootBridgeH(filepath.Join(ccallDir(), "go-googlesql")); err != nil {
		return err
	}
	if err := g.generateRootBindGO(filepath.Join(ccallDir(), "go-googlesql")); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateRootBindCC(outputDir string) error {
	pkgs := g.pkgs()
	libs := make([]string, 0, len(pkgs))
	for _, pkg := range pkgs {
		// Include every package that has bridge methods (zetasql + import e.g. absl/time).
		if len(pkg.Methods) == 0 {
			continue
		}
		libs = append(libs, normalizeGoPkgPath(pkg.Name))
	}
	output, err := g.generateCCSourceByTemplate(
		"templates/root_bind.cc.tmpl",
		libs,
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateExportInc(lib *Lib) error {
	includePath := ccallIncludePath(lib.BasePkg, lib.Name)
	dir := filepath.Join(ccallDir(), includePath)
	if err := os.MkdirAll(dir, 0o755); err != nil {
		return err
	}
	// Empty export.inc satisfies #include; headers may define visibility macros elsewhere.
	return os.WriteFile(filepath.Join(dir, "export.inc"), []byte{}, 0o600)
}

// ensureExportIncForAllDeps creates export.inc for every dep referenced from cclibs/ccprotos
// (external and go-googlesql). Some deps are only referenced, not built as libs, so they
// would otherwise lack export.inc and the C++ build would fail.
func (g *Generator) ensureExportIncForAllDeps(parsedFiles []*ParsedFile) error {
	seen := map[string]struct{}{}
	for _, f := range parsedFiles {
		for _, lib := range append(f.cclibs, f.ccprotos...) {
			for _, dep := range lib.Deps {
				key := dep.BasePkg + "/" + dep.Pkg
				if _, ok := seen[key]; ok {
					continue
				}
				seen[key] = struct{}{}
				if err := g.generateExportInc(&Lib{BasePkg: dep.BasePkg, Name: dep.Pkg}); err != nil {
					return err
				}
			}
		}
	}
	return nil
}

func (g *Generator) generateBindCC(outputDir string, lib *Lib) error {
	if err := os.MkdirAll(outputDir, 0o755); err != nil {
		return err
	}
	output, err := g.generateCCSourceByTemplate(
		"templates/bind.cc.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bind.cc"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) pkgs() []*Package {
	pkgs := make([]*Package, 0, len(g.pkgMap))
	for _, pkg := range g.pkgMap {
		pkg := pkg
		pkgs = append(pkgs, &pkg)
	}
	sort.Slice(pkgs, func(i, j int) bool {
		return pkgs[i].Name < pkgs[j].Name
	})
	return pkgs
}

func (g *Generator) generateRootBridgeH(outputDir string) error {
	pkgs := g.pkgs()
	libs := make([]string, 0, len(pkgs))
	for _, pkg := range pkgs {
		if len(pkg.Methods) == 0 {
			continue
		}
		libs = append(libs, normalizeGoPkgPath(pkg.Name))
	}
	output, err := g.generateCCSourceByTemplate(
		"templates/root_bridge.h.tmpl",
		libs,
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge.h.tmpl",
		g.createBindCCParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBridgeExternH(outputDir string, lib *Lib) error {
	output, err := g.generateCCSourceByTemplate(
		"templates/bridge_extern.h.tmpl",
		g.createBridgeExternParam(lib),
	)
	if err != nil {
		return err
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_extern.h"), output, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) generateBindGO(outputDir string, lib *Lib) error {
	{
		// for darwin ( currently windows not supported )
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamDarwin(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), output, 0o600); err != nil {
			return err
		}
	}
	{
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createBindGoParamLinux(lib),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), output, 0o600); err != nil {
			return err
		}
	}
	if existsFile(filepath.Join(outputDir, "bind.go")) {
		if err := os.Remove(filepath.Join(outputDir, "bind.go")); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateRootBindGO(outputDir string) error {
	{
		// for darwin ( currently windows not supported )
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createRootBindGoParamDarwin(),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_darwin.go"), output, 0o600); err != nil {
			return err
		}
	}
	{
		output, err := g.generateGoSourceByTemplate(
			"templates/bind.go.tmpl",
			g.createRootBindGoParamLinux(),
		)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bind_linux.go"), output, 0o600); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) generateBridgeCCInc(outputDir string) error {
	if existsFile(filepath.Join(outputDir, "bridge_cc.inc")) {
		return nil
	}
	if err := os.WriteFile(filepath.Join(outputDir, "bridge_cc.inc"), nil, 0o600); err != nil {
		return err
	}
	return nil
}

func (g *Generator) createBridgeIncParam(lib *Lib) *BridgeIncParam {
	param := &BridgeIncParam{
		FQDN: fqdnForExport(lib.BasePkg, lib.Name),
	}
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	pkg, exists := g.pkgMap[pkgName]
	if !exists {
		// Bridge YAML uses zetasql/...; BUILD uses go-googlesql/...
		pkg, exists = g.pkgMap[strings.Replace(pkgName, "go-googlesql", "zetasql", 1)]
	}
	if !exists || len(pkg.Methods) == 0 {
		return param
	}
	var sb strings.Builder
	for _, method := range pkg.Methods {
		args := make([]struct{ C string; IsOut bool }, 0, len(method.Args)+len(method.Ret))
		for _, arg := range method.Args {
			args = append(args, struct{ C string; IsOut bool }{C: g.toCType(arg), IsOut: false})
		}
		for _, ret := range method.Ret {
			args = append(args, struct{ C string; IsOut bool }{C: fmt.Sprintf("%s*", g.toCType(ret)), IsOut: true})
		}
		fmt.Fprintf(&sb, "void GO_EXPORT(%s)( ", method.Name)
		for i, a := range args {
			if i > 0 {
				sb.WriteString(", ")
			}
			fmt.Fprintf(&sb, "%s arg%d", a.C, i)
		}
		sb.WriteString(" ) {\n")
		for i, a := range args {
			if a.IsOut {
				fmt.Fprintf(&sb, "  *arg%d = 0;\n", i)
			} else {
				fmt.Fprintf(&sb, "  (void)arg%d;\n", i)
			}
		}
		sb.WriteString("}\n\n")
	}
	param.BindSourceCode = strings.TrimSuffix(sb.String(), "\n\n")
	return param
}

// generateRootBridgeIncForZetasqlPackages generates bridge.inc for every package
// that root_bind.cc includes (zetasql + import e.g. absl), so all C.export_zetasql_* symbols are defined.
func (g *Generator) generateRootBridgeIncForZetasqlPackages() error {
	for _, pkg := range g.pkgs() {
		if len(pkg.Methods) == 0 {
			continue
		}
		param := g.createBridgeIncParamFromPackage(pkg)
		includePath := normalizeGoPkgPath(pkg.Name)
		outputDir := filepath.Join(ccallDir(), includePath)
		if err := os.MkdirAll(outputDir, 0o755); err != nil {
			return err
		}
		output, err := g.generateCCSourceByTemplate("templates/bridge.inc.tmpl", param)
		if err != nil {
			return err
		}
		if err := os.WriteFile(filepath.Join(outputDir, "bridge.inc"), output, 0o600); err != nil {
			return err
		}
	}
	return nil
}

func (g *Generator) createBridgeIncParamFromPackage(pkg *Package) *BridgeIncParam {
	param := &BridgeIncParam{
		FQDN: strings.ReplaceAll(pkg.Name, "/", "_"),
	}
	if len(pkg.Methods) == 0 {
		return param
	}
	var sb strings.Builder
	for _, method := range pkg.Methods {
		args := make([]struct{ C string; IsOut bool }, 0, len(method.Args)+len(method.Ret))
		for _, arg := range method.Args {
			args = append(args, struct{ C string; IsOut bool }{C: g.toCType(arg), IsOut: false})
		}
		for _, ret := range method.Ret {
			args = append(args, struct{ C string; IsOut bool }{C: fmt.Sprintf("%s*", g.toCType(ret)), IsOut: true})
		}
		fmt.Fprintf(&sb, "void GO_EXPORT(%s)( ", method.Name)
		for i, a := range args {
			if i > 0 {
				sb.WriteString(", ")
			}
			fmt.Fprintf(&sb, "%s arg%d", a.C, i)
		}
		sb.WriteString(" ) {\n")
		for i, a := range args {
			if a.IsOut {
				fmt.Fprintf(&sb, "  *arg%d = 0;\n", i)
			} else {
				fmt.Fprintf(&sb, "  (void)arg%d;\n", i)
			}
		}
		sb.WriteString("}\n\n")
	}
	param.BindSourceCode = strings.TrimSuffix(sb.String(), "\n\n")
	return param
}

func (g *Generator) generateBridgeInc(outputDir string, lib *Lib) error {
	param := g.createBridgeIncParam(lib)
	output, err := g.generateCCSourceByTemplate("templates/bridge.inc.tmpl", param)
	if err != nil {
		return err
	}
	return os.WriteFile(filepath.Join(outputDir, "bridge.inc"), output, 0o600)
}

func (g *Generator) generateCCSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	return b.Bytes(), nil
}

func (g *Generator) generateGoSourceByTemplate(tmplPath string, param interface{}) ([]byte, error) {
	tmplText, err := g.templates.ReadFile(tmplPath)
	if err != nil {
		return nil, fmt.Errorf("failed to read template: %w", err)
	}
	tmpl, err := template.New("").Parse(string(tmplText))
	if err != nil {
		return nil, fmt.Errorf("failed to parse template: %w", err)
	}
	var b bytes.Buffer
	if err := tmpl.Execute(&b, param); err != nil {
		return nil, fmt.Errorf("failed to execute template: %w", err)
	}
	buf, err := format.Source(b.Bytes())
	if err != nil {
		return nil, fmt.Errorf("failed to format %s: %w", b.String(), err)
	}
	return buf, nil
}

type BindCCParam struct {
	FQDN         string
	PkgPath      string
	ReplaceNames []string
	Headers      []string
	Sources      []SourceParam
	Deps         []string
}

type SourceParam struct {
	Value             string
	BeforeIncludeHook string
	AfterIncludeHook  string
}

// fqdnForExport returns an FQDN safe for C/Go export symbols (no hyphens; hyphens invalid in identifiers).
func fqdnForExport(basePkg, name string) string {
	prefix := strings.ReplaceAll(basePkg, "/", "_")
	fqdn := fmt.Sprintf("%s_%s", prefix, name)
	return strings.ReplaceAll(fqdn, "-", "_")
}

func (g *Generator) createBindCCParam(lib *Lib) *BindCCParam {
	param := &BindCCParam{}

	prefix := strings.ReplaceAll(lib.BasePkg, "/", "_")
	param.FQDN = fqdnForExport(lib.BasePkg, lib.Name)
	param.PkgPath = lib.BasePkg
	param.ReplaceNames = append(
		append(
			append([]string{}, g.cfg.TopLevelNamespaces...),
			g.cfg.GlobalSymbols...,
		),
		g.internalExportNames...,
	)
	param.Headers = lib.HeaderPaths()
	sources := make([]SourceParam, 0, len(lib.Sources))
	prefixExport := strings.ReplaceAll(prefix, "-", "_")
	for _, src := range lib.SourcePaths() {
		sourceParam := SourceParam{Value: src}
		if sym, exists := g.containsConflictSymbolFileMap[src]; exists {
			sourceParam.BeforeIncludeHook = fmt.Sprintf("\n\n#define %s %s%s", sym.Symbol, prefixExport, sym.Symbol)
			sourceParam.AfterIncludeHook = fmt.Sprintf("\n#undef %s\n", sym.Symbol)
		}
		if addSource, exists := g.containsAddSourceFileMap[src]; exists {
			sourceParam.AfterIncludeHook += fmt.Sprintf("\n#include \"%s\"\n", addSource.Source)
		}
		sources = append(sources, sourceParam)
	}
	param.Sources = sources
	deps := make([]string, 0, len(lib.Deps))
	for _, dep := range lib.Deps {
		deps = append(deps, ccallIncludePath(dep.BasePkg, dep.Pkg))
	}
	param.Deps = deps
	return param
}

type NamedImport struct {
	Name string
	Path string
}

type BindGoParam struct {
	Compiler          string
	DebugMode         bool
	Pkg               string
	FQDN              string
	ImportUnsafePkg   bool
	IncludePaths      []string
	CXXFlags          []string
	LDFlags           []string
	BridgeHeaders     []string
	BridgeIncPaths    []string      // root only: paths to each package's bridge.inc (unused; root uses CallPkg instead)
	ImportGoLibs      []string      // blank imports (_ "path")
	NamedImportGoLibs []NamedImport // root only: named imports (name "path") so root can call dep packages
	Funcs             []Func
	ExportFuncs       []ExportFunc
	IncludeBridgeInc  bool // lib packages: include local bridge.inc
}

type BridgeExternParam struct {
	Funcs []Func
}

// BridgeIncParam is the template param for bridge.inc (C stub implementations).
type BridgeIncParam struct {
	FQDN           string
	BindSourceCode string
}

type Func struct {
	BasePkg string
	Name    string
	Args    []Type
	// CallPkg is set for root package only: call this package's BasePkg_Name instead of C.export_*.
	CallPkg string
}

type ExportFunc struct {
	Func
	LibName string
}

type Type struct {
	IsCustomType bool
	IsRetType    bool
	NeedsCast    bool
	GO           string
	CGO          string
	C            string
}

func (t *Type) GoToC(index int) string {
	argName := fmt.Sprintf("arg%d", index)
	if t.IsRetType {
		return fmt.Sprintf("(%s)(unsafe.Pointer(%s))", t.CGO, argName)
	}
	return fmt.Sprintf("%s(%s)", t.CGO, argName)
}

var reservedKeywords = []string{
	"case", "type",
}

func (g *Generator) goReservedKeyword(keyword string) bool {
	for _, k := range reservedKeywords {
		if keyword == k {
			return true
		}
	}
	return false
}

func (g *Generator) cgoCompiler(lib *Lib) string {
	if strings.Contains(lib.BasePkg, "absl") {
		return "c++11"
	}
	return "c++1z"
}

func (g *Generator) goPkgName(lib *Lib) string {
	if g.goReservedKeyword(lib.Name) {
		return "go_" + lib.Name
	}
	return lib.Name
}

func (g *Generator) extendLibs(lib *Lib) []string {
	if lib.BasePkg == "absl/time/internal/cctz" && lib.Name == "time_zone" {
		// TODO: switch by platform
		return []string{"-framework Foundation"}
	}
	return nil
}

func (g *Generator) createBindGoParamLinux(lib *Lib) *BindGoParam {
	ldflags := []string{"-ldl"}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType == Darwin || flag.OSType == Windows {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	cxxflags := []string{
		"-Wno-final-dtor-non-final-class",
		"-Wno-implicit-const-int-float-conversion",
	}
	return g.createBindGoParam(lib, cxxflags, ldflags)
}

func (g *Generator) createBindGoParamDarwin(lib *Lib) *BindGoParam {
	ldflags := []string{}
	for _, flag := range lib.LinkerFlags {
		if flag.OSType != Darwin {
			continue
		}
		ldflags = append(ldflags, flag.Flag)
	}
	return g.createBindGoParam(lib, nil, ldflags)
}

func (g *Generator) createRootBindGoParamLinux() *BindGoParam {
	ldflags := []string{"-ldl"}
	cxxflags := []string{
		"-Wno-final-dtor-non-final-class",
		"-Wno-implicit-const-int-float-conversion",
	}
	return g.createRootBindGoParam(cxxflags, ldflags)
}

func (g *Generator) createRootBindGoParamDarwin() *BindGoParam {
	return g.createRootBindGoParam(nil, nil)
}

func (g *Generator) createRootBindGoParam(cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false, IncludeBridgeInc: false}
	param.Pkg = "zetasql"
	param.FQDN = "zetasql"
	param.Compiler = "c++1z"
	param.CXXFlags = cxxflags
	param.LDFlags = ldflags

	ccallDir := "../"
	includePaths := []string{ccallDir}
	for _, includeDir := range includeDirs {
		includePaths = append(includePaths, filepath.Join(ccallDir, includeDir))
	}
	param.IncludePaths = includePaths
	bridgeHeaderMap := map[string]struct{}{}
	importGoLibsSet := map[string]struct{}{}
	for _, pkg := range g.pkgs() {
		pkgName := pkg.Name
		// pkgToAllDeps is keyed by libMap (go-googlesql/...); bridge uses zetasql/... so normalize.
		libKey := normalizeGoPkgPath(pkgName)
		for _, dep := range g.pkgToAllDeps[libKey] {
			if dep == libKey {
				continue
			}
			// Only import go-googlesql subpackages; they have bind_linux.go. External deps (absl, etc.)
			// often only have dummy.go with build tag "required" and would fail to build.
			if !strings.HasPrefix(dep, "go-googlesql") {
				continue
			}
			libName := fmt.Sprintf("github.com/vantaboard/go-googlesql/internal/ccall/%s", dep)
			callPkg := filepath.Base(dep)
			if _, ok := importGoLibsSet[libName]; !ok {
				importGoLibsSet[libName] = struct{}{}
				param.ImportGoLibs = append(param.ImportGoLibs, libName)
				param.NamedImportGoLibs = append(param.NamedImportGoLibs, NamedImport{Name: callPkg, Path: libName})
			}
			// Bridge headers and export funcs only for packages that have bridge definitions.
			depPkg, exists := g.importSymbolPackageMap[dep]
			if !exists {
				depPkg, exists = g.pkgMap[strings.Replace(dep, "go-googlesql", "zetasql", 1)]
			}
			if !exists {
				continue
			}
			basePkg := filepath.Base(dep)
			bridgeHeader := filepath.Join(ccallDir, dep, "bridge.h")
			if _, exists := bridgeHeaderMap[bridgeHeader]; exists {
				continue
			}
			param.BridgeHeaders = append(param.BridgeHeaders, bridgeHeader)
			bridgeHeaderMap[bridgeHeader] = struct{}{}
			for _, method := range depPkg.Methods {
				method := method
				fn, needsImportUnsagePkg := g.pkgMethodToFunc(basePkg, &method)
				if needsImportUnsagePkg {
					param.ImportUnsafePkg = true
				}
				fn.CallPkg = callPkg
				param.ExportFuncs = append(param.ExportFuncs, ExportFunc{
					Func:    fn,
					LibName: libName,
				})
				param.Funcs = append(param.Funcs, fn)
			}
		}
	}
	return param
}

func (g *Generator) createBindGoParam(lib *Lib, cxxflags, ldflags []string) *BindGoParam {
	param := &BindGoParam{DebugMode: false, IncludeBridgeInc: true}
	param.Pkg = g.goPkgName(lib)
	param.Compiler = g.cgoCompiler(lib)
	param.CXXFlags = cxxflags
	param.LDFlags = ldflags
	param.FQDN = fqdnForExport(lib.BasePkg, lib.Name)
	ccallDir := strings.Repeat("../", len(strings.Split(lib.BasePkg, "/"))+1)
	includePaths := []string{ccallDir}
	for _, includeDir := range includeDirs {
		includePaths = append(includePaths, filepath.Join(ccallDir, includeDir))
	}
	param.IncludePaths = includePaths
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	exportFuncs := []ExportFunc{}
	bridgeHeaders := []string{}
	importGoLibs := []string{}
	for _, dep := range g.pkgToAllDeps[pkgName] {
		if dep == pkgName {
			continue
		}
		pkg, exists := g.importSymbolPackageMap[dep]
		if !exists {
			continue
		}
		goPkgPath := normalizeGoPkgPath(dep)
		libName := fmt.Sprintf("github.com/vantaboard/go-googlesql/internal/ccall/%s", goPkgPath)
		importGoLibs = append(importGoLibs, libName)
		basePkg := filepath.Base(goPkgPath)
		bridgeHeaders = append(bridgeHeaders, filepath.Join(ccallDir, goPkgPath, "bridge.h"))
		for _, method := range pkg.Methods {
			method := method
			fn, needsImportUnsagePkg := g.pkgMethodToFunc(basePkg, &method)
			if needsImportUnsagePkg {
				param.ImportUnsafePkg = true
			}
			exportFuncs = append(exportFuncs, ExportFunc{
				Func:    fn,
				LibName: libName,
			})
		}
	}
	param.ImportGoLibs = importGoLibs
	param.BridgeHeaders = bridgeHeaders
	param.ExportFuncs = exportFuncs
	pkg, exists := g.pkgMap[pkgName]
	if !exists {
		pkg, exists = g.pkgMap[strings.Replace(pkgName, "go-googlesql", "zetasql", 1)]
	}
	if exists {
		pkg := pkg
		funcs, needsImportUnsafePkg := g.pkgToFuncs(lib.Name, &pkg)
		param.Funcs = funcs
		if needsImportUnsafePkg {
			param.ImportUnsafePkg = true
		}
	}
	return param
}

func (g *Generator) pkgToFuncs(pkgName string, pkg *Package) ([]Func, bool) {
	needsImportUnsafePkg := false
	funcs := make([]Func, 0, len(pkg.Methods))
	for _, method := range pkg.Methods {
		method := method
		fn, needsUnsafePkg := g.pkgMethodToFunc(pkgName, &method)
		funcs = append(funcs, fn)
		if needsUnsafePkg {
			needsImportUnsafePkg = true
		}
	}
	return funcs, needsImportUnsafePkg
}

func (g *Generator) pkgMethodToFunc(pkgName string, method *Method) (Func, bool) {
	needsImportUnsafePkg := false
	fn := Func{
		BasePkg: pkgName,
		Name:    method.Name,
	}
	args := []Type{}
	for _, arg := range method.Args {
		cgoType := g.toCGOType(arg)
		if cgoType == "" {
			log.Fatalf("unexpected type: %s.%s.%s", pkgName, method.Name, arg)
		}
		if cgoType == "unsafe.Pointer" {
			needsImportUnsafePkg = true
		}
		goType := g.toGoType(arg)
		needsCast := goType != cgoType
		args = append(args, Type{
			NeedsCast: needsCast,
			GO:        goType,
			CGO:       cgoType,
		})
	}
	for _, ret := range method.Ret {
		cgoType := g.toCGOType(ret)
		if cgoType == "" {
			log.Fatalf("unexpected type: %s.%s.%s", pkgName, method.Name, ret)
		}
		if cgoType == "unsafe.Pointer" {
			needsImportUnsafePkg = true
		}
		goType := g.toGoType(ret)
		needsCast := goType != cgoType
		if needsCast {
			needsImportUnsafePkg = true
		}
		args = append(args, Type{
			IsRetType: true,
			NeedsCast: needsCast,
			GO:        "*" + goType,
			CGO:       "*" + cgoType,
		})
	}
	fn.Args = args
	return fn, needsImportUnsafePkg
}

func (g *Generator) createBridgeExternParam(lib *Lib) *BridgeExternParam {
	param := &BridgeExternParam{}
	pkgName := fmt.Sprintf("%s/%s", lib.BasePkg, lib.Name)
	if pkg, exists := g.pkgMap[pkgName]; exists {
		funcs := make([]Func, 0, len(pkg.Methods))
		for _, method := range pkg.Methods {
			fn := Func{
				BasePkg: lib.Name,
				Name:    method.Name,
			}
			args := []Type{}
			for _, arg := range method.Args {
				args = append(args, Type{C: g.toCType(arg)})
			}
			for _, ret := range method.Ret {
				args = append(args, Type{C: fmt.Sprintf("%s*", g.toCType(ret))})
			}
			fn.Args = args
			funcs = append(funcs, fn)
		}
		param.Funcs = funcs
	}
	return param
}

func (g *Generator) toGoType(typ string) string {
	if typ == "string" || typ == "struct" {
		return "unsafe.Pointer"
	}
	return typ
}

func (g *Generator) toCGOType(typ string) string {
	switch typ {
	case "bool":
		return "C.char"
	case "int":
		return "C.int"
	case "int8":
		return "C.int8_t"
	case "int16":
		return "C.int16_t"
	case "int32":
		return "C.int32_t"
	case "int64":
		return "C.int64_t"
	case "uint":
		return "C.uint"
	case "uint8":
		return "C.uint8_t"
	case "uint16":
		return "C.uint16_t"
	case "uint32":
		return "C.uint32_t"
	case "uint64":
		return "C.uint64_t"
	case "float32":
		return "C.float"
	case "float64":
		return "C.double"
	case "string", "struct":
		return "unsafe.Pointer"
	}
	return ""
}

func (g *Generator) toCType(typ string) string {
	switch typ {
	case "bool":
		return "char"
	case "int":
		return "int"
	case "int8":
		return "int8_t"
	case "int16":
		return "int16_t"
	case "int32":
		return "int32_t"
	case "int64":
		return "int64_t"
	case "uint":
		return "uint"
	case "uint8":
		return "uint8_t"
	case "uint16":
		return "uint16_t"
	case "uint32":
		return "uint32_t"
	case "uint64":
		return "uint64_t"
	case "float32":
		return "float"
	case "float64":
		return "double"
	case "string", "struct":
		return "void *"
	}
	return ""
}
