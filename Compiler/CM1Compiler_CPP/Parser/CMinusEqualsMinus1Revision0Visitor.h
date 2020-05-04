
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CMinusEqualsMinus1Revision0Parser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by CMinusEqualsMinus1Revision0Parser.
 */
class  CMinusEqualsMinus1Revision0Visitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

	/**
	 * Visit parse trees produced by CMinusEqualsMinus1Revision0Parser.
	 */
		virtual antlrcpp::Any visitCompilationUnit(CMinusEqualsMinus1Revision0Parser::CompilationUnitContext *context) = 0;

		virtual antlrcpp::Any visitLanguageStandardDeclaration(CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext *context) = 0;

		virtual antlrcpp::Any visitDeclarationSequence(CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext *context) = 0;

		virtual antlrcpp::Any visitDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext *context) = 0;

		virtual antlrcpp::Any visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext *context) = 0;

		virtual antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext *context) = 0;

		virtual antlrcpp::Any visitParameterList(CMinusEqualsMinus1Revision0Parser::ParameterListContext *context) = 0;

		virtual antlrcpp::Any visitFunctionBody(CMinusEqualsMinus1Revision0Parser::FunctionBodyContext *context) = 0;

		virtual antlrcpp::Any visitCompoundStatement(CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *context) = 0;

		virtual antlrcpp::Any visitStatement(CMinusEqualsMinus1Revision0Parser::StatementContext *context) = 0;

		virtual antlrcpp::Any visitIfStatement(CMinusEqualsMinus1Revision0Parser::IfStatementContext *context) = 0;

		virtual antlrcpp::Any visitLoopStatement(CMinusEqualsMinus1Revision0Parser::LoopStatementContext *context) = 0;

		virtual antlrcpp::Any visitRangeForStatement(CMinusEqualsMinus1Revision0Parser::RangeForStatementContext *context) = 0;

		virtual antlrcpp::Any visitForStatement(CMinusEqualsMinus1Revision0Parser::ForStatementContext *context) = 0;

		virtual antlrcpp::Any visitWhileStatement(CMinusEqualsMinus1Revision0Parser::WhileStatementContext *context) = 0;

		virtual antlrcpp::Any visitDoWhileStatement(CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext *context) = 0;

		virtual antlrcpp::Any visitWhileHeader(CMinusEqualsMinus1Revision0Parser::WhileHeaderContext *context) = 0;

		virtual antlrcpp::Any visitInfiniteLoopStatement(CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext *context) = 0;

		virtual antlrcpp::Any visitFunctionCall(CMinusEqualsMinus1Revision0Parser::FunctionCallContext *context) = 0;

		virtual antlrcpp::Any visitFunctionCallParameter(CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext *context) = 0;

		virtual antlrcpp::Any visitAttributeSequence(CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext *context) = 0;

		virtual antlrcpp::Any visitAttribute(CMinusEqualsMinus1Revision0Parser::AttributeContext *context) = 0;

		virtual antlrcpp::Any visitQualifiedIdentifier(CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext *context) = 0;

		virtual antlrcpp::Any visitExpression(CMinusEqualsMinus1Revision0Parser::ExpressionContext *context) = 0;

		virtual antlrcpp::Any visitArithmeticExpression(CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext *context) = 0;

		virtual antlrcpp::Any visitLogicalExpression(CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext *context) = 0;

		virtual antlrcpp::Any visitComparisonExpression(CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext *context) = 0;

		virtual antlrcpp::Any visitAssigmentStatement(CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext *context) = 0;

		virtual antlrcpp::Any visitLExpression(CMinusEqualsMinus1Revision0Parser::LExpressionContext *context) = 0;

		virtual antlrcpp::Any visitThrowExpression(CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext *context) = 0;


};

