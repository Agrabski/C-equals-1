
// Generated from CMinusEqualsMinus1Revision0.g4 by ANTLR 4.7.2

#pragma once
#include <iostream>


#include "antlr4-runtime.h"




class  CMinusEqualsMinus1Revision0Lexer : public antlr4::Lexer
{
public:
	enum
{
		T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
		T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
		T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
		T__20 = 21, AccessSpecifier = 22, Identifier = 23, OpenBracket = 24, CloseBracket = 25, 
		RAWSTRING = 26, DOUBLEQUOTE = 27, SINGLEQUOTE = 28, ParamOpen = 29, ParamClose = 30, 
		ATTROBITEOPEN = 31, ATTROBITECLOSE = 32, ArithmeticBinaryOperator = 33, 
		ArithmeticUnaryOperator = 34, ComparsionOperator = 35, LogicalBinaryOperator = 36, 
		LogicalUnaryOperator = 37, Not = 38, DoubleColon = 39, SemiColon = 40, 
		Comma = 41, Period = 42, Equals = 43, Asssigment = 44, NotEquals = 45, 
		Plus = 46, Minus = 47, Star = 48, PlusEquals = 49, MinusEquals = 50, MultiplyEquals = 51, 
		DivideEquals = 52, GreaterEqual = 53, LessEqual = 54, Equal = 55, NotEqual = 56, 
		Or = 57, And = 58, Xor = 59, Strong = 60, Nullable = 61, Mutable = 62, 
		Ref = 63, Class = 64, Interface = 65, Public = 66, Private = 67, Protected = 68, 
		Internal = 69, Final = 70, Virtual = 71, Abstract = 72, Override = 73, 
		DefaultSpecification = 74, Attribute = 75, Throw = 76, IntegerLiteral = 77, 
		DIGIT = 78, LETTER = 79, Whitespace = 80, Newline = 81, BlockComment = 82, 
		LineComment = 83
	};

	CMinusEqualsMinus1Revision0Lexer(antlr4::CharStream *input);

	std::string getGrammarFileName() const final;
	const std::vector<std::string_view>& getRuleNames() const final;

	const std::vector<std::string_view>& getChannelNames() const final;
	const std::vector<std::string_view>& getModeNames() const final;
	const std::vector<std::string_view>& getTokenNames() const final; // deprecated, use vocabulary instead
	antlr4::dfa::Vocabulary& getVocabulary() const final;

	const std::vector<uint16_t> getSerializedATN() const final;
	const antlr4::atn::ATN& getATN() const noexcept final;

private:
	static std::vector<antlr4::dfa::DFA> _decisionToDFA;
	static antlr4::atn::PredictionContextCache _sharedContextCache;
	static std::vector<std::string_view> _ruleNames;
	static std::vector<std::string_view> _tokenNames;
	static std::vector<std::string_view> _channelNames;
	static std::vector<std::string_view> _modeNames;

	static std::vector<std::string_view> _literalNames;
	static std::vector<std::string_view> _symbolicNames;
	static antlr4::dfa::Vocabulary _vocabulary;
	static antlr4::atn::ATN _atn;
	static std::vector<uint16_t> _serializedATN;


	// Individual action functions triggered by action() above.

	// Individual semantic predicate functions triggered by sempred() above.

	struct Initializer
{
		Initializer();
	};
	static Initializer _init;
};

