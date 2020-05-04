/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "atn/ATNDeserializationOptions.h"
#include "dfa/DFA.h"
#include "ParserRuleContext.h"
#include "tree/TerminalNode.h"
#include "tree/ErrorNodeImpl.h"
#include "Lexer.h"
#include "atn/ParserATNSimulator.h"
#include "misc/IntervalSet.h"
#include "atn/RuleStartState.h"
#include "DefaultErrorStrategy.h"
#include "atn/ATNDeserializer.h"
#include "atn/RuleTransition.h"
#include "atn/ATN.h"
#include "Exceptions.h"
#include "ANTLRErrorListener.h"

#include "atn/ProfilingATNSimulator.h"
#include "atn/ParseInfo.h"

#include "Parser.h"

using namespace antlr4;
using namespace antlr4::atn;

using namespace antlrcpp;

std::map<std::vector<uint16_t>, atn::ATN> Parser::bypassAltsAtnCache;

Parser::TraceListener::TraceListener(Parser* outerInstance_) : outerInstance(outerInstance_) {
}

void Parser::TraceListener::enterEveryRule(not_null < ParserRuleContext*> ctx)
{
	std::cout << "enter   " << outerInstance->getRuleNames()[ctx->getRuleIndex()]
		<< ", LT(1)=" << outerInstance->_input->LT(1)->getText() << std::endl;
}

void Parser::TraceListener::exitEveryRule(not_null < ParserRuleContext*> ctx)
{
	std::cout << "exit    " << outerInstance->getRuleNames()[ctx->getRuleIndex()]
		<< ", LT(1)=" << outerInstance->_input->LT(1)->getText() << std::endl;
}

Parser::TrimToSizeListener Parser::TrimToSizeListener::INSTANCE;

void Parser::TrimToSizeListener::exitEveryRule(not_null < ParserRuleContext*> ctx) {
	ctx->children.shrink_to_fit();
}

Parser::Parser(TokenStream* input) {
	InitializeInstanceFields();
	setInputStream(input);
}

void Parser::reset() {
	if (getInputStream() != nullptr) {
		getInputStream()->seek(0);
	}
	_errHandler->reset(this); // Watch out, this is not shared_ptr.reset().

	_matchedEOF = false;
	_syntaxErrors = 0;
	setTrace(false);
	_precedenceStack.clear();
	_precedenceStack.push_back(0);

	atn::ATNSimulator* interpreter = getInterpreter<atn::ParserATNSimulator>();
	if (interpreter != nullptr) {
		interpreter->reset();
	}
}

Token* Parser::match(size_t ttype, ParserRuleContext* currentContext) {
	Token* t = getCurrentToken();
	if (t->getType() == ttype) {
		if (ttype == EOF) {
			_matchedEOF = true;
		}
		_errHandler->reportMatch(this);
		consume(currentContext);
	}
	else {
		t = _errHandler->recoverInline(this, currentContext);
		if (_buildParseTrees && t->getTokenIndex() == INVALID_INDEX) {
			// we must have conjured up a new token during single token insertion
			// if it's not the current symbol
			currentContext->addChild(createErrorNode(t));
		}
	}
	return t;
}

Token* Parser::matchWildcard(ParserRuleContext* currentContext)
{
	Token* t = getCurrentToken();
	if (t->getType() > 0) {
		_errHandler->reportMatch(this);
		consume(currentContext);
	}
	else {
		t = _errHandler->recoverInline(this, currentContext);
		if (_buildParseTrees && t->getTokenIndex() == INVALID_INDEX) {
			// we must have conjured up a new token during single token insertion
			// if it's not the current symbol
			currentContext->addChild(createErrorNode(t));
		}
	}

	return t;
}

void Parser::setBuildParseTree(bool buildParseTrees) {
	this->_buildParseTrees = buildParseTrees;
}

bool Parser::getBuildParseTree() {
	return _buildParseTrees;
}

void Parser::setTrimParseTree(bool trimParseTrees) {
	if (trimParseTrees) {
		if (getTrimParseTree()) {
			return;
		}
		addParseListener(&TrimToSizeListener::INSTANCE);
	}
	else {
		removeParseListener(&TrimToSizeListener::INSTANCE);
	}
}

bool Parser::getTrimParseTree() {
	return std::find(getParseListeners().begin(), getParseListeners().end(), &TrimToSizeListener::INSTANCE) != getParseListeners().end();
}

std::vector<tree::ParseTreeListener*> Parser::getParseListeners() {
	return _parseListeners;
}

void Parser::addParseListener(tree::ParseTreeListener* listener) {
	if (!listener) {
		throw NullPointerException("listener");
	}

	this->_parseListeners.push_back(listener);
}

