package ast

import (
	"unsafe"

	"github.com/vantaboard/go-googlesql/types"
)

//go:linkname newParseLocationPoint github.com/vantaboard/go-googlesql/types.newParseLocationPoint
func newParseLocationPoint(unsafe.Pointer) *types.ParseLocationPoint

//go:linkname getRawParseLocationPoint github.com/vantaboard/go-googlesql/types.getRawParseLocationPoint
func getRawParseLocationPoint(*types.ParseLocationPoint) unsafe.Pointer

//go:linkname newParseLocationRange github.com/vantaboard/go-googlesql/types.newParseLocationRange
func newParseLocationRange(unsafe.Pointer) *types.ParseLocationRange

//go:linkname getRawParseLocationRange github.com/vantaboard/go-googlesql/types.getRawParseLocationRange
func getRawParseLocationRange(*types.ParseLocationRange) unsafe.Pointer
