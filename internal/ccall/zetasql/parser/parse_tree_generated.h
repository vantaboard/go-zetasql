//
// Copyright 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// parse_tree_generated.h is generated from parse_tree_generated.h.template
// by gen_parse_tree.py. It should never be #included directly. Include
// parse_tree.h instead.

#ifndef GOOGLESQL_PARSER_PARSE_TREE_GENERATED_H_
#define GOOGLESQL_PARSER_PARSE_TREE_GENERATED_H_

#include "googlesql/parser/ast_enums.pb.h"
#include "googlesql/parser/ast_node.h"
#include "googlesql/parser/parse_tree_decls.h"
#include "googlesql/public/id_string.h"
#include "googlesql/public/type.pb.h"

// NOLINTBEGIN(whitespace/line_length)

namespace googlesql {

// Superclass of all Statements.
class ASTStatement : public ASTNode {
 public:
  explicit ASTStatement(ASTNodeKind kind) : ASTNode(kind) {}

  bool IsStatement() const final { return true; }
  bool IsSqlStatement() const override { return true; }

  friend class ParseTreeSerializer;
};

// Represents a single query statement.
class ASTQueryStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_QUERY_STATEMENT;

  ASTQueryStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTQuery* query() const { return query_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_));
    return fl.Finalize();
  }

  const ASTQuery* query_ = nullptr;
};

// Represents a standalone subpipeline parsed as a statement.
// Also used for pipe suffixes on other statements in
// ASTStatementWithPipeOperators.
// See (broken link).
class ASTSubpipelineStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SUBPIPELINE_STATEMENT;

  ASTSubpipelineStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSubpipeline* subpipeline() const { return subpipeline_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&subpipeline_));
    return fl.Finalize();
  }

  const ASTSubpipeline* subpipeline_ = nullptr;
};

// Superclass for all query expressions.  These are top-level syntactic
// constructs (outside individual SELECTs) making up a query.  These include
// Query itself, Select, UnionAll, etc.
class ASTQueryExpression : public ASTNode {
 public:
  explicit ASTQueryExpression(ASTNodeKind kind) : ASTNode(kind) {}

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  bool IsQueryExpression() const override { return true; }

  friend class ParseTreeSerializer;

 private:
  bool parenthesized_ = false;
};

// This is a parenthesized query expression with an alias.
class ASTAliasedQueryExpression final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIASED_QUERY_EXPRESSION;

  ASTAliasedQueryExpression() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTQuery* query() const { return query_; }
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    return fl.Finalize();
  }

  const ASTQuery* query_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

class ASTQuery final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_QUERY;

  ASTQuery() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_nested(bool is_nested) { is_nested_ = is_nested; }
  bool is_nested() const { return is_nested_; }

  // True if this query represents the input to a pivot clause.
  void set_is_pivot_input(bool is_pivot_input) { is_pivot_input_ = is_pivot_input; }
  bool is_pivot_input() const { return is_pivot_input_; }

  // If present, the WITH clause wrapping this query.
  const ASTWithClause* with_clause() const { return with_clause_; }

  // The query_expr can be a single Select, or a more complex structure
  // composed out of nodes like SetOperation and Query.
  const ASTQueryExpression* query_expr() const { return query_expr_; }

  // If present, applies to the result of <query_expr_> as appropriate.
  const ASTOrderBy* order_by() const { return order_by_; }

  // If present, this applies after the result of <query_expr_> and
  // <order_by_>.
  const ASTLimitOffset* limit_offset() const { return limit_offset_; }

  // If present, applies to the <query_expr_>.
  const ASTLockMode* lock_mode() const { return lock_mode_; }

  const absl::Span<const ASTPipeOperator* const>& pipe_operator_list() const {
    return pipe_operator_list_;
  }
  const ASTPipeOperator* pipe_operator_list(int i) const { return pipe_operator_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&with_clause_, AST_WITH_CLAUSE);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_expr_));
    fl.AddOptional(&order_by_, AST_ORDER_BY);
    fl.AddOptional(&limit_offset_, AST_LIMIT_OFFSET);
    fl.AddOptional(&lock_mode_, AST_LOCK_MODE);
    fl.AddRestAsRepeated(&pipe_operator_list_);
    return fl.Finalize();
  }

  const ASTWithClause* with_clause_ = nullptr;
  const ASTQueryExpression* query_expr_ = nullptr;
  const ASTOrderBy* order_by_ = nullptr;
  const ASTLimitOffset* limit_offset_ = nullptr;
  const ASTLockMode* lock_mode_ = nullptr;
  bool is_nested_ = false;
  bool is_pivot_input_ = false;
  absl::Span<const ASTPipeOperator* const> pipe_operator_list_;
};

// This represents a FROM query, which has just a FROM clause and
// no other clauses.  This is enabled by FEATURE_PIPES.
class ASTFromQuery final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FROM_QUERY;

  ASTFromQuery() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTFromClause* from_clause() const { return from_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&from_clause_));
    return fl.Finalize();
  }

  const ASTFromClause* from_clause_ = nullptr;
};

class ASTSubpipeline final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SUBPIPELINE;

  ASTSubpipeline() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  const absl::Span<const ASTPipeOperator* const>& pipe_operator_list() const {
    return pipe_operator_list_;
  }
  const ASTPipeOperator* pipe_operator_list(int i) const { return pipe_operator_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&pipe_operator_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTPipeOperator* const> pipe_operator_list_;
  bool parenthesized_ = false;
};

// This is the superclass of all ASTPipe* operators, representing one
// pipe operation in a chain.
class ASTPipeOperator : public ASTNode {
 public:
  explicit ASTPipeOperator(ASTNodeKind kind) : ASTNode(kind) {}

  friend class ParseTreeSerializer;
};

// Pipe EXTEND is represented with an ASTSelect with only the
// SELECT clause present, where the SELECT clause stores the
// EXTEND expression list.
// Using this representation rather than storing an ASTSelectList
// makes sharing resolver code easier.
class ASTPipeExtend final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_EXTEND;

  ASTPipeExtend() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelect* select() const { return select_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    return fl.Finalize();
  }

  const ASTSelect* select_ = nullptr;
};

class ASTPipeRenameItem final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_RENAME_ITEM;

  ASTPipeRenameItem() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* old_name() const { return old_name_; }
  const ASTIdentifier* new_name() const { return new_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&old_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&new_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* old_name_ = nullptr;
  const ASTIdentifier* new_name_ = nullptr;
};

class ASTPipeRename final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_RENAME;

  ASTPipeRename() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPipeRenameItem* const>& rename_item_list() const {
    return rename_item_list_;
  }
  const ASTPipeRenameItem* rename_item_list(int i) const { return rename_item_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&rename_item_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTPipeRenameItem* const> rename_item_list_;
};

// Pipe AGGREGATE is represented with an ASTSelect with only the
// SELECT and (optionally) GROUP BY clause present, where the SELECT
// clause stores the AGGREGATE expression list.
// Using this representation rather than storing an ASTSelectList and
// ASTGroupBy makes sharing resolver code easier.
class ASTPipeAggregate final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_AGGREGATE;

  ASTPipeAggregate() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // If present, the WITH modifier specifying the mode of aggregation
  // (e.g., AGGREGATE WITH DIFFERENTIAL_PRIVACY).
  const ASTWithModifier* with_modifier() const { return with_modifier_; }

  const ASTSelect* select() const { return select_; }

      ABSL_DEPRECATED("Use with_modifier() instead")
      const ASTWithModifier* select_with() const { return with_modifier(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&with_modifier_, AST_WITH_MODIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    return fl.Finalize();
  }

  const ASTWithModifier* with_modifier_ = nullptr;
  const ASTSelect* select_ = nullptr;
};

// Pipe set operations are represented differently from ASTSetOperation
// because we have the set operation and metadata always once, and then
// one or more (not two or more) input queries.
//
// The syntax looks like
//   <input_table> |> UNION ALL [modifiers] (query1), (query2), ...
// and it produces the combination of input_table plus all rhs queries.
class ASTPipeSetOperation final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_SET_OPERATION;

  ASTPipeSetOperation() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSetOperationMetadata* metadata() const { return metadata_; }

  const absl::Span<const ASTQueryExpression* const>& inputs() const {
    return inputs_;
  }
  const ASTQueryExpression* inputs(int i) const { return inputs_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&metadata_));
    fl.AddRestAsRepeated(&inputs_);
    return fl.Finalize();
  }

  const ASTSetOperationMetadata* metadata_ = nullptr;
  absl::Span<const ASTQueryExpression* const> inputs_;
};

// Pipe JOIN is represented with an ASTJoin, where the required lhs
// is always an ASTPipeJoinLhsPlaceholder.
class ASTPipeJoin final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_JOIN;

  ASTPipeJoin() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTJoin* join() const { return join_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&join_));
    return fl.Finalize();
  }

  const ASTJoin* join_ = nullptr;
};

class ASTPipeCall final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_CALL;

  ASTPipeCall() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTVF* tvf() const { return tvf_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&tvf_));
    return fl.Finalize();
  }

  const ASTTVF* tvf_ = nullptr;
};

// Pipe WINDOW is represented with an ASTSelect with only the
// SELECT clause present, where the SELECT clause stores the
// WINDOW expression list.
// Using this representation rather than storing an ASTSelectList
// makes sharing resolver code easier.
class ASTPipeWindow final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_WINDOW;

  ASTPipeWindow() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelect* select() const { return select_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    return fl.Finalize();
  }

  const ASTSelect* select_ = nullptr;
};

class ASTPipeWhere final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_WHERE;

  ASTPipeWhere() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWhereClause* where() const { return where_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&where_));
    return fl.Finalize();
  }

  const ASTWhereClause* where_ = nullptr;
};

// Pipe SELECT is represented with an ASTSelect with only the
// SELECT clause present.
// Using this representation rather than storing an ASTSelectList
// makes sharing resolver code easier.
class ASTPipeSelect final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_SELECT;

  ASTPipeSelect() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelect* select() const { return select_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    return fl.Finalize();
  }

  const ASTSelect* select_ = nullptr;
};

class ASTPipeLimitOffset final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_LIMIT_OFFSET;

  ASTPipeLimitOffset() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTLimitOffset* limit_offset() const { return limit_offset_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&limit_offset_));
    return fl.Finalize();
  }

  const ASTLimitOffset* limit_offset_ = nullptr;
};

class ASTPipeOrderBy final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_ORDER_BY;

  ASTPipeOrderBy() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOrderBy* order_by() const { return order_by_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&order_by_));
    return fl.Finalize();
  }

  const ASTOrderBy* order_by_ = nullptr;
};

class ASTPipeDistinct final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_DISTINCT;

  ASTPipeDistinct() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTPipeTablesample final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_TABLESAMPLE;

  ASTPipeTablesample() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSampleClause* sample() const { return sample_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sample_));
    return fl.Finalize();
  }

  const ASTSampleClause* sample_ = nullptr;
};

class ASTPipeMatchRecognize final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_MATCH_RECOGNIZE;

  ASTPipeMatchRecognize() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTMatchRecognizeClause* match_recognize() const { return match_recognize_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&match_recognize_));
    return fl.Finalize();
  }

  const ASTMatchRecognizeClause* match_recognize_ = nullptr;
};

class ASTPipeAs final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_AS;

  ASTPipeAs() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    return fl.Finalize();
  }

  const ASTAlias* alias_ = nullptr;
};

class ASTPipeDescribe final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_DESCRIBE;

  ASTPipeDescribe() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTPipeStaticDescribe final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_STATIC_DESCRIBE;

  ASTPipeStaticDescribe() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTPipeAssert final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_ASSERT;

  ASTPipeAssert() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* condition() const { return condition_; }

  const absl::Span<const ASTExpression* const>& message_list() const {
    return message_list_;
  }
  const ASTExpression* message_list(int i) const { return message_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    fl.AddRestAsRepeated(&message_list_);
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
  absl::Span<const ASTExpression* const> message_list_;
};

class ASTPipeLog final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_LOG;

  ASTPipeLog() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }
  const ASTSubpipeline* subpipeline() const { return subpipeline_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&subpipeline_, AST_SUBPIPELINE);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTSubpipeline* subpipeline_ = nullptr;
};

class ASTPipeDrop final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_DROP;

  ASTPipeDrop() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifierList* column_list() const { return column_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_list_));
    return fl.Finalize();
  }

  const ASTIdentifierList* column_list_ = nullptr;
};

class ASTPipeSetItem final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_SET_ITEM;

  ASTPipeSetItem() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* column() const { return column_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

class ASTPipeSet final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_SET;

  ASTPipeSet() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPipeSetItem* const>& set_item_list() const {
    return set_item_list_;
  }
  const ASTPipeSetItem* set_item_list(int i) const { return set_item_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&set_item_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTPipeSetItem* const> set_item_list_;
};

class ASTPipePivot final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_PIVOT;

  ASTPipePivot() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPivotClause* pivot_clause() const { return pivot_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&pivot_clause_));
    return fl.Finalize();
  }

  const ASTPivotClause* pivot_clause_ = nullptr;
};

class ASTPipeUnpivot final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_UNPIVOT;

  ASTPipeUnpivot() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTUnpivotClause* unpivot_clause() const { return unpivot_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unpivot_clause_));
    return fl.Finalize();
  }

  const ASTUnpivotClause* unpivot_clause_ = nullptr;
};

// `if_cases` must have at least one item. The first item is the IF case.
// Additional items are ELSEIF cases.
class ASTPipeIf final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_IF;

  ASTPipeIf() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }
  const ASTSubpipeline* else_subpipeline() const { return else_subpipeline_; }

  const absl::Span<const ASTPipeIfCase* const>& if_cases() const {
    return if_cases_;
  }
  const ASTPipeIfCase* if_cases(int i) const { return if_cases_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddRepeatedWhileIsNodeKind(&if_cases_, AST_PIPE_IF_CASE);
    fl.AddOptional(&else_subpipeline_, AST_SUBPIPELINE);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  absl::Span<const ASTPipeIfCase* const> if_cases_;
  const ASTSubpipeline* else_subpipeline_ = nullptr;
};

class ASTPipeIfCase final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_IF_CASE;

  ASTPipeIfCase() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* condition() const { return condition_; }
  const ASTSubpipeline* subpipeline() const { return subpipeline_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&subpipeline_));
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
  const ASTSubpipeline* subpipeline_ = nullptr;
};

class ASTPipeFork final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_FORK;

  ASTPipeFork() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  const absl::Span<const ASTSubpipeline* const>& subpipeline_list() const {
    return subpipeline_list_;
  }
  const ASTSubpipeline* subpipeline_list(int i) const { return subpipeline_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddRestAsRepeated(&subpipeline_list_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  absl::Span<const ASTSubpipeline* const> subpipeline_list_;
};

class ASTPipeTee final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_TEE;

  ASTPipeTee() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  const absl::Span<const ASTSubpipeline* const>& subpipeline_list() const {
    return subpipeline_list_;
  }
  const ASTSubpipeline* subpipeline_list(int i) const { return subpipeline_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddRestAsRepeated(&subpipeline_list_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  absl::Span<const ASTSubpipeline* const> subpipeline_list_;
};

class ASTPipeWith final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_WITH;

  ASTPipeWith() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWithClause* with_clause() const { return with_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&with_clause_));
    return fl.Finalize();
  }

  const ASTWithClause* with_clause_ = nullptr;
};

class ASTPipeExportData final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_EXPORT_DATA;

  ASTPipeExportData() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExportDataStatement* export_data_statement() const { return export_data_statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&export_data_statement_));
    return fl.Finalize();
  }

  const ASTExportDataStatement* export_data_statement_ = nullptr;
};

class ASTPipeCreateTable final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_CREATE_TABLE;

  ASTPipeCreateTable() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTCreateTableStatement* create_table_statement() const { return create_table_statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&create_table_statement_));
    return fl.Finalize();
  }

  const ASTCreateTableStatement* create_table_statement_ = nullptr;
};

class ASTPipeInsert final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_INSERT;

  ASTPipeInsert() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTInsertStatement* insert_statement() const { return insert_statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&insert_statement_));
    return fl.Finalize();
  }

  const ASTInsertStatement* insert_statement_ = nullptr;
};

class ASTSelect final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SELECT;

  ASTSelect() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_distinct(bool distinct) { distinct_ = distinct; }
  bool distinct() const { return distinct_; }

  const ASTHint* hint() const { return hint_; }
  const ASTWithModifier* with_modifier() const { return with_modifier_; }
  const ASTSelectAs* select_as() const { return select_as_; }
  const ASTSelectList* select_list() const { return select_list_; }
  const ASTFromClause* from_clause() const { return from_clause_; }
  const ASTWhereClause* where_clause() const { return where_clause_; }
  const ASTGroupBy* group_by() const { return group_by_; }
  const ASTHaving* having() const { return having_; }
  const ASTQualify* qualify() const { return qualify_; }
  const ASTWindowClause* window_clause() const { return window_clause_; }

      ABSL_DEPRECATED("Use with_modifier() instead")
      const ASTWithModifier* select_with() const { return with_modifier(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&with_modifier_, AST_WITH_MODIFIER);
    fl.AddOptional(&select_as_, AST_SELECT_AS);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_list_));
    fl.AddOptional(&from_clause_, AST_FROM_CLAUSE);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    fl.AddOptional(&group_by_, AST_GROUP_BY);
    fl.AddOptional(&having_, AST_HAVING);
    fl.AddOptional(&qualify_, AST_QUALIFY);
    fl.AddOptional(&window_clause_, AST_WINDOW_CLAUSE);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTWithModifier* with_modifier_ = nullptr;
  bool distinct_ = false;
  const ASTSelectAs* select_as_ = nullptr;
  const ASTSelectList* select_list_ = nullptr;
  const ASTFromClause* from_clause_ = nullptr;
  const ASTWhereClause* where_clause_ = nullptr;
  const ASTGroupBy* group_by_ = nullptr;
  const ASTHaving* having_ = nullptr;
  const ASTQualify* qualify_ = nullptr;
  const ASTWindowClause* window_clause_ = nullptr;
};

// This is the column list in SELECT, containing expressions with optional
// aliases and supporting SELECT-list features like star and dot-star.
//
// This is also used for selection lists in pipe operators, where
// ASTGroupingItemOrder suffixes may be present.
class ASTSelectList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SELECT_LIST;

  ASTSelectList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTSelectColumn* const>& columns() const {
    return columns_;
  }
  const ASTSelectColumn* columns(int i) const { return columns_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&columns_);
    return fl.Finalize();
  }

  absl::Span<const ASTSelectColumn* const> columns_;
};

class ASTSelectColumn final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SELECT_COLUMN;

  ASTSelectColumn() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTAlias* alias() const { return alias_; }

  // This is the ordering suffix {ASC|DESC} [NULLS {FIRST|LAST}].
  // It can only be present on ASTSelectColumns parsed with the
  // `pipe_selection_item_list_with_order` rule, which is
  // currently only the pipe AGGREGATE operator.
  const ASTGroupingItemOrder* grouping_item_order() const { return grouping_item_order_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&grouping_item_order_, AST_GROUPING_ITEM_ORDER);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTGroupingItemOrder* grouping_item_order_ = nullptr;
};

class ASTExpression : public ASTNode {
 public:
  explicit ASTExpression(ASTNodeKind kind) : ASTNode(kind) {}

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  bool IsExpression() const override { return true; }

  // Returns true if this expression is allowed to occur as a child of a
  // comparison expression. This is not allowed for unparenthesized comparison
  // expressions and operators with a lower precedence level (AND, OR, and NOT).
  virtual bool IsAllowedInComparison() const { return true; }

  friend class ParseTreeSerializer;

 private:
  bool parenthesized_ = false;
};

// The name ASTLeaf is kept for backward compatibility alone. However, not
// all subclasses are necessarily leaf nodes. ASTStringLiteral and
// ASTBytesLiteral both have children which are the one or more components
// of literal concatenations. Similarly, ASTDateOrTimeLiteral and
// ASTRangeLiteral each contain a child ASTStringLiteral, which itself is not
// a leaf.
//
// The grouping does not make much sense at this point, given that it
// encompasses not only literals, but also ASTStar.
//
// Its main function was intended to be the nodes that get printed through
// image(), but this is no longer applicable. This functionality is now
// handled by a stricted abstract class ASTPrintableLeaf.
//
// This class should be removed, and subclasses should directly inherit from
// ASTExpression (just as ASTDateOrTimeLiteral does right now). Once all
// callers have been updated as such, we should remove this class from the
// hierarchy and directly inherit from ASTExpression.
class ASTLeaf : public ASTExpression {
 public:
  explicit ASTLeaf(ASTNodeKind kind) : ASTExpression(kind) {}

  bool IsLeaf() const override { return true; }

  friend class ParseTreeSerializer;
};

// Intermediate subclass of ASTLeaf which is the parent of nodes that are
// still using image(). Ideally image() should be hidden, and only used to
// print back to the user, but it is currently being abused in some places
// to represent the value as well, such as with ASTIntLiteral and
// ASTFloatLiteral.
//
// Generally, image() should be removed, and location offsets of the node,
// leaf or not, should be enough to print back the image, for example within
// error messages.
class ASTPrintableLeaf : public ASTLeaf {
 public:
  explicit ASTPrintableLeaf(ASTNodeKind kind) : ASTLeaf(kind) {}

  std::string SingleNodeDebugString() const override;

  // image() references data with the same lifetime as this ASTLeaf object.
  void set_image(std::string image) { image_ = std::move(image); }
  absl::string_view image() const { return image_; }

  friend class ParseTreeSerializer;

 private:
  std::string image_;
};

class ASTIntLiteral final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INT_LITERAL;

  ASTIntLiteral() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  bool is_hex() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTIdentifier final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTIFIER;

  ASTIdentifier() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // Used only by the parser to determine the correct handling of
  // "VALUE" in `SELECT AS VALUE`, as well as time functions like
  // CURRENT_TIMESTAMP() which can be called without parentheses if
  // unquoted. After parsing, this field is completely ignored.
  void set_is_quoted(bool is_quoted) { is_quoted_ = is_quoted; }
  bool is_quoted() const { return is_quoted_; }

  // Set the identifier string.  Input <identifier> is the unquoted identifier.
  // There is no validity checking here.  This assumes the identifier was
  // validated and unquoted in the parser.
  void SetIdentifier(IdString identifier) {
    id_string_ = identifier;
  }

  // Get the unquoted and unescaped string value of this identifier.
  IdString GetAsIdString() const { return id_string_; }
  std::string GetAsString() const { return id_string_.ToString(); }
  absl::string_view GetAsStringView() const {
    return id_string_.ToStringView();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  IdString id_string_;
  bool is_quoted_ = false;
};

class ASTAlias final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIAS;

  ASTAlias() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }

  // Get the unquoted and unescaped string value of this alias.
  std::string GetAsString() const;
  absl::string_view GetAsStringView() const;
  IdString GetAsIdString() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
};

// Parent class that corresponds to the subset of ASTExpression nodes that are
// allowed by the <generalized_path_expression> grammar rule. It allows for some
// extra type safety vs. simply passing around ASTExpression as
// <generalized_path_expression>s.
//
// Only the following node kinds are allowed:
// - AST_PATH_EXPRESSION
// - AST_DOT_GENERALIZED_FIELD where the left hand side is a
//   <generalized_path_expression>.
// - AST_DOT_IDENTIFIER where the left hand side is a
//   <generalized_path_expression>.
// - AST_ARRAY_ELEMENT where the left hand side is a
//   <generalized_path_expression>
//
// Note that the type system does not capture the "pureness constraint" that,
// e.g., the left hand side of an AST_DOT_GENERALIZED_FIELD must be a
// <generalized_path_expression> in order for the node. However, it is still
// considered a bug to create a variable with type ASTGeneralizedPathExpression
// that does not satisfy the pureness constraint (similarly, it is considered a
// bug to call a function with an ASTGeneralizedPathExpression argument that
// does not satisfy the pureness constraint).
class ASTGeneralizedPathExpression : public ASTExpression {
 public:
  explicit ASTGeneralizedPathExpression(ASTNodeKind kind) : ASTExpression(kind) {}

  // Returns an error if 'path' contains a node that cannot come from the
  // <generalized_path_expression> grammar rule. If `node_kind_out` is not
  // nullptr, also updates it with the name of the node that caused the error.
  static absl::Status VerifyIsPureGeneralizedPathExpression(
      const ASTExpression* path,
      std::string* node_kind_out = nullptr);

  friend class ParseTreeSerializer;
};

// This is used for dotted identifier paths only, not dotting into
// arbitrary expressions (see ASTDotIdentifier below).
class ASTPathExpression final : public ASTGeneralizedPathExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PATH_EXPRESSION;

  ASTPathExpression() : ASTGeneralizedPathExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const int num_names() const { return names_.size(); }
  const absl::Span<const ASTIdentifier* const>& names() const {
    return names_;
  }
  const ASTIdentifier* name(int i) const { return names_[i]; }
  const ASTIdentifier* first_name() const { return names_.front(); }
  const ASTIdentifier* last_name() const { return names_.back(); }

  // Return this PathExpression as a dotted SQL identifier string, with
  // quoting if necessary.  If <max_prefix_size> is non-zero, include at most
  // that many identifiers from the prefix of <path>.
  std::string ToIdentifierPathString(size_t max_prefix_size = 0) const;

  // Return the vector of identifier strings (without quoting).
  std::vector<std::string> ToIdentifierVector() const;

  // Similar to ToIdentifierVector(), but returns a vector of IdString's,
  // avoiding the need to make copies.
  std::vector<IdString> ToIdStringVector() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&names_);
    return fl.Finalize();
  }

  absl::Span<const ASTIdentifier* const> names_;
};

// A common superclass for all postfix table operators like TABLESAMPLE.
class ASTPostfixTableOperator : public ASTNode {
 public:
  explicit ASTPostfixTableOperator(ASTNodeKind kind) : ASTNode(kind) {}

  // The name of the operator to show in user-visible error messages.
  virtual absl::string_view Name() const = 0;

  friend class ParseTreeSerializer;
};

// Superclass for all table expressions.  These are things that appear in the
// from clause and produce a stream of rows like a table.
// This includes table scans, joins and subqueries.
class ASTTableExpression : public ASTNode {
 public:
  explicit ASTTableExpression(ASTNodeKind kind) : ASTNode(kind) {}

  const absl::Span<const ASTPostfixTableOperator* const>& postfix_operators() const {
    return postfix_operators_;
  }
  const ASTPostfixTableOperator* postfix_operators(int i) const { return postfix_operators_[i]; }

  bool IsTableExpression() const override { return true; }

  // Return the alias, if the particular subclass has one.
  virtual const ASTAlias* alias() const { return nullptr; }

  // Return the ASTNode location of the alias for this table expression,
  // if applicable.
  const ASTNode* alias_location() const;

  // Compatibility getters until callers are migrated to directly use the list
  // of posfix operators.
  const ASTPivotClause* pivot_clause() const {
    for (const auto* op : postfix_operators()) {
      if (op->node_kind() == AST_PIVOT_CLAUSE) {
        return op->GetAsOrDie<ASTPivotClause>();
      }
    }
    return nullptr;
  }
  const ASTUnpivotClause* unpivot_clause() const {
    for (const auto* op : postfix_operators()) {
      if (op->node_kind() == AST_UNPIVOT_CLAUSE) {
        return op->GetAsOrDie<ASTUnpivotClause>();
      }
    }
    return nullptr;
  }
  const ASTSampleClause* sample_clause() const {
    for (const auto* op : postfix_operators()) {
      if (op->node_kind() == AST_SAMPLE_CLAUSE) {
        return op->GetAsOrDie<ASTSampleClause>();
      }
    }
    return nullptr;
  }

  friend class ParseTreeSerializer;

 protected:
  absl::Span<const ASTPostfixTableOperator* const> postfix_operators_;
};

// TablePathExpression are the TableExpressions that introduce a single scan,
// referenced by a path expression or UNNEST, and can optionally have
// aliases, hints, and WITH OFFSET.
class ASTTablePathExpression final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_PATH_EXPRESSION;

  ASTTablePathExpression() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Exactly one of path_exp or unnest_expr must be non-NULL.
  const ASTPathExpression* path_expr() const { return path_expr_; }

  const ASTUnnestExpression* unnest_expr() const { return unnest_expr_; }
  const ASTHint* hint() const { return hint_; }

  // Present if the scan had WITH OFFSET.
  const ASTWithOffset* with_offset() const { return with_offset_; }

  const ASTForSystemTime* for_system_time() const { return for_system_time_; }

  const ASTAlias* alias() const override { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_expr_, AST_PATH_EXPRESSION);
    fl.AddOptional(&unnest_expr_, AST_UNNEST_EXPRESSION);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&with_offset_, AST_WITH_OFFSET);
    fl.AddOptional(&for_system_time_, AST_FOR_SYSTEM_TIME);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  const ASTPathExpression* path_expr_ = nullptr;
  const ASTUnnestExpression* unnest_expr_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTWithOffset* with_offset_ = nullptr;
  const ASTForSystemTime* for_system_time_ = nullptr;
};

// This is a placehodler ASTTableExpression used for the lhs field in
// the ASTJoin used to represent ASTPipeJoin.
class ASTPipeJoinLhsPlaceholder final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_JOIN_LHS_PLACEHOLDER;

  ASTPipeJoinLhsPlaceholder() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }
};

class ASTFromClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FROM_CLAUSE;

  ASTFromClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // A FromClause has exactly one TableExpression child.
  // If the FROM clause has commas, they will be expressed as a tree
  // of ASTJoin nodes with join_type=COMMA.
  const ASTTableExpression* table_expression() const { return table_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_expression_));
    return fl.Finalize();
  }

  const ASTTableExpression* table_expression_ = nullptr;
};

class ASTWhereClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WHERE_CLAUSE;

  ASTWhereClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

class ASTBooleanLiteral final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BOOLEAN_LITERAL;

  ASTBooleanLiteral() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_value(bool value) { value_ = value; }
  bool value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  bool value_ = false;
};

class ASTAndExpr final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_AND_EXPR;

  ASTAndExpr() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& conjuncts() const {
    return conjuncts_;
  }
  const ASTExpression* conjuncts(int i) const { return conjuncts_[i]; }

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&conjuncts_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> conjuncts_;
};

class ASTBinaryExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BINARY_EXPRESSION;

  ASTBinaryExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTBinaryExpressionEnums::Op in ast_enums.proto
  enum Op {
    NOT_SET = ASTBinaryExpressionEnums::NOT_SET,
    LIKE = ASTBinaryExpressionEnums::LIKE,
    IS = ASTBinaryExpressionEnums::IS,
    EQ = ASTBinaryExpressionEnums::EQ,
    NE = ASTBinaryExpressionEnums::NE,
    NE2 = ASTBinaryExpressionEnums::NE2,
    GT = ASTBinaryExpressionEnums::GT,
    LT = ASTBinaryExpressionEnums::LT,
    GE = ASTBinaryExpressionEnums::GE,
    LE = ASTBinaryExpressionEnums::LE,
    BITWISE_OR = ASTBinaryExpressionEnums::BITWISE_OR,
    BITWISE_XOR = ASTBinaryExpressionEnums::BITWISE_XOR,
    BITWISE_AND = ASTBinaryExpressionEnums::BITWISE_AND,
    PLUS = ASTBinaryExpressionEnums::PLUS,
    MINUS = ASTBinaryExpressionEnums::MINUS,
    MULTIPLY = ASTBinaryExpressionEnums::MULTIPLY,
    DIVIDE = ASTBinaryExpressionEnums::DIVIDE,
    CONCAT_OP = ASTBinaryExpressionEnums::CONCAT_OP,
    DISTINCT = ASTBinaryExpressionEnums::DISTINCT,
    IS_SOURCE_NODE = ASTBinaryExpressionEnums::IS_SOURCE_NODE,
    IS_DEST_NODE = ASTBinaryExpressionEnums::IS_DEST_NODE
  };

  // See description of Op values in ast_enums.proto.
  void set_op(ASTBinaryExpression::Op op) { op_ = op; }
  ASTBinaryExpression::Op op() const { return op_; }

  // Signifies whether the binary operator has a preceding NOT to it.
  // For NOT LIKE and IS NOT.
  void set_is_not(bool is_not) { is_not_ = is_not; }
  bool is_not() const { return is_not_; }

  const ASTExpression* lhs() const { return lhs_; }
  const ASTExpression* rhs() const { return rhs_; }

  // Returns name of the operator in SQL, including the NOT keyword when
  // necessary.
  std::string GetSQLForOperator() const;

  bool IsAllowedInComparison() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&rhs_));
    return fl.Finalize();
  }

  ASTBinaryExpression::Op op_ = ASTBinaryExpression::NOT_SET;
  bool is_not_ = false;
  const ASTExpression* lhs_ = nullptr;
  const ASTExpression* rhs_ = nullptr;
};

// Represents a string literal which could be just a singleton or a whole
// concatenation.
class ASTStringLiteral final : public ASTLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRING_LITERAL;

  ASTStringLiteral() : ASTLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTStringLiteralComponent* const>& components() const {
    return components_;
  }
  const ASTStringLiteralComponent* components(int i) const { return components_[i]; }

  // The parsed and validated value of this literal.
  const std::string& string_value() const { return string_value_; }
  void set_string_value(absl::string_view string_value) {
    string_value_ = std::string(string_value);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsExpression(&components_);
    return fl.Finalize();
  }

  absl::Span<const ASTStringLiteralComponent* const> components_;
  std::string string_value_;
};

class ASTStringLiteralComponent final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRING_LITERAL_COMPONENT;

  ASTStringLiteralComponent() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The parsed and validated value of this literal. The raw input value can be
  // found in image().
  const std::string& string_value() const { return string_value_; }
  void set_string_value(std::string string_value) {
    string_value_ = std::move(string_value);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  std::string string_value_;
};

class ASTStar final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STAR;

  ASTStar() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTOrExpr final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_OR_EXPR;

  ASTOrExpr() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& disjuncts() const {
    return disjuncts_;
  }
  const ASTExpression* disjuncts(int i) const { return disjuncts_[i]; }

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&disjuncts_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> disjuncts_;
};

// Represents a concatenation expression, such as "a || b || c".
class ASTConcatExpr final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CONCAT_EXPR;

  ASTConcatExpr() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& operands() const {
    return operands_;
  }
  const ASTExpression* operands(int i) const { return operands_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&operands_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> operands_;
};

class ASTOrderingExpression final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ORDERING_EXPRESSION;

  ASTOrderingExpression() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTOrderingExpressionEnums::OrderingSpec in ast_enums.proto
  enum OrderingSpec {
    NOT_SET = ASTOrderingExpressionEnums::NOT_SET,
    ASC = ASTOrderingExpressionEnums::ASC,
    DESC = ASTOrderingExpressionEnums::DESC,
    UNSPECIFIED = ASTOrderingExpressionEnums::UNSPECIFIED
  };

  void set_ordering_spec(ASTOrderingExpression::OrderingSpec ordering_spec) { ordering_spec_ = ordering_spec; }
  ASTOrderingExpression::OrderingSpec ordering_spec() const { return ordering_spec_; }

  const ASTExpression* expression() const { return expression_; }
  const ASTCollate* collate() const { return collate_; }
  const ASTNullOrder* null_order() const { return null_order_; }
  const ASTOptionsList* option_list() const { return option_list_; }

  bool descending() const { return ordering_spec_ == DESC; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&null_order_, AST_NULL_ORDER);
    fl.AddOptional(&option_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTCollate* collate_ = nullptr;
  const ASTNullOrder* null_order_ = nullptr;
  ASTOrderingExpression::OrderingSpec ordering_spec_ = ASTOrderingExpression::UNSPECIFIED;
  const ASTOptionsList* option_list_ = nullptr;
};

class ASTOrderBy final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ORDER_BY;

  ASTOrderBy() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  const absl::Span<const ASTOrderingExpression* const>& ordering_expressions() const {
    return ordering_expressions_;
  }
  const ASTOrderingExpression* ordering_expressions(int i) const { return ordering_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddRestAsRepeated(&ordering_expressions_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  absl::Span<const ASTOrderingExpression* const> ordering_expressions_;
};

class ASTGroupingItemOrder final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUPING_ITEM_ORDER;

  ASTGroupingItemOrder() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_ordering_spec(ASTOrderingExpression::OrderingSpec ordering_spec) { ordering_spec_ = ordering_spec; }
  ASTOrderingExpression::OrderingSpec ordering_spec() const { return ordering_spec_; }

  const ASTNullOrder* null_order() const { return null_order_; }

        bool descending() const {
          return ordering_spec_ == ASTOrderingExpression::DESC;
        }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&null_order_, AST_NULL_ORDER);
    return fl.Finalize();
  }

  ASTOrderingExpression::OrderingSpec ordering_spec_ = ASTOrderingExpression::UNSPECIFIED;
  const ASTNullOrder* null_order_ = nullptr;
};

// Represents a grouping item, which is either an expression (a regular
// group by key), or a rollup list, or a cube list, or a grouping set list.
// The item "()", meaning an empty grouping list, is represented as an
// ASTGroupingItem with no children.
class ASTGroupingItem final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUPING_ITEM;

  ASTGroupingItem() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  // A rollup() containing multiple expressions.
  const ASTRollup* rollup() const { return rollup_; }

  // A cube() containing multiple expressions.
  const ASTCube* cube() const { return cube_; }

  // A list of grouping set and each of them is an
  // ASTGroupingSet.
  const ASTGroupingSetList* grouping_set_list() const { return grouping_set_list_; }

  // Alias can only be present for `expression` cases.
  // It can be present but is not valid outside pipe AGGREGATE.
  const ASTAlias* alias() const { return alias_; }

  // Order can only be present for `expression` cases.
  // It can be present but is not valid outside pipe AGGREGATE.
  const ASTGroupingItemOrder* grouping_item_order() const { return grouping_item_order_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    fl.AddOptional(&rollup_, AST_ROLLUP);
    fl.AddOptional(&cube_, AST_CUBE);
    fl.AddOptional(&grouping_set_list_, AST_GROUPING_SET_LIST);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&grouping_item_order_, AST_GROUPING_ITEM_ORDER);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTRollup* rollup_ = nullptr;
  const ASTCube* cube_ = nullptr;
  const ASTGroupingSetList* grouping_set_list_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTGroupingItemOrder* grouping_item_order_ = nullptr;
};

class ASTGroupBy final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUP_BY;

  ASTGroupBy() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // True if query had AND ORDER BY on the GROUP BY.
  void set_and_order_by(bool and_order_by) { and_order_by_ = and_order_by; }
  bool and_order_by() const { return and_order_by_; }

  const ASTHint* hint() const { return hint_; }

  // When `all` is set, it represents syntax: GROUP BY ALL. The syntax
  // is mutually exclusive with syntax GROUP BY `grouping items`, in
  // which case `all` is nullptr and `grouping_items` is non-empty.
  const ASTGroupByAll* all() const { return all_; }

  const absl::Span<const ASTGroupingItem* const>& grouping_items() const {
    return grouping_items_;
  }
  const ASTGroupingItem* grouping_items(int i) const { return grouping_items_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&all_, AST_GROUP_BY_ALL);
    fl.AddRestAsRepeated(&grouping_items_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTGroupByAll* all_ = nullptr;
  absl::Span<const ASTGroupingItem* const> grouping_items_;
  bool and_order_by_ = false;
};

// Wrapper node for the keyword ALL in syntax GROUP BY ALL to provide parse
// location range.
class ASTGroupByAll final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUP_BY_ALL;

  ASTGroupByAll() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Wrapper node for the keyword ALL in syntax LIMIT ALL to provide parse
