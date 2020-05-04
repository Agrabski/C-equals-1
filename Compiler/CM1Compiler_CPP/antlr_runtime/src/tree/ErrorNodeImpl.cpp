/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "Exceptions.h"
#include "tree/ParseTreeVisitor.h"

#include "tree/ErrorNodeImpl.h"
#include "Token.h"

using namespace antlr4;
using namespace antlr4::misc;
using namespace antlr4::tree;

ErrorNodeImpl::ErrorNodeImpl(Token* token) : TerminalNodeImpl(token->clone()) {}

antlrcpp::Any ErrorNodeImpl::accept(ParseTreeVisitor* visitor) {
	return visitor->visitErrorNode(this);
}

std::unique_ptr<ParseTree> antlr4::tree::ErrorNodeImpl::clone(ParseTree* parent) const
{
	auto r = std::make_unique<ErrorNodeImpl>(*this);
	r->parent = parent;
	return r;
}
