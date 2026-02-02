#include "googlesql/parser/parse_tree.h"
namespace googlesql {
void ASTQueryStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQueryStatement(this, data);
}

void ASTSubpipelineStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSubpipelineStatement(this, data);
}

void ASTAliasedQueryExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAliasedQueryExpression(this, data);
}

void ASTQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQuery(this, data);
}

void ASTFromQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFromQuery(this, data);
}

void ASTSubpipeline::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSubpipeline(this, data);
}

void ASTPipeExtend::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeExtend(this, data);
}

void ASTPipeRenameItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeRenameItem(this, data);
}

void ASTPipeRename::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeRename(this, data);
}

void ASTPipeAggregate::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeAggregate(this, data);
}

void ASTPipeSetOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeSetOperation(this, data);
}

void ASTPipeJoin::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeJoin(this, data);
}

void ASTPipeCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeCall(this, data);
}

void ASTPipeWindow::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeWindow(this, data);
}

void ASTPipeWhere::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeWhere(this, data);
}

void ASTPipeSelect::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeSelect(this, data);
}

void ASTPipeLimitOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeLimitOffset(this, data);
}

void ASTPipeOrderBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeOrderBy(this, data);
}

void ASTPipeDistinct::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeDistinct(this, data);
}

void ASTPipeTablesample::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeTablesample(this, data);
}

void ASTPipeMatchRecognize::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeMatchRecognize(this, data);
}

void ASTPipeAs::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeAs(this, data);
}

void ASTPipeDescribe::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeDescribe(this, data);
}

void ASTPipeStaticDescribe::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeStaticDescribe(this, data);
}

void ASTPipeAssert::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeAssert(this, data);
}

void ASTPipeLog::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeLog(this, data);
}

void ASTPipeDrop::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeDrop(this, data);
}

void ASTPipeSetItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeSetItem(this, data);
}

void ASTPipeSet::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeSet(this, data);
}

void ASTPipePivot::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipePivot(this, data);
}

void ASTPipeUnpivot::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeUnpivot(this, data);
}

void ASTPipeIf::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeIf(this, data);
}

void ASTPipeIfCase::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeIfCase(this, data);
}

void ASTPipeFork::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeFork(this, data);
}

void ASTPipeTee::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeTee(this, data);
}

void ASTPipeWith::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeWith(this, data);
}

void ASTPipeExportData::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeExportData(this, data);
}

void ASTPipeCreateTable::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeCreateTable(this, data);
}

void ASTPipeInsert::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeInsert(this, data);
}

void ASTSelect::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelect(this, data);
}

void ASTSelectList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectList(this, data);
}

void ASTSelectColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectColumn(this, data);
}

void ASTIntLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntLiteral(this, data);
}

void ASTIdentifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentifier(this, data);
}

void ASTAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlias(this, data);
}

void ASTPathExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPathExpression(this, data);
}

void ASTTablePathExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTablePathExpression(this, data);
}

void ASTPipeJoinLhsPlaceholder::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeJoinLhsPlaceholder(this, data);
}

void ASTFromClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFromClause(this, data);
}

void ASTWhereClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhereClause(this, data);
}

void ASTBooleanLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBooleanLiteral(this, data);
}

void ASTAndExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAndExpr(this, data);
}

void ASTBinaryExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBinaryExpression(this, data);
}

void ASTStringLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStringLiteral(this, data);
}

void ASTStringLiteralComponent::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStringLiteralComponent(this, data);
}

void ASTStar::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStar(this, data);
}

void ASTOrExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrExpr(this, data);
}

void ASTConcatExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTConcatExpr(this, data);
}

void ASTOrderingExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrderingExpression(this, data);
}

void ASTOrderBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOrderBy(this, data);
}

void ASTGroupingItemOrder::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupingItemOrder(this, data);
}

void ASTGroupingItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupingItem(this, data);
}

void ASTGroupBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupBy(this, data);
}

void ASTGroupByAll::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupByAll(this, data);
}

void ASTLimitAll::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLimitAll(this, data);
}

void ASTLimit::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLimit(this, data);
}

void ASTLimitOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLimitOffset(this, data);
}

void ASTFloatLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFloatLiteral(this, data);
}

void ASTNullLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNullLiteral(this, data);
}

void ASTOnClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOnClause(this, data);
}

void ASTAliasedQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAliasedQuery(this, data);
}

void ASTJoin::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTJoin(this, data);
}

void ASTAliasedGroupRows::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAliasedGroupRows(this, data);
}

void ASTWithClauseEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithClauseEntry(this, data);
}

void ASTWithClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithClause(this, data);
}

void ASTHaving::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHaving(this, data);
}

void ASTSimpleType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSimpleType(this, data);
}

void ASTArrayType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayType(this, data);
}

void ASTStructField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructField(this, data);
}

void ASTStructType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructType(this, data);
}

void ASTFunctionTypeArgList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionTypeArgList(this, data);
}

void ASTFunctionType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionType(this, data);
}

void ASTCastExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCastExpression(this, data);
}

void ASTSelectAs::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSelectAs(this, data);
}

void ASTRollup::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRollup(this, data);
}

void ASTCube::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCube(this, data);
}

void ASTGroupingSet::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupingSet(this, data);
}

void ASTGroupingSetList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGroupingSetList(this, data);
}

void ASTExpressionWithAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExpressionWithAlias(this, data);
}

void ASTFunctionCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionCall(this, data);
}

void ASTChainedBaseExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTChainedBaseExpr(this, data);
}

void ASTArrayConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayConstructor(this, data);
}

void ASTStructConstructorArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorArg(this, data);
}

void ASTStructConstructorWithParens::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorWithParens(this, data);
}

void ASTStructConstructorWithKeyword::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructConstructorWithKeyword(this, data);
}

void ASTInExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInExpression(this, data);
}

void ASTInList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInList(this, data);
}

void ASTBetweenExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBetweenExpression(this, data);
}

void ASTNumericLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNumericLiteral(this, data);
}

void ASTBigNumericLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBigNumericLiteral(this, data);
}

void ASTBytesLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBytesLiteral(this, data);
}

void ASTBytesLiteralComponent::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBytesLiteralComponent(this, data);
}

void ASTDateOrTimeLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDateOrTimeLiteral(this, data);
}

void ASTMaxLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMaxLiteral(this, data);
}

void ASTJSONLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTJSONLiteral(this, data);
}

void ASTCaseValueExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseValueExpression(this, data);
}

void ASTCaseNoValueExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseNoValueExpression(this, data);
}

void ASTArrayElement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayElement(this, data);
}

void ASTBitwiseShiftExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBitwiseShiftExpression(this, data);
}

void ASTCollate::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCollate(this, data);
}

void ASTDotGeneralizedField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotGeneralizedField(this, data);
}

void ASTDotIdentifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotIdentifier(this, data);
}

void ASTDotStar::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotStar(this, data);
}

void ASTDotStarWithModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDotStarWithModifiers(this, data);
}

void ASTExpressionSubquery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExpressionSubquery(this, data);
}

void ASTExtractExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExtractExpression(this, data);
}

void ASTHavingModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHavingModifier(this, data);
}

void ASTIntervalExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntervalExpr(this, data);
}

void ASTSequenceArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSequenceArg(this, data);
}

void ASTNamedArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNamedArgument(this, data);
}

void ASTInputTableArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInputTableArgument(this, data);
}

void ASTNullOrder::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNullOrder(this, data);
}

void ASTOnOrUsingClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOnOrUsingClauseList(this, data);
}

void ASTParenthesizedJoin::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParenthesizedJoin(this, data);
}

void ASTPartitionBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPartitionBy(this, data);
}

void ASTSetOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperation(this, data);
}

void ASTSetOperationMetadataList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationMetadataList(this, data);
}

void ASTSetOperationAllOrDistinct::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationAllOrDistinct(this, data);
}

void ASTSetOperationType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationType(this, data);
}

void ASTSetOperationColumnMatchMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationColumnMatchMode(this, data);
}

void ASTSetOperationColumnPropagationMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationColumnPropagationMode(this, data);
}

void ASTSetOperationMetadata::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOperationMetadata(this, data);
}

void ASTStarExceptList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarExceptList(this, data);
}

void ASTStarModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarModifiers(this, data);
}

void ASTStarReplaceItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarReplaceItem(this, data);
}

void ASTStarWithModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStarWithModifiers(this, data);
}

void ASTTableSubquery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableSubquery(this, data);
}

void ASTUnaryExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnaryExpression(this, data);
}

void ASTExpressionWithOptAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExpressionWithOptAlias(this, data);
}

void ASTUnnestExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnnestExpression(this, data);
}

void ASTWindowClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowClause(this, data);
}

void ASTWindowDefinition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowDefinition(this, data);
}

void ASTWindowFrame::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowFrame(this, data);
}

void ASTWindowFrameExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowFrameExpr(this, data);
}

void ASTLikeExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLikeExpression(this, data);
}

void ASTQuantifiedComparisonExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQuantifiedComparisonExpression(this, data);
}

void ASTWindowSpecification::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWindowSpecification(this, data);
}

void ASTWithOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithOffset(this, data);
}

void ASTAnySomeAllOp::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnySomeAllOp(this, data);
}

void ASTStatementList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStatementList(this, data);
}

void ASTHintedStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHintedStatement(this, data);
}

void ASTStatementWithPipeOperators::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStatementWithPipeOperators(this, data);
}

void ASTExplainStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExplainStatement(this, data);
}

void ASTDescribeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescribeStatement(this, data);
}

void ASTShowStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTShowStatement(this, data);
}

void ASTTransactionIsolationLevel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionIsolationLevel(this, data);
}

void ASTTransactionReadWriteMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionReadWriteMode(this, data);
}

void ASTTransactionModeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransactionModeList(this, data);
}

void ASTBeginStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBeginStatement(this, data);
}

void ASTSetTransactionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetTransactionStatement(this, data);
}

void ASTCommitStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCommitStatement(this, data);
}

void ASTRollbackStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRollbackStatement(this, data);
}

void ASTStartBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStartBatchStatement(this, data);
}

void ASTRunBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRunBatchStatement(this, data);
}

void ASTAbortBatchStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAbortBatchStatement(this, data);
}

void ASTDropEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropEntityStatement(this, data);
}

void ASTDropFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropFunctionStatement(this, data);
}

void ASTDropTableFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropTableFunctionStatement(this, data);
}

void ASTDropAllRowAccessPoliciesStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropAllRowAccessPoliciesStatement(this, data);
}

void ASTDropMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropMaterializedViewStatement(this, data);
}

void ASTDropSnapshotTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropSnapshotTableStatement(this, data);
}

void ASTDropSearchIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropSearchIndexStatement(this, data);
}

void ASTDropVectorIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropVectorIndexStatement(this, data);
}

void ASTRenameStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameStatement(this, data);
}

void ASTImportStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTImportStatement(this, data);
}

void ASTModuleStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTModuleStatement(this, data);
}

void ASTWithConnectionClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithConnectionClause(this, data);
}

void ASTIntoAlias::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntoAlias(this, data);
}

void ASTUnnestExpressionWithOptAliasAndOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnnestExpressionWithOptAliasAndOffset(this, data);
}

void ASTPivotExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotExpression(this, data);
}

void ASTPivotValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotValue(this, data);
}

void ASTPivotExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotExpressionList(this, data);
}

void ASTPivotValueList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotValueList(this, data);
}

void ASTPivotClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPivotClause(this, data);
}

void ASTUnpivotInItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItem(this, data);
}

void ASTUnpivotInItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItemList(this, data);
}

void ASTUnpivotClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotClause(this, data);
}

void ASTUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUsingClause(this, data);
}

void ASTForSystemTime::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForSystemTime(this, data);
}

void ASTMatchRecognizeClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMatchRecognizeClause(this, data);
}

void ASTAfterMatchSkipClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAfterMatchSkipClause(this, data);
}

void ASTRowPatternVariable::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRowPatternVariable(this, data);
}

void ASTRowPatternOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRowPatternOperation(this, data);
}

void ASTEmptyRowPattern::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTEmptyRowPattern(this, data);
}

void ASTRowPatternAnchor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRowPatternAnchor(this, data);
}

void ASTBoundedQuantifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBoundedQuantifier(this, data);
}

void ASTQuantifierBound::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQuantifierBound(this, data);
}

void ASTFixedQuantifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFixedQuantifier(this, data);
}

void ASTSymbolQuantifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSymbolQuantifier(this, data);
}

void ASTRowPatternQuantification::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRowPatternQuantification(this, data);
}

void ASTQualify::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTQualify(this, data);
}

void ASTClampedBetweenModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTClampedBetweenModifier(this, data);
}

void ASTWithReportModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithReportModifier(this, data);
}

void ASTFormatClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFormatClause(this, data);
}

void ASTPathExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPathExpressionList(this, data);
}

void ASTParameterExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParameterExpr(this, data);
}

void ASTSystemVariableExpr::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSystemVariableExpr(this, data);
}

void ASTLambda::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLambda(this, data);
}

void ASTAnalyticFunctionCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnalyticFunctionCall(this, data);
}

void ASTClusterBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTClusterBy(this, data);
}

void ASTNewConstructorArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNewConstructorArg(this, data);
}

void ASTNewConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNewConstructor(this, data);
}

void ASTBracedConstructorLhs::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBracedConstructorLhs(this, data);
}

void ASTBracedConstructorFieldValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBracedConstructorFieldValue(this, data);
}

void ASTBracedConstructorField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBracedConstructorField(this, data);
}

void ASTBracedConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBracedConstructor(this, data);
}

void ASTBracedNewConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBracedNewConstructor(this, data);
}

void ASTExtendedPathExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExtendedPathExpression(this, data);
}

void ASTUpdateConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateConstructor(this, data);
}

void ASTStructBracedConstructor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructBracedConstructor(this, data);
}

void ASTOptionsList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOptionsList(this, data);
}

void ASTOptionsEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOptionsEntry(this, data);
}

void ASTFunctionParameter::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionParameter(this, data);
}

void ASTFunctionParameters::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionParameters(this, data);
}

void ASTFunctionDeclaration::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFunctionDeclaration(this, data);
}

void ASTSqlFunctionBody::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSqlFunctionBody(this, data);
}

void ASTTVFArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFArgument(this, data);
}

void ASTTVF::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVF(this, data);
}

void ASTTableClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableClause(this, data);
}

void ASTModelClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTModelClause(this, data);
}

void ASTConnectionClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTConnectionClause(this, data);
}

void ASTCloneDataSource::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataSource(this, data);
}

void ASTCopyDataSource::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCopyDataSource(this, data);
}

void ASTCloneDataSourceList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataSourceList(this, data);
}

void ASTCloneDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCloneDataStatement(this, data);
}

void ASTCreateConnectionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateConnectionStatement(this, data);
}

void ASTCreateConstantStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateConstantStatement(this, data);
}

void ASTCreateDatabaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateDatabaseStatement(this, data);
}

void ASTCreateProcedureStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateProcedureStatement(this, data);
}

void ASTCreateSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSchemaStatement(this, data);
}

void ASTCreateExternalSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateExternalSchemaStatement(this, data);
}

void ASTAliasedQueryList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAliasedQueryList(this, data);
}

void ASTTransformClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTransformClause(this, data);
}

void ASTCreateModelStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateModelStatement(this, data);
}

void ASTIndexAllColumns::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexAllColumns(this, data);
}

void ASTIndexItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexItemList(this, data);
}

void ASTIndexStoringExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexStoringExpressionList(this, data);
}

void ASTIndexUnnestExpressionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIndexUnnestExpressionList(this, data);
}

void ASTCreateIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateIndexStatement(this, data);
}

void ASTExportDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExportDataStatement(this, data);
}

void ASTExportModelStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExportModelStatement(this, data);
}

void ASTExportMetadataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExportMetadataStatement(this, data);
}

void ASTCallStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCallStatement(this, data);
}

void ASTDefineTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDefineTableStatement(this, data);
}

void ASTCreateLocalityGroupStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateLocalityGroupStatement(this, data);
}

void ASTWithPartitionColumnsClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithPartitionColumnsClause(this, data);
}

void ASTCreateSnapshotStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSnapshotStatement(this, data);
}

void ASTCreateSnapshotTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSnapshotTableStatement(this, data);
}

void ASTTypeParameterList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTypeParameterList(this, data);
}

void ASTTVFSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFSchema(this, data);
}

void ASTTVFSchemaColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTVFSchemaColumn(this, data);
}

void ASTTableAndColumnInfo::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableAndColumnInfo(this, data);
}

void ASTTableAndColumnInfoList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableAndColumnInfoList(this, data);
}

void ASTTemplatedParameterType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTemplatedParameterType(this, data);
}

void ASTDefaultLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDefaultLiteral(this, data);
}

void ASTAnalyzeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAnalyzeStatement(this, data);
}

void ASTAssertStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssertStatement(this, data);
}

void ASTAssertRowsModified::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssertRowsModified(this, data);
}

void ASTReturningClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReturningClause(this, data);
}

void ASTOnConflictClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTOnConflictClause(this, data);
}

void ASTDeleteStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDeleteStatement(this, data);
}

void ASTNotNullColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTNotNullColumnAttribute(this, data);
}

void ASTHiddenColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHiddenColumnAttribute(this, data);
}

void ASTPrimaryKeyColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKeyColumnAttribute(this, data);
}

void ASTForeignKeyColumnAttribute::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyColumnAttribute(this, data);
}

void ASTColumnAttributeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnAttributeList(this, data);
}

void ASTStructColumnField::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructColumnField(this, data);
}

void ASTGeneratedColumnInfo::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGeneratedColumnInfo(this, data);
}

void ASTColumnDefinition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnDefinition(this, data);
}

void ASTTableElementList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTableElementList(this, data);
}

void ASTColumnList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnList(this, data);
}

void ASTColumnPosition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnPosition(this, data);
}

void ASTInsertValuesRow::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertValuesRow(this, data);
}

void ASTInsertValuesRowList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertValuesRowList(this, data);
}

void ASTInsertStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInsertStatement(this, data);
}

void ASTUpdateSetValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateSetValue(this, data);
}

void ASTUpdateItem::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateItem(this, data);
}

void ASTUpdateItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateItemList(this, data);
}

void ASTUpdateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUpdateStatement(this, data);
}

void ASTTruncateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTruncateStatement(this, data);
}

void ASTMergeAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeAction(this, data);
}

void ASTMergeWhenClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeWhenClause(this, data);
}

void ASTMergeWhenClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeWhenClauseList(this, data);
}

void ASTMergeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMergeStatement(this, data);
}

void ASTPrivilege::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrivilege(this, data);
}

void ASTPrivileges::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrivileges(this, data);
}

void ASTGranteeList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGranteeList(this, data);
}

void ASTGrantStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGrantStatement(this, data);
}

void ASTRevokeStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRevokeStatement(this, data);
}

void ASTRepeatableClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRepeatableClause(this, data);
}

void ASTFilterFieldsArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFilterFieldsArg(this, data);
}

void ASTReplaceFieldsArg::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReplaceFieldsArg(this, data);
}

void ASTReplaceFieldsExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReplaceFieldsExpression(this, data);
}

void ASTSampleSize::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleSize(this, data);
}

void ASTWithWeight::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithWeight(this, data);
}

void ASTSampleSuffix::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleSuffix(this, data);
}

void ASTSampleClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSampleClause(this, data);
}

void ASTSetOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetOptionsAction(this, data);
}

void ASTSetAsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetAsAction(this, data);
}

void ASTAddConstraintAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddConstraintAction(this, data);
}

void ASTDropPrimaryKeyAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropPrimaryKeyAction(this, data);
}

void ASTDropConstraintAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropConstraintAction(this, data);
}

void ASTAlterConstraintEnforcementAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterConstraintEnforcementAction(this, data);
}

void ASTAlterConstraintSetOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterConstraintSetOptionsAction(this, data);
}

void ASTAddColumnIdentifierAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddColumnIdentifierAction(this, data);
}

void ASTAddColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddColumnAction(this, data);
}

void ASTDropColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropColumnAction(this, data);
}

void ASTRenameColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameColumnAction(this, data);
}

void ASTAlterColumnTypeAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnTypeAction(this, data);
}

void ASTAlterColumnOptionsAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnOptionsAction(this, data);
}

void ASTAlterColumnSetDefaultAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnSetDefaultAction(this, data);
}

void ASTAlterColumnDropDefaultAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnDropDefaultAction(this, data);
}

void ASTAlterColumnDropNotNullAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnDropNotNullAction(this, data);
}

void ASTAlterColumnDropGeneratedAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnDropGeneratedAction(this, data);
}

void ASTAlterColumnSetGeneratedAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterColumnSetGeneratedAction(this, data);
}

void ASTGrantToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGrantToClause(this, data);
}

void ASTRestrictToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRestrictToClause(this, data);
}

void ASTAddToRestricteeListClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddToRestricteeListClause(this, data);
}

void ASTRemoveFromRestricteeListClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRemoveFromRestricteeListClause(this, data);
}

void ASTFilterUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTFilterUsingClause(this, data);
}

void ASTRevokeFromClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRevokeFromClause(this, data);
}

void ASTRenameToClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRenameToClause(this, data);
}

void ASTSetCollateClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSetCollateClause(this, data);
}

void ASTAlterSubEntityAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterSubEntityAction(this, data);
}

void ASTAddSubEntityAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddSubEntityAction(this, data);
}

void ASTDropSubEntityAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropSubEntityAction(this, data);
}

void ASTAddTtlAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAddTtlAction(this, data);
}

void ASTReplaceTtlAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReplaceTtlAction(this, data);
}

void ASTDropTtlAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropTtlAction(this, data);
}

void ASTAlterActionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterActionList(this, data);
}

void ASTAlterAllRowAccessPoliciesStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterAllRowAccessPoliciesStatement(this, data);
}

void ASTForeignKeyActions::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyActions(this, data);
}

void ASTForeignKeyReference::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKeyReference(this, data);
}

void ASTScript::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTScript(this, data);
}

void ASTElseifClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTElseifClause(this, data);
}

void ASTElseifClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTElseifClauseList(this, data);
}

void ASTIfStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIfStatement(this, data);
}

void ASTWhenThenClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhenThenClause(this, data);
}

void ASTWhenThenClauseList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhenThenClauseList(this, data);
}

void ASTCaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCaseStatement(this, data);
}

void ASTHint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHint(this, data);
}

void ASTHintEntry::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTHintEntry(this, data);
}

void ASTUnpivotInItemLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUnpivotInItemLabel(this, data);
}

void ASTDescriptor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptor(this, data);
}

void ASTSimpleColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSimpleColumnSchema(this, data);
}

void ASTArrayColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTArrayColumnSchema(this, data);
}

void ASTRangeColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRangeColumnSchema(this, data);
}

void ASTMapColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMapColumnSchema(this, data);
}

void ASTPrimaryKeyElement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKeyElement(this, data);
}

void ASTPrimaryKeyElementList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKeyElementList(this, data);
}

void ASTPrimaryKey::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPrimaryKey(this, data);
}

void ASTForeignKey::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForeignKey(this, data);
}

void ASTCheckConstraint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCheckConstraint(this, data);
}

void ASTDescriptorColumn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptorColumn(this, data);
}

void ASTDescriptorColumnList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDescriptorColumnList(this, data);
}

void ASTCreateEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateEntityStatement(this, data);
}

void ASTRaiseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRaiseStatement(this, data);
}

void ASTExceptionHandler::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExceptionHandler(this, data);
}

void ASTExceptionHandlerList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExceptionHandlerList(this, data);
}

void ASTBeginEndBlock::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBeginEndBlock(this, data);
}

void ASTIdentifierList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentifierList(this, data);
}

void ASTVariableDeclaration::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTVariableDeclaration(this, data);
}

void ASTUntilClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUntilClause(this, data);
}

void ASTBreakStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTBreakStatement(this, data);
}

void ASTContinueStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTContinueStatement(this, data);
}

void ASTDropPrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropPrivilegeRestrictionStatement(this, data);
}

void ASTDropRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropRowAccessPolicyStatement(this, data);
}

void ASTCreatePrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreatePrivilegeRestrictionStatement(this, data);
}

void ASTCreateRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateRowAccessPolicyStatement(this, data);
}

void ASTDropStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDropStatement(this, data);
}

void ASTReturnStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTReturnStatement(this, data);
}

void ASTSingleAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSingleAssignment(this, data);
}

void ASTParameterAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTParameterAssignment(this, data);
}

void ASTSystemVariableAssignment::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSystemVariableAssignment(this, data);
}

void ASTAssignmentFromStruct::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAssignmentFromStruct(this, data);
}

void ASTCreateTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateTableStatement(this, data);
}

void ASTCreateExternalTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateExternalTableStatement(this, data);
}

void ASTCreateViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateViewStatement(this, data);
}

void ASTCreateMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateMaterializedViewStatement(this, data);
}

void ASTCreateApproxViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateApproxViewStatement(this, data);
}

void ASTWhileStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWhileStatement(this, data);
}

void ASTRepeatStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRepeatStatement(this, data);
}

void ASTForInStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTForInStatement(this, data);
}

void ASTAlterConnectionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterConnectionStatement(this, data);
}

void ASTAlterDatabaseStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterDatabaseStatement(this, data);
}

void ASTAlterSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterSchemaStatement(this, data);
}

void ASTAlterExternalSchemaStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterExternalSchemaStatement(this, data);
}

void ASTAlterTableStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterTableStatement(this, data);
}

void ASTAlterViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterViewStatement(this, data);
}

void ASTAlterMaterializedViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterMaterializedViewStatement(this, data);
}

void ASTAlterApproxViewStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterApproxViewStatement(this, data);
}

void ASTAlterModelStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterModelStatement(this, data);
}

void ASTAlterPrivilegeRestrictionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterPrivilegeRestrictionStatement(this, data);
}

void ASTAlterRowAccessPolicyStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterRowAccessPolicyStatement(this, data);
}

void ASTAlterEntityStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterEntityStatement(this, data);
}

void ASTRebuildAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRebuildAction(this, data);
}

void ASTAlterIndexStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterIndexStatement(this, data);
}

void ASTCreateFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateFunctionStatement(this, data);
}

void ASTCreateTableFunctionStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateTableFunctionStatement(this, data);
}

void ASTStructColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTStructColumnSchema(this, data);
}

void ASTInferredTypeColumnSchema::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInferredTypeColumnSchema(this, data);
}

void ASTExecuteIntoClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteIntoClause(this, data);
}

void ASTExecuteUsingArgument::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteUsingArgument(this, data);
}

void ASTExecuteUsingClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteUsingClause(this, data);
}

void ASTExecuteImmediateStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTExecuteImmediateStatement(this, data);
}

void ASTAuxLoadDataFromFilesOptionsList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAuxLoadDataFromFilesOptionsList(this, data);
}

void ASTAuxLoadDataPartitionsClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAuxLoadDataPartitionsClause(this, data);
}

void ASTAuxLoadDataStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAuxLoadDataStatement(this, data);
}

void ASTLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLabel(this, data);
}

void ASTWithExpression::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithExpression(this, data);
}

void ASTTtlClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTTtlClause(this, data);
}

void ASTLocation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLocation(this, data);
}

void ASTInputOutputClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTInputOutputClause(this, data);
}

void ASTSpannerTableOptions::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSpannerTableOptions(this, data);
}

void ASTSpannerInterleaveClause::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSpannerInterleaveClause(this, data);
}

void ASTSpannerAlterColumnAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSpannerAlterColumnAction(this, data);
}

void ASTSpannerSetOnDeleteAction::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTSpannerSetOnDeleteAction(this, data);
}

void ASTRangeLiteral::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRangeLiteral(this, data);
}

void ASTRangeType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRangeType(this, data);
}

void ASTCreatePropertyGraphStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreatePropertyGraphStatement(this, data);
}

void ASTGraphElementTableList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementTableList(this, data);
}

void ASTGraphElementTable::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementTable(this, data);
}

void ASTGraphNodeTableReference::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphNodeTableReference(this, data);
}

void ASTGraphElementLabelAndPropertiesList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementLabelAndPropertiesList(this, data);
}

void ASTGraphElementLabelAndProperties::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementLabelAndProperties(this, data);
}

void ASTGraphDerivedProperty::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphDerivedProperty(this, data);
}

void ASTGraphDerivedPropertyList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphDerivedPropertyList(this, data);
}

void ASTGraphProperties::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphProperties(this, data);
}

void ASTGraphDynamicLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphDynamicLabel(this, data);
}

void ASTGraphDynamicProperties::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphDynamicProperties(this, data);
}

void ASTGraphPattern::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPattern(this, data);
}

void ASTGqlQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlQuery(this, data);
}

void ASTGqlGraphPatternQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlGraphPatternQuery(this, data);
}

void ASTGqlLinearOpsQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlLinearOpsQuery(this, data);
}

void ASTGraphTableQuery::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphTableQuery(this, data);
}

void ASTGraphElementLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementLabel(this, data);
}

void ASTGraphWildcardLabel::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphWildcardLabel(this, data);
}

void ASTGraphLabelOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphLabelOperation(this, data);
}

