#pragma once


#include "antlr4-runtime.h"




class  XPathLexer : public antlr4::Lexer
{
public:
	enum 
	{
		TOKEN_REF = 1, RULE_REF = 2, ANYWHERE = 3, ROOT = 4, WILDCARD = 5, BANG = 6,
		ID = 7, STRING = 8
	};

	XPathLexer(antlr4::CharStream* input);

	std::string getGrammarFileName() const override;
	const std::vector<std::string_view>& getRuleNames() const override;

	const std::vector<std::string_view>& getChannelNames() const override;
	const std::vector<std::string_view>& getModeNames() const override;
	const std::vector<std::string_view>& getTokenNames() const override; // deprecated, use vocabulary instead
	antlr4::dfa::Vocabulary& getVocabulary() const override;

	const std::vector<uint16_t> getSerializedATN() const noexcept override;
	const antlr4::atn::ATN& getATN() const noexcept override;

	void action(antlr4::RuleContext* context, size_t ruleIndex, size_t actionIndex) override;
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
	void IDAction(antlr4::RuleContext* context, size_t actionIndex);

	// Individual semantic predicate functions triggered by sempred() above.

	struct Initializer {
		Initializer();
	};
	static Initializer _init;
};

