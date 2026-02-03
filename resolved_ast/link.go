package resolved_ast

import (
	"unsafe"

	"github.com/vantaboard/go-googlesql/types"
)

//go:linkname newValue github.com/vantaboard/go-googlesql/types.newValue
func newValue(unsafe.Pointer) types.Value

//go:linkname getRawValue github.com/vantaboard/go-googlesql/types.getRawValue
func getRawValue(types.Value) unsafe.Pointer

//go:linkname newType github.com/vantaboard/go-googlesql/types.newType
func newType(unsafe.Pointer) types.Type

//go:linkname getRawType github.com/vantaboard/go-googlesql/types.getRawType
func getRawType(types.Type) unsafe.Pointer

//go:linkname newTypeParameters github.com/vantaboard/go-googlesql/types.newTypeParameters
func newTypeParameters(unsafe.Pointer) *types.TypeParameters

//go:linkname getRawTypeParameters github.com/vantaboard/go-googlesql/types.getRawTypeParameters
func getRawTypeParameters(*types.TypeParameters) unsafe.Pointer

//go:linkname newAnnotationMap github.com/vantaboard/go-googlesql/types.newAnnotationMap
func newAnnotationMap(unsafe.Pointer) types.AnnotationMap

//go:linkname getRawAnnotationMap github.com/vantaboard/go-googlesql/types.getRawAnnotationMap
func getRawAnnotationMap(types.AnnotationMap) unsafe.Pointer

//go:linkname newAnnotatedType github.com/vantaboard/go-googlesql/types.newAnnotatedType
func newAnnotatedType(unsafe.Pointer) *types.AnnotatedType

//go:linkname getRawAnnotatedType github.com/vantaboard/go-googlesql/types.getRawAnnotatedType
func getRawAnnotatedType(*types.AnnotatedType) unsafe.Pointer

//go:linkname newConstant github.com/vantaboard/go-googlesql/types.newConstant
func newConstant(unsafe.Pointer) types.Constant

//go:linkname getRawConstant github.com/vantaboard/go-googlesql/types.getRawConstant
func getRawConstant(types.Constant) unsafe.Pointer

//go:linkname newFunction github.com/vantaboard/go-googlesql/types.newFunction
func newFunction(unsafe.Pointer) *types.Function

//go:linkname getRawFunction github.com/vantaboard/go-googlesql/types.getRawFunction
func getRawFunction(*types.Function) unsafe.Pointer

//go:linkname newFunctionSignature github.com/vantaboard/go-googlesql/types.newFunctionSignature
func newFunctionSignature(unsafe.Pointer) *types.FunctionSignature

//go:linkname getRawFunctionSignature github.com/vantaboard/go-googlesql/types.getRawFunctionSignature
func getRawFunctionSignature(*types.FunctionSignature) unsafe.Pointer

//go:linkname newModel github.com/vantaboard/go-googlesql/types.newModel
func newModel(unsafe.Pointer) types.Model

//go:linkname getRawModel github.com/vantaboard/go-googlesql/types.getRawModel
func getRawModel(types.Model) unsafe.Pointer

//go:linkname newConnection github.com/vantaboard/go-googlesql/types.newConnection
func newConnection(unsafe.Pointer) types.Connection

//go:linkname getRawConnection github.com/vantaboard/go-googlesql/types.getRawConnection
func getRawConnection(types.Connection) unsafe.Pointer

//go:linkname newTable github.com/vantaboard/go-googlesql/types.newTable
func newTable(unsafe.Pointer) types.Table

//go:linkname getRawTable github.com/vantaboard/go-googlesql/types.getRawTable
func getRawTable(types.Table) unsafe.Pointer

//go:linkname newTableValuedFunction github.com/vantaboard/go-googlesql/types.newSQLTableValuedFunction
func newTableValuedFunction(unsafe.Pointer) types.TableValuedFunction

//go:linkname getRawTableValuedFunction github.com/vantaboard/go-googlesql/types.getRawTableValuedFunction
func getRawTableValuedFunction(types.TableValuedFunction) unsafe.Pointer

//go:linkname newTVFSignature github.com/vantaboard/go-googlesql/types.newTVFSignature
func newTVFSignature(unsafe.Pointer) *types.TVFSignature

//go:linkname getRawTVFSignature github.com/vantaboard/go-googlesql/types.getRawTVFSignature
func getRawTVFSignature(*types.TVFSignature) unsafe.Pointer

//go:linkname newProcedure github.com/vantaboard/go-googlesql/types.newProcedure
func newProcedure(unsafe.Pointer) types.Procedure

//go:linkname getRawProcedure github.com/vantaboard/go-googlesql/types.getRawProcedure
func getRawProcedure(types.Procedure) unsafe.Pointer

//go:linkname newParseLocationRange github.com/vantaboard/go-googlesql/types.newParseLocationRange
func newParseLocationRange(unsafe.Pointer) *types.ParseLocationRange

//go:linkname getRawParseLocationRange github.com/vantaboard/go-googlesql/types.getRawParseLocationRange
func getRawParseLocationRange(*types.ParseLocationRange) unsafe.Pointer
