
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include <memory>




class  CMinusEqualsMinus1Revision0Parser : public antlr4::Parser
{
public:
	enum
	{
		T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7,
		T__7 = 8, T__8 = 9, T__9 = 10, Identifier = 11, OpenBracket = 12, CloseBracket = 13,
		RAWSTRING = 14, DOUBLEQUOTE = 15, SINGLEQUOTE = 16, ParamOpen = 17, ParamClose = 18,
		ATTROBITEOPEN = 19, ATTROBITECLOSE = 20, ArithmeticBinaryOperator = 21,
		ArithmeticUnaryOperator = 22, ComparsionOperator = 23, LogicalBinaryOperator = 24,
		LogicalUnaryOperator = 25, Not = 26, DoubleColon = 27, SemiColon = 28,
		Comma = 29, Period = 30, Equals = 31, Asssigment = 32, NotEquals = 33,
		Plus = 34, Minus = 35, Star = 36, PlusEquals = 37, MinusEquals = 38, MultiplyEquals = 39,
		DivideEquals = 40, GreaterThan = 41, LessThan = 42, GreaterEqual = 43,
		LessEqual = 44, Equal = 45, NotEqual = 46, Or = 47, And = 48, Xor = 49,
		Strong = 50, Nullable = 51, Mutable = 52, Ref = 53, Class = 54, Interface = 55,
		Public = 56, Private = 57, Protected = 58, Internal = 59, Final = 60,
		Virtual = 61, Abstract = 62, Override = 63, DefaultSpecification = 64,
		Attribute = 65, Throw = 66, IntegerLiteral = 67, DIGIT = 68, LETTER = 69,
		Whitespace = 70, Newline = 71, BlockComment = 72, LineComment = 73
	};

	enum
	{
		RuleCompilationUnit = 0, RuleLanguageStandardDeclaration = 1, RuleDeclarationSequence = 2,
		RuleDeclaration = 3, RuleNamespaceDeclaration = 4, RuleFunctionDeclaration = 5,
		RuleParameterList = 6, RuleFunctionBody = 7, RuleCompoundStatement = 8,
		RuleStatement = 9, RuleIfStatement = 10, RuleLoopStatement = 11, RuleRangeForStatement = 12,
		RuleForStatement = 13, RuleWhileStatement = 14, RuleDoWhileStatement = 15,
		RuleWhileHeader = 16, RuleInfiniteLoopStatement = 17, RuleFunctionCall = 18,
		RuleFunctionCallParameter = 19, RuleAttributeSequence = 20, RuleAttribute = 21,
		RuleQualifiedIdentifier = 22, RuleExpression = 23, RuleArithmeticExpression = 24,
		RuleLogicalExpression = 25, RuleComparisonExpression = 26, RuleAssigmentStatement = 27,
		RuleLExpression = 28, RuleThrowExpression = 29
	};

	CMinusEqualsMinus1Revision0Parser(antlr4::TokenStream* input);


	std::string getGrammarFileName() const final;
	const antlr4::atn::ATN& getATN() const noexcept final
	{
		return _atn;
	};
	const std::vector<std::string_view>& getTokenNames() const final
	{
		return _tokenNames;
	}; // deprecated: use vocabulary instead.
	const std::vector<std::string_view>& getRuleNames() const final;
	antlr4::dfa::Vocabulary& getVocabulary() const final;


	class CompilationUnitContext;
	std::unique_ptr<CompilationUnitContext> parseCompilationUnit()
	{
		compilationUnit();
		return std::unique_ptr<CompilationUnitContext>(static_cast<CompilationUnitContext*>(_root.release()));
	}
	class LanguageStandardDeclarationContext;
	class DeclarationSequenceContext;
	class DeclarationContext;
	class NamespaceDeclarationContext;
	class FunctionDeclarationContext;
	class ParameterListContext;
	class FunctionBodyContext;
	class CompoundStatementContext;
	class StatementContext;
	class IfStatementContext;
	class LoopStatementContext;
	class RangeForStatementContext;
	class ForStatementContext;
	class WhileStatementContext;
	class DoWhileStatementContext;
	class WhileHeaderContext;
	class InfiniteLoopStatementContext;
	class FunctionCallContext;
	class FunctionCallParameterContext;
	class AttributeSequenceContext;
	class AttributeContext;
	class QualifiedIdentifierContext;
	class ExpressionContext;
	class ArithmeticExpressionContext;
	class LogicalExpressionContext;
	class ComparisonExpressionContext;
	class AssigmentStatementContext;
	class LExpressionContext;
	class ThrowExpressionContext;

