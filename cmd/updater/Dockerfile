FROM golang:1.21-bookworm

RUN apt-get update && apt-get install -y --no-install-recommends curl ca-certificates gnupg
RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor -o /usr/share/keyrings/bazel-archive-keyring.gpg
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | tee /etc/apt/sources.list.d/bazel.list
RUN apt-get update && apt-get install --no-install-recommends -y make g++ git python3 openjdk-17-jdk unzip libtinfo5
RUN update-alternatives --install /usr/bin/python python /usr/bin/python3 100
RUN go install github.com/bazelbuild/bazelisk@v1.19.0 && ln -s /go/bin/bazelisk /usr/local/bin/bazel

COPY googlesql /googlesql

WORKDIR /googlesql

RUN bazel build '//googlesql/public:sql_formatter'

COPY export.sh .
