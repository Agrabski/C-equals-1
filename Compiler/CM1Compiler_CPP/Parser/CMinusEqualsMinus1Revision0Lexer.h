
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

