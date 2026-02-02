#ifndef STORAGE_GOOGLESQL_PARSER_PARSE_TREE_VISITOR_H_
#define STORAGE_GOOGLESQL_PARSER_PARSE_TREE_VISITOR_H_
#include "googlesql/parser/parse_tree.h"
#include "googlesql/parser/visit_result.h"

namespace googlesql {
class ParseTreeVisitor {
 public:
  virtual ~ParseTreeVisitor() {}
  virtual void visit(const ASTNode *node, void* data) = 0;
  virtual void visitASTQueryStatement(const ASTQueryStatement* node, void* data) = 0;

  virtual void visitASTSubpipelineStatement(const ASTSubpipelineStatement* node, void* data) = 0;

  virtual void visitASTAliasedQueryExpression(const ASTAliasedQueryExpression* node, void* data) = 0;

  virtual void visitASTQuery(const ASTQuery* node, void* data) = 0;

  virtual void visitASTFromQuery(const ASTFromQuery* node, void* data) = 0;

  virtual void visitASTSubpipeline(const ASTSubpipeline* node, void* data) = 0;

  virtual void visitASTPipeExtend(const ASTPipeExtend* node, void* data) = 0;

  virtual void visitASTPipeRenameItem(const ASTPipeRenameItem* node, void* data) = 0;

  virtual void visitASTPipeRename(const ASTPipeRename* node, void* data) = 0;

  virtual void visitASTPipeAggregate(const ASTPipeAggregate* node, void* data) = 0;

  virtual void visitASTPipeSetOperation(const ASTPipeSetOperation* node, void* data) = 0;

  virtual void visitASTPipeJoin(const ASTPipeJoin* node, void* data) = 0;

  virtual void visitASTPipeCall(const ASTPipeCall* node, void* data) = 0;

  virtual void visitASTPipeWindow(const ASTPipeWindow* node, void* data) = 0;

  virtual void visitASTPipeWhere(const ASTPipeWhere* node, void* data) = 0;

  virtual void visitASTPipeSelect(const ASTPipeSelect* node, void* data) = 0;

  virtual void visitASTPipeLimitOffset(const ASTPipeLimitOffset* node, void* data) = 0;

  virtual void visitASTPipeOrderBy(const ASTPipeOrderBy* node, void* data) = 0;

  virtual void visitASTPipeDistinct(const ASTPipeDistinct* node, void* data) = 0;

  virtual void visitASTPipeTablesample(const ASTPipeTablesample* node, void* data) = 0;

  virtual void visitASTPipeMatchRecognize(const ASTPipeMatchRecognize* node, void* data) = 0;

  virtual void visitASTPipeAs(const ASTPipeAs* node, void* data) = 0;

  virtual void visitASTPipeDescribe(const ASTPipeDescribe* node, void* data) = 0;

  virtual void visitASTPipeStaticDescribe(const ASTPipeStaticDescribe* node, void* data) = 0;

  virtual void visitASTPipeAssert(const ASTPipeAssert* node, void* data) = 0;

  virtual void visitASTPipeLog(const ASTPipeLog* node, void* data) = 0;

  virtual void visitASTPipeDrop(const ASTPipeDrop* node, void* data) = 0;

  virtual void visitASTPipeSetItem(const ASTPipeSetItem* node, void* data) = 0;

  virtual void visitASTPipeSet(const ASTPipeSet* node, void* data) = 0;

  virtual void visitASTPipePivot(const ASTPipePivot* node, void* data) = 0;

  virtual void visitASTPipeUnpivot(const ASTPipeUnpivot* node, void* data) = 0;

  virtual void visitASTPipeIf(const ASTPipeIf* node, void* data) = 0;

  virtual void visitASTPipeIfCase(const ASTPipeIfCase* node, void* data) = 0;

  virtual void visitASTPipeFork(const ASTPipeFork* node, void* data) = 0;

  virtual void visitASTPipeTee(const ASTPipeTee* node, void* data) = 0;

  virtual void visitASTPipeWith(const ASTPipeWith* node, void* data) = 0;

  virtual void visitASTPipeExportData(const ASTPipeExportData* node, void* data) = 0;

  virtual void visitASTPipeCreateTable(const ASTPipeCreateTable* node, void* data) = 0;

  virtual void visitASTPipeInsert(const ASTPipeInsert* node, void* data) = 0;

  virtual void visitASTSelect(const ASTSelect* node, void* data) = 0;

  virtual void visitASTSelectList(const ASTSelectList* node, void* data) = 0;

  virtual void visitASTSelectColumn(const ASTSelectColumn* node, void* data) = 0;

  virtual void visitASTIntLiteral(const ASTIntLiteral* node, void* data) = 0;

  virtual void visitASTIdentifier(const ASTIdentifier* node, void* data) = 0;

  virtual void visitASTAlias(const ASTAlias* node, void* data) = 0;

  virtual void visitASTPathExpression(const ASTPathExpression* node, void* data) = 0;

  virtual void visitASTTablePathExpression(const ASTTablePathExpression* node, void* data) = 0;

  virtual void visitASTPipeJoinLhsPlaceholder(const ASTPipeJoinLhsPlaceholder* node, void* data) = 0;

  virtual void visitASTFromClause(const ASTFromClause* node, void* data) = 0;

  virtual void visitASTWhereClause(const ASTWhereClause* node, void* data) = 0;

  virtual void visitASTBooleanLiteral(const ASTBooleanLiteral* node, void* data) = 0;

  virtual void visitASTAndExpr(const ASTAndExpr* node, void* data) = 0;

  virtual void visitASTBinaryExpression(const ASTBinaryExpression* node, void* data) = 0;

  virtual void visitASTStringLiteral(const ASTStringLiteral* node, void* data) = 0;

  virtual void visitASTStringLiteralComponent(const ASTStringLiteralComponent* node, void* data) = 0;

  virtual void visitASTStar(const ASTStar* node, void* data) = 0;

  virtual void visitASTOrExpr(const ASTOrExpr* node, void* data) = 0;

  virtual void visitASTConcatExpr(const ASTConcatExpr* node, void* data) = 0;

  virtual void visitASTOrderingExpression(const ASTOrderingExpression* node, void* data) = 0;

  virtual void visitASTOrderBy(const ASTOrderBy* node, void* data) = 0;

  virtual void visitASTGroupingItemOrder(const ASTGroupingItemOrder* node, void* data) = 0;

  virtual void visitASTGroupingItem(const ASTGroupingItem* node, void* data) = 0;

  virtual void visitASTGroupBy(const ASTGroupBy* node, void* data) = 0;

  virtual void visitASTGroupByAll(const ASTGroupByAll* node, void* data) = 0;

  virtual void visitASTLimitAll(const ASTLimitAll* node, void* data) = 0;

  virtual void visitASTLimit(const ASTLimit* node, void* data) = 0;

  virtual void visitASTLimitOffset(const ASTLimitOffset* node, void* data) = 0;

  virtual void visitASTFloatLiteral(const ASTFloatLiteral* node, void* data) = 0;

  virtual void visitASTNullLiteral(const ASTNullLiteral* node, void* data) = 0;

  virtual void visitASTOnClause(const ASTOnClause* node, void* data) = 0;

  virtual void visitASTAliasedQuery(const ASTAliasedQuery* node, void* data) = 0;

  virtual void visitASTJoin(const ASTJoin* node, void* data) = 0;

  virtual void visitASTAliasedGroupRows(const ASTAliasedGroupRows* node, void* data) = 0;

  virtual void visitASTWithClauseEntry(const ASTWithClauseEntry* node, void* data) = 0;

  virtual void visitASTWithClause(const ASTWithClause* node, void* data) = 0;

  virtual void visitASTHaving(const ASTHaving* node, void* data) = 0;

  virtual void visitASTSimpleType(const ASTSimpleType* node, void* data) = 0;

  virtual void visitASTArrayType(const ASTArrayType* node, void* data) = 0;

  virtual void visitASTStructField(const ASTStructField* node, void* data) = 0;

  virtual void visitASTStructType(const ASTStructType* node, void* data) = 0;

  virtual void visitASTFunctionTypeArgList(const ASTFunctionTypeArgList* node, void* data) = 0;

  virtual void visitASTFunctionType(const ASTFunctionType* node, void* data) = 0;

  virtual void visitASTCastExpression(const ASTCastExpression* node, void* data) = 0;

  virtual void visitASTSelectAs(const ASTSelectAs* node, void* data) = 0;

  virtual void visitASTRollup(const ASTRollup* node, void* data) = 0;

  virtual void visitASTCube(const ASTCube* node, void* data) = 0;

  virtual void visitASTGroupingSet(const ASTGroupingSet* node, void* data) = 0;

  virtual void visitASTGroupingSetList(const ASTGroupingSetList* node, void* data) = 0;

  virtual void visitASTExpressionWithAlias(const ASTExpressionWithAlias* node, void* data) = 0;

  virtual void visitASTFunctionCall(const ASTFunctionCall* node, void* data) = 0;

  virtual void visitASTChainedBaseExpr(const ASTChainedBaseExpr* node, void* data) = 0;

  virtual void visitASTArrayConstructor(const ASTArrayConstructor* node, void* data) = 0;

  virtual void visitASTStructConstructorArg(const ASTStructConstructorArg* node, void* data) = 0;

  virtual void visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, void* data) = 0;

