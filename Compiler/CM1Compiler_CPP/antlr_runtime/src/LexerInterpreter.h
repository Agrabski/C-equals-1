/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "Lexer.h"
#include "atn/PredictionContext.h"
#include "Vocabulary.h"

namespace antlr4 {

	class ANTLR4CPP_PUBLIC LexerInterpreter : public Lexer
	{
	public:
		// @deprecated
		[[deprecated]]
		LexerInterpreter(const std::string& grammarFileName, const std::vector<std::string_view>& tokenNames,
			const std::vector<std::string_view>& ruleNames, const std::vector<std::string_view>& channelNames,
			const std::vector<std::string_view>& modeNames, const atn::ATN& atn, CharStream* input);
		LexerInterpreter(const std::string& grammarFileName, const dfa::Vocabulary& vocabulary,
			const std::vector<std::string_view>& ruleNames, const std::vector<std::string_view>& channelNames,
			const std::vector<std::string_view>& modeNames, const atn::ATN& atn, CharStream* input);

		~LexerInterpreter() noexcept = default;

		const atn::ATN& getATN() const noexcept override;
		std::string getGrammarFileName() const noexcept override;
		const std::vector<std::string_view>& getTokenNames() const noexcept override;
		const std::vector<std::string_view>& getRuleNames() const noexcept override;
		const std::vector<std::string_view>& getChannelNames() const noexcept override;
		const std::vector<std::string_view>& getModeNames() const noexcept override;

		const dfa::Vocabulary& getVocabulary() const noexcept override;

	protected:
		const std::string _grammarFileName;
		const atn::ATN& _atn;

		[[deprecated]]
		std::vector<std::string_view> _tokenNames;
		const std::vector<std::string_view>& _ruleNames;
		const std::vector<std::string_view>& _channelNames;
		const std::vector<std::string_view>& _modeNames;
		std::vector<dfa::DFA> _decisionToDFA;

		atn::PredictionContextCache _sharedContextCache;

	private:
		dfa::Vocabulary _vocabulary;
	};

} // namespace antlr4
