/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "tree/TerminalNode.h"

namespace antlr4 {
	namespace tree {

		class ANTLR4CPP_PUBLIC TerminalNodeImpl : public virtual TerminalNode
		{
		public:
			std::unique_ptr<Token> symbol;

			TerminalNodeImpl(std::unique_ptr<Token>&& symbol);
			TerminalNodeImpl(TerminalNodeImpl const&);

			Token* getSymbol() override;
			void setParent(RuleContext* parent) override;
			misc::Interval getSourceInterval() const noexcept override;

			antlrcpp::Any accept(ParseTreeVisitor* visitor) override;

			std::string getText() override;
			std::string toStringTree(Parser* parser) override;
			std::string toString() override;
			std::string toStringTree() override;
			std::unique_ptr<ParseTree> clone(ParseTree* parent) const override;

		};

	} // namespace tree
} // namespace antlr4