void ASTGraphLabelFilter::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphLabelFilter(this, data);
}

void ASTGraphIsLabeledPredicate::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphIsLabeledPredicate(this, data);
}

void ASTGraphElementPatternFiller::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphElementPatternFiller(this, data);
}

void ASTGraphPropertySpecification::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPropertySpecification(this, data);
}

void ASTGraphPropertyNameAndValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPropertyNameAndValue(this, data);
}

void ASTGraphNodePattern::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphNodePattern(this, data);
}

void ASTGraphLhsHint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphLhsHint(this, data);
}

void ASTGraphRhsHint::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphRhsHint(this, data);
}

void ASTGraphPathSearchPrefix::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPathSearchPrefix(this, data);
}

void ASTGraphPathSearchPrefixCount::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPathSearchPrefixCount(this, data);
}

void ASTGraphEdgePattern::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphEdgePattern(this, data);
}

void ASTGraphPathMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPathMode(this, data);
}

void ASTGraphPathPattern::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGraphPathPattern(this, data);
}

void ASTGqlMatch::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlMatch(this, data);
}

void ASTGqlReturn::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlReturn(this, data);
}

void ASTGqlWith::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlWith(this, data);
}

void ASTGqlFor::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlFor(this, data);
}

void ASTGqlNamedCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlNamedCall(this, data);
}

void ASTYieldItemList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTYieldItemList(this, data);
}

void ASTGqlInlineSubqueryCall::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlInlineSubqueryCall(this, data);
}

void ASTGqlLet::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlLet(this, data);
}

void ASTGqlLetVariableDefinitionList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlLetVariableDefinitionList(this, data);
}

void ASTGqlLetVariableDefinition::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlLetVariableDefinition(this, data);
}

void ASTGqlFilter::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlFilter(this, data);
}

void ASTGqlOperatorList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlOperatorList(this, data);
}

void ASTGqlSetOperation::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlSetOperation(this, data);
}

void ASTGqlPageLimit::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlPageLimit(this, data);
}

void ASTGqlPageOffset::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlPageOffset(this, data);
}

void ASTGqlPage::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlPage(this, data);
}

void ASTGqlOrderByAndPage::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlOrderByAndPage(this, data);
}

void ASTGqlSample::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTGqlSample(this, data);
}

void ASTWithModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTWithModifier(this, data);
}

void ASTColumnWithOptions::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnWithOptions(this, data);
}

void ASTColumnWithOptionsList::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTColumnWithOptionsList(this, data);
}

void ASTMacroBody::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMacroBody(this, data);
}

void ASTDefineMacroStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTDefineMacroStatement(this, data);
}

void ASTUndropStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTUndropStatement(this, data);
}

void ASTIdentityColumnInfo::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentityColumnInfo(this, data);
}

void ASTIdentityColumnStartWith::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentityColumnStartWith(this, data);
}

void ASTIdentityColumnIncrementBy::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentityColumnIncrementBy(this, data);
}

void ASTIdentityColumnMaxValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentityColumnMaxValue(this, data);
}

void ASTIdentityColumnMinValue::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIdentityColumnMinValue(this, data);
}

void ASTAliasedQueryModifiers::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAliasedQueryModifiers(this, data);
}

void ASTIntOrUnbounded::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTIntOrUnbounded(this, data);
}

void ASTRecursionDepthModifier::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRecursionDepthModifier(this, data);
}

void ASTMapType::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTMapType(this, data);
}

void ASTLockMode::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTLockMode(this, data);
}

void ASTPipeRecursiveUnion::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTPipeRecursiveUnion(this, data);
}

void ASTRunStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTRunStatement(this, data);
}

void ASTCreateSequenceStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTCreateSequenceStatement(this, data);
}

