
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
		T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, AccessSpecifier = 12, Identifier = 13, 
		OpenBracket = 14, CloseBracket = 15, RAWSTRING = 16, DOUBLEQUOTE = 17, 
		SINGLEQUOTE = 18, ParamOpen = 19, ParamClose = 20, ATTROBITEOPEN = 21, 
		ATTROBITECLOSE = 22, ArithmeticBinaryOperator = 23, ArithmeticUnaryOperator = 24, 
		ComparsionOperator = 25, LogicalBinaryOperator = 26, LogicalUnaryOperator = 27, 
		Not = 28, DoubleColon = 29, SemiColon = 30, Comma = 31, Period = 32, Equals = 33, 
		Asssigment = 34, NotEquals = 35, Plus = 36, Minus = 37, Star = 38, PlusEquals = 39, 
		MinusEquals = 40, MultiplyEquals = 41, DivideEquals = 42, GreaterThan = 43, 
		LessThan = 44, GreaterEqual = 45, LessEqual = 46, Equal = 47, NotEqual = 48, 
		Or = 49, And = 50, Xor = 51, Strong = 52, Nullable = 53, Mutable = 54, 
		Ref = 55, Class = 56, Interface = 57, Public = 58, Private = 59, Protected = 60, 
		Internal = 61, Final = 62, Virtual = 63, Abstract = 64, Override = 65, 
		DefaultSpecification = 66, Attribute = 67, Throw = 68, IntegerLiteral = 69, 
		DIGIT = 70, LETTER = 71, Whitespace = 72, Newline = 73, BlockComment = 74, 
		LineComment = 75
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