// location range.
class ASTLimitAll final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LIMIT_ALL;

  ASTLimitAll() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTLimit final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LIMIT;

  ASTLimit() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // When `all` is set, it represents syntax: LIMIT ALL. The syntax is
  // mutually exclusive with syntax LIMIT `expression`, in which case
  // `all` is nullptr and `expression` is non-empty.
  const ASTLimitAll* all() const { return all_; }

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&all_, AST_LIMIT_ALL);
    fl.AddOptionalExpression(&expression_);
    return fl.Finalize();
  }

  const ASTLimitAll* all_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

class ASTLimitOffset final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LIMIT_OFFSET;

  ASTLimitOffset() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The LIMIT value. Never NULL. Either `all` should be set when ALL
  // is specified or `expression` should be set when an expression is
  // specified.
  const ASTLimit* limit() const { return limit_; }

  // The OFFSET value. NULL if no OFFSET specified.
  const ASTExpression* offset() const { return offset_; }

  // Returns the limit expression if it is set, or nullptr otherwise.
  const ASTExpression* limit_expression() const {
    if (limit_->all() != nullptr) {
      return nullptr;
    }
    return limit_->expression();
  }
  // Returns true if LIMIT ALL is used.
  bool has_limit_all() const { return limit_->all() != nullptr; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&limit_));
    fl.AddOptionalExpression(&offset_);
    return fl.Finalize();
  }

  const ASTLimit* limit_ = nullptr;
  const ASTExpression* offset_ = nullptr;
};

class ASTFloatLiteral final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FLOAT_LITERAL;

  ASTFloatLiteral() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTNullLiteral final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NULL_LITERAL;

  ASTNullLiteral() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTOnClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ON_CLAUSE;

  ASTOnClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

class ASTAliasedQuery final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIASED_QUERY;

  ASTAliasedQuery() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* alias() const { return alias_; }
  const ASTQuery* query() const { return query_; }
  const ASTAliasedQueryModifiers* modifiers() const { return modifiers_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_));
    fl.AddOptional(&modifiers_, AST_ALIASED_QUERY_MODIFIERS);
    return fl.Finalize();
  }

  const ASTIdentifier* alias_ = nullptr;
  const ASTQuery* query_ = nullptr;
  const ASTAliasedQueryModifiers* modifiers_ = nullptr;
};

// Joins could introduce multiple scans and cannot have aliases.
// It can also represent a JOIN with a list of consecutive ON/USING
// clauses. Such a JOIN is only for internal use, and will never show up in
// the final parse tree.
class ASTJoin final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_JOIN;

  ASTJoin() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTJoinEnums::JoinType in ast_enums.proto
  enum JoinType {
    DEFAULT_JOIN_TYPE = ASTJoinEnums::DEFAULT_JOIN_TYPE,
    COMMA = ASTJoinEnums::COMMA,
    CROSS = ASTJoinEnums::CROSS,
    FULL = ASTJoinEnums::FULL,
    INNER = ASTJoinEnums::INNER,
    LEFT = ASTJoinEnums::LEFT,
    RIGHT = ASTJoinEnums::RIGHT
  };

  // This enum is equivalent to ASTJoinEnums::JoinHint in ast_enums.proto
  enum JoinHint {
    NO_JOIN_HINT = ASTJoinEnums::NO_JOIN_HINT,
    HASH = ASTJoinEnums::HASH,
    LOOKUP = ASTJoinEnums::LOOKUP
  };

  void set_join_type(ASTJoin::JoinType join_type) { join_type_ = join_type; }
  ASTJoin::JoinType join_type() const { return join_type_; }
  void set_join_hint(ASTJoin::JoinHint join_hint) { join_hint_ = join_hint; }
  ASTJoin::JoinHint join_hint() const { return join_hint_; }
  void set_natural(bool natural) { natural_ = natural; }
  bool natural() const { return natural_; }

  // unmatched_join_count_ and transformation_needed are for internal use for
  // handling consecutive ON/USING clauses. They are not used in the final AST.
  void set_unmatched_join_count(int unmatched_join_count) { unmatched_join_count_ = unmatched_join_count; }
  int unmatched_join_count() const { return unmatched_join_count_; }

  void set_transformation_needed(bool transformation_needed) { transformation_needed_ = transformation_needed; }
  bool transformation_needed() const { return transformation_needed_; }
  void set_contains_comma_join(bool contains_comma_join) { contains_comma_join_ = contains_comma_join; }
  bool contains_comma_join() const { return contains_comma_join_; }

  const ASTTableExpression* lhs() const { return lhs_; }
  const ASTHint* hint() const { return hint_; }
  const ASTLocation* join_location() const { return join_location_; }
  const ASTTableExpression* rhs() const { return rhs_; }
  const ASTOnClause* on_clause() const { return on_clause_; }
  const ASTUsingClause* using_clause() const { return using_clause_; }

  // Represents a parse error when parsing join expressions.
  // See comments in file join_processor.h for more details.
  struct ParseError {
    // The node where the error occurs.
    const ASTNode* error_node;

    std::string message;
  };

  const ParseError* parse_error() const {
    return parse_error_.get();
  }
  void set_parse_error(std::unique_ptr<ParseError> parse_error) {
    parse_error_ = std::move(parse_error);
  }

  // The join type and hint strings
  std::string GetSQLForJoinType() const;
  std::string GetSQLForJoinHint() const;

  void set_join_location(ASTLocation* join_location) {
    join_location_ = join_location;
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    fl.AddOptional(&hint_, AST_HINT);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&join_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&rhs_));
    fl.AddOptional(&on_clause_, AST_ON_CLAUSE);
    fl.AddOptional(&using_clause_, AST_USING_CLAUSE);
    fl.AddOptional(&clause_list_, AST_ON_OR_USING_CLAUSE_LIST);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  const ASTTableExpression* lhs_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTLocation* join_location_ = nullptr;
  const ASTTableExpression* rhs_ = nullptr;
  const ASTOnClause* on_clause_ = nullptr;
  const ASTUsingClause* using_clause_ = nullptr;

  // Note that if consecutive ON/USING clauses are encountered, they are saved
  // as clause_list_, and both on_clause_ and using_clause_ will be nullptr.
  const ASTOnOrUsingClauseList* clause_list_ = nullptr;

  ASTJoin::JoinType join_type_ = ASTJoin::DEFAULT_JOIN_TYPE;
  ASTJoin::JoinHint join_hint_ = ASTJoin::NO_JOIN_HINT;
  bool natural_ = false;

  // The number of qualified joins that do not have a matching ON/USING clause.
  // See the comment in join_processor.cc for details.
  int unmatched_join_count_ = 0;

  // Indicates if this node needs to be transformed. See the comment
  // in join_processor.cc for details.
  // This is true if contains_clause_list_ is true, or if there is a JOIN with
  // ON/USING clause list on the lhs side of the tree path.
  // For internal use only. See the comment in join_processor.cc for details.
  bool transformation_needed_ = false;

  // Indicates whether this join contains a COMMA JOIN on the lhs side of the
  // tree path.
  bool contains_comma_join_ = false;

  std::unique_ptr<ParseError> parse_error_ = nullptr;
};

// This represents an aliased group rows entry in the WITH clause.
class ASTAliasedGroupRows final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIASED_GROUP_ROWS;

  ASTAliasedGroupRows() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    return fl.Finalize();
  }

  const ASTIdentifier* alias_ = nullptr;
};

// This represents a WITH clause entry that must contain either an aliased
// query or a aliased group rows.
//
// All these fields are mutually exclusive, meaning only one of them can be
// populated at a time.
class ASTWithClauseEntry final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_CLAUSE_ENTRY;

  ASTWithClauseEntry() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Custom field getters that ensure only one of the with clause entry fields
  // are populated.
  const ASTAliasedQuery* aliased_query() const;
  const ASTAliasedGroupRows* aliased_group_rows() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&aliased_query_, AST_ALIASED_QUERY);
    fl.AddOptional(&aliased_group_rows_, AST_ALIASED_GROUP_ROWS);
    return fl.Finalize();
  }

  const ASTAliasedQuery* aliased_query_ = nullptr;
  const ASTAliasedGroupRows* aliased_group_rows_ = nullptr;
};

// This represents a WITH clause, which defines one or more named entries
// such as common table expressions (CTEs) via ASTAliasedQuery.
// If `recursive` is true, this is a WITH RECURSIVE clause.
class ASTWithClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_CLAUSE;

  ASTWithClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_recursive(bool recursive) { recursive_ = recursive; }
  bool recursive() const { return recursive_; }

  const absl::Span<const ASTWithClauseEntry* const>& entries() const {
    return entries_;
  }
  const ASTWithClauseEntry* entries(int i) const { return entries_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&entries_);
    return fl.Finalize();
  }

  absl::Span<const ASTWithClauseEntry* const> entries_;
  bool recursive_ = false;
};

class ASTHaving final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HAVING;

  ASTHaving() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

class ASTType : public ASTNode {
 public:
  explicit ASTType(ASTNodeKind kind) : ASTNode(kind) {}

  bool IsType() const override { return true; }

  virtual const ASTTypeParameterList* type_parameters() const = 0;

  virtual const ASTCollate* collate() const = 0;

  friend class ParseTreeSerializer;
};

// TODO This takes a PathExpression and isn't really a simple type.
// Calling this NamedType or TypeName may be more appropriate.
class ASTSimpleType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SIMPLE_TYPE;

  ASTSimpleType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* type_name() const { return type_name_; }
  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_name_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTPathExpression* type_name_ = nullptr;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTArrayType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ARRAY_TYPE;

  ASTArrayType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTType* element_type() const { return element_type_; }
  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const override { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&element_type_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTType* element_type_ = nullptr;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTStructField final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_FIELD;

  ASTStructField() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // name_ will be NULL for anonymous fields like in STRUCT<int, string>.
  const ASTIdentifier* name() const { return name_; }

  const ASTType* type() const { return type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTType* type_ = nullptr;
};

class ASTStructType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_TYPE;

  ASTStructType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const override { return collate_; }

  const absl::Span<const ASTStructField* const>& struct_fields() const {
    return struct_fields_;
  }
  const ASTStructField* struct_fields(int i) const { return struct_fields_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsNodeKind(&struct_fields_, AST_STRUCT_FIELD);
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  absl::Span<const ASTStructField* const> struct_fields_;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTFunctionTypeArgList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_TYPE_ARG_LIST;

  ASTFunctionTypeArgList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTType* const>& args() const {
    return args_;
  }
  const ASTType* args(int i) const { return args_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&args_);
    return fl.Finalize();
  }

  absl::Span<const ASTType* const> args_;
};

class ASTFunctionType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_TYPE;

  ASTFunctionType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTFunctionTypeArgList* arg_list() const { return arg_list_; }
  const ASTType* return_type() const { return return_type_; }
  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const override { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&arg_list_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&return_type_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTFunctionTypeArgList* arg_list_ = nullptr;
  const ASTType* return_type_ = nullptr;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTCastExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CAST_EXPRESSION;

  ASTCastExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_safe_cast(bool is_safe_cast) { is_safe_cast_ = is_safe_cast; }
  bool is_safe_cast() const { return is_safe_cast_; }

  const ASTExpression* expr() const { return expr_; }
  const ASTType* type() const { return type_; }
  const ASTFormatClause* format() const { return format_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    fl.AddOptional(&format_, AST_FORMAT_CLAUSE);
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  const ASTType* type_ = nullptr;
  const ASTFormatClause* format_ = nullptr;
  bool is_safe_cast_ = false;
};

// This represents a SELECT with an AS clause giving it an output type.
//   SELECT AS STRUCT ...
//   SELECT AS VALUE ...
//   SELECT AS <type_name> ...
// Exactly one of these is present.
class ASTSelectAs final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SELECT_AS;

  ASTSelectAs() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTSelectAsEnums::AsMode in ast_enums.proto
  enum AsMode {
    NOT_SET = ASTSelectAsEnums::NOT_SET,
    STRUCT = ASTSelectAsEnums::STRUCT,
    VALUE = ASTSelectAsEnums::VALUE,
    TYPE_NAME = ASTSelectAsEnums::TYPE_NAME
  };

  // Set if as_mode() == kTypeName;
  void set_as_mode(ASTSelectAs::AsMode as_mode) { as_mode_ = as_mode; }
  ASTSelectAs::AsMode as_mode() const { return as_mode_; }

  const ASTPathExpression* type_name() const { return type_name_; }

  bool is_select_as_struct() const { return as_mode_ == STRUCT; }
  bool is_select_as_value() const { return as_mode_ == VALUE; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&type_name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTPathExpression* type_name_ = nullptr;
  ASTSelectAs::AsMode as_mode_ = ASTSelectAs::NOT_SET;
};

class ASTRollup final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROLLUP;

  ASTRollup() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& expressions() const {
    return expressions_;
  }
  const ASTExpression* expressions(int i) const { return expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> expressions_;
};

// Represents a cube list which contains a list of expressions.
class ASTCube final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CUBE;

  ASTCube() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& expressions() const {
    return expressions_;
  }
  const ASTExpression* expressions(int i) const { return expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> expressions_;
};

// Represents a grouping set, which is either an empty grouping set "()",
// or a rollup, or a cube, or an expression.
//
// The expression can be single-level nested to represent a column list,
// e.g. (x, y), it will be represented as an ASTStructConstructorWithParens
// in this case.
class ASTGroupingSet final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUPING_SET;

  ASTGroupingSet() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTRollup* rollup() const { return rollup_; }
  const ASTCube* cube() const { return cube_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    fl.AddOptional(&rollup_, AST_ROLLUP);
    fl.AddOptional(&cube_, AST_CUBE);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTRollup* rollup_ = nullptr;
  const ASTCube* cube_ = nullptr;
};

// Represents a list of grouping set, each grouping set is an ASTGroupingSet.
class ASTGroupingSetList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GROUPING_SET_LIST;

  ASTGroupingSetList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTGroupingSet* const>& grouping_sets() const {
    return grouping_sets_;
  }
  const ASTGroupingSet* grouping_sets(int i) const { return grouping_sets_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&grouping_sets_);
    return fl.Finalize();
  }

  absl::Span<const ASTGroupingSet* const> grouping_sets_;
};

class ASTExpressionWithAlias final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPRESSION_WITH_ALIAS;

  ASTExpressionWithAlias() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

class ASTFunctionCall final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_CALL;

  ASTFunctionCall() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTFunctionCallEnums::NullHandlingModifier in ast_enums.proto
  enum NullHandlingModifier {
    DEFAULT_NULL_HANDLING = ASTFunctionCallEnums::DEFAULT_NULL_HANDLING,
    IGNORE_NULLS = ASTFunctionCallEnums::IGNORE_NULLS,
    RESPECT_NULLS = ASTFunctionCallEnums::RESPECT_NULLS
  };

  // If present, modifies the input behavior of aggregate functions.
  void set_null_handling_modifier(ASTFunctionCall::NullHandlingModifier null_handling_modifier) { null_handling_modifier_ = null_handling_modifier; }
  ASTFunctionCall::NullHandlingModifier null_handling_modifier() const { return null_handling_modifier_; }

  void set_distinct(bool distinct) { distinct_ = distinct; }
  bool distinct() const { return distinct_; }

  // Used by the parser to mark CURRENT_<date/time> functions to which no
  // parentheses have yet been applied.
  void set_is_current_date_time_without_parentheses(bool is_current_date_time_without_parentheses) { is_current_date_time_without_parentheses_ = is_current_date_time_without_parentheses; }
  bool is_current_date_time_without_parentheses() const { return is_current_date_time_without_parentheses_; }

  // If true, this function was called with chained call syntax.
  // For example,
  //   `(base_expression).function_call(args)`
  // which is semantically similar to
  //   `function_call(base_expression, args)`
  //
  // `arguments` must have at least one element.  The first element is the
  // base expression.
  void set_is_chained_call(bool is_chained_call) { is_chained_call_ = is_chained_call; }
  bool is_chained_call() const { return is_chained_call_; }

  const ASTPathExpression* function() const { return function_; }
  const ASTWhereClause* where_expr() const { return where_expr_; }
  const ASTHavingModifier* having_modifier() const { return having_modifier_; }
  const ASTGroupBy* group_by() const { return group_by_; }
  const ASTHaving* having_expr() const { return having_expr_; }

  // If present, applies to the inputs of anonymized aggregate functions.
  const ASTClampedBetweenModifier* clamped_between_modifier() const { return clamped_between_modifier_; }

  // If present, the report modifier applies to the result of anonymized
  // aggregate functions.
  const ASTWithReportModifier* with_report_modifier() const { return with_report_modifier_; }

  // If present, applies to the inputs of aggregate functions.
  const ASTOrderBy* order_by() const { return order_by_; }

  // If present, this applies to the inputs of aggregate functions.
  const ASTLimitOffset* limit_offset() const { return limit_offset_; }

  // hint if not null.
  const ASTHint* hint() const { return hint_; }

  const absl::Span<const ASTExpression* const>& arguments() const {
    return arguments_;
  }
  const ASTExpression* arguments(int i) const { return arguments_[i]; }

  // Convenience method that returns true if any modifiers are set. Useful for
  // places in the resolver where function call syntax is used for purposes
  // other than a function call (e.g., <array>[OFFSET(<expr>) or WEEK(MONDAY)]).
  // Ignore `is_chained_call` if `ignore_is_chained_call` is true.
  bool HasModifiers(bool ignore_is_chained_call=false) const {
    return distinct_ || null_handling_modifier_ != DEFAULT_NULL_HANDLING ||
           having_modifier_ != nullptr ||
           clamped_between_modifier_ != nullptr || order_by_ != nullptr ||
           limit_offset_ != nullptr || group_by_ != nullptr ||
           where_expr_ != nullptr || having_expr_ != nullptr ||
           with_report_modifier_ != nullptr ||
           (is_chained_call_ && !ignore_is_chained_call);
  }

  // Return the number of optional modifiers present on this call.
  // Callers can use this to check that there are no unsupported modifiers by
  // checking that the number of supported modifiers that are present and
  // handled is equal to NumModifiers().
  int NumModifiers() const {
    return
         (distinct_ ? 1 : 0) +
         (null_handling_modifier_ != DEFAULT_NULL_HANDLING  ? 1 : 0) +
         (having_modifier_ != nullptr  ? 1 : 0) +
         (clamped_between_modifier_ != nullptr  ? 1 : 0) +
         (order_by_ != nullptr  ? 1 : 0) +
         (limit_offset_ != nullptr  ? 1 : 0) +
         (group_by_ != nullptr  ? 1 : 0) +
         (where_expr_ != nullptr  ? 1 : 0) +
         (having_expr_ != nullptr  ? 1 : 0) +
         (with_report_modifier_ != nullptr  ? 1 : 0) +
         (is_chained_call_ ? 1 : 0);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&function_));
    fl.AddRepeatedWhileIsExpression(&arguments_);
    fl.AddOptional(&where_expr_, AST_WHERE_CLAUSE);
    fl.AddOptional(&having_modifier_, AST_HAVING_MODIFIER);
    fl.AddOptional(&group_by_, AST_GROUP_BY);
    fl.AddOptional(&having_expr_, AST_HAVING);
    fl.AddOptional(&clamped_between_modifier_, AST_CLAMPED_BETWEEN_MODIFIER);
    fl.AddOptional(&with_report_modifier_, AST_WITH_REPORT_MODIFIER);
    fl.AddOptional(&order_by_, AST_ORDER_BY);
    fl.AddOptional(&limit_offset_, AST_LIMIT_OFFSET);
    fl.AddOptional(&hint_, AST_HINT);
    return fl.Finalize();
  }

  const ASTPathExpression* function_ = nullptr;
  absl::Span<const ASTExpression* const> arguments_;

  // Set if the function was called with FUNC(args WHERE expr).
  const ASTWhereClause* where_expr_ = nullptr;

  // Set if the function was called with FUNC(args HAVING {MAX|MIN} expr).
  const ASTHavingModifier* having_modifier_ = nullptr;

  // Set if the function was called with FUNC(args GROUP BY expr [, ... ]).
  const ASTGroupBy* group_by_ = nullptr;

  // Set if the function was called with FUNC(args group_by HAVING expr).
  const ASTHaving* having_expr_ = nullptr;

  // Set if the function was called with
  // FUNC(args CLAMPED BETWEEN low AND high).
  const ASTClampedBetweenModifier* clamped_between_modifier_ = nullptr;

  // Set if the function was called with
  // FUNC(args WITH REPORT).
  const ASTWithReportModifier* with_report_modifier_ = nullptr;

  // Set if the function was called with FUNC(args ORDER BY cols).
  const ASTOrderBy* order_by_ = nullptr;

  // Set if the function was called with FUNC(args LIMIT N).
  const ASTLimitOffset* limit_offset_ = nullptr;

  // Optional hint.
  const ASTHint* hint_ = nullptr;

  // Set if the function was called with FUNC(args {IGNORE|RESPECT} NULLS).
  ASTFunctionCall::NullHandlingModifier null_handling_modifier_ = ASTFunctionCall::DEFAULT_NULL_HANDLING;

  // True if the function was called with FUNC(DISTINCT args).
  bool distinct_ = false;

  // This is set by the parser to indicate a parentheses-less call to
  // CURRENT_* functions. The parser parses them as function calls even without
  // the parentheses, but then still allows function call parentheses to be
  // applied.
  bool is_current_date_time_without_parentheses_ = false;

  bool is_chained_call_ = false;
};

class ASTChainedBaseExpr final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CHAINED_BASE_EXPR;

  ASTChainedBaseExpr() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
};

class ASTArrayConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ARRAY_CONSTRUCTOR;

  ASTArrayConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // May return NULL. Occurs only if the array is constructed through
  // ARRAY<type>[...] syntax and not ARRAY[...] or [...].
  const ASTArrayType* type() const { return type_; }

  const absl::Span<const ASTExpression* const>& elements() const {
    return elements_;
  }
  const ASTExpression* elements(int i) const { return elements_[i]; }

  // DEPRECATED - use elements(int i)
  const ASTExpression* element(int i) const { return elements_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&type_, AST_ARRAY_TYPE);
    fl.AddRestAsRepeated(&elements_);
    return fl.Finalize();
  }

  const ASTArrayType* type_ = nullptr;
  absl::Span<const ASTExpression* const> elements_;
};

class ASTStructConstructorArg final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_CONSTRUCTOR_ARG;

  ASTStructConstructorArg() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

// This node results from structs constructed with (expr, expr, ...).
// This will only occur when there are at least two expressions.
class ASTStructConstructorWithParens final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_CONSTRUCTOR_WITH_PARENS;

  ASTStructConstructorWithParens() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& field_expressions() const {
    return field_expressions_;
  }
  const ASTExpression* field_expressions(int i) const { return field_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&field_expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> field_expressions_;
};

// This node results from structs constructed with the STRUCT keyword.
//   STRUCT(expr [AS alias], ...)
//   STRUCT<...>(expr [AS alias], ...)
// Both forms support empty field lists.
// The struct_type_ child will be non-NULL for the second form,
// which includes the struct's field list.
class ASTStructConstructorWithKeyword final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_CONSTRUCTOR_WITH_KEYWORD;

  ASTStructConstructorWithKeyword() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStructType* struct_type() const { return struct_type_; }

  const absl::Span<const ASTStructConstructorArg* const>& fields() const {
    return fields_;
  }
  const ASTStructConstructorArg* fields(int i) const { return fields_[i]; }

  // Deprecated - use fields(int i)
  const ASTStructConstructorArg* field(int idx) const { return fields_[idx]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&struct_type_, AST_STRUCT_TYPE);
    fl.AddRestAsRepeated(&fields_);
    return fl.Finalize();
  }

  // May be NULL.
  const ASTStructType* struct_type_ = nullptr;

  absl::Span<const ASTStructConstructorArg* const> fields_;
};

class ASTInExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IN_EXPRESSION;

  ASTInExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // Signifies whether the IN operator has a preceding NOT to it.
  void set_is_not(bool is_not) { is_not_ = is_not; }
  bool is_not() const { return is_not_; }

  const ASTExpression* lhs() const { return lhs_; }

  // Represents the location of the 'IN' token. Used only for error
  // messages.
  const ASTLocation* in_location() const { return in_location_; }

  // Hints specified on IN clause.
  // This can be set only if IN clause has subquery as RHS.
  const ASTHint* hint() const { return hint_; }

  // Exactly one of in_list, query or unnest_expr is present.
  const ASTInList* in_list() const { return in_list_; }

  const ASTQuery* query() const { return query_; }
  const ASTUnnestExpression* unnest_expr() const { return unnest_expr_; }

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&in_location_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&in_list_, AST_IN_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&unnest_expr_, AST_UNNEST_EXPRESSION);
    return fl.Finalize();
  }

  // Expression for which we need to verify whether its resolved result matches
  // any of the resolved results of the expressions present in the in_list_.
  const ASTExpression* lhs_ = nullptr;

  const ASTLocation* in_location_ = nullptr;

  // Hints specified on IN clause
  const ASTHint* hint_ = nullptr;

  // List of expressions to check against for the presence of lhs_.
  const ASTInList* in_list_ = nullptr;

  // Query returns the row values to check against for the presence of lhs_.
  const ASTQuery* query_ = nullptr;

  // Check if lhs_ is an element of the array value inside Unnest.
  const ASTUnnestExpression* unnest_expr_ = nullptr;

  bool is_not_ = false;
};

// This implementation is shared with the IN operator and LIKE ANY/SOME/ALL.
class ASTInList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IN_LIST;

  ASTInList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& list() const {
    return list_;
  }
  const ASTExpression* list(int i) const { return list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&list_);
    return fl.Finalize();
  }

  // List of expressions present in the InList node.
  absl::Span<const ASTExpression* const> list_;
};

class ASTBetweenExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BETWEEN_EXPRESSION;

  ASTBetweenExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // Signifies whether the BETWEEN operator has a preceding NOT to it.
  void set_is_not(bool is_not) { is_not_ = is_not; }
  bool is_not() const { return is_not_; }

  const ASTExpression* lhs() const { return lhs_; }

  // Represents the location of the 'BETWEEN' token. Used only for
  // error messages.
  const ASTLocation* between_location() const { return between_location_; }

  const ASTExpression* low() const { return low_; }
  const ASTExpression* high() const { return high_; }

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&between_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&low_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&high_));
    return fl.Finalize();
  }

  // Represents <lhs_> BETWEEN <low_> AND <high_>
  const ASTExpression* lhs_ = nullptr;

  const ASTLocation* between_location_ = nullptr;
  const ASTExpression* low_ = nullptr;
  const ASTExpression* high_ = nullptr;
  bool is_not_ = false;
};

class ASTNumericLiteral final : public ASTLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NUMERIC_LITERAL;

  ASTNumericLiteral() : ASTLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStringLiteral* string_literal() const { return string_literal_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&string_literal_));
    return fl.Finalize();
  }

  const ASTStringLiteral* string_literal_ = nullptr;
};

class ASTBigNumericLiteral final : public ASTLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BIGNUMERIC_LITERAL;

  ASTBigNumericLiteral() : ASTLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStringLiteral* string_literal() const { return string_literal_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&string_literal_));
    return fl.Finalize();
  }

  const ASTStringLiteral* string_literal_ = nullptr;
};

// Represents a bytes literal which could be just a singleton or a whole
// concatenation.
class ASTBytesLiteral final : public ASTLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BYTES_LITERAL;

  ASTBytesLiteral() : ASTLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTBytesLiteralComponent* const>& components() const {
    return components_;
  }
  const ASTBytesLiteralComponent* components(int i) const { return components_[i]; }

  // The parsed and validated value of this literal.
  const std::string& bytes_value() const { return bytes_value_; }
  void set_bytes_value(std::string bytes_value) {
    bytes_value_ = std::move(bytes_value);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsExpression(&components_);
    return fl.Finalize();
  }

  absl::Span<const ASTBytesLiteralComponent* const> components_;
  std::string bytes_value_;
};

class ASTBytesLiteralComponent final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BYTES_LITERAL_COMPONENT;

  ASTBytesLiteralComponent() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The parsed and validated value of this literal. The raw input value can be
  // found in image().
  const std::string& bytes_value() const { return bytes_value_; }
  void set_bytes_value(std::string bytes_value) {
    bytes_value_ = std::move(bytes_value);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
  std::string bytes_value_;
};

class ASTDateOrTimeLiteral final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DATE_OR_TIME_LITERAL;

  ASTDateOrTimeLiteral() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_type_kind(TypeKind type_kind) { type_kind_ = type_kind; }
  TypeKind type_kind() const { return type_kind_; }

  const ASTStringLiteral* string_literal() const { return string_literal_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&string_literal_));
    return fl.Finalize();
  }

  const ASTStringLiteral* string_literal_ = nullptr;
  TypeKind type_kind_ = TYPE_UNKNOWN;
};

// This represents the value MAX that shows up in type parameter lists.
// It will not show up as a general expression anywhere else.
class ASTMaxLiteral final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MAX_LITERAL;

  ASTMaxLiteral() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTJSONLiteral final : public ASTLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_JSON_LITERAL;

  ASTJSONLiteral() : ASTLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStringLiteral* string_literal() const { return string_literal_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&string_literal_));
    return fl.Finalize();
  }

  const ASTStringLiteral* string_literal_ = nullptr;
};

class ASTCaseValueExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CASE_VALUE_EXPRESSION;

  ASTCaseValueExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& arguments() const {
    return arguments_;
  }
  const ASTExpression* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> arguments_;
};

class ASTCaseNoValueExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CASE_NO_VALUE_EXPRESSION;

  ASTCaseNoValueExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& arguments() const {
    return arguments_;
  }
  const ASTExpression* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> arguments_;
};

class ASTArrayElement final : public ASTGeneralizedPathExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ARRAY_ELEMENT;

  ASTArrayElement() : ASTGeneralizedPathExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* array() const { return array_; }
  const ASTLocation* open_bracket_location() const { return open_bracket_location_; }
  const ASTExpression* position() const { return position_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&array_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&open_bracket_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&position_));
    return fl.Finalize();
  }

  const ASTExpression* array_ = nullptr;
  const ASTLocation* open_bracket_location_ = nullptr;
  const ASTExpression* position_ = nullptr;
};

class ASTBitwiseShiftExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BITWISE_SHIFT_EXPRESSION;

  ASTBitwiseShiftExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // Signifies whether the bitwise shift is of left shift type "<<" or right
  // shift type ">>".
  void set_is_left_shift(bool is_left_shift) { is_left_shift_ = is_left_shift; }
  bool is_left_shift() const { return is_left_shift_; }

  const ASTExpression* lhs() const { return lhs_; }
  const ASTLocation* operator_location() const { return operator_location_; }
  const ASTExpression* rhs() const { return rhs_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&operator_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&rhs_));
    return fl.Finalize();
  }

  const ASTExpression* lhs_ = nullptr;
  const ASTLocation* operator_location_ = nullptr;
  const ASTExpression* rhs_ = nullptr;
  bool is_left_shift_ = false;
};

class ASTCollate final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLLATE;

  ASTCollate() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* collation_name() const { return collation_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&collation_name_));
    return fl.Finalize();
  }

  const ASTExpression* collation_name_ = nullptr;
};

// This is a generalized form of extracting a field from an expression.
// It uses a parenthesized path_expression instead of a single identifier
// to select the field.
class ASTDotGeneralizedField final : public ASTGeneralizedPathExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DOT_GENERALIZED_FIELD;

  ASTDotGeneralizedField() : ASTGeneralizedPathExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }
  const ASTPathExpression* path() const { return path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_));
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  const ASTPathExpression* path_ = nullptr;
};

// This is used for using dot to extract a field from an arbitrary expression.
// In cases where we know the left side is always an identifier path, we
// use ASTPathExpression instead.
class ASTDotIdentifier final : public ASTGeneralizedPathExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DOT_IDENTIFIER;

  ASTDotIdentifier() : ASTGeneralizedPathExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }
  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  const ASTIdentifier* name_ = nullptr;
};

class ASTDotStar final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DOT_STAR;

  ASTDotStar() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
};

// SELECT x.* EXCEPT(...) REPLACE(...).  See (broken link).
class ASTDotStarWithModifiers final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DOT_STAR_WITH_MODIFIERS;

  ASTDotStarWithModifiers() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }
  const ASTStarModifiers* modifiers() const { return modifiers_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&modifiers_));
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  const ASTStarModifiers* modifiers_ = nullptr;
};

// A subquery in an expression.  (Not in the FROM clause.)
class ASTExpressionSubquery final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPRESSION_SUBQUERY;

  ASTExpressionSubquery() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTExpressionSubqueryEnums::Modifier in ast_enums.proto
  enum Modifier {
    NONE = ASTExpressionSubqueryEnums::NONE,
    ARRAY = ASTExpressionSubqueryEnums::ARRAY,
    EXISTS = ASTExpressionSubqueryEnums::EXISTS,
    VALUE = ASTExpressionSubqueryEnums::VALUE
  };

  // The syntactic modifier on this expression subquery.
  void set_modifier(ASTExpressionSubquery::Modifier modifier) { modifier_ = modifier; }
  ASTExpressionSubquery::Modifier modifier() const { return modifier_; }

  const ASTHint* hint() const { return hint_; }
  const ASTQuery* query() const { return query_; }

  static std::string ModifierToString(Modifier modifier);

  // Note, this is intended by called from inside the parser.  At this stage
  // InitFields has _not_ been set, thus we need to use only children offsets.
  // Returns null on error.
  ASTQuery* GetMutableQueryChildInternal() {
    if (num_children() == 1) {
      return mutable_child(0)->GetAsOrNull<ASTQuery>();
    } else if (num_children() == 2) {
      // Hint is the first child.
      return mutable_child(1)->GetAsOrNull<ASTQuery>();
    } else {
      return nullptr;
    }
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_));
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTQuery* query_ = nullptr;
  ASTExpressionSubquery::Modifier modifier_ = ASTExpressionSubquery::NONE;
};

class ASTExtractExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXTRACT_EXPRESSION;

  ASTExtractExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* lhs_expr() const { return lhs_expr_; }
  const ASTExpression* rhs_expr() const { return rhs_expr_; }
  const ASTExpression* time_zone_expr() const { return time_zone_expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_expr_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&rhs_expr_));
    fl.AddOptionalExpression(&time_zone_expr_);
    return fl.Finalize();
  }

  const ASTExpression* lhs_expr_ = nullptr;
  const ASTExpression* rhs_expr_ = nullptr;
  const ASTExpression* time_zone_expr_ = nullptr;
};

class ASTHavingModifier final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HAVING_MODIFIER;

  ASTHavingModifier() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTHavingModifierEnums::ModifierKind in ast_enums.proto
  enum ModifierKind {
    NOT_SET = ASTHavingModifierEnums::NOT_SET,
    MIN = ASTHavingModifierEnums::MIN,
    MAX = ASTHavingModifierEnums::MAX
  };

  void set_modifier_kind(ASTHavingModifier::ModifierKind modifier_kind) { modifier_kind_ = modifier_kind; }
  ASTHavingModifier::ModifierKind modifier_kind() const { return modifier_kind_; }

  const ASTExpression* expr() const { return expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    return fl.Finalize();
  }

  // The expression MAX or MIN applies to. Never NULL.
  const ASTExpression* expr_ = nullptr;

  ASTHavingModifier::ModifierKind modifier_kind_ = ASTHavingModifier::MAX;
};

class ASTIntervalExpr final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INTERVAL_EXPR;

  ASTIntervalExpr() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* interval_value() const { return interval_value_; }
  const ASTIdentifier* date_part_name() const { return date_part_name_; }
  const ASTIdentifier* date_part_name_to() const { return date_part_name_to_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&interval_value_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&date_part_name_));
    fl.AddOptional(&date_part_name_to_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTExpression* interval_value_ = nullptr;
  const ASTIdentifier* date_part_name_ = nullptr;
  const ASTIdentifier* date_part_name_to_ = nullptr;
};

// This represents a clause of form "SEQUENCE <target>", where <target> is a
// sequence name.
class ASTSequenceArg final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SEQUENCE_ARG;

  ASTSequenceArg() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* sequence_path() const { return sequence_path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sequence_path_));
    return fl.Finalize();
  }

  const ASTPathExpression* sequence_path_ = nullptr;
};

// Represents a named function call argument using syntax: name => expression.
// The resolver will match these against available argument names in the
// function signature.
class ASTNamedArgument final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NAMED_ARGUMENT;

  ASTNamedArgument() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }
  const ASTExpression* expr() const { return expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    return fl.Finalize();
  }

  // Required, never NULL.
  const ASTIdentifier* name_ = nullptr;

  // Required, never NULL.
  const ASTExpression* expr_ = nullptr;
};

// This node represents the keywords INPUT TABLE, used as a TVF argument.
class ASTInputTableArgument final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INPUT_TABLE_ARGUMENT;

  ASTInputTableArgument() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTNullOrder final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NULL_ORDER;

  ASTNullOrder() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_nulls_first(bool nulls_first) { nulls_first_ = nulls_first; }
  bool nulls_first() const { return nulls_first_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  bool nulls_first_ = false;
};

class ASTOnOrUsingClauseList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ON_OR_USING_CLAUSE_LIST;

  ASTOnOrUsingClauseList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTNode* const>& on_or_using_clause_list() const {
    return on_or_using_clause_list_;
  }
  const ASTNode* on_or_using_clause_list(int i) const { return on_or_using_clause_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&on_or_using_clause_list_);
    return fl.Finalize();
  }

  // Each element in the list must be either ASTOnClause or ASTUsingClause.
  absl::Span<const ASTNode* const> on_or_using_clause_list_;
};

class ASTParenthesizedJoin final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PARENTHESIZED_JOIN;

  ASTParenthesizedJoin() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTJoin* join() const { return join_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&join_));
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  // Required.
  const ASTJoin* join_ = nullptr;
};

class ASTPartitionBy final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PARTITION_BY;

  ASTPartitionBy() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  const absl::Span<const ASTExpression* const>& partitioning_expressions() const {
    return partitioning_expressions_;
  }
  const ASTExpression* partitioning_expressions(int i) const { return partitioning_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddRestAsRepeated(&partitioning_expressions_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  absl::Span<const ASTExpression* const> partitioning_expressions_;
};

class ASTSetOperation final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION;

  ASTSetOperation() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTSetOperationEnums::OperationType in ast_enums.proto
  enum OperationType {
    NOT_SET = ASTSetOperationEnums::NOT_SET,
    UNION = ASTSetOperationEnums::UNION,
    EXCEPT = ASTSetOperationEnums::EXCEPT,
    INTERSECT = ASTSetOperationEnums::INTERSECT
  };

  // This enum is equivalent to ASTSetOperationEnums::AllOrDistinct in ast_enums.proto
  enum AllOrDistinct {
    ALL_OR_DISTINCT_NOT_SET = ASTSetOperationEnums::ALL_OR_DISTINCT_NOT_SET,
    ALL = ASTSetOperationEnums::ALL,
    DISTINCT = ASTSetOperationEnums::DISTINCT
  };

  // This enum is equivalent to ASTSetOperationEnums::ColumnMatchMode in ast_enums.proto
  enum ColumnMatchMode {
    BY_POSITION = ASTSetOperationEnums::BY_POSITION,
    CORRESPONDING = ASTSetOperationEnums::CORRESPONDING,
    CORRESPONDING_BY = ASTSetOperationEnums::CORRESPONDING_BY,
    BY_NAME = ASTSetOperationEnums::BY_NAME,
    BY_NAME_ON = ASTSetOperationEnums::BY_NAME_ON
  };

  // This enum is equivalent to ASTSetOperationEnums::ColumnPropagationMode in ast_enums.proto
  enum ColumnPropagationMode {
    STRICT = ASTSetOperationEnums::STRICT,
    INNER = ASTSetOperationEnums::INNER,
    LEFT = ASTSetOperationEnums::LEFT,
    FULL = ASTSetOperationEnums::FULL
  };

  const ASTSetOperationMetadataList* metadata() const { return metadata_; }

  const absl::Span<const ASTQueryExpression* const>& inputs() const {
    return inputs_;
  }
  const ASTQueryExpression* inputs(int i) const { return inputs_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&metadata_));
    fl.AddRestAsRepeated(&inputs_);
    return fl.Finalize();
  }

  const ASTSetOperationMetadataList* metadata_ = nullptr;
  absl::Span<const ASTQueryExpression* const> inputs_;
};

