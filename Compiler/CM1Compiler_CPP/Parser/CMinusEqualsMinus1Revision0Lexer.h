
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
		T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, AccessSpecifier = 20, 
		Identifier = 21, OpenBracket = 22, CloseBracket = 23, RAWSTRING = 24, 
		DOUBLEQUOTE = 25, SINGLEQUOTE = 26, ParamOpen = 27, ParamClose = 28, ATTROBITEOPEN = 29, 
		ATTROBITECLOSE = 30, ArithmeticBinaryOperator = 31, ArithmeticUnaryOperator = 32, 
		ComparsionOperator = 33, LogicalBinaryOperator = 34, LogicalUnaryOperator = 35, 
		Not = 36, DoubleColon = 37, SemiColon = 38, Comma = 39, Period = 40, Equals = 41, 
		Asssigment = 42, NotEquals = 43, Plus = 44, Minus = 45, Star = 46, PlusEquals = 47, 
		MinusEquals = 48, MultiplyEquals = 49, DivideEquals = 50, GreaterEqual = 51, 
		LessEqual = 52, Equal = 53, NotEqual = 54, Or = 55, And = 56, Xor = 57, 
		Strong = 58, Nullable = 59, Mutable = 60, Ref = 61, Class = 62, Interface = 63, 
		Public = 64, Private = 65, Protected = 66, Internal = 67, Final = 68, 
		Virtual = 69, Abstract = 70, Override = 71, DefaultSpecification = 72, 
		Attribute = 73, Throw = 74, IntegerLiteral = 75, DIGIT = 76, LETTER = 77, 
		Whitespace = 78, Newline = 79, BlockComment = 80, LineComment = 81
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

