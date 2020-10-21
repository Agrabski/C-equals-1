
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