void ASTAlterSequenceStatement::Accept(ParseTreeVisitor* visitor, void* data) const {
  visitor->visitASTAlterSequenceStatement(this, data);
}

        absl::Status ASTQueryStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTQueryStatement(this, output);
        }

                absl::Status ASTSubpipelineStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSubpipelineStatement(this, output);
        }

                absl::Status ASTAliasedQueryExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAliasedQueryExpression(this, output);
        }

                absl::Status ASTQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTQuery(this, output);
        }

                absl::Status ASTFromQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFromQuery(this, output);
        }

                absl::Status ASTSubpipeline::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSubpipeline(this, output);
        }

                absl::Status ASTPipeExtend::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeExtend(this, output);
        }

                absl::Status ASTPipeRenameItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeRenameItem(this, output);
        }

                absl::Status ASTPipeRename::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeRename(this, output);
        }

                absl::Status ASTPipeAggregate::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeAggregate(this, output);
        }

                absl::Status ASTPipeSetOperation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeSetOperation(this, output);
        }

                absl::Status ASTPipeJoin::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeJoin(this, output);
        }

                absl::Status ASTPipeCall::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeCall(this, output);
        }

                absl::Status ASTPipeWindow::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeWindow(this, output);
        }

                absl::Status ASTPipeWhere::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeWhere(this, output);
        }

                absl::Status ASTPipeSelect::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeSelect(this, output);
        }

                absl::Status ASTPipeLimitOffset::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeLimitOffset(this, output);
        }

                absl::Status ASTPipeOrderBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeOrderBy(this, output);
        }

                absl::Status ASTPipeDistinct::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeDistinct(this, output);
        }

                absl::Status ASTPipeTablesample::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeTablesample(this, output);
        }

                absl::Status ASTPipeMatchRecognize::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeMatchRecognize(this, output);
        }

                absl::Status ASTPipeAs::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeAs(this, output);
        }

                absl::Status ASTPipeDescribe::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeDescribe(this, output);
        }

                absl::Status ASTPipeStaticDescribe::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeStaticDescribe(this, output);
        }

                absl::Status ASTPipeAssert::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeAssert(this, output);
        }

                absl::Status ASTPipeLog::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeLog(this, output);
        }

                absl::Status ASTPipeDrop::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeDrop(this, output);
        }

                absl::Status ASTPipeSetItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeSetItem(this, output);
        }

                absl::Status ASTPipeSet::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeSet(this, output);
        }

                absl::Status ASTPipePivot::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipePivot(this, output);
        }

                absl::Status ASTPipeUnpivot::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeUnpivot(this, output);
        }

                absl::Status ASTPipeIf::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeIf(this, output);
        }

                absl::Status ASTPipeIfCase::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeIfCase(this, output);
        }

                absl::Status ASTPipeFork::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeFork(this, output);
        }

                absl::Status ASTPipeTee::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeTee(this, output);
        }

                absl::Status ASTPipeWith::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeWith(this, output);
        }

                absl::Status ASTPipeExportData::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeExportData(this, output);
        }

                absl::Status ASTPipeCreateTable::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeCreateTable(this, output);
        }

                absl::Status ASTPipeInsert::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeInsert(this, output);
        }

                absl::Status ASTSelect::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSelect(this, output);
        }

                absl::Status ASTSelectList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSelectList(this, output);
        }

                absl::Status ASTSelectColumn::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSelectColumn(this, output);
        }

                absl::Status ASTIntLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIntLiteral(this, output);
        }

                absl::Status ASTIdentifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentifier(this, output);
        }

                absl::Status ASTAlias::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlias(this, output);
        }

                absl::Status ASTPathExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPathExpression(this, output);
        }

                absl::Status ASTTablePathExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTablePathExpression(this, output);
        }

                absl::Status ASTPipeJoinLhsPlaceholder::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeJoinLhsPlaceholder(this, output);
        }

                absl::Status ASTFromClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFromClause(this, output);
        }

                absl::Status ASTWhereClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWhereClause(this, output);
        }

                absl::Status ASTBooleanLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBooleanLiteral(this, output);
        }

                absl::Status ASTAndExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAndExpr(this, output);
        }

                absl::Status ASTBinaryExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBinaryExpression(this, output);
        }

                absl::Status ASTStringLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStringLiteral(this, output);
        }

                absl::Status ASTStringLiteralComponent::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStringLiteralComponent(this, output);
        }

                absl::Status ASTStar::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStar(this, output);
        }

                absl::Status ASTOrExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOrExpr(this, output);
        }

                absl::Status ASTConcatExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTConcatExpr(this, output);
        }

                absl::Status ASTOrderingExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOrderingExpression(this, output);
        }

                absl::Status ASTOrderBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOrderBy(this, output);
        }

                absl::Status ASTGroupingItemOrder::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupingItemOrder(this, output);
        }

                absl::Status ASTGroupingItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupingItem(this, output);
        }

                absl::Status ASTGroupBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupBy(this, output);
        }

                absl::Status ASTGroupByAll::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupByAll(this, output);
        }

                absl::Status ASTLimitAll::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLimitAll(this, output);
        }

                absl::Status ASTLimit::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLimit(this, output);
        }

                absl::Status ASTLimitOffset::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLimitOffset(this, output);
        }

                absl::Status ASTFloatLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFloatLiteral(this, output);
        }

                absl::Status ASTNullLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNullLiteral(this, output);
        }

                absl::Status ASTOnClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOnClause(this, output);
        }

                absl::Status ASTAliasedQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAliasedQuery(this, output);
        }

                absl::Status ASTJoin::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTJoin(this, output);
        }

                absl::Status ASTAliasedGroupRows::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAliasedGroupRows(this, output);
        }

                absl::Status ASTWithClauseEntry::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithClauseEntry(this, output);
        }

                absl::Status ASTWithClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithClause(this, output);
        }

                absl::Status ASTHaving::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHaving(this, output);
        }

                absl::Status ASTSimpleType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSimpleType(this, output);
        }

                absl::Status ASTArrayType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTArrayType(this, output);
        }

                absl::Status ASTStructField::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructField(this, output);
        }

                absl::Status ASTStructType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructType(this, output);
        }

                absl::Status ASTFunctionTypeArgList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionTypeArgList(this, output);
        }

                absl::Status ASTFunctionType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionType(this, output);
        }

                absl::Status ASTCastExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCastExpression(this, output);
        }

                absl::Status ASTSelectAs::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSelectAs(this, output);
        }

                absl::Status ASTRollup::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRollup(this, output);
        }

                absl::Status ASTCube::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCube(this, output);
        }

                absl::Status ASTGroupingSet::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupingSet(this, output);
        }

                absl::Status ASTGroupingSetList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGroupingSetList(this, output);
        }

                absl::Status ASTExpressionWithAlias::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExpressionWithAlias(this, output);
        }

                absl::Status ASTFunctionCall::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionCall(this, output);
        }

                absl::Status ASTChainedBaseExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTChainedBaseExpr(this, output);
        }

                absl::Status ASTArrayConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTArrayConstructor(this, output);
        }

                absl::Status ASTStructConstructorArg::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructConstructorArg(this, output);
        }

                absl::Status ASTStructConstructorWithParens::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructConstructorWithParens(this, output);
        }

                absl::Status ASTStructConstructorWithKeyword::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructConstructorWithKeyword(this, output);
        }

                absl::Status ASTInExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInExpression(this, output);
        }

                absl::Status ASTInList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInList(this, output);
        }

                absl::Status ASTBetweenExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBetweenExpression(this, output);
        }

                absl::Status ASTNumericLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNumericLiteral(this, output);
        }

                absl::Status ASTBigNumericLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBigNumericLiteral(this, output);
        }

                absl::Status ASTBytesLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBytesLiteral(this, output);
        }

                absl::Status ASTBytesLiteralComponent::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBytesLiteralComponent(this, output);
        }

                absl::Status ASTDateOrTimeLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDateOrTimeLiteral(this, output);
        }

                absl::Status ASTMaxLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMaxLiteral(this, output);
        }

                absl::Status ASTJSONLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTJSONLiteral(this, output);
        }

                absl::Status ASTCaseValueExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCaseValueExpression(this, output);
        }

                absl::Status ASTCaseNoValueExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCaseNoValueExpression(this, output);
        }

                absl::Status ASTArrayElement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTArrayElement(this, output);
        }

                absl::Status ASTBitwiseShiftExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBitwiseShiftExpression(this, output);
        }

                absl::Status ASTCollate::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCollate(this, output);
        }

                absl::Status ASTDotGeneralizedField::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDotGeneralizedField(this, output);
        }

                absl::Status ASTDotIdentifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDotIdentifier(this, output);
        }

                absl::Status ASTDotStar::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDotStar(this, output);
        }

                absl::Status ASTDotStarWithModifiers::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDotStarWithModifiers(this, output);
        }

                absl::Status ASTExpressionSubquery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExpressionSubquery(this, output);
        }

                absl::Status ASTExtractExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExtractExpression(this, output);
        }

                absl::Status ASTHavingModifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHavingModifier(this, output);
        }

                absl::Status ASTIntervalExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIntervalExpr(this, output);
        }

                absl::Status ASTSequenceArg::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSequenceArg(this, output);
        }

                absl::Status ASTNamedArgument::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNamedArgument(this, output);
        }

                absl::Status ASTInputTableArgument::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInputTableArgument(this, output);
        }

                absl::Status ASTNullOrder::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNullOrder(this, output);
        }

                absl::Status ASTOnOrUsingClauseList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOnOrUsingClauseList(this, output);
        }

                absl::Status ASTParenthesizedJoin::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTParenthesizedJoin(this, output);
        }

                absl::Status ASTPartitionBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPartitionBy(this, output);
        }

                absl::Status ASTSetOperation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperation(this, output);
        }

                absl::Status ASTSetOperationMetadataList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationMetadataList(this, output);
        }

                absl::Status ASTSetOperationAllOrDistinct::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationAllOrDistinct(this, output);
        }

                absl::Status ASTSetOperationType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationType(this, output);
        }

                absl::Status ASTSetOperationColumnMatchMode::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationColumnMatchMode(this, output);
        }

                absl::Status ASTSetOperationColumnPropagationMode::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationColumnPropagationMode(this, output);
        }

                absl::Status ASTSetOperationMetadata::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOperationMetadata(this, output);
        }

                absl::Status ASTStarExceptList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStarExceptList(this, output);
        }

                absl::Status ASTStarModifiers::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStarModifiers(this, output);
        }

                absl::Status ASTStarReplaceItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStarReplaceItem(this, output);
        }

                absl::Status ASTStarWithModifiers::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStarWithModifiers(this, output);
        }

                absl::Status ASTTableSubquery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTableSubquery(this, output);
        }

                absl::Status ASTUnaryExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnaryExpression(this, output);
        }

                absl::Status ASTExpressionWithOptAlias::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExpressionWithOptAlias(this, output);
        }

                absl::Status ASTUnnestExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnnestExpression(this, output);
        }

                absl::Status ASTWindowClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWindowClause(this, output);
        }

                absl::Status ASTWindowDefinition::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWindowDefinition(this, output);
        }

                absl::Status ASTWindowFrame::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWindowFrame(this, output);
        }

                absl::Status ASTWindowFrameExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWindowFrameExpr(this, output);
        }

                absl::Status ASTLikeExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLikeExpression(this, output);
        }

                absl::Status ASTQuantifiedComparisonExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTQuantifiedComparisonExpression(this, output);
        }

                absl::Status ASTWindowSpecification::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWindowSpecification(this, output);
        }

                absl::Status ASTWithOffset::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithOffset(this, output);
        }

                absl::Status ASTAnySomeAllOp::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAnySomeAllOp(this, output);
        }

                absl::Status ASTStatementList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStatementList(this, output);
        }

                absl::Status ASTHintedStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHintedStatement(this, output);
        }

                absl::Status ASTStatementWithPipeOperators::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStatementWithPipeOperators(this, output);
        }

                absl::Status ASTExplainStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExplainStatement(this, output);
        }

                absl::Status ASTDescribeStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDescribeStatement(this, output);
        }

                absl::Status ASTShowStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTShowStatement(this, output);
        }

                absl::Status ASTTransactionIsolationLevel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTransactionIsolationLevel(this, output);
        }

                absl::Status ASTTransactionReadWriteMode::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTransactionReadWriteMode(this, output);
        }

                absl::Status ASTTransactionModeList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTransactionModeList(this, output);
        }

                absl::Status ASTBeginStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBeginStatement(this, output);
        }

                absl::Status ASTSetTransactionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetTransactionStatement(this, output);
        }

                absl::Status ASTCommitStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCommitStatement(this, output);
        }

                absl::Status ASTRollbackStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRollbackStatement(this, output);
        }

                absl::Status ASTStartBatchStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStartBatchStatement(this, output);
        }

                absl::Status ASTRunBatchStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRunBatchStatement(this, output);
        }

                absl::Status ASTAbortBatchStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAbortBatchStatement(this, output);
        }

                absl::Status ASTDropEntityStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropEntityStatement(this, output);
        }

                absl::Status ASTDropFunctionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropFunctionStatement(this, output);
        }

                absl::Status ASTDropTableFunctionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropTableFunctionStatement(this, output);
        }

                absl::Status ASTDropAllRowAccessPoliciesStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropAllRowAccessPoliciesStatement(this, output);
        }

                absl::Status ASTDropMaterializedViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropMaterializedViewStatement(this, output);
        }

                absl::Status ASTDropSnapshotTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropSnapshotTableStatement(this, output);
        }

                absl::Status ASTDropSearchIndexStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropSearchIndexStatement(this, output);
        }

                absl::Status ASTDropVectorIndexStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropVectorIndexStatement(this, output);
        }

                absl::Status ASTRenameStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRenameStatement(this, output);
        }

                absl::Status ASTImportStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTImportStatement(this, output);
        }

                absl::Status ASTModuleStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTModuleStatement(this, output);
        }

                absl::Status ASTWithConnectionClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithConnectionClause(this, output);
        }

                absl::Status ASTIntoAlias::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIntoAlias(this, output);
        }

                absl::Status ASTUnnestExpressionWithOptAliasAndOffset::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnnestExpressionWithOptAliasAndOffset(this, output);
        }

                absl::Status ASTPivotExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPivotExpression(this, output);
        }

                absl::Status ASTPivotValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPivotValue(this, output);
        }

                absl::Status ASTPivotExpressionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPivotExpressionList(this, output);
        }

                absl::Status ASTPivotValueList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPivotValueList(this, output);
        }

                absl::Status ASTPivotClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPivotClause(this, output);
        }

                absl::Status ASTUnpivotInItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnpivotInItem(this, output);
        }

                absl::Status ASTUnpivotInItemList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnpivotInItemList(this, output);
        }

                absl::Status ASTUnpivotClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnpivotClause(this, output);
        }

                absl::Status ASTUsingClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUsingClause(this, output);
        }

                absl::Status ASTForSystemTime::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForSystemTime(this, output);
        }

                absl::Status ASTMatchRecognizeClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMatchRecognizeClause(this, output);
        }

                absl::Status ASTAfterMatchSkipClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAfterMatchSkipClause(this, output);
        }

                absl::Status ASTRowPatternVariable::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRowPatternVariable(this, output);
        }

                absl::Status ASTRowPatternOperation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRowPatternOperation(this, output);
        }

                absl::Status ASTEmptyRowPattern::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTEmptyRowPattern(this, output);
        }

                absl::Status ASTRowPatternAnchor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRowPatternAnchor(this, output);
        }

                absl::Status ASTBoundedQuantifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBoundedQuantifier(this, output);
        }

                absl::Status ASTQuantifierBound::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTQuantifierBound(this, output);
        }

                absl::Status ASTFixedQuantifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFixedQuantifier(this, output);
        }

                absl::Status ASTSymbolQuantifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSymbolQuantifier(this, output);
        }

                absl::Status ASTRowPatternQuantification::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRowPatternQuantification(this, output);
        }

                absl::Status ASTQualify::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTQualify(this, output);
        }

                absl::Status ASTClampedBetweenModifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTClampedBetweenModifier(this, output);
        }

                absl::Status ASTWithReportModifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithReportModifier(this, output);
        }

                absl::Status ASTFormatClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFormatClause(this, output);
        }

                absl::Status ASTPathExpressionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPathExpressionList(this, output);
        }

                absl::Status ASTParameterExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTParameterExpr(this, output);
        }

                absl::Status ASTSystemVariableExpr::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSystemVariableExpr(this, output);
        }

                absl::Status ASTLambda::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLambda(this, output);
        }

                absl::Status ASTAnalyticFunctionCall::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAnalyticFunctionCall(this, output);
        }

                absl::Status ASTClusterBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTClusterBy(this, output);
        }

                absl::Status ASTNewConstructorArg::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNewConstructorArg(this, output);
        }

                absl::Status ASTNewConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNewConstructor(this, output);
        }

                absl::Status ASTBracedConstructorLhs::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBracedConstructorLhs(this, output);
        }

                absl::Status ASTBracedConstructorFieldValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBracedConstructorFieldValue(this, output);
        }

                absl::Status ASTBracedConstructorField::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBracedConstructorField(this, output);
        }

                absl::Status ASTBracedConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBracedConstructor(this, output);
        }

                absl::Status ASTBracedNewConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBracedNewConstructor(this, output);
        }

                absl::Status ASTExtendedPathExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExtendedPathExpression(this, output);
        }

                absl::Status ASTUpdateConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUpdateConstructor(this, output);
        }

                absl::Status ASTStructBracedConstructor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructBracedConstructor(this, output);
        }

                absl::Status ASTOptionsList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOptionsList(this, output);
        }

                absl::Status ASTOptionsEntry::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOptionsEntry(this, output);
        }

                absl::Status ASTFunctionParameter::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionParameter(this, output);
        }

                absl::Status ASTFunctionParameters::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionParameters(this, output);
        }

                absl::Status ASTFunctionDeclaration::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFunctionDeclaration(this, output);
        }

                absl::Status ASTSqlFunctionBody::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSqlFunctionBody(this, output);
        }

                absl::Status ASTTVFArgument::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTVFArgument(this, output);
        }

                absl::Status ASTTVF::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTVF(this, output);
        }

                absl::Status ASTTableClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTableClause(this, output);
        }

                absl::Status ASTModelClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTModelClause(this, output);
        }

                absl::Status ASTConnectionClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTConnectionClause(this, output);
        }

                absl::Status ASTCloneDataSource::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCloneDataSource(this, output);
        }

                absl::Status ASTCopyDataSource::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCopyDataSource(this, output);
        }

                absl::Status ASTCloneDataSourceList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCloneDataSourceList(this, output);
        }

                absl::Status ASTCloneDataStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCloneDataStatement(this, output);
        }

                absl::Status ASTCreateConnectionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateConnectionStatement(this, output);
        }

                absl::Status ASTCreateConstantStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateConstantStatement(this, output);
        }

                absl::Status ASTCreateDatabaseStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateDatabaseStatement(this, output);
        }

                absl::Status ASTCreateProcedureStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateProcedureStatement(this, output);
        }

                absl::Status ASTCreateSchemaStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateSchemaStatement(this, output);
        }

                absl::Status ASTCreateExternalSchemaStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateExternalSchemaStatement(this, output);
        }

                absl::Status ASTAliasedQueryList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAliasedQueryList(this, output);
        }

                absl::Status ASTTransformClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTransformClause(this, output);
        }

                absl::Status ASTCreateModelStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateModelStatement(this, output);
        }

                absl::Status ASTIndexAllColumns::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIndexAllColumns(this, output);
        }

                absl::Status ASTIndexItemList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIndexItemList(this, output);
        }

                absl::Status ASTIndexStoringExpressionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIndexStoringExpressionList(this, output);
        }

                absl::Status ASTIndexUnnestExpressionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIndexUnnestExpressionList(this, output);
        }

                absl::Status ASTCreateIndexStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateIndexStatement(this, output);
        }

                absl::Status ASTExportDataStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExportDataStatement(this, output);
        }

                absl::Status ASTExportModelStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExportModelStatement(this, output);
        }

                absl::Status ASTExportMetadataStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExportMetadataStatement(this, output);
        }

                absl::Status ASTCallStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCallStatement(this, output);
        }

                absl::Status ASTDefineTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDefineTableStatement(this, output);
        }

                absl::Status ASTCreateLocalityGroupStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateLocalityGroupStatement(this, output);
        }

                absl::Status ASTWithPartitionColumnsClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithPartitionColumnsClause(this, output);
        }

                absl::Status ASTCreateSnapshotStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateSnapshotStatement(this, output);
        }

                absl::Status ASTCreateSnapshotTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateSnapshotTableStatement(this, output);
        }

                absl::Status ASTTypeParameterList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTypeParameterList(this, output);
        }

                absl::Status ASTTVFSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTVFSchema(this, output);
        }

                absl::Status ASTTVFSchemaColumn::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTVFSchemaColumn(this, output);
        }

                absl::Status ASTTableAndColumnInfo::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTableAndColumnInfo(this, output);
        }

                absl::Status ASTTableAndColumnInfoList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTableAndColumnInfoList(this, output);
        }

                absl::Status ASTTemplatedParameterType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTemplatedParameterType(this, output);
        }

                absl::Status ASTDefaultLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDefaultLiteral(this, output);
        }

                absl::Status ASTAnalyzeStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAnalyzeStatement(this, output);
        }

                absl::Status ASTAssertStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAssertStatement(this, output);
        }

                absl::Status ASTAssertRowsModified::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAssertRowsModified(this, output);
        }

                absl::Status ASTReturningClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTReturningClause(this, output);
        }

                absl::Status ASTOnConflictClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTOnConflictClause(this, output);
        }

                absl::Status ASTDeleteStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDeleteStatement(this, output);
        }

                absl::Status ASTNotNullColumnAttribute::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTNotNullColumnAttribute(this, output);
        }

                absl::Status ASTHiddenColumnAttribute::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHiddenColumnAttribute(this, output);
        }

                absl::Status ASTPrimaryKeyColumnAttribute::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrimaryKeyColumnAttribute(this, output);
        }

                absl::Status ASTForeignKeyColumnAttribute::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForeignKeyColumnAttribute(this, output);
        }

                absl::Status ASTColumnAttributeList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnAttributeList(this, output);
        }

                absl::Status ASTStructColumnField::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructColumnField(this, output);
        }

                absl::Status ASTGeneratedColumnInfo::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGeneratedColumnInfo(this, output);
        }

                absl::Status ASTColumnDefinition::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnDefinition(this, output);
        }

                absl::Status ASTTableElementList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTableElementList(this, output);
        }

                absl::Status ASTColumnList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnList(this, output);
        }

                absl::Status ASTColumnPosition::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnPosition(this, output);
        }

                absl::Status ASTInsertValuesRow::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInsertValuesRow(this, output);
        }

                absl::Status ASTInsertValuesRowList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInsertValuesRowList(this, output);
        }

                absl::Status ASTInsertStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInsertStatement(this, output);
        }

                absl::Status ASTUpdateSetValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUpdateSetValue(this, output);
        }

                absl::Status ASTUpdateItem::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUpdateItem(this, output);
        }

                absl::Status ASTUpdateItemList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUpdateItemList(this, output);
        }

                absl::Status ASTUpdateStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUpdateStatement(this, output);
        }

                absl::Status ASTTruncateStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTruncateStatement(this, output);
        }

                absl::Status ASTMergeAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMergeAction(this, output);
        }

                absl::Status ASTMergeWhenClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMergeWhenClause(this, output);
        }

                absl::Status ASTMergeWhenClauseList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMergeWhenClauseList(this, output);
        }

                absl::Status ASTMergeStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMergeStatement(this, output);
        }

                absl::Status ASTPrivilege::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrivilege(this, output);
        }

                absl::Status ASTPrivileges::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrivileges(this, output);
        }

                absl::Status ASTGranteeList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGranteeList(this, output);
        }

                absl::Status ASTGrantStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGrantStatement(this, output);
        }

                absl::Status ASTRevokeStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRevokeStatement(this, output);
        }

                absl::Status ASTRepeatableClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRepeatableClause(this, output);
        }

                absl::Status ASTFilterFieldsArg::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFilterFieldsArg(this, output);
        }

                absl::Status ASTReplaceFieldsArg::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTReplaceFieldsArg(this, output);
        }

                absl::Status ASTReplaceFieldsExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTReplaceFieldsExpression(this, output);
        }

                absl::Status ASTSampleSize::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSampleSize(this, output);
        }

                absl::Status ASTWithWeight::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithWeight(this, output);
        }

                absl::Status ASTSampleSuffix::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSampleSuffix(this, output);
        }

                absl::Status ASTSampleClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSampleClause(this, output);
        }

                absl::Status ASTSetOptionsAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetOptionsAction(this, output);
        }

                absl::Status ASTSetAsAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetAsAction(this, output);
        }

                absl::Status ASTAddConstraintAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddConstraintAction(this, output);
        }

                absl::Status ASTDropPrimaryKeyAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropPrimaryKeyAction(this, output);
        }

                absl::Status ASTDropConstraintAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropConstraintAction(this, output);
        }

                absl::Status ASTAlterConstraintEnforcementAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterConstraintEnforcementAction(this, output);
        }

                absl::Status ASTAlterConstraintSetOptionsAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterConstraintSetOptionsAction(this, output);
        }

                absl::Status ASTAddColumnIdentifierAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddColumnIdentifierAction(this, output);
        }

                absl::Status ASTAddColumnAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddColumnAction(this, output);
        }

                absl::Status ASTDropColumnAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropColumnAction(this, output);
        }

                absl::Status ASTRenameColumnAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRenameColumnAction(this, output);
        }

                absl::Status ASTAlterColumnTypeAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnTypeAction(this, output);
        }

                absl::Status ASTAlterColumnOptionsAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnOptionsAction(this, output);
        }

                absl::Status ASTAlterColumnSetDefaultAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnSetDefaultAction(this, output);
        }

                absl::Status ASTAlterColumnDropDefaultAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnDropDefaultAction(this, output);
        }

                absl::Status ASTAlterColumnDropNotNullAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnDropNotNullAction(this, output);
        }

                absl::Status ASTAlterColumnDropGeneratedAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnDropGeneratedAction(this, output);
        }

                absl::Status ASTAlterColumnSetGeneratedAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterColumnSetGeneratedAction(this, output);
        }

                absl::Status ASTGrantToClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGrantToClause(this, output);
        }

                absl::Status ASTRestrictToClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRestrictToClause(this, output);
        }

                absl::Status ASTAddToRestricteeListClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddToRestricteeListClause(this, output);
        }

                absl::Status ASTRemoveFromRestricteeListClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRemoveFromRestricteeListClause(this, output);
        }

                absl::Status ASTFilterUsingClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTFilterUsingClause(this, output);
        }

                absl::Status ASTRevokeFromClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRevokeFromClause(this, output);
        }

                absl::Status ASTRenameToClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRenameToClause(this, output);
        }

                absl::Status ASTSetCollateClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSetCollateClause(this, output);
        }

                absl::Status ASTAlterSubEntityAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterSubEntityAction(this, output);
        }

                absl::Status ASTAddSubEntityAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddSubEntityAction(this, output);
        }

                absl::Status ASTDropSubEntityAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropSubEntityAction(this, output);
        }

                absl::Status ASTAddTtlAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAddTtlAction(this, output);
        }

                absl::Status ASTReplaceTtlAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTReplaceTtlAction(this, output);
        }

                absl::Status ASTDropTtlAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropTtlAction(this, output);
        }

                absl::Status ASTAlterActionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterActionList(this, output);
        }

                absl::Status ASTAlterAllRowAccessPoliciesStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterAllRowAccessPoliciesStatement(this, output);
        }

                absl::Status ASTForeignKeyActions::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForeignKeyActions(this, output);
        }

                absl::Status ASTForeignKeyReference::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForeignKeyReference(this, output);
        }

                absl::Status ASTScript::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTScript(this, output);
        }

                absl::Status ASTElseifClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTElseifClause(this, output);
        }

                absl::Status ASTElseifClauseList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTElseifClauseList(this, output);
        }

                absl::Status ASTIfStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIfStatement(this, output);
        }

                absl::Status ASTWhenThenClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWhenThenClause(this, output);
        }

                absl::Status ASTWhenThenClauseList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWhenThenClauseList(this, output);
        }

                absl::Status ASTCaseStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCaseStatement(this, output);
        }

                absl::Status ASTHint::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHint(this, output);
        }

                absl::Status ASTHintEntry::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTHintEntry(this, output);
        }

                absl::Status ASTUnpivotInItemLabel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUnpivotInItemLabel(this, output);
        }

                absl::Status ASTDescriptor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDescriptor(this, output);
        }

                absl::Status ASTSimpleColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSimpleColumnSchema(this, output);
        }

                absl::Status ASTArrayColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTArrayColumnSchema(this, output);
        }

                absl::Status ASTRangeColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRangeColumnSchema(this, output);
        }

                absl::Status ASTMapColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMapColumnSchema(this, output);
        }

                absl::Status ASTPrimaryKeyElement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrimaryKeyElement(this, output);
        }

                absl::Status ASTPrimaryKeyElementList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrimaryKeyElementList(this, output);
        }

                absl::Status ASTPrimaryKey::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPrimaryKey(this, output);
        }

                absl::Status ASTForeignKey::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForeignKey(this, output);
        }

                absl::Status ASTCheckConstraint::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCheckConstraint(this, output);
        }

                absl::Status ASTDescriptorColumn::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDescriptorColumn(this, output);
        }

                absl::Status ASTDescriptorColumnList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDescriptorColumnList(this, output);
        }

                absl::Status ASTCreateEntityStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateEntityStatement(this, output);
        }

                absl::Status ASTRaiseStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRaiseStatement(this, output);
        }

                absl::Status ASTExceptionHandler::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExceptionHandler(this, output);
        }

                absl::Status ASTExceptionHandlerList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExceptionHandlerList(this, output);
        }

                absl::Status ASTBeginEndBlock::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBeginEndBlock(this, output);
        }

                absl::Status ASTIdentifierList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentifierList(this, output);
        }

                absl::Status ASTVariableDeclaration::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTVariableDeclaration(this, output);
        }

                absl::Status ASTUntilClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUntilClause(this, output);
        }

                absl::Status ASTBreakStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTBreakStatement(this, output);
        }

                absl::Status ASTContinueStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTContinueStatement(this, output);
        }

                absl::Status ASTDropPrivilegeRestrictionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropPrivilegeRestrictionStatement(this, output);
        }

                absl::Status ASTDropRowAccessPolicyStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropRowAccessPolicyStatement(this, output);
        }

                absl::Status ASTCreatePrivilegeRestrictionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreatePrivilegeRestrictionStatement(this, output);
        }

                absl::Status ASTCreateRowAccessPolicyStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateRowAccessPolicyStatement(this, output);
        }

                absl::Status ASTDropStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDropStatement(this, output);
        }

                absl::Status ASTReturnStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTReturnStatement(this, output);
        }

                absl::Status ASTSingleAssignment::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSingleAssignment(this, output);
        }

                absl::Status ASTParameterAssignment::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTParameterAssignment(this, output);
        }

                absl::Status ASTSystemVariableAssignment::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSystemVariableAssignment(this, output);
        }

                absl::Status ASTAssignmentFromStruct::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAssignmentFromStruct(this, output);
        }

                absl::Status ASTCreateTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateTableStatement(this, output);
        }

                absl::Status ASTCreateExternalTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateExternalTableStatement(this, output);
        }

                absl::Status ASTCreateViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateViewStatement(this, output);
        }

                absl::Status ASTCreateMaterializedViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateMaterializedViewStatement(this, output);
        }

                absl::Status ASTCreateApproxViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateApproxViewStatement(this, output);
        }

                absl::Status ASTWhileStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWhileStatement(this, output);
        }

                absl::Status ASTRepeatStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRepeatStatement(this, output);
        }

                absl::Status ASTForInStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTForInStatement(this, output);
        }

                absl::Status ASTAlterConnectionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterConnectionStatement(this, output);
        }

                absl::Status ASTAlterDatabaseStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterDatabaseStatement(this, output);
        }

                absl::Status ASTAlterSchemaStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterSchemaStatement(this, output);
        }

                absl::Status ASTAlterExternalSchemaStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterExternalSchemaStatement(this, output);
        }

                absl::Status ASTAlterTableStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterTableStatement(this, output);
        }

                absl::Status ASTAlterViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterViewStatement(this, output);
        }

                absl::Status ASTAlterMaterializedViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterMaterializedViewStatement(this, output);
        }

                absl::Status ASTAlterApproxViewStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterApproxViewStatement(this, output);
        }

                absl::Status ASTAlterModelStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterModelStatement(this, output);
        }

                absl::Status ASTAlterPrivilegeRestrictionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterPrivilegeRestrictionStatement(this, output);
        }

                absl::Status ASTAlterRowAccessPolicyStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterRowAccessPolicyStatement(this, output);
        }

                absl::Status ASTAlterEntityStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterEntityStatement(this, output);
        }

                absl::Status ASTRebuildAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRebuildAction(this, output);
        }

                absl::Status ASTAlterIndexStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterIndexStatement(this, output);
        }

                absl::Status ASTCreateFunctionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateFunctionStatement(this, output);
        }

                absl::Status ASTCreateTableFunctionStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateTableFunctionStatement(this, output);
        }

                absl::Status ASTStructColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTStructColumnSchema(this, output);
        }

                absl::Status ASTInferredTypeColumnSchema::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInferredTypeColumnSchema(this, output);
        }

                absl::Status ASTExecuteIntoClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExecuteIntoClause(this, output);
        }

                absl::Status ASTExecuteUsingArgument::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExecuteUsingArgument(this, output);
        }

                absl::Status ASTExecuteUsingClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExecuteUsingClause(this, output);
        }

                absl::Status ASTExecuteImmediateStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTExecuteImmediateStatement(this, output);
        }

                absl::Status ASTAuxLoadDataFromFilesOptionsList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAuxLoadDataFromFilesOptionsList(this, output);
        }

                absl::Status ASTAuxLoadDataPartitionsClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAuxLoadDataPartitionsClause(this, output);
        }

                absl::Status ASTAuxLoadDataStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAuxLoadDataStatement(this, output);
        }

                absl::Status ASTLabel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLabel(this, output);
        }

                absl::Status ASTWithExpression::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithExpression(this, output);
        }

                absl::Status ASTTtlClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTTtlClause(this, output);
        }

                absl::Status ASTLocation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLocation(this, output);
        }

                absl::Status ASTInputOutputClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTInputOutputClause(this, output);
        }

                absl::Status ASTSpannerTableOptions::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSpannerTableOptions(this, output);
        }

                absl::Status ASTSpannerInterleaveClause::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSpannerInterleaveClause(this, output);
        }

                absl::Status ASTSpannerAlterColumnAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSpannerAlterColumnAction(this, output);
        }

                absl::Status ASTSpannerSetOnDeleteAction::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTSpannerSetOnDeleteAction(this, output);
        }

                absl::Status ASTRangeLiteral::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRangeLiteral(this, output);
        }

                absl::Status ASTRangeType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRangeType(this, output);
        }

                absl::Status ASTCreatePropertyGraphStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreatePropertyGraphStatement(this, output);
        }

                absl::Status ASTGraphElementTableList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementTableList(this, output);
        }

                absl::Status ASTGraphElementTable::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementTable(this, output);
        }

                absl::Status ASTGraphNodeTableReference::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphNodeTableReference(this, output);
        }

                absl::Status ASTGraphElementLabelAndPropertiesList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementLabelAndPropertiesList(this, output);
        }

                absl::Status ASTGraphElementLabelAndProperties::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementLabelAndProperties(this, output);
        }

                absl::Status ASTGraphDerivedProperty::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphDerivedProperty(this, output);
        }

                absl::Status ASTGraphDerivedPropertyList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphDerivedPropertyList(this, output);
        }

                absl::Status ASTGraphProperties::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphProperties(this, output);
        }

                absl::Status ASTGraphDynamicLabel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphDynamicLabel(this, output);
        }

                absl::Status ASTGraphDynamicProperties::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphDynamicProperties(this, output);
        }

                absl::Status ASTGraphPattern::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPattern(this, output);
        }

                absl::Status ASTGqlQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlQuery(this, output);
        }

                absl::Status ASTGqlGraphPatternQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlGraphPatternQuery(this, output);
        }

                absl::Status ASTGqlLinearOpsQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlLinearOpsQuery(this, output);
        }

                absl::Status ASTGraphTableQuery::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphTableQuery(this, output);
        }

                absl::Status ASTGraphElementLabel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementLabel(this, output);
        }

                absl::Status ASTGraphWildcardLabel::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphWildcardLabel(this, output);
        }

                absl::Status ASTGraphLabelOperation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphLabelOperation(this, output);
        }

                absl::Status ASTGraphLabelFilter::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphLabelFilter(this, output);
        }

                absl::Status ASTGraphIsLabeledPredicate::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphIsLabeledPredicate(this, output);
        }

                absl::Status ASTGraphElementPatternFiller::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphElementPatternFiller(this, output);
        }

                absl::Status ASTGraphPropertySpecification::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPropertySpecification(this, output);
        }

                absl::Status ASTGraphPropertyNameAndValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPropertyNameAndValue(this, output);
        }

                absl::Status ASTGraphNodePattern::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphNodePattern(this, output);
        }

                absl::Status ASTGraphLhsHint::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphLhsHint(this, output);
        }

                absl::Status ASTGraphRhsHint::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphRhsHint(this, output);
        }

                absl::Status ASTGraphPathSearchPrefix::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPathSearchPrefix(this, output);
        }

                absl::Status ASTGraphPathSearchPrefixCount::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPathSearchPrefixCount(this, output);
        }

                absl::Status ASTGraphEdgePattern::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphEdgePattern(this, output);
        }

                absl::Status ASTGraphPathMode::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPathMode(this, output);
        }

                absl::Status ASTGraphPathPattern::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGraphPathPattern(this, output);
        }

                absl::Status ASTGqlMatch::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlMatch(this, output);
        }

                absl::Status ASTGqlReturn::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlReturn(this, output);
        }

                absl::Status ASTGqlWith::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlWith(this, output);
        }

                absl::Status ASTGqlFor::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlFor(this, output);
        }

                absl::Status ASTGqlNamedCall::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlNamedCall(this, output);
        }

                absl::Status ASTYieldItemList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTYieldItemList(this, output);
        }

                absl::Status ASTGqlInlineSubqueryCall::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlInlineSubqueryCall(this, output);
        }

                absl::Status ASTGqlLet::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlLet(this, output);
        }

                absl::Status ASTGqlLetVariableDefinitionList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlLetVariableDefinitionList(this, output);
        }

                absl::Status ASTGqlLetVariableDefinition::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlLetVariableDefinition(this, output);
        }

                absl::Status ASTGqlFilter::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlFilter(this, output);
        }

                absl::Status ASTGqlOperatorList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlOperatorList(this, output);
        }

                absl::Status ASTGqlSetOperation::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlSetOperation(this, output);
        }

                absl::Status ASTGqlPageLimit::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlPageLimit(this, output);
        }

                absl::Status ASTGqlPageOffset::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlPageOffset(this, output);
        }

                absl::Status ASTGqlPage::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlPage(this, output);
        }

                absl::Status ASTGqlOrderByAndPage::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlOrderByAndPage(this, output);
        }

                absl::Status ASTGqlSample::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTGqlSample(this, output);
        }

                absl::Status ASTWithModifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTWithModifier(this, output);
        }

                absl::Status ASTColumnWithOptions::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnWithOptions(this, output);
        }

                absl::Status ASTColumnWithOptionsList::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTColumnWithOptionsList(this, output);
        }

                absl::Status ASTMacroBody::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMacroBody(this, output);
        }

                absl::Status ASTDefineMacroStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTDefineMacroStatement(this, output);
        }

                absl::Status ASTUndropStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTUndropStatement(this, output);
        }

                absl::Status ASTIdentityColumnInfo::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentityColumnInfo(this, output);
        }

                absl::Status ASTIdentityColumnStartWith::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentityColumnStartWith(this, output);
        }

                absl::Status ASTIdentityColumnIncrementBy::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentityColumnIncrementBy(this, output);
        }

                absl::Status ASTIdentityColumnMaxValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentityColumnMaxValue(this, output);
        }

                absl::Status ASTIdentityColumnMinValue::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIdentityColumnMinValue(this, output);
        }

                absl::Status ASTAliasedQueryModifiers::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAliasedQueryModifiers(this, output);
        }

                absl::Status ASTIntOrUnbounded::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTIntOrUnbounded(this, output);
        }

                absl::Status ASTRecursionDepthModifier::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRecursionDepthModifier(this, output);
        }

                absl::Status ASTMapType::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTMapType(this, output);
        }

                absl::Status ASTLockMode::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTLockMode(this, output);
        }

                absl::Status ASTPipeRecursiveUnion::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTPipeRecursiveUnion(this, output);
        }

                absl::Status ASTRunStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTRunStatement(this, output);
        }

                absl::Status ASTCreateSequenceStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTCreateSequenceStatement(this, output);
        }

                absl::Status ASTAlterSequenceStatement::Accept(ParseTreeStatusVisitor& visitor, std::any& output) const {
          return visitor.VisitASTAlterSequenceStatement(this, output);
        }

        absl::StatusOr<VisitResult> ASTQueryStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQueryStatement(this);
}