	class  CompilationUnitContext : public antlr4::ParserRuleContext
	{
	public:
		CompilationUnitContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		LanguageStandardDeclarationContext* languageStandardDeclaration();
		DeclarationSequenceContext* declarationSequence();
		antlr4::tree::TerminalNode* EOF();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	CompilationUnitContext* compilationUnit(antlr4::ParserRuleContext* parent = nullptr);

	class  LanguageStandardDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		LanguageStandardDeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* Asssigment();
		antlr4::tree::TerminalNode* IntegerLiteral();
		antlr4::tree::TerminalNode* SemiColon();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	LanguageStandardDeclarationContext* languageStandardDeclaration(antlr4::ParserRuleContext* parent = nullptr);

	class  DeclarationSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		DeclarationSequenceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		std::vector<DeclarationContext*> declaration();
		DeclarationContext* declaration(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	DeclarationSequenceContext* declarationSequence(antlr4::ParserRuleContext* parent = nullptr);

	class  DeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		DeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		FunctionDeclarationContext* functionDeclaration();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	DeclarationContext* declaration(antlr4::ParserRuleContext* parent = nullptr);

	class  NamespaceDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		NamespaceDeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		QualifiedIdentifierContext* qualifiedIdentifier();
		antlr4::tree::TerminalNode* OpenBracket();
		DeclarationSequenceContext* declarationSequence();
		antlr4::tree::TerminalNode* CloseBracket();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	NamespaceDeclarationContext* namespaceDeclaration(antlr4::ParserRuleContext* parent = nullptr);

	class  FunctionDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		FunctionDeclarationContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* Identifier();
		antlr4::tree::TerminalNode* ParamOpen();
		ParameterListContext* parameterList();
		antlr4::tree::TerminalNode* ParamClose();
		QualifiedIdentifierContext* qualifiedIdentifier();
		FunctionBodyContext* functionBody();
		AttributeSequenceContext* attributeSequence();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	FunctionDeclarationContext* functionDeclaration(antlr4::ParserRuleContext* parent = nullptr);

	class  ParameterListContext : public antlr4::ParserRuleContext
	{
	public:
		ParameterListContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		std::vector<QualifiedIdentifierContext*> qualifiedIdentifier();
		QualifiedIdentifierContext* qualifiedIdentifier(size_t i);
		std::vector<antlr4::tree::TerminalNode*> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode*> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ParameterListContext* parameterList(antlr4::ParserRuleContext* parent = nullptr);

	class  FunctionBodyContext : public antlr4::ParserRuleContext
	{
	public:
		FunctionBodyContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* OpenBracket();
		antlr4::tree::TerminalNode* CloseBracket();
		std::vector<StatementContext*> statement();
		StatementContext* statement(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	FunctionBodyContext* functionBody(antlr4::ParserRuleContext* parent = nullptr);

	class  CompoundStatementContext : public antlr4::ParserRuleContext
	{
	public:
		CompoundStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* OpenBracket();
		antlr4::tree::TerminalNode* CloseBracket();
		std::vector<StatementContext*> statement();
		StatementContext* statement(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	CompoundStatementContext* compoundStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  StatementContext : public antlr4::ParserRuleContext
	{
	public:
		StatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		ExpressionContext* expression();
		antlr4::tree::TerminalNode* SemiColon();
		IfStatementContext* ifStatement();
		LoopStatementContext* loopStatement();
		AssigmentStatementContext* assigmentStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	StatementContext* statement(antlr4::ParserRuleContext* parent = nullptr);

	class  IfStatementContext : public antlr4::ParserRuleContext
	{
	public:
		IfStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* ParamOpen();
		LogicalExpressionContext* logicalExpression();
		antlr4::tree::TerminalNode* ParamClose();
		CompoundStatementContext* compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	IfStatementContext* ifStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  LoopStatementContext : public antlr4::ParserRuleContext
	{
	public:
		LoopStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		RangeForStatementContext* rangeForStatement();
		ForStatementContext* forStatement();
		WhileStatementContext* whileStatement();
		DoWhileStatementContext* doWhileStatement();
		InfiniteLoopStatementContext* infiniteLoopStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	LoopStatementContext* loopStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  RangeForStatementContext : public antlr4::ParserRuleContext
	{
	public:
		RangeForStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* ParamOpen();
		antlr4::tree::TerminalNode* Identifier();
		ExpressionContext* expression();
		antlr4::tree::TerminalNode* ParamClose();
		CompoundStatementContext* compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	RangeForStatementContext* rangeForStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  ForStatementContext : public antlr4::ParserRuleContext
	{
	public:
		ForStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* ParamOpen();
		std::vector<ExpressionContext*> expression();
		ExpressionContext* expression(size_t i);
		std::vector<antlr4::tree::TerminalNode*> SemiColon();
		antlr4::tree::TerminalNode* SemiColon(size_t i);
		LogicalExpressionContext* logicalExpression();
		antlr4::tree::TerminalNode* ParamClose();
		CompoundStatementContext* compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ForStatementContext* forStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  WhileStatementContext : public antlr4::ParserRuleContext
	{
	public:
		WhileStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		WhileHeaderContext* whileHeader();
		CompoundStatementContext* compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	WhileStatementContext* whileStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  DoWhileStatementContext : public antlr4::ParserRuleContext
	{
	public:
		DoWhileStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		CompoundStatementContext* compoundStatement();
		WhileHeaderContext* whileHeader();
		antlr4::tree::TerminalNode* SemiColon();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	DoWhileStatementContext* doWhileStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  WhileHeaderContext : public antlr4::ParserRuleContext
	{
	public:
		WhileHeaderContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* ParamOpen();
		LogicalExpressionContext* logicalExpression();
		antlr4::tree::TerminalNode* ParamClose();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	WhileHeaderContext* whileHeader(antlr4::ParserRuleContext* parent = nullptr);

	class  InfiniteLoopStatementContext : public antlr4::ParserRuleContext
	{
	public:
		InfiniteLoopStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		CompoundStatementContext* compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	InfiniteLoopStatementContext* infiniteLoopStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  FunctionCallContext : public antlr4::ParserRuleContext
	{
	public:
		FunctionCallContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		QualifiedIdentifierContext* qualifiedIdentifier();
		antlr4::tree::TerminalNode* ParamOpen();
		antlr4::tree::TerminalNode* ParamClose();
		std::vector<FunctionCallParameterContext*> functionCallParameter();
		FunctionCallParameterContext* functionCallParameter(size_t i);
		std::vector<antlr4::tree::TerminalNode*> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	FunctionCallContext* functionCall(antlr4::ParserRuleContext* parent = nullptr);

	class  FunctionCallParameterContext : public antlr4::ParserRuleContext
	{
	public:
		FunctionCallParameterContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		ExpressionContext* expression();
		ArithmeticExpressionContext* arithmeticExpression();
		LogicalExpressionContext* logicalExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	FunctionCallParameterContext* functionCallParameter(antlr4::ParserRuleContext* parent = nullptr);

	class  AttributeSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		AttributeSequenceContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		std::vector<AttributeContext*> attribute();
		AttributeContext* attribute(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	AttributeSequenceContext* attributeSequence(antlr4::ParserRuleContext* parent = nullptr);

	class  AttributeContext : public antlr4::ParserRuleContext
	{
	public:
		AttributeContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* ATTROBITEOPEN();
		FunctionCallContext* functionCall();
		antlr4::tree::TerminalNode* ATTROBITECLOSE();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	AttributeContext* attribute(antlr4::ParserRuleContext* parent = nullptr);

	class  QualifiedIdentifierContext : public antlr4::ParserRuleContext
	{
	public:
		QualifiedIdentifierContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode*> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode*> DoubleColon();
		antlr4::tree::TerminalNode* DoubleColon(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	QualifiedIdentifierContext* qualifiedIdentifier(antlr4::ParserRuleContext* parent = nullptr);

	class  ExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		ExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		FunctionCallContext* functionCall();
		ThrowExpressionContext* throwExpression();
		QualifiedIdentifierContext* qualifiedIdentifier();
		antlr4::tree::TerminalNode* ParamOpen();
		ExpressionContext* expression();
		antlr4::tree::TerminalNode* ParamClose();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ExpressionContext* expression(antlr4::ParserRuleContext* parent = nullptr);

	class  ArithmeticExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		ArithmeticExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		FunctionCallContext* functionCall();
		QualifiedIdentifierContext* qualifiedIdentifier();
		antlr4::tree::TerminalNode* ArithmeticUnaryOperator();
		std::vector<ArithmeticExpressionContext*> arithmeticExpression();
		ArithmeticExpressionContext* arithmeticExpression(size_t i);
		antlr4::tree::TerminalNode* IntegerLiteral();
		ExpressionContext* expression();
		antlr4::tree::TerminalNode* ArithmeticBinaryOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ArithmeticExpressionContext* arithmeticExpression();
	ArithmeticExpressionContext* arithmeticExpression(int precedence, antlr4::ParserRuleContext* parent);
	class  LogicalExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		LogicalExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		FunctionCallContext* functionCall();
		QualifiedIdentifierContext* qualifiedIdentifier();
		antlr4::tree::TerminalNode* LogicalUnaryOperator();
		std::vector<LogicalExpressionContext*> logicalExpression();
		LogicalExpressionContext* logicalExpression(size_t i);
		ComparisonExpressionContext* comparisonExpression();
		ExpressionContext* expression();
		antlr4::tree::TerminalNode* LogicalBinaryOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	LogicalExpressionContext* logicalExpression();
	LogicalExpressionContext* logicalExpression(int precedence, antlr4::ParserRuleContext* parent);
	class  ComparisonExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		ComparisonExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		std::vector<ArithmeticExpressionContext*> arithmeticExpression();
		ArithmeticExpressionContext* arithmeticExpression(size_t i);
		antlr4::tree::TerminalNode* ComparsionOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ComparisonExpressionContext* comparisonExpression(antlr4::ParserRuleContext* parent = nullptr);

	class  AssigmentStatementContext : public antlr4::ParserRuleContext
	{
	public:
		AssigmentStatementContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		LExpressionContext* lExpression();
		antlr4::tree::TerminalNode* Asssigment();
		ExpressionContext* expression();
		ArithmeticExpressionContext* arithmeticExpression();
		LogicalExpressionContext* logicalExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	AssigmentStatementContext* assigmentStatement(antlr4::ParserRuleContext* parent = nullptr);

	class  LExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		LExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		QualifiedIdentifierContext* qualifiedIdentifier();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	LExpressionContext* lExpression(antlr4::ParserRuleContext* parent = nullptr);

	class  ThrowExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		ThrowExpressionContext(antlr4::ParserRuleContext* parent, size_t invokingState);
		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode* Throw();
		ExpressionContext* expression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor* visitor) final;

	};

	ThrowExpressionContext* throwExpression(antlr4::ParserRuleContext* parent = nullptr);


	bool sempred(antlr4::RuleContext* _localctx, size_t ruleIndex, size_t predicateIndex) final;
	bool arithmeticExpressionSempred(ArithmeticExpressionContext* _localctx, size_t predicateIndex);
	bool logicalExpressionSempred(LogicalExpressionContext* _localctx, size_t predicateIndex);

private:
	static std::vector<antlr4::dfa::DFA> _decisionToDFA;
	static antlr4::atn::PredictionContextCache _sharedContextCache;
	static std::vector<std::string_view> _ruleNames;
	static std::vector<std::string_view> _tokenNames;

	static std::vector<std::string_view> _literalNames;
	static std::vector<std::string_view> _symbolicNames;
	static antlr4::dfa::Vocabulary _vocabulary;
	static antlr4::atn::ATN _atn;
	static std::vector<uint16_t> _serializedATN;


	struct Initializer
	{
		Initializer();
	};
	static Initializer _init;
};

