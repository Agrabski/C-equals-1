
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "CMinusEqualsMinus1Revision0Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by CMinusEqualsMinus1Revision0Parser.
 */
class  CMinusEqualsMinus1Revision0Listener : public antlr4::tree::ParseTreeListener {
public:

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::CompilationUnitContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::CompilationUnitContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::LanguageStandardDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::DeclarationSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::DeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::DeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AttributeContentSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AttributeContentSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ClassDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::InterfaceDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::InterfaceDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::InterfaceContentSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::InterfaceContentSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::StructDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::StructDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::StructContentSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::StructContentSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ImplementedInterfacesSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ParameterListContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ParameterListContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FunctionBodyContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FunctionBodyContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::StatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::StatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::IfStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::IfStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::LoopStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::LoopStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::RangeForStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::RangeForStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ForStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ForStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::WhileStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::WhileStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::DoWhileStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::WhileHeaderContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::WhileHeaderContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::InfiniteLoopStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AttributeSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::QualifiedIdentifierContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::LogicalExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ComparisonExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext *>) = 0;


};