absl::StatusOr<VisitResult> ASTSubpipelineStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSubpipelineStatement(this);
}

absl::StatusOr<VisitResult> ASTAliasedQueryExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAliasedQueryExpression(this);
}

absl::StatusOr<VisitResult> ASTQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQuery(this);
}

absl::StatusOr<VisitResult> ASTFromQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFromQuery(this);
}

absl::StatusOr<VisitResult> ASTSubpipeline::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSubpipeline(this);
}

absl::StatusOr<VisitResult> ASTPipeExtend::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeExtend(this);
}

absl::StatusOr<VisitResult> ASTPipeRenameItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeRenameItem(this);
}

absl::StatusOr<VisitResult> ASTPipeRename::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeRename(this);
}

absl::StatusOr<VisitResult> ASTPipeAggregate::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeAggregate(this);
}

absl::StatusOr<VisitResult> ASTPipeSetOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeSetOperation(this);
}

absl::StatusOr<VisitResult> ASTPipeJoin::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeJoin(this);
}

absl::StatusOr<VisitResult> ASTPipeCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeCall(this);
}

absl::StatusOr<VisitResult> ASTPipeWindow::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeWindow(this);
}

absl::StatusOr<VisitResult> ASTPipeWhere::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeWhere(this);
}

absl::StatusOr<VisitResult> ASTPipeSelect::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeSelect(this);
}

