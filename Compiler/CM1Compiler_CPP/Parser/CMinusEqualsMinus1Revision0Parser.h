
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
		T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
		T__26 = 27, AccessSpecifier = 28, OpenBracket = 29, CloseBracket = 30, 
		DOUBLEQUOTE = 31, SINGLEQUOTE = 32, ParamOpen = 33, ParamClose = 34, ATTROBITEOPEN = 35, 
		ATTROBITECLOSE = 36, Array = 37, Unsafe = 38, LogicalUnaryOperator = 39, 
		Not = 40, DoubleColon = 41, SemiColon = 42, Comma = 43, Period = 44, Equals = 45, 
		Asssigment = 46, NotEquals = 47, Plus = 48, Minus = 49, Star = 50, PlusEquals = 51, 
		MinusEquals = 52, MultiplyEquals = 53, DivideEquals = 54, GreaterEqual = 55, 
		Greater = 56, Less = 57, LessEqual = 58, Equal = 59, NotEqual = 60, Or = 61, 
		And = 62, Xor = 63, Strong = 64, Nullable = 65, Mutable = 66, Class = 67, 
		Interface = 68, Public = 69, Private = 70, Internal = 71, Final = 72, 
		Virtual = 73, Abstract = 74, Override = 75, DefaultSpecification = 76, 
		Attribute = 77, Throw = 78, Operator = 79, Shared = 80, Unique = 81, New = 82, 
		SimpleIdentifier = 83, IntegerLiteral = 84, DIGIT = 85, STRING = 86, AnyCharacter = 87, 
		LETTER = 88, Whitespace = 89, Newline = 90, BlockComment = 91, LineComment = 92
	};

	enum
{
		RuleCompilationUnit = 0, RuleLanguageStandardDeclaration = 1, RuleDeclarationSequence = 2, 
		RuleDeclaration = 3, RuleAttributeDeclaration = 4, RuleAttributeTarget = 5, 
		RuleImportDeclaration = 6, RuleTypeDeclaration = 7, RuleClassTypeSpecifier = 8, 
		RuleClassContentSequence = 9, RuleFieldDeclaration = 10, RuleGenericSpecifier = 11, 
		RuleImplementedInterfacesSequence = 12, RuleNamespaceDeclaration = 13, 
		RuleFunctionDeclaration = 14, RuleParameterList = 15, RuleParameter = 16, 
		RuleTypeSpecifier = 17, RuleGenericUsage = 18, RuleFunctionBody = 19, 
		RuleFunctionName = 20, RuleSpecialFunctionIdentifier = 21, RuleCompoundStatement = 22, 
		RuleStatement = 23, RuleFunctionCallStatement = 24, RuleReturnStatement = 25, 
		RuleVariableDeclarationStatement = 26, RuleIfStatement = 27, RuleLoopStatement = 28, 
		RuleRangeForStatement = 29, RuleForStatement = 30, RuleWhileStatement = 31, 
		RuleDoWhileStatement = 32, RuleWhileHeader = 33, RuleInfiniteLoopStatement = 34, 
		RuleFunctionCall = 35, RuleFunctionCallParameter = 36, RuleAttributeSequence = 37, 
		RuleAttribute = 38, RuleQualifiedIdentifier = 39, RuleExpression = 40, 
		RuleIndexExpression = 41, RuleNewExpression = 42, RuleAssigmentStatement = 43, 
		RuleThrowExpression = 44, RuleArithmeticBinaryOperator = 45, RuleComparsionOperator = 46, 
		RuleBinaryOperator = 47, RuleLogicalBinaryOperator = 48, RuleRef = 49, 
		RuleIdentifier = 50
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
	class GenericUsageContext;
	class FunctionBodyContext;
	class FunctionNameContext;
	class SpecialFunctionIdentifierContext;
	class CompoundStatementContext;
	class StatementContext;
	class FunctionCallStatementContext;
	class ReturnStatementContext;
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
	class IndexExpressionContext;
	class NewExpressionContext;
	class AssigmentStatementContext;
	class ThrowExpressionContext;
	class ArithmeticBinaryOperatorContext;
	class ComparsionOperatorContext;
	class BinaryOperatorContext;
	class LogicalBinaryOperatorContext;
	class RefContext;
	class IdentifierContext; 

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
		antlr4::tree::TerminalNode *Less();
		antlr4::tree::TerminalNode *Greater();
		IdentifierContext *identifier();
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
		std::vector<IdentifierContext *> identifier();
		IdentifierContext* identifier(size_t i);

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
		IdentifierContext *identifier();
		antlr4::tree::TerminalNode *OpenBracket();
		ClassContentSequenceContext *classContentSequence();
		antlr4::tree::TerminalNode *CloseBracket();
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *AccessSpecifier();
		GenericSpecifierContext *genericSpecifier();
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
		IdentifierContext *identifier();
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
		antlr4::tree::TerminalNode *Less();
		std::vector<IdentifierContext *> identifier();
		IdentifierContext* identifier(size_t i);
		antlr4::tree::TerminalNode *Greater();
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
		std::vector<IdentifierContext *> identifier();
		IdentifierContext* identifier(size_t i);
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
		FunctionNameContext *functionName();
		antlr4::tree::TerminalNode *ParamOpen();
		ParameterListContext *parameterList();
		antlr4::tree::TerminalNode *ParamClose();
		FunctionBodyContext *functionBody();
		AttributeSequenceContext *attributeSequence();
		antlr4::tree::TerminalNode *AccessSpecifier();
		GenericSpecifierContext *genericSpecifier();
		TypeSpecifierContext *typeSpecifier();

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
		IdentifierContext *identifier();
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
		IdentifierContext *identifier();
		GenericUsageContext *genericUsage();
		std::vector<RefContext *> ref();
		RefContext* ref(size_t i);
		antlr4::tree::TerminalNode *Array();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	TypeSpecifierContext* typeSpecifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<TypeSpecifierContext> parsetypeSpecifier();

