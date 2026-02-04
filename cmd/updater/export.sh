#!/bin/bash
set -e

# Find Bazel output_base. Prefer the workspace symlinks (bazel-out in /googlesql from
# the image build) so we don't start a new server and get an empty path.
if [ -e /googlesql/bazel-out ]; then
  REAL=$(readlink -f /googlesql/bazel-out)
  D=$(dirname "$REAL")
  while [ "$D" != "/" ]; do
    if [ -d "$D/execroot" ]; then
      OUTPUT_BASE=$D
      break
    fi
    D=$(dirname "$D")
  done
fi
if [ -z "$OUTPUT_BASE" ]; then
  # Build targets that produce all generated headers and protos required by the CGo build.
  # reference_impl omitted for 2022.02.01 (no BUILD in zetasql/reference_impl at that tag).
  bazel build \
    '//zetasql/public:sql_formatter' \
    '//zetasql/resolved_ast:resolved_ast' \
    '//zetasql/resolved_ast:comparator' \
    '//zetasql/base/net:public_suffix_oss' \
    '//zetasql/parser:parse_tree_serializer' \
    '//zetasql/scripting:script_exception_cc_proto' \
    '//zetasql/scripting:script_executor_state_cc_proto' \
    '//zetasql/public/functions:common_proto'
  OUTPUT_BASE=$(bazel info output_base)
fi

# bazel-out lives inside execroot at execroot/<workspace>/bazel-out, not at output_base/bazel-out
cp -r "$OUTPUT_BASE/execroot" /tmp/
[ -d "$OUTPUT_BASE/external" ] && cp -r "$OUTPUT_BASE/external" /tmp/ || true