// Contains the list of metadata for each set operation. Note the parser
// range of this node can span the inner SELECT clauses, if any. For example,
// for the following SQL query:
//   ```
//   SELECT 1
//   UNION ALL
//   SELECT 2
//   UNION ALL
//   SELECT 3
//   ```
// the parser range of `ASTSetOperationMetadataList` starts from the first
// "UNION ALL" to the last "UNION ALL", including the "SELECT 2" in middle.
class ASTSetOperationMetadataList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_METADATA_LIST;

  ASTSetOperationMetadataList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTSetOperationMetadata* const>& set_operation_metadata_list() const {
    return set_operation_metadata_list_;
  }
  const ASTSetOperationMetadata* set_operation_metadata_list(int i) const { return set_operation_metadata_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&set_operation_metadata_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTSetOperationMetadata* const> set_operation_metadata_list_;
};

// Wrapper node for the enum ASTSetOperation::AllOrDistinct to provide parse
// location range.
class ASTSetOperationAllOrDistinct final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_ALL_OR_DISTINCT;

  ASTSetOperationAllOrDistinct() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_value(ASTSetOperation::AllOrDistinct value) { value_ = value; }
  ASTSetOperation::AllOrDistinct value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTSetOperation::AllOrDistinct value_ = ASTSetOperation::ALL;
};

// Wrapper node for the enum ASTSetOperation::OperationType to provide parse
// location range.
class ASTSetOperationType final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_TYPE;

  ASTSetOperationType() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_value(ASTSetOperation::OperationType value) { value_ = value; }
  ASTSetOperation::OperationType value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTSetOperation::OperationType value_ = ASTSetOperation::NOT_SET;
};

// Wrapper node for the enum ASTSetOperation::ColumnMatchMode to provide
// parse location range.
class ASTSetOperationColumnMatchMode final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_COLUMN_MATCH_MODE;

  ASTSetOperationColumnMatchMode() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_value(ASTSetOperation::ColumnMatchMode value) { value_ = value; }
  ASTSetOperation::ColumnMatchMode value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTSetOperation::ColumnMatchMode value_ = ASTSetOperation::BY_POSITION;
};

// Wrapper node for the enum ASTSetOperation::ColumnPropagationMode to
// provide parse location range.
class ASTSetOperationColumnPropagationMode final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_COLUMN_PROPAGATION_MODE;

  ASTSetOperationColumnPropagationMode() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_value(ASTSetOperation::ColumnPropagationMode value) { value_ = value; }
  ASTSetOperation::ColumnPropagationMode value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTSetOperation::ColumnPropagationMode value_ = ASTSetOperation::STRICT;
};

class ASTSetOperationMetadata final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPERATION_METADATA;

  ASTSetOperationMetadata() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSetOperationType* op_type() const { return op_type_; }
  const ASTSetOperationAllOrDistinct* all_or_distinct() const { return all_or_distinct_; }
  const ASTHint* hint() const { return hint_; }
  const ASTSetOperationColumnMatchMode* column_match_mode() const { return column_match_mode_; }
  const ASTSetOperationColumnPropagationMode* column_propagation_mode() const { return column_propagation_mode_; }

  // Stores the column list for the CORRESPONDING BY clause, only
  // populated when `column_match_mode` = CORRESPONDING_BY.
  const ASTColumnList* corresponding_by_column_list() const { return corresponding_by_column_list_; }

      // Returns a SQL string representation for the metadata.
      std::string GetSQLForOperation() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&op_type_, AST_SET_OPERATION_TYPE);
    fl.AddOptional(&all_or_distinct_, AST_SET_OPERATION_ALL_OR_DISTINCT);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&column_match_mode_, AST_SET_OPERATION_COLUMN_MATCH_MODE);
    fl.AddOptional(&column_propagation_mode_, AST_SET_OPERATION_COLUMN_PROPAGATION_MODE);
    fl.AddOptional(&corresponding_by_column_list_, AST_COLUMN_LIST);
    return fl.Finalize();
  }

  const ASTSetOperationType* op_type_ = nullptr;
  const ASTSetOperationAllOrDistinct* all_or_distinct_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTSetOperationColumnMatchMode* column_match_mode_ = nullptr;
  const ASTSetOperationColumnPropagationMode* column_propagation_mode_ = nullptr;
  const ASTColumnList* corresponding_by_column_list_ = nullptr;
};

class ASTStarExceptList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STAR_EXCEPT_LIST;

  ASTStarExceptList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTIdentifier* const>& identifiers() const {
    return identifiers_;
  }
  const ASTIdentifier* identifiers(int i) const { return identifiers_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&identifiers_);
    return fl.Finalize();
  }

  absl::Span<const ASTIdentifier* const> identifiers_;
};

// SELECT * EXCEPT(...) REPLACE(...).  See (broken link).
class ASTStarModifiers final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STAR_MODIFIERS;

  ASTStarModifiers() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStarExceptList* except_list() const { return except_list_; }

  const absl::Span<const ASTStarReplaceItem* const>& replace_items() const {
    return replace_items_;
  }
  const ASTStarReplaceItem* replace_items(int i) const { return replace_items_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&except_list_, AST_STAR_EXCEPT_LIST);
    fl.AddRestAsRepeated(&replace_items_);
    return fl.Finalize();
  }

  const ASTStarExceptList* except_list_ = nullptr;
  absl::Span<const ASTStarReplaceItem* const> replace_items_;
};

class ASTStarReplaceItem final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STAR_REPLACE_ITEM;

  ASTStarReplaceItem() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTIdentifier* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alias_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTIdentifier* alias_ = nullptr;
};

// SELECT * EXCEPT(...) REPLACE(...).  See (broken link).
class ASTStarWithModifiers final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STAR_WITH_MODIFIERS;

  ASTStarWithModifiers() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStarModifiers* modifiers() const { return modifiers_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&modifiers_));
    return fl.Finalize();
  }

  const ASTStarModifiers* modifiers_ = nullptr;
};

class ASTTableSubquery final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_SUBQUERY;

  ASTTableSubquery() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_lateral(bool is_lateral) { is_lateral_ = is_lateral; }
  bool is_lateral() const { return is_lateral_; }

  const ASTQuery* subquery() const { return subquery_; }

  const ASTAlias* alias() const override { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&subquery_));
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  const ASTQuery* subquery_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  bool is_lateral_ = false;
};

class ASTUnaryExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNARY_EXPRESSION;

  ASTUnaryExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTUnaryExpressionEnums::Op in ast_enums.proto
  enum Op {
    NOT_SET = ASTUnaryExpressionEnums::NOT_SET,
    NOT = ASTUnaryExpressionEnums::NOT,
    BITWISE_NOT = ASTUnaryExpressionEnums::BITWISE_NOT,
    MINUS = ASTUnaryExpressionEnums::MINUS,
    PLUS = ASTUnaryExpressionEnums::PLUS,
    IS_UNKNOWN = ASTUnaryExpressionEnums::IS_UNKNOWN,
    IS_NOT_UNKNOWN = ASTUnaryExpressionEnums::IS_NOT_UNKNOWN
  };

  void set_op(ASTUnaryExpression::Op op) { op_ = op; }
  ASTUnaryExpression::Op op() const { return op_; }

  const ASTExpression* operand() const { return operand_; }

  bool IsAllowedInComparison() const override {
    return parenthesized() || op_ != NOT;
  }

  std::string GetSQLForOperator() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&operand_));
    return fl.Finalize();
  }

  const ASTExpression* operand_ = nullptr;
  ASTUnaryExpression::Op op_ = ASTUnaryExpression::NOT_SET;
};

class ASTExpressionWithOptAlias final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPRESSION_WITH_OPT_ALIAS;

  ASTExpressionWithOptAlias() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTAlias* optional_alias() const { return optional_alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&optional_alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* optional_alias_ = nullptr;
};

class ASTUnnestExpression final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNNEST_EXPRESSION;

  ASTUnnestExpression() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTNamedArgument* array_zip_mode() const { return array_zip_mode_; }

  // Grammar guarantees `expressions_` is not empty.
  const absl::Span<const ASTExpressionWithOptAlias* const>& expressions() const {
    return expressions_;
  }
  const ASTExpressionWithOptAlias* expressions(int i) const { return expressions_[i]; }

      ABSL_DEPRECATED("Use `expressions()` instead")
      inline const ASTExpression* expression() const {
          return expressions()[0]->expression();
      }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsNodeKind(&expressions_, AST_EXPRESSION_WITH_OPT_ALIAS);
    fl.AddOptional(&array_zip_mode_, AST_NAMED_ARGUMENT);
    return fl.Finalize();
  }

  absl::Span<const ASTExpressionWithOptAlias* const> expressions_;
  const ASTNamedArgument* array_zip_mode_ = nullptr;
};

class ASTWindowClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WINDOW_CLAUSE;

  ASTWindowClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTWindowDefinition* const>& windows() const {
    return windows_;
  }
  const ASTWindowDefinition* windows(int i) const { return windows_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&windows_);
    return fl.Finalize();
  }

  absl::Span<const ASTWindowDefinition* const> windows_;
};

class ASTWindowDefinition final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WINDOW_DEFINITION;

  ASTWindowDefinition() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }
  const ASTWindowSpecification* window_spec() const { return window_spec_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&window_spec_));
    return fl.Finalize();
  }

  // Required, never NULL.
  const ASTIdentifier* name_ = nullptr;

  // Required, never NULL.
  const ASTWindowSpecification* window_spec_ = nullptr;
};

class ASTWindowFrame final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WINDOW_FRAME;

  ASTWindowFrame() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTWindowFrameEnums::FrameUnit in ast_enums.proto
  enum FrameUnit {
    ROWS = ASTWindowFrameEnums::ROWS,
    RANGE = ASTWindowFrameEnums::RANGE
  };

  const ASTWindowFrameExpr* start_expr() const { return start_expr_; }
  const ASTWindowFrameExpr* end_expr() const { return end_expr_; }

  void set_unit(FrameUnit frame_unit) { frame_unit_ = frame_unit; }
  FrameUnit frame_unit() const { return frame_unit_; }

  std::string GetFrameUnitString() const;

  static std::string FrameUnitToString(FrameUnit unit);

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&start_expr_));
    fl.AddOptional(&end_expr_, AST_WINDOW_FRAME_EXPR);
    return fl.Finalize();
  }

  // Starting boundary expression. Never NULL.
  const ASTWindowFrameExpr* start_expr_ = nullptr;

  // Ending boundary expression. Can be NULL.
  // When this is NULL, the implicit ending boundary is CURRENT ROW.
  const ASTWindowFrameExpr* end_expr_ = nullptr;

  ASTWindowFrame::FrameUnit frame_unit_ = ASTWindowFrame::RANGE;
};

class ASTWindowFrameExpr final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WINDOW_FRAME_EXPR;

  ASTWindowFrameExpr() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTWindowFrameExprEnums::BoundaryType in ast_enums.proto
  enum BoundaryType {
    UNBOUNDED_PRECEDING = ASTWindowFrameExprEnums::UNBOUNDED_PRECEDING,
    OFFSET_PRECEDING = ASTWindowFrameExprEnums::OFFSET_PRECEDING,
    CURRENT_ROW = ASTWindowFrameExprEnums::CURRENT_ROW,
    OFFSET_FOLLOWING = ASTWindowFrameExprEnums::OFFSET_FOLLOWING,
    UNBOUNDED_FOLLOWING = ASTWindowFrameExprEnums::UNBOUNDED_FOLLOWING
  };

  void set_boundary_type(ASTWindowFrameExpr::BoundaryType boundary_type) { boundary_type_ = boundary_type; }
  ASTWindowFrameExpr::BoundaryType boundary_type() const { return boundary_type_; }

  const ASTExpression* expression() const { return expression_; }

  std::string GetBoundaryTypeString() const;
  static std::string BoundaryTypeToString(BoundaryType type);

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    return fl.Finalize();
  }

  // Expression to specify the boundary as a logical or physical offset
  // to current row. Cannot be NULL if boundary_type is OFFSET_PRECEDING
  // or OFFSET_FOLLOWING; otherwise, should be NULL.
  const ASTExpression* expression_ = nullptr;

  ASTWindowFrameExpr::BoundaryType boundary_type_ = ASTWindowFrameExpr::UNBOUNDED_PRECEDING;
};

// Represents a LIKE expression with an ANY, ALL, or SOME quantifier.
class ASTLikeExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LIKE_EXPRESSION;

  ASTLikeExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // Signifies whether the LIKE operator has a preceding NOT.
  void set_is_not(bool is_not) { is_not_ = is_not; }
  bool is_not() const { return is_not_; }

  // Expression being compared to the in_list, query, or unnest_expr.
  const ASTExpression* lhs() const { return lhs_; }

  // Location of the 'LIKE' token. Used for error messages.
  const ASTLocation* like_location() const { return like_location_; }

  // The ANY, SOME, or ALL quantifier used.
  const ASTAnySomeAllOp* op() const { return op_; }

  // Hints specified on LIKE clause.
  // This can be set only if the RHS is a subquery.
  const ASTHint* hint() const { return hint_; }

  // Exactly one of in_list, query, or unnest_expr is present.
  // List of expressions to compare with lhs.
  const ASTInList* in_list() const { return in_list_; }

  // Query returning row values to compare with lhs.
  const ASTQuery* query() const { return query_; }

  // Array expression whose elements are to be compared with lhs.
  const ASTUnnestExpression* unnest_expr() const { return unnest_expr_; }

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&like_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&op_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&in_list_, AST_IN_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&unnest_expr_, AST_UNNEST_EXPRESSION);
    return fl.Finalize();
  }

  const ASTExpression* lhs_ = nullptr;
  const ASTLocation* like_location_ = nullptr;
  const ASTAnySomeAllOp* op_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTInList* in_list_ = nullptr;
  const ASTQuery* query_ = nullptr;
  const ASTUnnestExpression* unnest_expr_ = nullptr;
  bool is_not_ = false;
};

// Represents a comparison expression with a quantifier,
// like `x = ANY (a, b, c)`.
class ASTQuantifiedComparisonExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_QUANTIFIED_COMPARISON_EXPRESSION;

  ASTQuantifiedComparisonExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // The comparison operator.
  // See description of Op values in ast_enums.proto.
  // A subset are supported: `=`, `!=`, `<>`, `<`, `<=`, `>`, `>=`.
  void set_op(ASTBinaryExpression::Op op) { op_ = op; }
  ASTBinaryExpression::Op op() const { return op_; }

  // Expression being compared to the in_list, query, or unnest_expr.
  const ASTExpression* lhs() const { return lhs_; }

  const ASTLocation* op_location() const { return op_location_; }

  // The ANY, SOME, or ALL quantifier used.
  const ASTAnySomeAllOp* quantifier() const { return quantifier_; }

  // Hints specified on subquery.
  // This can be set only if the RHS is a subquery.
  const ASTHint* hint() const { return hint_; }

  // Exactly one of in_list, query or unnest_expr is present.
  // List of expressions to compare with lhs.
  const ASTInList* in_list() const { return in_list_; }

  // Query returning row values to compare with lhs.
  const ASTQuery* query() const { return query_; }

  // Array expression whose elements are to be compared with lhs.
  const ASTUnnestExpression* unnest_expr() const { return unnest_expr_; }

  // Returns name of the operator in SQL.
  std::string GetSQLForOperator() const;

  bool IsAllowedInComparison() const override { return parenthesized(); }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&op_location_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&quantifier_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&in_list_, AST_IN_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&unnest_expr_, AST_UNNEST_EXPRESSION);
    return fl.Finalize();
  }

  const ASTExpression* lhs_ = nullptr;
  ASTBinaryExpression::Op op_ = ASTBinaryExpression::NOT_SET;

  // Location of the comparison operator. Used for error messages.
  const ASTLocation* op_location_ = nullptr;

  const ASTAnySomeAllOp* quantifier_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTInList* in_list_ = nullptr;
  const ASTQuery* query_ = nullptr;
  const ASTUnnestExpression* unnest_expr_ = nullptr;
};

class ASTWindowSpecification final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WINDOW_SPECIFICATION;

  ASTWindowSpecification() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* base_window_name() const { return base_window_name_; }
  const ASTPartitionBy* partition_by() const { return partition_by_; }
  const ASTOrderBy* order_by() const { return order_by_; }
  const ASTWindowFrame* window_frame() const { return window_frame_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&base_window_name_, AST_IDENTIFIER);
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&order_by_, AST_ORDER_BY);
    fl.AddOptional(&window_frame_, AST_WINDOW_FRAME);
    return fl.Finalize();
  }

  // All fields are optional, can be NULL.
  const ASTIdentifier* base_window_name_ = nullptr;

  const ASTPartitionBy* partition_by_ = nullptr;
  const ASTOrderBy* order_by_ = nullptr;
  const ASTWindowFrame* window_frame_ = nullptr;
};

class ASTWithOffset final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_OFFSET;

  ASTWithOffset() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // alias may be NULL.
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTAlias* alias_ = nullptr;
};

class ASTAnySomeAllOp final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ANY_SOME_ALL_OP;

  ASTAnySomeAllOp() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTAnySomeAllOpEnums::Op in ast_enums.proto
  enum Op {
    kUninitialized = ASTAnySomeAllOpEnums::kUninitialized,
    kAny = ASTAnySomeAllOpEnums::kAny,
    kSome = ASTAnySomeAllOpEnums::kSome,
    kAll = ASTAnySomeAllOpEnums::kAll
  };

  void set_op(ASTAnySomeAllOp::Op op) { op_ = op; }
  ASTAnySomeAllOp::Op op() const { return op_; }

  std::string GetSQLForOperator() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTAnySomeAllOp::Op op_ = ASTAnySomeAllOp::kUninitialized;
};

class ASTParameterExprBase : public ASTExpression {
 public:
  explicit ASTParameterExprBase(ASTNodeKind kind) : ASTExpression(kind) {}

  friend class ParseTreeSerializer;
};

// Contains a list of statements.  Variable declarations allowed only at the
// start of the list, and only if variable_declarations_allowed() is true.
class ASTStatementList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STATEMENT_LIST;

  ASTStatementList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_variable_declarations_allowed(bool variable_declarations_allowed) { variable_declarations_allowed_ = variable_declarations_allowed; }
  bool variable_declarations_allowed() const { return variable_declarations_allowed_; }

  const absl::Span<const ASTStatement* const>& statement_list() const {
    return statement_list_;
  }
  const ASTStatement* statement_list(int i) const { return statement_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&statement_list_);
    return fl.Finalize();
  }

  // Repeated
  absl::Span<const ASTStatement* const> statement_list_;

  bool variable_declarations_allowed_ = false;
};

class ASTScriptStatement : public ASTStatement {
 public:
  explicit ASTScriptStatement(ASTNodeKind kind) : ASTStatement(kind) {}

  bool IsScriptStatement() const final { return true; }
  bool IsSqlStatement() const override { return false; }

  friend class ParseTreeSerializer;
};

// This wraps any other statement to add statement-level hints.
class ASTHintedStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HINTED_STATEMENT;

  ASTHintedStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }
  const ASTStatement* statement() const { return statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&hint_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_));
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTStatement* statement_ = nullptr;
};

// This wraps another statement, adding pipe operators on the end.
//
// The parser doesn't use this for ASTQueryStatement or other nodes that
// can include pipe operator suffixes themselves.
//
// This can only occur if FEATURE_STATEMENT_WITH_PIPE_OPERATORS is set.
//
// These pipe suffixes are generally not handled by the analyzer, and must
// be processed by the engine.  See (broken link).
class ASTStatementWithPipeOperators final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STATEMENT_WITH_PIPE_OPERATORS;

  ASTStatementWithPipeOperators() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStatement* statement() const { return statement_; }
  const ASTSubpipelineStatement* pipe_operator_suffix() const { return pipe_operator_suffix_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_));
    fl.AddOptional(&pipe_operator_suffix_, AST_SUBPIPELINE_STATEMENT);
    return fl.Finalize();
  }

  const ASTStatement* statement_ = nullptr;
  const ASTSubpipelineStatement* pipe_operator_suffix_ = nullptr;
};

// Represents an EXPLAIN statement.
class ASTExplainStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPLAIN_STATEMENT;

  ASTExplainStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStatement* statement() const { return statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_));
    return fl.Finalize();
  }

  const ASTStatement* statement_ = nullptr;
};

// Represents a DESCRIBE statement.
class ASTDescribeStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DESCRIBE_STATEMENT;

  ASTDescribeStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* optional_identifier() const { return optional_identifier_; }
  const ASTPathExpression* name() const { return name_; }
  const ASTPathExpression* optional_from_name() const { return optional_from_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&optional_identifier_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&optional_from_name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTIdentifier* optional_identifier_ = nullptr;
  const ASTPathExpression* name_ = nullptr;
  const ASTPathExpression* optional_from_name_ = nullptr;
};

// Represents a SHOW statement.
class ASTShowStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SHOW_STATEMENT;

  ASTShowStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }
  const ASTPathExpression* optional_name() const { return optional_name_; }
  const ASTStringLiteral* optional_like_string() const { return optional_like_string_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    fl.AddOptional(&optional_name_, AST_PATH_EXPRESSION);
    fl.AddOptional(&optional_like_string_, AST_STRING_LITERAL);
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  const ASTPathExpression* optional_name_ = nullptr;
  const ASTStringLiteral* optional_like_string_ = nullptr;
};

// Base class transaction modifier elements.
class ASTTransactionMode : public ASTNode {
 public:
  explicit ASTTransactionMode(ASTNodeKind kind) : ASTNode(kind) {}

  friend class ParseTreeSerializer;
};

class ASTTransactionIsolationLevel final : public ASTTransactionMode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TRANSACTION_ISOLATION_LEVEL;

  ASTTransactionIsolationLevel() : ASTTransactionMode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier1() const { return identifier1_; }

  // Second identifier can be non-null only if first identifier is non-null.
  const ASTIdentifier* identifier2() const { return identifier2_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&identifier1_, AST_IDENTIFIER);
    fl.AddOptional(&identifier2_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTIdentifier* identifier1_ = nullptr;
  const ASTIdentifier* identifier2_ = nullptr;
};

class ASTTransactionReadWriteMode final : public ASTTransactionMode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TRANSACTION_READ_WRITE_MODE;

  ASTTransactionReadWriteMode() : ASTTransactionMode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTTransactionReadWriteModeEnums::Mode in ast_enums.proto
  enum Mode {
    INVALID = ASTTransactionReadWriteModeEnums::INVALID,
    READ_ONLY = ASTTransactionReadWriteModeEnums::READ_ONLY,
    READ_WRITE = ASTTransactionReadWriteModeEnums::READ_WRITE
  };

  void set_mode(ASTTransactionReadWriteMode::Mode mode) { mode_ = mode; }
  ASTTransactionReadWriteMode::Mode mode() const { return mode_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTTransactionReadWriteMode::Mode mode_ = ASTTransactionReadWriteMode::INVALID;
};

class ASTTransactionModeList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TRANSACTION_MODE_LIST;

  ASTTransactionModeList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTTransactionMode* const>& elements() const {
    return elements_;
  }
  const ASTTransactionMode* elements(int i) const { return elements_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&elements_);
    return fl.Finalize();
  }

  absl::Span<const ASTTransactionMode* const> elements_;
};

// Represents a BEGIN or START TRANSACTION statement.
class ASTBeginStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BEGIN_STATEMENT;

  ASTBeginStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTransactionModeList* mode_list() const { return mode_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&mode_list_, AST_TRANSACTION_MODE_LIST);
    return fl.Finalize();
  }

  const ASTTransactionModeList* mode_list_ = nullptr;
};

// Represents a SET TRANSACTION statement.
class ASTSetTransactionStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_TRANSACTION_STATEMENT;

  ASTSetTransactionStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTransactionModeList* mode_list() const { return mode_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&mode_list_));
    return fl.Finalize();
  }

  const ASTTransactionModeList* mode_list_ = nullptr;
};

// Represents a COMMIT statement.
class ASTCommitStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COMMIT_STATEMENT;

  ASTCommitStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Represents a ROLLBACK statement.
class ASTRollbackStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROLLBACK_STATEMENT;

  ASTRollbackStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTStartBatchStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_START_BATCH_STATEMENT;

  ASTStartBatchStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* batch_type() const { return batch_type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&batch_type_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTIdentifier* batch_type_ = nullptr;
};

class ASTRunBatchStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RUN_BATCH_STATEMENT;

  ASTRunBatchStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTAbortBatchStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ABORT_BATCH_STATEMENT;

  ASTAbortBatchStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Common superclass of DDL statements.
class ASTDdlStatement : public ASTStatement {
 public:
  explicit ASTDdlStatement(ASTNodeKind kind) : ASTStatement(kind) {}

  bool IsDdlStatement() const override { return true; }

  virtual const ASTPathExpression* GetDdlTarget() const = 0;

  friend class ParseTreeSerializer;
};

// Generic DROP statement (broken link).
class ASTDropEntityStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_ENTITY_STATEMENT;

  ASTDropEntityStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* entity_type() const { return entity_type_; }
  const ASTPathExpression* name() const { return name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&entity_type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* entity_type_ = nullptr;
  const ASTPathExpression* name_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP FUNCTION statement.
class ASTDropFunctionStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_FUNCTION_STATEMENT;

  ASTDropFunctionStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTFunctionParameters* parameters() const { return parameters_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&parameters_, AST_FUNCTION_PARAMETERS);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTFunctionParameters* parameters_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP TABLE FUNCTION statement.
// Note: Table functions don't support overloading so function parameters are
//       not accepted in this statement.
//       (broken link)
class ASTDropTableFunctionStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_TABLE_FUNCTION_STATEMENT;

  ASTDropTableFunctionStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* name() const { return name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP ALL ROW ACCESS POLICIES statement.
class ASTDropAllRowAccessPoliciesStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_ALL_ROW_ACCESS_POLICIES_STATEMENT;

  ASTDropAllRowAccessPoliciesStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_has_access_keyword(bool has_access_keyword) { has_access_keyword_ = has_access_keyword; }
  bool has_access_keyword() const { return has_access_keyword_; }

  const ASTPathExpression* table_name() const { return table_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_));
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_ = nullptr;
  bool has_access_keyword_ = false;
};

// Represents a DROP MATERIALIZED VIEW statement.
class ASTDropMaterializedViewStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_MATERIALIZED_VIEW_STATEMENT;

  ASTDropMaterializedViewStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* name() const { return name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP SNAPSHOT TABLE statement.
class ASTDropSnapshotTableStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_SNAPSHOT_TABLE_STATEMENT;

  ASTDropSnapshotTableStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* name() const { return name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP SEARCH|VECTOR INDEX statement. It is different from the
// regular drop index in that it has a trailing "ON PATH" clause.
class ASTDropIndexStatement : public ASTDdlStatement {
 public:
  explicit ASTDropIndexStatement(ASTNodeKind kind) : ASTDdlStatement(kind) {}

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTPathExpression* table_name() const { return table_name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* name_ = nullptr;
  const ASTPathExpression* table_name_ = nullptr;
  bool is_if_exists_ = false;
};

// Represents a DROP SEARCH INDEX statement.
class ASTDropSearchIndexStatement final : public ASTDropIndexStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_SEARCH_INDEX_STATEMENT;

  ASTDropSearchIndexStatement() : ASTDropIndexStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&table_name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }
};

// Represents a DROP VECTOR INDEX statement.
class ASTDropVectorIndexStatement final : public ASTDropIndexStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_VECTOR_INDEX_STATEMENT;

  ASTDropVectorIndexStatement() : ASTDropIndexStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&table_name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }
};

// Represents a RENAME statement.
class ASTRenameStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RENAME_STATEMENT;

  ASTRenameStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }
  const ASTPathExpression* old_name() const { return old_name_; }
  const ASTPathExpression* new_name() const { return new_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&old_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&new_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  const ASTPathExpression* old_name_ = nullptr;
  const ASTPathExpression* new_name_ = nullptr;
};

// Represents an IMPORT statement, which currently support MODULE or PROTO
// kind. We want this statement to be a generic import at some point.
class ASTImportStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IMPORT_STATEMENT;

  ASTImportStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTImportStatementEnums::ImportKind in ast_enums.proto
  enum ImportKind {
    MODULE = ASTImportStatementEnums::MODULE,
    PROTO = ASTImportStatementEnums::PROTO
  };

  void set_import_kind(ASTImportStatement::ImportKind import_kind) { import_kind_ = import_kind; }
  ASTImportStatement::ImportKind import_kind() const { return import_kind_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTStringLiteral* string_value() const { return string_value_; }
  const ASTAlias* alias() const { return alias_; }
  const ASTIntoAlias* into_alias() const { return into_alias_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_PATH_EXPRESSION);
    fl.AddOptional(&string_value_, AST_STRING_LITERAL);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&into_alias_, AST_INTO_ALIAS);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  // Exactly one of 'name_' or 'string_value_' will be populated.
  const ASTPathExpression* name_ = nullptr;

  const ASTStringLiteral* string_value_ = nullptr;

  // At most one of 'alias_' or 'into_alias_' will be populated.
  const ASTAlias* alias_ = nullptr;

  const ASTIntoAlias* into_alias_ = nullptr;

  // May be NULL.
  const ASTOptionsList* options_list_ = nullptr;

  ASTImportStatement::ImportKind import_kind_ = ASTImportStatement::MODULE;
};

class ASTModuleStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MODULE_STATEMENT;

  ASTModuleStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;

  // May be NULL
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTWithConnectionClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_CONNECTION_CLAUSE;

  ASTWithConnectionClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTConnectionClause* connection_clause() const { return connection_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&connection_clause_));
    return fl.Finalize();
  }

  const ASTConnectionClause* connection_clause_ = nullptr;
};

class ASTIntoAlias final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INTO_ALIAS;

  ASTIntoAlias() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }

  // Get the unquoted and unescaped string value of this alias.
  std::string GetAsString() const;
  absl::string_view GetAsStringView() const;
  IdString GetAsIdString() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
};

// A conjunction of the unnest expression and the optional alias and offset.
class ASTUnnestExpressionWithOptAliasAndOffset final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNNEST_EXPRESSION_WITH_OPT_ALIAS_AND_OFFSET;

  ASTUnnestExpressionWithOptAliasAndOffset() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTUnnestExpression* unnest_expression() const { return unnest_expression_; }
  const ASTAlias* optional_alias() const { return optional_alias_; }
  const ASTWithOffset* optional_with_offset() const { return optional_with_offset_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unnest_expression_));
    fl.AddOptional(&optional_alias_, AST_ALIAS);
    fl.AddOptional(&optional_with_offset_, AST_WITH_OFFSET);
    return fl.Finalize();
  }

  const ASTUnnestExpression* unnest_expression_ = nullptr;
  const ASTAlias* optional_alias_ = nullptr;
  const ASTWithOffset* optional_with_offset_ = nullptr;
};

class ASTPivotExpression final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIVOT_EXPRESSION;

  ASTPivotExpression() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

class ASTPivotValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIVOT_VALUE;

  ASTPivotValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* value() const { return value_; }
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTExpression* value_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

class ASTPivotExpressionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIVOT_EXPRESSION_LIST;

  ASTPivotExpressionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPivotExpression* const>& expressions() const {
    return expressions_;
  }
  const ASTPivotExpression* expressions(int i) const { return expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTPivotExpression* const> expressions_;
};

class ASTPivotValueList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIVOT_VALUE_LIST;

  ASTPivotValueList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPivotValue* const>& values() const {
    return values_;
  }
  const ASTPivotValue* values(int i) const { return values_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&values_);
    return fl.Finalize();
  }

  absl::Span<const ASTPivotValue* const> values_;
};

class ASTPivotClause final : public ASTPostfixTableOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIVOT_CLAUSE;

  ASTPivotClause() : ASTPostfixTableOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPivotExpressionList* pivot_expressions() const { return pivot_expressions_; }
  const ASTExpression* for_expression() const { return for_expression_; }
  const ASTPivotValueList* pivot_values() const { return pivot_values_; }
  const ASTAlias* output_alias() const { return output_alias_; }

  absl::string_view Name() const override { return "PIVOT"; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&pivot_expressions_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&for_expression_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&pivot_values_));
    fl.AddOptional(&output_alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTPivotExpressionList* pivot_expressions_ = nullptr;
  const ASTExpression* for_expression_ = nullptr;
  const ASTPivotValueList* pivot_values_ = nullptr;
  const ASTAlias* output_alias_ = nullptr;
};

class ASTUnpivotInItem final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNPIVOT_IN_ITEM;

  ASTUnpivotInItem() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpressionList* unpivot_columns() const { return unpivot_columns_; }
  const ASTUnpivotInItemLabel* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unpivot_columns_));
    fl.AddOptional(&alias_, AST_UNPIVOT_IN_ITEM_LABEL);
    return fl.Finalize();
  }

  const ASTPathExpressionList* unpivot_columns_ = nullptr;
  const ASTUnpivotInItemLabel* alias_ = nullptr;
};

class ASTUnpivotInItemList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNPIVOT_IN_ITEM_LIST;

  ASTUnpivotInItemList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTUnpivotInItem* const>& in_items() const {
    return in_items_;
  }
  const ASTUnpivotInItem* in_items(int i) const { return in_items_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&in_items_);
    return fl.Finalize();
  }

  absl::Span<const ASTUnpivotInItem* const> in_items_;
};

class ASTUnpivotClause final : public ASTPostfixTableOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNPIVOT_CLAUSE;

  ASTUnpivotClause() : ASTPostfixTableOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTUnpivotClauseEnums::NullFilter in ast_enums.proto
  enum NullFilter {
    kUnspecified = ASTUnpivotClauseEnums::kUnspecified,
    kInclude = ASTUnpivotClauseEnums::kInclude,
    kExclude = ASTUnpivotClauseEnums::kExclude
  };

  void set_null_filter(ASTUnpivotClause::NullFilter null_filter) { null_filter_ = null_filter; }
  ASTUnpivotClause::NullFilter null_filter() const { return null_filter_; }

  const ASTPathExpressionList* unpivot_output_value_columns() const { return unpivot_output_value_columns_; }
  const ASTPathExpression* unpivot_output_name_column() const { return unpivot_output_name_column_; }
  const ASTUnpivotInItemList* unpivot_in_items() const { return unpivot_in_items_; }
  const ASTAlias* output_alias() const { return output_alias_; }

  std::string GetSQLForNullFilter() const;
  absl::string_view Name() const override { return "UNPIVOT"; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unpivot_output_value_columns_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unpivot_output_name_column_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&unpivot_in_items_));
    fl.AddOptional(&output_alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTPathExpressionList* unpivot_output_value_columns_ = nullptr;
  const ASTPathExpression* unpivot_output_name_column_ = nullptr;
  const ASTUnpivotInItemList* unpivot_in_items_ = nullptr;
  const ASTAlias* output_alias_ = nullptr;
  ASTUnpivotClause::NullFilter null_filter_ = ASTUnpivotClause::kUnspecified;
};

class ASTUsingClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_USING_CLAUSE;

  ASTUsingClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTIdentifier* const>& keys() const {
    return keys_;
  }
  const ASTIdentifier* keys(int i) const { return keys_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&keys_);
    return fl.Finalize();
  }

  absl::Span<const ASTIdentifier* const> keys_;
};

class ASTForSystemTime final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOR_SYSTEM_TIME;

  ASTForSystemTime() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

// Represents a row pattern recognition clause, i.e., MATCH_RECOGNIZE().
class ASTMatchRecognizeClause final : public ASTPostfixTableOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MATCH_RECOGNIZE_CLAUSE;

  ASTMatchRecognizeClause() : ASTPostfixTableOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTPartitionBy* partition_by() const { return partition_by_; }
  const ASTOrderBy* order_by() const { return order_by_; }
  const ASTSelectList* measures() const { return measures_; }
  const ASTAfterMatchSkipClause* after_match_skip_clause() const { return after_match_skip_clause_; }
  const ASTRowPatternExpression* pattern() const { return pattern_; }
  const ASTSelectList* pattern_variable_definition_list() const { return pattern_variable_definition_list_; }
  const ASTAlias* output_alias() const { return output_alias_; }

  absl::string_view Name() const override { return "MATCH_RECOGNIZE"; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&order_by_, AST_ORDER_BY);
    fl.AddOptional(&measures_, AST_SELECT_LIST);
    fl.AddOptional(&after_match_skip_clause_, AST_AFTER_MATCH_SKIP_CLAUSE);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&pattern_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&pattern_variable_definition_list_));
    fl.AddOptional(&output_alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTOptionsList* options_list_ = nullptr;
  const ASTPartitionBy* partition_by_ = nullptr;
  const ASTOrderBy* order_by_ = nullptr;
  const ASTSelectList* measures_ = nullptr;
  const ASTAfterMatchSkipClause* after_match_skip_clause_ = nullptr;
  const ASTRowPatternExpression* pattern_ = nullptr;
  const ASTSelectList* pattern_variable_definition_list_ = nullptr;
  const ASTAlias* output_alias_ = nullptr;
};

class ASTAfterMatchSkipClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_AFTER_MATCH_SKIP_CLAUSE;

  ASTAfterMatchSkipClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTAfterMatchSkipClauseEnums::AfterMatchSkipTargetType in ast_enums.proto
  enum AfterMatchSkipTargetType {
    AFTER_MATCH_SKIP_TARGET_UNSPECIFIED = ASTAfterMatchSkipClauseEnums::AFTER_MATCH_SKIP_TARGET_UNSPECIFIED,
    PAST_LAST_ROW = ASTAfterMatchSkipClauseEnums::PAST_LAST_ROW,
    TO_NEXT_ROW = ASTAfterMatchSkipClauseEnums::TO_NEXT_ROW
  };

  void set_target_type(ASTAfterMatchSkipClause::AfterMatchSkipTargetType target_type) { target_type_ = target_type; }
  ASTAfterMatchSkipClause::AfterMatchSkipTargetType target_type() const { return target_type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTAfterMatchSkipClause::AfterMatchSkipTargetType target_type_ = ASTAfterMatchSkipClause::AFTER_MATCH_SKIP_TARGET_UNSPECIFIED;
};

// Represents a pattern expression for row pattern recognition.
class ASTRowPatternExpression : public ASTNode {
 public:
  explicit ASTRowPatternExpression(ASTNodeKind kind) : ASTNode(kind) {}

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  friend class ParseTreeSerializer;

 private:
  bool parenthesized_ = false;
};

class ASTRowPatternVariable final : public ASTRowPatternExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROW_PATTERN_VARIABLE;

  ASTRowPatternVariable() : ASTRowPatternExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
};

