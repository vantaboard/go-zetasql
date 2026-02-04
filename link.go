package googlesql

import (
	"unsafe"

	"github.com/vantaboard/go-googlesql/ast"
	"github.com/vantaboard/go-googlesql/resolved_ast"
	"github.com/vantaboard/go-googlesql/types"
)

//go:linkname getRawCatalog github.com/vantaboard/go-googlesql/types.getRawCatalog
func getRawCatalog(types.Catalog) unsafe.Pointer

//go:linkname newResolvedNode github.com/vantaboard/go-googlesql/resolved_ast.newNode
func newResolvedNode(unsafe.Pointer) resolved_ast.Node

//go:linkname getRawResolvedNode github.com/vantaboard/go-googlesql/resolved_ast.getRawNode
func getRawResolvedNode(resolved_ast.Node) unsafe.Pointer

//go:linkname newType github.com/vantaboard/go-googlesql/types.newType
func newType(unsafe.Pointer) types.Type

//go:linkname getRawType github.com/vantaboard/go-googlesql/types.getRawType
func getRawType(types.Type) unsafe.Pointer

//go:linkname newBuiltinFunctionOptions github.com/vantaboard/go-googlesql/types.newBuiltinFunctionOptions
func newBuiltinFunctionOptions(unsafe.Pointer) *types.BuiltinFunctionOptions

//go:linkname newNode github.com/vantaboard/go-googlesql/ast.newNode
func newNode(unsafe.Pointer) ast.Node

//go:linkname getNodeRaw github.com/vantaboard/go-googlesql/ast.getNodeRaw
func getNodeRaw(ast.Node) unsafe.Pointer
