// Package main: patches applied to internal/ccall after copy so that fixes
// are preserved across "make update" and "make generate". Stub files are
// written so they exist even when ccall is repopulated from cache.

package main

import (
	"os"
	"path/filepath"
	"strings"
)

// applyPatches rewrites upstream files under ccall so that build fixes
// (redefinition avoidance, include guards, etc.) persist after regeneration.
func applyPatches(ccall string) error {
	gg := filepath.Join(ccall, "go-googlesql")
	patches := []struct {
		path string
		fn   func(string) string
	}{
		{filepath.Join(gg, "public", "types", "type.cc"), patchTypeCc},
		{filepath.Join(gg, "base", "net", "public_suffix_list_data.h"), patchPublicSuffixListDataH},
		{filepath.Join(gg, "analyzer", "resolver_query.cc"), patchResolverQueryCc},
		{filepath.Join(gg, "analyzer", "analytic_function_resolver.cc"), patchAnalyticFunctionResolverCc},
		{filepath.Join(gg, "analyzer", "function_resolver.cc"), patchFunctionResolverCc},
		{filepath.Join(gg, "reference_impl", "analytic_op.cc"), patchAnalyticOpCc},
		{filepath.Join(gg, "public", "anonymization_utils.cc"), patchAnonymizationUtilsCc},
	}
	for _, p := range patches {
		if err := applyPatch(p.path, p.fn); err != nil {
			return err
		}
	}
	return nil
}

func applyPatch(path string, fn func(string) string) error {
	body, err := os.ReadFile(path)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return err
	}
	out := fn(string(body))
	if out == string(body) {
		return nil
	}
	return os.WriteFile(path, []byte(out), 0o644)
}

func patchTypeCc(body string) string {
	if strings.Contains(body, "TypeKindCostInfo") {
		return body
	}
	body = strings.Replace(body,
		"struct TypeKindInfo {\n  const char* const name;",
		"// Renamed to avoid redefinition with simple_type.cc's TypeKindInfo (optional<LanguageFeature>).\nstruct TypeKindCostInfo {\n  const char* const name;",
		1)
	body = strings.Replace(body, "static const TypeKindInfo kTypeKindInfo[]", "static const TypeKindCostInfo kTypeKindInfo[]", 1)
	return body
}

func patchPublicSuffixListDataH(body string) string {
	if strings.Contains(body, "ZETASQL_BASE_NET_PUBLIC_SUFFIX_LIST_DATA_H_") &&
		strings.Contains(body, "static inline constexpr") {
		return body
	}
	if !strings.Contains(body, "ZETASQL_BASE_NET_PUBLIC_SUFFIX_LIST_DATA_H_") {
		guard := "#ifndef ZETASQL_BASE_NET_PUBLIC_SUFFIX_LIST_DATA_H_\n#define ZETASQL_BASE_NET_PUBLIC_SUFFIX_LIST_DATA_H_\n"
		body = guard + body
	}
	if strings.Contains(body, "namespace zetasql::internal {") &&
		!strings.Contains(body, "static inline constexpr") {
		body = strings.Replace(body,
			"namespace zetasql::internal {\nconstexpr absl::string_view kPublicSuffixListData =",
			"namespace zetasql::internal {\n// static inline for internal linkage when header included from multiple TUs.\nstatic inline constexpr absl::string_view kPublicSuffixListData =",
			1)
	}
	if !strings.HasSuffix(strings.TrimSpace(body), "#endif") {
		body = strings.TrimRight(body, "\n") + "\n#endif  // ZETASQL_BASE_NET_PUBLIC_SUFFIX_LIST_DATA_H_\n"
	}
	return body
}

func patchResolverQueryCc(body string) string {
	if strings.Contains(body, "kOrderByQueryId") {
		return body
	}
	body = strings.Replace(body, "STATIC_IDSTRING(kOrderById, \"$orderby\");", "// Renamed to avoid redefinition when resolver_expr.cc and resolver_query.cc are in same TU.\nSTATIC_IDSTRING(kOrderByQueryId, \"$orderby\");", 1)
	body = strings.Replace(body, "AddColumnsForOrderByExprs(kOrderById /* query_alias */,", "AddColumnsForOrderByExprs(kOrderByQueryId /* query_alias */,", 1)
	body = strings.Replace(body, "kOrderById /* query_alias */,", "kOrderByQueryId /* query_alias */,", 1)
	return body
}