// Represents an operation on a pattern expression. For example, it can
// be an alternation (A|B) or a concatenation (A B), or quantification.
// Note that alternation is analogous to OR, while concatenation is analogous
// to AND.
class ASTRowPatternOperation final : public ASTRowPatternExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROW_PATTERN_OPERATION;

  ASTRowPatternOperation() : ASTRowPatternExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTRowPatternOperationEnums::OperationType in ast_enums.proto
  enum OperationType {
    OPERATION_TYPE_UNSPECIFIED = ASTRowPatternOperationEnums::OPERATION_TYPE_UNSPECIFIED,
    CONCAT = ASTRowPatternOperationEnums::CONCAT,
    ALTERNATE = ASTRowPatternOperationEnums::ALTERNATE,
    PERMUTE = ASTRowPatternOperationEnums::PERMUTE,
    EXCLUDE = ASTRowPatternOperationEnums::EXCLUDE
  };

  void set_op_type(ASTRowPatternOperation::OperationType op_type) { op_type_ = op_type; }
  ASTRowPatternOperation::OperationType op_type() const { return op_type_; }

  const absl::Span<const ASTRowPatternExpression* const>& inputs() const {
    return inputs_;
  }
  const ASTRowPatternExpression* inputs(int i) const { return inputs_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&inputs_);
    return fl.Finalize();
  }

  ASTRowPatternOperation::OperationType op_type_ = ASTRowPatternOperation::OPERATION_TYPE_UNSPECIFIED;
  absl::Span<const ASTRowPatternExpression* const> inputs_;
};

// Represents an empty pattern. Unparenthesized empty patterns can occur at
// the root of the pattern, or under alternation. Never under concatenation,
// since it has no infix operator.
//
// Parenthesized empty patterns can appear anywhere.
//
// This node's location is a point location, usually the start of the
// following token.
class ASTEmptyRowPattern final : public ASTRowPatternExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EMPTY_ROW_PATTERN;

  ASTEmptyRowPattern() : ASTRowPatternExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Represents an anchor in a row pattern, i.e., `^` or `$`.
// Just like in regular expressions, the `^` anchor adds the requirement that
// the match must be at the start of the partition, while the `$` anchor
// means the match must be at the end of the partition.
class ASTRowPatternAnchor final : public ASTRowPatternExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROW_PATTERN_ANCHOR;

  ASTRowPatternAnchor() : ASTRowPatternExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTRowPatternAnchorEnums::Anchor in ast_enums.proto
  enum Anchor {
    ANCHOR_UNSPECIFIED = ASTRowPatternAnchorEnums::ANCHOR_UNSPECIFIED,
    START = ASTRowPatternAnchorEnums::START,
    END = ASTRowPatternAnchorEnums::END
  };

  void set_anchor(ASTRowPatternAnchor::Anchor anchor) { anchor_ = anchor; }
  ASTRowPatternAnchor::Anchor anchor() const { return anchor_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTRowPatternAnchor::Anchor anchor_ = ASTRowPatternAnchor::ANCHOR_UNSPECIFIED;
};

// Represents a quantifier, either a symbol (e.g. + or *), or a
// bounded quantifier, e.g. {1, 3}.
class ASTQuantifier : public ASTNode {
 public:
  explicit ASTQuantifier(ASTNodeKind kind) : ASTNode(kind) {}

  std::string SingleNodeDebugString() const override;

  void set_is_reluctant(bool is_reluctant) { is_reluctant_ = is_reluctant; }
  bool is_reluctant() const { return is_reluctant_; }

  bool IsQuantifier() const final { return true; }

  friend class ParseTreeSerializer;

 private:
  bool is_reluctant_ = false;
};

// Represents a bounded quantifier, e.g. {1, 3}. At least one bound must be
// non-null.
class ASTBoundedQuantifier final : public ASTQuantifier {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BOUNDED_QUANTIFIER;

  ASTBoundedQuantifier() : ASTQuantifier(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTQuantifierBound* lower_bound() const { return lower_bound_; }
  const ASTQuantifierBound* upper_bound() const { return upper_bound_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lower_bound_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&upper_bound_));
    return fl.Finalize();
  }

  const ASTQuantifierBound* lower_bound_ = nullptr;
  const ASTQuantifierBound* upper_bound_ = nullptr;
};

// Represents the lower or upper bound of a quantifier. This wrapper node
// is to get around the field loader mechanism.
class ASTQuantifierBound final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_QUANTIFIER_BOUND;

  ASTQuantifierBound() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* bound() const { return bound_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&bound_);
    return fl.Finalize();
  }

  const ASTExpression* bound_ = nullptr;
};

// Represents a fixed quantifier. Note that this cannot be represented as a
// bounded quantifier with identical ends because of positional parameters:
// i.e., {?} is not the same as {?, ?}. See b/362819300 for details.
class ASTFixedQuantifier final : public ASTQuantifier {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FIXED_QUANTIFIER;

  ASTFixedQuantifier() : ASTQuantifier(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* bound() const { return bound_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&bound_));
    return fl.Finalize();
  }

  const ASTExpression* bound_ = nullptr;
};

// Represents a quantifier such as '+', '?', or '*'.
class ASTSymbolQuantifier final : public ASTQuantifier {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SYMBOL_QUANTIFIER;

  ASTSymbolQuantifier() : ASTQuantifier(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTSymbolQuantifierEnums::Symbol in ast_enums.proto
  enum Symbol {
    SYMBOL_UNSPECIFIED = ASTSymbolQuantifierEnums::SYMBOL_UNSPECIFIED,
    QUESTION_MARK = ASTSymbolQuantifierEnums::QUESTION_MARK,
    PLUS = ASTSymbolQuantifierEnums::PLUS,
    STAR = ASTSymbolQuantifierEnums::STAR
  };

  void set_symbol(ASTSymbolQuantifier::Symbol symbol) { symbol_ = symbol; }
  ASTSymbolQuantifier::Symbol symbol() const { return symbol_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTSymbolQuantifier::Symbol symbol_ = ASTSymbolQuantifier::SYMBOL_UNSPECIFIED;
};

// Represents a quantified row pattern expression, e.g. (A|B)+?
class ASTRowPatternQuantification final : public ASTRowPatternExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ROW_PATTERN_QUANTIFICATION;

  ASTRowPatternQuantification() : ASTRowPatternExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The operand of the quantification. Cannot be nullptr.
  const ASTRowPatternExpression* operand() const { return operand_; }

  // The quantifier. Cannot be nullptr.
  const ASTQuantifier* quantifier() const { return quantifier_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&operand_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&quantifier_));
    return fl.Finalize();
  }

  const ASTRowPatternExpression* operand_ = nullptr;
  const ASTQuantifier* quantifier_ = nullptr;
};

class ASTQualify final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_QUALIFY;

  ASTQualify() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

class ASTClampedBetweenModifier final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CLAMPED_BETWEEN_MODIFIER;

  ASTClampedBetweenModifier() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* low() const { return low_; }
  const ASTExpression* high() const { return high_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&low_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&high_));
    return fl.Finalize();
  }

  const ASTExpression* low_ = nullptr;
  const ASTExpression* high_ = nullptr;
};

class ASTWithReportModifier final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_REPORT_MODIFIER;

  ASTWithReportModifier() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTOptionsList* options_list_ = nullptr;
};

class ASTFormatClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FORMAT_CLAUSE;

  ASTFormatClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* format() const { return format_; }
  const ASTExpression* time_zone_expr() const { return time_zone_expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&format_));
    fl.AddOptionalExpression(&time_zone_expr_);
    return fl.Finalize();
  }

  const ASTExpression* format_ = nullptr;
  const ASTExpression* time_zone_expr_ = nullptr;
};

class ASTPathExpressionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PATH_EXPRESSION_LIST;

  ASTPathExpressionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Guaranteed by the parser to never be empty.
  const absl::Span<const ASTPathExpression* const>& path_expression_list() const {
    return path_expression_list_;
  }
  const ASTPathExpression* path_expression_list(int i) const { return path_expression_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&path_expression_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTPathExpression* const> path_expression_list_;
};

class ASTParameterExpr final : public ASTParameterExprBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PARAMETER_EXPR;

  ASTParameterExpr() : ASTParameterExprBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_position(int position) { position_ = position; }
  int position() const { return position_; }

  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;

  // 1-based position of the parameter in the query. Mutually exclusive
  // with name_.
  int position_ = 0;
};

class ASTSystemVariableExpr final : public ASTParameterExprBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SYSTEM_VARIABLE_EXPR;

  ASTSystemVariableExpr() : ASTParameterExprBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* path() const { return path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_));
    return fl.Finalize();
  }

  const ASTPathExpression* path_ = nullptr;
};

// Function argument is required to be expression.
class ASTLambda final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LAMBDA;

  ASTLambda() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* argument_list() const { return argument_list_; }
  const ASTExpression* body() const { return body_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&argument_list_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  // Empty parameter list is represented as empty
  // ASTStructConstructorWithParens.
  const ASTExpression* argument_list_ = nullptr;

  // Required, never NULL.
  const ASTExpression* body_ = nullptr;
};

class ASTAnalyticFunctionCall final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ANALYTIC_FUNCTION_CALL;

  ASTAnalyticFunctionCall() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTFunctionCall* function() const { return function_; }
  const ASTWindowSpecification* window_spec() const { return window_spec_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&function_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&window_spec_));
    return fl.Finalize();
  }

  // Required, never NULL.
  const ASTFunctionCall* function_ = nullptr;

  // Required, never NULL.
  const ASTWindowSpecification* window_spec_ = nullptr;
};

class ASTClusterBy final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CLUSTER_BY;

  ASTClusterBy() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& clustering_expressions() const {
    return clustering_expressions_;
  }
  const ASTExpression* clustering_expressions(int i) const { return clustering_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&clustering_expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> clustering_expressions_;
};

// At most one of 'optional_identifier' and 'optional_path_expression' are
// set.
class ASTNewConstructorArg final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NEW_CONSTRUCTOR_ARG;

  ASTNewConstructorArg() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTIdentifier* optional_identifier() const { return optional_identifier_; }
  const ASTPathExpression* optional_path_expression() const { return optional_path_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&optional_identifier_, AST_IDENTIFIER);
    fl.AddOptional(&optional_path_expression_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTIdentifier* optional_identifier_ = nullptr;
  const ASTPathExpression* optional_path_expression_ = nullptr;
};

class ASTNewConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NEW_CONSTRUCTOR;

  ASTNewConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSimpleType* type_name() const { return type_name_; }

  const absl::Span<const ASTNewConstructorArg* const>& arguments() const {
    return arguments_;
  }
  const ASTNewConstructorArg* arguments(int i) const { return arguments_[i]; }

  const ASTNewConstructorArg* argument(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_name_));
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  const ASTSimpleType* type_name_ = nullptr;
  absl::Span<const ASTNewConstructorArg* const> arguments_;
};

class ASTBracedConstructorLhs final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BRACED_CONSTRUCTOR_LHS;

  ASTBracedConstructorLhs() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTBracedConstructorLhsEnums::Operation in ast_enums.proto
  enum Operation {
    UPDATE_SINGLE = ASTBracedConstructorLhsEnums::UPDATE_SINGLE,
    UPDATE_MANY = ASTBracedConstructorLhsEnums::UPDATE_MANY,
    UPDATE_SINGLE_NO_CREATION = ASTBracedConstructorLhsEnums::UPDATE_SINGLE_NO_CREATION
  };

  void set_operation(ASTBracedConstructorLhs::Operation operation) { operation_ = operation; }
  ASTBracedConstructorLhs::Operation operation() const { return operation_; }

  const ASTGeneralizedPathExpression* extended_path_expr() const { return extended_path_expr_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&extended_path_expr_));
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* extended_path_expr_ = nullptr;
  ASTBracedConstructorLhs::Operation operation_ = ASTBracedConstructorLhs::UPDATE_SINGLE;
};

class ASTBracedConstructorFieldValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BRACED_CONSTRUCTOR_FIELD_VALUE;

  ASTBracedConstructorFieldValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // True if "field:value" syntax is used.
  // False if "field value" syntax is used.
  // The later is only allowed in proto instead of struct.
  void set_colon_prefixed(bool colon_prefixed) { colon_prefixed_ = colon_prefixed; }
  bool colon_prefixed() const { return colon_prefixed_; }

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  bool colon_prefixed_ = false;
};

class ASTBracedConstructorField final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BRACED_CONSTRUCTOR_FIELD;

  ASTBracedConstructorField() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // True if this field is separated by comma from the previous one,
  // e.g.all e.g. "a:1,b:2".
  // False if separated by whitespace, e.g. "a:1 b:2".
  // The latter is only allowed in proto instead of struct.
  void set_comma_separated(bool comma_separated) { comma_separated_ = comma_separated; }
  bool comma_separated() const { return comma_separated_; }

  const ASTBracedConstructorLhs* braced_constructor_lhs() const { return braced_constructor_lhs_; }
  const ASTBracedConstructorFieldValue* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&braced_constructor_lhs_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTBracedConstructorLhs* braced_constructor_lhs_ = nullptr;
  const ASTBracedConstructorFieldValue* value_ = nullptr;
  bool comma_separated_ = false;
};

class ASTBracedConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BRACED_CONSTRUCTOR;

  ASTBracedConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTBracedConstructorField* const>& fields() const {
    return fields_;
  }
  const ASTBracedConstructorField* fields(int i) const { return fields_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&fields_);
    return fl.Finalize();
  }

  absl::Span<const ASTBracedConstructorField* const> fields_;
};

class ASTBracedNewConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BRACED_NEW_CONSTRUCTOR;

  ASTBracedNewConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSimpleType* type_name() const { return type_name_; }
  const ASTBracedConstructor* braced_constructor() const { return braced_constructor_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&braced_constructor_));
    return fl.Finalize();
  }

  const ASTSimpleType* type_name_ = nullptr;
  const ASTBracedConstructor* braced_constructor_ = nullptr;
};

class ASTExtendedPathExpression final : public ASTGeneralizedPathExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXTENDED_PATH_EXPRESSION;

  ASTExtendedPathExpression() : ASTGeneralizedPathExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGeneralizedPathExpression* parenthesized_path() const { return parenthesized_path_; }
  const ASTGeneralizedPathExpression* generalized_path_expression() const { return generalized_path_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&parenthesized_path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&generalized_path_expression_));
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* parenthesized_path_ = nullptr;
  const ASTGeneralizedPathExpression* generalized_path_expression_ = nullptr;
};

class ASTUpdateConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UPDATE_CONSTRUCTOR;

  ASTUpdateConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTFunctionCall* function() const { return function_; }
  const ASTBracedConstructor* braced_constructor() const { return braced_constructor_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&function_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&braced_constructor_));
    return fl.Finalize();
  }

  const ASTFunctionCall* function_ = nullptr;
  const ASTBracedConstructor* braced_constructor_ = nullptr;
};

class ASTStructBracedConstructor final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_BRACED_CONSTRUCTOR;

  ASTStructBracedConstructor() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTType* type_name() const { return type_name_; }
  const ASTBracedConstructor* braced_constructor() const { return braced_constructor_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalType(&type_name_);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&braced_constructor_));
    return fl.Finalize();
  }

  const ASTType* type_name_ = nullptr;
  const ASTBracedConstructor* braced_constructor_ = nullptr;
};

class ASTOptionsList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_OPTIONS_LIST;

  ASTOptionsList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTOptionsEntry* const>& options_entries() const {
    return options_entries_;
  }
  const ASTOptionsEntry* options_entries(int i) const { return options_entries_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&options_entries_);
    return fl.Finalize();
  }

  absl::Span<const ASTOptionsEntry* const> options_entries_;
};

class ASTOptionsEntry final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_OPTIONS_ENTRY;

  ASTOptionsEntry() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTOptionsEntryEnums::AssignmentOp in ast_enums.proto
  enum AssignmentOp {
    NOT_SET = ASTOptionsEntryEnums::NOT_SET,
    ASSIGN = ASTOptionsEntryEnums::ASSIGN,
    ADD_ASSIGN = ASTOptionsEntryEnums::ADD_ASSIGN,
    SUB_ASSIGN = ASTOptionsEntryEnums::SUB_ASSIGN
  };

  // See description of Op values in ast_enums.proto.
  void set_assignment_op(ASTOptionsEntry::AssignmentOp assignment_op) { assignment_op_ = assignment_op; }
  ASTOptionsEntry::AssignmentOp assignment_op() const { return assignment_op_; }

  const ASTIdentifier* name() const { return name_; }

  // Value may be any expression; engines can decide whether they
  // support identifiers, literals, parameters, constants, etc.
  const ASTExpression* value() const { return value_; }

      // Returns name of the assignment operator in SQL.
      std::string GetSQLForOperator() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTExpression* value_ = nullptr;
  ASTOptionsEntry::AssignmentOp assignment_op_ = ASTOptionsEntry::NOT_SET;
};

// Common superclass of CREATE statements supporting the common
// modifiers:
//   CREATE [OR REPLACE] [TEMP|PUBLIC|PRIVATE] <object> [IF NOT EXISTS].
class ASTCreateStatement : public ASTDdlStatement {
 public:
  explicit ASTCreateStatement(ASTNodeKind kind) : ASTDdlStatement(kind) {}

  // This adds the modifiers is_temp, etc, to the node name.
  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTCreateStatementEnums::Scope in ast_enums.proto
  enum Scope {
    DEFAULT_SCOPE = ASTCreateStatementEnums::DEFAULT_SCOPE,
    PRIVATE = ASTCreateStatementEnums::PRIVATE,
    PUBLIC = ASTCreateStatementEnums::PUBLIC,
    TEMPORARY = ASTCreateStatementEnums::TEMPORARY
  };

  // This enum is equivalent to ASTCreateStatementEnums::SqlSecurity in ast_enums.proto
  enum SqlSecurity {
    SQL_SECURITY_UNSPECIFIED = ASTCreateStatementEnums::SQL_SECURITY_UNSPECIFIED,
    SQL_SECURITY_DEFINER = ASTCreateStatementEnums::SQL_SECURITY_DEFINER,
    SQL_SECURITY_INVOKER = ASTCreateStatementEnums::SQL_SECURITY_INVOKER
  };

  void set_scope(ASTCreateStatement::Scope scope) { scope_ = scope; }
  ASTCreateStatement::Scope scope() const { return scope_; }
  void set_is_or_replace(bool is_or_replace) { is_or_replace_ = is_or_replace; }
  bool is_or_replace() const { return is_or_replace_; }
  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  bool is_default_scope() const { return scope_ == DEFAULT_SCOPE; }
  bool is_private() const { return scope_ == PRIVATE; }
  bool is_public() const { return scope_ == PUBLIC; }
  bool is_temp() const { return scope_ == TEMPORARY; }

  bool IsCreateStatement() const override { return true; }

  friend class ParseTreeSerializer;

 protected:
  virtual void CollectModifiers(std::vector<std::string>* modifiers) const;

 private:
  ASTCreateStatement::Scope scope_ = ASTCreateStatement::DEFAULT_SCOPE;
  bool is_or_replace_ = false;
  bool is_if_not_exists_ = false;
};

class ASTFunctionParameter final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_PARAMETER;

  ASTFunctionParameter() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTFunctionParameterEnums::ProcedureParameterMode in ast_enums.proto
  enum ProcedureParameterMode {
    NOT_SET = ASTFunctionParameterEnums::NOT_SET,
    IN = ASTFunctionParameterEnums::IN,
    OUT = ASTFunctionParameterEnums::OUT,
    INOUT = ASTFunctionParameterEnums::INOUT
  };

  void set_procedure_parameter_mode(ASTFunctionParameter::ProcedureParameterMode procedure_parameter_mode) { procedure_parameter_mode_ = procedure_parameter_mode; }
  ASTFunctionParameter::ProcedureParameterMode procedure_parameter_mode() const { return procedure_parameter_mode_; }
  void set_is_not_aggregate(bool is_not_aggregate) { is_not_aggregate_ = is_not_aggregate; }
  bool is_not_aggregate() const { return is_not_aggregate_; }

  const ASTIdentifier* name() const { return name_; }
  const ASTType* type() const { return type_; }
  const ASTTemplatedParameterType* templated_parameter_type() const { return templated_parameter_type_; }
  const ASTTVFSchema* tvf_schema() const { return tvf_schema_; }
  const ASTAlias* alias() const { return alias_; }
  const ASTExpression* default_value() const { return default_value_; }

  bool IsTableParameter() const;
  bool IsTemplated() const {
    return templated_parameter_type_ != nullptr;
  }

  static std::string ProcedureParameterModeToString(
      ProcedureParameterMode mode);

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_IDENTIFIER);
    fl.AddOptionalType(&type_);
    fl.AddOptional(&templated_parameter_type_, AST_TEMPLATED_PARAMETER_TYPE);
    fl.AddOptional(&tvf_schema_, AST_TVF_SCHEMA);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptionalExpression(&default_value_);
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;

  // Only one of <type_>, <templated_parameter_type_>, or <tvf_schema_>
  // will be set.
  //
  // This is the type for concrete scalar parameters.
  const ASTType* type_ = nullptr;

  // This indicates a templated parameter type, which may be either a
  // templated scalar type (ANY PROTO, ANY STRUCT, etc.) or templated table
  // type as indicated by its kind().
  const ASTTemplatedParameterType* templated_parameter_type_ = nullptr;

  // Only allowed for table-valued functions, indicating a table type
  // parameter.
  const ASTTVFSchema* tvf_schema_ = nullptr;

  const ASTAlias* alias_ = nullptr;

  // The default value of the function parameter if specified.
  const ASTExpression* default_value_ = nullptr;

  // Function parameter doesn't use this field and always has value NOT_SET.
  // Procedure parameter should have this field set during parsing.
  ASTFunctionParameter::ProcedureParameterMode procedure_parameter_mode_ = ASTFunctionParameter::NOT_SET;

  // True if the NOT AGGREGATE modifier is present.
  bool is_not_aggregate_ = false;
};

class ASTFunctionParameters final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_PARAMETERS;

  ASTFunctionParameters() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTFunctionParameter* const>& parameter_entries() const {
    return parameter_entries_;
  }
  const ASTFunctionParameter* parameter_entries(int i) const { return parameter_entries_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&parameter_entries_);
    return fl.Finalize();
  }

  absl::Span<const ASTFunctionParameter* const> parameter_entries_;
};

class ASTFunctionDeclaration final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FUNCTION_DECLARATION;

  ASTFunctionDeclaration() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTFunctionParameters* parameters() const { return parameters_; }

  // Returns whether or not any of the <parameters_> are templated.
  bool IsTemplated() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&parameters_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTFunctionParameters* parameters_ = nullptr;
};

class ASTSqlFunctionBody final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SQL_FUNCTION_BODY;

  ASTSqlFunctionBody() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

// This represents an argument to a table-valued function (TVF). GoogleSQL can
// parse the argument in one of the following ways:
//
// (1) GoogleSQL parses the argument as an expression; if any arguments are
//     table subqueries then GoogleSQL will parse them as subquery expressions
//     and the resolver may interpret them as needed later. In this case the
//     expr_ of this class is filled.
//
//     These special argument forms are also parsed as ASTExpressions,
//     but analyzed specially:
//       * ASTNamedArgument
//       * ASTLambda
//       * ASTInputTable
//     These node types (other than ASTNamedArgument) can also occur
//     as named arguments themselves, inside an ASTNamedArgument.
//
// (2) GoogleSQL parses the argument as "TABLE path"; this syntax represents a
//     table argument including all columns in the named table. In this case the
//     table_clause_ of this class is non-empty.
//
// (3) GoogleSQL parses the argument as "MODEL path"; this syntax represents a
//     model argument. In this case the model_clause_ of this class is
//     non-empty.
//
// (4) GoogleSQL parses the argument as "CONNECTION path"; this syntax
//     represents a connection argument. In this case the connection_clause_ of
//     this class is non-empty.
//
// (5) GoogleSQL parses the argument as "DESCRIPTOR"; this syntax represents a
//    descriptor on a list of columns with optional types.
class ASTTVFArgument final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TVF_ARGUMENT;

  ASTTVFArgument() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }
  const ASTTableClause* table_clause() const { return table_clause_; }
  const ASTModelClause* model_clause() const { return model_clause_; }
  const ASTConnectionClause* connection_clause() const { return connection_clause_; }

  const ASTDescriptor* descriptor() const {return desc_;}

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expr_);
    fl.AddOptional(&table_clause_, AST_TABLE_CLAUSE);
    fl.AddOptional(&model_clause_, AST_MODEL_CLAUSE);
    fl.AddOptional(&connection_clause_, AST_CONNECTION_CLAUSE);
    fl.AddOptional(&desc_, AST_DESCRIPTOR);
    return fl.Finalize();
  }

  // Only one of expr, table_clause, model_clause, connection_clause or
  // descriptor may be non-null.
  const ASTExpression* expr_ = nullptr;

  const ASTTableClause* table_clause_ = nullptr;
  const ASTModelClause* model_clause_ = nullptr;
  const ASTConnectionClause* connection_clause_ = nullptr;
  const ASTDescriptor* desc_ = nullptr;
};

// This represents a call to a table-valued function (TVF). Each TVF returns an
// entire output relation instead of a single scalar value. The enclosing query
// may refer to the TVF as if it were a table subquery. The TVF may accept
// scalar arguments and/or other input relations.
class ASTTVF final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TVF;

  ASTTVF() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_lateral(bool is_lateral) { is_lateral_ = is_lateral; }
  bool is_lateral() const { return is_lateral_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTHint* hint() const { return hint_; }
  const ASTAlias* alias() const { return alias_; }

  const absl::Span<const ASTTVFArgument* const>& argument_entries() const {
    return argument_entries_;
  }
  const ASTTVFArgument* argument_entries(int i) const { return argument_entries_[i]; }

  // Compatibility getters until callers are migrated to directly use the list
  // of posfix operators.
  const ASTSampleClause* sample() const {
      return sample_clause();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddRepeatedWhileIsNodeKind(&argument_entries_, AST_TVF_ARGUMENT);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  absl::Span<const ASTTVFArgument* const> argument_entries_;
  bool is_lateral_ = false;
  const ASTHint* hint_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

// This represents a clause of form "TABLE <target>", where <target> is either
// a path expression representing a table name, or <target> is a TVF call.
// It is currently only supported for relation arguments to table-valued
// functions.
class ASTTableClause final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_CLAUSE;

  ASTTableClause() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* table_path() const { return table_path_; }
  const ASTTVF* tvf() const { return tvf_; }
  const ASTWhereClause* where_clause() const { return where_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&table_path_, AST_PATH_EXPRESSION);
    fl.AddOptional(&tvf_, AST_TVF);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    return fl.Finalize();
  }

  // Exactly one of these will be non-null.
  const ASTPathExpression* table_path_ = nullptr;

  const ASTTVF* tvf_ = nullptr;
  const ASTWhereClause* where_clause_ = nullptr;
};

// This represents a clause of form "MODEL <target>", where <target> is a model
// name.
class ASTModelClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MODEL_CLAUSE;

  ASTModelClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* model_path() const { return model_path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&model_path_));
    return fl.Finalize();
  }

  const ASTPathExpression* model_path_ = nullptr;
};

// This represents a clause of `CONNECTION DEFAULT` or `CONNECTION <path>`.
// In the former form, the connection_path will be a default literal. In the
// latter form, the connection_path will be a path expression.
class ASTConnectionClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CONNECTION_CLAUSE;

  ASTConnectionClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* connection_path() const { return connection_path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&connection_path_));
    return fl.Finalize();
  }

  const ASTExpression* connection_path_ = nullptr;
};

class ASTTableDataSource : public ASTTableExpression {
 public:
  explicit ASTTableDataSource(ASTNodeKind kind) : ASTTableExpression(kind) {}

  const ASTPathExpression* path_expr() const { return path_expr_; }
  const ASTForSystemTime* for_system_time() const { return for_system_time_; }
  const ASTWhereClause* where_clause() const { return where_clause_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* path_expr_ = nullptr;
  const ASTForSystemTime* for_system_time_ = nullptr;
  const ASTWhereClause* where_clause_ = nullptr;
};

class ASTCloneDataSource final : public ASTTableDataSource {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CLONE_DATA_SOURCE;

  ASTCloneDataSource() : ASTTableDataSource(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_expr_));
    fl.AddOptional(&for_system_time_, AST_FOR_SYSTEM_TIME);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }
};

class ASTCopyDataSource final : public ASTTableDataSource {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COPY_DATA_SOURCE;

  ASTCopyDataSource() : ASTTableDataSource(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_expr_));
    fl.AddOptional(&for_system_time_, AST_FOR_SYSTEM_TIME);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }
};

class ASTCloneDataSourceList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CLONE_DATA_SOURCE_LIST;

  ASTCloneDataSourceList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTCloneDataSource* const>& data_sources() const {
    return data_sources_;
  }
  const ASTCloneDataSource* data_sources(int i) const { return data_sources_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&data_sources_);
    return fl.Finalize();
  }

  absl::Span<const ASTCloneDataSource* const> data_sources_;
};

class ASTCloneDataStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CLONE_DATA_STATEMENT;

  ASTCloneDataStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTCloneDataSourceList* data_source_list() const { return data_source_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&data_source_list_));
    return fl.Finalize();
  }

  const ASTPathExpression* target_path_ = nullptr;
  const ASTCloneDataSourceList* data_source_list_ = nullptr;
};

// This represents a CREATE CONNECTION statement, i.e.,
// CREATE [OR REPLACE] CONNECTION
//   [IF NOT EXISTS] <name_path> OPTIONS (name=value, ...);
class ASTCreateConnectionStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_CONNECTION_STATEMENT;

  ASTCreateConnectionStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

// This represents a CREATE CONSTANT statement, i.e.,
// CREATE [OR REPLACE] [TEMP|TEMPORARY|PUBLIC|PRIVATE] CONSTANT
//   [IF NOT EXISTS] <name_path> = <expression>;
class ASTCreateConstantStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_CONSTANT_STATEMENT;

  ASTCreateConstantStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTExpression* expr() const { return expr_; }

      const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTExpression* expr_ = nullptr;
};

// This represents a CREATE DATABASE statement, i.e.,
// CREATE DATABASE <name> [OPTIONS (name=value, ...)];
class ASTCreateDatabaseStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_DATABASE_STATEMENT;

  ASTCreateDatabaseStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTCreateProcedureStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_PROCEDURE_STATEMENT;

  ASTCreateProcedureStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_external_security(ASTCreateStatement::SqlSecurity external_security) { external_security_ = external_security; }
  ASTCreateStatement::SqlSecurity external_security() const { return external_security_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTFunctionParameters* parameters() const { return parameters_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  // The body of a procedure. Always consists of a single BeginEndBlock
  // including the BEGIN/END keywords and text in between.
  const ASTScript* body() const { return body_; }

  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }
  const ASTIdentifier* language() const { return language_; }
  const ASTStringLiteral* code() const { return code_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }
  std::string GetSqlForExternalSecurity() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&parameters_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&body_, AST_SCRIPT);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&language_, AST_IDENTIFIER);
    fl.AddOptional(&code_, AST_STRING_LITERAL);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTFunctionParameters* parameters_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTScript* body_ = nullptr;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
  const ASTIdentifier* language_ = nullptr;
  const ASTStringLiteral* code_ = nullptr;
  ASTCreateStatement::SqlSecurity external_security_ = ASTCreateStatement::SQL_SECURITY_UNSPECIFIED;
};

// A base class to be used by statements that create schemas, including
// CREATE SCHEMA and CREATE EXTERNAL SCHEMA.
class ASTCreateSchemaStmtBase : public ASTCreateStatement {
 public:
  explicit ASTCreateSchemaStmtBase(ASTNodeKind kind) : ASTCreateStatement(kind) {}

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

// This represents a CREATE SCHEMA statement, i.e.,
// CREATE SCHEMA <name> [OPTIONS (name=value, ...)];
class ASTCreateSchemaStatement final : public ASTCreateSchemaStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_SCHEMA_STATEMENT;

  ASTCreateSchemaStatement() : ASTCreateSchemaStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTCollate* collate() const { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTCollate* collate_ = nullptr;
};

// This represents a CREATE EXTERNAL SCHEMA statement, i.e.,
// CREATE [OR REPLACE] [TEMP|TEMPORARY|PUBLIC|PRIVATE] EXTERNAL SCHEMA [IF
// NOT EXISTS] <name> [WITH CONNECTION <connection>] OPTIONS (name=value,
// ...);
class ASTCreateExternalSchemaStatement final : public ASTCreateSchemaStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_EXTERNAL_SCHEMA_STATEMENT;

  ASTCreateExternalSchemaStatement() : ASTCreateSchemaStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
};

class ASTAliasedQueryList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIASED_QUERY_LIST;

  ASTAliasedQueryList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTAliasedQuery* const>& aliased_query_list() const {
    return aliased_query_list_;
  }
  const ASTAliasedQuery* aliased_query_list(int i) const { return aliased_query_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&aliased_query_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTAliasedQuery* const> aliased_query_list_;
};

class ASTTransformClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TRANSFORM_CLAUSE;

  ASTTransformClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelectList* select_list() const { return select_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_list_));
    return fl.Finalize();
  }

  const ASTSelectList* select_list_ = nullptr;
};

// This represents a CREATE MODEL statement, i.e.,
// CREATE OR REPLACE MODEL model
// TRANSFORM(...)
// OPTIONS(...)
// AS
// <query> | (<identifier> AS (<query>) [, ...]).
//
// Note that at most one of `query` and `aliased_query_list` will be
// populated, and if so the other will be null.
class ASTCreateModelStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_MODEL_STATEMENT;

  ASTCreateModelStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_remote(bool is_remote) { is_remote_ = is_remote; }
  bool is_remote() const { return is_remote_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTInputOutputClause* input_output_clause() const { return input_output_clause_; }
  const ASTTransformClause* transform_clause() const { return transform_clause_; }
  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTQuery* query() const { return query_; }
  const ASTAliasedQueryList* aliased_query_list() const { return aliased_query_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&input_output_clause_, AST_INPUT_OUTPUT_CLAUSE);
    fl.AddOptional(&transform_clause_, AST_TRANSFORM_CLAUSE);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&aliased_query_list_, AST_ALIASED_QUERY_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTInputOutputClause* input_output_clause_ = nullptr;
  const ASTTransformClause* transform_clause_ = nullptr;
  bool is_remote_ = false;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTQuery* query_ = nullptr;
  const ASTAliasedQueryList* aliased_query_list_ = nullptr;
};

// Represents 'ALL COLUMNS' index key expression.
class ASTIndexAllColumns final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INDEX_ALL_COLUMNS;

  ASTIndexAllColumns() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIndexItemList* column_options() const { return column_options_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&column_options_, AST_INDEX_ITEM_LIST);
    return fl.Finalize();
  }

  const ASTIndexItemList* column_options_ = nullptr;
};

// Represents the list of expressions used to order an index.
class ASTIndexItemList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INDEX_ITEM_LIST;

  ASTIndexItemList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTOrderingExpression* const>& ordering_expressions() const {
    return ordering_expressions_;
  }
  const ASTOrderingExpression* ordering_expressions(int i) const { return ordering_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&ordering_expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTOrderingExpression* const> ordering_expressions_;
};

// Represents the list of expressions being used in the STORING clause of an
// index.
class ASTIndexStoringExpressionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INDEX_STORING_EXPRESSION_LIST;

  ASTIndexStoringExpressionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& expressions() const {
    return expressions_;
  }
  const ASTExpression* expressions(int i) const { return expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> expressions_;
};

// Represents the list of unnest expressions for create_index.
class ASTIndexUnnestExpressionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INDEX_UNNEST_EXPRESSION_LIST;

  ASTIndexUnnestExpressionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTUnnestExpressionWithOptAliasAndOffset* const>& unnest_expressions() const {
    return unnest_expressions_;
  }
  const ASTUnnestExpressionWithOptAliasAndOffset* unnest_expressions(int i) const { return unnest_expressions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&unnest_expressions_);
    return fl.Finalize();
  }

  absl::Span<const ASTUnnestExpressionWithOptAliasAndOffset* const> unnest_expressions_;
};

// Represents a CREATE INDEX statement.
class ASTCreateIndexStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_INDEX_STATEMENT;

  ASTCreateIndexStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_unique(bool is_unique) { is_unique_ = is_unique; }
  bool is_unique() const { return is_unique_; }
  void set_is_search(bool is_search) { is_search_ = is_search; }
  bool is_search() const { return is_search_; }
  void set_spanner_is_null_filtered(bool spanner_is_null_filtered) { spanner_is_null_filtered_ = spanner_is_null_filtered; }
  bool spanner_is_null_filtered() const { return spanner_is_null_filtered_; }
  void set_is_vector(bool is_vector) { is_vector_ = is_vector; }
  bool is_vector() const { return is_vector_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTPathExpression* table_name() const { return table_name_; }
  const ASTAlias* optional_table_alias() const { return optional_table_alias_; }
  const ASTIndexUnnestExpressionList* optional_index_unnest_expression_list() const { return optional_index_unnest_expression_list_; }
  const ASTIndexItemList* index_item_list() const { return index_item_list_; }
  const ASTIndexStoringExpressionList* optional_index_storing_expressions() const { return optional_index_storing_expressions_; }
  const ASTPartitionBy* optional_partition_by() const { return optional_partition_by_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTSpannerInterleaveClause* spanner_interleave_clause() const { return spanner_interleave_clause_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_));
    fl.AddOptional(&optional_table_alias_, AST_ALIAS);
    fl.AddOptional(&optional_index_unnest_expression_list_, AST_INDEX_UNNEST_EXPRESSION_LIST);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&index_item_list_));
    fl.AddOptional(&optional_index_storing_expressions_, AST_INDEX_STORING_EXPRESSION_LIST);
    fl.AddOptional(&optional_partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&spanner_interleave_clause_, AST_SPANNER_INTERLEAVE_CLAUSE);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTPathExpression* table_name_ = nullptr;
  const ASTAlias* optional_table_alias_ = nullptr;
  const ASTIndexUnnestExpressionList* optional_index_unnest_expression_list_ = nullptr;
  const ASTIndexItemList* index_item_list_ = nullptr;
  const ASTIndexStoringExpressionList* optional_index_storing_expressions_ = nullptr;
  const ASTPartitionBy* optional_partition_by_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  bool is_unique_ = false;
  bool is_search_ = false;
  const ASTSpannerInterleaveClause* spanner_interleave_clause_ = nullptr;
  bool spanner_is_null_filtered_ = false;
  bool is_vector_ = false;
};

class ASTExportDataStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPORT_DATA_STATEMENT;

  ASTExportDataStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  // `query` is always present when this node is used as an EXPORT DATA
  // statement.
  // `query` is never present when this is node is used as a
  // pipe EXPORT DATA operator.
  const ASTQuery* query() const { return query_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    return fl.Finalize();
  }

  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTQuery* query_ = nullptr;
};

class ASTExportModelStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPORT_MODEL_STATEMENT;

  ASTExportModelStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* model_name_path() const { return model_name_path_; }
  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&model_name_path_));
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* model_name_path_ = nullptr;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

// Generic EXPORT <object_kind> METADATA statement.
class ASTExportMetadataStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXPORT_METADATA_STATEMENT;

  ASTExportMetadataStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_schema_object_kind(SchemaObjectKind schema_object_kind) { schema_object_kind_ = schema_object_kind; }
  SchemaObjectKind schema_object_kind() const { return schema_object_kind_; }

  const ASTPathExpression* name_path() const { return name_path_; }
  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_path_));
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  SchemaObjectKind schema_object_kind_ = kInvalidSchemaObjectKind;
  const ASTPathExpression* name_path_ = nullptr;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTCallStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CALL_STATEMENT;

  ASTCallStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* procedure_name() const { return procedure_name_; }

  const absl::Span<const ASTTVFArgument* const>& arguments() const {
    return arguments_;
  }
  const ASTTVFArgument* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&procedure_name_));
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  const ASTPathExpression* procedure_name_ = nullptr;
  absl::Span<const ASTTVFArgument* const> arguments_;
};

class ASTDefineTableStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DEFINE_TABLE_STATEMENT;

  ASTDefineTableStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&options_list_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTCreateLocalityGroupStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_LOCALITY_GROUP_STATEMENT;

  ASTCreateLocalityGroupStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTWithPartitionColumnsClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_PARTITION_COLUMNS_CLAUSE;

  ASTWithPartitionColumnsClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTableElementList* table_element_list() const { return table_element_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&table_element_list_, AST_TABLE_ELEMENT_LIST);
    return fl.Finalize();
  }

  const ASTTableElementList* table_element_list_ = nullptr;
};

// Represents a generic CREATE SNAPSHOT statement.
// Currently used for CREATE SNAPSHOT SCHEMA statement.
class ASTCreateSnapshotStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_SNAPSHOT_STATEMENT;

  ASTCreateSnapshotStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_schema_object_kind(SchemaObjectKind schema_object_kind) { schema_object_kind_ = schema_object_kind; }
  SchemaObjectKind schema_object_kind() const { return schema_object_kind_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTCloneDataSource* clone_data_source() const { return clone_data_source_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&clone_data_source_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  SchemaObjectKind schema_object_kind_ = kInvalidSchemaObjectKind;
  const ASTPathExpression* name_ = nullptr;
  const ASTCloneDataSource* clone_data_source_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

// Represents a CREATE SNAPSHOT TABLE statement.
class ASTCreateSnapshotTableStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_SNAPSHOT_TABLE_STATEMENT;

  ASTCreateSnapshotTableStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTCloneDataSource* clone_data_source() const { return clone_data_source_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&clone_data_source_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTCloneDataSource* clone_data_source_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTTypeParameterList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TYPE_PARAMETER_LIST;

  ASTTypeParameterList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTLeaf* const>& parameters() const {
    return parameters_;
  }
  const ASTLeaf* parameters(int i) const { return parameters_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&parameters_);
    return fl.Finalize();
  }

  absl::Span<const ASTLeaf* const> parameters_;
};

// This represents a relation argument or return type for a table-valued
// function (TVF). The resolver can convert each ASTTVFSchema directly into a
// TVFRelation object suitable for use in TVF signatures. For more information
// about the TVFRelation object, please refer to public/table_valued_function.h.
// TODO: Change the names of these objects to make them generic and
// re-usable wherever we want to represent the schema of some intermediate or
// final table. Same for ASTTVFSchemaColumn.
class ASTTVFSchema final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TVF_SCHEMA;

  ASTTVFSchema() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTTVFSchemaColumn* const>& columns() const {
    return columns_;
  }
  const ASTTVFSchemaColumn* columns(int i) const { return columns_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&columns_);
    return fl.Finalize();
  }

  absl::Span<const ASTTVFSchemaColumn* const> columns_;
};

// This represents one column of a relation argument or return value for a
// table-valued function (TVF). It contains the name and type of the column.
class ASTTVFSchemaColumn final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TVF_SCHEMA_COLUMN;

  ASTTVFSchemaColumn() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // name_ will be NULL for value tables.
  const ASTIdentifier* name() const { return name_; }

  const ASTType* type() const { return type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTType* type_ = nullptr;
};

class ASTTableAndColumnInfo final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_AND_COLUMN_INFO;

  ASTTableAndColumnInfo() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* table_name() const { return table_name_; }
  const ASTColumnList* column_list() const { return column_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_));
    fl.AddOptional(&column_list_, AST_COLUMN_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_ = nullptr;
  const ASTColumnList* column_list_ = nullptr;
};

class ASTTableAndColumnInfoList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_AND_COLUMN_INFO_LIST;

  ASTTableAndColumnInfoList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTTableAndColumnInfo* const>& table_and_column_info_entries() const {
    return table_and_column_info_entries_;
  }
  const ASTTableAndColumnInfo* table_and_column_info_entries(int i) const { return table_and_column_info_entries_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&table_and_column_info_entries_);
    return fl.Finalize();
  }

  absl::Span<const ASTTableAndColumnInfo* const> table_and_column_info_entries_;
};

class ASTTemplatedParameterType final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TEMPLATED_PARAMETER_TYPE;

  ASTTemplatedParameterType() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTTemplatedParameterTypeEnums::TemplatedTypeKind in ast_enums.proto
  enum TemplatedTypeKind {
    UNINITIALIZED = ASTTemplatedParameterTypeEnums::UNINITIALIZED,
    ANY_TYPE = ASTTemplatedParameterTypeEnums::ANY_TYPE,
    ANY_PROTO = ASTTemplatedParameterTypeEnums::ANY_PROTO,
    ANY_ENUM = ASTTemplatedParameterTypeEnums::ANY_ENUM,
    ANY_STRUCT = ASTTemplatedParameterTypeEnums::ANY_STRUCT,
    ANY_ARRAY = ASTTemplatedParameterTypeEnums::ANY_ARRAY,
    ANY_TABLE = ASTTemplatedParameterTypeEnums::ANY_TABLE
  };

  void set_kind(ASTTemplatedParameterType::TemplatedTypeKind kind) { kind_ = kind; }
  ASTTemplatedParameterType::TemplatedTypeKind kind() const { return kind_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTTemplatedParameterType::TemplatedTypeKind kind_ = ASTTemplatedParameterType::UNINITIALIZED;
};

// This represents the value DEFAULT in DML statements or connection clauses.
// It will not show up as a general expression anywhere else.
class ASTDefaultLiteral final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DEFAULT_LITERAL;

  ASTDefaultLiteral() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTAnalyzeStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ANALYZE_STATEMENT;

  ASTAnalyzeStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTTableAndColumnInfoList* table_and_column_info_list() const { return table_and_column_info_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&table_and_column_info_list_, AST_TABLE_AND_COLUMN_INFO_LIST);
    return fl.Finalize();
  }

  const ASTOptionsList* options_list_ = nullptr;
  const ASTTableAndColumnInfoList* table_and_column_info_list_ = nullptr;
};

class ASTAssertStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ASSERT_STATEMENT;

  ASTAssertStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }
  const ASTStringLiteral* description() const { return description_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    fl.AddOptional(&description_, AST_STRING_LITERAL);
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  const ASTStringLiteral* description_ = nullptr;
};

class ASTAssertRowsModified final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ASSERT_ROWS_MODIFIED;

  ASTAssertRowsModified() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* num_rows() const { return num_rows_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&num_rows_));
    return fl.Finalize();
  }

  const ASTExpression* num_rows_ = nullptr;
};

// This represents the {THEN RETURN} clause.
// (broken link)
class ASTReturningClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RETURNING_CLAUSE;

  ASTReturningClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelectList* select_list() const { return select_list_; }
  const ASTAlias* action_alias() const { return action_alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_list_));
    fl.AddOptional(&action_alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTSelectList* select_list_ = nullptr;
  const ASTAlias* action_alias_ = nullptr;
};

// This is used in INSERT statements to specify an alternate action if the
// the insert row causes unique constraint violations.
//
// conflict_action is either UPDATE or NOTHING
//
// conflict_target, unique_constraint_name:
// They are applicable for both conflict actions. They are optional but are
// mutually exclusive. It is allowed for both fields to be null. They will
// then be analyzed according to the conflict action.
//
// update_item_list, update_where_clause applies:
// They are applicable for conflict action UPDATE only.
class ASTOnConflictClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ON_CONFLICT_CLAUSE;

  ASTOnConflictClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTOnConflictClauseEnums::ConflictAction in ast_enums.proto
  enum ConflictAction {
    NOT_SET = ASTOnConflictClauseEnums::NOT_SET,
    NOTHING = ASTOnConflictClauseEnums::NOTHING,
    UPDATE = ASTOnConflictClauseEnums::UPDATE
  };

  void set_conflict_action(ASTOnConflictClause::ConflictAction conflict_action) { conflict_action_ = conflict_action; }
  ASTOnConflictClause::ConflictAction conflict_action() const { return conflict_action_; }

  // If defined, the column list must not be empty.
  const ASTColumnList* conflict_target() const { return conflict_target_; }

  const ASTIdentifier* unique_constraint_name() const { return unique_constraint_name_; }

  // Defined only for conflict action UPDATE. It must be non empty
  // if defined.
  const ASTUpdateItemList* update_item_list() const { return update_item_list_; }

  // Defined only for conflict action UPDATE. It is an optional field.
  const ASTExpression* update_where_clause() const { return update_where_clause_; }

  std::string GetSQLForConflictAction() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&conflict_target_, AST_COLUMN_LIST);
    fl.AddOptional(&unique_constraint_name_, AST_IDENTIFIER);
    fl.AddOptional(&update_item_list_, AST_UPDATE_ITEM_LIST);
    fl.AddOptionalExpression(&update_where_clause_);
    return fl.Finalize();
  }

  ASTOnConflictClause::ConflictAction conflict_action_ = ASTOnConflictClause::NOT_SET;
  const ASTColumnList* conflict_target_ = nullptr;
  const ASTIdentifier* unique_constraint_name_ = nullptr;
  const ASTUpdateItemList* update_item_list_ = nullptr;
  const ASTExpression* update_where_clause_ = nullptr;
};

// This is used for both top-level DELETE statements and for nested DELETEs
// inside ASTUpdateItem. When used at the top-level, the target is always a
// path expression.
class ASTDeleteStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DELETE_STATEMENT;

  ASTDeleteStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGeneralizedPathExpression* target_path() const { return target_path_; }
  const ASTHint* hint() const { return hint_; }
  const ASTAlias* alias() const { return alias_; }
  const ASTWithOffset* offset() const { return offset_; }
  const ASTExpression* where() const { return where_; }
  const ASTAssertRowsModified* assert_rows_modified() const { return assert_rows_modified_; }
  const ASTReturningClause* returning() const { return returning_; }

  // Verifies that the target path is an ASTPathExpression and, if so, returns
  // it. The behavior is undefined when called on a node that represents a
  // nested DELETE.
  absl::StatusOr<const ASTPathExpression*> GetTargetPathForNonNested() const;

  const ASTGeneralizedPathExpression* GetTargetPathForNested() const {
    return target_path_;
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&offset_, AST_WITH_OFFSET);
    fl.AddOptionalExpression(&where_);
    fl.AddOptional(&assert_rows_modified_, AST_ASSERT_ROWS_MODIFIED);
    fl.AddOptional(&returning_, AST_RETURNING_CLAUSE);
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* target_path_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTWithOffset* offset_ = nullptr;
  const ASTExpression* where_ = nullptr;
  const ASTAssertRowsModified* assert_rows_modified_ = nullptr;
  const ASTReturningClause* returning_ = nullptr;
};

class ASTColumnAttribute : public ASTNode {
 public:
  explicit ASTColumnAttribute(ASTNodeKind kind) : ASTNode(kind) {}

  virtual std::string SingleNodeSqlString() const = 0;

  friend class ParseTreeSerializer;
};

class ASTNotNullColumnAttribute final : public ASTColumnAttribute {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_NOT_NULL_COLUMN_ATTRIBUTE;

  ASTNotNullColumnAttribute() : ASTColumnAttribute(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeSqlString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTHiddenColumnAttribute final : public ASTColumnAttribute {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HIDDEN_COLUMN_ATTRIBUTE;

  ASTHiddenColumnAttribute() : ASTColumnAttribute(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeSqlString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTPrimaryKeyColumnAttribute final : public ASTColumnAttribute {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIMARY_KEY_COLUMN_ATTRIBUTE;

  ASTPrimaryKeyColumnAttribute() : ASTColumnAttribute(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_enforced(bool enforced) { enforced_ = enforced; }
  bool enforced() const { return enforced_; }

  std::string SingleNodeSqlString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  bool enforced_ = true;
};

class ASTForeignKeyColumnAttribute final : public ASTColumnAttribute {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOREIGN_KEY_COLUMN_ATTRIBUTE;

  ASTForeignKeyColumnAttribute() : ASTColumnAttribute(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* constraint_name() const { return constraint_name_; }
  const ASTForeignKeyReference* reference() const { return reference_; }

  std::string SingleNodeSqlString() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&constraint_name_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&reference_));
    return fl.Finalize();
  }

  const ASTIdentifier* constraint_name_ = nullptr;
  const ASTForeignKeyReference* reference_ = nullptr;
};

class ASTColumnAttributeList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_ATTRIBUTE_LIST;

  ASTColumnAttributeList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTColumnAttribute* const>& values() const {
    return values_;
  }
  const ASTColumnAttribute* values(int i) const { return values_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&values_);
    return fl.Finalize();
  }

  absl::Span<const ASTColumnAttribute* const> values_;
};

class ASTStructColumnField final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_COLUMN_FIELD;

  ASTStructColumnField() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // name_ will be NULL for anonymous fields like in STRUCT<int, string>.
  const ASTIdentifier* name() const { return name_; }

  const ASTColumnSchema* schema() const { return schema_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&name_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&schema_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTColumnSchema* schema_ = nullptr;
};

class ASTGeneratedColumnInfo final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GENERATED_COLUMN_INFO;

  ASTGeneratedColumnInfo() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Adds stored_mode and generated_mode to the debug string.
  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTGeneratedColumnInfoEnums::StoredMode in ast_enums.proto
  enum StoredMode {
    NON_STORED = ASTGeneratedColumnInfoEnums::NON_STORED,
    STORED = ASTGeneratedColumnInfoEnums::STORED,
    STORED_VOLATILE = ASTGeneratedColumnInfoEnums::STORED_VOLATILE
  };

  // This enum is equivalent to ASTGeneratedColumnInfoEnums::GeneratedMode in ast_enums.proto
  enum GeneratedMode {
    ALWAYS = ASTGeneratedColumnInfoEnums::ALWAYS,
    BY_DEFAULT = ASTGeneratedColumnInfoEnums::BY_DEFAULT
  };

  void set_stored_mode(ASTGeneratedColumnInfo::StoredMode stored_mode) { stored_mode_ = stored_mode; }
  ASTGeneratedColumnInfo::StoredMode stored_mode() const { return stored_mode_; }
  void set_generated_mode(ASTGeneratedColumnInfo::GeneratedMode generated_mode) { generated_mode_ = generated_mode; }
  ASTGeneratedColumnInfo::GeneratedMode generated_mode() const { return generated_mode_; }

  const ASTExpression* expression() const { return expression_; }
  const ASTIdentityColumnInfo* identity_column_info() const { return identity_column_info_; }

  std::string GetSqlForStoredMode() const;
  std::string GetSqlForGeneratedMode() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    fl.AddOptional(&identity_column_info_, AST_IDENTITY_COLUMN_INFO);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  ASTGeneratedColumnInfo::StoredMode stored_mode_ = ASTGeneratedColumnInfo::NON_STORED;
  ASTGeneratedColumnInfo::GeneratedMode generated_mode_ = ASTGeneratedColumnInfo::ALWAYS;
  const ASTIdentityColumnInfo* identity_column_info_ = nullptr;
};

// Base class for CREATE TABLE elements, including column definitions and
// table constraints.
class ASTTableElement : public ASTNode {
 public:
  explicit ASTTableElement(ASTNodeKind kind) : ASTNode(kind) {}

  friend class ParseTreeSerializer;
};

class ASTColumnDefinition final : public ASTTableElement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_DEFINITION;

  ASTColumnDefinition() : ASTTableElement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }
  const ASTColumnSchema* schema() const { return schema_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&schema_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTColumnSchema* schema_ = nullptr;
};

class ASTTableElementList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TABLE_ELEMENT_LIST;

  ASTTableElementList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTTableElement* const>& elements() const {
    return elements_;
  }
  const ASTTableElement* elements(int i) const { return elements_[i]; }

  bool HasConstraints() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&elements_);
    return fl.Finalize();
  }

  absl::Span<const ASTTableElement* const> elements_;
};

class ASTColumnList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_LIST;

  ASTColumnList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTIdentifier* const>& identifiers() const {
    return identifiers_;
  }
  const ASTIdentifier* identifiers(int i) const { return identifiers_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&identifiers_);
    return fl.Finalize();
  }

  absl::Span<const ASTIdentifier* const> identifiers_;
};

class ASTColumnPosition final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_POSITION;

  ASTColumnPosition() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTColumnPositionEnums::RelativePositionType in ast_enums.proto
  enum RelativePositionType {
    PRECEDING = ASTColumnPositionEnums::PRECEDING,
    FOLLOWING = ASTColumnPositionEnums::FOLLOWING
  };

  void set_type(ASTColumnPosition::RelativePositionType type) { type_ = type; }
  ASTColumnPosition::RelativePositionType type() const { return type_; }

  const ASTIdentifier* identifier() const { return identifier_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  ASTColumnPosition::RelativePositionType type_ = ASTColumnPosition::PRECEDING;
};

class ASTInsertValuesRow final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INSERT_VALUES_ROW;

  ASTInsertValuesRow() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // A row of values in a VALUES clause.  May include ASTDefaultLiteral.
  const absl::Span<const ASTExpression* const>& values() const {
    return values_;
  }
  const ASTExpression* values(int i) const { return values_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&values_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpression* const> values_;
};

class ASTInsertValuesRowList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INSERT_VALUES_ROW_LIST;

  ASTInsertValuesRowList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTInsertValuesRow* const>& rows() const {
    return rows_;
  }
  const ASTInsertValuesRow* rows(int i) const { return rows_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&rows_);
    return fl.Finalize();
  }

  absl::Span<const ASTInsertValuesRow* const> rows_;
};

// This is used for both top-level INSERT statements and for nested INSERTs
// inside ASTUpdateItem. When used at the top-level, the target is always a
// path expression.
class ASTInsertStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INSERT_STATEMENT;

  ASTInsertStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTInsertStatementEnums::InsertMode in ast_enums.proto
  enum InsertMode {
    DEFAULT_MODE = ASTInsertStatementEnums::DEFAULT_MODE,
    REPLACE = ASTInsertStatementEnums::REPLACE,
    UPDATE = ASTInsertStatementEnums::UPDATE,
    IGNORE = ASTInsertStatementEnums::IGNORE
  };

  // This enum is equivalent to ASTInsertStatementEnums::ParseProgress in ast_enums.proto
  enum ParseProgress {
    kInitial = ASTInsertStatementEnums::kInitial,
    kSeenOrIgnoreReplaceUpdate = ASTInsertStatementEnums::kSeenOrIgnoreReplaceUpdate,
    kSeenTargetPath = ASTInsertStatementEnums::kSeenTargetPath,
    kSeenColumnList = ASTInsertStatementEnums::kSeenColumnList,
    kSeenValuesList = ASTInsertStatementEnums::kSeenValuesList
  };

  // Deprecated
  void set_deprecated_parse_progress(int deprecated_parse_progress) { deprecated_parse_progress_ = deprecated_parse_progress; }
  int deprecated_parse_progress() const { return deprecated_parse_progress_; }

  void set_insert_mode(ASTInsertStatement::InsertMode insert_mode) { insert_mode_ = insert_mode; }
  ASTInsertStatement::InsertMode insert_mode() const { return insert_mode_; }

  const ASTGeneralizedPathExpression* target_path() const { return target_path_; }
  const ASTHint* hint() const { return hint_; }
  const ASTColumnList* column_list() const { return column_list_; }

  // Non-NULL rows() means we had a VALUES clause.
  // This is mutually exclusive with query() and with().
  const ASTInsertValuesRowList* rows() const { return rows_; }

  const ASTQuery* query() const { return query_; }
  const ASTOnConflictClause* on_conflict() const { return on_conflict_; }
  const ASTAssertRowsModified* assert_rows_modified() const { return assert_rows_modified_; }
  const ASTReturningClause* returning() const { return returning_; }

  const ASTGeneralizedPathExpression* GetTargetPathForNested() const {
     return target_path_;
  }

  std::string GetSQLForInsertMode() const;

  // Verifies that the target path is an ASTPathExpression and, if so, returns
  // it. The behavior is undefined when called on a node that represents a
  // nested INSERT.
  absl::StatusOr<const ASTPathExpression*> GetTargetPathForNonNested() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&column_list_, AST_COLUMN_LIST);
    fl.AddOptional(&rows_, AST_INSERT_VALUES_ROW_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&on_conflict_, AST_ON_CONFLICT_CLAUSE);
    fl.AddOptional(&assert_rows_modified_, AST_ASSERT_ROWS_MODIFIED);
    fl.AddOptional(&returning_, AST_RETURNING_CLAUSE);
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* target_path_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTColumnList* column_list_ = nullptr;

  // Exactly one of rows_ or query_ will be present.
  // with_ can be present if query_ is present.
  const ASTInsertValuesRowList* rows_ = nullptr;

  const ASTQuery* query_ = nullptr;
  const ASTOnConflictClause* on_conflict_ = nullptr;
  const ASTAssertRowsModified* assert_rows_modified_ = nullptr;
  const ASTReturningClause* returning_ = nullptr;
  int deprecated_parse_progress_ = 0;
  ASTInsertStatement::InsertMode insert_mode_ = ASTInsertStatement::DEFAULT_MODE;
};

class ASTUpdateSetValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UPDATE_SET_VALUE;

  ASTUpdateSetValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGeneralizedPathExpression* path() const { return path_; }

  // The rhs of SET X=Y.  May be ASTDefaultLiteral.
  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* path_ = nullptr;
  const ASTExpression* value_ = nullptr;
};

class ASTUpdateItem final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UPDATE_ITEM;

  ASTUpdateItem() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTUpdateSetValue* set_value() const { return set_value_; }
  const ASTInsertStatement* insert_statement() const { return insert_statement_; }
  const ASTDeleteStatement* delete_statement() const { return delete_statement_; }
  const ASTUpdateStatement* update_statement() const { return update_statement_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&set_value_, AST_UPDATE_SET_VALUE);
    fl.AddOptional(&insert_statement_, AST_INSERT_STATEMENT);
    fl.AddOptional(&delete_statement_, AST_DELETE_STATEMENT);
    fl.AddOptional(&update_statement_, AST_UPDATE_STATEMENT);
    return fl.Finalize();
  }

  // Exactly one of set_value, insert_statement, delete_statement
  // or update_statement will be non-NULL.
  const ASTUpdateSetValue* set_value_ = nullptr;

  const ASTInsertStatement* insert_statement_ = nullptr;
  const ASTDeleteStatement* delete_statement_ = nullptr;
  const ASTUpdateStatement* update_statement_ = nullptr;
};

class ASTUpdateItemList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UPDATE_ITEM_LIST;

  ASTUpdateItemList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTUpdateItem* const>& update_items() const {
    return update_items_;
  }
  const ASTUpdateItem* update_items(int i) const { return update_items_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&update_items_);
    return fl.Finalize();
  }

  absl::Span<const ASTUpdateItem* const> update_items_;
};

// This is used for both top-level UPDATE statements and for nested UPDATEs
// inside ASTUpdateItem. When used at the top-level, the target is always a
// path expression.
class ASTUpdateStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UPDATE_STATEMENT;

  ASTUpdateStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGeneralizedPathExpression* target_path() const { return target_path_; }
  const ASTHint* hint() const { return hint_; }
  const ASTAlias* alias() const { return alias_; }
  const ASTWithOffset* offset() const { return offset_; }
  const ASTUpdateItemList* update_item_list() const { return update_item_list_; }
  const ASTFromClause* from_clause() const { return from_clause_; }
  const ASTExpression* where() const { return where_; }
  const ASTAssertRowsModified* assert_rows_modified() const { return assert_rows_modified_; }
  const ASTReturningClause* returning() const { return returning_; }

  const ASTGeneralizedPathExpression* GetTargetPathForNested() const {
    return target_path_;
  }

  // Verifies that the target path is an ASTPathExpression and, if so, returns
  // it. The behavior is undefined when called on a node that represents a
  // nested UPDATE.
  absl::StatusOr<const ASTPathExpression*> GetTargetPathForNonNested() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&offset_, AST_WITH_OFFSET);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&update_item_list_));
    fl.AddOptional(&from_clause_, AST_FROM_CLAUSE);
    fl.AddOptionalExpression(&where_);
    fl.AddOptional(&assert_rows_modified_, AST_ASSERT_ROWS_MODIFIED);
    fl.AddOptional(&returning_, AST_RETURNING_CLAUSE);
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* target_path_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTWithOffset* offset_ = nullptr;
  const ASTUpdateItemList* update_item_list_ = nullptr;
  const ASTFromClause* from_clause_ = nullptr;
  const ASTExpression* where_ = nullptr;
  const ASTAssertRowsModified* assert_rows_modified_ = nullptr;
  const ASTReturningClause* returning_ = nullptr;
};

class ASTTruncateStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TRUNCATE_STATEMENT;

  ASTTruncateStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTExpression* where() const { return where_; }

  // Verifies that the target path is an ASTPathExpression and, if so, returns
  // it. The behavior is undefined when called on a node that represents a
  // nested TRUNCATE (but this is not allowed by the parser).
  absl::StatusOr<const ASTPathExpression*> GetTargetPathForNonNested() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptionalExpression(&where_);
    return fl.Finalize();
  }

  const ASTPathExpression* target_path_ = nullptr;
  const ASTExpression* where_ = nullptr;
};

class ASTMergeAction final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MERGE_ACTION;

  ASTMergeAction() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTMergeActionEnums::ActionType in ast_enums.proto
  enum ActionType {
    NOT_SET = ASTMergeActionEnums::NOT_SET,
    INSERT = ASTMergeActionEnums::INSERT,
    UPDATE = ASTMergeActionEnums::UPDATE,
    DELETE = ASTMergeActionEnums::DELETE
  };

  void set_action_type(ASTMergeAction::ActionType action_type) { action_type_ = action_type; }
  ASTMergeAction::ActionType action_type() const { return action_type_; }

  // Exactly one of the INSERT/UPDATE/DELETE operation must be defined in
  // following ways,
  //   -- INSERT, action_type() is INSERT. The insert_column_list() is optional.
  //      The insert_row() must be non-null, but may have an empty value list.
  //   -- UPDATE, action_type() is UPDATE. update_item_list() is non-null.
  //   -- DELETE, action_type() is DELETE.
  const ASTColumnList* insert_column_list() const { return insert_column_list_; }

  const ASTInsertValuesRow* insert_row() const { return insert_row_; }
  const ASTUpdateItemList* update_item_list() const { return update_item_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&insert_column_list_, AST_COLUMN_LIST);
    fl.AddOptional(&insert_row_, AST_INSERT_VALUES_ROW);
    fl.AddOptional(&update_item_list_, AST_UPDATE_ITEM_LIST);
    return fl.Finalize();
  }

  // For INSERT operation.
  const ASTColumnList* insert_column_list_ = nullptr;

  const ASTInsertValuesRow* insert_row_ = nullptr;

  // For UPDATE operation.
  const ASTUpdateItemList* update_item_list_ = nullptr;

  // Merge action type.
  ASTMergeAction::ActionType action_type_ = ASTMergeAction::NOT_SET;
};

class ASTMergeWhenClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MERGE_WHEN_CLAUSE;

  ASTMergeWhenClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTMergeWhenClauseEnums::MatchType in ast_enums.proto
  enum MatchType {
    NOT_SET = ASTMergeWhenClauseEnums::NOT_SET,
    MATCHED = ASTMergeWhenClauseEnums::MATCHED,
    NOT_MATCHED_BY_SOURCE = ASTMergeWhenClauseEnums::NOT_MATCHED_BY_SOURCE,
    NOT_MATCHED_BY_TARGET = ASTMergeWhenClauseEnums::NOT_MATCHED_BY_TARGET
  };

  void set_match_type(ASTMergeWhenClause::MatchType match_type) { match_type_ = match_type; }
  ASTMergeWhenClause::MatchType match_type() const { return match_type_; }

  const ASTExpression* search_condition() const { return search_condition_; }
  const ASTMergeAction* action() const { return action_; }

  std::string GetSQLForMatchType() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&search_condition_);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_));
    return fl.Finalize();
  }

  const ASTExpression* search_condition_ = nullptr;
  const ASTMergeAction* action_ = nullptr;
  ASTMergeWhenClause::MatchType match_type_ = ASTMergeWhenClause::NOT_SET;
};

class ASTMergeWhenClauseList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MERGE_WHEN_CLAUSE_LIST;

  ASTMergeWhenClauseList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTMergeWhenClause* const>& clause_list() const {
    return clause_list_;
  }
  const ASTMergeWhenClause* clause_list(int i) const { return clause_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&clause_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTMergeWhenClause* const> clause_list_;
};

class ASTMergeStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MERGE_STATEMENT;

  ASTMergeStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTAlias* alias() const { return alias_; }
  const ASTTableExpression* table_expression() const { return table_expression_; }
  const ASTExpression* merge_condition() const { return merge_condition_; }
  const ASTMergeWhenClauseList* when_clauses() const { return when_clauses_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptional(&alias_, AST_ALIAS);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_expression_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&merge_condition_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&when_clauses_));
    return fl.Finalize();
  }

  const ASTPathExpression* target_path_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTTableExpression* table_expression_ = nullptr;
  const ASTExpression* merge_condition_ = nullptr;
  const ASTMergeWhenClauseList* when_clauses_ = nullptr;
};

class ASTPrivilege final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIVILEGE;

  ASTPrivilege() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* privilege_action() const { return privilege_action_; }
  const ASTPathExpressionList* paths() const { return paths_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privilege_action_));
    fl.AddOptional(&paths_, AST_PATH_EXPRESSION_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* privilege_action_ = nullptr;
  const ASTPathExpressionList* paths_ = nullptr;
};

// Represents privileges to be granted or revoked. It can be either or a
// non-empty list of ASTPrivilege, or "ALL PRIVILEGES" in which case the list
// will be empty.
class ASTPrivileges final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIVILEGES;

  ASTPrivileges() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPrivilege* const>& privileges() const {
    return privileges_;
  }
  const ASTPrivilege* privileges(int i) const { return privileges_[i]; }

  bool is_all_privileges() const {
    // Empty Span means ALL PRIVILEGES.
    return privileges_.empty();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&privileges_);
    return fl.Finalize();
  }

  absl::Span<const ASTPrivilege* const> privileges_;
};

class ASTGranteeList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRANTEE_LIST;

  ASTGranteeList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExpression* const>& grantee_list() const {
    return grantee_list_;
  }
  const ASTExpression* grantee_list(int i) const { return grantee_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&grantee_list_);
    return fl.Finalize();
  }

  // An ASTGranteeList element may either be a string literal or
  // parameter.
  absl::Span<const ASTExpression* const> grantee_list_;
};

class ASTGrantStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRANT_STATEMENT;

  ASTGrantStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPrivileges* privileges() const { return privileges_; }
  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTGranteeList* grantee_list() const { return grantee_list_; }

  const absl::Span<const ASTIdentifier* const>& target_type_parts() const {
    return target_type_parts_;
  }
  const ASTIdentifier* target_type_parts(int i) const { return target_type_parts_[i]; }

      ABSL_DEPRECATED("Use `target_type_parts()` instead")
      inline const ASTIdentifier* target_type() const {
          if (target_type_parts().empty()) {
              return nullptr;
          }

          return target_type_parts()[0];
      }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privileges_));
    fl.AddRepeatedWhileIsNodeKind(&target_type_parts_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&grantee_list_));
    return fl.Finalize();
  }

  const ASTPrivileges* privileges_ = nullptr;
  absl::Span<const ASTIdentifier* const> target_type_parts_;
  const ASTPathExpression* target_path_ = nullptr;
  const ASTGranteeList* grantee_list_ = nullptr;
};

class ASTRevokeStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REVOKE_STATEMENT;

  ASTRevokeStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPrivileges* privileges() const { return privileges_; }
  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTGranteeList* grantee_list() const { return grantee_list_; }

  const absl::Span<const ASTIdentifier* const>& target_type_parts() const {
    return target_type_parts_;
  }
  const ASTIdentifier* target_type_parts(int i) const { return target_type_parts_[i]; }

      ABSL_DEPRECATED("Use `target_type_parts()` instead")
      inline const ASTIdentifier* target_type() const {
          if (target_type_parts().empty()) {
              return nullptr;
          }

          return target_type_parts()[0];
      }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privileges_));
    fl.AddRepeatedWhileIsNodeKind(&target_type_parts_, AST_IDENTIFIER);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&grantee_list_));
    return fl.Finalize();
  }

  const ASTPrivileges* privileges_ = nullptr;
  absl::Span<const ASTIdentifier* const> target_type_parts_;
  const ASTPathExpression* target_path_ = nullptr;
  const ASTGranteeList* grantee_list_ = nullptr;
};

class ASTRepeatableClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REPEATABLE_CLAUSE;

  ASTRepeatableClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* argument() const { return argument_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&argument_));
    return fl.Finalize();
  }

  const ASTExpression* argument_ = nullptr;
};

class ASTFilterFieldsArg final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FILTER_FIELDS_ARG;

  ASTFilterFieldsArg() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTFilterFieldsArgEnums::FilterType in ast_enums.proto
  enum FilterType {
    NOT_SET = ASTFilterFieldsArgEnums::NOT_SET,
    INCLUDE = ASTFilterFieldsArgEnums::INCLUDE,
    EXCLUDE = ASTFilterFieldsArgEnums::EXCLUDE
  };

  void set_filter_type(ASTFilterFieldsArg::FilterType filter_type) { filter_type_ = filter_type; }
  ASTFilterFieldsArg::FilterType filter_type() const { return filter_type_; }

  const ASTGeneralizedPathExpression* path_expression() const { return path_expression_; }

  std::string GetSQLForOperator() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_expression_));
    return fl.Finalize();
  }

  const ASTGeneralizedPathExpression* path_expression_ = nullptr;
  ASTFilterFieldsArg::FilterType filter_type_ = ASTFilterFieldsArg::NOT_SET;
};

class ASTReplaceFieldsArg final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REPLACE_FIELDS_ARG;

  ASTReplaceFieldsArg() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }
  const ASTGeneralizedPathExpression* path_expression() const { return path_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTGeneralizedPathExpression* path_expression_ = nullptr;
};

class ASTReplaceFieldsExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REPLACE_FIELDS_EXPRESSION;

  ASTReplaceFieldsExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expr() const { return expr_; }

  const absl::Span<const ASTReplaceFieldsArg* const>& arguments() const {
    return arguments_;
  }
  const ASTReplaceFieldsArg* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expr_));
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  const ASTExpression* expr_ = nullptr;
  absl::Span<const ASTReplaceFieldsArg* const> arguments_;
};

class ASTSampleSize final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SAMPLE_SIZE;

  ASTSampleSize() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTSampleSizeEnums::Unit in ast_enums.proto
  enum Unit {
    NOT_SET = ASTSampleSizeEnums::NOT_SET,
    ROWS = ASTSampleSizeEnums::ROWS,
    PERCENT = ASTSampleSizeEnums::PERCENT
  };

  // Returns the token kind corresponding to the sample-size unit, i.e.
  // parser::ROWS or parser::PERCENT.
  void set_unit(ASTSampleSize::Unit unit) { unit_ = unit; }
  ASTSampleSize::Unit unit() const { return unit_; }

  const ASTExpression* size() const { return size_; }
  const ASTPartitionBy* partition_by() const { return partition_by_; }

  // Returns the SQL keyword for the sample-size unit, i.e. "ROWS" or "PERCENT".
  std::string GetSQLForUnit() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&size_));
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    return fl.Finalize();
  }

  const ASTExpression* size_ = nullptr;

  // Can only be non-NULL when 'unit_' is parser::ROWS.
  const ASTPartitionBy* partition_by_ = nullptr;

  ASTSampleSize::Unit unit_ = ASTSampleSize::NOT_SET;
};

class ASTWithWeight final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_WEIGHT;

  ASTWithWeight() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // alias may be NULL.
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTAlias* alias_ = nullptr;
};

class ASTSampleSuffix final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SAMPLE_SUFFIX;

  ASTSampleSuffix() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // weight and repeat may be NULL.
  const ASTWithWeight* weight() const { return weight_; }

  const ASTRepeatableClause* repeat() const { return repeat_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&weight_, AST_WITH_WEIGHT);
    fl.AddOptional(&repeat_, AST_REPEATABLE_CLAUSE);
    return fl.Finalize();
  }

  const ASTWithWeight* weight_ = nullptr;
  const ASTRepeatableClause* repeat_ = nullptr;
};

class ASTSampleClause final : public ASTPostfixTableOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SAMPLE_CLAUSE;

  ASTSampleClause() : ASTPostfixTableOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* sample_method() const { return sample_method_; }
  const ASTSampleSize* sample_size() const { return sample_size_; }
  const ASTSampleSuffix* sample_suffix() const { return sample_suffix_; }

  absl::string_view Name() const override { return "TABLESAMPLE"; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sample_method_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sample_size_));
    fl.AddOptional(&sample_suffix_, AST_SAMPLE_SUFFIX);
    return fl.Finalize();
  }

  const ASTIdentifier* sample_method_ = nullptr;
  const ASTSampleSize* sample_size_ = nullptr;
  const ASTSampleSuffix* sample_suffix_ = nullptr;
};

// Common parent for all actions in ALTER statements
class ASTAlterAction : public ASTNode {
 public:
  explicit ASTAlterAction(ASTNodeKind kind) : ASTNode(kind) {}

  virtual std::string GetSQLForAlterAction() const = 0;

  friend class ParseTreeSerializer;
};

// ALTER action for "SET OPTIONS ()" clause
class ASTSetOptionsAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_OPTIONS_ACTION;

  ASTSetOptionsAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&options_list_));
    return fl.Finalize();
  }

  const ASTOptionsList* options_list_ = nullptr;
};

// ALTER action for "SET AS" clause
class ASTSetAsAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_AS_ACTION;

  ASTSetAsAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTJSONLiteral* json_body() const { return json_body_; }
  const ASTStringLiteral* text_body() const { return text_body_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&json_body_, AST_JSON_LITERAL);
    fl.AddOptional(&text_body_, AST_STRING_LITERAL);
    return fl.Finalize();
  }

  const ASTJSONLiteral* json_body_ = nullptr;
  const ASTStringLiteral* text_body_ = nullptr;
};

// ALTER table action for "ADD CONSTRAINT" clause
class ASTAddConstraintAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_CONSTRAINT_ACTION;

  ASTAddConstraintAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTTableConstraint* constraint() const { return constraint_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&constraint_));
    return fl.Finalize();
  }

  const ASTTableConstraint* constraint_ = nullptr;
  bool is_if_not_exists_ = false;
};

// ALTER table action for "DROP PRIMARY KEY" clause
class ASTDropPrimaryKeyAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_PRIMARY_KEY_ACTION;

  ASTDropPrimaryKeyAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  bool is_if_exists_ = false;
};

// ALTER table action for "DROP CONSTRAINT" clause
class ASTDropConstraintAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_CONSTRAINT_ACTION;

  ASTDropConstraintAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* constraint_name() const { return constraint_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&constraint_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* constraint_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER CONSTRAINT identifier [NOT] ENFORCED" clause
class ASTAlterConstraintEnforcementAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_CONSTRAINT_ENFORCEMENT_ACTION;

  ASTAlterConstraintEnforcementAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }
  void set_is_enforced(bool is_enforced) { is_enforced_ = is_enforced; }
  bool is_enforced() const { return is_enforced_; }

  const ASTIdentifier* constraint_name() const { return constraint_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&constraint_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* constraint_name_ = nullptr;
  bool is_if_exists_ = false;
  bool is_enforced_ = true;
};

