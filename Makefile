# Check for internal/ccall (from installer or cmd/updater); exit with message if missing.
CCALL_MARKER := internal/ccall/go-googlesql
# Package roots only; do not use ./... or go list will try to load cmd/updater/cache and fail
GO_PKGS := $(shell go list -tags=ccall ./cmd/install ./cmd/generator ./cmd/updater ./internal/... ./ast/... ./types/... ./resolved_ast/... . 2>/dev/null)

# Generate Go bindings in internal/ccall. Build the generator first, then run it (run after cmd/updater: make export && make update).
generate:
	@mkdir -p .bin
	go build -o .bin/generator ./cmd/generator
	.bin/generator

build:
	@if [ ! -d "$(CCALL_MARKER)" ]; then \
		echo ""; \
		echo "internal/ccall not found. Run the installer first:"; \
		echo "  go run github.com/vantaboard/go-googlesql/cmd/install@latest"; \
		echo ""; \
		echo "Or build from source: cd cmd/updater && make export && make update && cd ../.. && make generate"; \
		echo ""; \
		exit 1; \
	fi
	@if [ -z "$$(find $(CCALL_MARKER) -maxdepth 1 -name '*.go' 2>/dev/null)" ]; then \
		echo ""; \
		echo "internal/ccall/go-googlesql has no Go bindings. Run: make generate"; \
		echo ""; \
		exit 1; \
	fi
	CGO_ENABLED=1 go build -tags=ccall $(GO_PKGS)

docker/build:
	docker build -t go-googlesql .

test/linux: docker/build
	docker run --rm go-googlesql bash -c "go test -v ./..."
