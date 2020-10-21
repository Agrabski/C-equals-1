
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  CMinusEqualsMinus1Revision0Parser : public antlr4::Parser
{
public:
	enum
{
		T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
		T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
		T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
		T__20 = 21, T__21 = 22, Unique = 23, Shared = 24, AccessSpecifier = 25, 
		Identifier = 26, OpenBracket = 27, CloseBracket = 28, DOUBLEQUOTE = 29, 
		SINGLEQUOTE = 30, ParamOpen = 31, ParamClose = 32, ATTROBITEOPEN = 33, 
		ATTROBITECLOSE = 34, Array = 35, ArithmeticBinaryOperator = 36, ArithmeticUnaryOperator = 37, 
		ComparsionOperator = 38, LogicalBinaryOperator = 39, Unsafe = 40, LogicalUnaryOperator = 41, 
		Not = 42, DoubleColon = 43, SemiColon = 44, Comma = 45, Period = 46, Equals = 47, 
		Asssigment = 48, NotEquals = 49, Plus = 50, Minus = 51, Star = 52, PlusEquals = 53, 
		MinusEquals = 54, MultiplyEquals = 55, DivideEquals = 56, GreaterEqual = 57, 
		LessEqual = 58, Equal = 59, NotEqual = 60, Or = 61, And = 62, Xor = 63, 
		Strong = 64, Nullable = 65, Mutable = 66, Ref = 67, Class = 68, Interface = 69, 
		Public = 70, Private = 71, Internal = 72, Final = 73, Virtual = 74, Abstract = 75, 
		Override = 76, DefaultSpecification = 77, Attribute = 78, Throw = 79, 
		IntegerLiteral = 80, DIGIT = 81, STRING = 82, AnyCharacter = 83, LETTER = 84, 
		Whitespace = 85, Newline = 86, BlockComment = 87, LineComment = 88
	};

	enum
{
		RuleCompilationUnit = 0, RuleLanguageStandardDeclaration = 1, RuleDeclarationSequence = 2, 
		RuleDeclaration = 3, RuleAttributeDeclaration = 4, RuleAttributeTarget = 5, 
		RuleImportDeclaration = 6, RuleTypeDeclaration = 7, RuleClassTypeSpecifier = 8, 
		RuleClassContentSequence = 9, RuleFieldDeclaration = 10, RuleGenericSpecifier = 11, 
		RuleImplementedInterfacesSequence = 12, RuleNamespaceDeclaration = 13, 
		RuleFunctionDeclaration = 14, RuleParameterList = 15, RuleParameter = 16, 
		RuleTypeSpecifier = 17, RuleFunctionBody = 18, RuleCompoundStatement = 19, 
		RuleStatement = 20, RuleVariableDeclarationStatement = 21, RuleIfStatement = 22, 
		RuleLoopStatement = 23, RuleRangeForStatement = 24, RuleForStatement = 25, 
		RuleWhileStatement = 26, RuleDoWhileStatement = 27, RuleWhileHeader = 28, 
		RuleInfiniteLoopStatement = 29, RuleFunctionCall = 30, RuleFunctionCallParameter = 31, 
		RuleAttributeSequence = 32, RuleAttribute = 33, RuleQualifiedIdentifier = 34, 
		RuleExpression = 35, RuleArithmeticExpression = 36, RuleLogicalExpression = 37, 
		RuleComparisonExpression = 38, RuleAssigmentStatement = 39, RuleLExpression = 40, 
		RuleThrowExpression = 41
	};

	CMinusEqualsMinus1Revision0Parser(antlr4::TokenStream *input);

	std::string getGrammarFileName() const final;
	const antlr4::atn::ATN& getATN() const noexcept final
{ return _atn; };
	const std::vector<std::string_view>& getTokenNames() const final
{ return _tokenNames; }; // deprecated: use vocabulary instead.
	const std::vector<std::string_view>& getRuleNames() const final;
	antlr4::dfa::Vocabulary& getVocabulary() const final;


	class CompilationUnitContext;
	class LanguageStandardDeclarationContext;
	class DeclarationSequenceContext;
	class DeclarationContext;
	class AttributeDeclarationContext;
	class AttributeTargetContext;
	class ImportDeclarationContext;
	class TypeDeclarationContext;
	class ClassTypeSpecifierContext;
	class ClassContentSequenceContext;
	class FieldDeclarationContext;
	class GenericSpecifierContext;
	class ImplementedInterfacesSequenceContext;
	class NamespaceDeclarationContext;
	class FunctionDeclarationContext;
	class ParameterListContext;
	class ParameterContext;
	class TypeSpecifierContext;
	class FunctionBodyContext;
	class CompoundStatementContext;
	class StatementContext;
	class VariableDeclarationStatementContext;
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
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		CompilationUnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		CompilationUnitContext() = default;
		void copyFrom(CompilationUnitContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		LanguageStandardDeclarationContext *languageStandardDeclaration();
		DeclarationSequenceContext *declarationSequence();
		antlr4::tree::TerminalNode *EOF();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	CompilationUnitContext* compilationUnit(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<CompilationUnitContext> parsecompilationUnit();

	class  LanguageStandardDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		LanguageStandardDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		LanguageStandardDeclarationContext() = default;
		void copyFrom(LanguageStandardDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Asssigment();
		antlr4::tree::TerminalNode *IntegerLiteral();
		antlr4::tree::TerminalNode *SemiColon();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	LanguageStandardDeclarationContext* languageStandardDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<LanguageStandardDeclarationContext> parselanguageStandardDeclaration();

	class  DeclarationSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		DeclarationSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		DeclarationSequenceContext() = default;
		void copyFrom(DeclarationSequenceContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<DeclarationContext *> declaration();
		DeclarationContext* declaration(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	DeclarationSequenceContext* declarationSequence(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<DeclarationSequenceContext> parsedeclarationSequence();

	class  DeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		DeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		DeclarationContext() = default;
		void copyFrom(DeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		FunctionDeclarationContext *functionDeclaration();
		TypeDeclarationContext *typeDeclaration();
		NamespaceDeclarationContext *namespaceDeclaration();
		ImportDeclarationContext *importDeclaration();
		AttributeDeclarationContext *attributeDeclaration();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	DeclarationContext* declaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<DeclarationContext> parsedeclaration();

	class  AttributeDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AttributeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AttributeDeclarationContext() = default;
		void copyFrom(AttributeDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *OpenBracket();
		ClassContentSequenceContext *classContentSequence();
		antlr4::tree::TerminalNode *CloseBracket();
		antlr4::tree::TerminalNode *AccessSpecifier();
		std::vector<AttributeTargetContext *> attributeTarget();
		AttributeTargetContext* attributeTarget(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AttributeDeclarationContext* attributeDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AttributeDeclarationContext> parseattributeDeclaration();

	class  AttributeTargetContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AttributeTargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AttributeTargetContext() = default;
		void copyFrom(AttributeTargetContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AttributeTargetContext* attributeTarget(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AttributeTargetContext> parseattributeTarget();

	class  ImportDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ImportDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ImportDeclarationContext() = default;
		void copyFrom(ImportDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> OpenBracket();
		antlr4::tree::TerminalNode* OpenBracket(size_t i);
		std::vector<antlr4::tree::TerminalNode *> CloseBracket();
		antlr4::tree::TerminalNode* CloseBracket(size_t i);
		QualifiedIdentifierContext *qualifiedIdentifier();
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ImportDeclarationContext* importDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ImportDeclarationContext> parseimportDeclaration();

	class  TypeDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		TypeDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		TypeDeclarationContext() = default;
		void copyFrom(TypeDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		ClassTypeSpecifierContext *classTypeSpecifier();
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *OpenBracket();
		ClassContentSequenceContext *classContentSequence();
		antlr4::tree::TerminalNode *CloseBracket();
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *AccessSpecifier();
		ImplementedInterfacesSequenceContext *implementedInterfacesSequence();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	TypeDeclarationContext* typeDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<TypeDeclarationContext> parsetypeDeclaration();

	class  ClassTypeSpecifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ClassTypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ClassTypeSpecifierContext() = default;
		void copyFrom(ClassTypeSpecifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Class();
		antlr4::tree::TerminalNode *Interface();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ClassTypeSpecifierContext* classTypeSpecifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ClassTypeSpecifierContext> parseclassTypeSpecifier();

	class  ClassContentSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ClassContentSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ClassContentSequenceContext() = default;
		void copyFrom(ClassContentSequenceContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<FunctionDeclarationContext *> functionDeclaration();
		FunctionDeclarationContext* functionDeclaration(size_t i);
		std::vector<FieldDeclarationContext *> fieldDeclaration();
		FieldDeclarationContext* fieldDeclaration(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ClassContentSequenceContext* classContentSequence(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ClassContentSequenceContext> parseclassContentSequence();

	class  FieldDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FieldDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FieldDeclarationContext() = default;
		void copyFrom(FieldDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Identifier();
		TypeSpecifierContext *typeSpecifier();
		antlr4::tree::TerminalNode *SemiColon();
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *AccessSpecifier();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FieldDeclarationContext* fieldDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FieldDeclarationContext> parsefieldDeclaration();

	class  GenericSpecifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		GenericSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		GenericSpecifierContext() = default;
		void copyFrom(GenericSpecifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode *> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	GenericSpecifierContext* genericSpecifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<GenericSpecifierContext> parsegenericSpecifier();

	class  ImplementedInterfacesSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ImplementedInterfacesSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ImplementedInterfacesSequenceContext() = default;
		void copyFrom(ImplementedInterfacesSequenceContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode *> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ImplementedInterfacesSequenceContext* implementedInterfacesSequence(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ImplementedInterfacesSequenceContext> parseimplementedInterfacesSequence();

	class  NamespaceDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		NamespaceDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		NamespaceDeclarationContext() = default;
		void copyFrom(NamespaceDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		QualifiedIdentifierContext *qualifiedIdentifier();
		antlr4::tree::TerminalNode *OpenBracket();
		DeclarationSequenceContext *declarationSequence();
		antlr4::tree::TerminalNode *CloseBracket();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	NamespaceDeclarationContext* namespaceDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<NamespaceDeclarationContext> parsenamespaceDeclaration();

	class  FunctionDeclarationContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionDeclarationContext() = default;
		void copyFrom(FunctionDeclarationContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		antlr4::tree::TerminalNode *ParamOpen();
		ParameterListContext *parameterList();
		antlr4::tree::TerminalNode *ParamClose();
		FunctionBodyContext *functionBody();
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *AccessSpecifier();
		GenericSpecifierContext *genericSpecifier();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionDeclarationContext* functionDeclaration(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionDeclarationContext> parsefunctionDeclaration();

	class  ParameterListContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ParameterListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ParameterListContext() = default;
		void copyFrom(ParameterListContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<ParameterContext *> parameter();
		ParameterContext* parameter(size_t i);
		std::vector<antlr4::tree::TerminalNode *> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ParameterListContext* parameterList(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ParameterListContext> parseparameterList();

	class  ParameterContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ParameterContext() = default;
		void copyFrom(ParameterContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Identifier();
		TypeSpecifierContext *typeSpecifier();
		AttributeSequenceContext *attributeSequence();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ParameterContext* parameter(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ParameterContext> parseparameter();

	class  TypeSpecifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		TypeSpecifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		TypeSpecifierContext() = default;
		void copyFrom(TypeSpecifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *Ref();
		antlr4::tree::TerminalNode *Array();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	TypeSpecifierContext* typeSpecifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<TypeSpecifierContext> parsetypeSpecifier();

	class  FunctionBodyContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionBodyContext() = default;
		void copyFrom(FunctionBodyContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *OpenBracket();
		antlr4::tree::TerminalNode *CloseBracket();
		std::vector<StatementContext *> statement();
		StatementContext* statement(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionBodyContext* functionBody(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionBodyContext> parsefunctionBody();

	class  CompoundStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		CompoundStatementContext() = default;
		void copyFrom(CompoundStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *OpenBracket();
		antlr4::tree::TerminalNode *CloseBracket();
		antlr4::tree::TerminalNode *Unsafe();
		std::vector<StatementContext *> statement();
		StatementContext* statement(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	CompoundStatementContext* compoundStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<CompoundStatementContext> parsecompoundStatement();

	class  StatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		StatementContext() = default;
		void copyFrom(StatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *SemiColon();
		IfStatementContext *ifStatement();
		LoopStatementContext *loopStatement();
		AssigmentStatementContext *assigmentStatement();
		VariableDeclarationStatementContext *variableDeclarationStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	StatementContext* statement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<StatementContext> parsestatement();

	class  VariableDeclarationStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		VariableDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		VariableDeclarationStatementContext() = default;
		void copyFrom(VariableDeclarationStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *Asssigment();
		FunctionCallParameterContext *functionCallParameter();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	VariableDeclarationStatementContext* variableDeclarationStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<VariableDeclarationStatementContext> parsevariableDeclarationStatement();

	class  IfStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		IfStatementContext() = default;
		void copyFrom(IfStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ParamOpen();
		LogicalExpressionContext *logicalExpression();
		antlr4::tree::TerminalNode *ParamClose();
		std::vector<CompoundStatementContext *> compoundStatement();
		CompoundStatementContext* compoundStatement(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	IfStatementContext* ifStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<IfStatementContext> parseifStatement();

	class  LoopStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		LoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		LoopStatementContext() = default;
		void copyFrom(LoopStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		RangeForStatementContext *rangeForStatement();
		ForStatementContext *forStatement();
		WhileStatementContext *whileStatement();
		DoWhileStatementContext *doWhileStatement();
		InfiniteLoopStatementContext *infiniteLoopStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	LoopStatementContext* loopStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<LoopStatementContext> parseloopStatement();

	class  RangeForStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		RangeForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		RangeForStatementContext() = default;
		void copyFrom(RangeForStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ParamOpen();
		antlr4::tree::TerminalNode *Identifier();
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *ParamClose();
		CompoundStatementContext *compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	RangeForStatementContext* rangeForStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<RangeForStatementContext> parserangeForStatement();

	class  ForStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ForStatementContext() = default;
		void copyFrom(ForStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ParamOpen();
		std::vector<ExpressionContext *> expression();
		ExpressionContext* expression(size_t i);
		std::vector<antlr4::tree::TerminalNode *> SemiColon();
		antlr4::tree::TerminalNode* SemiColon(size_t i);
		LogicalExpressionContext *logicalExpression();
		antlr4::tree::TerminalNode *ParamClose();
		CompoundStatementContext *compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ForStatementContext* forStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ForStatementContext> parseforStatement();

	class  WhileStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		WhileStatementContext() = default;
		void copyFrom(WhileStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		WhileHeaderContext *whileHeader();
		CompoundStatementContext *compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	WhileStatementContext* whileStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<WhileStatementContext> parsewhileStatement();

	class  DoWhileStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		DoWhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		DoWhileStatementContext() = default;
		void copyFrom(DoWhileStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		CompoundStatementContext *compoundStatement();
		WhileHeaderContext *whileHeader();
		antlr4::tree::TerminalNode *SemiColon();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	DoWhileStatementContext* doWhileStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<DoWhileStatementContext> parsedoWhileStatement();

	class  WhileHeaderContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		WhileHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		WhileHeaderContext() = default;
		void copyFrom(WhileHeaderContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ParamOpen();
		LogicalExpressionContext *logicalExpression();
		antlr4::tree::TerminalNode *ParamClose();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	WhileHeaderContext* whileHeader(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<WhileHeaderContext> parsewhileHeader();

	class  InfiniteLoopStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		InfiniteLoopStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		InfiniteLoopStatementContext() = default;
		void copyFrom(InfiniteLoopStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		CompoundStatementContext *compoundStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	InfiniteLoopStatementContext* infiniteLoopStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<InfiniteLoopStatementContext> parseinfiniteLoopStatement();

	class  FunctionCallContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionCallContext() = default;
		void copyFrom(FunctionCallContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *ParamOpen();
		antlr4::tree::TerminalNode *ParamClose();
		GenericSpecifierContext *genericSpecifier();
		std::vector<FunctionCallParameterContext *> functionCallParameter();
		FunctionCallParameterContext* functionCallParameter(size_t i);
		std::vector<antlr4::tree::TerminalNode *> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionCallContext* functionCall(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionCallContext> parsefunctionCall();

	class  FunctionCallParameterContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionCallParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionCallParameterContext() = default;
		void copyFrom(FunctionCallParameterContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		ExpressionContext *expression();
		ArithmeticExpressionContext *arithmeticExpression();
		LogicalExpressionContext *logicalExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionCallParameterContext* functionCallParameter(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionCallParameterContext> parsefunctionCallParameter();

	class  AttributeSequenceContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AttributeSequenceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AttributeSequenceContext() = default;
		void copyFrom(AttributeSequenceContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<AttributeContext *> attribute();
		AttributeContext* attribute(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AttributeSequenceContext* attributeSequence(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AttributeSequenceContext> parseattributeSequence();

	class  AttributeContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AttributeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AttributeContext() = default;
		void copyFrom(AttributeContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ATTROBITEOPEN();
		FunctionCallContext *functionCall();
		antlr4::tree::TerminalNode *ATTROBITECLOSE();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AttributeContext* attribute(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AttributeContext> parseattribute();

	class  QualifiedIdentifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		QualifiedIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		QualifiedIdentifierContext() = default;
		void copyFrom(QualifiedIdentifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode *> DoubleColon();
		antlr4::tree::TerminalNode* DoubleColon(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	QualifiedIdentifierContext* qualifiedIdentifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<QualifiedIdentifierContext> parsequalifiedIdentifier();

	class  ExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ExpressionContext() = default;
		void copyFrom(ExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *STRING();
		FunctionCallContext *functionCall();
		ThrowExpressionContext *throwExpression();
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *ParamOpen();
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *ParamClose();
		LExpressionContext *lExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ExpressionContext* expression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ExpressionContext> parseexpression();

	class  ArithmeticExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ArithmeticExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ArithmeticExpressionContext() = default;
		void copyFrom(ArithmeticExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		FunctionCallContext *functionCall();
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *ArithmeticUnaryOperator();
		std::vector<ArithmeticExpressionContext *> arithmeticExpression();
		ArithmeticExpressionContext* arithmeticExpression(size_t i);
		antlr4::tree::TerminalNode *IntegerLiteral();
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *ArithmeticBinaryOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ArithmeticExpressionContext* arithmeticExpression();
	ArithmeticExpressionContext* arithmeticExpression(int precedence, antlr4::ParserRuleContext *parent);
	std::unique_ptr<ArithmeticExpressionContext> parsearithmeticExpression();
	class  LogicalExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		LogicalExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		LogicalExpressionContext() = default;
		void copyFrom(LogicalExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		FunctionCallContext *functionCall();
		antlr4::tree::TerminalNode *Identifier();
		antlr4::tree::TerminalNode *LogicalUnaryOperator();
		std::vector<LogicalExpressionContext *> logicalExpression();
		LogicalExpressionContext* logicalExpression(size_t i);
		ComparisonExpressionContext *comparisonExpression();
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *LogicalBinaryOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	LogicalExpressionContext* logicalExpression();
	LogicalExpressionContext* logicalExpression(int precedence, antlr4::ParserRuleContext *parent);
	std::unique_ptr<LogicalExpressionContext> parselogicalExpression();
	class  ComparisonExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ComparisonExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ComparisonExpressionContext() = default;
		void copyFrom(ComparisonExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<ArithmeticExpressionContext *> arithmeticExpression();
		ArithmeticExpressionContext* arithmeticExpression(size_t i);
		antlr4::tree::TerminalNode *ComparsionOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ComparisonExpressionContext* comparisonExpression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ComparisonExpressionContext> parsecomparisonExpression();

	class  AssigmentStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AssigmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AssigmentStatementContext() = default;
		void copyFrom(AssigmentStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		LExpressionContext *lExpression();
		antlr4::tree::TerminalNode *Asssigment();
		ExpressionContext *expression();
		ArithmeticExpressionContext *arithmeticExpression();
		LogicalExpressionContext *logicalExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AssigmentStatementContext* assigmentStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AssigmentStatementContext> parseassigmentStatement();

	class  LExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		LExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		LExpressionContext() = default;
		void copyFrom(LExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<antlr4::tree::TerminalNode *> Identifier();
		antlr4::tree::TerminalNode* Identifier(size_t i);
		std::vector<antlr4::tree::TerminalNode *> Period();
		antlr4::tree::TerminalNode* Period(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	LExpressionContext* lExpression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<LExpressionContext> parselExpression();

	class  ThrowExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ThrowExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ThrowExpressionContext() = default;
		void copyFrom(ThrowExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Throw();
		ExpressionContext *expression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ThrowExpressionContext* throwExpression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ThrowExpressionContext> parsethrowExpression();


	bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) final;
	bool arithmeticExpressionSempred(ArithmeticExpressionContext *_localctx, size_t predicateIndex);
	bool logicalExpressionSempred(LogicalExpressionContext *_localctx, size_t predicateIndex);

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

