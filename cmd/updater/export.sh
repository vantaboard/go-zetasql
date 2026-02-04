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
  # Build targets that produce all generated headers (e.g. resolved_ast.h) required by the CGo build.
  bazel build '//zetasql/public:sql_formatter' '//zetasql/resolved_ast:resolved_ast'
  OUTPUT_BASE=$(bazel info output_base)
fi

# bazel-out lives inside execroot at execroot/<workspace>/bazel-out, not at output_base/bazel-out
cp -r "$OUTPUT_BASE/execroot" /tmp/
[ -d "$OUTPUT_BASE/external" ] && cp -r "$OUTPUT_BASE/external" /tmp/ || true