// ALTER table action for "ALTER CONSTRAINT identifier SET OPTIONS" clause
class ASTAlterConstraintSetOptionsAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_CONSTRAINT_SET_OPTIONS_ACTION;

  ASTAlterConstraintSetOptionsAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* constraint_name() const { return constraint_name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&constraint_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&options_list_));
    return fl.Finalize();
  }

  const ASTIdentifier* constraint_name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER SEARCH|VECTOR INDEX action for "ADD COLUMN" clause.
// Note: Different from ASTAddColumnAction, this action is used for adding an
// existing column in table to an index, so it doesn't need column definition
// or other fields in ASTAddColumnAction.
class ASTAddColumnIdentifierAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_COLUMN_IDENTIFIER_ACTION;

  ASTAddColumnIdentifierAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  bool is_if_not_exists_ = false;
};

// ALTER table action for "ADD COLUMN" clause
class ASTAddColumnAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_COLUMN_ACTION;

  ASTAddColumnAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTColumnDefinition* column_definition() const { return column_definition_; }

  // Optional children.
  const ASTColumnPosition* column_position() const { return column_position_; }

  const ASTExpression* fill_expression() const { return fill_expression_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_definition_));
    fl.AddOptional(&column_position_, AST_COLUMN_POSITION);
    fl.AddOptionalExpression(&fill_expression_);
    return fl.Finalize();
  }

  const ASTColumnDefinition* column_definition_ = nullptr;
  const ASTColumnPosition* column_position_ = nullptr;
  const ASTExpression* fill_expression_ = nullptr;
  bool is_if_not_exists_ = false;
};

// ALTER table action for "DROP COLUMN" clause
class ASTDropColumnAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_COLUMN_ACTION;

  ASTDropColumnAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "RENAME COLUMN" clause
class ASTRenameColumnAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RENAME_COLUMN_ACTION;

  ASTRenameColumnAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTIdentifier* new_column_name() const { return new_column_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&new_column_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTIdentifier* new_column_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN SET TYPE" clause
class ASTAlterColumnTypeAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_TYPE_ACTION;

  ASTAlterColumnTypeAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTColumnSchema* schema() const { return schema_; }
  const ASTCollate* collate() const { return collate_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&schema_));
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTColumnSchema* schema_ = nullptr;
  const ASTCollate* collate_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN SET OPTIONS" clause
class ASTAlterColumnOptionsAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_OPTIONS_ACTION;

  ASTAlterColumnOptionsAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&options_list_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN SET DEFAULT" clause
class ASTAlterColumnSetDefaultAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_SET_DEFAULT_ACTION;

  ASTAlterColumnSetDefaultAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTExpression* default_expression() const { return default_expression_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&default_expression_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTExpression* default_expression_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN DROP DEFAULT" clause
class ASTAlterColumnDropDefaultAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_DROP_DEFAULT_ACTION;

  ASTAlterColumnDropDefaultAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN DROP NOT NULL" clause
class ASTAlterColumnDropNotNullAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_DROP_NOT_NULL_ACTION;

  ASTAlterColumnDropNotNullAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN DROP GENERATED" clause
class ASTAlterColumnDropGeneratedAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_DROP_GENERATED_ACTION;

  ASTAlterColumnDropGeneratedAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER table action for "ALTER COLUMN SET GENERATED" clause
class ASTAlterColumnSetGeneratedAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_COLUMN_SET_GENERATED_ACTION;

  ASTAlterColumnSetGeneratedAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* column_name() const { return column_name_; }
  const ASTGeneratedColumnInfo* generated_column_info() const { return generated_column_info_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&generated_column_info_));
    return fl.Finalize();
  }

  const ASTIdentifier* column_name_ = nullptr;
  const ASTGeneratedColumnInfo* generated_column_info_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER ROW ACCESS POLICY action for "GRANT TO (<grantee_list>)" or "TO
// <grantee_list>" clause, also used by CREATE ROW ACCESS POLICY
class ASTGrantToClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRANT_TO_CLAUSE;

  ASTGrantToClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_has_grant_keyword_and_parens(bool has_grant_keyword_and_parens) { has_grant_keyword_and_parens_ = has_grant_keyword_and_parens; }
  bool has_grant_keyword_and_parens() const { return has_grant_keyword_and_parens_; }

  const ASTGranteeList* grantee_list() const { return grantee_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&grantee_list_));
    return fl.Finalize();
  }

  const ASTGranteeList* grantee_list_ = nullptr;
  bool has_grant_keyword_and_parens_ = false;
};

// ALTER PRIVILEGE RESTRICTION action for "RESTRICT TO (<restrictee_list>)"
// clause, also used by CREATE PRIVILEGE RESTRICTION
class ASTRestrictToClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RESTRICT_TO_CLAUSE;

  ASTRestrictToClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGranteeList* restrictee_list() const { return restrictee_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&restrictee_list_));
    return fl.Finalize();
  }

  const ASTGranteeList* restrictee_list_ = nullptr;
};

// ALTER PRIVILEGE RESTRICTION action for "ADD (<restrictee_list>)" clause
class ASTAddToRestricteeListClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_TO_RESTRICTEE_LIST_CLAUSE;

  ASTAddToRestricteeListClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTGranteeList* restrictee_list() const { return restrictee_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&restrictee_list_));
    return fl.Finalize();
  }

  bool is_if_not_exists_ = false;
  const ASTGranteeList* restrictee_list_ = nullptr;
};

// ALTER PRIVILEGE RESTRICTION action for "REMOVE (<restrictee_list>)" clause
class ASTRemoveFromRestricteeListClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REMOVE_FROM_RESTRICTEE_LIST_CLAUSE;

  ASTRemoveFromRestricteeListClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTGranteeList* restrictee_list() const { return restrictee_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&restrictee_list_));
    return fl.Finalize();
  }

  bool is_if_exists_ = false;
  const ASTGranteeList* restrictee_list_ = nullptr;
};

// ALTER ROW ACCESS POLICY action for "[FILTER] USING (<expression>)" clause,
// also used by CREATE ROW ACCESS POLICY
class ASTFilterUsingClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FILTER_USING_CLAUSE;

  ASTFilterUsingClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_has_filter_keyword(bool has_filter_keyword) { has_filter_keyword_ = has_filter_keyword; }
  bool has_filter_keyword() const { return has_filter_keyword_; }

  const ASTExpression* predicate() const { return predicate_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&predicate_));
    return fl.Finalize();
  }

  const ASTExpression* predicate_ = nullptr;
  bool has_filter_keyword_ = false;
};

// ALTER ROW ACCESS POLICY action for "REVOKE FROM (<grantee_list>)|ALL" clause
class ASTRevokeFromClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REVOKE_FROM_CLAUSE;

  ASTRevokeFromClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_revoke_from_all(bool is_revoke_from_all) { is_revoke_from_all_ = is_revoke_from_all; }
  bool is_revoke_from_all() const { return is_revoke_from_all_; }

  const ASTGranteeList* revoke_from_list() const { return revoke_from_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&revoke_from_list_, AST_GRANTEE_LIST);
    return fl.Finalize();
  }

  const ASTGranteeList* revoke_from_list_ = nullptr;
  bool is_revoke_from_all_ = false;
};

// ALTER ROW ACCESS POLICY action for "RENAME TO <new_name>" clause,
// and ALTER table action for "RENAME TO" clause.
class ASTRenameToClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RENAME_TO_CLAUSE;

  ASTRenameToClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* new_name() const { return new_name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&new_name_));
    return fl.Finalize();
  }

  const ASTPathExpression* new_name_ = nullptr;
};

// ALTER action for "SET COLLATE ()" clause
class ASTSetCollateClause final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SET_COLLATE_CLAUSE;

  ASTSetCollateClause() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTCollate* collate() const { return collate_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&collate_));
    return fl.Finalize();
  }

  const ASTCollate* collate_ = nullptr;
};

// ALTER action for "ALTER <subentity>" clause
class ASTAlterSubEntityAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_SUB_ENTITY_ACTION;

  ASTAlterSubEntityAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* type() const { return type_; }
  const ASTIdentifier* name() const { return name_; }
  const ASTAlterAction* action() const { return action_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_));
    return fl.Finalize();
  }

  const ASTIdentifier* type_ = nullptr;
  const ASTIdentifier* name_ = nullptr;
  const ASTAlterAction* action_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER action for "ADD <subentity>" clause
class ASTAddSubEntityAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_SUB_ENTITY_ACTION;

  ASTAddSubEntityAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTIdentifier* type() const { return type_; }
  const ASTIdentifier* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* type_ = nullptr;
  const ASTIdentifier* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  bool is_if_not_exists_ = false;
};

// ALTER action for "DROP <subentity>" clause
class ASTDropSubEntityAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_SUB_ENTITY_ACTION;

  ASTDropSubEntityAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTIdentifier* type() const { return type_; }
  const ASTIdentifier* name() const { return name_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* type_ = nullptr;
  const ASTIdentifier* name_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER action for "ADD ROW DELETION POLICY clause
class ASTAddTtlAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ADD_TTL_ACTION;

  ASTAddTtlAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTExpression* expression() const { return expression_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  bool is_if_not_exists_ = false;
};

// ALTER action for "REPLACE ROW DELETION POLICY clause
class ASTReplaceTtlAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REPLACE_TTL_ACTION;

  ASTReplaceTtlAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTExpression* expression() const { return expression_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  bool is_if_exists_ = false;
};

// ALTER action for "DROP ROW DELETION POLICY clause
class ASTDropTtlAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_TTL_ACTION;

  ASTDropTtlAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  bool is_if_exists_ = false;
};

class ASTAlterActionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_ACTION_LIST;

  ASTAlterActionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTAlterAction* const>& actions() const {
    return actions_;
  }
  const ASTAlterAction* actions(int i) const { return actions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&actions_);
    return fl.Finalize();
  }

  absl::Span<const ASTAlterAction* const> actions_;
};

class ASTAlterAllRowAccessPoliciesStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_ALL_ROW_ACCESS_POLICIES_STATEMENT;

  ASTAlterAllRowAccessPoliciesStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* table_name_path() const { return table_name_path_; }
  const ASTAlterAction* alter_action() const { return alter_action_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_path_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&alter_action_));
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_path_ = nullptr;
  const ASTAlterAction* alter_action_ = nullptr;
};

class ASTForeignKeyActions final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOREIGN_KEY_ACTIONS;

  ASTForeignKeyActions() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTForeignKeyActionsEnums::Action in ast_enums.proto
  enum Action {
    NO_ACTION = ASTForeignKeyActionsEnums::NO_ACTION,
    RESTRICT = ASTForeignKeyActionsEnums::RESTRICT,
    CASCADE = ASTForeignKeyActionsEnums::CASCADE,
    SET_NULL = ASTForeignKeyActionsEnums::SET_NULL
  };

  void set_update_action(ASTForeignKeyActions::Action update_action) { update_action_ = update_action; }
  ASTForeignKeyActions::Action update_action() const { return update_action_; }
  void set_delete_action(ASTForeignKeyActions::Action delete_action) { delete_action_ = delete_action; }
  ASTForeignKeyActions::Action delete_action() const { return delete_action_; }

  static std::string GetSQLForAction(Action action);

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTForeignKeyActions::Action update_action_ = ASTForeignKeyActions::NO_ACTION;
  ASTForeignKeyActions::Action delete_action_ = ASTForeignKeyActions::NO_ACTION;
};

class ASTForeignKeyReference final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOREIGN_KEY_REFERENCE;

  ASTForeignKeyReference() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTForeignKeyReferenceEnums::Match in ast_enums.proto
  enum Match {
    SIMPLE = ASTForeignKeyReferenceEnums::SIMPLE,
    FULL = ASTForeignKeyReferenceEnums::FULL,
    NOT_DISTINCT = ASTForeignKeyReferenceEnums::NOT_DISTINCT
  };

  void set_match(ASTForeignKeyReference::Match match) { match_ = match; }
  ASTForeignKeyReference::Match match() const { return match_; }
  void set_enforced(bool enforced) { enforced_ = enforced; }
  bool enforced() const { return enforced_; }

  const ASTPathExpression* table_name() const { return table_name_; }
  const ASTColumnList* column_list() const { return column_list_; }
  const ASTForeignKeyActions* actions() const { return actions_; }

  std::string GetSQLForMatch() const;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_list_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&actions_));
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_ = nullptr;
  const ASTColumnList* column_list_ = nullptr;
  const ASTForeignKeyActions* actions_ = nullptr;
  ASTForeignKeyReference::Match match_ = ASTForeignKeyReference::SIMPLE;
  bool enforced_ = true;
};

// A top-level script.
class ASTScript final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SCRIPT;

  ASTScript() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTStatementList* statement_list_node() const { return statement_list_node_; }

  absl::Span<const ASTStatement* const> statement_list() const {
    return statement_list_node_->statement_list();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_list_node_));
    return fl.Finalize();
  }

  const ASTStatementList* statement_list_node_ = nullptr;
};

// Represents an ELSEIF clause in an IF statement.
class ASTElseifClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ELSEIF_CLAUSE;

  ASTElseifClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // condition and body are both required.
  const ASTExpression* condition() const { return condition_; }

  const ASTStatementList* body() const { return body_; }

  // Returns the ASTIfStatement that this ASTElseifClause belongs to.
  const ASTIfStatement* if_stmt() const {
    return parent()->parent()->GetAsOrDie<ASTIfStatement>();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
  const ASTStatementList* body_ = nullptr;
};

// Represents a list of ELSEIF clauses.  Note that this list is never empty,
// as the grammar will not create an ASTElseifClauseList object unless there
// exists at least one ELSEIF clause.
class ASTElseifClauseList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ELSEIF_CLAUSE_LIST;

  ASTElseifClauseList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTElseifClause* const>& elseif_clauses() const {
    return elseif_clauses_;
  }
  const ASTElseifClause* elseif_clauses(int i) const { return elseif_clauses_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&elseif_clauses_);
    return fl.Finalize();
  }

  absl::Span<const ASTElseifClause* const> elseif_clauses_;
};

class ASTIfStatement final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IF_STATEMENT;

  ASTIfStatement() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // condition and then_list are both required.
  const ASTExpression* condition() const { return condition_; }

  const ASTStatementList* then_list() const { return then_list_; }

  // Optional; nullptr if no ELSEIF clauses are specified.  If present, the
  // list will never be empty.
  const ASTElseifClauseList* elseif_clauses() const { return elseif_clauses_; }

  // Optional; nullptr if no ELSE clause is specified
  const ASTStatementList* else_list() const { return else_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&then_list_));
    fl.AddOptional(&elseif_clauses_, AST_ELSEIF_CLAUSE_LIST);
    fl.AddOptional(&else_list_, AST_STATEMENT_LIST);
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
  const ASTStatementList* then_list_ = nullptr;
  const ASTElseifClauseList* elseif_clauses_ = nullptr;
  const ASTStatementList* else_list_ = nullptr;
};

// Represents a WHEN...THEN clause in a CASE statement.
class ASTWhenThenClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WHEN_THEN_CLAUSE;

  ASTWhenThenClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // condition and body are both required.
  const ASTExpression* condition() const { return condition_; }

  const ASTStatementList* body() const { return body_; }

  // Returns the ASTCaseStatement that this ASTWhenThenClause belongs to.
  // Immediate parent is an ASTWhenThenClauseList, contained in an
  // ASTCaseStatement.
  const ASTCaseStatement* case_stmt() const {
    return parent()->parent()->GetAsOrDie<ASTCaseStatement>();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
  const ASTStatementList* body_ = nullptr;
};

// Represents a list of WHEN...THEN clauses. Note that this list is never empty,
// as the grammar mandates that there is at least one WHEN...THEN clause in
// a CASE statement.
class ASTWhenThenClauseList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WHEN_THEN_CLAUSE_LIST;

  ASTWhenThenClauseList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTWhenThenClause* const>& when_then_clauses() const {
    return when_then_clauses_;
  }
  const ASTWhenThenClause* when_then_clauses(int i) const { return when_then_clauses_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&when_then_clauses_);
    return fl.Finalize();
  }

  absl::Span<const ASTWhenThenClause* const> when_then_clauses_;
};

class ASTCaseStatement final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CASE_STATEMENT;

  ASTCaseStatement() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Optional; nullptr if not specified
  const ASTExpression* expression() const { return expression_; }

  // Required field.
  const ASTWhenThenClauseList* when_then_clauses() const { return when_then_clauses_; }

  const ASTStatementList* else_list() const { return else_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&expression_);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&when_then_clauses_));
    fl.AddOptional(&else_list_, AST_STATEMENT_LIST);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTWhenThenClauseList* when_then_clauses_ = nullptr;
  const ASTStatementList* else_list_ = nullptr;
};

class ASTHint final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HINT;

  ASTHint() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This is the @num_shards hint shorthand that can occur anywhere that a
  // hint can occur, prior to @{...} hints.
  // At least one of num_shards_hints is non-NULL or hint_entries is non-empty.
  const ASTIntLiteral* num_shards_hint() const { return num_shards_hint_; }

  const absl::Span<const ASTHintEntry* const>& hint_entries() const {
    return hint_entries_;
  }
  const ASTHintEntry* hint_entries(int i) const { return hint_entries_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&num_shards_hint_, AST_INT_LITERAL);
    fl.AddRestAsRepeated(&hint_entries_);
    return fl.Finalize();
  }

  const ASTIntLiteral* num_shards_hint_ = nullptr;
  absl::Span<const ASTHintEntry* const> hint_entries_;
};

class ASTHintEntry final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_HINT_ENTRY;

  ASTHintEntry() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* qualifier() const { return qualifier_; }
  const ASTIdentifier* name() const { return name_; }

  // Value may be any expression; engines can decide whether they
  // support identifiers, literals, parameters, constants, etc.
  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  const ASTIdentifier* qualifier_ = nullptr;
  const ASTIdentifier* name_ = nullptr;
  const ASTExpression* value_ = nullptr;

  absl::Status InitFields() final {
    // We need a special case here because we have two children that both have
    // type ASTIdentifier and the first one is optional.
    if (num_children() == 2) {
      FieldLoader fl(this);
      GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
      GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
      return fl.Finalize();
    } else {
      FieldLoader fl(this);
      GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&qualifier_));
      GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
      GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
      return fl.Finalize();
    }
  }
};

class ASTUnpivotInItemLabel final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNPIVOT_IN_ITEM_LABEL;

  ASTUnpivotInItemLabel() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* label() const {
    if (string_label_ != nullptr) {
      return string_label_;
    }
    return int_label_;
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&string_label_, AST_STRING_LITERAL);
    fl.AddOptional(&int_label_, AST_INT_LITERAL);
    return fl.Finalize();
  }

  const ASTStringLiteral* string_label_ = nullptr;
  const ASTIntLiteral* int_label_ = nullptr;
};

class ASTDescriptor final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DESCRIPTOR;

  ASTDescriptor() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTDescriptorColumnList* columns() const { return columns_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&columns_));
    return fl.Finalize();
  }

  const ASTDescriptorColumnList* columns_ = nullptr;
};

// A column schema identifies the column type and the column annotations.
// The annotations consist of the column attributes and the column options.
//
// This class is used only in column definitions of CREATE TABLE statements,
// and is unrelated to CREATE SCHEMA despite the usage of the overloaded term
// "schema".
//
// The hierarchy of column schema is similar to the type hierarchy.
// The annotations can be applied on struct fields or array elements, for
// example, as in STRUCT<x INT64 NOT NULL, y STRING OPTIONS(foo="bar")>.
// In this case, some column attributes, such as PRIMARY KEY and HIDDEN, are
// disallowed as field attributes.
class ASTColumnSchema : public ASTNode {
 public:
  explicit ASTColumnSchema(ASTNodeKind kind) : ASTNode(kind) {}

  const ASTTypeParameterList* type_parameters() const { return type_parameters_; }
  const ASTCollate* collate() const { return collate_; }
  const ASTGeneratedColumnInfo* generated_column_info() const { return generated_column_info_; }
  const ASTExpression* default_expression() const { return default_expression_; }
  const ASTColumnAttributeList* attributes() const { return attributes_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  // Helper method that returns true if the attributes()->values() contains an
  // ASTColumnAttribute with the node->kind() equal to 'node_kind'.
  bool ContainsAttribute(ASTNodeKind node_kind) const;

  template <typename T>
  std::vector<const T*> FindAttributes(ASTNodeKind node_kind) const {
    std::vector<const T*> found;
    if (attributes() == nullptr) {
      return found;
    }
    for (const ASTColumnAttribute* attribute : attributes()->values()) {
      if (attribute->node_kind() == node_kind) {
        found.push_back(static_cast<const T*>(attribute));
      }
    }
    return found;
  }

  friend class ParseTreeSerializer;

 protected:
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
  const ASTGeneratedColumnInfo* generated_column_info_ = nullptr;
  const ASTExpression* default_expression_ = nullptr;
  const ASTColumnAttributeList* attributes_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTSimpleColumnSchema final : public ASTColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SIMPLE_COLUMN_SCHEMA;

  ASTSimpleColumnSchema() : ASTColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* type_name() const { return type_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_name_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* type_name_ = nullptr;
};

// Base class for column schemas that are also defined by an element type (eg
// ARRAY and RANGE).
class ASTElementTypeColumnSchema : public ASTColumnSchema {
 public:
  explicit ASTElementTypeColumnSchema(ASTNodeKind kind) : ASTColumnSchema(kind) {}

  const ASTColumnSchema* element_schema() const { return element_schema_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTColumnSchema* element_schema_ = nullptr;
};

class ASTArrayColumnSchema final : public ASTElementTypeColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ARRAY_COLUMN_SCHEMA;

  ASTArrayColumnSchema() : ASTElementTypeColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&element_schema_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }
};

class ASTRangeColumnSchema final : public ASTElementTypeColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RANGE_COLUMN_SCHEMA;

  ASTRangeColumnSchema() : ASTElementTypeColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&element_schema_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }
};

class ASTMapColumnSchema final : public ASTColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MAP_COLUMN_SCHEMA;

  ASTMapColumnSchema() : ASTColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTColumnSchema* key_schema() const { return key_schema_; }
  const ASTColumnSchema* value_schema() const { return value_schema_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&key_schema_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_schema_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTColumnSchema* key_schema_ = nullptr;
  const ASTColumnSchema* value_schema_ = nullptr;
};

class ASTPrimaryKeyElement final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIMARY_KEY_ELEMENT;

  ASTPrimaryKeyElement() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_ordering_spec(ASTOrderingExpression::OrderingSpec ordering_spec) { ordering_spec_ = ordering_spec; }
  ASTOrderingExpression::OrderingSpec ordering_spec() const { return ordering_spec_; }

  const ASTIdentifier* column() const { return column_; }
  const ASTNullOrder* null_order() const { return null_order_; }

  bool descending() const {
    return ordering_spec_ == ASTOrderingExpression::DESC;
  }
  bool ascending() const {
    return ordering_spec_ == ASTOrderingExpression::ASC;
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_));
    fl.AddOptional(&null_order_, AST_NULL_ORDER);
    return fl.Finalize();
  }

  const ASTIdentifier* column_ = nullptr;
  ASTOrderingExpression::OrderingSpec ordering_spec_ = ASTOrderingExpression::UNSPECIFIED;
  const ASTNullOrder* null_order_ = nullptr;
};

class ASTPrimaryKeyElementList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIMARY_KEY_ELEMENT_LIST;

  ASTPrimaryKeyElementList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTPrimaryKeyElement* const>& elements() const {
    return elements_;
  }
  const ASTPrimaryKeyElement* elements(int i) const { return elements_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&elements_);
    return fl.Finalize();
  }

  absl::Span<const ASTPrimaryKeyElement* const> elements_;
};

// Base class for constraints, including primary key, foreign key and check
// constraints.
class ASTTableConstraint : public ASTTableElement {
 public:
  explicit ASTTableConstraint(ASTNodeKind kind) : ASTTableElement(kind) {}

  virtual const ASTIdentifier* constraint_name() const = 0;

  friend class ParseTreeSerializer;
};

class ASTPrimaryKey final : public ASTTableConstraint {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PRIMARY_KEY;

  ASTPrimaryKey() : ASTTableConstraint(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_enforced(bool enforced) { enforced_ = enforced; }
  bool enforced() const { return enforced_; }

  const ASTPrimaryKeyElementList* element_list() const { return element_list_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTIdentifier* constraint_name() const override { return constraint_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&element_list_, AST_PRIMARY_KEY_ELEMENT_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&constraint_name_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTPrimaryKeyElementList* element_list_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTIdentifier* constraint_name_ = nullptr;
  bool enforced_ = true;
};

class ASTForeignKey final : public ASTTableConstraint {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOREIGN_KEY;

  ASTForeignKey() : ASTTableConstraint(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTColumnList* column_list() const { return column_list_; }
  const ASTForeignKeyReference* reference() const { return reference_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTIdentifier* constraint_name() const override { return constraint_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_list_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&reference_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&constraint_name_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTColumnList* column_list_ = nullptr;
  const ASTForeignKeyReference* reference_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTIdentifier* constraint_name_ = nullptr;
};

class ASTCheckConstraint final : public ASTTableConstraint {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CHECK_CONSTRAINT;

  ASTCheckConstraint() : ASTTableConstraint(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_enforced(bool is_enforced) { is_enforced_ = is_enforced; }
  bool is_enforced() const { return is_enforced_; }

  const ASTExpression* expression() const { return expression_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTIdentifier* constraint_name() const override { return constraint_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&constraint_name_, AST_IDENTIFIER);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTIdentifier* constraint_name_ = nullptr;
  bool is_enforced_ = true;
};

class ASTDescriptorColumn final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DESCRIPTOR_COLUMN;

  ASTDescriptorColumn() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field
  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
};

class ASTDescriptorColumnList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DESCRIPTOR_COLUMN_LIST;

  ASTDescriptorColumnList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Guaranteed by the parser to never be empty.
  const absl::Span<const ASTDescriptorColumn* const>& descriptor_column_list() const {
    return descriptor_column_list_;
  }
  const ASTDescriptorColumn* descriptor_column_list(int i) const { return descriptor_column_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&descriptor_column_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTDescriptorColumn* const> descriptor_column_list_;
};

class ASTCreateEntityStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_ENTITY_STATEMENT;

  ASTCreateEntityStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* type() const { return type_; }
  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTJSONLiteral* json_body() const { return json_body_; }
  const ASTStringLiteral* text_body() const { return text_body_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&json_body_, AST_JSON_LITERAL);
    fl.AddOptional(&text_body_, AST_STRING_LITERAL);
    return fl.Finalize();
  }

  const ASTIdentifier* type_ = nullptr;
  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTJSONLiteral* json_body_ = nullptr;
  const ASTStringLiteral* text_body_ = nullptr;
};

class ASTRaiseStatement final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RAISE_STATEMENT;

  ASTRaiseStatement() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* message() const { return message_; }

  // A RAISE statement rethrows an existing exception, as opposed to creating
  // a new exception, when none of the properties are set.  Currently, the only
  // property is the message.  However, for future proofing, as more properties
  // get added to RAISE later, code should call this function to check for a
  // rethrow, rather than checking for the presence of a message, directly.
  bool is_rethrow() const { return message_ == nullptr; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&message_);
    return fl.Finalize();
  }

  const ASTExpression* message_ = nullptr;
};

class ASTExceptionHandler final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXCEPTION_HANDLER;

  ASTExceptionHandler() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field; even an empty block still contains an empty statement list.
  const ASTStatementList* statement_list() const { return statement_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_list_));
    return fl.Finalize();
  }

  const ASTStatementList* statement_list_ = nullptr;
};

// Represents a list of exception handlers in a block.  Currently restricted
// to one element, but may contain multiple elements in the future, once there
// are multiple error codes for a block to catch.
class ASTExceptionHandlerList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXCEPTION_HANDLER_LIST;

  ASTExceptionHandlerList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExceptionHandler* const>& exception_handler_list() const {
    return exception_handler_list_;
  }
  const ASTExceptionHandler* exception_handler_list(int i) const { return exception_handler_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&exception_handler_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTExceptionHandler* const> exception_handler_list_;
};

class ASTBeginEndBlock final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BEGIN_END_BLOCK;

  ASTBeginEndBlock() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTLabel* label() const { return label_; }
  const ASTStatementList* statement_list_node() const { return statement_list_node_; }

  // Optional; nullptr indicates a BEGIN block without an EXCEPTION clause.
  const ASTExceptionHandlerList* handler_list() const { return handler_list_; }

  absl::Span<const ASTStatement* const> statement_list() const {
    return statement_list_node_->statement_list();
  }

  bool has_exception_handler() const {
    return handler_list_ != nullptr &&
           !handler_list_->exception_handler_list().empty();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&statement_list_node_));
    fl.AddOptional(&handler_list_, AST_EXCEPTION_HANDLER_LIST);
    return fl.Finalize();
  }

  const ASTLabel* label_ = nullptr;
  const ASTStatementList* statement_list_node_ = nullptr;
  const ASTExceptionHandlerList* handler_list_ = nullptr;
};

class ASTIdentifierList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTIFIER_LIST;

  ASTIdentifierList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Guaranteed by the parser to never be empty.
  const absl::Span<const ASTIdentifier* const>& identifier_list() const {
    return identifier_list_;
  }
  const ASTIdentifier* identifier_list(int i) const { return identifier_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&identifier_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTIdentifier* const> identifier_list_;
};

class ASTVariableDeclaration final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_VARIABLE_DECLARATION;

  ASTVariableDeclaration() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required fields
  const ASTIdentifierList* variable_list() const { return variable_list_; }

  // Optional fields; at least one of <type> and <default_value> must be
  // present.
  const ASTType* type() const { return type_; }

  const ASTExpression* default_value() const { return default_value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variable_list_));
    fl.AddOptionalType(&type_);
    fl.AddOptionalExpression(&default_value_);
    return fl.Finalize();
  }

  const ASTIdentifierList* variable_list_ = nullptr;
  const ASTType* type_ = nullptr;
  const ASTExpression* default_value_ = nullptr;
};

// Represents UNTIL in a REPEAT statement.
class ASTUntilClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNTIL_CLAUSE;

  ASTUntilClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field
  const ASTExpression* condition() const { return condition_; }

  // Returns the ASTRepeatStatement that this ASTUntilClause belongs to.
  const ASTRepeatStatement* repeat_stmt() const {
    return parent()->GetAsOrDie<ASTRepeatStatement>();
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
};

// Base class shared by break and continue statements.
class ASTBreakContinueStatement : public ASTScriptStatement {
 public:
  explicit ASTBreakContinueStatement(ASTNodeKind kind) : ASTScriptStatement(kind) {}

  // This enum is equivalent to ASTBreakContinueStatementEnums::BreakContinueKeyword in ast_enums.proto
  enum BreakContinueKeyword {
    BREAK = ASTBreakContinueStatementEnums::BREAK,
    LEAVE = ASTBreakContinueStatementEnums::LEAVE,
    CONTINUE = ASTBreakContinueStatementEnums::CONTINUE,
    ITERATE = ASTBreakContinueStatementEnums::ITERATE
  };

  const ASTLabel* label() const { return label_; }

  virtual void set_keyword(BreakContinueKeyword keyword) = 0;
  virtual BreakContinueKeyword keyword() const = 0;

  // Returns text representing the keyword used for this BREAK/CONINUE
  // statement.  All letters are in uppercase.
  absl::string_view GetKeywordText() const {
    switch (keyword()) {
      case BREAK:
        return "BREAK";
      case LEAVE:
        return "LEAVE";
      case CONTINUE:
        return "CONTINUE";
      case ITERATE:
        return "ITERATE";
    }
  }

  friend class ParseTreeSerializer;

 protected:
  const ASTLabel* label_ = nullptr;
};

class ASTBreakStatement final : public ASTBreakContinueStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_BREAK_STATEMENT;

  ASTBreakStatement() : ASTBreakContinueStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_keyword(ASTBreakContinueStatement::BreakContinueKeyword keyword) { keyword_ = keyword; }
  ASTBreakContinueStatement::BreakContinueKeyword keyword() const { return keyword_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    return fl.Finalize();
  }

  ASTBreakContinueStatement::BreakContinueKeyword keyword_ = ASTBreakContinueStatement::BREAK;
};

class ASTContinueStatement final : public ASTBreakContinueStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CONTINUE_STATEMENT;

  ASTContinueStatement() : ASTBreakContinueStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_keyword(ASTBreakContinueStatement::BreakContinueKeyword keyword) { keyword_ = keyword; }
  ASTBreakContinueStatement::BreakContinueKeyword keyword() const { return keyword_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    return fl.Finalize();
  }

  ASTBreakContinueStatement::BreakContinueKeyword keyword_ = ASTBreakContinueStatement::CONTINUE;
};

class ASTDropPrivilegeRestrictionStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_PRIVILEGE_RESTRICTION_STATEMENT;

  ASTDropPrivilegeRestrictionStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPrivileges* privileges() const { return privileges_; }
  const ASTIdentifier* object_type() const { return object_type_; }
  const ASTPathExpression* name_path() const { return name_path_; }

const ASTPathExpression*
          GetDdlTarget() const override { return name_path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privileges_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&object_type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_path_));
    return fl.Finalize();
  }

  bool is_if_exists_ = false;
  const ASTPrivileges* privileges_ = nullptr;
  const ASTIdentifier* object_type_ = nullptr;
  const ASTPathExpression* name_path_ = nullptr;
};

// Represents a DROP ROW ACCESS POLICY statement.
class ASTDropRowAccessPolicyStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_ROW_ACCESS_POLICY_STATEMENT;

  ASTDropRowAccessPolicyStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* table_name() const { return table_name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  const ASTIdentifier* name() const {
    ABSL_DCHECK(name_ == nullptr || name_->num_names() == 1);
    return name_ == nullptr ? nullptr : name_->name(0);
  }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&table_name_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTPathExpression* table_name_ = nullptr;
  bool is_if_exists_ = false;
};

class ASTCreatePrivilegeRestrictionStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_PRIVILEGE_RESTRICTION_STATEMENT;

  ASTCreatePrivilegeRestrictionStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPrivileges* privileges() const { return privileges_; }
  const ASTIdentifier* object_type() const { return object_type_; }
  const ASTPathExpression* name_path() const { return name_path_; }
  const ASTRestrictToClause* restrict_to() const { return restrict_to_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_path_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privileges_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&object_type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_path_));
    fl.AddOptional(&restrict_to_, AST_RESTRICT_TO_CLAUSE);
    return fl.Finalize();
  }

  const ASTPrivileges* privileges_ = nullptr;
  const ASTIdentifier* object_type_ = nullptr;
  const ASTPathExpression* name_path_ = nullptr;
  const ASTRestrictToClause* restrict_to_ = nullptr;
};

class ASTCreateRowAccessPolicyStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_ROW_ACCESS_POLICY_STATEMENT;

  ASTCreateRowAccessPolicyStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_has_access_keyword(bool has_access_keyword) { has_access_keyword_ = has_access_keyword; }
  bool has_access_keyword() const { return has_access_keyword_; }

  const ASTPathExpression* target_path() const { return target_path_; }
  const ASTGrantToClause* grant_to() const { return grant_to_; }
  const ASTFilterUsingClause* filter_using() const { return filter_using_; }

  const ASTIdentifier* name() const {
    ABSL_DCHECK(name_ == nullptr || name_->num_names() == 1);
    return name_ == nullptr ? nullptr : name_->name(0);
  }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&target_path_));
    fl.AddOptional(&grant_to_, AST_GRANT_TO_CLAUSE);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&filter_using_));
    fl.AddOptional(&name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTPathExpression* target_path_ = nullptr;
  const ASTGrantToClause* grant_to_ = nullptr;
  const ASTFilterUsingClause* filter_using_ = nullptr;
  const ASTPathExpression* name_ = nullptr;
  bool has_access_keyword_ = false;
};

// Represents a DROP statement.
class ASTDropStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DROP_STATEMENT;

  ASTDropStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTDropStatementEnums::DropMode in ast_enums.proto
  enum DropMode {
    DROP_MODE_UNSPECIFIED = ASTDropStatementEnums::DROP_MODE_UNSPECIFIED,
    RESTRICT = ASTDropStatementEnums::RESTRICT,
    CASCADE = ASTDropStatementEnums::CASCADE
  };

  void set_drop_mode(ASTDropStatement::DropMode drop_mode) { drop_mode_ = drop_mode; }
  ASTDropStatement::DropMode drop_mode() const { return drop_mode_; }
  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }
  void set_schema_object_kind(SchemaObjectKind schema_object_kind) { schema_object_kind_ = schema_object_kind; }
  SchemaObjectKind schema_object_kind() const { return schema_object_kind_; }

  const ASTPathExpression* name() const { return name_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  static std::string GetSQLForDropMode(DropMode drop_mode);

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  ASTDropStatement::DropMode drop_mode_ = ASTDropStatement::DROP_MODE_UNSPECIFIED;
  bool is_if_exists_ = false;
  SchemaObjectKind schema_object_kind_ = kInvalidSchemaObjectKind;
};

class ASTReturnStatement final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RETURN_STATEMENT;

  ASTReturnStatement() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// A statement which assigns to a single variable from an expression.
// Example:
//   SET x = 3;
class ASTSingleAssignment final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SINGLE_ASSIGNMENT;

  ASTSingleAssignment() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* variable() const { return variable_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variable_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTIdentifier* variable_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

// A statement which assigns to a query parameter from an expression.
// Example:
//   SET @x = 3;
class ASTParameterAssignment final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PARAMETER_ASSIGNMENT;

  ASTParameterAssignment() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTParameterExpr* parameter() const { return parameter_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&parameter_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTParameterExpr* parameter_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

// A statement which assigns to a system variable from an expression.
// Example:
//   SET @@x = 3;
class ASTSystemVariableAssignment final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SYSTEM_VARIABLE_ASSIGNMENT;

  ASTSystemVariableAssignment() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSystemVariableExpr* system_variable() const { return system_variable_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&system_variable_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTSystemVariableExpr* system_variable_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

// A statement which assigns multiple variables to fields in a struct,
// which each variable assigned to one field.
// Example:
//   SET (x, y) = (5, 10);
class ASTAssignmentFromStruct final : public ASTScriptStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ASSIGNMENT_FROM_STRUCT;

  ASTAssignmentFromStruct() : ASTScriptStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifierList* variables() const { return variables_; }
  const ASTExpression* struct_expression() const { return struct_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variables_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&struct_expression_));
    return fl.Finalize();
  }

  const ASTIdentifierList* variables_ = nullptr;
  const ASTExpression* struct_expression_ = nullptr;
};

class ASTCreateTableStmtBase : public ASTCreateStatement {
 public:
  explicit ASTCreateTableStmtBase(ASTNodeKind kind) : ASTCreateStatement(kind) {}

  const ASTPathExpression* name() const { return name_; }
  const ASTTableElementList* table_element_list() const { return table_element_list_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTPathExpression* like_table_name() const { return like_table_name_; }
  const ASTCollate* collate() const { return collate_; }
  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* name_ = nullptr;
  const ASTTableElementList* table_element_list_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTPathExpression* like_table_name_ = nullptr;
  const ASTCollate* collate_ = nullptr;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
};

class ASTCreateTableStatement final : public ASTCreateTableStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_TABLE_STATEMENT;

