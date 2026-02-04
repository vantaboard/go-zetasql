# Updater: build GoogleSQL and copy to internal/ccall

This directory builds the [google/googlesql](https://github.com/google/googlesql) C++ tree and copies it (plus Bazel output and external deps) into the repo's `internal/ccall`. That tree is not committed; consumers get it via the **installer** (pre-built tarballs) or by running this updater.

## No submodule

GoogleSQL is **not** a submodule. It is cloned at build time into `./googlesql` (gitignored), then the Docker image is built and the updater copies files into `internal/ccall`.

## Build (local or CI)

1. **Clone googlesql** at the pinned commit (default: `3465a9281a7b258711782af5ae5e7c75f0e24358`, or set `UPSTREAM_COMMIT` or `GOOGLESQL_COMMIT`):

   ```bash
   make clone-googlesql
   # Or at a specific commit:
   make clone-googlesql GOOGLESQL_COMMIT=3465a9281a7b258711782af5ae5e7c75f0e24358
   ```

2. **Build and export** (Docker + Bazel):

   ```bash
   make build   # depends on clone-googlesql
   make export
   ```

   The export must complete successfully so that Bazel-generated headers (e.g. `resolved_ast.h`, `*.pb.h`) are present in the cache. Without them, `make build` from the repo root will fail with missing-header errors.

3. **Copy to internal/ccall**:

   ```bash
   make update
   ```

4. **Generate Go bindings** (from repo root):

   ```bash
   cd ../..
   make generate
   ```

5. **Build the Go module** (from repo root):

   ```bash
   make build
   ``` To push pre-built artifacts, run the release-assets workflow (it clones googlesql, builds, and uploads the tarball).

## Inspecting the cache

You can run an interactive shell in the built image to inspect the raw cache (e.g. Bazel output under `/tmp` after `export`):

```bash
docker run -it --rm zetasql
```

## Removing the old submodule (one-time)

If you still have the old `cmd/updater/zetasql` submodule in your clone:

```bash
git submodule deinit cmd/updater/zetasql
git rm cmd/updater/zetasql
rm -rf .git/modules/cmd/updater/zetasql
```

Then use `clone-googlesql` as above.