func patchAnalyticFunctionResolverCc(body string) string {
	if strings.Contains(body, "kAnalyticOrderById") {
		return body
	}
	body = strings.Replace(body, "STATIC_IDSTRING(kOrderById, \"$orderby\");", "// Renamed to avoid redefinition when included in same TU as resolver_expr.cc.\nSTATIC_IDSTRING(kAnalyticOrderById, \"$orderby\");", 1)
	body = strings.Replace(body, "ZETASQL_RETURN_IF_ERROR(AddColumnForWindowExpression(\n          kOrderById,", "ZETASQL_RETURN_IF_ERROR(AddColumnForWindowExpression(\n          kAnalyticOrderById,", 1)
	return body
}

func patchFunctionResolverCc(body string) string {
	if strings.Contains(body, "kFunctionResolverIsNullFnName") {
		return body
	}
	body = strings.Replace(body,
		"static const std::string* const kIsNullFnName = new std::string(\"$is_null\");",
		"// Renamed to avoid redefinition when included in same TU as resolver_expr.cc.\nstatic const std::string* const kFunctionResolverIsNullFnName = new std::string(\"$is_null\");",
		1)
	body = strings.Replace(body, "return *kIsNullFnName;", "return *kFunctionResolverIsNullFnName;", 1)
	return body
}

func patchAnalyticOpCc(body string) string {
	if strings.Contains(body, "IsNaNValue") {
		return body
	}
	body = strings.Replace(body,
		"// Returns true if the data type of <value> has NaN and it has the value equal\n// to NaN.\nbool IsNaN(const Value& value) {",
		"// Returns true if the data type of <value> has NaN and it has the value equal\n// to NaN.\n// Renamed to avoid redefinition when included in same TU as function.cc.\nstatic bool IsNaNValue(const Value& value) {",
		1)
	body = strings.Replace(body, "IsNaN(partition[tuple_id]->slot(order_key_slot_idx).value()))", "IsNaNValue(partition[tuple_id]->slot(order_key_slot_idx).value()))", -1)
	return body
}

func patchAnonymizationUtilsCc(body string) string {
	if strings.Contains(body, "LaplacePartitionSelection<double>::") {
		return body
	}
	body = strings.Replace(body, "differential_privacy::LaplacePartitionSelection::CalculateThreshold(", "differential_privacy::LaplacePartitionSelection<double>::CalculateThreshold(", 1)
	body = strings.Replace(body, "differential_privacy::LaplacePartitionSelection::CalculateDelta(", "differential_privacy::LaplacePartitionSelection<double>::CalculateDelta(", 1)
	return body
}

// writeStubs writes stub headers under ccall so they exist after any copy.
// These are used when the full external libs (farmhash, differential_privacy)
// are not copied into ccall.
func writeStubs(ccall string) error {
	stubs := map[string]string{
		"farmhash.h":                          stubFarmhashH,
		"algorithms/algorithm.h":              stubAlgorithmH,
		"algorithms/partition-selection.h":   stubPartitionSelectionH,
		"algorithms/bounded-mean.h":           stubBoundedMeanH,
		"algorithms/bounded-sum.h":            stubBoundedSumH,
		"algorithms/bounded-variance.h":       stubBoundedVarianceH,
		"algorithms/bounded-standard-deviation.h": stubBoundedStandardDeviationH,
	}
	for rel, content := range stubs {
		p := filepath.Join(ccall, rel)
		if err := os.MkdirAll(filepath.Dir(p), 0o755); err != nil {
			return err
		}
		if err := os.WriteFile(p, []byte(content), 0o644); err != nil {
			return err
		}
	}
	return nil
}

const stubFarmhashH = `// Stub for farmhash when not copying com_google_farmhash external.
#ifndef FARMHASH_STUB_H_
#define FARMHASH_STUB_H_
#include <cstdint>
#include <cstring>
namespace farmhash {
inline uint32_t Hash32(const char* s, size_t len) { (void)s; return static_cast<uint32_t>(len); }
inline uint64_t Hash64(const char* s, size_t len) { (void)s; return static_cast<uint64_t>(len); }
inline uint64_t Fingerprint64(const char* s, size_t len) { (void)s; return static_cast<uint64_t>(len); }
template <typename S>
inline uint64_t Fingerprint64(const S& s) {
  return Fingerprint64(s.data(), s.size());
}
}
#endif
`