	class  GenericUsageContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		GenericUsageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		GenericUsageContext() = default;
		void copyFrom(GenericUsageContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Less();
		std::vector<TypeSpecifierContext *> typeSpecifier();
		TypeSpecifierContext* typeSpecifier(size_t i);
		antlr4::tree::TerminalNode *Greater();
		std::vector<antlr4::tree::TerminalNode *> Comma();
		antlr4::tree::TerminalNode* Comma(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	GenericUsageContext* genericUsage(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<GenericUsageContext> parsegenericUsage();

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

	class  FunctionNameContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionNameContext() = default;
		void copyFrom(FunctionNameContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		IdentifierContext *identifier();
		SpecialFunctionIdentifierContext *specialFunctionIdentifier();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionNameContext* functionName(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionNameContext> parsefunctionName();

	class  SpecialFunctionIdentifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		SpecialFunctionIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		SpecialFunctionIdentifierContext() = default;
		void copyFrom(SpecialFunctionIdentifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Operator();
		antlr4::tree::TerminalNode *New();
		BinaryOperatorContext *binaryOperator();
		antlr4::tree::TerminalNode *Unique();
		antlr4::tree::TerminalNode *Shared();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	SpecialFunctionIdentifierContext* specialFunctionIdentifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<SpecialFunctionIdentifierContext> parsespecialFunctionIdentifier();

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
		IfStatementContext *ifStatement();
		LoopStatementContext *loopStatement();
		AssigmentStatementContext *assigmentStatement();
		antlr4::tree::TerminalNode *SemiColon();
		VariableDeclarationStatementContext *variableDeclarationStatement();
		ReturnStatementContext *returnStatement();
		FunctionCallStatementContext *functionCallStatement();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	StatementContext* statement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<StatementContext> parsestatement();

	class  FunctionCallStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		FunctionCallStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		FunctionCallStatementContext() = default;
		void copyFrom(FunctionCallStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		FunctionCallContext *functionCall();
		ExpressionContext *expression();
		antlr4::tree::TerminalNode *Period();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	FunctionCallStatementContext* functionCallStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<FunctionCallStatementContext> parsefunctionCallStatement();

	class  ReturnStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ReturnStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ReturnStatementContext() = default;
		void copyFrom(ReturnStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		ExpressionContext *expression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ReturnStatementContext* returnStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ReturnStatementContext> parsereturnStatement();

	class  VariableDeclarationStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		VariableDeclarationStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		VariableDeclarationStatementContext() = default;
		void copyFrom(VariableDeclarationStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		IdentifierContext *identifier();
		AttributeSequenceContext *attributeSequence();
		TypeSpecifierContext *typeSpecifier();
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
		ExpressionContext *expression();
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
		IdentifierContext *identifier();
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
		ExpressionContext *expression();
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
		IdentifierContext *identifier();
		antlr4::tree::TerminalNode *ParamOpen();
		antlr4::tree::TerminalNode *ParamClose();
		GenericUsageContext *genericUsage();
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
		std::vector<IdentifierContext *> identifier();
		IdentifierContext* identifier(size_t i);
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
		antlr4::tree::TerminalNode *ParamOpen();
		std::vector<ExpressionContext *> expression();
		ExpressionContext* expression(size_t i);
		antlr4::tree::TerminalNode *ParamClose();
		FunctionCallContext *functionCall();
		ThrowExpressionContext *throwExpression();
		IdentifierContext *identifier();
		antlr4::tree::TerminalNode *IntegerLiteral();
		NewExpressionContext *newExpression();
		antlr4::tree::TerminalNode *LogicalUnaryOperator();
		BinaryOperatorContext *binaryOperator();
		antlr4::tree::TerminalNode *Period();
		IndexExpressionContext *indexExpression();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ExpressionContext* expression();
	ExpressionContext* expression(int precedence, antlr4::ParserRuleContext *parent);
	std::unique_ptr<ExpressionContext> parseexpression();
	class  IndexExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		IndexExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		IndexExpressionContext() = default;
		void copyFrom(IndexExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *ATTROBITEOPEN();
		antlr4::tree::TerminalNode *ATTROBITECLOSE();
		std::vector<ExpressionContext *> expression();
		ExpressionContext* expression(size_t i);

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	IndexExpressionContext* indexExpression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<IndexExpressionContext> parseindexExpression();

	class  NewExpressionContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		NewExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		NewExpressionContext() = default;
		void copyFrom(NewExpressionContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *New();
		FunctionCallContext *functionCall();
		antlr4::tree::TerminalNode *Unique();
		antlr4::tree::TerminalNode *Shared();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	NewExpressionContext* newExpression(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<NewExpressionContext> parsenewExpression();

	class  AssigmentStatementContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		AssigmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		AssigmentStatementContext() = default;
		void copyFrom(AssigmentStatementContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		std::vector<ExpressionContext *> expression();
		ExpressionContext* expression(size_t i);
		antlr4::tree::TerminalNode *Asssigment();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	AssigmentStatementContext* assigmentStatement(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<AssigmentStatementContext> parseassigmentStatement();

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

	class  ArithmeticBinaryOperatorContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ArithmeticBinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ArithmeticBinaryOperatorContext() = default;
		void copyFrom(ArithmeticBinaryOperatorContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Plus();
		antlr4::tree::TerminalNode *Minus();
		antlr4::tree::TerminalNode *Star();
		antlr4::tree::TerminalNode *PlusEquals();
		antlr4::tree::TerminalNode *MinusEquals();
		antlr4::tree::TerminalNode *MultiplyEquals();
		antlr4::tree::TerminalNode *DivideEquals();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ArithmeticBinaryOperatorContext* arithmeticBinaryOperator(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ArithmeticBinaryOperatorContext> parsearithmeticBinaryOperator();

	class  ComparsionOperatorContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		ComparsionOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		ComparsionOperatorContext() = default;
		void copyFrom(ComparsionOperatorContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Greater();
		antlr4::tree::TerminalNode *Less();
		antlr4::tree::TerminalNode *GreaterEqual();
		antlr4::tree::TerminalNode *LessEqual();
		antlr4::tree::TerminalNode *Equal();
		antlr4::tree::TerminalNode *NotEqual();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	ComparsionOperatorContext* comparsionOperator(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<ComparsionOperatorContext> parsecomparsionOperator();

	class  BinaryOperatorContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		BinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		BinaryOperatorContext() = default;
		void copyFrom(BinaryOperatorContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		LogicalBinaryOperatorContext *logicalBinaryOperator();
		ComparsionOperatorContext *comparsionOperator();
		ArithmeticBinaryOperatorContext *arithmeticBinaryOperator();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	BinaryOperatorContext* binaryOperator(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<BinaryOperatorContext> parsebinaryOperator();

	class  LogicalBinaryOperatorContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		LogicalBinaryOperatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		LogicalBinaryOperatorContext() = default;
		void copyFrom(LogicalBinaryOperatorContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Or();
		antlr4::tree::TerminalNode *And();
		antlr4::tree::TerminalNode *Xor();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	LogicalBinaryOperatorContext* logicalBinaryOperator(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<LogicalBinaryOperatorContext> parselogicalBinaryOperator();

	class  RefContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		RefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		RefContext() = default;
		void copyFrom(RefContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *Star();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	RefContext* ref(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<RefContext> parseref();

	class  IdentifierContext : public antlr4::ParserRuleContext
	{
	public:
		std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;
		IdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
		IdentifierContext() = default;
		void copyFrom(IdentifierContext *context);
		using antlr4::ParserRuleContext::copyFrom;

		size_t getRuleIndex() const final;
		antlr4::tree::TerminalNode *SimpleIdentifier();

		void enterRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;
		void exitRule(not_null<antlr4::tree::ParseTreeListener*> listener) final;

		antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) final;
	 
	};

	IdentifierContext* identifier(antlr4::ParserRuleContext *parent = nullptr);
	std::unique_ptr<IdentifierContext> parseidentifier();


	bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) final;
	bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

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

