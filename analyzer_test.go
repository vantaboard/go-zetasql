package googlesql_test

import (
	"testing"

	"github.com/vantaboard/go-googlesql"
	ast "github.com/vantaboard/go-googlesql/resolved_ast"
	"github.com/vantaboard/go-googlesql/types"
)

func TestAnalyzer(t *testing.T) {
	const tableName = "z_table"
	catalog := types.NewSimpleCatalog("z_catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
		}),
	)
	catalog.AddGoogleSQLBuiltinFunctions(nil)
	langOpt := googlesql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(googlesql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.SetEnabledLanguageFeatures([]googlesql.LanguageFeature{
		googlesql.FeatureNamedArguments,
		googlesql.FeatureNumericType,
		googlesql.FeatureTablesample,
		googlesql.FeatureTimestampNanos,
		googlesql.FeatureV11HavingInAggregate,
		googlesql.FeatureV11NullHandlingModifierInAggregate,
		googlesql.FeatureV11OrderByCollate,
		googlesql.FeatureV11SelectStarExceptReplace,
		googlesql.FeatureV12SafeFunctionCall,
		googlesql.FeatureJsonType,
		googlesql.FeatureJsonArrayFunctions,
		googlesql.FeatureJsonStrictNumberParsing,
	})
	langOpt.SetSupportedStatementKinds([]ast.Kind{
		ast.QueryStmt, ast.InsertStmt, ast.UpdateStmt, ast.DeleteStmt,
	})
	opt := googlesql.NewAnalyzerOptions()
	opt.SetAllowUndeclaredParameters(true)
	opt.SetLanguage(langOpt)
	opt.SetParseLocationRecordType(googlesql.ParseLocationRecordFullNodeScope)

	out, err := googlesql.AnalyzeStatement("SELECT * FROM z_table WHERE col1 = 1000", catalog, opt)
	if err != nil {
		t.Fatal(err)
	}
	stmt := out.Statement()
	if err := ast.Walk(stmt, func(n ast.Node) error {
		locRange := n.ParseLocationRange()
		if locRange != nil {
			t.Logf("%T[%s] %s", n, locRange, n.DebugString())
		} else {
			t.Logf("%T %s", n, n.DebugString())
		}
		return nil
	}); err != nil {
		t.Fatal(err)
	}
	query := stmt.(*ast.QueryStmtNode)
	outputColumns := query.OutputColumnList()
	if len(outputColumns) != 2 {
		t.Fatal("failed to get output column list")
	}
	col1 := outputColumns[0].Column()
	col2 := outputColumns[1].Column()
	if col1.Name() != "col1" || col2.Name() != "col2" {
		t.Fatalf("failed to get column name")
	}
	if col1.Type().TypeName(0) != "INT64" || col2.Type().TypeName(0) != "STRING" {
		t.Fatalf("failed to get column type")
	}
	project := query.Query().(*ast.ProjectScanNode)
	filter := project.InputScan().(*ast.FilterScanNode)
	if filter.InputScan().(*ast.TableScanNode).Table().Name() != "z_table" {
		t.Fatal("failed to get table name")
	}
	funcCall := filter.FilterExpr().(*ast.FunctionCallNode)
	fn := funcCall.Function()
	if !fn.IsGoogleSQLBuiltin() || fn.Name() != "$equal" {
		t.Fatalf("failed to get function: %s", fn.Name())
	}
	fnArgs := funcCall.ArgumentList()
	if len(fnArgs) != 2 {
		t.Fatalf("failed to get function arguments: %d", len(fnArgs))
	}
	if fnArgs[0].(*ast.ColumnRefNode).Column().Name() != "col1" {
		t.Fatal("failed to get function argument column name")
	}
	if fnArgs[1].(*ast.LiteralNode).Value().Int64Value() != 1000 {
		t.Fatal("failed to get function argument value")
	}
}

func TestAnalyzeMultiStatements(t *testing.T) {
	const tableName = "table"
	catalog := types.NewSimpleCatalog("catalog")
	catalog.AddTable(
		types.NewSimpleTable(tableName, []types.Column{
			types.NewSimpleColumn(tableName, "col1", types.Int64Type()),
			types.NewSimpleColumn(tableName, "col2", types.StringType()),
		}),
	)
	langOpt := googlesql.NewLanguageOptions()
	langOpt.SetNameResolutionMode(googlesql.NameResolutionDefault)
	langOpt.SetProductMode(types.ProductExternal)
	langOpt.EnableMaximumLanguageFeatures()
	langOpt.SetSupportedStatementKinds([]ast.Kind{ast.CreateFunctionStmt, ast.QueryStmt})
	catalog.AddGoogleSQLBuiltinFunctions(langOpt.BuiltinFunctionOptions())
	opt := googlesql.NewAnalyzerOptions()
	opt.SetAllowUndeclaredParameters(true)
	opt.SetLanguage(langOpt)
	query := `
CREATE TEMP FUNCTION Add(x INT64, y INT64) AS (x + y);
SELECT Add(3, 4);
`
	loc := googlesql.NewParseResumeLocation(query)
	out, isEnd, err := googlesql.AnalyzeNextStatement(loc, catalog, opt)
	if err != nil {
		t.Fatal(err)
	}
	if isEnd {
		t.Fatalf("failed to read multiple statement")
	}
	fnNode, ok := out.Statement().(*ast.CreateFunctionStmtNode)
	if !ok {
		t.Fatalf("failed to get create function statement node: %T", out.Statement())
	}
	fn := types.NewFunction(
		[]string{"Add"},
		"",
		types.ScalarMode,
		[]*types.FunctionSignature{fnNode.Signature()},
	)
	catalog.AddFunction(fn)
	out, isEnd, err = googlesql.AnalyzeNextStatement(loc, catalog, opt)
	if err != nil {
		t.Fatal(err)
	}
	if !isEnd {
		t.Fatalf("failed to get isEnd flag")
	}
	if _, ok := out.Statement().(*ast.QueryStmtNode); !ok {
		t.Fatalf("failed to get query statement node: %T", out.Statement())
	}
}
