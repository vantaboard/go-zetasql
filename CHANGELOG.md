## 0.6.0 (2026-02-04)

#### Feature

* **bump:** build, updater, install, and Go API surface for 2022.02.01 (eb1d9e40)
* **generator:** generate bridge.inc C stubs and include in cgo (9568f2c4)
* **install:** add ZetaSQL installer and move internal/cmd to cmd (9b9d7f17)
* add semantic release (2ae24716)

#### Bug Fixes

* release issues with build condition (8a16ab2e)
* **generator:** root bind safe imports, CToGo, export.inc, LaplacePartitionSelection stubs (01158d8c)
* **generator:** parser package lookup and root call dep packages (248c55fa)
* **generator:** expand differential privacy stubs for reference_impl/function.cc (4b618b64)
* **generator:** suppress deprecated-builtins and skip bridge.inc for root (76e7b134)
* **build:** root bind linking and persistent ccall patches/stubs (89be6eb0)
* **updater:** harden pipeline with resolved_ast target, verification, and docs (e17beb0e)
* **updater:** install Bazel version from googlesql/.bazelversion (8841107a)
* **install:** resolve version from module and improve 404 error message (389f42bf)
* update upstream workflow was removing submodule (21653f0f)
* zetasql rename resolution (efd0e538)
* SimpleTypeNode.TypeName returns *PathExpressionNode (be08f3da)

#### Documentation

* add copyright notice to LICENSE for Apache 2.0 compliance (f1d2a8ca)
* **updater:** document docker run -it for inspecting cache (ef61734e)

#### Chores

* update release to run and remove the test one for now (bde2601d)
* cursor zetasql install plan (5b943dc2)
* add NOTICE and include LICENSE/NOTICE in release tarballs (edeae29d)
* cursor plans and rules (705153f5)
* remove submodule, use googlesql clone-at-build at pinned commit (9aa2091d)
* remove gitignored files (2fe732f3)

#### Build

* **updater:** harden Dockerfile and bump Java/Bazelisk (183e33a3)

#### CI

* add upstream-update workflow and adjust CI for submodules (e3e15902)