void Parser::removeParseListener(tree::ParseTreeListener* listener) {
	if (!_parseListeners.empty()) {
		auto it = std::find(_parseListeners.begin(), _parseListeners.end(), listener);
		if (it != _parseListeners.end()) {
			_parseListeners.erase(it);
		}
	}
}

void Parser::removeParseListeners() {
	_parseListeners.clear();
}

void Parser::triggerEnterRuleEvent(ParserRuleContext* currentContext)
{
	for (auto listener : _parseListeners)
	{
		listener->enterEveryRule(currentContext);
		currentContext->enterRule(listener);
	}
}

void Parser::triggerExitRuleEvent(ParserRuleContext* currentContext)
{
	// reverse order walk of listeners
	for (auto it = _parseListeners.rbegin(); it != _parseListeners.rend(); ++it) {
		currentContext->exitRule(*it);
		(*it)->exitEveryRule(currentContext);
	}
}

size_t Parser::getNumberOfSyntaxErrors() {
	return _syntaxErrors;
}

Ref<TokenFactory<CommonToken>> Parser::getTokenFactory() {
	return _input->getTokenSource()->getTokenFactory();
}


const atn::ATN& Parser::getATNWithBypassAlts() {
	std::vector<uint16_t> serializedAtn = getSerializedATN();
	if (serializedAtn.empty()) {
		throw UnsupportedOperationException("The current parser does not support an ATN with bypass alternatives.");
	}

	std::lock_guard<std::mutex> lck(_mutex);

	// XXX: using the entire serialized ATN as key into the map is a big resource waste.
	//      How large can that thing become?
	if (bypassAltsAtnCache.find(serializedAtn) == bypassAltsAtnCache.end())
	{
		atn::ATNDeserializationOptions deserializationOptions;
		deserializationOptions.setGenerateRuleBypassTransitions(true);

		atn::ATNDeserializer deserializer(deserializationOptions);
		bypassAltsAtnCache[serializedAtn] = deserializer.deserialize(serializedAtn);
	}

	return bypassAltsAtnCache[serializedAtn];
}

Ref<ANTLRErrorStrategy> Parser::getErrorHandler() {
	return _errHandler;
}

void Parser::setErrorHandler(Ref<ANTLRErrorStrategy> const& handler) {
	_errHandler = handler;
}

IntStream* Parser::getInputStream() {
	return getTokenStream();
}

void Parser::setInputStream(IntStream* input) {
	setTokenStream(static_cast<TokenStream*>(input));
}

TokenStream* Parser::getTokenStream() {
	return _input;
}

void Parser::setTokenStream(TokenStream* input) {
	_input = nullptr; // Just a reference we don't own.
	reset();
	_input = input;
}

Token* Parser::getCurrentToken() {
	return _input->LT(1);
}

void Parser::notifyErrorListeners(const std::string& msg) {
	notifyErrorListeners(getCurrentToken(), msg, nullptr);
}

void Parser::notifyErrorListeners(Token* offendingToken, const std::string& msg, std::exception_ptr e) {
	_syntaxErrors++;
	size_t line = offendingToken->getLine();
	size_t charPositionInLine = offendingToken->getCharPositionInLine();

	ProxyErrorListener& listener = getErrorListenerDispatch();
	listener.syntaxError(this, offendingToken, line, charPositionInLine, msg, e);
}

Token* Parser::consume(ParserRuleContext* currentContext)
{
	Token* o = getCurrentToken();
	if (o->getType() != EOF) {
		getInputStream()->consume();
	}

	bool hasListener = _parseListeners.size() > 0 && !_parseListeners.empty();
	if (_buildParseTrees || hasListener)
	{
		if (_errHandler->inErrorRecoveryMode(this))
		{
			auto node = createErrorNode(o);
			auto n = node.get();
			currentContext->addChild(std::move(node));
			if (_parseListeners.size() > 0)
				for (auto listener : _parseListeners)
					listener->visitErrorNode(n);
		}
		else
		{
			tree::TerminalNode* node = currentContext->addChild(createTerminalNode(o));
			if (_parseListeners.size() > 0)
				for (auto listener : _parseListeners)
					listener->visitTerminal(node);
		}
	}
	return o;
}

void Parser::addContextToParseTree(std::unique_ptr<ParserRuleContext>&& currentContext)
{
	// Add current context to parent if we have a parent.
	if (currentContext->parent == nullptr)
	{
		assert(_root == nullptr);
		_root = std::move(currentContext);
		return;
	}

	ParserRuleContext* parent = dynamic_cast<ParserRuleContext*>(currentContext->parent);
	parent->addChild(std::move(currentContext));
}