  ASTCreateTableStatement() : ASTCreateTableStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTCloneDataSource* clone_data_source() const { return clone_data_source_; }
  const ASTCopyDataSource* copy_data_source() const { return copy_data_source_; }
  const ASTPartitionBy* partition_by() const { return partition_by_; }
  const ASTClusterBy* cluster_by() const { return cluster_by_; }
  const ASTQuery* query() const { return query_; }
  const ASTSpannerTableOptions* spanner_options() const { return spanner_options_; }
  const ASTTtlClause* ttl() const { return ttl_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&table_element_list_, AST_TABLE_ELEMENT_LIST);
    fl.AddOptional(&spanner_options_, AST_SPANNER_TABLE_OPTIONS);
    fl.AddOptional(&like_table_name_, AST_PATH_EXPRESSION);
    fl.AddOptional(&clone_data_source_, AST_CLONE_DATA_SOURCE);
    fl.AddOptional(&copy_data_source_, AST_COPY_DATA_SOURCE);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&cluster_by_, AST_CLUSTER_BY);
    fl.AddOptional(&ttl_, AST_TTL_CLAUSE);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    return fl.Finalize();
  }

  const ASTCloneDataSource* clone_data_source_ = nullptr;
  const ASTCopyDataSource* copy_data_source_ = nullptr;
  const ASTPartitionBy* partition_by_ = nullptr;
  const ASTClusterBy* cluster_by_ = nullptr;
  const ASTQuery* query_ = nullptr;
  const ASTSpannerTableOptions* spanner_options_ = nullptr;
  const ASTTtlClause* ttl_ = nullptr;
};

class ASTCreateExternalTableStatement final : public ASTCreateTableStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_EXTERNAL_TABLE_STATEMENT;

  ASTCreateExternalTableStatement() : ASTCreateTableStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWithPartitionColumnsClause* with_partition_columns_clause() const { return with_partition_columns_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&table_element_list_, AST_TABLE_ELEMENT_LIST);
    fl.AddOptional(&like_table_name_, AST_PATH_EXPRESSION);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&with_partition_columns_clause_, AST_WITH_PARTITION_COLUMNS_CLAUSE);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTWithPartitionColumnsClause* with_partition_columns_clause_ = nullptr;
};

class ASTCreateViewStatementBase : public ASTCreateStatement {
 public:
  explicit ASTCreateViewStatementBase(ASTNodeKind kind) : ASTCreateStatement(kind) {}

  void set_sql_security(ASTCreateStatement::SqlSecurity sql_security) { sql_security_ = sql_security; }
  ASTCreateStatement::SqlSecurity sql_security() const { return sql_security_; }
  void set_recursive(bool recursive) { recursive_ = recursive; }
  bool recursive() const { return recursive_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTColumnWithOptionsList* column_with_options_list() const { return column_with_options_list_; }
  const ASTOptionsList* options_list() const { return options_list_; }
  const ASTQuery* query() const { return query_; }

  std::string GetSqlForSqlSecurity() const;

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* name_ = nullptr;
  const ASTColumnWithOptionsList* column_with_options_list_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
  const ASTQuery* query_ = nullptr;
  ASTCreateStatement::SqlSecurity sql_security_ = ASTCreateStatement::SQL_SECURITY_UNSPECIFIED;
  bool recursive_ = false;

  void CollectModifiers(std::vector<std::string>* modifiers) const override;
};

class ASTCreateViewStatement final : public ASTCreateViewStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_VIEW_STATEMENT;

  ASTCreateViewStatement() : ASTCreateViewStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&column_with_options_list_, AST_COLUMN_WITH_OPTIONS_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    return fl.Finalize();
  }
};

class ASTCreateMaterializedViewStatement final : public ASTCreateViewStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_MATERIALIZED_VIEW_STATEMENT;

  ASTCreateMaterializedViewStatement() : ASTCreateViewStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPartitionBy* partition_by() const { return partition_by_; }
  const ASTClusterBy* cluster_by() const { return cluster_by_; }
  const ASTPathExpression* replica_source() const { return replica_source_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&column_with_options_list_, AST_COLUMN_WITH_OPTIONS_LIST);
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&cluster_by_, AST_CLUSTER_BY);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    fl.AddOptional(&replica_source_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTPartitionBy* partition_by_ = nullptr;
  const ASTClusterBy* cluster_by_ = nullptr;
  const ASTPathExpression* replica_source_ = nullptr;
};

class ASTCreateApproxViewStatement final : public ASTCreateViewStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_APPROX_VIEW_STATEMENT;

  ASTCreateApproxViewStatement() : ASTCreateViewStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&column_with_options_list_, AST_COLUMN_WITH_OPTIONS_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&query_, AST_QUERY);
    return fl.Finalize();
  }
};

// Base class for all loop statements (loop/end loop, while, foreach, etc.).
// Every loop has a body.
class ASTLoopStatement : public ASTScriptStatement {
 public:
  explicit ASTLoopStatement(ASTNodeKind kind) : ASTScriptStatement(kind) {}

  // Optional field
  const ASTLabel* label() const { return label_; }

  // Required field
  const ASTStatementList* body() const { return body_; }

  bool IsLoopStatement() const override { return true; }

  friend class ParseTreeSerializer;

 protected:
  const ASTLabel* label_ = nullptr;
  const ASTStatementList* body_ = nullptr;
};

// Represents either:
// - LOOP...END LOOP (if condition is nullptr).  This is semantically
//                  equivalent to WHILE(true)...END WHILE.
// - WHILE...END WHILE (if condition is not nullptr)
class ASTWhileStatement final : public ASTLoopStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WHILE_STATEMENT;

  ASTWhileStatement() : ASTLoopStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The <condition> is optional.  A null <condition> indicates a
  // LOOP...END LOOP construct.
  const ASTExpression* condition() const { return condition_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    fl.AddOptionalExpression(&condition_);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  const ASTExpression* condition_ = nullptr;
};

// Represents the statement REPEAT...UNTIL...END REPEAT.
// This is conceptually also called do-while.
class ASTRepeatStatement final : public ASTLoopStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REPEAT_STATEMENT;

  ASTRepeatStatement() : ASTLoopStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field.
  const ASTUntilClause* until_clause() const { return until_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&until_clause_));
    return fl.Finalize();
  }

  const ASTUntilClause* until_clause_ = nullptr;
};

// Represents the statement FOR...IN...DO...END FOR.
// This is conceptually also called for-each.
class ASTForInStatement final : public ASTLoopStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_FOR_IN_STATEMENT;

  ASTForInStatement() : ASTLoopStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* variable() const { return variable_; }
  const ASTQuery* query() const { return query_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_, AST_LABEL);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variable_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&query_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  const ASTIdentifier* variable_ = nullptr;
  const ASTQuery* query_ = nullptr;
};

// Common parent class for ALTER statement, e.g., ALTER TABLE/ALTER VIEW
class ASTAlterStatementBase : public ASTDdlStatement {
 public:
  explicit ASTAlterStatementBase(ASTNodeKind kind) : ASTDdlStatement(kind) {}

  // This adds the "if exists" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_is_if_exists(bool is_if_exists) { is_if_exists_ = is_if_exists; }
  bool is_if_exists() const { return is_if_exists_; }

  const ASTPathExpression* path() const { return path_; }
  const ASTAlterActionList* action_list() const { return action_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return path_; }
  bool IsAlterStatement() const override { return true; }

  friend class ParseTreeSerializer;

 protected:
  const ASTPathExpression* path_ = nullptr;
  const ASTAlterActionList* action_list_ = nullptr;

 private:
  bool is_if_exists_ = false;
};

// Represents the statement ALTER CONNECTION <name_path> SET OPTIONS
// <options_list>
class ASTAlterConnectionStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_CONNECTION_STATEMENT;

  ASTAlterConnectionStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterDatabaseStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_DATABASE_STATEMENT;

  ASTAlterDatabaseStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterSchemaStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_SCHEMA_STATEMENT;

  ASTAlterSchemaStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterExternalSchemaStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_EXTERNAL_SCHEMA_STATEMENT;

  ASTAlterExternalSchemaStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterTableStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_TABLE_STATEMENT;

  ASTAlterTableStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterViewStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_VIEW_STATEMENT;

  ASTAlterViewStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterMaterializedViewStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_MATERIALIZED_VIEW_STATEMENT;

  ASTAlterMaterializedViewStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterApproxViewStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_APPROX_VIEW_STATEMENT;

  ASTAlterApproxViewStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterModelStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_MODEL_STATEMENT;

  ASTAlterModelStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

class ASTAlterPrivilegeRestrictionStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_PRIVILEGE_RESTRICTION_STATEMENT;

  ASTAlterPrivilegeRestrictionStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field.
  const ASTPrivileges* privileges() const { return privileges_; }

  // Required field.
  const ASTIdentifier* object_type() const { return object_type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&privileges_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&object_type_));
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }

  const ASTPrivileges* privileges_ = nullptr;
  const ASTIdentifier* object_type_ = nullptr;
};

class ASTAlterRowAccessPolicyStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_ROW_ACCESS_POLICY_STATEMENT;

  ASTAlterRowAccessPolicyStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Required field.
  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
};

class ASTAlterEntityStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_ENTITY_STATEMENT;

  ASTAlterEntityStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* type() const { return type_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }

  const ASTIdentifier* type_ = nullptr;
};

// ALTER SEARCH|VECTOR INDEX action for "REBUILD" clause.
class ASTRebuildAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_REBUILD_ACTION;

  ASTRebuildAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Represents a ALTER SEARCH|VECTOR INDEX statement.
// Note: ALTER INDEX without SEARCH or VECTOR is currently resolved to
// schema_object_kind, and throws not supported error.
class ASTAlterIndexStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_INDEX_STATEMENT;

  ASTAlterIndexStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTAlterIndexStatementEnums::IndexType in ast_enums.proto
  enum IndexType {
    INDEX_DEFAULT = ASTAlterIndexStatementEnums::INDEX_DEFAULT,
    INDEX_SEARCH = ASTAlterIndexStatementEnums::INDEX_SEARCH,
    INDEX_VECTOR = ASTAlterIndexStatementEnums::INDEX_VECTOR
  };

  void set_index_type(ASTAlterIndexStatement::IndexType index_type) { index_type_ = index_type; }
  ASTAlterIndexStatement::IndexType index_type() const { return index_type_; }

  const ASTPathExpression* table_name() const { return table_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    fl.AddOptional(&table_name_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_ = nullptr;
  ASTAlterIndexStatement::IndexType index_type_ = ASTAlterIndexStatement::INDEX_DEFAULT;
};

// This is the common superclass of CREATE FUNCTION and CREATE TABLE FUNCTION
// statements. It contains all fields shared between the two types of
// statements, including the function declaration, return type, OPTIONS list,
// and string body (if present).
class ASTCreateFunctionStmtBase : public ASTCreateStatement {
 public:
  explicit ASTCreateFunctionStmtBase(ASTNodeKind kind) : ASTCreateStatement(kind) {}

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTCreateFunctionStmtBaseEnums::DeterminismLevel in ast_enums.proto
  enum DeterminismLevel {
    DETERMINISM_UNSPECIFIED = ASTCreateFunctionStmtBaseEnums::DETERMINISM_UNSPECIFIED,
    DETERMINISTIC = ASTCreateFunctionStmtBaseEnums::DETERMINISTIC,
    NOT_DETERMINISTIC = ASTCreateFunctionStmtBaseEnums::NOT_DETERMINISTIC,
    IMMUTABLE = ASTCreateFunctionStmtBaseEnums::IMMUTABLE,
    STABLE = ASTCreateFunctionStmtBaseEnums::STABLE,
    VOLATILE = ASTCreateFunctionStmtBaseEnums::VOLATILE
  };

  void set_determinism_level(ASTCreateFunctionStmtBase::DeterminismLevel determinism_level) { determinism_level_ = determinism_level; }
  ASTCreateFunctionStmtBase::DeterminismLevel determinism_level() const { return determinism_level_; }
  void set_sql_security(ASTCreateStatement::SqlSecurity sql_security) { sql_security_ = sql_security; }
  ASTCreateStatement::SqlSecurity sql_security() const { return sql_security_; }

  const ASTFunctionDeclaration* function_declaration() const { return function_declaration_; }
  const ASTIdentifier* language() const { return language_; }
  const ASTStringLiteral* code() const { return code_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  std::string GetSqlForSqlSecurity() const;
  std::string GetSqlForDeterminismLevel() const;

  const ASTPathExpression* GetDdlTarget() const override {
    return function_declaration()->name();
  }

  friend class ParseTreeSerializer;

 protected:
  const ASTFunctionDeclaration* function_declaration_ = nullptr;
  const ASTIdentifier* language_ = nullptr;
  const ASTStringLiteral* code_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;

 private:
  ASTCreateFunctionStmtBase::DeterminismLevel determinism_level_ = ASTCreateFunctionStmtBase::DETERMINISM_UNSPECIFIED;
  ASTCreateStatement::SqlSecurity sql_security_ = ASTCreateStatement::SQL_SECURITY_UNSPECIFIED;
};

// This may represent an "external language" function (e.g., implemented in a
// non-SQL programming language such as JavaScript), a "sql" function, or a
// "remote" function (e.g., implemented in a remote service and with an agnostic
// programming language).
// Note that some combinations of field setting can represent functions that are
// not actually valid due to optional members that would be inappropriate for
// one type of function or another; validity of the parsed function must be
// checked by the analyzer.
class ASTCreateFunctionStatement final : public ASTCreateFunctionStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_FUNCTION_STATEMENT;

  ASTCreateFunctionStatement() : ASTCreateFunctionStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_aggregate(bool is_aggregate) { is_aggregate_ = is_aggregate; }
  bool is_aggregate() const { return is_aggregate_; }
  void set_is_remote(bool is_remote) { is_remote_ = is_remote; }
  bool is_remote() const { return is_remote_; }

  const ASTType* return_type() const { return return_type_; }
  const ASTSqlFunctionBody* sql_function_body() const { return sql_function_body_; }
  const ASTWithConnectionClause* with_connection_clause() const { return with_connection_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&function_declaration_));
    fl.AddOptionalType(&return_type_);
    fl.AddOptional(&language_, AST_IDENTIFIER);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    fl.AddOptional(&code_, AST_STRING_LITERAL);
    fl.AddOptional(&sql_function_body_, AST_SQL_FUNCTION_BODY);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTType* return_type_ = nullptr;

  // For SQL functions.
  const ASTSqlFunctionBody* sql_function_body_ = nullptr;

  bool is_aggregate_ = false;
  bool is_remote_ = false;
  const ASTWithConnectionClause* with_connection_clause_ = nullptr;
};

// This represents a table-valued function declaration statement in GoogleSQL,
// using the CREATE TABLE FUNCTION syntax. Note that some combinations of field
// settings can represent functions that are not actually valid, since optional
// members may be inappropriate for one type of function or another; validity of
// the parsed function must be checked by the analyzer.
class ASTCreateTableFunctionStatement final : public ASTCreateFunctionStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_TABLE_FUNCTION_STATEMENT;

  ASTCreateTableFunctionStatement() : ASTCreateFunctionStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  const ASTTVFSchema* return_tvf_schema() const { return return_tvf_schema_; }
  const ASTQuery* query() const { return query_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&function_declaration_));
    fl.AddOptional(&return_tvf_schema_, AST_TVF_SCHEMA);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    fl.AddOptional(&language_, AST_IDENTIFIER);
    fl.AddOptional(&code_, AST_STRING_LITERAL);
    fl.AddOptional(&query_, AST_QUERY);
    return fl.Finalize();
  }

  const ASTTVFSchema* return_tvf_schema_ = nullptr;
  const ASTQuery* query_ = nullptr;
};

class ASTStructColumnSchema final : public ASTColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_STRUCT_COLUMN_SCHEMA;

  ASTStructColumnSchema() : ASTColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTStructColumnField* const>& struct_fields() const {
    return struct_fields_;
  }
  const ASTStructColumnField* struct_fields(int i) const { return struct_fields_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsNodeKind(&struct_fields_, AST_STRUCT_COLUMN_FIELD);
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  absl::Span<const ASTStructColumnField* const> struct_fields_;
};

class ASTInferredTypeColumnSchema final : public ASTColumnSchema {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INFERRED_TYPE_COLUMN_SCHEMA;

  ASTInferredTypeColumnSchema() : ASTColumnSchema(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&generated_column_info_, AST_GENERATED_COLUMN_INFO);
    fl.AddOptionalExpression(&default_expression_);
    fl.AddOptional(&attributes_, AST_COLUMN_ATTRIBUTE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }
};

class ASTExecuteIntoClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXECUTE_INTO_CLAUSE;

  ASTExecuteIntoClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifierList* identifiers() const { return identifiers_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifiers_));
    return fl.Finalize();
  }

  const ASTIdentifierList* identifiers_ = nullptr;
};

class ASTExecuteUsingArgument final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXECUTE_USING_ARGUMENT;

  ASTExecuteUsingArgument() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  // Optional. Absent if this argument is positional. Present if it is named.
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

class ASTExecuteUsingClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXECUTE_USING_CLAUSE;

  ASTExecuteUsingClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTExecuteUsingArgument* const>& arguments() const {
    return arguments_;
  }
  const ASTExecuteUsingArgument* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  absl::Span<const ASTExecuteUsingArgument* const> arguments_;
};

class ASTExecuteImmediateStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_EXECUTE_IMMEDIATE_STATEMENT;

  ASTExecuteImmediateStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* sql() const { return sql_; }
  const ASTExecuteIntoClause* into_clause() const { return into_clause_; }
  const ASTExecuteUsingClause* using_clause() const { return using_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sql_));
    fl.AddOptional(&into_clause_, AST_EXECUTE_INTO_CLAUSE);
    fl.AddOptional(&using_clause_, AST_EXECUTE_USING_CLAUSE);
    return fl.Finalize();
  }

  const ASTExpression* sql_ = nullptr;
  const ASTExecuteIntoClause* into_clause_ = nullptr;
  const ASTExecuteUsingClause* using_clause_ = nullptr;
};

class ASTAuxLoadDataFromFilesOptionsList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_AUX_LOAD_DATA_FROM_FILES_OPTIONS_LIST;

  ASTAuxLoadDataFromFilesOptionsList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTOptionsList* options_list_ = nullptr;
};

class ASTAuxLoadDataPartitionsClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_AUX_LOAD_DATA_PARTITIONS_CLAUSE;

  ASTAuxLoadDataPartitionsClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_is_overwrite(bool is_overwrite) { is_overwrite_ = is_overwrite; }
  bool is_overwrite() const { return is_overwrite_; }

  const ASTExpression* partition_filter() const { return partition_filter_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&partition_filter_);
    return fl.Finalize();
  }

  const ASTExpression* partition_filter_ = nullptr;
  bool is_overwrite_ = false;
};

// Auxiliary statement used by some engines but not formally part of the
// GoogleSQL language.
class ASTAuxLoadDataStatement final : public ASTCreateTableStmtBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_AUX_LOAD_DATA_STATEMENT;

  ASTAuxLoadDataStatement() : ASTCreateTableStmtBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTAuxLoadDataStatementEnums::InsertionMode in ast_enums.proto
  enum InsertionMode {
    NOT_SET = ASTAuxLoadDataStatementEnums::NOT_SET,
    APPEND = ASTAuxLoadDataStatementEnums::APPEND,
    OVERWRITE = ASTAuxLoadDataStatementEnums::OVERWRITE
  };

  void set_insertion_mode(ASTAuxLoadDataStatement::InsertionMode insertion_mode) { insertion_mode_ = insertion_mode; }
  ASTAuxLoadDataStatement::InsertionMode insertion_mode() const { return insertion_mode_; }
  void set_is_temp_table(bool is_temp_table) { is_temp_table_ = is_temp_table; }
  bool is_temp_table() const { return is_temp_table_; }

  const ASTAuxLoadDataPartitionsClause* load_data_partitions_clause() const { return load_data_partitions_clause_; }
  const ASTPartitionBy* partition_by() const { return partition_by_; }
  const ASTClusterBy* cluster_by() const { return cluster_by_; }
  const ASTAuxLoadDataFromFilesOptionsList* from_files() const { return from_files_; }
  const ASTWithPartitionColumnsClause* with_partition_columns_clause() const { return with_partition_columns_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&table_element_list_, AST_TABLE_ELEMENT_LIST);
    fl.AddOptional(&load_data_partitions_clause_, AST_AUX_LOAD_DATA_PARTITIONS_CLAUSE);
    fl.AddOptional(&collate_, AST_COLLATE);
    fl.AddOptional(&partition_by_, AST_PARTITION_BY);
    fl.AddOptional(&cluster_by_, AST_CLUSTER_BY);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&from_files_));
    fl.AddOptional(&with_partition_columns_clause_, AST_WITH_PARTITION_COLUMNS_CLAUSE);
    fl.AddOptional(&with_connection_clause_, AST_WITH_CONNECTION_CLAUSE);
    return fl.Finalize();
  }

  ASTAuxLoadDataStatement::InsertionMode insertion_mode_ = ASTAuxLoadDataStatement::NOT_SET;
  bool is_temp_table_ = false;
  const ASTAuxLoadDataPartitionsClause* load_data_partitions_clause_ = nullptr;
  const ASTPartitionBy* partition_by_ = nullptr;
  const ASTClusterBy* cluster_by_ = nullptr;
  const ASTAuxLoadDataFromFilesOptionsList* from_files_ = nullptr;
  const ASTWithPartitionColumnsClause* with_partition_columns_clause_ = nullptr;
};

class ASTLabel final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LABEL;

  ASTLabel() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
};

class ASTWithExpression final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_EXPRESSION;

  ASTWithExpression() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelectList* variables() const { return variables_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variables_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTSelectList* variables_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

class ASTTtlClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_TTL_CLAUSE;

  ASTTtlClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
};

// A non-functional node used only to carry a location for better error
// messages.
class ASTLocation final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LOCATION;

  ASTLocation() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTInputOutputClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INPUT_OUTPUT_CLAUSE;

  ASTInputOutputClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTableElementList* input() const { return input_; }
  const ASTTableElementList* output() const { return output_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&input_, AST_TABLE_ELEMENT_LIST);
    fl.AddOptional(&output_, AST_TABLE_ELEMENT_LIST);
    return fl.Finalize();
  }

  const ASTTableElementList* input_ = nullptr;
  const ASTTableElementList* output_ = nullptr;
};

// Represents Spanner-specific extensions for CREATE TABLE statement.
class ASTSpannerTableOptions final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SPANNER_TABLE_OPTIONS;

  ASTSpannerTableOptions() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPrimaryKey* primary_key() const { return primary_key_; }
  const ASTSpannerInterleaveClause* interleave_clause() const { return interleave_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&primary_key_, AST_PRIMARY_KEY);
    fl.AddOptional(&interleave_clause_, AST_SPANNER_INTERLEAVE_CLAUSE);
    return fl.Finalize();
  }

  const ASTPrimaryKey* primary_key_ = nullptr;
  const ASTSpannerInterleaveClause* interleave_clause_ = nullptr;
};

// Represents an INTERLEAVE clause used in Spanner-specific DDL statements.
class ASTSpannerInterleaveClause final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SPANNER_INTERLEAVE_CLAUSE;

  ASTSpannerInterleaveClause() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTSpannerInterleaveClauseEnums::Type in ast_enums.proto
  enum Type {
    NOT_SET = ASTSpannerInterleaveClauseEnums::NOT_SET,
    IN = ASTSpannerInterleaveClauseEnums::IN,
    IN_PARENT = ASTSpannerInterleaveClauseEnums::IN_PARENT
  };

  void set_type(ASTSpannerInterleaveClause::Type type) { type_ = type; }
  ASTSpannerInterleaveClause::Type type() const { return type_; }
  void set_action(ASTForeignKeyActions::Action action) { action_ = action; }
  ASTForeignKeyActions::Action action() const { return action_; }

  const ASTPathExpression* table_name() const { return table_name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&table_name_, AST_PATH_EXPRESSION);
    return fl.Finalize();
  }

  const ASTPathExpression* table_name_ = nullptr;
  ASTSpannerInterleaveClause::Type type_ = ASTSpannerInterleaveClause::NOT_SET;
  ASTForeignKeyActions::Action action_ = ASTForeignKeyActions::NO_ACTION;
};

// ALTER TABLE action for Spanner-specific "ALTER COLUMN" clause
class ASTSpannerAlterColumnAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SPANNER_ALTER_COLUMN_ACTION;

  ASTSpannerAlterColumnAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTColumnDefinition* column_definition() const { return column_definition_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&column_definition_));
    return fl.Finalize();
  }

  const ASTColumnDefinition* column_definition_ = nullptr;
};

// ALTER TABLE action for Spanner-specific "SET ON DELETE" clause
class ASTSpannerSetOnDeleteAction final : public ASTAlterAction {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_SPANNER_SET_ON_DELETE_ACTION;

  ASTSpannerSetOnDeleteAction() : ASTAlterAction(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_action(ASTForeignKeyActions::Action action) { action_ = action; }
  ASTForeignKeyActions::Action action() const { return action_; }

  std::string GetSQLForAlterAction() const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTForeignKeyActions::Action action_ = ASTForeignKeyActions::NO_ACTION;
};

// This node results from ranges constructed with the RANGE keyword followed
// by a literal. Example:
//   RANGE<DATE> '[2022-08-01, 2022-08-02)'
//   RANGE<TIMESTAMP> '[2020-10-01 12:00:00+08, 2020-12-31 12:00:00+08)';
class ASTRangeLiteral final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RANGE_LITERAL;

  ASTRangeLiteral() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTRangeType* type() const { return type_; }

  // String literal representing the range, must have format
  // "[range start, range end)" where "range start" and "range end"
  // are literals of the type specified RANGE<type>
  const ASTStringLiteral* range_value() const { return range_value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&range_value_));
    return fl.Finalize();
  }

  const ASTRangeType* type_ = nullptr;
  const ASTStringLiteral* range_value_ = nullptr;
};

class ASTRangeType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RANGE_TYPE;

  ASTRangeType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTType* element_type() const { return element_type_; }
  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const override { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&element_type_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTType* element_type_ = nullptr;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTCreatePropertyGraphStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_PROPERTY_GRAPH_STATEMENT;

  ASTCreatePropertyGraphStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Path expression for the target property graph.
  const ASTPathExpression* name() const { return name_; }

  // GraphNodeTable definitions.
  const ASTGraphElementTableList* node_table_list() const { return node_table_list_; }

  // GraphEdgeTable definitions.
  const ASTGraphElementTableList* edge_table_list() const { return edge_table_list_; }

  // Placeholder for now. Schema options support is out of scope of MVP.
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&node_table_list_));
    fl.AddOptional(&edge_table_list_, AST_GRAPH_ELEMENT_TABLE_LIST);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTGraphElementTableList* node_table_list_ = nullptr;
  const ASTGraphElementTableList* edge_table_list_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTGraphElementTableList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_TABLE_LIST;

  ASTGraphElementTableList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // GraphElementTable definitions.
  const absl::Span<const ASTGraphElementTable* const>& element_tables() const {
    return element_tables_;
  }
  const ASTGraphElementTable* element_tables(int i) const { return element_tables_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&element_tables_);
    return fl.Finalize();
  }

  absl::Span<const ASTGraphElementTable* const> element_tables_;
};

class ASTGraphElementTable final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_TABLE;

  ASTGraphElementTable() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // GraphElementTable identifier. There should exist an underlying
  // table with the same name.
  const ASTPathExpression* name() const { return name_; }

  // GraphElementTable alias.
  const ASTAlias* alias() const { return alias_; }

  // List of columns that uniquely identifies a row in GraphElementTable.
  const ASTColumnList* key_list() const { return key_list_; }

  // GraphEdgeTable should have this field referencing source node of the edge.
  const ASTGraphNodeTableReference* source_node_reference() const { return source_node_reference_; }

  // GraphEdgeTable should have this field referencing destination node of the edge.
  const ASTGraphNodeTableReference* dest_node_reference() const { return dest_node_reference_; }

  // List of Labels exposed by this ElementTable, along with the
  // Properties exposed by the Label. This list can never be empty.
  const ASTGraphElementLabelAndPropertiesList* label_properties_list() const { return label_properties_list_; }

  // If present, this is the dynamic label(s) exposed by
  // this ElementTable.
  const ASTGraphDynamicLabel* dynamic_label() const { return dynamic_label_; }

  // If present, this is the dynamic properties exposed by
  // this ElementTable.
  const ASTGraphDynamicProperties* dynamic_properties() const { return dynamic_properties_; }

  // If present, this is options associated with the default label
  // of this element table.
  const ASTOptionsList* default_label_options_list() const { return default_label_options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&key_list_, AST_COLUMN_LIST);
    fl.AddOptional(&source_node_reference_, AST_GRAPH_NODE_TABLE_REFERENCE);
    fl.AddOptional(&dest_node_reference_, AST_GRAPH_NODE_TABLE_REFERENCE);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&label_properties_list_));
    fl.AddOptional(&dynamic_label_, AST_GRAPH_DYNAMIC_LABEL);
    fl.AddOptional(&dynamic_properties_, AST_GRAPH_DYNAMIC_PROPERTIES);
    fl.AddOptional(&default_label_options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTColumnList* key_list_ = nullptr;
  const ASTGraphNodeTableReference* source_node_reference_ = nullptr;
  const ASTGraphNodeTableReference* dest_node_reference_ = nullptr;
  const ASTGraphElementLabelAndPropertiesList* label_properties_list_ = nullptr;
  const ASTGraphDynamicLabel* dynamic_label_ = nullptr;
  const ASTGraphDynamicProperties* dynamic_properties_ = nullptr;
  const ASTOptionsList* default_label_options_list_ = nullptr;
};

class ASTGraphNodeTableReference final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_NODE_TABLE_REFERENCE;

  ASTGraphNodeTableReference() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTGraphNodeTableReferenceEnums::NodeReferenceType in ast_enums.proto
  enum NodeReferenceType {
    NODE_REFERENCE_TYPE_UNSPECIFIED = ASTGraphNodeTableReferenceEnums::NODE_REFERENCE_TYPE_UNSPECIFIED,
    SOURCE = ASTGraphNodeTableReferenceEnums::SOURCE,
    DESTINATION = ASTGraphNodeTableReferenceEnums::DESTINATION
  };

  void set_node_reference_type(ASTGraphNodeTableReference::NodeReferenceType node_reference_type) { node_reference_type_ = node_reference_type; }
  ASTGraphNodeTableReference::NodeReferenceType node_reference_type() const { return node_reference_type_; }

  // Referenced GraphNodeTable alias
  const ASTIdentifier* node_table_identifier() const { return node_table_identifier_; }

  // GraphEdgeTable columns referencing GraphNodeTable columns.
  const ASTColumnList* edge_table_columns() const { return edge_table_columns_; }

  // GraphNodeTable columns referenced by GraphEdgeTable
  const ASTColumnList* node_table_columns() const { return node_table_columns_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&node_table_identifier_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&edge_table_columns_));
    fl.AddOptional(&node_table_columns_, AST_COLUMN_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* node_table_identifier_ = nullptr;
  const ASTColumnList* edge_table_columns_ = nullptr;
  const ASTColumnList* node_table_columns_ = nullptr;
  ASTGraphNodeTableReference::NodeReferenceType node_reference_type_ = ASTGraphNodeTableReference::NODE_REFERENCE_TYPE_UNSPECIFIED;
};

class ASTGraphElementLabelAndPropertiesList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_LABEL_AND_PROPERTIES_LIST;

  ASTGraphElementLabelAndPropertiesList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This can never be empty.
  const absl::Span<const ASTGraphElementLabelAndProperties* const>& label_properties_list() const {
    return label_properties_list_;
  }
  const ASTGraphElementLabelAndProperties* label_properties_list(int i) const { return label_properties_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&label_properties_list_);
    return fl.Finalize();
  }

  absl::Span<const ASTGraphElementLabelAndProperties* const> label_properties_list_;
};

class ASTGraphElementLabelAndProperties final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_LABEL_AND_PROPERTIES;

  ASTGraphElementLabelAndProperties() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Label of the element table.
  // If NULL, it is equivalent to explicitly specifying "DEFAULT LABEL" in
  // the element table definition.
  const ASTIdentifier* label_name() const { return label_name_; }

  // Options associated with the label.
  const ASTOptionsList* label_options_list() const { return label_options_list_; }

  // Properties exposed by the label.
  const ASTGraphProperties* properties() const { return properties_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&label_name_, AST_IDENTIFIER);
    fl.AddOptional(&label_options_list_, AST_OPTIONS_LIST);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&properties_));
    return fl.Finalize();
  }

  const ASTIdentifier* label_name_ = nullptr;
  const ASTOptionsList* label_options_list_ = nullptr;
  const ASTGraphProperties* properties_ = nullptr;
};

// <expression> [AS <alias>] [OPTIONS (<options>)]
class ASTGraphDerivedProperty final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_DERIVED_PROPERTY;

  ASTGraphDerivedProperty() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Sql expression for the property.
  const ASTExpression* expression() const { return expression_; }

  // Alias for the property.
  const ASTAlias* alias() const { return alias_; }

  // Options associated with the property definition.
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTExpression* expression_ = nullptr;
  const ASTAlias* alias_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTGraphDerivedPropertyList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_DERIVED_PROPERTY_LIST;

  ASTGraphDerivedPropertyList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This can never be empty.
  const absl::Span<const ASTGraphDerivedProperty* const>& properties() const {
    return properties_;
  }
  const ASTGraphDerivedProperty* properties(int i) const { return properties_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&properties_);
    return fl.Finalize();
  }

  absl::Span<const ASTGraphDerivedProperty* const> properties_;
};

class ASTGraphProperties final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PROPERTIES;

  ASTGraphProperties() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // If true, derived_property_list and all_except_columns are ignored.
  // It means NO PROPERTIES
  void set_no_properties(bool no_properties) { no_properties_ = no_properties; }
  bool no_properties() const { return no_properties_; }

  // no_properties must be false for the following to take effect:
  // If NULL, it means: PROPERTIES [ARE] ALL COLUMNS.
  // If not NULL, it means: PROPERTIES(<derived property list>);
  const ASTGraphDerivedPropertyList* derived_property_list() const { return derived_property_list_; }

  // no_properties must be false and derived_property_list must be
  // NULL for the following to take effect:
  // If not NULL, it appends optional EXCEPT(<all_except_columns>)
  // list to PROPERTIES [ARE] ALL COLUMNS.
  const ASTColumnList* all_except_columns() const { return all_except_columns_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&derived_property_list_, AST_GRAPH_DERIVED_PROPERTY_LIST);
    fl.AddOptional(&all_except_columns_, AST_COLUMN_LIST);
    return fl.Finalize();
  }

  bool no_properties_ = false;
  const ASTGraphDerivedPropertyList* derived_property_list_ = nullptr;
  const ASTColumnList* all_except_columns_ = nullptr;
};

class ASTGraphDynamicLabel final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_DYNAMIC_LABEL;

  ASTGraphDynamicLabel() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Label expression.
  const ASTExpression* label() const { return label_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&label_));
    return fl.Finalize();
  }

  const ASTExpression* label_ = nullptr;
};

class ASTGraphDynamicProperties final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_DYNAMIC_PROPERTIES;

  ASTGraphDynamicProperties() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Properties expression.
  const ASTExpression* properties() const { return properties_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&properties_));
    return fl.Finalize();
  }

  const ASTExpression* properties_ = nullptr;
};

// Represents a <graph pattern>
class ASTGraphPattern final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PATTERN;

  ASTGraphPattern() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWhereClause* where_clause() const { return where_clause_; }

  const absl::Span<const ASTGraphPathPattern* const>& paths() const {
    return paths_;
  }
  const ASTGraphPathPattern* paths(int i) const { return paths_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRepeatedWhileIsNodeKind(&paths_, AST_GRAPH_PATH_PATTERN);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    return fl.Finalize();
  }

  absl::Span<const ASTGraphPathPattern* const> paths_;
  const ASTWhereClause* where_clause_ = nullptr;
};

// This represents a graph query expression which can only be produced
// by either a top level graph query statement, or a subquery expression.
// See below docs for details:
// - (broken link):top-level-gql-query-statement
// - (broken link):gql-subquery
class ASTGqlQuery final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_QUERY;

  ASTGqlQuery() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGraphTableQuery* graph_table() const { return graph_table_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&graph_table_));
    return fl.Finalize();
  }

  const ASTGraphTableQuery* graph_table_ = nullptr;
};

// This represents a graph query expression that only contains a
// graph pattern. It can be used to construct an "EXISTS" graph subquery
// expression.
class ASTGqlGraphPatternQuery final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_GRAPH_PATTERN_QUERY;

  ASTGqlGraphPatternQuery() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Optional path expression for the target property graph.
  const ASTPathExpression* graph_reference() const { return graph_reference_; }

  const ASTGraphPattern* graph_pattern() const { return graph_pattern_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&graph_reference_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&graph_pattern_));
    return fl.Finalize();
  }

  const ASTPathExpression* graph_reference_ = nullptr;
  const ASTGraphPattern* graph_pattern_ = nullptr;
};

// This represents a graph query expression that only contains an
// ASTGqlOperatorList. It can be used to construct an "EXISTS"
// graph subquery expression with RETURN operator omitted.
class ASTGqlLinearOpsQuery final : public ASTQueryExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_LINEAR_OPS_QUERY;

  ASTGqlLinearOpsQuery() : ASTQueryExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Optional path expression for the target property graph.
  const ASTPathExpression* graph_reference() const { return graph_reference_; }

  const ASTGqlOperatorList* linear_ops() const { return linear_ops_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&graph_reference_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&linear_ops_));
    return fl.Finalize();
  }

  const ASTPathExpression* graph_reference_ = nullptr;
  const ASTGqlOperatorList* linear_ops_ = nullptr;
};

// Represents a GRAPH_TABLE() query
class ASTGraphTableQuery final : public ASTTableExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_TABLE_QUERY;

  ASTGraphTableQuery() : ASTTableExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Path expression for the target property graph.
  // If this is a subquery, the graph reference is optional and may be
  // inferred from the context.
  const ASTPathExpression* graph_reference() const { return graph_reference_; }

  // Graph matching operator. Can be an ASTGqlMatch or an
  // ASTGqlOperatorList. See (broken link):gql-graph-table for more details
  const ASTGqlOperator* graph_op() const { return graph_op_; }

  // The expression list with aliases to be projected to the outer
  // query. Exists only when `graph_op` is an ASTGqlMatch. See
  // (broken link):gql-graph-table for more details
  const ASTSelectList* graph_table_shape() const { return graph_table_shape_; }

  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&graph_reference_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&graph_op_));
    fl.AddOptional(&graph_table_shape_, AST_SELECT_LIST);
    fl.AddOptional(&alias_, AST_ALIAS);
    fl.AddRestAsRepeated(&postfix_operators_);
    return fl.Finalize();
  }

  const ASTPathExpression* graph_reference_ = nullptr;
  const ASTGqlOperator* graph_op_ = nullptr;
  const ASTSelectList* graph_table_shape_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

// Represents a graph element label expression.
class ASTGraphLabelExpression : public ASTNode {
 public:
  explicit ASTGraphLabelExpression(ASTNodeKind kind) : ASTNode(kind) {}

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  friend class ParseTreeSerializer;

 private:
  bool parenthesized_ = false;
};

class ASTGraphElementLabel final : public ASTGraphLabelExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_LABEL;

  ASTGraphElementLabel() : ASTGraphLabelExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
};

