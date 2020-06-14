/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "tree/TerminalNode.h"
#include "tree/ErrorNode.h"
#include "misc/Interval.h"
#include "Parser.h"
#include "Token.h"

#include "support/CPPUtils.h"

#include "ParserRuleContext.h"

using namespace antlr4;
using namespace antlr4::tree;

using namespace antlrcpp;

ParserRuleContext ParserRuleContext::EMPTY;

ParserRuleContext::ParserRuleContext()
	: start(nullptr), stop(nullptr) {
}

ParserRuleContext::ParserRuleContext(ParserRuleContext* parent, size_t invokingStateNumber)
	: RuleContext(parent, invokingStateNumber), start(nullptr), stop(nullptr) {
}

void ParserRuleContext::copyFrom(ParserRuleContext const* ctx) {
	// from RuleContext
	this->parent = ctx->parent;
	this->invokingState = ctx->invokingState;

	this->start = ctx->start;
	this->stop = ctx->stop;

	for (auto& child : ctx->children)
		children.push_back(child->clone(this));
}

tree::TerminalNode* ParserRuleContext::addChild(std::unique_ptr<tree::TerminalNode>&& t)
{
	t->setParent(this);
	auto r = t.get();
	children.push_back(std::move(t));
	return r;
}

RuleContext* ParserRuleContext::addChild(std::unique_ptr<RuleContext>&& ruleInvocation) {
	auto r = ruleInvocation.get();
	children.push_back(std::move(ruleInvocation));
	return r;
}

void ParserRuleContext::removeLastChild() {
	if (!children.empty()) {
		children.pop_back();
	}
}

tree::TerminalNode* ParserRuleContext::getToken(size_t ttype, size_t i) {
	if (i >= children.size()) {
		return nullptr;
	}

	size_t j = 0; // what token with ttype have we found?
	for (auto& o : children) {
		if (is<tree::TerminalNode*>(o.get())) {
			tree::TerminalNode* tnode = dynamic_cast<tree::TerminalNode*>(o.get());
			Token* symbol = tnode->getSymbol();
			if (symbol->getType() == ttype) {
				if (j++ == i) {
					return tnode;
				}
			}
		}
	}

	return nullptr;
}

std::vector<tree::TerminalNode*> ParserRuleContext::getTokens(size_t ttype) {
	std::vector<tree::TerminalNode*> tokens;
	for (auto& o : children)
	{
		if (is<tree::TerminalNode*>(o.get()))
		{
			tree::TerminalNode* tnode = dynamic_cast<tree::TerminalNode*>(o.get());
			Token* symbol = tnode->getSymbol();
			if (symbol->getType() == ttype)
				tokens.push_back(tnode);
		}
	}

	return tokens;
}

misc::Interval ParserRuleContext::getSourceInterval() const noexcept {
	if (start == nullptr) {
		return misc::Interval::INVALID;
	}

	if (stop == nullptr || stop->getTokenIndex() < start->getTokenIndex()) {
		return misc::Interval(start->getTokenIndex(), start->getTokenIndex() - 1); // empty
	}
	return misc::Interval(start->getTokenIndex(), stop->getTokenIndex());
}

Token* ParserRuleContext::getStart() {
	return start;
}

Token* ParserRuleContext::getStop() {
	return stop;
}

std::string ParserRuleContext::toInfoString(Parser* recognizer) {
	std::vector<std::string> rules = recognizer->getRuleInvocationStack(this);
	std::reverse(rules.begin(), rules.end());
	std::string rulesStr = antlrcpp::arrayToString(rules);
	return "ParserRuleContext" + rulesStr + "{start=" + std::to_string(start->getTokenIndex()) + ", stop=" +
		std::to_string(stop->getTokenIndex()) + '}';
}

std::unique_ptr<ParseTree> antlr4::ParserRuleContext::clone(ParseTree* parent) const
{
	auto result = std::make_unique<ParserRuleContext>(*this);
	result->parent = parent;
	return result;
}