void Parser::enterRule(std::unique_ptr<ParserRuleContext>&& currentContext, size_t state, size_t /*ruleIndex*/) {
	setState(state);
	currentContext->start = _input->LT(1);
	auto ctx = currentContext.get();
	if (_buildParseTrees) {
		addContextToParseTree(std::move(currentContext));
	}
	if (_parseListeners.size() > 0) {
		triggerEnterRuleEvent(ctx);
	}
}

void Parser::exitRule(ParserRuleContext* currentContext)
{
	if (_matchedEOF) {
		// if we have matched EOF, it cannot consume past EOF so we use LT(1) here
		currentContext->stop = _input->LT(1); // LT(1) will be end of file
	}
	else {
		currentContext->stop = _input->LT(-1); // stop node is what we just matched
	}

	// trigger event on ctx, before it reverts to parent
	if (_parseListeners.size() > 0) {
		triggerExitRuleEvent(currentContext);
	}
	setState(currentContext->invokingState);
}

void Parser::enterOuterAlt(ParserRuleContext* localctx, size_t altNum)
{
	localctx->setAltNumber(altNum);
}

int Parser::getPrecedence() const
{
	if (_precedenceStack.empty())
		return -1;
	return _precedenceStack.back();
}

void Parser::enterRecursionRule(ParserRuleContext* localctx, size_t ruleIndex) {
	enterRecursionRule(localctx, getATN().ruleToStartState[ruleIndex]->stateNumber, ruleIndex, 0);
}

void Parser::enterRecursionRule(ParserRuleContext* localctx, size_t state, size_t /*ruleIndex*/, int precedence) {
	setState(state);
	_precedenceStack.push_back(precedence);
	localctx->start = _input->LT(1);
	if (!_parseListeners.empty()) {
		triggerEnterRuleEvent(localctx); // simulates rule entry for left-recursive rules
	}
}
void Parser::unrollRecursionContexts(ParserRuleContext* parentctx, std::unique_ptr<ParserRuleContext>&& currentctx) {
	_precedenceStack.pop_back();
	if (currentctx != nullptr)
	{
		currentctx->stop = _input->LT(-1);

		// hook into tree
		currentctx->parent = parentctx;

		if (_buildParseTrees && parentctx != nullptr && currentctx != nullptr)
			// add return ctx into invoking rule's tree
			parentctx->addChild(std::move(currentctx));
		if (parentctx == nullptr)
			_root = std::move(currentctx);
	}
}

ParserRuleContext* Parser::getInvokingContext(ParserRuleContext* currentCtx, size_t ruleIndex) {
	ParserRuleContext* p = currentCtx;
	while (p) {
		if (p->getRuleIndex() == ruleIndex) {
			return p;
		}
		if (p->parent == nullptr)
			break;
		p = dynamic_cast<ParserRuleContext*>(p->parent);
	}
	return nullptr;
}

bool Parser::precpred(RuleContext* /*localctx*/, int precedence) {
	return precedence >= _precedenceStack.back();
}

bool Parser::inContext(const std::string&/*context*/) {
	// TO_DO: useful in parser?
	return false;
}

bool Parser::isExpectedToken(ParserRuleContext* current, size_t symbol) {
	const atn::ATN& atn = getInterpreter<atn::ParserATNSimulator>()->atn;
	ParserRuleContext* ctx = current;
	atn::ATNState* s = atn.states[getState()].get();
	misc::IntervalSet following = atn.nextTokens(s);

	if (following.contains(symbol)) {
		return true;
	}

	if (!following.contains(Token::EPSILON)) {
		return false;
	}

	while (ctx && ctx->invokingState != ATNState::INVALID_STATE_NUMBER && following.contains(Token::EPSILON)) {
		atn::ATNState* invokingState = atn.states[ctx->invokingState].get();
		atn::RuleTransition* rt = static_cast<atn::RuleTransition*>(invokingState->transitions[0]);
		following = atn.nextTokens(rt->followState);
		if (following.contains(symbol)) {
			return true;
		}

		ctx = dynamic_cast<ParserRuleContext*>(ctx->parent);
	}

	if (following.contains(Token::EPSILON) && symbol == EOF) {
		return true;
	}

	return false;
}

bool Parser::isMatchedEOF() const {
	return _matchedEOF;
}

misc::IntervalSet Parser::getExpectedTokens(ParserRuleContext* currentContext) {
	return getATN().getExpectedTokens(getState(), currentContext);
}

misc::IntervalSet Parser::getExpectedTokensWithinCurrentRule() {
	const atn::ATN& atn = getInterpreter<atn::ParserATNSimulator>()->atn;
	atn::ATNState* s = atn.states[getState()].get();
	return atn.nextTokens(s);
}

size_t Parser::getRuleIndex(const std::string& ruleName) {
	const std::map<std::string, size_t>& m = getRuleIndexMap();
	auto iterator = m.find(ruleName);
	if (iterator == m.end()) {
		return INVALID_INDEX;
	}
	return iterator->second;
}