  virtual void visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, void* data) = 0;

  virtual void visitASTInExpression(const ASTInExpression* node, void* data) = 0;

  virtual void visitASTInList(const ASTInList* node, void* data) = 0;

  virtual void visitASTBetweenExpression(const ASTBetweenExpression* node, void* data) = 0;

  virtual void visitASTNumericLiteral(const ASTNumericLiteral* node, void* data) = 0;

  virtual void visitASTBigNumericLiteral(const ASTBigNumericLiteral* node, void* data) = 0;

  virtual void visitASTBytesLiteral(const ASTBytesLiteral* node, void* data) = 0;

  virtual void visitASTBytesLiteralComponent(const ASTBytesLiteralComponent* node, void* data) = 0;

  virtual void visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, void* data) = 0;

  virtual void visitASTMaxLiteral(const ASTMaxLiteral* node, void* data) = 0;

  virtual void visitASTJSONLiteral(const ASTJSONLiteral* node, void* data) = 0;

  virtual void visitASTCaseValueExpression(const ASTCaseValueExpression* node, void* data) = 0;

  virtual void visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, void* data) = 0;

  virtual void visitASTArrayElement(const ASTArrayElement* node, void* data) = 0;

  virtual void visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, void* data) = 0;

  virtual void visitASTCollate(const ASTCollate* node, void* data) = 0;

  virtual void visitASTDotGeneralizedField(const ASTDotGeneralizedField* node, void* data) = 0;

  virtual void visitASTDotIdentifier(const ASTDotIdentifier* node, void* data) = 0;

  virtual void visitASTDotStar(const ASTDotStar* node, void* data) = 0;

  virtual void visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, void* data) = 0;

  virtual void visitASTExpressionSubquery(const ASTExpressionSubquery* node, void* data) = 0;

  virtual void visitASTExtractExpression(const ASTExtractExpression* node, void* data) = 0;

  virtual void visitASTHavingModifier(const ASTHavingModifier* node, void* data) = 0;

  virtual void visitASTIntervalExpr(const ASTIntervalExpr* node, void* data) = 0;

  virtual void visitASTSequenceArg(const ASTSequenceArg* node, void* data) = 0;

  virtual void visitASTNamedArgument(const ASTNamedArgument* node, void* data) = 0;

  virtual void visitASTInputTableArgument(const ASTInputTableArgument* node, void* data) = 0;

  virtual void visitASTNullOrder(const ASTNullOrder* node, void* data) = 0;

  virtual void visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, void* data) = 0;

  virtual void visitASTParenthesizedJoin(const ASTParenthesizedJoin* node, void* data) = 0;

  virtual void visitASTPartitionBy(const ASTPartitionBy* node, void* data) = 0;

  virtual void visitASTSetOperation(const ASTSetOperation* node, void* data) = 0;

  virtual void visitASTSetOperationMetadataList(const ASTSetOperationMetadataList* node, void* data) = 0;

  virtual void visitASTSetOperationAllOrDistinct(const ASTSetOperationAllOrDistinct* node, void* data) = 0;

  virtual void visitASTSetOperationType(const ASTSetOperationType* node, void* data) = 0;

  virtual void visitASTSetOperationColumnMatchMode(const ASTSetOperationColumnMatchMode* node, void* data) = 0;

  virtual void visitASTSetOperationColumnPropagationMode(const ASTSetOperationColumnPropagationMode* node, void* data) = 0;

  virtual void visitASTSetOperationMetadata(const ASTSetOperationMetadata* node, void* data) = 0;

  virtual void visitASTStarExceptList(const ASTStarExceptList* node, void* data) = 0;

  virtual void visitASTStarModifiers(const ASTStarModifiers* node, void* data) = 0;

  virtual void visitASTStarReplaceItem(const ASTStarReplaceItem* node, void* data) = 0;

  virtual void visitASTStarWithModifiers(const ASTStarWithModifiers* node, void* data) = 0;

  virtual void visitASTTableSubquery(const ASTTableSubquery* node, void* data) = 0;

  virtual void visitASTUnaryExpression(const ASTUnaryExpression* node, void* data) = 0;

  virtual void visitASTExpressionWithOptAlias(const ASTExpressionWithOptAlias* node, void* data) = 0;

  virtual void visitASTUnnestExpression(const ASTUnnestExpression* node, void* data) = 0;

  virtual void visitASTWindowClause(const ASTWindowClause* node, void* data) = 0;

  virtual void visitASTWindowDefinition(const ASTWindowDefinition* node, void* data) = 0;

  virtual void visitASTWindowFrame(const ASTWindowFrame* node, void* data) = 0;

  virtual void visitASTWindowFrameExpr(const ASTWindowFrameExpr* node, void* data) = 0;

  virtual void visitASTLikeExpression(const ASTLikeExpression* node, void* data) = 0;

  virtual void visitASTQuantifiedComparisonExpression(const ASTQuantifiedComparisonExpression* node, void* data) = 0;

  virtual void visitASTWindowSpecification(const ASTWindowSpecification* node, void* data) = 0;

  virtual void visitASTWithOffset(const ASTWithOffset* node, void* data) = 0;

  virtual void visitASTAnySomeAllOp(const ASTAnySomeAllOp* node, void* data) = 0;

  virtual void visitASTStatementList(const ASTStatementList* node, void* data) = 0;

  virtual void visitASTHintedStatement(const ASTHintedStatement* node, void* data) = 0;

  virtual void visitASTStatementWithPipeOperators(const ASTStatementWithPipeOperators* node, void* data) = 0;

  virtual void visitASTExplainStatement(const ASTExplainStatement* node, void* data) = 0;

  virtual void visitASTDescribeStatement(const ASTDescribeStatement* node, void* data) = 0;

  virtual void visitASTShowStatement(const ASTShowStatement* node, void* data) = 0;

  virtual void visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, void* data) = 0;

  virtual void visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, void* data) = 0;

  virtual void visitASTTransactionModeList(const ASTTransactionModeList* node, void* data) = 0;

  virtual void visitASTBeginStatement(const ASTBeginStatement* node, void* data) = 0;

  virtual void visitASTSetTransactionStatement(const ASTSetTransactionStatement* node, void* data) = 0;

  virtual void visitASTCommitStatement(const ASTCommitStatement* node, void* data) = 0;

  virtual void visitASTRollbackStatement(const ASTRollbackStatement* node, void* data) = 0;

  virtual void visitASTStartBatchStatement(const ASTStartBatchStatement* node, void* data) = 0;

  virtual void visitASTRunBatchStatement(const ASTRunBatchStatement* node, void* data) = 0;

  virtual void visitASTAbortBatchStatement(const ASTAbortBatchStatement* node, void* data) = 0;

  virtual void visitASTDropEntityStatement(const ASTDropEntityStatement* node, void* data) = 0;

  virtual void visitASTDropFunctionStatement(const ASTDropFunctionStatement* node, void* data) = 0;

  virtual void visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, void* data) = 0;

  virtual void visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, void* data) = 0;

  virtual void visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, void* data) = 0;

  virtual void visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, void* data) = 0;

  virtual void visitASTDropVectorIndexStatement(const ASTDropVectorIndexStatement* node, void* data) = 0;

  virtual void visitASTRenameStatement(const ASTRenameStatement* node, void* data) = 0;

  virtual void visitASTImportStatement(const ASTImportStatement* node, void* data) = 0;

  virtual void visitASTModuleStatement(const ASTModuleStatement* node, void* data) = 0;

  virtual void visitASTWithConnectionClause(const ASTWithConnectionClause* node, void* data) = 0;

  virtual void visitASTIntoAlias(const ASTIntoAlias* node, void* data) = 0;

  virtual void visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, void* data) = 0;

  virtual void visitASTPivotExpression(const ASTPivotExpression* node, void* data) = 0;

  virtual void visitASTPivotValue(const ASTPivotValue* node, void* data) = 0;

  virtual void visitASTPivotExpressionList(const ASTPivotExpressionList* node, void* data) = 0;

  virtual void visitASTPivotValueList(const ASTPivotValueList* node, void* data) = 0;

  virtual void visitASTPivotClause(const ASTPivotClause* node, void* data) = 0;

  virtual void visitASTUnpivotInItem(const ASTUnpivotInItem* node, void* data) = 0;

  virtual void visitASTUnpivotInItemList(const ASTUnpivotInItemList* node, void* data) = 0;

  virtual void visitASTUnpivotClause(const ASTUnpivotClause* node, void* data) = 0;

  virtual void visitASTUsingClause(const ASTUsingClause* node, void* data) = 0;

  virtual void visitASTForSystemTime(const ASTForSystemTime* node, void* data) = 0;

  virtual void visitASTMatchRecognizeClause(const ASTMatchRecognizeClause* node, void* data) = 0;

  virtual void visitASTAfterMatchSkipClause(const ASTAfterMatchSkipClause* node, void* data) = 0;

  virtual void visitASTRowPatternVariable(const ASTRowPatternVariable* node, void* data) = 0;

  virtual void visitASTRowPatternOperation(const ASTRowPatternOperation* node, void* data) = 0;

  virtual void visitASTEmptyRowPattern(const ASTEmptyRowPattern* node, void* data) = 0;

  virtual void visitASTRowPatternAnchor(const ASTRowPatternAnchor* node, void* data) = 0;

  virtual void visitASTBoundedQuantifier(const ASTBoundedQuantifier* node, void* data) = 0;

  virtual void visitASTQuantifierBound(const ASTQuantifierBound* node, void* data) = 0;

  virtual void visitASTFixedQuantifier(const ASTFixedQuantifier* node, void* data) = 0;

  virtual void visitASTSymbolQuantifier(const ASTSymbolQuantifier* node, void* data) = 0;

  virtual void visitASTRowPatternQuantification(const ASTRowPatternQuantification* node, void* data) = 0;

  virtual void visitASTQualify(const ASTQualify* node, void* data) = 0;

  virtual void visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, void* data) = 0;

  virtual void visitASTWithReportModifier(const ASTWithReportModifier* node, void* data) = 0;

  virtual void visitASTFormatClause(const ASTFormatClause* node, void* data) = 0;

  virtual void visitASTPathExpressionList(const ASTPathExpressionList* node, void* data) = 0;

  virtual void visitASTParameterExpr(const ASTParameterExpr* node, void* data) = 0;

  virtual void visitASTSystemVariableExpr(const ASTSystemVariableExpr* node, void* data) = 0;

  virtual void visitASTLambda(const ASTLambda* node, void* data) = 0;

  virtual void visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, void* data) = 0;

  virtual void visitASTClusterBy(const ASTClusterBy* node, void* data) = 0;

  virtual void visitASTNewConstructorArg(const ASTNewConstructorArg* node, void* data) = 0;

  virtual void visitASTNewConstructor(const ASTNewConstructor* node, void* data) = 0;

  virtual void visitASTBracedConstructorLhs(const ASTBracedConstructorLhs* node, void* data) = 0;

  virtual void visitASTBracedConstructorFieldValue(const ASTBracedConstructorFieldValue* node, void* data) = 0;

  virtual void visitASTBracedConstructorField(const ASTBracedConstructorField* node, void* data) = 0;

  virtual void visitASTBracedConstructor(const ASTBracedConstructor* node, void* data) = 0;

  virtual void visitASTBracedNewConstructor(const ASTBracedNewConstructor* node, void* data) = 0;

  virtual void visitASTExtendedPathExpression(const ASTExtendedPathExpression* node, void* data) = 0;

  virtual void visitASTUpdateConstructor(const ASTUpdateConstructor* node, void* data) = 0;

  virtual void visitASTStructBracedConstructor(const ASTStructBracedConstructor* node, void* data) = 0;

  virtual void visitASTOptionsList(const ASTOptionsList* node, void* data) = 0;

  virtual void visitASTOptionsEntry(const ASTOptionsEntry* node, void* data) = 0;

  virtual void visitASTFunctionParameter(const ASTFunctionParameter* node, void* data) = 0;

  virtual void visitASTFunctionParameters(const ASTFunctionParameters* node, void* data) = 0;

  virtual void visitASTFunctionDeclaration(const ASTFunctionDeclaration* node, void* data) = 0;

  virtual void visitASTSqlFunctionBody(const ASTSqlFunctionBody* node, void* data) = 0;

  virtual void visitASTTVFArgument(const ASTTVFArgument* node, void* data) = 0;

  virtual void visitASTTVF(const ASTTVF* node, void* data) = 0;

  virtual void visitASTTableClause(const ASTTableClause* node, void* data) = 0;

  virtual void visitASTModelClause(const ASTModelClause* node, void* data) = 0;

  virtual void visitASTConnectionClause(const ASTConnectionClause* node, void* data) = 0;

  virtual void visitASTCloneDataSource(const ASTCloneDataSource* node, void* data) = 0;

  virtual void visitASTCopyDataSource(const ASTCopyDataSource* node, void* data) = 0;

  virtual void visitASTCloneDataSourceList(const ASTCloneDataSourceList* node, void* data) = 0;

  virtual void visitASTCloneDataStatement(const ASTCloneDataStatement* node, void* data) = 0;

  virtual void visitASTCreateConnectionStatement(const ASTCreateConnectionStatement* node, void* data) = 0;

  virtual void visitASTCreateConstantStatement(const ASTCreateConstantStatement* node, void* data) = 0;

  virtual void visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, void* data) = 0;

  virtual void visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, void* data) = 0;

  virtual void visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, void* data) = 0;

  virtual void visitASTCreateExternalSchemaStatement(const ASTCreateExternalSchemaStatement* node, void* data) = 0;

  virtual void visitASTAliasedQueryList(const ASTAliasedQueryList* node, void* data) = 0;

  virtual void visitASTTransformClause(const ASTTransformClause* node, void* data) = 0;

  virtual void visitASTCreateModelStatement(const ASTCreateModelStatement* node, void* data) = 0;

  virtual void visitASTIndexAllColumns(const ASTIndexAllColumns* node, void* data) = 0;

  virtual void visitASTIndexItemList(const ASTIndexItemList* node, void* data) = 0;

  virtual void visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, void* data) = 0;

  virtual void visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, void* data) = 0;

  virtual void visitASTCreateIndexStatement(const ASTCreateIndexStatement* node, void* data) = 0;

  virtual void visitASTExportDataStatement(const ASTExportDataStatement* node, void* data) = 0;

  virtual void visitASTExportModelStatement(const ASTExportModelStatement* node, void* data) = 0;

  virtual void visitASTExportMetadataStatement(const ASTExportMetadataStatement* node, void* data) = 0;

  virtual void visitASTCallStatement(const ASTCallStatement* node, void* data) = 0;

  virtual void visitASTDefineTableStatement(const ASTDefineTableStatement* node, void* data) = 0;

  virtual void visitASTCreateLocalityGroupStatement(const ASTCreateLocalityGroupStatement* node, void* data) = 0;

  virtual void visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, void* data) = 0;

  virtual void visitASTCreateSnapshotStatement(const ASTCreateSnapshotStatement* node, void* data) = 0;

  virtual void visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, void* data) = 0;

  virtual void visitASTTypeParameterList(const ASTTypeParameterList* node, void* data) = 0;

  virtual void visitASTTVFSchema(const ASTTVFSchema* node, void* data) = 0;

  virtual void visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, void* data) = 0;

  virtual void visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, void* data) = 0;

  virtual void visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, void* data) = 0;

  virtual void visitASTTemplatedParameterType(const ASTTemplatedParameterType* node, void* data) = 0;

  virtual void visitASTDefaultLiteral(const ASTDefaultLiteral* node, void* data) = 0;

  virtual void visitASTAnalyzeStatement(const ASTAnalyzeStatement* node, void* data) = 0;

  virtual void visitASTAssertStatement(const ASTAssertStatement* node, void* data) = 0;

  virtual void visitASTAssertRowsModified(const ASTAssertRowsModified* node, void* data) = 0;

  virtual void visitASTReturningClause(const ASTReturningClause* node, void* data) = 0;

  virtual void visitASTOnConflictClause(const ASTOnConflictClause* node, void* data) = 0;

  virtual void visitASTDeleteStatement(const ASTDeleteStatement* node, void* data) = 0;

  virtual void visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, void* data) = 0;

  virtual void visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, void* data) = 0;

  virtual void visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, void* data) = 0;

  virtual void visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, void* data) = 0;

  virtual void visitASTColumnAttributeList(const ASTColumnAttributeList* node, void* data) = 0;

  virtual void visitASTStructColumnField(const ASTStructColumnField* node, void* data) = 0;

  virtual void visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, void* data) = 0;

  virtual void visitASTColumnDefinition(const ASTColumnDefinition* node, void* data) = 0;

  virtual void visitASTTableElementList(const ASTTableElementList* node, void* data) = 0;

  virtual void visitASTColumnList(const ASTColumnList* node, void* data) = 0;

  virtual void visitASTColumnPosition(const ASTColumnPosition* node, void* data) = 0;

  virtual void visitASTInsertValuesRow(const ASTInsertValuesRow* node, void* data) = 0;

  virtual void visitASTInsertValuesRowList(const ASTInsertValuesRowList* node, void* data) = 0;

  virtual void visitASTInsertStatement(const ASTInsertStatement* node, void* data) = 0;

  virtual void visitASTUpdateSetValue(const ASTUpdateSetValue* node, void* data) = 0;

  virtual void visitASTUpdateItem(const ASTUpdateItem* node, void* data) = 0;

  virtual void visitASTUpdateItemList(const ASTUpdateItemList* node, void* data) = 0;

  virtual void visitASTUpdateStatement(const ASTUpdateStatement* node, void* data) = 0;

  virtual void visitASTTruncateStatement(const ASTTruncateStatement* node, void* data) = 0;

  virtual void visitASTMergeAction(const ASTMergeAction* node, void* data) = 0;

  virtual void visitASTMergeWhenClause(const ASTMergeWhenClause* node, void* data) = 0;

  virtual void visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, void* data) = 0;

  virtual void visitASTMergeStatement(const ASTMergeStatement* node, void* data) = 0;

  virtual void visitASTPrivilege(const ASTPrivilege* node, void* data) = 0;

  virtual void visitASTPrivileges(const ASTPrivileges* node, void* data) = 0;

  virtual void visitASTGranteeList(const ASTGranteeList* node, void* data) = 0;

  virtual void visitASTGrantStatement(const ASTGrantStatement* node, void* data) = 0;

  virtual void visitASTRevokeStatement(const ASTRevokeStatement* node, void* data) = 0;

  virtual void visitASTRepeatableClause(const ASTRepeatableClause* node, void* data) = 0;

  virtual void visitASTFilterFieldsArg(const ASTFilterFieldsArg* node, void* data) = 0;

  virtual void visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, void* data) = 0;

  virtual void visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, void* data) = 0;

  virtual void visitASTSampleSize(const ASTSampleSize* node, void* data) = 0;

  virtual void visitASTWithWeight(const ASTWithWeight* node, void* data) = 0;

  virtual void visitASTSampleSuffix(const ASTSampleSuffix* node, void* data) = 0;

  virtual void visitASTSampleClause(const ASTSampleClause* node, void* data) = 0;

  virtual void visitASTSetOptionsAction(const ASTSetOptionsAction* node, void* data) = 0;

  virtual void visitASTSetAsAction(const ASTSetAsAction* node, void* data) = 0;

  virtual void visitASTAddConstraintAction(const ASTAddConstraintAction* node, void* data) = 0;

  virtual void visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, void* data) = 0;

  virtual void visitASTDropConstraintAction(const ASTDropConstraintAction* node, void* data) = 0;

  virtual void visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, void* data) = 0;

  virtual void visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, void* data) = 0;

  virtual void visitASTAddColumnIdentifierAction(const ASTAddColumnIdentifierAction* node, void* data) = 0;

  virtual void visitASTAddColumnAction(const ASTAddColumnAction* node, void* data) = 0;

  virtual void visitASTDropColumnAction(const ASTDropColumnAction* node, void* data) = 0;

  virtual void visitASTRenameColumnAction(const ASTRenameColumnAction* node, void* data) = 0;

  virtual void visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, void* data) = 0;

  virtual void visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, void* data) = 0;

  virtual void visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, void* data) = 0;

  virtual void visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, void* data) = 0;

  virtual void visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, void* data) = 0;

  virtual void visitASTAlterColumnDropGeneratedAction(const ASTAlterColumnDropGeneratedAction* node, void* data) = 0;

  virtual void visitASTAlterColumnSetGeneratedAction(const ASTAlterColumnSetGeneratedAction* node, void* data) = 0;

  virtual void visitASTGrantToClause(const ASTGrantToClause* node, void* data) = 0;

  virtual void visitASTRestrictToClause(const ASTRestrictToClause* node, void* data) = 0;

  virtual void visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, void* data) = 0;

  virtual void visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, void* data) = 0;

  virtual void visitASTFilterUsingClause(const ASTFilterUsingClause* node, void* data) = 0;

  virtual void visitASTRevokeFromClause(const ASTRevokeFromClause* node, void* data) = 0;

  virtual void visitASTRenameToClause(const ASTRenameToClause* node, void* data) = 0;

  virtual void visitASTSetCollateClause(const ASTSetCollateClause* node, void* data) = 0;

  virtual void visitASTAlterSubEntityAction(const ASTAlterSubEntityAction* node, void* data) = 0;

  virtual void visitASTAddSubEntityAction(const ASTAddSubEntityAction* node, void* data) = 0;

  virtual void visitASTDropSubEntityAction(const ASTDropSubEntityAction* node, void* data) = 0;

  virtual void visitASTAddTtlAction(const ASTAddTtlAction* node, void* data) = 0;

  virtual void visitASTReplaceTtlAction(const ASTReplaceTtlAction* node, void* data) = 0;

  virtual void visitASTDropTtlAction(const ASTDropTtlAction* node, void* data) = 0;

  virtual void visitASTAlterActionList(const ASTAlterActionList* node, void* data) = 0;

  virtual void visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, void* data) = 0;

  virtual void visitASTForeignKeyActions(const ASTForeignKeyActions* node, void* data) = 0;

  virtual void visitASTForeignKeyReference(const ASTForeignKeyReference* node, void* data) = 0;

  virtual void visitASTScript(const ASTScript* node, void* data) = 0;

  virtual void visitASTElseifClause(const ASTElseifClause* node, void* data) = 0;

  virtual void visitASTElseifClauseList(const ASTElseifClauseList* node, void* data) = 0;

  virtual void visitASTIfStatement(const ASTIfStatement* node, void* data) = 0;

  virtual void visitASTWhenThenClause(const ASTWhenThenClause* node, void* data) = 0;

  virtual void visitASTWhenThenClauseList(const ASTWhenThenClauseList* node, void* data) = 0;

  virtual void visitASTCaseStatement(const ASTCaseStatement* node, void* data) = 0;

  virtual void visitASTHint(const ASTHint* node, void* data) = 0;

  virtual void visitASTHintEntry(const ASTHintEntry* node, void* data) = 0;

  virtual void visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, void* data) = 0;

  virtual void visitASTDescriptor(const ASTDescriptor* node, void* data) = 0;

  virtual void visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, void* data) = 0;

  virtual void visitASTArrayColumnSchema(const ASTArrayColumnSchema* node, void* data) = 0;

  virtual void visitASTRangeColumnSchema(const ASTRangeColumnSchema* node, void* data) = 0;

  virtual void visitASTMapColumnSchema(const ASTMapColumnSchema* node, void* data) = 0;

  virtual void visitASTPrimaryKeyElement(const ASTPrimaryKeyElement* node, void* data) = 0;

  virtual void visitASTPrimaryKeyElementList(const ASTPrimaryKeyElementList* node, void* data) = 0;

  virtual void visitASTPrimaryKey(const ASTPrimaryKey* node, void* data) = 0;

  virtual void visitASTForeignKey(const ASTForeignKey* node, void* data) = 0;

  virtual void visitASTCheckConstraint(const ASTCheckConstraint* node, void* data) = 0;

  virtual void visitASTDescriptorColumn(const ASTDescriptorColumn* node, void* data) = 0;

  virtual void visitASTDescriptorColumnList(const ASTDescriptorColumnList* node, void* data) = 0;

  virtual void visitASTCreateEntityStatement(const ASTCreateEntityStatement* node, void* data) = 0;

  virtual void visitASTRaiseStatement(const ASTRaiseStatement* node, void* data) = 0;

  virtual void visitASTExceptionHandler(const ASTExceptionHandler* node, void* data) = 0;

  virtual void visitASTExceptionHandlerList(const ASTExceptionHandlerList* node, void* data) = 0;

  virtual void visitASTBeginEndBlock(const ASTBeginEndBlock* node, void* data) = 0;

  virtual void visitASTIdentifierList(const ASTIdentifierList* node, void* data) = 0;

  virtual void visitASTVariableDeclaration(const ASTVariableDeclaration* node, void* data) = 0;

  virtual void visitASTUntilClause(const ASTUntilClause* node, void* data) = 0;

  virtual void visitASTBreakStatement(const ASTBreakStatement* node, void* data) = 0;

  virtual void visitASTContinueStatement(const ASTContinueStatement* node, void* data) = 0;

  virtual void visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTDropStatement(const ASTDropStatement* node, void* data) = 0;

  virtual void visitASTReturnStatement(const ASTReturnStatement* node, void* data) = 0;

  virtual void visitASTSingleAssignment(const ASTSingleAssignment* node, void* data) = 0;

  virtual void visitASTParameterAssignment(const ASTParameterAssignment* node, void* data) = 0;

  virtual void visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, void* data) = 0;

  virtual void visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, void* data) = 0;

  virtual void visitASTCreateTableStatement(const ASTCreateTableStatement* node, void* data) = 0;

  virtual void visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, void* data) = 0;

  virtual void visitASTCreateViewStatement(const ASTCreateViewStatement* node, void* data) = 0;

  virtual void visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTCreateApproxViewStatement(const ASTCreateApproxViewStatement* node, void* data) = 0;

  virtual void visitASTWhileStatement(const ASTWhileStatement* node, void* data) = 0;

  virtual void visitASTRepeatStatement(const ASTRepeatStatement* node, void* data) = 0;

  virtual void visitASTForInStatement(const ASTForInStatement* node, void* data) = 0;

  virtual void visitASTAlterConnectionStatement(const ASTAlterConnectionStatement* node, void* data) = 0;

  virtual void visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, void* data) = 0;

  virtual void visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, void* data) = 0;

  virtual void visitASTAlterExternalSchemaStatement(const ASTAlterExternalSchemaStatement* node, void* data) = 0;

  virtual void visitASTAlterTableStatement(const ASTAlterTableStatement* node, void* data) = 0;

  virtual void visitASTAlterViewStatement(const ASTAlterViewStatement* node, void* data) = 0;

  virtual void visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, void* data) = 0;

  virtual void visitASTAlterApproxViewStatement(const ASTAlterApproxViewStatement* node, void* data) = 0;

  virtual void visitASTAlterModelStatement(const ASTAlterModelStatement* node, void* data) = 0;

  virtual void visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, void* data) = 0;

  virtual void visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, void* data) = 0;

  virtual void visitASTAlterEntityStatement(const ASTAlterEntityStatement* node, void* data) = 0;

  virtual void visitASTRebuildAction(const ASTRebuildAction* node, void* data) = 0;

  virtual void visitASTAlterIndexStatement(const ASTAlterIndexStatement* node, void* data) = 0;

  virtual void visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, void* data) = 0;

  virtual void visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, void* data) = 0;

  virtual void visitASTStructColumnSchema(const ASTStructColumnSchema* node, void* data) = 0;

  virtual void visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, void* data) = 0;

  virtual void visitASTExecuteIntoClause(const ASTExecuteIntoClause* node, void* data) = 0;

  virtual void visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, void* data) = 0;

  virtual void visitASTExecuteUsingClause(const ASTExecuteUsingClause* node, void* data) = 0;

  virtual void visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, void* data) = 0;

  virtual void visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, void* data) = 0;

  virtual void visitASTAuxLoadDataPartitionsClause(const ASTAuxLoadDataPartitionsClause* node, void* data) = 0;

  virtual void visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, void* data) = 0;

  virtual void visitASTLabel(const ASTLabel* node, void* data) = 0;

  virtual void visitASTWithExpression(const ASTWithExpression* node, void* data) = 0;

  virtual void visitASTTtlClause(const ASTTtlClause* node, void* data) = 0;

  virtual void visitASTLocation(const ASTLocation* node, void* data) = 0;

  virtual void visitASTInputOutputClause(const ASTInputOutputClause* node, void* data) = 0;

  virtual void visitASTSpannerTableOptions(const ASTSpannerTableOptions* node, void* data) = 0;

  virtual void visitASTSpannerInterleaveClause(const ASTSpannerInterleaveClause* node, void* data) = 0;

  virtual void visitASTSpannerAlterColumnAction(const ASTSpannerAlterColumnAction* node, void* data) = 0;

  virtual void visitASTSpannerSetOnDeleteAction(const ASTSpannerSetOnDeleteAction* node, void* data) = 0;

  virtual void visitASTRangeLiteral(const ASTRangeLiteral* node, void* data) = 0;

  virtual void visitASTRangeType(const ASTRangeType* node, void* data) = 0;

  virtual void visitASTCreatePropertyGraphStatement(const ASTCreatePropertyGraphStatement* node, void* data) = 0;

  virtual void visitASTGraphElementTableList(const ASTGraphElementTableList* node, void* data) = 0;

  virtual void visitASTGraphElementTable(const ASTGraphElementTable* node, void* data) = 0;

  virtual void visitASTGraphNodeTableReference(const ASTGraphNodeTableReference* node, void* data) = 0;

  virtual void visitASTGraphElementLabelAndPropertiesList(const ASTGraphElementLabelAndPropertiesList* node, void* data) = 0;

  virtual void visitASTGraphElementLabelAndProperties(const ASTGraphElementLabelAndProperties* node, void* data) = 0;

  virtual void visitASTGraphDerivedProperty(const ASTGraphDerivedProperty* node, void* data) = 0;

  virtual void visitASTGraphDerivedPropertyList(const ASTGraphDerivedPropertyList* node, void* data) = 0;

  virtual void visitASTGraphProperties(const ASTGraphProperties* node, void* data) = 0;

  virtual void visitASTGraphDynamicLabel(const ASTGraphDynamicLabel* node, void* data) = 0;

  virtual void visitASTGraphDynamicProperties(const ASTGraphDynamicProperties* node, void* data) = 0;

  virtual void visitASTGraphPattern(const ASTGraphPattern* node, void* data) = 0;

  virtual void visitASTGqlQuery(const ASTGqlQuery* node, void* data) = 0;

  virtual void visitASTGqlGraphPatternQuery(const ASTGqlGraphPatternQuery* node, void* data) = 0;

  virtual void visitASTGqlLinearOpsQuery(const ASTGqlLinearOpsQuery* node, void* data) = 0;

  virtual void visitASTGraphTableQuery(const ASTGraphTableQuery* node, void* data) = 0;

  virtual void visitASTGraphElementLabel(const ASTGraphElementLabel* node, void* data) = 0;

  virtual void visitASTGraphWildcardLabel(const ASTGraphWildcardLabel* node, void* data) = 0;

  virtual void visitASTGraphLabelOperation(const ASTGraphLabelOperation* node, void* data) = 0;

  virtual void visitASTGraphLabelFilter(const ASTGraphLabelFilter* node, void* data) = 0;

  virtual void visitASTGraphIsLabeledPredicate(const ASTGraphIsLabeledPredicate* node, void* data) = 0;

  virtual void visitASTGraphElementPatternFiller(const ASTGraphElementPatternFiller* node, void* data) = 0;

  virtual void visitASTGraphPropertySpecification(const ASTGraphPropertySpecification* node, void* data) = 0;

  virtual void visitASTGraphPropertyNameAndValue(const ASTGraphPropertyNameAndValue* node, void* data) = 0;

  virtual void visitASTGraphNodePattern(const ASTGraphNodePattern* node, void* data) = 0;

  virtual void visitASTGraphLhsHint(const ASTGraphLhsHint* node, void* data) = 0;

  virtual void visitASTGraphRhsHint(const ASTGraphRhsHint* node, void* data) = 0;

  virtual void visitASTGraphPathSearchPrefix(const ASTGraphPathSearchPrefix* node, void* data) = 0;

  virtual void visitASTGraphPathSearchPrefixCount(const ASTGraphPathSearchPrefixCount* node, void* data) = 0;

  virtual void visitASTGraphEdgePattern(const ASTGraphEdgePattern* node, void* data) = 0;

  virtual void visitASTGraphPathMode(const ASTGraphPathMode* node, void* data) = 0;

  virtual void visitASTGraphPathPattern(const ASTGraphPathPattern* node, void* data) = 0;

  virtual void visitASTGqlMatch(const ASTGqlMatch* node, void* data) = 0;

  virtual void visitASTGqlReturn(const ASTGqlReturn* node, void* data) = 0;

  virtual void visitASTGqlWith(const ASTGqlWith* node, void* data) = 0;

  virtual void visitASTGqlFor(const ASTGqlFor* node, void* data) = 0;

  virtual void visitASTGqlNamedCall(const ASTGqlNamedCall* node, void* data) = 0;

  virtual void visitASTYieldItemList(const ASTYieldItemList* node, void* data) = 0;

  virtual void visitASTGqlInlineSubqueryCall(const ASTGqlInlineSubqueryCall* node, void* data) = 0;

  virtual void visitASTGqlLet(const ASTGqlLet* node, void* data) = 0;

  virtual void visitASTGqlLetVariableDefinitionList(const ASTGqlLetVariableDefinitionList* node, void* data) = 0;

  virtual void visitASTGqlLetVariableDefinition(const ASTGqlLetVariableDefinition* node, void* data) = 0;

  virtual void visitASTGqlFilter(const ASTGqlFilter* node, void* data) = 0;

  virtual void visitASTGqlOperatorList(const ASTGqlOperatorList* node, void* data) = 0;

  virtual void visitASTGqlSetOperation(const ASTGqlSetOperation* node, void* data) = 0;

  virtual void visitASTGqlPageLimit(const ASTGqlPageLimit* node, void* data) = 0;

  virtual void visitASTGqlPageOffset(const ASTGqlPageOffset* node, void* data) = 0;

  virtual void visitASTGqlPage(const ASTGqlPage* node, void* data) = 0;

  virtual void visitASTGqlOrderByAndPage(const ASTGqlOrderByAndPage* node, void* data) = 0;

  virtual void visitASTGqlSample(const ASTGqlSample* node, void* data) = 0;

  virtual void visitASTWithModifier(const ASTWithModifier* node, void* data) = 0;

  virtual void visitASTColumnWithOptions(const ASTColumnWithOptions* node, void* data) = 0;

  virtual void visitASTColumnWithOptionsList(const ASTColumnWithOptionsList* node, void* data) = 0;

  virtual void visitASTMacroBody(const ASTMacroBody* node, void* data) = 0;

  virtual void visitASTDefineMacroStatement(const ASTDefineMacroStatement* node, void* data) = 0;

  virtual void visitASTUndropStatement(const ASTUndropStatement* node, void* data) = 0;

  virtual void visitASTIdentityColumnInfo(const ASTIdentityColumnInfo* node, void* data) = 0;

  virtual void visitASTIdentityColumnStartWith(const ASTIdentityColumnStartWith* node, void* data) = 0;

  virtual void visitASTIdentityColumnIncrementBy(const ASTIdentityColumnIncrementBy* node, void* data) = 0;

  virtual void visitASTIdentityColumnMaxValue(const ASTIdentityColumnMaxValue* node, void* data) = 0;

  virtual void visitASTIdentityColumnMinValue(const ASTIdentityColumnMinValue* node, void* data) = 0;

  virtual void visitASTAliasedQueryModifiers(const ASTAliasedQueryModifiers* node, void* data) = 0;

  virtual void visitASTIntOrUnbounded(const ASTIntOrUnbounded* node, void* data) = 0;

  virtual void visitASTRecursionDepthModifier(const ASTRecursionDepthModifier* node, void* data) = 0;

  virtual void visitASTMapType(const ASTMapType* node, void* data) = 0;

  virtual void visitASTLockMode(const ASTLockMode* node, void* data) = 0;

  virtual void visitASTPipeRecursiveUnion(const ASTPipeRecursiveUnion* node, void* data) = 0;

  virtual void visitASTRunStatement(const ASTRunStatement* node, void* data) = 0;

  virtual void visitASTCreateSequenceStatement(const ASTCreateSequenceStatement* node, void* data) = 0;

  virtual void visitASTAlterSequenceStatement(const ASTAlterSequenceStatement* node, void* data) = 0;

};