const stubAlgorithmH = `// Stub for differential-privacy algorithm when not copying external.
#ifndef ALGORITHMS_ALGORITHM_STUB_H_
#define ALGORITHMS_ALGORITHM_STUB_H_
#include "absl/status/statusor.h"
#include <memory>
namespace differential_privacy {
template <typename T>
class Algorithm {
 public:
  virtual ~Algorithm() = default;
  void AddEntry(T) {}
  absl::StatusOr<int> PartialResult() const {
    return 0;
  }
};
template <typename T>
T GetValue(int) {
  return T{};
}
}
#endif
`

const stubPartitionSelectionH = `// Stub for differential-privacy partition-selection when not copying external.
#ifndef ALGORITHMS_PARTITION_SELECTION_STUB_H_
#define ALGORITHMS_PARTITION_SELECTION_STUB_H_
#include "absl/status/statusor.h"
namespace differential_privacy {
template <typename T>
class PartitionSelection { public: bool ShouldKeep(double) const { return true; } };
template <typename T>
class LaplacePartitionSelection : public PartitionSelection<T> {
 public:
  bool ShouldKeep(double epsilon) const { (void)epsilon; return true; }
  static absl::StatusOr<double> CalculateThreshold(double epsilon, double delta, int64_t kappa) {
    (void)epsilon; (void)delta; (void)kappa;
    return 0.0;
  }
  static absl::StatusOr<double> CalculateDelta(double epsilon, int64_t k_threshold, int64_t kappa) {
    (void)epsilon; (void)k_threshold; (void)kappa;
    return 0.0;
  }
};
}
#endif
`

const stubBoundedMeanH = `// Stub for differential-privacy bounded-mean when not copying external.
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
}
#endif
`

const stubBoundedSumH = `// Stub for differential-privacy bounded-sum when not copying external.
#ifndef ALGORITHMS_BOUNDED_SUM_STUB_H_
#define ALGORITHMS_BOUNDED_SUM_STUB_H_
#include "absl/status/statusor.h"
#include "algorithms/algorithm.h"
#include <memory>
namespace differential_privacy {
template <typename T>
class BoundedSum : public Algorithm<T> {
 public:
  T Sum() const { return T{}; }
  class Builder {
   public:
    Builder& SetEpsilon(double) { return *this; }
    Builder& SetLower(T) { return *this; }
    Builder& SetUpper(T) { return *this; }
    absl::StatusOr<std::unique_ptr<Algorithm<T>>> Build() {
      return std::make_unique<BoundedSum>();
    }
  };
};
}
#endif
`

const stubBoundedVarianceH = `// Stub for differential-privacy bounded-variance when not copying external.
#ifndef ALGORITHMS_BOUNDED_VARIANCE_STUB_H_
#define ALGORITHMS_BOUNDED_VARIANCE_STUB_H_
#include "absl/status/statusor.h"
#include "algorithms/algorithm.h"
#include <memory>
namespace differential_privacy {
template <typename T>
class BoundedVariance : public Algorithm<T> {
 public:
  double Variance() const { return 0; }
  class Builder {
   public:
    Builder& SetEpsilon(double) { return *this; }
    Builder& SetLower(T) { return *this; }
    Builder& SetUpper(T) { return *this; }
    absl::StatusOr<std::unique_ptr<Algorithm<T>>> Build() {
      return std::make_unique<BoundedVariance>();
    }
  };
};
}
#endif
`

const stubBoundedStandardDeviationH = `// Stub for differential-privacy bounded-standard-deviation when not copying external.
#ifndef ALGORITHMS_BOUNDED_STANDARD_DEVIATION_STUB_H_
#define ALGORITHMS_BOUNDED_STANDARD_DEVIATION_STUB_H_
#include "absl/status/statusor.h"
#include "algorithms/algorithm.h"
#include <memory>
namespace differential_privacy {
template <typename T>
class BoundedStandardDeviation : public Algorithm<T> {
 public:
  double StdDev() const { return 0; }
  class Builder {
   public:
    Builder& SetEpsilon(double) { return *this; }
    Builder& SetLower(T) { return *this; }
    Builder& SetUpper(T) { return *this; }
    absl::StatusOr<std::unique_ptr<Algorithm<T>>> Build() {
      return std::make_unique<BoundedStandardDeviation>();
    }
  };
};
}
#endif
`