absl::StatusOr<VisitResult> ASTPipeLimitOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeLimitOffset(this);
}

absl::StatusOr<VisitResult> ASTPipeOrderBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeOrderBy(this);
}

absl::StatusOr<VisitResult> ASTPipeDistinct::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeDistinct(this);
}

absl::StatusOr<VisitResult> ASTPipeTablesample::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeTablesample(this);
}

absl::StatusOr<VisitResult> ASTPipeMatchRecognize::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeMatchRecognize(this);
}

absl::StatusOr<VisitResult> ASTPipeAs::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeAs(this);
}

absl::StatusOr<VisitResult> ASTPipeDescribe::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeDescribe(this);
}

absl::StatusOr<VisitResult> ASTPipeStaticDescribe::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeStaticDescribe(this);
}

absl::StatusOr<VisitResult> ASTPipeAssert::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeAssert(this);
}

absl::StatusOr<VisitResult> ASTPipeLog::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeLog(this);
}

absl::StatusOr<VisitResult> ASTPipeDrop::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeDrop(this);
}

absl::StatusOr<VisitResult> ASTPipeSetItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeSetItem(this);
}

absl::StatusOr<VisitResult> ASTPipeSet::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeSet(this);
}

absl::StatusOr<VisitResult> ASTPipePivot::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipePivot(this);
}

absl::StatusOr<VisitResult> ASTPipeUnpivot::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeUnpivot(this);
}

absl::StatusOr<VisitResult> ASTPipeIf::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeIf(this);
}

absl::StatusOr<VisitResult> ASTPipeIfCase::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeIfCase(this);
}

absl::StatusOr<VisitResult> ASTPipeFork::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeFork(this);
}

absl::StatusOr<VisitResult> ASTPipeTee::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeTee(this);
}

absl::StatusOr<VisitResult> ASTPipeWith::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeWith(this);
}

absl::StatusOr<VisitResult> ASTPipeExportData::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeExportData(this);
}

absl::StatusOr<VisitResult> ASTPipeCreateTable::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeCreateTable(this);
}

absl::StatusOr<VisitResult> ASTPipeInsert::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeInsert(this);
}

absl::StatusOr<VisitResult> ASTSelect::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelect(this);
}

absl::StatusOr<VisitResult> ASTSelectList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectList(this);
}

absl::StatusOr<VisitResult> ASTSelectColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectColumn(this);
}

absl::StatusOr<VisitResult> ASTIntLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntLiteral(this);
}

absl::StatusOr<VisitResult> ASTIdentifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentifier(this);
}

absl::StatusOr<VisitResult> ASTAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlias(this);
}

absl::StatusOr<VisitResult> ASTPathExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPathExpression(this);
}

absl::StatusOr<VisitResult> ASTTablePathExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTablePathExpression(this);
}

absl::StatusOr<VisitResult> ASTPipeJoinLhsPlaceholder::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeJoinLhsPlaceholder(this);
}

absl::StatusOr<VisitResult> ASTFromClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFromClause(this);
}

absl::StatusOr<VisitResult> ASTWhereClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhereClause(this);
}

absl::StatusOr<VisitResult> ASTBooleanLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBooleanLiteral(this);
}

absl::StatusOr<VisitResult> ASTAndExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAndExpr(this);
}

absl::StatusOr<VisitResult> ASTBinaryExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBinaryExpression(this);
}

absl::StatusOr<VisitResult> ASTStringLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStringLiteral(this);
}

absl::StatusOr<VisitResult> ASTStringLiteralComponent::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStringLiteralComponent(this);
}

absl::StatusOr<VisitResult> ASTStar::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStar(this);
}

absl::StatusOr<VisitResult> ASTOrExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrExpr(this);
}

absl::StatusOr<VisitResult> ASTConcatExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTConcatExpr(this);
}

absl::StatusOr<VisitResult> ASTOrderingExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrderingExpression(this);
}

absl::StatusOr<VisitResult> ASTOrderBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOrderBy(this);
}

absl::StatusOr<VisitResult> ASTGroupingItemOrder::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupingItemOrder(this);
}

absl::StatusOr<VisitResult> ASTGroupingItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupingItem(this);
}

absl::StatusOr<VisitResult> ASTGroupBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupBy(this);
}

absl::StatusOr<VisitResult> ASTGroupByAll::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupByAll(this);
}

absl::StatusOr<VisitResult> ASTLimitAll::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLimitAll(this);
}

absl::StatusOr<VisitResult> ASTLimit::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLimit(this);
}

absl::StatusOr<VisitResult> ASTLimitOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLimitOffset(this);
}

absl::StatusOr<VisitResult> ASTFloatLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFloatLiteral(this);
}

absl::StatusOr<VisitResult> ASTNullLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNullLiteral(this);
}

absl::StatusOr<VisitResult> ASTOnClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOnClause(this);
}

absl::StatusOr<VisitResult> ASTAliasedQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAliasedQuery(this);
}

absl::StatusOr<VisitResult> ASTJoin::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTJoin(this);
}

absl::StatusOr<VisitResult> ASTAliasedGroupRows::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAliasedGroupRows(this);
}

absl::StatusOr<VisitResult> ASTWithClauseEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithClauseEntry(this);
}

absl::StatusOr<VisitResult> ASTWithClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithClause(this);
}

absl::StatusOr<VisitResult> ASTHaving::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHaving(this);
}

absl::StatusOr<VisitResult> ASTSimpleType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSimpleType(this);
}

absl::StatusOr<VisitResult> ASTArrayType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayType(this);
}

absl::StatusOr<VisitResult> ASTStructField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructField(this);
}

absl::StatusOr<VisitResult> ASTStructType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructType(this);
}

absl::StatusOr<VisitResult> ASTFunctionTypeArgList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionTypeArgList(this);
}

absl::StatusOr<VisitResult> ASTFunctionType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionType(this);
}

absl::StatusOr<VisitResult> ASTCastExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCastExpression(this);
}

absl::StatusOr<VisitResult> ASTSelectAs::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSelectAs(this);
}

absl::StatusOr<VisitResult> ASTRollup::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRollup(this);
}

absl::StatusOr<VisitResult> ASTCube::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCube(this);
}

absl::StatusOr<VisitResult> ASTGroupingSet::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupingSet(this);
}

absl::StatusOr<VisitResult> ASTGroupingSetList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGroupingSetList(this);
}

absl::StatusOr<VisitResult> ASTExpressionWithAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExpressionWithAlias(this);
}

absl::StatusOr<VisitResult> ASTFunctionCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionCall(this);
}

absl::StatusOr<VisitResult> ASTChainedBaseExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTChainedBaseExpr(this);
}

absl::StatusOr<VisitResult> ASTArrayConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayConstructor(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorArg(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorWithParens::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorWithParens(this);
}

absl::StatusOr<VisitResult> ASTStructConstructorWithKeyword::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructConstructorWithKeyword(this);
}

absl::StatusOr<VisitResult> ASTInExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInExpression(this);
}

absl::StatusOr<VisitResult> ASTInList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInList(this);
}

absl::StatusOr<VisitResult> ASTBetweenExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBetweenExpression(this);
}

absl::StatusOr<VisitResult> ASTNumericLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNumericLiteral(this);
}

absl::StatusOr<VisitResult> ASTBigNumericLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBigNumericLiteral(this);
}

absl::StatusOr<VisitResult> ASTBytesLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBytesLiteral(this);
}

absl::StatusOr<VisitResult> ASTBytesLiteralComponent::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBytesLiteralComponent(this);
}

absl::StatusOr<VisitResult> ASTDateOrTimeLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDateOrTimeLiteral(this);
}

absl::StatusOr<VisitResult> ASTMaxLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMaxLiteral(this);
}

absl::StatusOr<VisitResult> ASTJSONLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTJSONLiteral(this);
}

absl::StatusOr<VisitResult> ASTCaseValueExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseValueExpression(this);
}

absl::StatusOr<VisitResult> ASTCaseNoValueExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseNoValueExpression(this);
}

absl::StatusOr<VisitResult> ASTArrayElement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayElement(this);
}

absl::StatusOr<VisitResult> ASTBitwiseShiftExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBitwiseShiftExpression(this);
}

absl::StatusOr<VisitResult> ASTCollate::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCollate(this);
}

absl::StatusOr<VisitResult> ASTDotGeneralizedField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotGeneralizedField(this);
}

absl::StatusOr<VisitResult> ASTDotIdentifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotIdentifier(this);
}

absl::StatusOr<VisitResult> ASTDotStar::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotStar(this);
}

absl::StatusOr<VisitResult> ASTDotStarWithModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDotStarWithModifiers(this);
}

absl::StatusOr<VisitResult> ASTExpressionSubquery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExpressionSubquery(this);
}

absl::StatusOr<VisitResult> ASTExtractExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExtractExpression(this);
}

absl::StatusOr<VisitResult> ASTHavingModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHavingModifier(this);
}

absl::StatusOr<VisitResult> ASTIntervalExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntervalExpr(this);
}

absl::StatusOr<VisitResult> ASTSequenceArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSequenceArg(this);
}

absl::StatusOr<VisitResult> ASTNamedArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNamedArgument(this);
}

absl::StatusOr<VisitResult> ASTInputTableArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInputTableArgument(this);
}

absl::StatusOr<VisitResult> ASTNullOrder::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNullOrder(this);
}

absl::StatusOr<VisitResult> ASTOnOrUsingClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOnOrUsingClauseList(this);
}

absl::StatusOr<VisitResult> ASTParenthesizedJoin::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParenthesizedJoin(this);
}

absl::StatusOr<VisitResult> ASTPartitionBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPartitionBy(this);
}

absl::StatusOr<VisitResult> ASTSetOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperation(this);
}

absl::StatusOr<VisitResult> ASTSetOperationMetadataList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationMetadataList(this);
}

absl::StatusOr<VisitResult> ASTSetOperationAllOrDistinct::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationAllOrDistinct(this);
}

absl::StatusOr<VisitResult> ASTSetOperationType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationType(this);
}

absl::StatusOr<VisitResult> ASTSetOperationColumnMatchMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationColumnMatchMode(this);
}

absl::StatusOr<VisitResult> ASTSetOperationColumnPropagationMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationColumnPropagationMode(this);
}

absl::StatusOr<VisitResult> ASTSetOperationMetadata::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOperationMetadata(this);
}

absl::StatusOr<VisitResult> ASTStarExceptList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarExceptList(this);
}

absl::StatusOr<VisitResult> ASTStarModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarModifiers(this);
}

absl::StatusOr<VisitResult> ASTStarReplaceItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarReplaceItem(this);
}

absl::StatusOr<VisitResult> ASTStarWithModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStarWithModifiers(this);
}

absl::StatusOr<VisitResult> ASTTableSubquery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableSubquery(this);
}

absl::StatusOr<VisitResult> ASTUnaryExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnaryExpression(this);
}

absl::StatusOr<VisitResult> ASTExpressionWithOptAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExpressionWithOptAlias(this);
}

absl::StatusOr<VisitResult> ASTUnnestExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnnestExpression(this);
}

absl::StatusOr<VisitResult> ASTWindowClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowClause(this);
}

absl::StatusOr<VisitResult> ASTWindowDefinition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowDefinition(this);
}

absl::StatusOr<VisitResult> ASTWindowFrame::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowFrame(this);
}

absl::StatusOr<VisitResult> ASTWindowFrameExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowFrameExpr(this);
}

absl::StatusOr<VisitResult> ASTLikeExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLikeExpression(this);
}

absl::StatusOr<VisitResult> ASTQuantifiedComparisonExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQuantifiedComparisonExpression(this);
}

absl::StatusOr<VisitResult> ASTWindowSpecification::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWindowSpecification(this);
}

absl::StatusOr<VisitResult> ASTWithOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithOffset(this);
}

absl::StatusOr<VisitResult> ASTAnySomeAllOp::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnySomeAllOp(this);
}

absl::StatusOr<VisitResult> ASTStatementList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStatementList(this);
}

absl::StatusOr<VisitResult> ASTHintedStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHintedStatement(this);
}

absl::StatusOr<VisitResult> ASTStatementWithPipeOperators::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStatementWithPipeOperators(this);
}

absl::StatusOr<VisitResult> ASTExplainStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExplainStatement(this);
}

absl::StatusOr<VisitResult> ASTDescribeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescribeStatement(this);
}

absl::StatusOr<VisitResult> ASTShowStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTShowStatement(this);
}

