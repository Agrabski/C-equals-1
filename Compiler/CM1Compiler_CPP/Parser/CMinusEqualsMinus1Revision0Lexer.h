
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
		DOUBLEQUOTE = 26, SINGLEQUOTE = 27, ParamOpen = 28, ParamClose = 29, ATTROBITEOPEN = 30, 
		ATTROBITECLOSE = 31, ArithmeticBinaryOperator = 32, ArithmeticUnaryOperator = 33, 
		ComparsionOperator = 34, LogicalBinaryOperator = 35, LogicalUnaryOperator = 36, 
		Not = 37, DoubleColon = 38, SemiColon = 39, Comma = 40, Period = 41, Equals = 42, 
		Asssigment = 43, NotEquals = 44, Plus = 45, Minus = 46, Star = 47, PlusEquals = 48, 
		MinusEquals = 49, MultiplyEquals = 50, DivideEquals = 51, GreaterEqual = 52, 
		LessEqual = 53, Equal = 54, NotEqual = 55, Or = 56, And = 57, Xor = 58, 
		Strong = 59, Nullable = 60, Mutable = 61, Ref = 62, Class = 63, Interface = 64, 
		Public = 65, Private = 66, Protected = 67, Internal = 68, Final = 69, 
		Virtual = 70, Abstract = 71, Override = 72, DefaultSpecification = 73, 
		Attribute = 74, Throw = 75, IntegerLiteral = 76, DIGIT = 77, STRING = 78, 
		AnyCharacter = 79, LETTER = 80, Whitespace = 81, Newline = 82, BlockComment = 83, 
		LineComment = 84
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