class ASTGraphWildcardLabel final : public ASTGraphLabelExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_WILDCARD_LABEL;

  ASTGraphWildcardLabel() : ASTGraphLabelExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

class ASTGraphLabelOperation final : public ASTGraphLabelExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_LABEL_OPERATION;

  ASTGraphLabelOperation() : ASTGraphLabelExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  // This enum is equivalent to ASTGraphLabelOperationEnums::OperationType in ast_enums.proto
  enum OperationType {
    OPERATION_TYPE_UNSPECIFIED = ASTGraphLabelOperationEnums::OPERATION_TYPE_UNSPECIFIED,
    NOT = ASTGraphLabelOperationEnums::NOT,
    AND = ASTGraphLabelOperationEnums::AND,
    OR = ASTGraphLabelOperationEnums::OR
  };

  void set_op_type(ASTGraphLabelOperation::OperationType op_type) { op_type_ = op_type; }
  ASTGraphLabelOperation::OperationType op_type() const { return op_type_; }

  const absl::Span<const ASTGraphLabelExpression* const>& inputs() const {
    return inputs_;
  }
  const ASTGraphLabelExpression* inputs(int i) const { return inputs_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&inputs_);
    return fl.Finalize();
  }

  ASTGraphLabelOperation::OperationType op_type_ = ASTGraphLabelOperation::OPERATION_TYPE_UNSPECIFIED;
  absl::Span<const ASTGraphLabelExpression* const> inputs_;
};

// Filter label on a graph node or edge pattern. This node wraps the label
// expression filter just like ASTWhereClause wraps the scalar filter
// expression.
class ASTGraphLabelFilter final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_LABEL_FILTER;

  ASTGraphLabelFilter() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGraphLabelExpression* label_expression() const { return label_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&label_expression_));
    return fl.Finalize();
  }

  const ASTGraphLabelExpression* label_expression_ = nullptr;
};

// Binary expression which contains an element variable name `operand` and
// a `label_expression`.
// Note we do not use ASTBinaryExpression because we need to accommodate
// `label_expression` which is not an `expression`.
class ASTGraphIsLabeledPredicate final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_IS_LABELED_PREDICATE;

  ASTGraphIsLabeledPredicate() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // Signifies whether the predicate has a NOT.
  // Used for "IS NOT LABELED"
  void set_is_not(bool is_not) { is_not_ = is_not; }
  bool is_not() const { return is_not_; }

  const ASTExpression* operand() const { return operand_; }
  const ASTGraphLabelExpression* label_expression() const { return label_expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&operand_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&label_expression_));
    return fl.Finalize();
  }

  bool is_not_ = false;
  const ASTExpression* operand_ = nullptr;
  const ASTGraphLabelExpression* label_expression_ = nullptr;
};

// Filler of an element pattern which can contain the element variable name
// of this pattern and two element filters (label-based filter and where
// clause filter).
class ASTGraphElementPatternFiller final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_ELEMENT_PATTERN_FILLER;

  ASTGraphElementPatternFiller() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* variable_name() const { return variable_name_; }
  const ASTGraphLabelFilter* label_filter() const { return label_filter_; }
  const ASTWhereClause* where_clause() const { return where_clause_; }
  const ASTGraphPropertySpecification* property_specification() const { return property_specification_; }
  const ASTHint* hint() const { return hint_; }
  const ASTExpression* edge_cost() const { return edge_cost_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&variable_name_, AST_IDENTIFIER);
    fl.AddOptional(&label_filter_, AST_GRAPH_LABEL_FILTER);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    fl.AddOptional(&property_specification_, AST_GRAPH_PROPERTY_SPECIFICATION);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptionalExpression(&edge_cost_);
    return fl.Finalize();
  }

  const ASTIdentifier* variable_name_ = nullptr;
  const ASTGraphLabelFilter* label_filter_ = nullptr;
  const ASTWhereClause* where_clause_ = nullptr;
  const ASTGraphPropertySpecification* property_specification_ = nullptr;
  const ASTHint* hint_ = nullptr;
  const ASTExpression* edge_cost_ = nullptr;
};

// The property specification that contains a list of property name and value
// .
class ASTGraphPropertySpecification final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PROPERTY_SPECIFICATION;

  ASTGraphPropertySpecification() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTGraphPropertyNameAndValue* const>& property_name_and_value() const {
    return property_name_and_value_;
  }
  const ASTGraphPropertyNameAndValue* property_name_and_value(int i) const { return property_name_and_value_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&property_name_and_value_);
    return fl.Finalize();
  }

  absl::Span<const ASTGraphPropertyNameAndValue* const> property_name_and_value_;
};

// Property name and value pair.
class ASTGraphPropertyNameAndValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PROPERTY_NAME_AND_VALUE;

  ASTGraphPropertyNameAndValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* property_name() const { return property_name_; }
  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&property_name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTIdentifier* property_name_ = nullptr;
  const ASTExpression* value_ = nullptr;
};

// Common base class for ASTGraphElementPattern and ASTGraphPathPattern.
// Both are potentially quantified.
class ASTGraphPathBase : public ASTNode {
 public:
  explicit ASTGraphPathBase(ASTNodeKind kind) : ASTNode(kind) {}

  const ASTQuantifier* quantifier() const { return quantifier_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTQuantifier* quantifier_ = nullptr;
};

// Represents one element pattern.
class ASTGraphElementPattern : public ASTGraphPathBase {
 public:
  explicit ASTGraphElementPattern(ASTNodeKind kind) : ASTGraphPathBase(kind) {}

  const ASTGraphElementPatternFiller* filler() const { return filler_; }

  friend class ParseTreeSerializer;

 protected:
  const ASTGraphElementPatternFiller* filler_ = nullptr;
};

// ASTGraphElementPattern that represents one node pattern.
class ASTGraphNodePattern final : public ASTGraphElementPattern {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_NODE_PATTERN;

  ASTGraphNodePattern() : ASTGraphElementPattern(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&filler_, AST_GRAPH_ELEMENT_PATTERN_FILLER);
    fl.AddOptionalQuantifier(&quantifier_);
    return fl.Finalize();
  }
};

// ASTGraphLhsHint is used to represent a hint that occurs on a traversal
// from a node to an inbound edge.
class ASTGraphLhsHint final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_LHS_HINT;

  ASTGraphLhsHint() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
};

// ASTGraphRhsHint is used to represent a hint that occurs on a traversal
// from an outbound edge to a node.
class ASTGraphRhsHint final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_RHS_HINT;

  ASTGraphRhsHint() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTHint* hint() const { return hint_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
};

// Represents a path pattern search prefix which restricts the result from a
// graph pattern match by partitioning the resulting paths by their endpoints
// (the first and last vertices) and makes a selection of paths from each
// partition.
// path_count refers to the number of paths to select from each partition,
// if unspecified only one path is selected.
class ASTGraphPathSearchPrefix final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PATH_SEARCH_PREFIX;

  ASTGraphPathSearchPrefix() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTGraphPathSearchPrefixEnums::PathSearchPrefixType in ast_enums.proto
  enum PathSearchPrefixType {
    PATH_SEARCH_PREFIX_TYPE_UNSPECIFIED = ASTGraphPathSearchPrefixEnums::PATH_SEARCH_PREFIX_TYPE_UNSPECIFIED,
    ANY = ASTGraphPathSearchPrefixEnums::ANY,
    SHORTEST = ASTGraphPathSearchPrefixEnums::SHORTEST,
    ALL = ASTGraphPathSearchPrefixEnums::ALL,
    ALL_SHORTEST = ASTGraphPathSearchPrefixEnums::ALL_SHORTEST,
    CHEAPEST = ASTGraphPathSearchPrefixEnums::CHEAPEST,
    ALL_CHEAPEST = ASTGraphPathSearchPrefixEnums::ALL_CHEAPEST
  };

  void set_type(ASTGraphPathSearchPrefix::PathSearchPrefixType type) { type_ = type; }
  ASTGraphPathSearchPrefix::PathSearchPrefixType type() const { return type_; }

  const ASTGraphPathSearchPrefixCount* path_count() const { return path_count_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_count_, AST_GRAPH_PATH_SEARCH_PREFIX_COUNT);
    return fl.Finalize();
  }

  ASTGraphPathSearchPrefix::PathSearchPrefixType type_ = ASTGraphPathSearchPrefix::PATH_SEARCH_PREFIX_TYPE_UNSPECIFIED;
  const ASTGraphPathSearchPrefixCount* path_count_ = nullptr;
};

// Represents the number of paths to retain from each partition of path
// bindings containing the same head and tail.
class ASTGraphPathSearchPrefixCount final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PATH_SEARCH_PREFIX_COUNT;

  ASTGraphPathSearchPrefixCount() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* path_count() const { return path_count_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&path_count_));
    return fl.Finalize();
  }

  const ASTExpression* path_count_ = nullptr;
};

// ASTGraphElementPattern that represents one edge pattern.
class ASTGraphEdgePattern final : public ASTGraphElementPattern {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_EDGE_PATTERN;

  ASTGraphEdgePattern() : ASTGraphElementPattern(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTGraphEdgePatternEnums::EdgeOrientation in ast_enums.proto
  enum EdgeOrientation {
    EDGE_ORIENTATION_NOT_SET = ASTGraphEdgePatternEnums::EDGE_ORIENTATION_NOT_SET,
    ANY = ASTGraphEdgePatternEnums::ANY,
    LEFT = ASTGraphEdgePatternEnums::LEFT,
    RIGHT = ASTGraphEdgePatternEnums::RIGHT
  };

  void set_orientation(ASTGraphEdgePattern::EdgeOrientation orientation) { orientation_ = orientation; }
  ASTGraphEdgePattern::EdgeOrientation orientation() const { return orientation_; }

  const ASTGraphLhsHint* lhs_hint() const { return lhs_hint_; }
  const ASTGraphRhsHint* rhs_hint() const { return rhs_hint_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalQuantifier(&quantifier_);
    fl.AddOptional(&lhs_hint_, AST_GRAPH_LHS_HINT);
    fl.AddOptional(&rhs_hint_, AST_GRAPH_RHS_HINT);
    fl.AddOptional(&filler_, AST_GRAPH_ELEMENT_PATTERN_FILLER);
    return fl.Finalize();
  }

  ASTGraphEdgePattern::EdgeOrientation orientation_ = ASTGraphEdgePattern::EDGE_ORIENTATION_NOT_SET;
  const ASTGraphLhsHint* lhs_hint_ = nullptr;
  const ASTGraphRhsHint* rhs_hint_ = nullptr;
};

// Represents path mode.
class ASTGraphPathMode final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PATH_MODE;

  ASTGraphPathMode() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTGraphPathModeEnums::PathMode in ast_enums.proto
  enum PathMode {
    PATH_MODE_UNSPECIFIED = ASTGraphPathModeEnums::PATH_MODE_UNSPECIFIED,
    WALK = ASTGraphPathModeEnums::WALK,
    TRAIL = ASTGraphPathModeEnums::TRAIL,
    SIMPLE = ASTGraphPathModeEnums::SIMPLE,
    ACYCLIC = ASTGraphPathModeEnums::ACYCLIC
  };

  void set_path_mode(ASTGraphPathMode::PathMode path_mode) { path_mode_ = path_mode; }
  ASTGraphPathMode::PathMode path_mode() const { return path_mode_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTGraphPathMode::PathMode path_mode_ = ASTGraphPathMode::PATH_MODE_UNSPECIFIED;
};

// Represents a path pattern that contains a list of element
// patterns or subpath patterns.
class ASTGraphPathPattern final : public ASTGraphPathBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GRAPH_PATH_PATTERN;

  ASTGraphPathPattern() : ASTGraphPathBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This adds the "parenthesized" modifier to the node name.
  std::string SingleNodeDebugString() const override;

  void set_parenthesized(bool parenthesized) { parenthesized_ = parenthesized; }
  bool parenthesized() const { return parenthesized_; }

  const ASTHint* hint() const { return hint_; }
  const ASTWhereClause* where_clause() const { return where_clause_; }
  const ASTGraphPathMode* path_mode() const { return path_mode_; }
  const ASTGraphPathSearchPrefix* search_prefix() const { return search_prefix_; }
  const ASTIdentifier* path_name() const { return path_name_; }

  const absl::Span<const ASTGraphPathBase* const>& input_pattern_list() const {
    return input_pattern_list_;
  }
  const ASTGraphPathBase* input_pattern_list(int i) const { return input_pattern_list_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&hint_, AST_HINT);
    fl.AddOptionalQuantifier(&quantifier_);
    fl.AddOptional(&where_clause_, AST_WHERE_CLAUSE);
    fl.AddOptional(&path_name_, AST_IDENTIFIER);
    fl.AddOptional(&search_prefix_, AST_GRAPH_PATH_SEARCH_PREFIX);
    fl.AddOptional(&path_mode_, AST_GRAPH_PATH_MODE);
    fl.AddRestAsRepeated(&input_pattern_list_);
    return fl.Finalize();
  }

  const ASTHint* hint_ = nullptr;
  const ASTWhereClause* where_clause_ = nullptr;
  const ASTGraphPathMode* path_mode_ = nullptr;
  const ASTGraphPathSearchPrefix* search_prefix_ = nullptr;
  absl::Span<const ASTGraphPathBase* const> input_pattern_list_;
  bool parenthesized_ = false;
  const ASTIdentifier* path_name_ = nullptr;
};

// Represents a generic graph operator in GoogleSQL graph query language.
class ASTGqlOperator : public ASTNode {
 public:
  explicit ASTGqlOperator(ASTNodeKind kind) : ASTNode(kind) {}

  friend class ParseTreeSerializer;
};

// Represents a MATCH operator in GoogleSQL graph query language,
// which simply contains <graph pattern>.
class ASTGqlMatch final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_MATCH;

  ASTGqlMatch() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  std::string SingleNodeDebugString() const override;

  void set_optional(bool optional) { optional_ = optional; }
  bool optional() const { return optional_; }

  const ASTGraphPattern* graph_pattern() const { return graph_pattern_; }
  const ASTHint* hint() const { return hint_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&graph_pattern_));
    fl.AddOptional(&hint_, AST_HINT);
    return fl.Finalize();
  }

  const ASTGraphPattern* graph_pattern_ = nullptr;
  bool optional_ = false;
  const ASTHint* hint_ = nullptr;
};

// Represents a RETURN operator in GoogleSQL graph query language.
// RETURN is represented with an ASTSelect with only the
// SELECT, DISTINCT, and (optionally) GROUP BY clause present.
// Using this representation rather than storing an ASTSelectList and
// ASTGroupBy makes sharing resolver code easier.
class ASTGqlReturn final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_RETURN;

  ASTGqlReturn() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelect* select() const { return select_; }
  const ASTGqlOrderByAndPage* order_by_page() const { return order_by_page_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    fl.AddOptional(&order_by_page_, AST_GQL_ORDER_BY_AND_PAGE);
    return fl.Finalize();
  }

  const ASTSelect* select_ = nullptr;
  const ASTGqlOrderByAndPage* order_by_page_ = nullptr;
};

// Represents a WITH operator in GoogleSQL graph query language.
// WITH is represented with an ASTSelect with only the
// SELECT clause present.
class ASTGqlWith final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_WITH;

  ASTGqlWith() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSelect* select() const { return select_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&select_));
    return fl.Finalize();
  }

  const ASTSelect* select_ = nullptr;
};

// Represents a FOR operator in GoogleSQL graph query language.
class ASTGqlFor final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_FOR;

  ASTGqlFor() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }
  const ASTExpression* expression() const { return expression_; }
  const ASTWithOffset* with_offset() const { return with_offset_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    fl.AddOptional(&with_offset_, AST_WITH_OFFSET);
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  const ASTExpression* expression_ = nullptr;
  const ASTWithOffset* with_offset_ = nullptr;
};

// Represents a GQL CALL operator.
// Note that this is different from the pipe Call.
class ASTGqlCallBase : public ASTGqlOperator {
 public:
  explicit ASTGqlCallBase(ASTNodeKind kind) : ASTGqlOperator(kind) {}

  void set_optional(bool optional) { optional_ = optional; }
  bool optional() const { return optional_; }

  // Indicates whether this call partitions the input working table.
  //
  // When set, the `name_capture_list` defines the partitioning
  // columns. The target of this CALL operation (TVF or subquery) is
  // invoked for each partition. This is a FOR EACH PARTITION BY
  // operation (and if the list is empty, a simple TVF call).
  //
  // Otherwise, the target is invoked for each row in the input
  // (like LATERAL join). The `name_capture_list` contains the
  // columns exposed to the derived subquery/TVF (i.e., these are the
  // columns which can be referenced "laterally").
  //
  // Note that both cases can be viewed as similar, if we consider
  // that the "non-partitioning" case is still partitioning but by
  // a hidden row ID column which leads to each row being in its own
  // partition.
  void set_is_partitioning(bool is_partitioning) { is_partitioning_ = is_partitioning; }
  bool is_partitioning() const { return is_partitioning_; }

  // The list of columns exposed to the target TVF or subquery of
  // this CALL. If `is_partitioning` is set, these are the
  // partitioning columns. Otherwise, these are the columns which can
  // be referenced "laterally".
  const ASTIdentifierList* name_capture_list() const { return name_capture_list_; }

  friend class ParseTreeSerializer;

 protected:
  bool optional_ = false;
  bool is_partitioning_ = false;
  const ASTIdentifierList* name_capture_list_ = nullptr;
};

// Represents a GQL CALL operator to a named TVF.
class ASTGqlNamedCall final : public ASTGqlCallBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_NAMED_CALL;

  ASTGqlNamedCall() : ASTGqlCallBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTTVF* tvf_call() const { return tvf_call_; }

  // Represents the YIELD clause, if present.
  const ASTYieldItemList* yield_clause() const { return yield_clause_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&tvf_call_));
    fl.AddOptional(&yield_clause_, AST_YIELD_ITEM_LIST);
    fl.AddOptional(&name_capture_list_, AST_IDENTIFIER_LIST);
    return fl.Finalize();
  }

  const ASTTVF* tvf_call_ = nullptr;
  const ASTYieldItemList* yield_clause_ = nullptr;
};

// Represents the YIELD clause.
class ASTYieldItemList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_YIELD_ITEM_LIST;

  ASTYieldItemList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The list of YIELD items in the YIELD clause. The grammar
  // guarantees that this list is never empty.
  const absl::Span<const ASTExpressionWithOptAlias* const>& yield_items() const {
    return yield_items_;
  }
  const ASTExpressionWithOptAlias* yield_items(int i) const { return yield_items_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&yield_items_);
    return fl.Finalize();
  }

  absl::Span<const ASTExpressionWithOptAlias* const> yield_items_;
};

// Represents a GQL CALL operator to an inline subquery.
class ASTGqlInlineSubqueryCall final : public ASTGqlCallBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_INLINE_SUBQUERY_CALL;

  ASTGqlInlineSubqueryCall() : ASTGqlCallBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTQuery* subquery() const { return subquery_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&subquery_));
    fl.AddOptional(&name_capture_list_, AST_IDENTIFIER_LIST);
    return fl.Finalize();
  }

  const ASTQuery* subquery_ = nullptr;
};

// Represents a LET operator in GoogleSQL graph query language
class ASTGqlLet final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_LET;

  ASTGqlLet() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTGqlLetVariableDefinitionList* variable_definition_list() const { return variable_definition_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&variable_definition_list_));
    return fl.Finalize();
  }

  const ASTGqlLetVariableDefinitionList* variable_definition_list_ = nullptr;
};

// Represents column definitions within a LET statement of a GQL query
class ASTGqlLetVariableDefinitionList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_LET_VARIABLE_DEFINITION_LIST;

  ASTGqlLetVariableDefinitionList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTGqlLetVariableDefinition* const>& variable_definitions() const {
    return variable_definitions_;
  }
  const ASTGqlLetVariableDefinition* variable_definitions(int i) const { return variable_definitions_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&variable_definitions_);
    return fl.Finalize();
  }

  absl::Span<const ASTGqlLetVariableDefinition* const> variable_definitions_;
};

// Represents one column definition within a LET statement of a GQL query
class ASTGqlLetVariableDefinition final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_LET_VARIABLE_DEFINITION;

  ASTGqlLetVariableDefinition() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }
  const ASTExpression* expression() const { return expression_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&expression_));
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  const ASTExpression* expression_ = nullptr;
};

// Represents a FILTER operator within GoogleSQL Graph query language.
class ASTGqlFilter final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_FILTER;

  ASTGqlFilter() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTWhereClause* condition() const { return condition_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&condition_));
    return fl.Finalize();
  }

  const ASTWhereClause* condition_ = nullptr;
};

// Represents a linear graph query operator in
// GoogleSQL graph query language, which contains a vector of child
// graph query operators.
class ASTGqlOperatorList final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_OPERATOR_LIST;

  ASTGqlOperatorList() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTGqlOperator* const>& operators() const {
    return operators_;
  }
  const ASTGqlOperator* operators(int i) const { return operators_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&operators_);
    return fl.Finalize();
  }

  absl::Span<const ASTGqlOperator* const> operators_;
};

// Represents a composite query statement, aka. set operation, in
// GoogleSQL graph query language. Each input is one linear graph query.
class ASTGqlSetOperation final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_SET_OPERATION;

  ASTGqlSetOperation() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSetOperationMetadataList* metadata() const { return metadata_; }

  const absl::Span<const ASTGqlOperator* const>& inputs() const {
    return inputs_;
  }
  const ASTGqlOperator* inputs(int i) const { return inputs_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&metadata_));
    fl.AddRestAsRepeated(&inputs_);
    return fl.Finalize();
  }

  const ASTSetOperationMetadataList* metadata_ = nullptr;
  absl::Span<const ASTGqlOperator* const> inputs_;
};

// Represents the LIMIT clause of a GQL '[<order by>] [<offset>] [<limit>]`
// linear query statement. It is a child of ASTGqlPage. Note: we cannot use
// an ASTLimitOffset node because its 'limit' field is required, while it can
// be optional in GQL linear queries. We also cannot have two
// consecutive OPTIONAL_EXPRESSION fields in ASTGqlPage.
class ASTGqlPageLimit final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_PAGE_LIMIT;

  ASTGqlPageLimit() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* limit() const { return limit_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&limit_));
    return fl.Finalize();
  }

  const ASTExpression* limit_ = nullptr;
};

// Represents the OFFSET clause of a GQL '[<order by>] [<offset>] [<limit>]`
// linear query statement. It is a child of ASTGqlPage. Note: we cannot use
// an ASTLimitOffset node because its 'limit' field is required, while it can
// be optional in GQL linear queries. We also cannot have two
// consecutive OPTIONAL_EXPRESSION fields in ASTGqlPage.
class ASTGqlPageOffset final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_PAGE_OFFSET;

  ASTGqlPageOffset() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* offset() const { return offset_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&offset_));
    return fl.Finalize();
  }

  const ASTExpression* offset_ = nullptr;
};

// Groups together ASTGqlPageOffset and ASTGqlPageLimit nodes. Note: we
// cannot use an ASTLimitOffset node because its 'limit' field is required,
// while it can be optional in GQL linear queries. We also cannot have two
// consecutive OPTIONAL_EXPRESSION fields.
class ASTGqlPage final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_PAGE;

  ASTGqlPage() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The OFFSET value. Offset and limit are independent, and can be
  // present or not regardless of whether the other is present.
  const ASTGqlPageOffset* offset() const { return offset_; }

  // The LIMIT value. Offset and limit are independent, and can be
  // present or not regardless of whether the other is present.
  const ASTGqlPageLimit* limit() const { return limit_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&offset_, AST_GQL_PAGE_OFFSET);
    fl.AddOptional(&limit_, AST_GQL_PAGE_LIMIT);
    return fl.Finalize();
  }

  const ASTGqlPageOffset* offset_ = nullptr;
  const ASTGqlPageLimit* limit_ = nullptr;
};

// Represents the three clauses of a GQL '[<order by>] [<offset>] [<limit>]`
// linear query statement.
class ASTGqlOrderByAndPage final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_ORDER_BY_AND_PAGE;

  ASTGqlOrderByAndPage() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTOrderBy* order_by() const { return order_by_; }
  const ASTGqlPage* page() const { return page_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&order_by_, AST_ORDER_BY);
    fl.AddOptional(&page_, AST_GQL_PAGE);
    return fl.Finalize();
  }

  const ASTOrderBy* order_by_ = nullptr;
  const ASTGqlPage* page_ = nullptr;
};

// Represents a SAMPLE operator within GoogleSQL Graph query language.
class ASTGqlSample final : public ASTGqlOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_GQL_SAMPLE;

  ASTGqlSample() : ASTGqlOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSampleClause* sample() const { return sample_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&sample_));
    return fl.Finalize();
  }

  const ASTSampleClause* sample_ = nullptr;
};

// Represents WITH modifier clause (e.g., `SELECT WITH`, `|> AGGREGATE WITH`).
class ASTWithModifier final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_WITH_MODIFIER;

  ASTWithModifier() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* identifier() const { return identifier_; }
  const ASTOptionsList* options() const { return options_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&identifier_));
    fl.AddOptional(&options_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* identifier_ = nullptr;
  const ASTOptionsList* options_ = nullptr;
};

class ASTColumnWithOptions final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_WITH_OPTIONS;

  ASTColumnWithOptions() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTColumnWithOptionsList final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_COLUMN_WITH_OPTIONS_LIST;

  ASTColumnWithOptionsList() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const absl::Span<const ASTColumnWithOptions* const>& column_with_options() const {
    return column_with_options_;
  }
  const ASTColumnWithOptions* column_with_options(int i) const { return column_with_options_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddRestAsRepeated(&column_with_options_);
    return fl.Finalize();
  }

  absl::Span<const ASTColumnWithOptions* const> column_with_options_;
};

// Represents the body of a DEFINE MACRO statement.
class ASTMacroBody final : public ASTPrintableLeaf {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MACRO_BODY;

  ASTMacroBody() : ASTPrintableLeaf(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }
};

// Represents a DEFINE MACRO statement.
class ASTDefineMacroStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_DEFINE_MACRO_STATEMENT;

  ASTDefineMacroStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTIdentifier* name() const { return name_; }
  const ASTMacroBody* body() const { return body_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&body_));
    return fl.Finalize();
  }

  const ASTIdentifier* name_ = nullptr;
  const ASTMacroBody* body_ = nullptr;
};

// This represents an UNDROP statement (broken link)
class ASTUndropStatement final : public ASTDdlStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_UNDROP_STATEMENT;

  ASTUndropStatement() : ASTDdlStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_schema_object_kind(SchemaObjectKind schema_object_kind) { schema_object_kind_ = schema_object_kind; }
  SchemaObjectKind schema_object_kind() const { return schema_object_kind_; }
  void set_is_if_not_exists(bool is_if_not_exists) { is_if_not_exists_ = is_if_not_exists; }
  bool is_if_not_exists() const { return is_if_not_exists_; }

  const ASTPathExpression* name() const { return name_; }
  const ASTForSystemTime* for_system_time() const { return for_system_time_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&for_system_time_, AST_FOR_SYSTEM_TIME);
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  SchemaObjectKind schema_object_kind_ = kInvalidSchemaObjectKind;
  const ASTPathExpression* name_ = nullptr;
  bool is_if_not_exists_ = false;
  const ASTForSystemTime* for_system_time_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

class ASTIdentityColumnInfo final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTITY_COLUMN_INFO;

  ASTIdentityColumnInfo() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  void set_cycling_enabled(bool cycling_enabled) { cycling_enabled_ = cycling_enabled; }
  bool cycling_enabled() const { return cycling_enabled_; }

  const ASTIdentityColumnStartWith* start_with_value() const { return start_with_value_; }
  const ASTIdentityColumnIncrementBy* increment_by_value() const { return increment_by_value_; }
  const ASTIdentityColumnMaxValue* max_value() const { return max_value_; }
  const ASTIdentityColumnMinValue* min_value() const { return min_value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&start_with_value_, AST_IDENTITY_COLUMN_START_WITH);
    fl.AddOptional(&increment_by_value_, AST_IDENTITY_COLUMN_INCREMENT_BY);
    fl.AddOptional(&max_value_, AST_IDENTITY_COLUMN_MAX_VALUE);
    fl.AddOptional(&min_value_, AST_IDENTITY_COLUMN_MIN_VALUE);
    return fl.Finalize();
  }

  const ASTIdentityColumnStartWith* start_with_value_ = nullptr;
  const ASTIdentityColumnIncrementBy* increment_by_value_ = nullptr;
  const ASTIdentityColumnMaxValue* max_value_ = nullptr;
  const ASTIdentityColumnMinValue* min_value_ = nullptr;
  bool cycling_enabled_ = false;
};

class ASTIdentityColumnStartWith final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTITY_COLUMN_START_WITH;

  ASTIdentityColumnStartWith() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTExpression* value_ = nullptr;
};

class ASTIdentityColumnIncrementBy final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTITY_COLUMN_INCREMENT_BY;

  ASTIdentityColumnIncrementBy() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTExpression* value_ = nullptr;
};

class ASTIdentityColumnMaxValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTITY_COLUMN_MAX_VALUE;

  ASTIdentityColumnMaxValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTExpression* value_ = nullptr;
};

class ASTIdentityColumnMinValue final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_IDENTITY_COLUMN_MIN_VALUE;

  ASTIdentityColumnMinValue() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* value() const { return value_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_));
    return fl.Finalize();
  }

  const ASTExpression* value_ = nullptr;
};

class ASTAliasedQueryModifiers final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALIASED_QUERY_MODIFIERS;

  ASTAliasedQueryModifiers() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTRecursionDepthModifier* recursion_depth_modifier() const { return recursion_depth_modifier_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&recursion_depth_modifier_, AST_RECURSION_DEPTH_MODIFIER);
    return fl.Finalize();
  }

  const ASTRecursionDepthModifier* recursion_depth_modifier_ = nullptr;
};

// This represents an integer or an unbounded integer.
// The semantic of unbounded integer depends on the context.
class ASTIntOrUnbounded final : public ASTExpression {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_INT_OR_UNBOUNDED;

  ASTIntOrUnbounded() : ASTExpression(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTExpression* bound() const { return bound_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptionalExpression(&bound_);
    return fl.Finalize();
  }

  const ASTExpression* bound_ = nullptr;
};

class ASTRecursionDepthModifier final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RECURSION_DEPTH_MODIFIER;

  ASTRecursionDepthModifier() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTAlias* alias() const { return alias_; }

  // lower bound is 0 when the node's `bound` field is unset.
  const ASTIntOrUnbounded* lower_bound() const { return lower_bound_; }

  // upper_bound is infinity when the node's `bound` field is unset.
  const ASTIntOrUnbounded* upper_bound() const { return upper_bound_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&alias_, AST_ALIAS);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&lower_bound_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&upper_bound_));
    return fl.Finalize();
  }

  const ASTAlias* alias_ = nullptr;
  const ASTIntOrUnbounded* lower_bound_ = nullptr;
  const ASTIntOrUnbounded* upper_bound_ = nullptr;
};

class ASTMapType final : public ASTType {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_MAP_TYPE;

  ASTMapType() : ASTType(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTType* key_type() const { return key_type_; }
  const ASTType* value_type() const { return value_type_; }
  const ASTTypeParameterList* type_parameters() const override { return type_parameters_; }
  const ASTCollate* collate() const override { return collate_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&key_type_));
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&value_type_));
    fl.AddOptional(&type_parameters_, AST_TYPE_PARAMETER_LIST);
    fl.AddOptional(&collate_, AST_COLLATE);
    return fl.Finalize();
  }

  const ASTType* key_type_ = nullptr;
  const ASTType* value_type_ = nullptr;
  const ASTTypeParameterList* type_parameters_ = nullptr;
  const ASTCollate* collate_ = nullptr;
};

class ASTLockMode final : public ASTNode {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_LOCK_MODE;

  ASTLockMode() : ASTNode(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // This enum is equivalent to ASTLockModeEnums::LockStrengthSpec in ast_enums.proto
  enum LockStrengthSpec {
    NOT_SET = ASTLockModeEnums::NOT_SET,
    UPDATE = ASTLockModeEnums::UPDATE
  };

  // The lock strength. Never NULL.
  void set_strength(ASTLockMode::LockStrengthSpec strength) { strength_ = strength; }
  ASTLockMode::LockStrengthSpec strength() const { return strength_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    return fl.Finalize();
  }

  ASTLockMode::LockStrengthSpec strength_ = ASTLockMode::NOT_SET;
};

// Represents a pipe RECURSIVE UNION operator ((broken link)):
// ```
// |> RECURSIVE [outer_mode] UNION {ALL | DISTINCT} [corresponding_spec]
//    [recursion_depth_clause]
//    {<subquery> | <subpipeline>}
//    [AS alias]
// ```
//
// It is semantically the same as the standard recursive queries using WITH
// RECURSIVE but the syntax is more intuitive.
//
// It supports subqueries or subpipelines as input.
// Exactly one of `input_subquery` and `input_subpipeline` will be set.
class ASTPipeRecursiveUnion final : public ASTPipeOperator {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_PIPE_RECURSIVE_UNION;

  ASTPipeRecursiveUnion() : ASTPipeOperator(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTSetOperationMetadata* metadata() const { return metadata_; }

  // The optional recursion depth modifier for the recursive query.
  const ASTRecursionDepthModifier* recursion_depth_modifier() const { return recursion_depth_modifier_; }

  // The input subpipeline for the recursive union operator. The
  // input table to the subpipeline is the output of the previous
  // iteration.
  //
  // Example:
  //
  // ```SQL
  // FROM KeyValue
  // |> RECURSIVE UNION ALL (
  //     |> SET value = value + 1
  //     |> WHERE key < 10
  //   )
  const ASTSubpipeline* input_subpipeline() const { return input_subpipeline_; }

  // The input subquery for the recursive union operator.
  //
  // Example:
  //
  // ```SQL
  // FROM KeyValue
  // |> RECURSIVE UNION ALL (
  //     SELECT key, value + 1 AS value
  //     FROM KeyValue
  //     WHERE key < 10
  //   )
  // ```
  const ASTQueryExpression* input_subquery() const { return input_subquery_; }

  // The optional alias for the result of the recursive union. Note
  // it acts as both the input table to the next iteration, and the
  // output table of the recursive union. For example, in the
  // following query:
  //
  // ```SQL
  // FROM TreeNodes
  // |> RECURSIVE UNION ALL (
  //   |> JOIN TreeNodes AS child_node ON
  //       nodes.id = child_node.parent_id
  //   |> SELECT child_node.*
  // ) AS nodes;
  // ```
  //
  // The alias `nodes` is the output table of the recursive union,
  // and the input table to the next iteration.
  const ASTAlias* alias() const { return alias_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&metadata_));
    fl.AddOptional(&recursion_depth_modifier_, AST_RECURSION_DEPTH_MODIFIER);
    fl.AddOptional(&input_subpipeline_, AST_SUBPIPELINE);
    fl.AddOptionalIfSubkind<ASTQueryExpression>(&input_subquery_);
    fl.AddOptional(&alias_, AST_ALIAS);
    return fl.Finalize();
  }

  const ASTSetOperationMetadata* metadata_ = nullptr;
  const ASTRecursionDepthModifier* recursion_depth_modifier_ = nullptr;
  const ASTSubpipeline* input_subpipeline_ = nullptr;
  const ASTQueryExpression* input_subquery_ = nullptr;
  const ASTAlias* alias_ = nullptr;
};

// Represents a RUN statement.
//
// Syntax: RUN <child_script_path> [(<named_arguments>)]
//
// The RUN statement is used to execute statements in a separate script.
// The child script path maybe specified as a string literal or a path
// expression.
//
// Optional named arguments are supported using either `=>` or `=`.
//
// With path expression syntax, parentheses are required even if there are
// no arguments.
//
// Examples:
// ```
// -- Parentheses are optional when using string literal syntax.
// RUN "path/to/script.sql";
// RUN "path/to/script.sql"(foo => "bar");
// RUN "path/to/another_script.sql"();
// RUN my_catalog.my_script(foo => "bar");
//
// -- Parentheses are NOT optional when using path expression syntax.
// RUN my_catalog.my_script();
// ```
class ASTRunStatement final : public ASTStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_RUN_STATEMENT;

  ASTRunStatement() : ASTStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  // The target script addressed using an ASTPathExpression.
  // Exactly one of `target_path` and `target_string` will be set.
  //
  // e.g. `RUN my_catalog.my_script();`
  const ASTPathExpression* target_path_expression() const { return target_path_expression_; }

  // The target script addressed by a ASTStringLiteral.
  // Exactly one of `target_path` and `target_string` will be set.
  //
  // e.g. `RUN "path/to/script.sql";`
  const ASTStringLiteral* target_string_literal() const { return target_string_literal_; }

  // Represents named arguments supplied to the child script
  // for parameter substitution. Arguments are optional.
  //
  // Argument names are required to be valid identifiers, and
  // argument values are required to be string literals.
  //
  // Examples:
  // ```
  // RUN my_catalog.preamble();
  // RUN my_catalog.my_script(foo => "bar")
  // ```
  const absl::Span<const ASTNamedArgument* const>& arguments() const {
    return arguments_;
  }
  const ASTNamedArgument* arguments(int i) const { return arguments_[i]; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&target_path_expression_, AST_PATH_EXPRESSION);
    fl.AddOptional(&target_string_literal_, AST_STRING_LITERAL);
    fl.AddRestAsRepeated(&arguments_);
    return fl.Finalize();
  }

  const ASTPathExpression* target_path_expression_ = nullptr;
  const ASTStringLiteral* target_string_literal_ = nullptr;
  absl::Span<const ASTNamedArgument* const> arguments_;
};

// This represents a CREATE SEQUENCE statement, i.e.,
// CREATE [OR REPLACE] SEQUENCE
//   [IF NOT EXISTS] <name_path> OPTIONS (name=value, ...);
class ASTCreateSequenceStatement final : public ASTCreateStatement {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_CREATE_SEQUENCE_STATEMENT;

  ASTCreateSequenceStatement() : ASTCreateStatement(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  const ASTPathExpression* name() const { return name_; }
  const ASTOptionsList* options_list() const { return options_list_; }

  const ASTPathExpression* GetDdlTarget() const override { return name_; }

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&name_));
    fl.AddOptional(&options_list_, AST_OPTIONS_LIST);
    return fl.Finalize();
  }

  const ASTPathExpression* name_ = nullptr;
  const ASTOptionsList* options_list_ = nullptr;
};

// This represents a ALTER SEQUENCE statement, i.e.,
// ALTER SEQUENCE <name_path> SET OPTIONS (name=value, ...);
class ASTAlterSequenceStatement final : public ASTAlterStatementBase {
 public:
  static constexpr ASTNodeKind kConcreteNodeKind = AST_ALTER_SEQUENCE_STATEMENT;

  ASTAlterSequenceStatement() : ASTAlterStatementBase(kConcreteNodeKind) {}
  void Accept(ParseTreeVisitor* visitor, void* data) const override;
  absl::Status Accept(ParseTreeStatusVisitor& visitor, std::any& output) const override;
  absl::StatusOr<VisitResult> Accept(
      NonRecursiveParseTreeVisitor* visitor) const override;

  friend class ParseTreeSerializer;

 private:
  absl::Status InitFields() final {
    FieldLoader fl(this);
    fl.AddOptional(&path_, AST_PATH_EXPRESSION);
    GOOGLESQL_RETURN_IF_ERROR(fl.AddRequired(&action_list_));
    return fl.Finalize();
  }
};

}  // namespace googlesql
// NOLINTEND(whitespace/line_length)
#endif  // GOOGLESQL_PARSER_PARSE_TREE_GENERATED_H_