absl::StatusOr<VisitResult> ASTTransactionIsolationLevel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionIsolationLevel(this);
}

absl::StatusOr<VisitResult> ASTTransactionReadWriteMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionReadWriteMode(this);
}

absl::StatusOr<VisitResult> ASTTransactionModeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransactionModeList(this);
}

absl::StatusOr<VisitResult> ASTBeginStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBeginStatement(this);
}

absl::StatusOr<VisitResult> ASTSetTransactionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetTransactionStatement(this);
}

absl::StatusOr<VisitResult> ASTCommitStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCommitStatement(this);
}

absl::StatusOr<VisitResult> ASTRollbackStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRollbackStatement(this);
}

absl::StatusOr<VisitResult> ASTStartBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStartBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTRunBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRunBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTAbortBatchStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAbortBatchStatement(this);
}

absl::StatusOr<VisitResult> ASTDropEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTDropFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropTableFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropTableFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropAllRowAccessPoliciesStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropAllRowAccessPoliciesStatement(this);
}

absl::StatusOr<VisitResult> ASTDropMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTDropSnapshotTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropSnapshotTableStatement(this);
}

absl::StatusOr<VisitResult> ASTDropSearchIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropSearchIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTDropVectorIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropVectorIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTRenameStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameStatement(this);
}

absl::StatusOr<VisitResult> ASTImportStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTImportStatement(this);
}

absl::StatusOr<VisitResult> ASTModuleStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTModuleStatement(this);
}

absl::StatusOr<VisitResult> ASTWithConnectionClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithConnectionClause(this);
}

absl::StatusOr<VisitResult> ASTIntoAlias::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntoAlias(this);
}

absl::StatusOr<VisitResult> ASTUnnestExpressionWithOptAliasAndOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnnestExpressionWithOptAliasAndOffset(this);
}

absl::StatusOr<VisitResult> ASTPivotExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotExpression(this);
}

absl::StatusOr<VisitResult> ASTPivotValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotValue(this);
}

absl::StatusOr<VisitResult> ASTPivotExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotExpressionList(this);
}

absl::StatusOr<VisitResult> ASTPivotValueList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotValueList(this);
}

absl::StatusOr<VisitResult> ASTPivotClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPivotClause(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItem(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItemList(this);
}

absl::StatusOr<VisitResult> ASTUnpivotClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotClause(this);
}

absl::StatusOr<VisitResult> ASTUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUsingClause(this);
}

absl::StatusOr<VisitResult> ASTForSystemTime::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForSystemTime(this);
}

absl::StatusOr<VisitResult> ASTMatchRecognizeClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMatchRecognizeClause(this);
}

absl::StatusOr<VisitResult> ASTAfterMatchSkipClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAfterMatchSkipClause(this);
}

absl::StatusOr<VisitResult> ASTRowPatternVariable::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRowPatternVariable(this);
}

absl::StatusOr<VisitResult> ASTRowPatternOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRowPatternOperation(this);
}

absl::StatusOr<VisitResult> ASTEmptyRowPattern::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTEmptyRowPattern(this);
}

absl::StatusOr<VisitResult> ASTRowPatternAnchor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRowPatternAnchor(this);
}

absl::StatusOr<VisitResult> ASTBoundedQuantifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBoundedQuantifier(this);
}

absl::StatusOr<VisitResult> ASTQuantifierBound::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQuantifierBound(this);
}

absl::StatusOr<VisitResult> ASTFixedQuantifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFixedQuantifier(this);
}

absl::StatusOr<VisitResult> ASTSymbolQuantifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSymbolQuantifier(this);
}

absl::StatusOr<VisitResult> ASTRowPatternQuantification::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRowPatternQuantification(this);
}

absl::StatusOr<VisitResult> ASTQualify::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTQualify(this);
}

absl::StatusOr<VisitResult> ASTClampedBetweenModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTClampedBetweenModifier(this);
}

absl::StatusOr<VisitResult> ASTWithReportModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithReportModifier(this);
}

absl::StatusOr<VisitResult> ASTFormatClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFormatClause(this);
}

absl::StatusOr<VisitResult> ASTPathExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPathExpressionList(this);
}

absl::StatusOr<VisitResult> ASTParameterExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParameterExpr(this);
}

absl::StatusOr<VisitResult> ASTSystemVariableExpr::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSystemVariableExpr(this);
}

absl::StatusOr<VisitResult> ASTLambda::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLambda(this);
}

absl::StatusOr<VisitResult> ASTAnalyticFunctionCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnalyticFunctionCall(this);
}

absl::StatusOr<VisitResult> ASTClusterBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTClusterBy(this);
}

absl::StatusOr<VisitResult> ASTNewConstructorArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNewConstructorArg(this);
}

absl::StatusOr<VisitResult> ASTNewConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNewConstructor(this);
}

absl::StatusOr<VisitResult> ASTBracedConstructorLhs::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBracedConstructorLhs(this);
}

absl::StatusOr<VisitResult> ASTBracedConstructorFieldValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBracedConstructorFieldValue(this);
}

absl::StatusOr<VisitResult> ASTBracedConstructorField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBracedConstructorField(this);
}

absl::StatusOr<VisitResult> ASTBracedConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBracedConstructor(this);
}

absl::StatusOr<VisitResult> ASTBracedNewConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBracedNewConstructor(this);
}

absl::StatusOr<VisitResult> ASTExtendedPathExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExtendedPathExpression(this);
}

absl::StatusOr<VisitResult> ASTUpdateConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateConstructor(this);
}

absl::StatusOr<VisitResult> ASTStructBracedConstructor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructBracedConstructor(this);
}

absl::StatusOr<VisitResult> ASTOptionsList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOptionsList(this);
}

absl::StatusOr<VisitResult> ASTOptionsEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOptionsEntry(this);
}

absl::StatusOr<VisitResult> ASTFunctionParameter::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionParameter(this);
}

absl::StatusOr<VisitResult> ASTFunctionParameters::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionParameters(this);
}

absl::StatusOr<VisitResult> ASTFunctionDeclaration::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFunctionDeclaration(this);
}

absl::StatusOr<VisitResult> ASTSqlFunctionBody::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSqlFunctionBody(this);
}

absl::StatusOr<VisitResult> ASTTVFArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFArgument(this);
}

absl::StatusOr<VisitResult> ASTTVF::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVF(this);
}

absl::StatusOr<VisitResult> ASTTableClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableClause(this);
}

absl::StatusOr<VisitResult> ASTModelClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTModelClause(this);
}

absl::StatusOr<VisitResult> ASTConnectionClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTConnectionClause(this);
}

absl::StatusOr<VisitResult> ASTCloneDataSource::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataSource(this);
}

absl::StatusOr<VisitResult> ASTCopyDataSource::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCopyDataSource(this);
}

absl::StatusOr<VisitResult> ASTCloneDataSourceList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataSourceList(this);
}

absl::StatusOr<VisitResult> ASTCloneDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCloneDataStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateConnectionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateConnectionStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateConstantStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateConstantStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateDatabaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateDatabaseStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateProcedureStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateProcedureStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateExternalSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateExternalSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTAliasedQueryList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAliasedQueryList(this);
}

absl::StatusOr<VisitResult> ASTTransformClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTransformClause(this);
}

absl::StatusOr<VisitResult> ASTCreateModelStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateModelStatement(this);
}

absl::StatusOr<VisitResult> ASTIndexAllColumns::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexAllColumns(this);
}

absl::StatusOr<VisitResult> ASTIndexItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexItemList(this);
}

absl::StatusOr<VisitResult> ASTIndexStoringExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexStoringExpressionList(this);
}

absl::StatusOr<VisitResult> ASTIndexUnnestExpressionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIndexUnnestExpressionList(this);
}

absl::StatusOr<VisitResult> ASTCreateIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTExportDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExportDataStatement(this);
}

absl::StatusOr<VisitResult> ASTExportModelStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExportModelStatement(this);
}

absl::StatusOr<VisitResult> ASTExportMetadataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExportMetadataStatement(this);
}

absl::StatusOr<VisitResult> ASTCallStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCallStatement(this);
}

absl::StatusOr<VisitResult> ASTDefineTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDefineTableStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateLocalityGroupStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateLocalityGroupStatement(this);
}

absl::StatusOr<VisitResult> ASTWithPartitionColumnsClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithPartitionColumnsClause(this);
}

absl::StatusOr<VisitResult> ASTCreateSnapshotStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSnapshotStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateSnapshotTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSnapshotTableStatement(this);
}

absl::StatusOr<VisitResult> ASTTypeParameterList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTypeParameterList(this);
}

absl::StatusOr<VisitResult> ASTTVFSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFSchema(this);
}

absl::StatusOr<VisitResult> ASTTVFSchemaColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTVFSchemaColumn(this);
}

absl::StatusOr<VisitResult> ASTTableAndColumnInfo::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableAndColumnInfo(this);
}

absl::StatusOr<VisitResult> ASTTableAndColumnInfoList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableAndColumnInfoList(this);
}

absl::StatusOr<VisitResult> ASTTemplatedParameterType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTemplatedParameterType(this);
}

absl::StatusOr<VisitResult> ASTDefaultLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDefaultLiteral(this);
}

absl::StatusOr<VisitResult> ASTAnalyzeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAnalyzeStatement(this);
}

absl::StatusOr<VisitResult> ASTAssertStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssertStatement(this);
}

absl::StatusOr<VisitResult> ASTAssertRowsModified::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssertRowsModified(this);
}

absl::StatusOr<VisitResult> ASTReturningClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReturningClause(this);
}

absl::StatusOr<VisitResult> ASTOnConflictClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTOnConflictClause(this);
}

absl::StatusOr<VisitResult> ASTDeleteStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDeleteStatement(this);
}

absl::StatusOr<VisitResult> ASTNotNullColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTNotNullColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTHiddenColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHiddenColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKeyColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKeyColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyColumnAttribute::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyColumnAttribute(this);
}

absl::StatusOr<VisitResult> ASTColumnAttributeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnAttributeList(this);
}

absl::StatusOr<VisitResult> ASTStructColumnField::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructColumnField(this);
}

absl::StatusOr<VisitResult> ASTGeneratedColumnInfo::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGeneratedColumnInfo(this);
}

absl::StatusOr<VisitResult> ASTColumnDefinition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnDefinition(this);
}

absl::StatusOr<VisitResult> ASTTableElementList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTableElementList(this);
}

absl::StatusOr<VisitResult> ASTColumnList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnList(this);
}

absl::StatusOr<VisitResult> ASTColumnPosition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnPosition(this);
}

absl::StatusOr<VisitResult> ASTInsertValuesRow::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertValuesRow(this);
}

absl::StatusOr<VisitResult> ASTInsertValuesRowList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertValuesRowList(this);
}

absl::StatusOr<VisitResult> ASTInsertStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInsertStatement(this);
}

absl::StatusOr<VisitResult> ASTUpdateSetValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateSetValue(this);
}

absl::StatusOr<VisitResult> ASTUpdateItem::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateItem(this);
}

absl::StatusOr<VisitResult> ASTUpdateItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateItemList(this);
}

absl::StatusOr<VisitResult> ASTUpdateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUpdateStatement(this);
}

absl::StatusOr<VisitResult> ASTTruncateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTruncateStatement(this);
}

absl::StatusOr<VisitResult> ASTMergeAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeAction(this);
}

absl::StatusOr<VisitResult> ASTMergeWhenClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeWhenClause(this);
}

absl::StatusOr<VisitResult> ASTMergeWhenClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeWhenClauseList(this);
}

absl::StatusOr<VisitResult> ASTMergeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMergeStatement(this);
}

absl::StatusOr<VisitResult> ASTPrivilege::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrivilege(this);
}

absl::StatusOr<VisitResult> ASTPrivileges::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrivileges(this);
}

absl::StatusOr<VisitResult> ASTGranteeList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGranteeList(this);
}

absl::StatusOr<VisitResult> ASTGrantStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGrantStatement(this);
}

absl::StatusOr<VisitResult> ASTRevokeStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRevokeStatement(this);
}

absl::StatusOr<VisitResult> ASTRepeatableClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRepeatableClause(this);
}

absl::StatusOr<VisitResult> ASTFilterFieldsArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFilterFieldsArg(this);
}

absl::StatusOr<VisitResult> ASTReplaceFieldsArg::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReplaceFieldsArg(this);
}

absl::StatusOr<VisitResult> ASTReplaceFieldsExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReplaceFieldsExpression(this);
}

absl::StatusOr<VisitResult> ASTSampleSize::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleSize(this);
}

absl::StatusOr<VisitResult> ASTWithWeight::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithWeight(this);
}

absl::StatusOr<VisitResult> ASTSampleSuffix::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleSuffix(this);
}

absl::StatusOr<VisitResult> ASTSampleClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSampleClause(this);
}

absl::StatusOr<VisitResult> ASTSetOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTSetAsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetAsAction(this);
}

absl::StatusOr<VisitResult> ASTAddConstraintAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddConstraintAction(this);
}

absl::StatusOr<VisitResult> ASTDropPrimaryKeyAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropPrimaryKeyAction(this);
}

absl::StatusOr<VisitResult> ASTDropConstraintAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropConstraintAction(this);
}

absl::StatusOr<VisitResult> ASTAlterConstraintEnforcementAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterConstraintEnforcementAction(this);
}

absl::StatusOr<VisitResult> ASTAlterConstraintSetOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterConstraintSetOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTAddColumnIdentifierAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddColumnIdentifierAction(this);
}

absl::StatusOr<VisitResult> ASTAddColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddColumnAction(this);
}

absl::StatusOr<VisitResult> ASTDropColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropColumnAction(this);
}

absl::StatusOr<VisitResult> ASTRenameColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameColumnAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnTypeAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnTypeAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnOptionsAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnOptionsAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnSetDefaultAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnSetDefaultAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnDropDefaultAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnDropDefaultAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnDropNotNullAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnDropNotNullAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnDropGeneratedAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnDropGeneratedAction(this);
}

absl::StatusOr<VisitResult> ASTAlterColumnSetGeneratedAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterColumnSetGeneratedAction(this);
}

absl::StatusOr<VisitResult> ASTGrantToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGrantToClause(this);
}

absl::StatusOr<VisitResult> ASTRestrictToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRestrictToClause(this);
}

absl::StatusOr<VisitResult> ASTAddToRestricteeListClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddToRestricteeListClause(this);
}

absl::StatusOr<VisitResult> ASTRemoveFromRestricteeListClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRemoveFromRestricteeListClause(this);
}

absl::StatusOr<VisitResult> ASTFilterUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTFilterUsingClause(this);
}