class DefaultParseTreeVisitor : public ParseTreeVisitor {
 public:
  virtual void defaultVisit(const ASTNode* node, void* data) = 0;
  void visit(const ASTNode* node, void* data) override {
    defaultVisit(node, data);
  }
  void visitASTQueryStatement(const ASTQueryStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSubpipelineStatement(const ASTSubpipelineStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAliasedQueryExpression(const ASTAliasedQueryExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQuery(const ASTQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFromQuery(const ASTFromQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSubpipeline(const ASTSubpipeline* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeExtend(const ASTPipeExtend* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeRenameItem(const ASTPipeRenameItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeRename(const ASTPipeRename* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeAggregate(const ASTPipeAggregate* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeSetOperation(const ASTPipeSetOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeJoin(const ASTPipeJoin* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeCall(const ASTPipeCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeWindow(const ASTPipeWindow* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeWhere(const ASTPipeWhere* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeSelect(const ASTPipeSelect* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeLimitOffset(const ASTPipeLimitOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeOrderBy(const ASTPipeOrderBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeDistinct(const ASTPipeDistinct* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeTablesample(const ASTPipeTablesample* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeMatchRecognize(const ASTPipeMatchRecognize* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeAs(const ASTPipeAs* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeDescribe(const ASTPipeDescribe* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeStaticDescribe(const ASTPipeStaticDescribe* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeAssert(const ASTPipeAssert* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeLog(const ASTPipeLog* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeDrop(const ASTPipeDrop* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeSetItem(const ASTPipeSetItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeSet(const ASTPipeSet* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipePivot(const ASTPipePivot* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeUnpivot(const ASTPipeUnpivot* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeIf(const ASTPipeIf* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeIfCase(const ASTPipeIfCase* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeFork(const ASTPipeFork* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeTee(const ASTPipeTee* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeWith(const ASTPipeWith* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeExportData(const ASTPipeExportData* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeCreateTable(const ASTPipeCreateTable* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeInsert(const ASTPipeInsert* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelect(const ASTSelect* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectList(const ASTSelectList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectColumn(const ASTSelectColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntLiteral(const ASTIntLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentifier(const ASTIdentifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlias(const ASTAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPathExpression(const ASTPathExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTablePathExpression(const ASTTablePathExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeJoinLhsPlaceholder(const ASTPipeJoinLhsPlaceholder* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFromClause(const ASTFromClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhereClause(const ASTWhereClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBooleanLiteral(const ASTBooleanLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAndExpr(const ASTAndExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBinaryExpression(const ASTBinaryExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStringLiteral(const ASTStringLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStringLiteralComponent(const ASTStringLiteralComponent* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStar(const ASTStar* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrExpr(const ASTOrExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTConcatExpr(const ASTConcatExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrderingExpression(const ASTOrderingExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOrderBy(const ASTOrderBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupingItemOrder(const ASTGroupingItemOrder* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupingItem(const ASTGroupingItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupBy(const ASTGroupBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupByAll(const ASTGroupByAll* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLimitAll(const ASTLimitAll* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLimit(const ASTLimit* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLimitOffset(const ASTLimitOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFloatLiteral(const ASTFloatLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNullLiteral(const ASTNullLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOnClause(const ASTOnClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAliasedQuery(const ASTAliasedQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTJoin(const ASTJoin* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAliasedGroupRows(const ASTAliasedGroupRows* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithClauseEntry(const ASTWithClauseEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithClause(const ASTWithClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHaving(const ASTHaving* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSimpleType(const ASTSimpleType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayType(const ASTArrayType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructField(const ASTStructField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructType(const ASTStructType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionTypeArgList(const ASTFunctionTypeArgList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionType(const ASTFunctionType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCastExpression(const ASTCastExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSelectAs(const ASTSelectAs* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRollup(const ASTRollup* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCube(const ASTCube* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupingSet(const ASTGroupingSet* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGroupingSetList(const ASTGroupingSetList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExpressionWithAlias(const ASTExpressionWithAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionCall(const ASTFunctionCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTChainedBaseExpr(const ASTChainedBaseExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayConstructor(const ASTArrayConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorArg(const ASTStructConstructorArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInExpression(const ASTInExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInList(const ASTInList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBetweenExpression(const ASTBetweenExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNumericLiteral(const ASTNumericLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBigNumericLiteral(const ASTBigNumericLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBytesLiteral(const ASTBytesLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBytesLiteralComponent(const ASTBytesLiteralComponent* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMaxLiteral(const ASTMaxLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTJSONLiteral(const ASTJSONLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseValueExpression(const ASTCaseValueExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayElement(const ASTArrayElement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCollate(const ASTCollate* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotGeneralizedField(const ASTDotGeneralizedField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotIdentifier(const ASTDotIdentifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotStar(const ASTDotStar* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExpressionSubquery(const ASTExpressionSubquery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExtractExpression(const ASTExtractExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHavingModifier(const ASTHavingModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntervalExpr(const ASTIntervalExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSequenceArg(const ASTSequenceArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNamedArgument(const ASTNamedArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInputTableArgument(const ASTInputTableArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNullOrder(const ASTNullOrder* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParenthesizedJoin(const ASTParenthesizedJoin* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPartitionBy(const ASTPartitionBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperation(const ASTSetOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationMetadataList(const ASTSetOperationMetadataList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationAllOrDistinct(const ASTSetOperationAllOrDistinct* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationType(const ASTSetOperationType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationColumnMatchMode(const ASTSetOperationColumnMatchMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationColumnPropagationMode(const ASTSetOperationColumnPropagationMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOperationMetadata(const ASTSetOperationMetadata* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarExceptList(const ASTStarExceptList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarModifiers(const ASTStarModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarReplaceItem(const ASTStarReplaceItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStarWithModifiers(const ASTStarWithModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableSubquery(const ASTTableSubquery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnaryExpression(const ASTUnaryExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExpressionWithOptAlias(const ASTExpressionWithOptAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnnestExpression(const ASTUnnestExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowClause(const ASTWindowClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowDefinition(const ASTWindowDefinition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowFrame(const ASTWindowFrame* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowFrameExpr(const ASTWindowFrameExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLikeExpression(const ASTLikeExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQuantifiedComparisonExpression(const ASTQuantifiedComparisonExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWindowSpecification(const ASTWindowSpecification* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithOffset(const ASTWithOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnySomeAllOp(const ASTAnySomeAllOp* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStatementList(const ASTStatementList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHintedStatement(const ASTHintedStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStatementWithPipeOperators(const ASTStatementWithPipeOperators* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExplainStatement(const ASTExplainStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescribeStatement(const ASTDescribeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTShowStatement(const ASTShowStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransactionModeList(const ASTTransactionModeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBeginStatement(const ASTBeginStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetTransactionStatement(const ASTSetTransactionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCommitStatement(const ASTCommitStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRollbackStatement(const ASTRollbackStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStartBatchStatement(const ASTStartBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRunBatchStatement(const ASTRunBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAbortBatchStatement(const ASTAbortBatchStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropEntityStatement(const ASTDropEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropFunctionStatement(const ASTDropFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropVectorIndexStatement(const ASTDropVectorIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameStatement(const ASTRenameStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTImportStatement(const ASTImportStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTModuleStatement(const ASTModuleStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithConnectionClause(const ASTWithConnectionClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntoAlias(const ASTIntoAlias* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotExpression(const ASTPivotExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotValue(const ASTPivotValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotExpressionList(const ASTPivotExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotValueList(const ASTPivotValueList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPivotClause(const ASTPivotClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItem(const ASTUnpivotInItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItemList(const ASTUnpivotInItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotClause(const ASTUnpivotClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUsingClause(const ASTUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForSystemTime(const ASTForSystemTime* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMatchRecognizeClause(const ASTMatchRecognizeClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAfterMatchSkipClause(const ASTAfterMatchSkipClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRowPatternVariable(const ASTRowPatternVariable* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRowPatternOperation(const ASTRowPatternOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTEmptyRowPattern(const ASTEmptyRowPattern* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRowPatternAnchor(const ASTRowPatternAnchor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBoundedQuantifier(const ASTBoundedQuantifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQuantifierBound(const ASTQuantifierBound* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFixedQuantifier(const ASTFixedQuantifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSymbolQuantifier(const ASTSymbolQuantifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRowPatternQuantification(const ASTRowPatternQuantification* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTQualify(const ASTQualify* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithReportModifier(const ASTWithReportModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFormatClause(const ASTFormatClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPathExpressionList(const ASTPathExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParameterExpr(const ASTParameterExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSystemVariableExpr(const ASTSystemVariableExpr* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLambda(const ASTLambda* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTClusterBy(const ASTClusterBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNewConstructorArg(const ASTNewConstructorArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNewConstructor(const ASTNewConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBracedConstructorLhs(const ASTBracedConstructorLhs* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBracedConstructorFieldValue(const ASTBracedConstructorFieldValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBracedConstructorField(const ASTBracedConstructorField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBracedConstructor(const ASTBracedConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBracedNewConstructor(const ASTBracedNewConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExtendedPathExpression(const ASTExtendedPathExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateConstructor(const ASTUpdateConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructBracedConstructor(const ASTStructBracedConstructor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOptionsList(const ASTOptionsList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOptionsEntry(const ASTOptionsEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionParameter(const ASTFunctionParameter* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionParameters(const ASTFunctionParameters* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFunctionDeclaration(const ASTFunctionDeclaration* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSqlFunctionBody(const ASTSqlFunctionBody* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFArgument(const ASTTVFArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVF(const ASTTVF* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableClause(const ASTTableClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTModelClause(const ASTModelClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTConnectionClause(const ASTConnectionClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataSource(const ASTCloneDataSource* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCopyDataSource(const ASTCopyDataSource* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataSourceList(const ASTCloneDataSourceList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCloneDataStatement(const ASTCloneDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateConnectionStatement(const ASTCreateConnectionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateConstantStatement(const ASTCreateConstantStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateExternalSchemaStatement(const ASTCreateExternalSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAliasedQueryList(const ASTAliasedQueryList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTransformClause(const ASTTransformClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateModelStatement(const ASTCreateModelStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexAllColumns(const ASTIndexAllColumns* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexItemList(const ASTIndexItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateIndexStatement(const ASTCreateIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExportDataStatement(const ASTExportDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExportModelStatement(const ASTExportModelStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExportMetadataStatement(const ASTExportMetadataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCallStatement(const ASTCallStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDefineTableStatement(const ASTDefineTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateLocalityGroupStatement(const ASTCreateLocalityGroupStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSnapshotStatement(const ASTCreateSnapshotStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTypeParameterList(const ASTTypeParameterList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFSchema(const ASTTVFSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTemplatedParameterType(const ASTTemplatedParameterType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDefaultLiteral(const ASTDefaultLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAnalyzeStatement(const ASTAnalyzeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssertStatement(const ASTAssertStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssertRowsModified(const ASTAssertRowsModified* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReturningClause(const ASTReturningClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTOnConflictClause(const ASTOnConflictClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDeleteStatement(const ASTDeleteStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnAttributeList(const ASTColumnAttributeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructColumnField(const ASTStructColumnField* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnDefinition(const ASTColumnDefinition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTableElementList(const ASTTableElementList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnList(const ASTColumnList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnPosition(const ASTColumnPosition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertValuesRow(const ASTInsertValuesRow* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertValuesRowList(const ASTInsertValuesRowList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInsertStatement(const ASTInsertStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateSetValue(const ASTUpdateSetValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateItem(const ASTUpdateItem* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateItemList(const ASTUpdateItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUpdateStatement(const ASTUpdateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTruncateStatement(const ASTTruncateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeAction(const ASTMergeAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeWhenClause(const ASTMergeWhenClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMergeStatement(const ASTMergeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrivilege(const ASTPrivilege* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrivileges(const ASTPrivileges* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGranteeList(const ASTGranteeList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGrantStatement(const ASTGrantStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRevokeStatement(const ASTRevokeStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRepeatableClause(const ASTRepeatableClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFilterFieldsArg(const ASTFilterFieldsArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleSize(const ASTSampleSize* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithWeight(const ASTWithWeight* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleSuffix(const ASTSampleSuffix* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSampleClause(const ASTSampleClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetOptionsAction(const ASTSetOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetAsAction(const ASTSetAsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddConstraintAction(const ASTAddConstraintAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropConstraintAction(const ASTDropConstraintAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddColumnIdentifierAction(const ASTAddColumnIdentifierAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddColumnAction(const ASTAddColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropColumnAction(const ASTDropColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameColumnAction(const ASTRenameColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnDropGeneratedAction(const ASTAlterColumnDropGeneratedAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterColumnSetGeneratedAction(const ASTAlterColumnSetGeneratedAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGrantToClause(const ASTGrantToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRestrictToClause(const ASTRestrictToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTFilterUsingClause(const ASTFilterUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRevokeFromClause(const ASTRevokeFromClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRenameToClause(const ASTRenameToClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSetCollateClause(const ASTSetCollateClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterSubEntityAction(const ASTAlterSubEntityAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddSubEntityAction(const ASTAddSubEntityAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropSubEntityAction(const ASTDropSubEntityAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAddTtlAction(const ASTAddTtlAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReplaceTtlAction(const ASTReplaceTtlAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropTtlAction(const ASTDropTtlAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterActionList(const ASTAlterActionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyActions(const ASTForeignKeyActions* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKeyReference(const ASTForeignKeyReference* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTScript(const ASTScript* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTElseifClause(const ASTElseifClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTElseifClauseList(const ASTElseifClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIfStatement(const ASTIfStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhenThenClause(const ASTWhenThenClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhenThenClauseList(const ASTWhenThenClauseList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCaseStatement(const ASTCaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHint(const ASTHint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTHintEntry(const ASTHintEntry* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptor(const ASTDescriptor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTArrayColumnSchema(const ASTArrayColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRangeColumnSchema(const ASTRangeColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMapColumnSchema(const ASTMapColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKeyElement(const ASTPrimaryKeyElement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKeyElementList(const ASTPrimaryKeyElementList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPrimaryKey(const ASTPrimaryKey* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForeignKey(const ASTForeignKey* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCheckConstraint(const ASTCheckConstraint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptorColumn(const ASTDescriptorColumn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDescriptorColumnList(const ASTDescriptorColumnList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateEntityStatement(const ASTCreateEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRaiseStatement(const ASTRaiseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExceptionHandler(const ASTExceptionHandler* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExceptionHandlerList(const ASTExceptionHandlerList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBeginEndBlock(const ASTBeginEndBlock* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentifierList(const ASTIdentifierList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTVariableDeclaration(const ASTVariableDeclaration* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUntilClause(const ASTUntilClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTBreakStatement(const ASTBreakStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTContinueStatement(const ASTContinueStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDropStatement(const ASTDropStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTReturnStatement(const ASTReturnStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSingleAssignment(const ASTSingleAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTParameterAssignment(const ASTParameterAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateTableStatement(const ASTCreateTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateViewStatement(const ASTCreateViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateApproxViewStatement(const ASTCreateApproxViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWhileStatement(const ASTWhileStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRepeatStatement(const ASTRepeatStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTForInStatement(const ASTForInStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterConnectionStatement(const ASTAlterConnectionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterExternalSchemaStatement(const ASTAlterExternalSchemaStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterTableStatement(const ASTAlterTableStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterViewStatement(const ASTAlterViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterApproxViewStatement(const ASTAlterApproxViewStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterModelStatement(const ASTAlterModelStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterEntityStatement(const ASTAlterEntityStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRebuildAction(const ASTRebuildAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterIndexStatement(const ASTAlterIndexStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTStructColumnSchema(const ASTStructColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteIntoClause(const ASTExecuteIntoClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteUsingClause(const ASTExecuteUsingClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAuxLoadDataPartitionsClause(const ASTAuxLoadDataPartitionsClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLabel(const ASTLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithExpression(const ASTWithExpression* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTTtlClause(const ASTTtlClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLocation(const ASTLocation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTInputOutputClause(const ASTInputOutputClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSpannerTableOptions(const ASTSpannerTableOptions* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSpannerInterleaveClause(const ASTSpannerInterleaveClause* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSpannerAlterColumnAction(const ASTSpannerAlterColumnAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTSpannerSetOnDeleteAction(const ASTSpannerSetOnDeleteAction* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRangeLiteral(const ASTRangeLiteral* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRangeType(const ASTRangeType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreatePropertyGraphStatement(const ASTCreatePropertyGraphStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementTableList(const ASTGraphElementTableList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementTable(const ASTGraphElementTable* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphNodeTableReference(const ASTGraphNodeTableReference* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementLabelAndPropertiesList(const ASTGraphElementLabelAndPropertiesList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementLabelAndProperties(const ASTGraphElementLabelAndProperties* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphDerivedProperty(const ASTGraphDerivedProperty* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphDerivedPropertyList(const ASTGraphDerivedPropertyList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphProperties(const ASTGraphProperties* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphDynamicLabel(const ASTGraphDynamicLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphDynamicProperties(const ASTGraphDynamicProperties* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPattern(const ASTGraphPattern* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlQuery(const ASTGqlQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlGraphPatternQuery(const ASTGqlGraphPatternQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlLinearOpsQuery(const ASTGqlLinearOpsQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphTableQuery(const ASTGraphTableQuery* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementLabel(const ASTGraphElementLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphWildcardLabel(const ASTGraphWildcardLabel* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphLabelOperation(const ASTGraphLabelOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphLabelFilter(const ASTGraphLabelFilter* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphIsLabeledPredicate(const ASTGraphIsLabeledPredicate* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphElementPatternFiller(const ASTGraphElementPatternFiller* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPropertySpecification(const ASTGraphPropertySpecification* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPropertyNameAndValue(const ASTGraphPropertyNameAndValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphNodePattern(const ASTGraphNodePattern* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphLhsHint(const ASTGraphLhsHint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphRhsHint(const ASTGraphRhsHint* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPathSearchPrefix(const ASTGraphPathSearchPrefix* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPathSearchPrefixCount(const ASTGraphPathSearchPrefixCount* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphEdgePattern(const ASTGraphEdgePattern* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPathMode(const ASTGraphPathMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGraphPathPattern(const ASTGraphPathPattern* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlMatch(const ASTGqlMatch* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlReturn(const ASTGqlReturn* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlWith(const ASTGqlWith* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlFor(const ASTGqlFor* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlNamedCall(const ASTGqlNamedCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTYieldItemList(const ASTYieldItemList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlInlineSubqueryCall(const ASTGqlInlineSubqueryCall* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlLet(const ASTGqlLet* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlLetVariableDefinitionList(const ASTGqlLetVariableDefinitionList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlLetVariableDefinition(const ASTGqlLetVariableDefinition* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlFilter(const ASTGqlFilter* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlOperatorList(const ASTGqlOperatorList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlSetOperation(const ASTGqlSetOperation* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlPageLimit(const ASTGqlPageLimit* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlPageOffset(const ASTGqlPageOffset* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlPage(const ASTGqlPage* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlOrderByAndPage(const ASTGqlOrderByAndPage* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTGqlSample(const ASTGqlSample* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTWithModifier(const ASTWithModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnWithOptions(const ASTColumnWithOptions* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTColumnWithOptionsList(const ASTColumnWithOptionsList* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMacroBody(const ASTMacroBody* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTDefineMacroStatement(const ASTDefineMacroStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTUndropStatement(const ASTUndropStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentityColumnInfo(const ASTIdentityColumnInfo* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentityColumnStartWith(const ASTIdentityColumnStartWith* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentityColumnIncrementBy(const ASTIdentityColumnIncrementBy* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentityColumnMaxValue(const ASTIdentityColumnMaxValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIdentityColumnMinValue(const ASTIdentityColumnMinValue* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAliasedQueryModifiers(const ASTAliasedQueryModifiers* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTIntOrUnbounded(const ASTIntOrUnbounded* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRecursionDepthModifier(const ASTRecursionDepthModifier* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTMapType(const ASTMapType* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTLockMode(const ASTLockMode* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTPipeRecursiveUnion(const ASTPipeRecursiveUnion* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTRunStatement(const ASTRunStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTCreateSequenceStatement(const ASTCreateSequenceStatement* node, void* data) override {
    defaultVisit(node, data);
  }

  void visitASTAlterSequenceStatement(const ASTAlterSequenceStatement* node, void* data) override {
    defaultVisit(node, data);
  }

      };

      class ParseTreeStatusVisitor {
       public:
        virtual ~ParseTreeStatusVisitor() {}
        virtual absl::Status Visit(const ASTNode* node, std::any& output) = 0;
              virtual absl::Status VisitASTQueryStatement(const ASTQueryStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTSubpipelineStatement(const ASTSubpipelineStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAliasedQueryExpression(const ASTAliasedQueryExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTQuery(const ASTQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTFromQuery(const ASTFromQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTSubpipeline(const ASTSubpipeline* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeExtend(const ASTPipeExtend* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeRenameItem(const ASTPipeRenameItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeRename(const ASTPipeRename* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeAggregate(const ASTPipeAggregate* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeSetOperation(const ASTPipeSetOperation* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeJoin(const ASTPipeJoin* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeCall(const ASTPipeCall* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeWindow(const ASTPipeWindow* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeWhere(const ASTPipeWhere* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeSelect(const ASTPipeSelect* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeLimitOffset(const ASTPipeLimitOffset* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeOrderBy(const ASTPipeOrderBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeDistinct(const ASTPipeDistinct* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeTablesample(const ASTPipeTablesample* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeMatchRecognize(const ASTPipeMatchRecognize* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeAs(const ASTPipeAs* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeDescribe(const ASTPipeDescribe* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeStaticDescribe(const ASTPipeStaticDescribe* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeAssert(const ASTPipeAssert* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeLog(const ASTPipeLog* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeDrop(const ASTPipeDrop* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeSetItem(const ASTPipeSetItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeSet(const ASTPipeSet* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipePivot(const ASTPipePivot* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeUnpivot(const ASTPipeUnpivot* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeIf(const ASTPipeIf* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeIfCase(const ASTPipeIfCase* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeFork(const ASTPipeFork* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeTee(const ASTPipeTee* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeWith(const ASTPipeWith* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeExportData(const ASTPipeExportData* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeCreateTable(const ASTPipeCreateTable* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeInsert(const ASTPipeInsert* node, std::any& output) = 0;
                virtual absl::Status VisitASTSelect(const ASTSelect* node, std::any& output) = 0;
                virtual absl::Status VisitASTSelectList(const ASTSelectList* node, std::any& output) = 0;
                virtual absl::Status VisitASTSelectColumn(const ASTSelectColumn* node, std::any& output) = 0;
                virtual absl::Status VisitASTIntLiteral(const ASTIntLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentifier(const ASTIdentifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlias(const ASTAlias* node, std::any& output) = 0;
                virtual absl::Status VisitASTPathExpression(const ASTPathExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTTablePathExpression(const ASTTablePathExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeJoinLhsPlaceholder(const ASTPipeJoinLhsPlaceholder* node, std::any& output) = 0;
                virtual absl::Status VisitASTFromClause(const ASTFromClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTWhereClause(const ASTWhereClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTBooleanLiteral(const ASTBooleanLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTAndExpr(const ASTAndExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTBinaryExpression(const ASTBinaryExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTStringLiteral(const ASTStringLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTStringLiteralComponent(const ASTStringLiteralComponent* node, std::any& output) = 0;
                virtual absl::Status VisitASTStar(const ASTStar* node, std::any& output) = 0;
                virtual absl::Status VisitASTOrExpr(const ASTOrExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTConcatExpr(const ASTConcatExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTOrderingExpression(const ASTOrderingExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTOrderBy(const ASTOrderBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupingItemOrder(const ASTGroupingItemOrder* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupingItem(const ASTGroupingItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupBy(const ASTGroupBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupByAll(const ASTGroupByAll* node, std::any& output) = 0;
                virtual absl::Status VisitASTLimitAll(const ASTLimitAll* node, std::any& output) = 0;
                virtual absl::Status VisitASTLimit(const ASTLimit* node, std::any& output) = 0;
                virtual absl::Status VisitASTLimitOffset(const ASTLimitOffset* node, std::any& output) = 0;
                virtual absl::Status VisitASTFloatLiteral(const ASTFloatLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTNullLiteral(const ASTNullLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTOnClause(const ASTOnClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTAliasedQuery(const ASTAliasedQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTJoin(const ASTJoin* node, std::any& output) = 0;
                virtual absl::Status VisitASTAliasedGroupRows(const ASTAliasedGroupRows* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithClauseEntry(const ASTWithClauseEntry* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithClause(const ASTWithClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTHaving(const ASTHaving* node, std::any& output) = 0;
                virtual absl::Status VisitASTSimpleType(const ASTSimpleType* node, std::any& output) = 0;
                virtual absl::Status VisitASTArrayType(const ASTArrayType* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructField(const ASTStructField* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructType(const ASTStructType* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionTypeArgList(const ASTFunctionTypeArgList* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionType(const ASTFunctionType* node, std::any& output) = 0;
                virtual absl::Status VisitASTCastExpression(const ASTCastExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTSelectAs(const ASTSelectAs* node, std::any& output) = 0;
                virtual absl::Status VisitASTRollup(const ASTRollup* node, std::any& output) = 0;
                virtual absl::Status VisitASTCube(const ASTCube* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupingSet(const ASTGroupingSet* node, std::any& output) = 0;
                virtual absl::Status VisitASTGroupingSetList(const ASTGroupingSetList* node, std::any& output) = 0;
                virtual absl::Status VisitASTExpressionWithAlias(const ASTExpressionWithAlias* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionCall(const ASTFunctionCall* node, std::any& output) = 0;
                virtual absl::Status VisitASTChainedBaseExpr(const ASTChainedBaseExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTArrayConstructor(const ASTArrayConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructConstructorArg(const ASTStructConstructorArg* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, std::any& output) = 0;
                virtual absl::Status VisitASTInExpression(const ASTInExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTInList(const ASTInList* node, std::any& output) = 0;
                virtual absl::Status VisitASTBetweenExpression(const ASTBetweenExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTNumericLiteral(const ASTNumericLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTBigNumericLiteral(const ASTBigNumericLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTBytesLiteral(const ASTBytesLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTBytesLiteralComponent(const ASTBytesLiteralComponent* node, std::any& output) = 0;
                virtual absl::Status VisitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTMaxLiteral(const ASTMaxLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTJSONLiteral(const ASTJSONLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTCaseValueExpression(const ASTCaseValueExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTArrayElement(const ASTArrayElement* node, std::any& output) = 0;
                virtual absl::Status VisitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTCollate(const ASTCollate* node, std::any& output) = 0;
                virtual absl::Status VisitASTDotGeneralizedField(const ASTDotGeneralizedField* node, std::any& output) = 0;
                virtual absl::Status VisitASTDotIdentifier(const ASTDotIdentifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTDotStar(const ASTDotStar* node, std::any& output) = 0;
                virtual absl::Status VisitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, std::any& output) = 0;
                virtual absl::Status VisitASTExpressionSubquery(const ASTExpressionSubquery* node, std::any& output) = 0;
                virtual absl::Status VisitASTExtractExpression(const ASTExtractExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTHavingModifier(const ASTHavingModifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTIntervalExpr(const ASTIntervalExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTSequenceArg(const ASTSequenceArg* node, std::any& output) = 0;
                virtual absl::Status VisitASTNamedArgument(const ASTNamedArgument* node, std::any& output) = 0;
                virtual absl::Status VisitASTInputTableArgument(const ASTInputTableArgument* node, std::any& output) = 0;
                virtual absl::Status VisitASTNullOrder(const ASTNullOrder* node, std::any& output) = 0;
                virtual absl::Status VisitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, std::any& output) = 0;
                virtual absl::Status VisitASTParenthesizedJoin(const ASTParenthesizedJoin* node, std::any& output) = 0;
                virtual absl::Status VisitASTPartitionBy(const ASTPartitionBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperation(const ASTSetOperation* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationMetadataList(const ASTSetOperationMetadataList* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationAllOrDistinct(const ASTSetOperationAllOrDistinct* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationType(const ASTSetOperationType* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationColumnMatchMode(const ASTSetOperationColumnMatchMode* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationColumnPropagationMode(const ASTSetOperationColumnPropagationMode* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOperationMetadata(const ASTSetOperationMetadata* node, std::any& output) = 0;
                virtual absl::Status VisitASTStarExceptList(const ASTStarExceptList* node, std::any& output) = 0;
                virtual absl::Status VisitASTStarModifiers(const ASTStarModifiers* node, std::any& output) = 0;
                virtual absl::Status VisitASTStarReplaceItem(const ASTStarReplaceItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTStarWithModifiers(const ASTStarWithModifiers* node, std::any& output) = 0;
                virtual absl::Status VisitASTTableSubquery(const ASTTableSubquery* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnaryExpression(const ASTUnaryExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTExpressionWithOptAlias(const ASTExpressionWithOptAlias* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnnestExpression(const ASTUnnestExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTWindowClause(const ASTWindowClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTWindowDefinition(const ASTWindowDefinition* node, std::any& output) = 0;
                virtual absl::Status VisitASTWindowFrame(const ASTWindowFrame* node, std::any& output) = 0;
                virtual absl::Status VisitASTWindowFrameExpr(const ASTWindowFrameExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTLikeExpression(const ASTLikeExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTQuantifiedComparisonExpression(const ASTQuantifiedComparisonExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTWindowSpecification(const ASTWindowSpecification* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithOffset(const ASTWithOffset* node, std::any& output) = 0;
                virtual absl::Status VisitASTAnySomeAllOp(const ASTAnySomeAllOp* node, std::any& output) = 0;
                virtual absl::Status VisitASTStatementList(const ASTStatementList* node, std::any& output) = 0;
                virtual absl::Status VisitASTHintedStatement(const ASTHintedStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTStatementWithPipeOperators(const ASTStatementWithPipeOperators* node, std::any& output) = 0;
                virtual absl::Status VisitASTExplainStatement(const ASTExplainStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDescribeStatement(const ASTDescribeStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTShowStatement(const ASTShowStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, std::any& output) = 0;
                virtual absl::Status VisitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, std::any& output) = 0;
                virtual absl::Status VisitASTTransactionModeList(const ASTTransactionModeList* node, std::any& output) = 0;
                virtual absl::Status VisitASTBeginStatement(const ASTBeginStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetTransactionStatement(const ASTSetTransactionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCommitStatement(const ASTCommitStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRollbackStatement(const ASTRollbackStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTStartBatchStatement(const ASTStartBatchStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRunBatchStatement(const ASTRunBatchStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAbortBatchStatement(const ASTAbortBatchStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropEntityStatement(const ASTDropEntityStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropFunctionStatement(const ASTDropFunctionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropVectorIndexStatement(const ASTDropVectorIndexStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRenameStatement(const ASTRenameStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTImportStatement(const ASTImportStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTModuleStatement(const ASTModuleStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithConnectionClause(const ASTWithConnectionClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTIntoAlias(const ASTIntoAlias* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, std::any& output) = 0;
                virtual absl::Status VisitASTPivotExpression(const ASTPivotExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTPivotValue(const ASTPivotValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTPivotExpressionList(const ASTPivotExpressionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTPivotValueList(const ASTPivotValueList* node, std::any& output) = 0;
                virtual absl::Status VisitASTPivotClause(const ASTPivotClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnpivotInItem(const ASTUnpivotInItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnpivotInItemList(const ASTUnpivotInItemList* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnpivotClause(const ASTUnpivotClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTUsingClause(const ASTUsingClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTForSystemTime(const ASTForSystemTime* node, std::any& output) = 0;
                virtual absl::Status VisitASTMatchRecognizeClause(const ASTMatchRecognizeClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTAfterMatchSkipClause(const ASTAfterMatchSkipClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTRowPatternVariable(const ASTRowPatternVariable* node, std::any& output) = 0;
                virtual absl::Status VisitASTRowPatternOperation(const ASTRowPatternOperation* node, std::any& output) = 0;
                virtual absl::Status VisitASTEmptyRowPattern(const ASTEmptyRowPattern* node, std::any& output) = 0;
                virtual absl::Status VisitASTRowPatternAnchor(const ASTRowPatternAnchor* node, std::any& output) = 0;
                virtual absl::Status VisitASTBoundedQuantifier(const ASTBoundedQuantifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTQuantifierBound(const ASTQuantifierBound* node, std::any& output) = 0;
                virtual absl::Status VisitASTFixedQuantifier(const ASTFixedQuantifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTSymbolQuantifier(const ASTSymbolQuantifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTRowPatternQuantification(const ASTRowPatternQuantification* node, std::any& output) = 0;
                virtual absl::Status VisitASTQualify(const ASTQualify* node, std::any& output) = 0;
                virtual absl::Status VisitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithReportModifier(const ASTWithReportModifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTFormatClause(const ASTFormatClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTPathExpressionList(const ASTPathExpressionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTParameterExpr(const ASTParameterExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTSystemVariableExpr(const ASTSystemVariableExpr* node, std::any& output) = 0;
                virtual absl::Status VisitASTLambda(const ASTLambda* node, std::any& output) = 0;
                virtual absl::Status VisitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, std::any& output) = 0;
                virtual absl::Status VisitASTClusterBy(const ASTClusterBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTNewConstructorArg(const ASTNewConstructorArg* node, std::any& output) = 0;
                virtual absl::Status VisitASTNewConstructor(const ASTNewConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTBracedConstructorLhs(const ASTBracedConstructorLhs* node, std::any& output) = 0;
                virtual absl::Status VisitASTBracedConstructorFieldValue(const ASTBracedConstructorFieldValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTBracedConstructorField(const ASTBracedConstructorField* node, std::any& output) = 0;
                virtual absl::Status VisitASTBracedConstructor(const ASTBracedConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTBracedNewConstructor(const ASTBracedNewConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTExtendedPathExpression(const ASTExtendedPathExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTUpdateConstructor(const ASTUpdateConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructBracedConstructor(const ASTStructBracedConstructor* node, std::any& output) = 0;
                virtual absl::Status VisitASTOptionsList(const ASTOptionsList* node, std::any& output) = 0;
                virtual absl::Status VisitASTOptionsEntry(const ASTOptionsEntry* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionParameter(const ASTFunctionParameter* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionParameters(const ASTFunctionParameters* node, std::any& output) = 0;
                virtual absl::Status VisitASTFunctionDeclaration(const ASTFunctionDeclaration* node, std::any& output) = 0;
                virtual absl::Status VisitASTSqlFunctionBody(const ASTSqlFunctionBody* node, std::any& output) = 0;
                virtual absl::Status VisitASTTVFArgument(const ASTTVFArgument* node, std::any& output) = 0;
                virtual absl::Status VisitASTTVF(const ASTTVF* node, std::any& output) = 0;
                virtual absl::Status VisitASTTableClause(const ASTTableClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTModelClause(const ASTModelClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTConnectionClause(const ASTConnectionClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTCloneDataSource(const ASTCloneDataSource* node, std::any& output) = 0;
                virtual absl::Status VisitASTCopyDataSource(const ASTCopyDataSource* node, std::any& output) = 0;
                virtual absl::Status VisitASTCloneDataSourceList(const ASTCloneDataSourceList* node, std::any& output) = 0;
                virtual absl::Status VisitASTCloneDataStatement(const ASTCloneDataStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateConnectionStatement(const ASTCreateConnectionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateConstantStatement(const ASTCreateConstantStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateExternalSchemaStatement(const ASTCreateExternalSchemaStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAliasedQueryList(const ASTAliasedQueryList* node, std::any& output) = 0;
                virtual absl::Status VisitASTTransformClause(const ASTTransformClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateModelStatement(const ASTCreateModelStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTIndexAllColumns(const ASTIndexAllColumns* node, std::any& output) = 0;
                virtual absl::Status VisitASTIndexItemList(const ASTIndexItemList* node, std::any& output) = 0;
                virtual absl::Status VisitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateIndexStatement(const ASTCreateIndexStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTExportDataStatement(const ASTExportDataStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTExportModelStatement(const ASTExportModelStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTExportMetadataStatement(const ASTExportMetadataStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCallStatement(const ASTCallStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDefineTableStatement(const ASTDefineTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateLocalityGroupStatement(const ASTCreateLocalityGroupStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateSnapshotStatement(const ASTCreateSnapshotStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTTypeParameterList(const ASTTypeParameterList* node, std::any& output) = 0;
                virtual absl::Status VisitASTTVFSchema(const ASTTVFSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, std::any& output) = 0;
                virtual absl::Status VisitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, std::any& output) = 0;
                virtual absl::Status VisitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, std::any& output) = 0;
                virtual absl::Status VisitASTTemplatedParameterType(const ASTTemplatedParameterType* node, std::any& output) = 0;
                virtual absl::Status VisitASTDefaultLiteral(const ASTDefaultLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTAnalyzeStatement(const ASTAnalyzeStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAssertStatement(const ASTAssertStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAssertRowsModified(const ASTAssertRowsModified* node, std::any& output) = 0;
                virtual absl::Status VisitASTReturningClause(const ASTReturningClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTOnConflictClause(const ASTOnConflictClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTDeleteStatement(const ASTDeleteStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, std::any& output) = 0;
                virtual absl::Status VisitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, std::any& output) = 0;
                virtual absl::Status VisitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnAttributeList(const ASTColumnAttributeList* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructColumnField(const ASTStructColumnField* node, std::any& output) = 0;
                virtual absl::Status VisitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnDefinition(const ASTColumnDefinition* node, std::any& output) = 0;
                virtual absl::Status VisitASTTableElementList(const ASTTableElementList* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnList(const ASTColumnList* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnPosition(const ASTColumnPosition* node, std::any& output) = 0;
                virtual absl::Status VisitASTInsertValuesRow(const ASTInsertValuesRow* node, std::any& output) = 0;
                virtual absl::Status VisitASTInsertValuesRowList(const ASTInsertValuesRowList* node, std::any& output) = 0;
                virtual absl::Status VisitASTInsertStatement(const ASTInsertStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTUpdateSetValue(const ASTUpdateSetValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTUpdateItem(const ASTUpdateItem* node, std::any& output) = 0;
                virtual absl::Status VisitASTUpdateItemList(const ASTUpdateItemList* node, std::any& output) = 0;
                virtual absl::Status VisitASTUpdateStatement(const ASTUpdateStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTTruncateStatement(const ASTTruncateStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTMergeAction(const ASTMergeAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTMergeWhenClause(const ASTMergeWhenClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, std::any& output) = 0;
                virtual absl::Status VisitASTMergeStatement(const ASTMergeStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrivilege(const ASTPrivilege* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrivileges(const ASTPrivileges* node, std::any& output) = 0;
                virtual absl::Status VisitASTGranteeList(const ASTGranteeList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGrantStatement(const ASTGrantStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRevokeStatement(const ASTRevokeStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRepeatableClause(const ASTRepeatableClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTFilterFieldsArg(const ASTFilterFieldsArg* node, std::any& output) = 0;
                virtual absl::Status VisitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, std::any& output) = 0;
                virtual absl::Status VisitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTSampleSize(const ASTSampleSize* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithWeight(const ASTWithWeight* node, std::any& output) = 0;
                virtual absl::Status VisitASTSampleSuffix(const ASTSampleSuffix* node, std::any& output) = 0;
                virtual absl::Status VisitASTSampleClause(const ASTSampleClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetOptionsAction(const ASTSetOptionsAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetAsAction(const ASTSetAsAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddConstraintAction(const ASTAddConstraintAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropConstraintAction(const ASTDropConstraintAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddColumnIdentifierAction(const ASTAddColumnIdentifierAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddColumnAction(const ASTAddColumnAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropColumnAction(const ASTDropColumnAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTRenameColumnAction(const ASTRenameColumnAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnDropGeneratedAction(const ASTAlterColumnDropGeneratedAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterColumnSetGeneratedAction(const ASTAlterColumnSetGeneratedAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTGrantToClause(const ASTGrantToClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTRestrictToClause(const ASTRestrictToClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTFilterUsingClause(const ASTFilterUsingClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTRevokeFromClause(const ASTRevokeFromClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTRenameToClause(const ASTRenameToClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTSetCollateClause(const ASTSetCollateClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterSubEntityAction(const ASTAlterSubEntityAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddSubEntityAction(const ASTAddSubEntityAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropSubEntityAction(const ASTDropSubEntityAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAddTtlAction(const ASTAddTtlAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTReplaceTtlAction(const ASTReplaceTtlAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropTtlAction(const ASTDropTtlAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterActionList(const ASTAlterActionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTForeignKeyActions(const ASTForeignKeyActions* node, std::any& output) = 0;
                virtual absl::Status VisitASTForeignKeyReference(const ASTForeignKeyReference* node, std::any& output) = 0;
                virtual absl::Status VisitASTScript(const ASTScript* node, std::any& output) = 0;
                virtual absl::Status VisitASTElseifClause(const ASTElseifClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTElseifClauseList(const ASTElseifClauseList* node, std::any& output) = 0;
                virtual absl::Status VisitASTIfStatement(const ASTIfStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTWhenThenClause(const ASTWhenThenClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTWhenThenClauseList(const ASTWhenThenClauseList* node, std::any& output) = 0;
                virtual absl::Status VisitASTCaseStatement(const ASTCaseStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTHint(const ASTHint* node, std::any& output) = 0;
                virtual absl::Status VisitASTHintEntry(const ASTHintEntry* node, std::any& output) = 0;
                virtual absl::Status VisitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, std::any& output) = 0;
                virtual absl::Status VisitASTDescriptor(const ASTDescriptor* node, std::any& output) = 0;
                virtual absl::Status VisitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTArrayColumnSchema(const ASTArrayColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTRangeColumnSchema(const ASTRangeColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTMapColumnSchema(const ASTMapColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrimaryKeyElement(const ASTPrimaryKeyElement* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrimaryKeyElementList(const ASTPrimaryKeyElementList* node, std::any& output) = 0;
                virtual absl::Status VisitASTPrimaryKey(const ASTPrimaryKey* node, std::any& output) = 0;
                virtual absl::Status VisitASTForeignKey(const ASTForeignKey* node, std::any& output) = 0;
                virtual absl::Status VisitASTCheckConstraint(const ASTCheckConstraint* node, std::any& output) = 0;
                virtual absl::Status VisitASTDescriptorColumn(const ASTDescriptorColumn* node, std::any& output) = 0;
                virtual absl::Status VisitASTDescriptorColumnList(const ASTDescriptorColumnList* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateEntityStatement(const ASTCreateEntityStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRaiseStatement(const ASTRaiseStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTExceptionHandler(const ASTExceptionHandler* node, std::any& output) = 0;
                virtual absl::Status VisitASTExceptionHandlerList(const ASTExceptionHandlerList* node, std::any& output) = 0;
                virtual absl::Status VisitASTBeginEndBlock(const ASTBeginEndBlock* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentifierList(const ASTIdentifierList* node, std::any& output) = 0;
                virtual absl::Status VisitASTVariableDeclaration(const ASTVariableDeclaration* node, std::any& output) = 0;
                virtual absl::Status VisitASTUntilClause(const ASTUntilClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTBreakStatement(const ASTBreakStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTContinueStatement(const ASTContinueStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTDropStatement(const ASTDropStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTReturnStatement(const ASTReturnStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTSingleAssignment(const ASTSingleAssignment* node, std::any& output) = 0;
                virtual absl::Status VisitASTParameterAssignment(const ASTParameterAssignment* node, std::any& output) = 0;
                virtual absl::Status VisitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, std::any& output) = 0;
                virtual absl::Status VisitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateTableStatement(const ASTCreateTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateViewStatement(const ASTCreateViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateApproxViewStatement(const ASTCreateApproxViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTWhileStatement(const ASTWhileStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRepeatStatement(const ASTRepeatStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTForInStatement(const ASTForInStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterConnectionStatement(const ASTAlterConnectionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterExternalSchemaStatement(const ASTAlterExternalSchemaStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterTableStatement(const ASTAlterTableStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterViewStatement(const ASTAlterViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterApproxViewStatement(const ASTAlterApproxViewStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterModelStatement(const ASTAlterModelStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterEntityStatement(const ASTAlterEntityStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTRebuildAction(const ASTRebuildAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterIndexStatement(const ASTAlterIndexStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTStructColumnSchema(const ASTStructColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, std::any& output) = 0;
                virtual absl::Status VisitASTExecuteIntoClause(const ASTExecuteIntoClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, std::any& output) = 0;
                virtual absl::Status VisitASTExecuteUsingClause(const ASTExecuteUsingClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, std::any& output) = 0;
                virtual absl::Status VisitASTAuxLoadDataPartitionsClause(const ASTAuxLoadDataPartitionsClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTLabel(const ASTLabel* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithExpression(const ASTWithExpression* node, std::any& output) = 0;
                virtual absl::Status VisitASTTtlClause(const ASTTtlClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTLocation(const ASTLocation* node, std::any& output) = 0;
                virtual absl::Status VisitASTInputOutputClause(const ASTInputOutputClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTSpannerTableOptions(const ASTSpannerTableOptions* node, std::any& output) = 0;
                virtual absl::Status VisitASTSpannerInterleaveClause(const ASTSpannerInterleaveClause* node, std::any& output) = 0;
                virtual absl::Status VisitASTSpannerAlterColumnAction(const ASTSpannerAlterColumnAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTSpannerSetOnDeleteAction(const ASTSpannerSetOnDeleteAction* node, std::any& output) = 0;
                virtual absl::Status VisitASTRangeLiteral(const ASTRangeLiteral* node, std::any& output) = 0;
                virtual absl::Status VisitASTRangeType(const ASTRangeType* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreatePropertyGraphStatement(const ASTCreatePropertyGraphStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementTableList(const ASTGraphElementTableList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementTable(const ASTGraphElementTable* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphNodeTableReference(const ASTGraphNodeTableReference* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementLabelAndPropertiesList(const ASTGraphElementLabelAndPropertiesList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementLabelAndProperties(const ASTGraphElementLabelAndProperties* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphDerivedProperty(const ASTGraphDerivedProperty* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphDerivedPropertyList(const ASTGraphDerivedPropertyList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphProperties(const ASTGraphProperties* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphDynamicLabel(const ASTGraphDynamicLabel* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphDynamicProperties(const ASTGraphDynamicProperties* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPattern(const ASTGraphPattern* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlQuery(const ASTGqlQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlGraphPatternQuery(const ASTGqlGraphPatternQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlLinearOpsQuery(const ASTGqlLinearOpsQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphTableQuery(const ASTGraphTableQuery* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementLabel(const ASTGraphElementLabel* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphWildcardLabel(const ASTGraphWildcardLabel* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphLabelOperation(const ASTGraphLabelOperation* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphLabelFilter(const ASTGraphLabelFilter* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphIsLabeledPredicate(const ASTGraphIsLabeledPredicate* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphElementPatternFiller(const ASTGraphElementPatternFiller* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPropertySpecification(const ASTGraphPropertySpecification* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPropertyNameAndValue(const ASTGraphPropertyNameAndValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphNodePattern(const ASTGraphNodePattern* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphLhsHint(const ASTGraphLhsHint* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphRhsHint(const ASTGraphRhsHint* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPathSearchPrefix(const ASTGraphPathSearchPrefix* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPathSearchPrefixCount(const ASTGraphPathSearchPrefixCount* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphEdgePattern(const ASTGraphEdgePattern* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPathMode(const ASTGraphPathMode* node, std::any& output) = 0;
                virtual absl::Status VisitASTGraphPathPattern(const ASTGraphPathPattern* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlMatch(const ASTGqlMatch* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlReturn(const ASTGqlReturn* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlWith(const ASTGqlWith* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlFor(const ASTGqlFor* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlNamedCall(const ASTGqlNamedCall* node, std::any& output) = 0;
                virtual absl::Status VisitASTYieldItemList(const ASTYieldItemList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlInlineSubqueryCall(const ASTGqlInlineSubqueryCall* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlLet(const ASTGqlLet* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlLetVariableDefinitionList(const ASTGqlLetVariableDefinitionList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlLetVariableDefinition(const ASTGqlLetVariableDefinition* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlFilter(const ASTGqlFilter* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlOperatorList(const ASTGqlOperatorList* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlSetOperation(const ASTGqlSetOperation* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlPageLimit(const ASTGqlPageLimit* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlPageOffset(const ASTGqlPageOffset* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlPage(const ASTGqlPage* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlOrderByAndPage(const ASTGqlOrderByAndPage* node, std::any& output) = 0;
                virtual absl::Status VisitASTGqlSample(const ASTGqlSample* node, std::any& output) = 0;
                virtual absl::Status VisitASTWithModifier(const ASTWithModifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnWithOptions(const ASTColumnWithOptions* node, std::any& output) = 0;
                virtual absl::Status VisitASTColumnWithOptionsList(const ASTColumnWithOptionsList* node, std::any& output) = 0;
                virtual absl::Status VisitASTMacroBody(const ASTMacroBody* node, std::any& output) = 0;
                virtual absl::Status VisitASTDefineMacroStatement(const ASTDefineMacroStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTUndropStatement(const ASTUndropStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentityColumnInfo(const ASTIdentityColumnInfo* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentityColumnStartWith(const ASTIdentityColumnStartWith* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentityColumnIncrementBy(const ASTIdentityColumnIncrementBy* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentityColumnMaxValue(const ASTIdentityColumnMaxValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTIdentityColumnMinValue(const ASTIdentityColumnMinValue* node, std::any& output) = 0;
                virtual absl::Status VisitASTAliasedQueryModifiers(const ASTAliasedQueryModifiers* node, std::any& output) = 0;
                virtual absl::Status VisitASTIntOrUnbounded(const ASTIntOrUnbounded* node, std::any& output) = 0;
                virtual absl::Status VisitASTRecursionDepthModifier(const ASTRecursionDepthModifier* node, std::any& output) = 0;
                virtual absl::Status VisitASTMapType(const ASTMapType* node, std::any& output) = 0;
                virtual absl::Status VisitASTLockMode(const ASTLockMode* node, std::any& output) = 0;
                virtual absl::Status VisitASTPipeRecursiveUnion(const ASTPipeRecursiveUnion* node, std::any& output) = 0;
                virtual absl::Status VisitASTRunStatement(const ASTRunStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTCreateSequenceStatement(const ASTCreateSequenceStatement* node, std::any& output) = 0;
                virtual absl::Status VisitASTAlterSequenceStatement(const ASTAlterSequenceStatement* node, std::any& output) = 0;
              };

      class DefaultParseTreeStatusVisitor : public ParseTreeStatusVisitor {
       public:
        virtual absl::Status DefaultVisit(const ASTNode* node, std::any& output) {
          return node->ChildrenAccept(*this, output);
        }
        absl::Status Visit(const ASTNode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
      
        absl::Status VisitASTQueryStatement(const ASTQueryStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSubpipelineStatement(const ASTSubpipelineStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAliasedQueryExpression(const ASTAliasedQueryExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTQuery(const ASTQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFromQuery(const ASTFromQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSubpipeline(const ASTSubpipeline* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeExtend(const ASTPipeExtend* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeRenameItem(const ASTPipeRenameItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeRename(const ASTPipeRename* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeAggregate(const ASTPipeAggregate* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeSetOperation(const ASTPipeSetOperation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeJoin(const ASTPipeJoin* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeCall(const ASTPipeCall* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeWindow(const ASTPipeWindow* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeWhere(const ASTPipeWhere* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeSelect(const ASTPipeSelect* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeLimitOffset(const ASTPipeLimitOffset* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeOrderBy(const ASTPipeOrderBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeDistinct(const ASTPipeDistinct* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeTablesample(const ASTPipeTablesample* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeMatchRecognize(const ASTPipeMatchRecognize* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeAs(const ASTPipeAs* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeDescribe(const ASTPipeDescribe* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeStaticDescribe(const ASTPipeStaticDescribe* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeAssert(const ASTPipeAssert* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeLog(const ASTPipeLog* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeDrop(const ASTPipeDrop* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeSetItem(const ASTPipeSetItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeSet(const ASTPipeSet* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipePivot(const ASTPipePivot* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeUnpivot(const ASTPipeUnpivot* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeIf(const ASTPipeIf* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeIfCase(const ASTPipeIfCase* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeFork(const ASTPipeFork* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeTee(const ASTPipeTee* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeWith(const ASTPipeWith* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeExportData(const ASTPipeExportData* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeCreateTable(const ASTPipeCreateTable* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeInsert(const ASTPipeInsert* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSelect(const ASTSelect* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSelectList(const ASTSelectList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSelectColumn(const ASTSelectColumn* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIntLiteral(const ASTIntLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentifier(const ASTIdentifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlias(const ASTAlias* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPathExpression(const ASTPathExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTablePathExpression(const ASTTablePathExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeJoinLhsPlaceholder(const ASTPipeJoinLhsPlaceholder* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFromClause(const ASTFromClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWhereClause(const ASTWhereClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBooleanLiteral(const ASTBooleanLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAndExpr(const ASTAndExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBinaryExpression(const ASTBinaryExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStringLiteral(const ASTStringLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStringLiteralComponent(const ASTStringLiteralComponent* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStar(const ASTStar* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOrExpr(const ASTOrExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTConcatExpr(const ASTConcatExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOrderingExpression(const ASTOrderingExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOrderBy(const ASTOrderBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupingItemOrder(const ASTGroupingItemOrder* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupingItem(const ASTGroupingItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupBy(const ASTGroupBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupByAll(const ASTGroupByAll* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLimitAll(const ASTLimitAll* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLimit(const ASTLimit* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLimitOffset(const ASTLimitOffset* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFloatLiteral(const ASTFloatLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNullLiteral(const ASTNullLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOnClause(const ASTOnClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAliasedQuery(const ASTAliasedQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTJoin(const ASTJoin* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAliasedGroupRows(const ASTAliasedGroupRows* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithClauseEntry(const ASTWithClauseEntry* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithClause(const ASTWithClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHaving(const ASTHaving* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSimpleType(const ASTSimpleType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTArrayType(const ASTArrayType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructField(const ASTStructField* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructType(const ASTStructType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionTypeArgList(const ASTFunctionTypeArgList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionType(const ASTFunctionType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCastExpression(const ASTCastExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSelectAs(const ASTSelectAs* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRollup(const ASTRollup* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCube(const ASTCube* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupingSet(const ASTGroupingSet* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGroupingSetList(const ASTGroupingSetList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExpressionWithAlias(const ASTExpressionWithAlias* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionCall(const ASTFunctionCall* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTChainedBaseExpr(const ASTChainedBaseExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTArrayConstructor(const ASTArrayConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructConstructorArg(const ASTStructConstructorArg* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInExpression(const ASTInExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInList(const ASTInList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBetweenExpression(const ASTBetweenExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNumericLiteral(const ASTNumericLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBigNumericLiteral(const ASTBigNumericLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBytesLiteral(const ASTBytesLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBytesLiteralComponent(const ASTBytesLiteralComponent* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMaxLiteral(const ASTMaxLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTJSONLiteral(const ASTJSONLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCaseValueExpression(const ASTCaseValueExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTArrayElement(const ASTArrayElement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCollate(const ASTCollate* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDotGeneralizedField(const ASTDotGeneralizedField* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDotIdentifier(const ASTDotIdentifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDotStar(const ASTDotStar* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExpressionSubquery(const ASTExpressionSubquery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExtractExpression(const ASTExtractExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHavingModifier(const ASTHavingModifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIntervalExpr(const ASTIntervalExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSequenceArg(const ASTSequenceArg* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNamedArgument(const ASTNamedArgument* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInputTableArgument(const ASTInputTableArgument* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNullOrder(const ASTNullOrder* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTParenthesizedJoin(const ASTParenthesizedJoin* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPartitionBy(const ASTPartitionBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperation(const ASTSetOperation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationMetadataList(const ASTSetOperationMetadataList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationAllOrDistinct(const ASTSetOperationAllOrDistinct* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationType(const ASTSetOperationType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationColumnMatchMode(const ASTSetOperationColumnMatchMode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationColumnPropagationMode(const ASTSetOperationColumnPropagationMode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOperationMetadata(const ASTSetOperationMetadata* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStarExceptList(const ASTStarExceptList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStarModifiers(const ASTStarModifiers* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStarReplaceItem(const ASTStarReplaceItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStarWithModifiers(const ASTStarWithModifiers* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTableSubquery(const ASTTableSubquery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnaryExpression(const ASTUnaryExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExpressionWithOptAlias(const ASTExpressionWithOptAlias* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnnestExpression(const ASTUnnestExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWindowClause(const ASTWindowClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWindowDefinition(const ASTWindowDefinition* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWindowFrame(const ASTWindowFrame* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWindowFrameExpr(const ASTWindowFrameExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLikeExpression(const ASTLikeExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTQuantifiedComparisonExpression(const ASTQuantifiedComparisonExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWindowSpecification(const ASTWindowSpecification* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithOffset(const ASTWithOffset* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAnySomeAllOp(const ASTAnySomeAllOp* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStatementList(const ASTStatementList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHintedStatement(const ASTHintedStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStatementWithPipeOperators(const ASTStatementWithPipeOperators* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExplainStatement(const ASTExplainStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDescribeStatement(const ASTDescribeStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTShowStatement(const ASTShowStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTransactionModeList(const ASTTransactionModeList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBeginStatement(const ASTBeginStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetTransactionStatement(const ASTSetTransactionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCommitStatement(const ASTCommitStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRollbackStatement(const ASTRollbackStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStartBatchStatement(const ASTStartBatchStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRunBatchStatement(const ASTRunBatchStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAbortBatchStatement(const ASTAbortBatchStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropEntityStatement(const ASTDropEntityStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropFunctionStatement(const ASTDropFunctionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropVectorIndexStatement(const ASTDropVectorIndexStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRenameStatement(const ASTRenameStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTImportStatement(const ASTImportStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTModuleStatement(const ASTModuleStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithConnectionClause(const ASTWithConnectionClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIntoAlias(const ASTIntoAlias* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPivotExpression(const ASTPivotExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPivotValue(const ASTPivotValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPivotExpressionList(const ASTPivotExpressionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPivotValueList(const ASTPivotValueList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPivotClause(const ASTPivotClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnpivotInItem(const ASTUnpivotInItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnpivotInItemList(const ASTUnpivotInItemList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnpivotClause(const ASTUnpivotClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUsingClause(const ASTUsingClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForSystemTime(const ASTForSystemTime* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMatchRecognizeClause(const ASTMatchRecognizeClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAfterMatchSkipClause(const ASTAfterMatchSkipClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRowPatternVariable(const ASTRowPatternVariable* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRowPatternOperation(const ASTRowPatternOperation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTEmptyRowPattern(const ASTEmptyRowPattern* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRowPatternAnchor(const ASTRowPatternAnchor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBoundedQuantifier(const ASTBoundedQuantifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTQuantifierBound(const ASTQuantifierBound* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFixedQuantifier(const ASTFixedQuantifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSymbolQuantifier(const ASTSymbolQuantifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRowPatternQuantification(const ASTRowPatternQuantification* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTQualify(const ASTQualify* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithReportModifier(const ASTWithReportModifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFormatClause(const ASTFormatClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPathExpressionList(const ASTPathExpressionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTParameterExpr(const ASTParameterExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSystemVariableExpr(const ASTSystemVariableExpr* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLambda(const ASTLambda* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTClusterBy(const ASTClusterBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNewConstructorArg(const ASTNewConstructorArg* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNewConstructor(const ASTNewConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBracedConstructorLhs(const ASTBracedConstructorLhs* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBracedConstructorFieldValue(const ASTBracedConstructorFieldValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBracedConstructorField(const ASTBracedConstructorField* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBracedConstructor(const ASTBracedConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBracedNewConstructor(const ASTBracedNewConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExtendedPathExpression(const ASTExtendedPathExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUpdateConstructor(const ASTUpdateConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructBracedConstructor(const ASTStructBracedConstructor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOptionsList(const ASTOptionsList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOptionsEntry(const ASTOptionsEntry* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionParameter(const ASTFunctionParameter* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionParameters(const ASTFunctionParameters* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFunctionDeclaration(const ASTFunctionDeclaration* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSqlFunctionBody(const ASTSqlFunctionBody* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTVFArgument(const ASTTVFArgument* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTVF(const ASTTVF* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTableClause(const ASTTableClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTModelClause(const ASTModelClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTConnectionClause(const ASTConnectionClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCloneDataSource(const ASTCloneDataSource* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCopyDataSource(const ASTCopyDataSource* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCloneDataSourceList(const ASTCloneDataSourceList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCloneDataStatement(const ASTCloneDataStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateConnectionStatement(const ASTCreateConnectionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateConstantStatement(const ASTCreateConstantStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateExternalSchemaStatement(const ASTCreateExternalSchemaStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAliasedQueryList(const ASTAliasedQueryList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTransformClause(const ASTTransformClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateModelStatement(const ASTCreateModelStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIndexAllColumns(const ASTIndexAllColumns* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIndexItemList(const ASTIndexItemList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateIndexStatement(const ASTCreateIndexStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExportDataStatement(const ASTExportDataStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExportModelStatement(const ASTExportModelStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExportMetadataStatement(const ASTExportMetadataStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCallStatement(const ASTCallStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDefineTableStatement(const ASTDefineTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateLocalityGroupStatement(const ASTCreateLocalityGroupStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateSnapshotStatement(const ASTCreateSnapshotStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTypeParameterList(const ASTTypeParameterList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTVFSchema(const ASTTVFSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTemplatedParameterType(const ASTTemplatedParameterType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDefaultLiteral(const ASTDefaultLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAnalyzeStatement(const ASTAnalyzeStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAssertStatement(const ASTAssertStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAssertRowsModified(const ASTAssertRowsModified* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTReturningClause(const ASTReturningClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTOnConflictClause(const ASTOnConflictClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDeleteStatement(const ASTDeleteStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnAttributeList(const ASTColumnAttributeList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructColumnField(const ASTStructColumnField* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnDefinition(const ASTColumnDefinition* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTableElementList(const ASTTableElementList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnList(const ASTColumnList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnPosition(const ASTColumnPosition* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInsertValuesRow(const ASTInsertValuesRow* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInsertValuesRowList(const ASTInsertValuesRowList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInsertStatement(const ASTInsertStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUpdateSetValue(const ASTUpdateSetValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUpdateItem(const ASTUpdateItem* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUpdateItemList(const ASTUpdateItemList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUpdateStatement(const ASTUpdateStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTruncateStatement(const ASTTruncateStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMergeAction(const ASTMergeAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMergeWhenClause(const ASTMergeWhenClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMergeStatement(const ASTMergeStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrivilege(const ASTPrivilege* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrivileges(const ASTPrivileges* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGranteeList(const ASTGranteeList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGrantStatement(const ASTGrantStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRevokeStatement(const ASTRevokeStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRepeatableClause(const ASTRepeatableClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFilterFieldsArg(const ASTFilterFieldsArg* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSampleSize(const ASTSampleSize* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithWeight(const ASTWithWeight* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSampleSuffix(const ASTSampleSuffix* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSampleClause(const ASTSampleClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetOptionsAction(const ASTSetOptionsAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetAsAction(const ASTSetAsAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddConstraintAction(const ASTAddConstraintAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropConstraintAction(const ASTDropConstraintAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddColumnIdentifierAction(const ASTAddColumnIdentifierAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddColumnAction(const ASTAddColumnAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropColumnAction(const ASTDropColumnAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRenameColumnAction(const ASTRenameColumnAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnDropGeneratedAction(const ASTAlterColumnDropGeneratedAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterColumnSetGeneratedAction(const ASTAlterColumnSetGeneratedAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGrantToClause(const ASTGrantToClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRestrictToClause(const ASTRestrictToClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTFilterUsingClause(const ASTFilterUsingClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRevokeFromClause(const ASTRevokeFromClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRenameToClause(const ASTRenameToClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSetCollateClause(const ASTSetCollateClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterSubEntityAction(const ASTAlterSubEntityAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddSubEntityAction(const ASTAddSubEntityAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropSubEntityAction(const ASTDropSubEntityAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAddTtlAction(const ASTAddTtlAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTReplaceTtlAction(const ASTReplaceTtlAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropTtlAction(const ASTDropTtlAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterActionList(const ASTAlterActionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForeignKeyActions(const ASTForeignKeyActions* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForeignKeyReference(const ASTForeignKeyReference* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTScript(const ASTScript* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTElseifClause(const ASTElseifClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTElseifClauseList(const ASTElseifClauseList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIfStatement(const ASTIfStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWhenThenClause(const ASTWhenThenClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWhenThenClauseList(const ASTWhenThenClauseList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCaseStatement(const ASTCaseStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHint(const ASTHint* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTHintEntry(const ASTHintEntry* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDescriptor(const ASTDescriptor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTArrayColumnSchema(const ASTArrayColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRangeColumnSchema(const ASTRangeColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMapColumnSchema(const ASTMapColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrimaryKeyElement(const ASTPrimaryKeyElement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrimaryKeyElementList(const ASTPrimaryKeyElementList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPrimaryKey(const ASTPrimaryKey* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForeignKey(const ASTForeignKey* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCheckConstraint(const ASTCheckConstraint* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDescriptorColumn(const ASTDescriptorColumn* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDescriptorColumnList(const ASTDescriptorColumnList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateEntityStatement(const ASTCreateEntityStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRaiseStatement(const ASTRaiseStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExceptionHandler(const ASTExceptionHandler* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExceptionHandlerList(const ASTExceptionHandlerList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBeginEndBlock(const ASTBeginEndBlock* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentifierList(const ASTIdentifierList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTVariableDeclaration(const ASTVariableDeclaration* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUntilClause(const ASTUntilClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTBreakStatement(const ASTBreakStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTContinueStatement(const ASTContinueStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDropStatement(const ASTDropStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTReturnStatement(const ASTReturnStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSingleAssignment(const ASTSingleAssignment* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTParameterAssignment(const ASTParameterAssignment* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateTableStatement(const ASTCreateTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateViewStatement(const ASTCreateViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateApproxViewStatement(const ASTCreateApproxViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWhileStatement(const ASTWhileStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRepeatStatement(const ASTRepeatStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTForInStatement(const ASTForInStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterConnectionStatement(const ASTAlterConnectionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterExternalSchemaStatement(const ASTAlterExternalSchemaStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterTableStatement(const ASTAlterTableStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterViewStatement(const ASTAlterViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterApproxViewStatement(const ASTAlterApproxViewStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterModelStatement(const ASTAlterModelStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterEntityStatement(const ASTAlterEntityStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRebuildAction(const ASTRebuildAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterIndexStatement(const ASTAlterIndexStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTStructColumnSchema(const ASTStructColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExecuteIntoClause(const ASTExecuteIntoClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExecuteUsingClause(const ASTExecuteUsingClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAuxLoadDataPartitionsClause(const ASTAuxLoadDataPartitionsClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLabel(const ASTLabel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithExpression(const ASTWithExpression* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTTtlClause(const ASTTtlClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLocation(const ASTLocation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTInputOutputClause(const ASTInputOutputClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSpannerTableOptions(const ASTSpannerTableOptions* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSpannerInterleaveClause(const ASTSpannerInterleaveClause* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSpannerAlterColumnAction(const ASTSpannerAlterColumnAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTSpannerSetOnDeleteAction(const ASTSpannerSetOnDeleteAction* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRangeLiteral(const ASTRangeLiteral* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRangeType(const ASTRangeType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreatePropertyGraphStatement(const ASTCreatePropertyGraphStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementTableList(const ASTGraphElementTableList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementTable(const ASTGraphElementTable* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphNodeTableReference(const ASTGraphNodeTableReference* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementLabelAndPropertiesList(const ASTGraphElementLabelAndPropertiesList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementLabelAndProperties(const ASTGraphElementLabelAndProperties* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphDerivedProperty(const ASTGraphDerivedProperty* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphDerivedPropertyList(const ASTGraphDerivedPropertyList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphProperties(const ASTGraphProperties* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphDynamicLabel(const ASTGraphDynamicLabel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphDynamicProperties(const ASTGraphDynamicProperties* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPattern(const ASTGraphPattern* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlQuery(const ASTGqlQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlGraphPatternQuery(const ASTGqlGraphPatternQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlLinearOpsQuery(const ASTGqlLinearOpsQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphTableQuery(const ASTGraphTableQuery* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementLabel(const ASTGraphElementLabel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphWildcardLabel(const ASTGraphWildcardLabel* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphLabelOperation(const ASTGraphLabelOperation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphLabelFilter(const ASTGraphLabelFilter* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphIsLabeledPredicate(const ASTGraphIsLabeledPredicate* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphElementPatternFiller(const ASTGraphElementPatternFiller* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPropertySpecification(const ASTGraphPropertySpecification* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPropertyNameAndValue(const ASTGraphPropertyNameAndValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphNodePattern(const ASTGraphNodePattern* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphLhsHint(const ASTGraphLhsHint* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphRhsHint(const ASTGraphRhsHint* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPathSearchPrefix(const ASTGraphPathSearchPrefix* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPathSearchPrefixCount(const ASTGraphPathSearchPrefixCount* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphEdgePattern(const ASTGraphEdgePattern* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPathMode(const ASTGraphPathMode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGraphPathPattern(const ASTGraphPathPattern* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlMatch(const ASTGqlMatch* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlReturn(const ASTGqlReturn* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlWith(const ASTGqlWith* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlFor(const ASTGqlFor* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlNamedCall(const ASTGqlNamedCall* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTYieldItemList(const ASTYieldItemList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlInlineSubqueryCall(const ASTGqlInlineSubqueryCall* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlLet(const ASTGqlLet* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlLetVariableDefinitionList(const ASTGqlLetVariableDefinitionList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlLetVariableDefinition(const ASTGqlLetVariableDefinition* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlFilter(const ASTGqlFilter* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlOperatorList(const ASTGqlOperatorList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlSetOperation(const ASTGqlSetOperation* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlPageLimit(const ASTGqlPageLimit* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlPageOffset(const ASTGqlPageOffset* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlPage(const ASTGqlPage* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlOrderByAndPage(const ASTGqlOrderByAndPage* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTGqlSample(const ASTGqlSample* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTWithModifier(const ASTWithModifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnWithOptions(const ASTColumnWithOptions* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTColumnWithOptionsList(const ASTColumnWithOptionsList* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMacroBody(const ASTMacroBody* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTDefineMacroStatement(const ASTDefineMacroStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTUndropStatement(const ASTUndropStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentityColumnInfo(const ASTIdentityColumnInfo* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentityColumnStartWith(const ASTIdentityColumnStartWith* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentityColumnIncrementBy(const ASTIdentityColumnIncrementBy* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentityColumnMaxValue(const ASTIdentityColumnMaxValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIdentityColumnMinValue(const ASTIdentityColumnMinValue* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAliasedQueryModifiers(const ASTAliasedQueryModifiers* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTIntOrUnbounded(const ASTIntOrUnbounded* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRecursionDepthModifier(const ASTRecursionDepthModifier* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTMapType(const ASTMapType* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTLockMode(const ASTLockMode* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTPipeRecursiveUnion(const ASTPipeRecursiveUnion* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTRunStatement(const ASTRunStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTCreateSequenceStatement(const ASTCreateSequenceStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }
        absl::Status VisitASTAlterSequenceStatement(const ASTAlterSequenceStatement* node, std::any& output) override {
          return DefaultVisit(node, output);
        }};

class NonRecursiveParseTreeVisitor {
 public:
  virtual ~NonRecursiveParseTreeVisitor() {}
  virtual absl::StatusOr<VisitResult> defaultVisit(const ASTNode* node) = 0;
  absl::StatusOr<VisitResult> visit(const ASTNode* node) {
    return defaultVisit(node);
  }
  virtual absl::StatusOr<VisitResult> visitASTQueryStatement(const ASTQueryStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSubpipelineStatement(const ASTSubpipelineStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAliasedQueryExpression(const ASTAliasedQueryExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQuery(const ASTQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFromQuery(const ASTFromQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSubpipeline(const ASTSubpipeline* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeExtend(const ASTPipeExtend* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeRenameItem(const ASTPipeRenameItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeRename(const ASTPipeRename* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeAggregate(const ASTPipeAggregate* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeSetOperation(const ASTPipeSetOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeJoin(const ASTPipeJoin* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeCall(const ASTPipeCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeWindow(const ASTPipeWindow* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeWhere(const ASTPipeWhere* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeSelect(const ASTPipeSelect* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeLimitOffset(const ASTPipeLimitOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeOrderBy(const ASTPipeOrderBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeDistinct(const ASTPipeDistinct* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeTablesample(const ASTPipeTablesample* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeMatchRecognize(const ASTPipeMatchRecognize* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeAs(const ASTPipeAs* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeDescribe(const ASTPipeDescribe* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeStaticDescribe(const ASTPipeStaticDescribe* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeAssert(const ASTPipeAssert* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeLog(const ASTPipeLog* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeDrop(const ASTPipeDrop* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeSetItem(const ASTPipeSetItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeSet(const ASTPipeSet* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipePivot(const ASTPipePivot* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeUnpivot(const ASTPipeUnpivot* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeIf(const ASTPipeIf* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeIfCase(const ASTPipeIfCase* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeFork(const ASTPipeFork* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeTee(const ASTPipeTee* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeWith(const ASTPipeWith* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeExportData(const ASTPipeExportData* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeCreateTable(const ASTPipeCreateTable* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeInsert(const ASTPipeInsert* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelect(const ASTSelect* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectList(const ASTSelectList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectColumn(const ASTSelectColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntLiteral(const ASTIntLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentifier(const ASTIdentifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlias(const ASTAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPathExpression(const ASTPathExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTablePathExpression(const ASTTablePathExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeJoinLhsPlaceholder(const ASTPipeJoinLhsPlaceholder* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFromClause(const ASTFromClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhereClause(const ASTWhereClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBooleanLiteral(const ASTBooleanLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAndExpr(const ASTAndExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBinaryExpression(const ASTBinaryExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStringLiteral(const ASTStringLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStringLiteralComponent(const ASTStringLiteralComponent* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStar(const ASTStar* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrExpr(const ASTOrExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTConcatExpr(const ASTConcatExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrderingExpression(const ASTOrderingExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOrderBy(const ASTOrderBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupingItemOrder(const ASTGroupingItemOrder* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupingItem(const ASTGroupingItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupBy(const ASTGroupBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupByAll(const ASTGroupByAll* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLimitAll(const ASTLimitAll* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLimit(const ASTLimit* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLimitOffset(const ASTLimitOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFloatLiteral(const ASTFloatLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNullLiteral(const ASTNullLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOnClause(const ASTOnClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAliasedQuery(const ASTAliasedQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTJoin(const ASTJoin* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAliasedGroupRows(const ASTAliasedGroupRows* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithClauseEntry(const ASTWithClauseEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithClause(const ASTWithClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHaving(const ASTHaving* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSimpleType(const ASTSimpleType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayType(const ASTArrayType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructField(const ASTStructField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructType(const ASTStructType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionTypeArgList(const ASTFunctionTypeArgList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionType(const ASTFunctionType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCastExpression(const ASTCastExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSelectAs(const ASTSelectAs* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRollup(const ASTRollup* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCube(const ASTCube* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupingSet(const ASTGroupingSet* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGroupingSetList(const ASTGroupingSetList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExpressionWithAlias(const ASTExpressionWithAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionCall(const ASTFunctionCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTChainedBaseExpr(const ASTChainedBaseExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayConstructor(const ASTArrayConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorArg(const ASTStructConstructorArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorWithParens(const ASTStructConstructorWithParens* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructConstructorWithKeyword(const ASTStructConstructorWithKeyword* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInExpression(const ASTInExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInList(const ASTInList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBetweenExpression(const ASTBetweenExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNumericLiteral(const ASTNumericLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBigNumericLiteral(const ASTBigNumericLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBytesLiteral(const ASTBytesLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBytesLiteralComponent(const ASTBytesLiteralComponent* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDateOrTimeLiteral(const ASTDateOrTimeLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMaxLiteral(const ASTMaxLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTJSONLiteral(const ASTJSONLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseValueExpression(const ASTCaseValueExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseNoValueExpression(const ASTCaseNoValueExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayElement(const ASTArrayElement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBitwiseShiftExpression(const ASTBitwiseShiftExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCollate(const ASTCollate* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotGeneralizedField(const ASTDotGeneralizedField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotIdentifier(const ASTDotIdentifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotStar(const ASTDotStar* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDotStarWithModifiers(const ASTDotStarWithModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExpressionSubquery(const ASTExpressionSubquery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExtractExpression(const ASTExtractExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHavingModifier(const ASTHavingModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntervalExpr(const ASTIntervalExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSequenceArg(const ASTSequenceArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNamedArgument(const ASTNamedArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInputTableArgument(const ASTInputTableArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNullOrder(const ASTNullOrder* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOnOrUsingClauseList(const ASTOnOrUsingClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParenthesizedJoin(const ASTParenthesizedJoin* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPartitionBy(const ASTPartitionBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperation(const ASTSetOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationMetadataList(const ASTSetOperationMetadataList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationAllOrDistinct(const ASTSetOperationAllOrDistinct* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationType(const ASTSetOperationType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationColumnMatchMode(const ASTSetOperationColumnMatchMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationColumnPropagationMode(const ASTSetOperationColumnPropagationMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOperationMetadata(const ASTSetOperationMetadata* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarExceptList(const ASTStarExceptList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarModifiers(const ASTStarModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarReplaceItem(const ASTStarReplaceItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStarWithModifiers(const ASTStarWithModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableSubquery(const ASTTableSubquery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnaryExpression(const ASTUnaryExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExpressionWithOptAlias(const ASTExpressionWithOptAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnnestExpression(const ASTUnnestExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowClause(const ASTWindowClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowDefinition(const ASTWindowDefinition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowFrame(const ASTWindowFrame* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowFrameExpr(const ASTWindowFrameExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLikeExpression(const ASTLikeExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQuantifiedComparisonExpression(const ASTQuantifiedComparisonExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWindowSpecification(const ASTWindowSpecification* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithOffset(const ASTWithOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnySomeAllOp(const ASTAnySomeAllOp* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStatementList(const ASTStatementList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHintedStatement(const ASTHintedStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStatementWithPipeOperators(const ASTStatementWithPipeOperators* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExplainStatement(const ASTExplainStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescribeStatement(const ASTDescribeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTShowStatement(const ASTShowStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionIsolationLevel(const ASTTransactionIsolationLevel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionReadWriteMode(const ASTTransactionReadWriteMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransactionModeList(const ASTTransactionModeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBeginStatement(const ASTBeginStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetTransactionStatement(const ASTSetTransactionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCommitStatement(const ASTCommitStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRollbackStatement(const ASTRollbackStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStartBatchStatement(const ASTStartBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRunBatchStatement(const ASTRunBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAbortBatchStatement(const ASTAbortBatchStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropEntityStatement(const ASTDropEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropFunctionStatement(const ASTDropFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropTableFunctionStatement(const ASTDropTableFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropAllRowAccessPoliciesStatement(const ASTDropAllRowAccessPoliciesStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropMaterializedViewStatement(const ASTDropMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropSnapshotTableStatement(const ASTDropSnapshotTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropSearchIndexStatement(const ASTDropSearchIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropVectorIndexStatement(const ASTDropVectorIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameStatement(const ASTRenameStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTImportStatement(const ASTImportStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTModuleStatement(const ASTModuleStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithConnectionClause(const ASTWithConnectionClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntoAlias(const ASTIntoAlias* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnnestExpressionWithOptAliasAndOffset(const ASTUnnestExpressionWithOptAliasAndOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotExpression(const ASTPivotExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotValue(const ASTPivotValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotExpressionList(const ASTPivotExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotValueList(const ASTPivotValueList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPivotClause(const ASTPivotClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItem(const ASTUnpivotInItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItemList(const ASTUnpivotInItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotClause(const ASTUnpivotClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUsingClause(const ASTUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForSystemTime(const ASTForSystemTime* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMatchRecognizeClause(const ASTMatchRecognizeClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAfterMatchSkipClause(const ASTAfterMatchSkipClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRowPatternVariable(const ASTRowPatternVariable* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRowPatternOperation(const ASTRowPatternOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTEmptyRowPattern(const ASTEmptyRowPattern* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRowPatternAnchor(const ASTRowPatternAnchor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBoundedQuantifier(const ASTBoundedQuantifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQuantifierBound(const ASTQuantifierBound* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFixedQuantifier(const ASTFixedQuantifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSymbolQuantifier(const ASTSymbolQuantifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRowPatternQuantification(const ASTRowPatternQuantification* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTQualify(const ASTQualify* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTClampedBetweenModifier(const ASTClampedBetweenModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithReportModifier(const ASTWithReportModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFormatClause(const ASTFormatClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPathExpressionList(const ASTPathExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParameterExpr(const ASTParameterExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSystemVariableExpr(const ASTSystemVariableExpr* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLambda(const ASTLambda* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnalyticFunctionCall(const ASTAnalyticFunctionCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTClusterBy(const ASTClusterBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNewConstructorArg(const ASTNewConstructorArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNewConstructor(const ASTNewConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBracedConstructorLhs(const ASTBracedConstructorLhs* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBracedConstructorFieldValue(const ASTBracedConstructorFieldValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBracedConstructorField(const ASTBracedConstructorField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBracedConstructor(const ASTBracedConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBracedNewConstructor(const ASTBracedNewConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExtendedPathExpression(const ASTExtendedPathExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateConstructor(const ASTUpdateConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructBracedConstructor(const ASTStructBracedConstructor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOptionsList(const ASTOptionsList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOptionsEntry(const ASTOptionsEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionParameter(const ASTFunctionParameter* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionParameters(const ASTFunctionParameters* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFunctionDeclaration(const ASTFunctionDeclaration* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSqlFunctionBody(const ASTSqlFunctionBody* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFArgument(const ASTTVFArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVF(const ASTTVF* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableClause(const ASTTableClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTModelClause(const ASTModelClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTConnectionClause(const ASTConnectionClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataSource(const ASTCloneDataSource* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCopyDataSource(const ASTCopyDataSource* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataSourceList(const ASTCloneDataSourceList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCloneDataStatement(const ASTCloneDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateConnectionStatement(const ASTCreateConnectionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateConstantStatement(const ASTCreateConstantStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateDatabaseStatement(const ASTCreateDatabaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateProcedureStatement(const ASTCreateProcedureStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSchemaStatement(const ASTCreateSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateExternalSchemaStatement(const ASTCreateExternalSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAliasedQueryList(const ASTAliasedQueryList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTransformClause(const ASTTransformClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateModelStatement(const ASTCreateModelStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexAllColumns(const ASTIndexAllColumns* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexItemList(const ASTIndexItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexStoringExpressionList(const ASTIndexStoringExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIndexUnnestExpressionList(const ASTIndexUnnestExpressionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateIndexStatement(const ASTCreateIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExportDataStatement(const ASTExportDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExportModelStatement(const ASTExportModelStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExportMetadataStatement(const ASTExportMetadataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCallStatement(const ASTCallStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDefineTableStatement(const ASTDefineTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateLocalityGroupStatement(const ASTCreateLocalityGroupStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithPartitionColumnsClause(const ASTWithPartitionColumnsClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSnapshotStatement(const ASTCreateSnapshotStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSnapshotTableStatement(const ASTCreateSnapshotTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTypeParameterList(const ASTTypeParameterList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFSchema(const ASTTVFSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTVFSchemaColumn(const ASTTVFSchemaColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableAndColumnInfo(const ASTTableAndColumnInfo* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableAndColumnInfoList(const ASTTableAndColumnInfoList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTemplatedParameterType(const ASTTemplatedParameterType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDefaultLiteral(const ASTDefaultLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAnalyzeStatement(const ASTAnalyzeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssertStatement(const ASTAssertStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssertRowsModified(const ASTAssertRowsModified* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReturningClause(const ASTReturningClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTOnConflictClause(const ASTOnConflictClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDeleteStatement(const ASTDeleteStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTNotNullColumnAttribute(const ASTNotNullColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHiddenColumnAttribute(const ASTHiddenColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKeyColumnAttribute(const ASTPrimaryKeyColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyColumnAttribute(const ASTForeignKeyColumnAttribute* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnAttributeList(const ASTColumnAttributeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructColumnField(const ASTStructColumnField* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGeneratedColumnInfo(const ASTGeneratedColumnInfo* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnDefinition(const ASTColumnDefinition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTableElementList(const ASTTableElementList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnList(const ASTColumnList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnPosition(const ASTColumnPosition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertValuesRow(const ASTInsertValuesRow* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertValuesRowList(const ASTInsertValuesRowList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInsertStatement(const ASTInsertStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateSetValue(const ASTUpdateSetValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateItem(const ASTUpdateItem* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateItemList(const ASTUpdateItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUpdateStatement(const ASTUpdateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTruncateStatement(const ASTTruncateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeAction(const ASTMergeAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeWhenClause(const ASTMergeWhenClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeWhenClauseList(const ASTMergeWhenClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMergeStatement(const ASTMergeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrivilege(const ASTPrivilege* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrivileges(const ASTPrivileges* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGranteeList(const ASTGranteeList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGrantStatement(const ASTGrantStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRevokeStatement(const ASTRevokeStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRepeatableClause(const ASTRepeatableClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFilterFieldsArg(const ASTFilterFieldsArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReplaceFieldsArg(const ASTReplaceFieldsArg* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReplaceFieldsExpression(const ASTReplaceFieldsExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleSize(const ASTSampleSize* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithWeight(const ASTWithWeight* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleSuffix(const ASTSampleSuffix* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSampleClause(const ASTSampleClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetOptionsAction(const ASTSetOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetAsAction(const ASTSetAsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddConstraintAction(const ASTAddConstraintAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropPrimaryKeyAction(const ASTDropPrimaryKeyAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropConstraintAction(const ASTDropConstraintAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterConstraintEnforcementAction(const ASTAlterConstraintEnforcementAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterConstraintSetOptionsAction(const ASTAlterConstraintSetOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddColumnIdentifierAction(const ASTAddColumnIdentifierAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddColumnAction(const ASTAddColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropColumnAction(const ASTDropColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameColumnAction(const ASTRenameColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnTypeAction(const ASTAlterColumnTypeAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnOptionsAction(const ASTAlterColumnOptionsAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnSetDefaultAction(const ASTAlterColumnSetDefaultAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnDropDefaultAction(const ASTAlterColumnDropDefaultAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnDropNotNullAction(const ASTAlterColumnDropNotNullAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnDropGeneratedAction(const ASTAlterColumnDropGeneratedAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterColumnSetGeneratedAction(const ASTAlterColumnSetGeneratedAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGrantToClause(const ASTGrantToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRestrictToClause(const ASTRestrictToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddToRestricteeListClause(const ASTAddToRestricteeListClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRemoveFromRestricteeListClause(const ASTRemoveFromRestricteeListClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTFilterUsingClause(const ASTFilterUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRevokeFromClause(const ASTRevokeFromClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRenameToClause(const ASTRenameToClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSetCollateClause(const ASTSetCollateClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterSubEntityAction(const ASTAlterSubEntityAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddSubEntityAction(const ASTAddSubEntityAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropSubEntityAction(const ASTDropSubEntityAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAddTtlAction(const ASTAddTtlAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReplaceTtlAction(const ASTReplaceTtlAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropTtlAction(const ASTDropTtlAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterActionList(const ASTAlterActionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterAllRowAccessPoliciesStatement(const ASTAlterAllRowAccessPoliciesStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyActions(const ASTForeignKeyActions* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKeyReference(const ASTForeignKeyReference* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTScript(const ASTScript* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTElseifClause(const ASTElseifClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTElseifClauseList(const ASTElseifClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIfStatement(const ASTIfStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhenThenClause(const ASTWhenThenClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhenThenClauseList(const ASTWhenThenClauseList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCaseStatement(const ASTCaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHint(const ASTHint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTHintEntry(const ASTHintEntry* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUnpivotInItemLabel(const ASTUnpivotInItemLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptor(const ASTDescriptor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSimpleColumnSchema(const ASTSimpleColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTArrayColumnSchema(const ASTArrayColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRangeColumnSchema(const ASTRangeColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMapColumnSchema(const ASTMapColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKeyElement(const ASTPrimaryKeyElement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKeyElementList(const ASTPrimaryKeyElementList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPrimaryKey(const ASTPrimaryKey* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForeignKey(const ASTForeignKey* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCheckConstraint(const ASTCheckConstraint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptorColumn(const ASTDescriptorColumn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDescriptorColumnList(const ASTDescriptorColumnList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateEntityStatement(const ASTCreateEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRaiseStatement(const ASTRaiseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExceptionHandler(const ASTExceptionHandler* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExceptionHandlerList(const ASTExceptionHandlerList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBeginEndBlock(const ASTBeginEndBlock* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentifierList(const ASTIdentifierList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTVariableDeclaration(const ASTVariableDeclaration* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUntilClause(const ASTUntilClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTBreakStatement(const ASTBreakStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTContinueStatement(const ASTContinueStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropPrivilegeRestrictionStatement(const ASTDropPrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropRowAccessPolicyStatement(const ASTDropRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreatePrivilegeRestrictionStatement(const ASTCreatePrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateRowAccessPolicyStatement(const ASTCreateRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDropStatement(const ASTDropStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTReturnStatement(const ASTReturnStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSingleAssignment(const ASTSingleAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTParameterAssignment(const ASTParameterAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSystemVariableAssignment(const ASTSystemVariableAssignment* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAssignmentFromStruct(const ASTAssignmentFromStruct* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateTableStatement(const ASTCreateTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateExternalTableStatement(const ASTCreateExternalTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateViewStatement(const ASTCreateViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateMaterializedViewStatement(const ASTCreateMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateApproxViewStatement(const ASTCreateApproxViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWhileStatement(const ASTWhileStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRepeatStatement(const ASTRepeatStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTForInStatement(const ASTForInStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterConnectionStatement(const ASTAlterConnectionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterDatabaseStatement(const ASTAlterDatabaseStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterSchemaStatement(const ASTAlterSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterExternalSchemaStatement(const ASTAlterExternalSchemaStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterTableStatement(const ASTAlterTableStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterViewStatement(const ASTAlterViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterMaterializedViewStatement(const ASTAlterMaterializedViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterApproxViewStatement(const ASTAlterApproxViewStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterModelStatement(const ASTAlterModelStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterPrivilegeRestrictionStatement(const ASTAlterPrivilegeRestrictionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterRowAccessPolicyStatement(const ASTAlterRowAccessPolicyStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterEntityStatement(const ASTAlterEntityStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRebuildAction(const ASTRebuildAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterIndexStatement(const ASTAlterIndexStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateFunctionStatement(const ASTCreateFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateTableFunctionStatement(const ASTCreateTableFunctionStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTStructColumnSchema(const ASTStructColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInferredTypeColumnSchema(const ASTInferredTypeColumnSchema* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteIntoClause(const ASTExecuteIntoClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteUsingArgument(const ASTExecuteUsingArgument* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteUsingClause(const ASTExecuteUsingClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTExecuteImmediateStatement(const ASTExecuteImmediateStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAuxLoadDataFromFilesOptionsList(const ASTAuxLoadDataFromFilesOptionsList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAuxLoadDataPartitionsClause(const ASTAuxLoadDataPartitionsClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAuxLoadDataStatement(const ASTAuxLoadDataStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLabel(const ASTLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithExpression(const ASTWithExpression* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTTtlClause(const ASTTtlClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLocation(const ASTLocation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTInputOutputClause(const ASTInputOutputClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSpannerTableOptions(const ASTSpannerTableOptions* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSpannerInterleaveClause(const ASTSpannerInterleaveClause* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSpannerAlterColumnAction(const ASTSpannerAlterColumnAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTSpannerSetOnDeleteAction(const ASTSpannerSetOnDeleteAction* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRangeLiteral(const ASTRangeLiteral* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRangeType(const ASTRangeType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreatePropertyGraphStatement(const ASTCreatePropertyGraphStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementTableList(const ASTGraphElementTableList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementTable(const ASTGraphElementTable* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphNodeTableReference(const ASTGraphNodeTableReference* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementLabelAndPropertiesList(const ASTGraphElementLabelAndPropertiesList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementLabelAndProperties(const ASTGraphElementLabelAndProperties* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphDerivedProperty(const ASTGraphDerivedProperty* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphDerivedPropertyList(const ASTGraphDerivedPropertyList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphProperties(const ASTGraphProperties* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphDynamicLabel(const ASTGraphDynamicLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphDynamicProperties(const ASTGraphDynamicProperties* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPattern(const ASTGraphPattern* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlQuery(const ASTGqlQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlGraphPatternQuery(const ASTGqlGraphPatternQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlLinearOpsQuery(const ASTGqlLinearOpsQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphTableQuery(const ASTGraphTableQuery* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementLabel(const ASTGraphElementLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphWildcardLabel(const ASTGraphWildcardLabel* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphLabelOperation(const ASTGraphLabelOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphLabelFilter(const ASTGraphLabelFilter* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphIsLabeledPredicate(const ASTGraphIsLabeledPredicate* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphElementPatternFiller(const ASTGraphElementPatternFiller* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPropertySpecification(const ASTGraphPropertySpecification* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPropertyNameAndValue(const ASTGraphPropertyNameAndValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphNodePattern(const ASTGraphNodePattern* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphLhsHint(const ASTGraphLhsHint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphRhsHint(const ASTGraphRhsHint* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPathSearchPrefix(const ASTGraphPathSearchPrefix* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPathSearchPrefixCount(const ASTGraphPathSearchPrefixCount* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphEdgePattern(const ASTGraphEdgePattern* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPathMode(const ASTGraphPathMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGraphPathPattern(const ASTGraphPathPattern* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlMatch(const ASTGqlMatch* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlReturn(const ASTGqlReturn* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlWith(const ASTGqlWith* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlFor(const ASTGqlFor* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlNamedCall(const ASTGqlNamedCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTYieldItemList(const ASTYieldItemList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlInlineSubqueryCall(const ASTGqlInlineSubqueryCall* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlLet(const ASTGqlLet* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlLetVariableDefinitionList(const ASTGqlLetVariableDefinitionList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlLetVariableDefinition(const ASTGqlLetVariableDefinition* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlFilter(const ASTGqlFilter* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlOperatorList(const ASTGqlOperatorList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlSetOperation(const ASTGqlSetOperation* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlPageLimit(const ASTGqlPageLimit* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlPageOffset(const ASTGqlPageOffset* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlPage(const ASTGqlPage* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlOrderByAndPage(const ASTGqlOrderByAndPage* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTGqlSample(const ASTGqlSample* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTWithModifier(const ASTWithModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnWithOptions(const ASTColumnWithOptions* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTColumnWithOptionsList(const ASTColumnWithOptionsList* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMacroBody(const ASTMacroBody* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTDefineMacroStatement(const ASTDefineMacroStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTUndropStatement(const ASTUndropStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentityColumnInfo(const ASTIdentityColumnInfo* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentityColumnStartWith(const ASTIdentityColumnStartWith* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentityColumnIncrementBy(const ASTIdentityColumnIncrementBy* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentityColumnMaxValue(const ASTIdentityColumnMaxValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIdentityColumnMinValue(const ASTIdentityColumnMinValue* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAliasedQueryModifiers(const ASTAliasedQueryModifiers* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTIntOrUnbounded(const ASTIntOrUnbounded* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRecursionDepthModifier(const ASTRecursionDepthModifier* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTMapType(const ASTMapType* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTLockMode(const ASTLockMode* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTPipeRecursiveUnion(const ASTPipeRecursiveUnion* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTRunStatement(const ASTRunStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTCreateSequenceStatement(const ASTCreateSequenceStatement* node) {return defaultVisit(node);};

  virtual absl::StatusOr<VisitResult> visitASTAlterSequenceStatement(const ASTAlterSequenceStatement* node) {return defaultVisit(node);};

};
}  // namespace googlesql
#endif  // STORAGE_GOOGLESQL_PARSER_PARSE_TREE_VISITOR_H_
