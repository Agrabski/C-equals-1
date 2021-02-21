
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

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AttributeTargetContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AttributeTargetContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ClassTypeSpecifierContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ClassContentSequenceContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext *>) = 0;

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

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::GenericUsageContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::GenericUsageContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::FunctionBodyContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::FunctionBodyContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::CompoundStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::StatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::StatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ReturnStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ReturnStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::VariableDeclarationStatementContext *>) = 0;

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

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::AssigmentStatementContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticBinaryOperatorContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::ComparsionOperatorContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::BinaryOperatorContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::LogicalBinaryOperatorContext *>) = 0;

	virtual void enter(not_null<CMinusEqualsMinus1Revision0Parser::RefContext *>) = 0;
	virtual void exit(not_null<CMinusEqualsMinus1Revision0Parser::RefContext *>) = 0;


};

