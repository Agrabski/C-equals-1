
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