absl::StatusOr<VisitResult> ASTRevokeFromClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRevokeFromClause(this);
}

absl::StatusOr<VisitResult> ASTRenameToClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRenameToClause(this);
}

absl::StatusOr<VisitResult> ASTSetCollateClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSetCollateClause(this);
}

absl::StatusOr<VisitResult> ASTAlterSubEntityAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterSubEntityAction(this);
}

absl::StatusOr<VisitResult> ASTAddSubEntityAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddSubEntityAction(this);
}

absl::StatusOr<VisitResult> ASTDropSubEntityAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropSubEntityAction(this);
}

absl::StatusOr<VisitResult> ASTAddTtlAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAddTtlAction(this);
}

absl::StatusOr<VisitResult> ASTReplaceTtlAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReplaceTtlAction(this);
}

absl::StatusOr<VisitResult> ASTDropTtlAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropTtlAction(this);
}

absl::StatusOr<VisitResult> ASTAlterActionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterActionList(this);
}

absl::StatusOr<VisitResult> ASTAlterAllRowAccessPoliciesStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterAllRowAccessPoliciesStatement(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyActions::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyActions(this);
}

absl::StatusOr<VisitResult> ASTForeignKeyReference::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKeyReference(this);
}

absl::StatusOr<VisitResult> ASTScript::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTScript(this);
}

absl::StatusOr<VisitResult> ASTElseifClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTElseifClause(this);
}

absl::StatusOr<VisitResult> ASTElseifClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTElseifClauseList(this);
}

absl::StatusOr<VisitResult> ASTIfStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIfStatement(this);
}

absl::StatusOr<VisitResult> ASTWhenThenClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhenThenClause(this);
}

absl::StatusOr<VisitResult> ASTWhenThenClauseList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhenThenClauseList(this);
}

absl::StatusOr<VisitResult> ASTCaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCaseStatement(this);
}

absl::StatusOr<VisitResult> ASTHint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHint(this);
}

absl::StatusOr<VisitResult> ASTHintEntry::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTHintEntry(this);
}

absl::StatusOr<VisitResult> ASTUnpivotInItemLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUnpivotInItemLabel(this);
}

absl::StatusOr<VisitResult> ASTDescriptor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptor(this);
}

absl::StatusOr<VisitResult> ASTSimpleColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSimpleColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTArrayColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTArrayColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTRangeColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRangeColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTMapColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMapColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKeyElement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKeyElement(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKeyElementList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKeyElementList(this);
}

absl::StatusOr<VisitResult> ASTPrimaryKey::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPrimaryKey(this);
}

absl::StatusOr<VisitResult> ASTForeignKey::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForeignKey(this);
}

absl::StatusOr<VisitResult> ASTCheckConstraint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCheckConstraint(this);
}

absl::StatusOr<VisitResult> ASTDescriptorColumn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptorColumn(this);
}

absl::StatusOr<VisitResult> ASTDescriptorColumnList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDescriptorColumnList(this);
}

absl::StatusOr<VisitResult> ASTCreateEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTRaiseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRaiseStatement(this);
}

absl::StatusOr<VisitResult> ASTExceptionHandler::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExceptionHandler(this);
}

absl::StatusOr<VisitResult> ASTExceptionHandlerList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExceptionHandlerList(this);
}

absl::StatusOr<VisitResult> ASTBeginEndBlock::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBeginEndBlock(this);
}

absl::StatusOr<VisitResult> ASTIdentifierList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentifierList(this);
}

absl::StatusOr<VisitResult> ASTVariableDeclaration::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTVariableDeclaration(this);
}

absl::StatusOr<VisitResult> ASTUntilClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUntilClause(this);
}

absl::StatusOr<VisitResult> ASTBreakStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTBreakStatement(this);
}

absl::StatusOr<VisitResult> ASTContinueStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTContinueStatement(this);
}

absl::StatusOr<VisitResult> ASTDropPrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropPrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTDropRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTCreatePrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreatePrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTDropStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDropStatement(this);
}

absl::StatusOr<VisitResult> ASTReturnStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTReturnStatement(this);
}

absl::StatusOr<VisitResult> ASTSingleAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSingleAssignment(this);
}

absl::StatusOr<VisitResult> ASTParameterAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTParameterAssignment(this);
}

absl::StatusOr<VisitResult> ASTSystemVariableAssignment::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSystemVariableAssignment(this);
}

absl::StatusOr<VisitResult> ASTAssignmentFromStruct::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAssignmentFromStruct(this);
}

absl::StatusOr<VisitResult> ASTCreateTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateTableStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateExternalTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateExternalTableStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateViewStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateApproxViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateApproxViewStatement(this);
}

absl::StatusOr<VisitResult> ASTWhileStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWhileStatement(this);
}

absl::StatusOr<VisitResult> ASTRepeatStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRepeatStatement(this);
}

absl::StatusOr<VisitResult> ASTForInStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTForInStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterConnectionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterConnectionStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterDatabaseStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterDatabaseStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterExternalSchemaStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterExternalSchemaStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterTableStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterTableStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterViewStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterMaterializedViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterMaterializedViewStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterApproxViewStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterApproxViewStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterModelStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterModelStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterPrivilegeRestrictionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterPrivilegeRestrictionStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterRowAccessPolicyStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterRowAccessPolicyStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterEntityStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterEntityStatement(this);
}

absl::StatusOr<VisitResult> ASTRebuildAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRebuildAction(this);
}

absl::StatusOr<VisitResult> ASTAlterIndexStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterIndexStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateTableFunctionStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateTableFunctionStatement(this);
}

absl::StatusOr<VisitResult> ASTStructColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTStructColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTInferredTypeColumnSchema::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInferredTypeColumnSchema(this);
}

absl::StatusOr<VisitResult> ASTExecuteIntoClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteIntoClause(this);
}

absl::StatusOr<VisitResult> ASTExecuteUsingArgument::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteUsingArgument(this);
}

absl::StatusOr<VisitResult> ASTExecuteUsingClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteUsingClause(this);
}

absl::StatusOr<VisitResult> ASTExecuteImmediateStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTExecuteImmediateStatement(this);
}

absl::StatusOr<VisitResult> ASTAuxLoadDataFromFilesOptionsList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAuxLoadDataFromFilesOptionsList(this);
}

absl::StatusOr<VisitResult> ASTAuxLoadDataPartitionsClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAuxLoadDataPartitionsClause(this);
}

absl::StatusOr<VisitResult> ASTAuxLoadDataStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAuxLoadDataStatement(this);
}

absl::StatusOr<VisitResult> ASTLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLabel(this);
}

absl::StatusOr<VisitResult> ASTWithExpression::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithExpression(this);
}

absl::StatusOr<VisitResult> ASTTtlClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTTtlClause(this);
}

absl::StatusOr<VisitResult> ASTLocation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLocation(this);
}

absl::StatusOr<VisitResult> ASTInputOutputClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTInputOutputClause(this);
}

absl::StatusOr<VisitResult> ASTSpannerTableOptions::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSpannerTableOptions(this);
}

absl::StatusOr<VisitResult> ASTSpannerInterleaveClause::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSpannerInterleaveClause(this);
}

absl::StatusOr<VisitResult> ASTSpannerAlterColumnAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSpannerAlterColumnAction(this);
}

absl::StatusOr<VisitResult> ASTSpannerSetOnDeleteAction::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTSpannerSetOnDeleteAction(this);
}

absl::StatusOr<VisitResult> ASTRangeLiteral::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRangeLiteral(this);
}

absl::StatusOr<VisitResult> ASTRangeType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRangeType(this);
}

absl::StatusOr<VisitResult> ASTCreatePropertyGraphStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreatePropertyGraphStatement(this);
}

absl::StatusOr<VisitResult> ASTGraphElementTableList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementTableList(this);
}

absl::StatusOr<VisitResult> ASTGraphElementTable::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementTable(this);
}

absl::StatusOr<VisitResult> ASTGraphNodeTableReference::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphNodeTableReference(this);
}

absl::StatusOr<VisitResult> ASTGraphElementLabelAndPropertiesList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementLabelAndPropertiesList(this);
}

absl::StatusOr<VisitResult> ASTGraphElementLabelAndProperties::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementLabelAndProperties(this);
}

absl::StatusOr<VisitResult> ASTGraphDerivedProperty::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphDerivedProperty(this);
}

absl::StatusOr<VisitResult> ASTGraphDerivedPropertyList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphDerivedPropertyList(this);
}

absl::StatusOr<VisitResult> ASTGraphProperties::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphProperties(this);
}

absl::StatusOr<VisitResult> ASTGraphDynamicLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphDynamicLabel(this);
}

absl::StatusOr<VisitResult> ASTGraphDynamicProperties::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphDynamicProperties(this);
}

absl::StatusOr<VisitResult> ASTGraphPattern::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPattern(this);
}

absl::StatusOr<VisitResult> ASTGqlQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlQuery(this);
}

absl::StatusOr<VisitResult> ASTGqlGraphPatternQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlGraphPatternQuery(this);
}

absl::StatusOr<VisitResult> ASTGqlLinearOpsQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlLinearOpsQuery(this);
}

absl::StatusOr<VisitResult> ASTGraphTableQuery::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphTableQuery(this);
}

absl::StatusOr<VisitResult> ASTGraphElementLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementLabel(this);
}

absl::StatusOr<VisitResult> ASTGraphWildcardLabel::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphWildcardLabel(this);
}

absl::StatusOr<VisitResult> ASTGraphLabelOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphLabelOperation(this);
}

absl::StatusOr<VisitResult> ASTGraphLabelFilter::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphLabelFilter(this);
}

absl::StatusOr<VisitResult> ASTGraphIsLabeledPredicate::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphIsLabeledPredicate(this);
}

absl::StatusOr<VisitResult> ASTGraphElementPatternFiller::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphElementPatternFiller(this);
}

absl::StatusOr<VisitResult> ASTGraphPropertySpecification::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPropertySpecification(this);
}

absl::StatusOr<VisitResult> ASTGraphPropertyNameAndValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPropertyNameAndValue(this);
}

absl::StatusOr<VisitResult> ASTGraphNodePattern::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphNodePattern(this);
}

absl::StatusOr<VisitResult> ASTGraphLhsHint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphLhsHint(this);
}

absl::StatusOr<VisitResult> ASTGraphRhsHint::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphRhsHint(this);
}

absl::StatusOr<VisitResult> ASTGraphPathSearchPrefix::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPathSearchPrefix(this);
}

absl::StatusOr<VisitResult> ASTGraphPathSearchPrefixCount::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPathSearchPrefixCount(this);
}

absl::StatusOr<VisitResult> ASTGraphEdgePattern::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphEdgePattern(this);
}

absl::StatusOr<VisitResult> ASTGraphPathMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPathMode(this);
}

absl::StatusOr<VisitResult> ASTGraphPathPattern::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGraphPathPattern(this);
}

absl::StatusOr<VisitResult> ASTGqlMatch::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlMatch(this);
}

absl::StatusOr<VisitResult> ASTGqlReturn::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlReturn(this);
}

absl::StatusOr<VisitResult> ASTGqlWith::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlWith(this);
}

absl::StatusOr<VisitResult> ASTGqlFor::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlFor(this);
}

absl::StatusOr<VisitResult> ASTGqlNamedCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlNamedCall(this);
}

absl::StatusOr<VisitResult> ASTYieldItemList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTYieldItemList(this);
}

absl::StatusOr<VisitResult> ASTGqlInlineSubqueryCall::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlInlineSubqueryCall(this);
}

absl::StatusOr<VisitResult> ASTGqlLet::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlLet(this);
}

absl::StatusOr<VisitResult> ASTGqlLetVariableDefinitionList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlLetVariableDefinitionList(this);
}

absl::StatusOr<VisitResult> ASTGqlLetVariableDefinition::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlLetVariableDefinition(this);
}

absl::StatusOr<VisitResult> ASTGqlFilter::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlFilter(this);
}

absl::StatusOr<VisitResult> ASTGqlOperatorList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlOperatorList(this);
}

absl::StatusOr<VisitResult> ASTGqlSetOperation::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlSetOperation(this);
}

absl::StatusOr<VisitResult> ASTGqlPageLimit::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlPageLimit(this);
}

absl::StatusOr<VisitResult> ASTGqlPageOffset::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlPageOffset(this);
}

absl::StatusOr<VisitResult> ASTGqlPage::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlPage(this);
}

absl::StatusOr<VisitResult> ASTGqlOrderByAndPage::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlOrderByAndPage(this);
}

absl::StatusOr<VisitResult> ASTGqlSample::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTGqlSample(this);
}

absl::StatusOr<VisitResult> ASTWithModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTWithModifier(this);
}

absl::StatusOr<VisitResult> ASTColumnWithOptions::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnWithOptions(this);
}

absl::StatusOr<VisitResult> ASTColumnWithOptionsList::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTColumnWithOptionsList(this);
}

absl::StatusOr<VisitResult> ASTMacroBody::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMacroBody(this);
}

absl::StatusOr<VisitResult> ASTDefineMacroStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTDefineMacroStatement(this);
}

absl::StatusOr<VisitResult> ASTUndropStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTUndropStatement(this);
}

absl::StatusOr<VisitResult> ASTIdentityColumnInfo::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentityColumnInfo(this);
}

absl::StatusOr<VisitResult> ASTIdentityColumnStartWith::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentityColumnStartWith(this);
}

absl::StatusOr<VisitResult> ASTIdentityColumnIncrementBy::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentityColumnIncrementBy(this);
}

absl::StatusOr<VisitResult> ASTIdentityColumnMaxValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentityColumnMaxValue(this);
}

absl::StatusOr<VisitResult> ASTIdentityColumnMinValue::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIdentityColumnMinValue(this);
}

absl::StatusOr<VisitResult> ASTAliasedQueryModifiers::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAliasedQueryModifiers(this);
}

absl::StatusOr<VisitResult> ASTIntOrUnbounded::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTIntOrUnbounded(this);
}

absl::StatusOr<VisitResult> ASTRecursionDepthModifier::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRecursionDepthModifier(this);
}

absl::StatusOr<VisitResult> ASTMapType::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTMapType(this);
}

absl::StatusOr<VisitResult> ASTLockMode::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTLockMode(this);
}

absl::StatusOr<VisitResult> ASTPipeRecursiveUnion::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTPipeRecursiveUnion(this);
}

absl::StatusOr<VisitResult> ASTRunStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTRunStatement(this);
}

absl::StatusOr<VisitResult> ASTCreateSequenceStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTCreateSequenceStatement(this);
}

absl::StatusOr<VisitResult> ASTAlterSequenceStatement::Accept(NonRecursiveParseTreeVisitor* visitor) const {
  return visitor->visitASTAlterSequenceStatement(this);
}

}  // namespace googlesql