std::vector<std::string> Parser::getRuleInvocationStack(ParserRuleContext* current)
{
	return getRuleInvocationStack(current);
}

std::vector<std::string_view> Parser::getRuleInvocationStack(RuleContext* p)
{
	auto const& ruleNames = getRuleNames();
	std::vector<std::string_view> stack;
	RuleContext* run = p;
	while (run != nullptr) {
		// compute what follows who invoked us
		auto const ruleIndex = run->getRuleIndex();
		if (ruleIndex == INVALID_INDEX)
			stack.push_back("n/a");
		else
			stack.push_back(ruleNames[ruleIndex]);
		if (p->parent == nullptr)
			break;
		run = dynamic_cast<RuleContext*>(run->parent);
	}
	return stack;
}

std::vector<std::string> Parser::getDFAStrings() {
	atn::ParserATNSimulator* simulator = getInterpreter<atn::ParserATNSimulator>();
	if (!simulator->decisionToDFA.empty()) {
		std::lock_guard<std::mutex> lck(_mutex);

		std::vector<std::string> s;
		for (size_t d = 0; d < simulator->decisionToDFA.size(); d++) {
			dfa::DFA& dfa = simulator->decisionToDFA[d];
			s.push_back(dfa.toString(getVocabulary()));
		}
		return s;
	}
	return std::vector<std::string>();
}

void Parser::dumpDFA() {
	atn::ParserATNSimulator* simulator = getInterpreter<atn::ParserATNSimulator>();
	if (!simulator->decisionToDFA.empty()) {
		std::lock_guard<std::mutex> lck(_mutex);
		bool seenOne = false;
		for (size_t d = 0; d < simulator->decisionToDFA.size(); d++) {
			dfa::DFA& dfa = simulator->decisionToDFA[d];
			if (!dfa.states.empty()) {
				if (seenOne) {
					std::cout << std::endl;
				}
				std::cout << "Decision " << dfa.decision << ":" << std::endl;
				std::cout << dfa.toString(getVocabulary());
				seenOne = true;
			}
		}
	}
}

std::string Parser::getSourceName() {
	return _input->getSourceName();
}

atn::ParseInfo Parser::getParseInfo() const {
	atn::ProfilingATNSimulator* interp = getInterpreter<atn::ProfilingATNSimulator>();
	return atn::ParseInfo(interp);
}

void Parser::setProfile(bool profile) {
	atn::ParserATNSimulator* interp = getInterpreter<atn::ProfilingATNSimulator>();
	auto const saveMode = interp != nullptr ? interp->getPredictionMode() : atn::PredictionMode::LL;
	if (profile) {
		if (!is<atn::ProfilingATNSimulator*>(interp)) {
			setInterpreter(std::make_unique<atn::ProfilingATNSimulator>(this)); /* mem-check: replacing existing interpreter which gets deleted. */
		}
	}
	else
	{
		auto const interpeter = dynamic_cast<atn::ProfilingATNSimulator*>(interp);
		if (interpeter != nullptr)
			setInterpreter(std::make_unique<atn::ParserATNSimulator>(this, getATN(), interp->decisionToDFA, interp->getSharedContextCache()));
	}
	getInterpreter<atn::ParserATNSimulator>()->setPredictionMode(saveMode);
}

void Parser::setTrace(bool trace) {
	if (!trace) {
		if (_tracer)
			removeParseListener(_tracer);
		delete _tracer;
		_tracer = nullptr;
	}
	else {
		if (_tracer)
			removeParseListener(_tracer); // Just in case this is triggered multiple times.
		_tracer = new TraceListener(this);
		addParseListener(_tracer);
	}
}

bool Parser::isTrace() const {
	return _tracer != nullptr;
}

std::unique_ptr<tree::TerminalNode> Parser::createTerminalNode(std::unique_ptr<Token>&& t)
{
	return std::make_unique<tree::TerminalNodeImpl>(std::move(t));
}

std::unique_ptr<tree::TerminalNode> Parser::createTerminalNode(not_null<Token const*> t)
{
	return std::make_unique<tree::TerminalNodeImpl>(t->clone());
}

std::unique_ptr<tree::ErrorNode> Parser::createErrorNode(Token* t) {
	return std::make_unique<tree::ErrorNodeImpl>(t);
}

void Parser::InitializeInstanceFields() {
	_errHandler = std::make_shared<DefaultErrorStrategy>();
	_precedenceStack.clear();
	_precedenceStack.push_back(0);
	_buildParseTrees = true;
	_syntaxErrors = 0;
	_matchedEOF = false;
	_input = nullptr;
	_tracer = nullptr;
}

