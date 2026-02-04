CCALL_DIR := $(abspath $(CURDIR)/../../internal/ccall)
EXTERNAL_DIR := $(abspath $(CURDIR)/cache/external)
OUT_DIR := $(abspath $(CURDIR)/cache/execroot/com_google_googlesql/bazel-out/k8-fastbuild/bin)
OUT_EXTERNAL_DIR := $(OUT_DIR)/external

# Tag or commit for googlesql clone: read from UPSTREAM_COMMIT file, or GOOGLESQL_COMMIT env, else fallback.
GOOGLESQL_COMMIT ?= $(shell c=$$(cat UPSTREAM_COMMIT 2>/dev/null | tr -d '\n'); if [ -n "$$c" ]; then echo "$$c"; else echo "2022.02.01"; fi)
GOOGLESQL_URL ?= https://github.com/google/googlesql.git

# Clone googlesql at COMMIT into ./googlesql; required before build. Not committed (in .gitignore).
clone-googlesql:
	@COMMIT="$(GOOGLESQL_COMMIT)"; \
	if [ -z "$$COMMIT" ]; then COMMIT=$$(cat UPSTREAM_COMMIT 2>/dev/null | tr -d '\n'); fi; \
	if [ -z "$$COMMIT" ]; then COMMIT="2022.02.01"; fi; \
	if [ -d googlesql/.git ]; then \
		(cd googlesql && git fetch origin "$$COMMIT" 2>/dev/null || git fetch origin && git checkout "$$COMMIT"); \
	else \
		rm -rf googlesql && git clone $(GOOGLESQL_URL) googlesql && (cd googlesql && git checkout "$$COMMIT"); \
	fi; \
	echo "googlesql at $$COMMIT"

build: clone-googlesql
	docker build -t zetasql .

export: build
	docker run --rm -v "$(CURDIR)/cache:/tmp" zetasql sh -c "bash export.sh"

update:
	go run main.go
