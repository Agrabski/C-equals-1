/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "antlr4-common.h"
#include "support/CPPUtils.h"

namespace antlr4 {
	namespace tree {

		/** This interface describes the minimal core of methods triggered
		 *  by {@link ParseTreeWalker}. E.g.,
		 *
		 *  	ParseTreeWalker walker = new ParseTreeWalker();
		 *		walker.walk(myParseTreeListener, myParseTree); <-- triggers events in your listener
		 *
		 *  If you want to trigger events in multiple listeners during a single
		 *  tree walk, you can use the ParseTreeDispatcher object available at
		 *
		 * 		https://github.com/antlr/antlr4/issues/841
		 */
		class ANTLR4CPP_PUBLIC ParseTreeListener {
		public:
			virtual ~ParseTreeListener() = default;

			virtual void enterEveryRule(not_null<antlr4::ParserRuleContext*>) = 0;
			virtual void exitEveryRule(not_null<antlr4::ParserRuleContext*>) = 0;
			virtual void visitTerminal(not_null<antlr4::tree::TerminalNode*>) = 0;
			virtual void visitErrorNode(not_null<antlr4::tree::ErrorNode*>) = 0;

			bool operator == (const ParseTreeListener& other) const noexcept
			{
				return this == &other;
			}
		};

	} // namespace tree
} // namespace antlr4
