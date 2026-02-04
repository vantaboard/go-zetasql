# go-googlesql

![Go](https://github.com/vantaboard/go-googlesql/workflows/Go/badge.svg)
[![GoDoc](https://godoc.org/github.com/vantaboard/go-googlesql?status.svg)](https://pkg.go.dev/github.com/vantaboard/go-googlesql?tab=doc)

Go bindings for [GoogleSQL](https://github.com/google/googlesql)

GoogleSQL can parse all queries related to Cloud Spanner and BigQuery. This functionality is provided from the Go language using cgo. 

# Features

- Pre-built GoogleSQL artifacts (installer)
  - Run the installer once to download the GoogleSQL C++ bindings for your platform; no need to build from source. Pre-built artifacts are published for each release (e.g. linux-amd64). See [Installation](#installation).

- Can create a portable single binary even though it using cgo
  - You can create a static binary even with `CGO_ENABLED=1` by specifying the following options at build time: `--ldflags '-extldflags "-static"'`

- Can access all the APIs of the GoogleSQL parser
  - The GoogleSQL parser is not publicly available, but it is available in go-googlesql

- Can access analyzer APIs

# Status

In the features of GoogleSQL, you can use the functions of the following packages. Will be added sequentially.

| Package        | Supported  |
| ----           | ----       |
| parser         | yes        |
| public         | partial    |
| analyzer       | yes        |
| scripting      | no         |
| reference_impl | no         |

# Prerequisites

go-googlesql uses cgo. Therefore, `CGO_ENABLED=1` is required to build.  
Also, the compiler recommends `clang++`. Please set `CXX=clang++` to install.

|  Environment Name |  Value                   |
| ----              | ----                     |
|  CGO_ENABLED      |  1  ( required )         |
|  CXX              |  clang++ ( recommended ) |

# Installation

1. Add the module to your project:

   ```
   go get github.com/vantaboard/go-googlesql
   ```

2. Run the installer once so that the GoogleSQL C++ bindings (`internal/ccall`) are available. This downloads a pre-built artifact for your platform (e.g. linux-amd64, darwin-arm64) from GitHub releases:

   ```
   go run github.com/vantaboard/go-googlesql/cmd/install@latest
   ```

   Or pin to a specific version:

   ```
   go run github.com/vantaboard/go-googlesql/cmd/install@v0.1.0
   ```

   Optional: set `ZETASQL_CACHE_DIR` to change where artifacts are cached, or `ZETASQL_DOWNLOAD_BASE_URL` to use a custom download URL.

3. If no pre-built artifact exists for your platform (e.g. unsupported OS/arch), build from source using the updater (Docker + Bazel):

   ```
   cd cmd/updater && make build && make export && make update
   ```

   See [cmd/updater](cmd/updater) for prerequisites.

   **If you see a build error** like `no required module provides package ... internal/ccall` or `cannot find package ... internal/ccall`, run the installer (step 2) first, then build with `go build -tags=ccall ./...` or `make build`.

# Synopsis

## Parse SQL statement

```go
package main

import (
  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/ast"
)

func main() {

  stmt, err := googlesql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
  if err != nil {
    panic(err)
  }

  // use type assertion and get concrete nodes.
  queryStmt := stmt.(*ast.QueryStatementNode)
}
```

If you want to know the specific node of ast.Node, you can traverse by using ast.Walk.

```go
package main

import (
  "fmt"

  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/ast"
)

func main() {

  stmt, err := googlesql.ParseStatement("SELECT * FROM Samples WHERE id = 1", nil)
  if err != nil {
    panic(err)
  }

  // traverse all nodes of stmt.
  ast.Walk(stmt, func(n ast.Node) error {
    fmt.Printf("node: %T loc:%s\n", n, n.ParseLocationRange())
    return nil
  })
}
```

## Analyze SQL statement

If you have table information, you can use the analyzer API by using it as a Catalog.
By using analyzer API, you can parse SQL based on table information and output normalized node.
If you want to know the specific node of resolved_ast.Node, you can traverse by using resolved_ast.Walk.

```go
package main

import (
  "fmt"

  "github.com/vantaboard/go-googlesql"
  "github.com/vantaboard/go-googlesql/resolved_ast"
  "github.com/vantaboard/go-googlesql/types"
)

func main() {
  const tableName = "Samples"
  catalog := types.NewSimpleCatalog("catalog")
  catalog.AddTable(
    types.NewSimpleTable(tableName, []types.Column{
      types.NewSimpleColumn(tableName, "id", types.Int64Type()),
      types.NewSimpleColumn(tableName, "name", types.StringType()),
    }),
  )
  catalog.AddGoogleSQLBuiltinFunctions()
  out, err := googlesql.AnalyzeStatement("SELECT * FROM Samples WHERE id = 1000", catalog, nil)
  if err != nil {
    panic(err)
  }

  // get statement node from googlesql.AnalyzerOutput.
  stmt := out.Statement()

  // traverse all nodes of stmt.
  if err := resolved_ast.Walk(stmt, func(n resolved_ast.Node) error {
    fmt.Printf("%T\n", n)
    return nil
  }); err != nil {
    panic(err)
  }
}
```


Also, you can use the `node.DebugString()` API to dump the result of resolved_ast.Node.
This helps to understand all nodes of statement.

```go
stmt := out.Statement()
fmt.Println(stmt.DebugString())
```

# License

Apache-2.0 License

When building from source (cmd/updater), go-googlesql uses the source code of the following libraries. Therefore, the license is set according to the license of the dependent library.

- [googlesql](https://github.com/google/googlesql): [Apache License 2.0](https://github.com/google/googlesql/blob/master/LICENSE)
- [abseil](https://github.com/abseil/abseil-cpp): [Apache License 2.0](https://github.com/abseil/abseil-cpp/blob/master/LICENSE)
- [json](https://github.com/nlohmann/json): [MIT License](https://github.com/nlohmann/json/blob/develop/LICENSE.MIT)
- [re2](https://github.com/google/re2): [BSD 3-Clause](https://github.com/google/re2/blob/main/LICENSE)
- [boringssl](https://github.com/google/boringssl): [ISC License](https://github.com/google/boringssl/blob/master/LICENSE)
- [protobuf](https://github.com/protocolbuffers/protobuf): [License](https://github.com/protocolbuffers/protobuf/blob/master/LICENSE)
- [icu](https://github.com/unicode-org/icu): [ICU License](https://github.com/unicode-org/icu/blob/main/icu4c/LICENSE)
- [farmhash](https://github.com/google/farmhash): [MIT License](https://github.com/google/farmhash/blob/master/COPYING)
- [googletest](https://github.com/google/googletest): [BSK 3-Clause](https://github.com/google/googletest/blob/main/LICENSE)
