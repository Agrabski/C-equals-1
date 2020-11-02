
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
		T__20 = 21, T__21 = 22, T__22 = 23, AccessSpecifier = 24, Identifier = 25, 
		OpenBracket = 26, CloseBracket = 27, DOUBLEQUOTE = 28, SINGLEQUOTE = 29, 
		ParamOpen = 30, ParamClose = 31, ATTROBITEOPEN = 32, ATTROBITECLOSE = 33, 
		Array = 34, ArithmeticBinaryOperator = 35, ArithmeticUnaryOperator = 36, 
		ComparsionOperator = 37, LogicalBinaryOperator = 38, Unsafe = 39, LogicalUnaryOperator = 40, 
		Not = 41, DoubleColon = 42, SemiColon = 43, Comma = 44, Period = 45, Equals = 46, 
		Asssigment = 47, NotEquals = 48, Plus = 49, Minus = 50, Star = 51, PlusEquals = 52, 
		MinusEquals = 53, MultiplyEquals = 54, DivideEquals = 55, GreaterEqual = 56, 
		LessEqual = 57, Equal = 58, NotEqual = 59, Or = 60, And = 61, Xor = 62, 
		Strong = 63, Nullable = 64, Mutable = 65, Ref = 66, Class = 67, Interface = 68, 
		Public = 69, Private = 70, Internal = 71, Final = 72, Virtual = 73, Abstract = 74, 
		Override = 75, DefaultSpecification = 76, Attribute = 77, Throw = 78, 
		IntegerLiteral = 79, DIGIT = 80, STRING = 81, AnyCharacter = 82, LETTER = 83, 
		Whitespace = 84, Newline = 85, BlockComment = 86, LineComment = 87
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

