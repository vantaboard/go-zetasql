# Use Bullseye: Python 3.9 (collections.Mapping still in collections) and older glibc/GCC (SIGSTKSZ macro, no constexpr strictness).
# Install Go 1.25 from tarball since official image only has 1.25-bookworm and 1.25-trixie (newer Python/glibc).
FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    curl ca-certificates gnupg make g++ git python3 openjdk-17-jdk unzip libtinfo5 \
    && rm -rf /var/lib/apt/lists/*

RUN curl -fsSL https://go.dev/dl/go1.25.6.linux-amd64.tar.gz | tar -C /usr/local -xzf - \
    && echo 'export PATH=$PATH:/usr/local/go/bin' >> /etc/profile.d/go.sh
ENV PATH="/usr/local/go/bin:${PATH}"

RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor -o /usr/share/keyrings/bazel-archive-keyring.gpg \
    && echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list

# Install Bazel version required by googlesql (from .bazelversion). Versioned package installs /usr/bin/bazel-<ver>; symlink to bazel.
COPY googlesql/.bazelversion /tmp/googlesql-bazelversion
RUN BAZEL_VER="$(cat /tmp/googlesql-bazelversion)" \
    && apt-get update && apt-get install --no-install-recommends -y "bazel-${BAZEL_VER}" \
    && ln -sf "/usr/bin/bazel-${BAZEL_VER}" /usr/bin/bazel \
    && rm -rf /var/lib/apt/lists/* \
    && rm /tmp/googlesql-bazelversion

RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100

COPY googlesql /googlesql

WORKDIR /googlesql

# Build targets that produce all generated headers and protos required by the CGo build.
# reference_impl is omitted for 2022.02.01 (no BUILD in zetasql/reference_impl at that tag).
RUN bazel build \
  '//zetasql/public:sql_formatter' \
  '//zetasql/resolved_ast:resolved_ast' \
  '//zetasql/resolved_ast:comparator' \
  '//zetasql/base/net:public_suffix_oss' \
  '//zetasql/parser:parse_tree_serializer' \
  '//zetasql/scripting:script_exception_cc_proto' \
  '//zetasql/scripting:script_executor_state_cc_proto' \
  '//zetasql/public/functions:common_proto'

COPY export.sh .
