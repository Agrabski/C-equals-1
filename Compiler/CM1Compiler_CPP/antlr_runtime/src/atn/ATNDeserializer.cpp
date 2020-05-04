/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "atn/ATNDeserializationOptions.h"

#include "atn/ATNType.h"
#include "atn/ATNState.h"
#include "atn/ATN.h"

#include "atn/LoopEndState.h"
#include "atn/DecisionState.h"
#include "atn/RuleStartState.h"
#include "atn/RuleStopState.h"
#include "atn/TokensStartState.h"
#include "atn/RuleTransition.h"
#include "atn/EpsilonTransition.h"
#include "atn/PlusLoopbackState.h"
#include "atn/PlusBlockStartState.h"
#include "atn/StarLoopbackState.h"
#include "atn/BasicBlockStartState.h"
#include "atn/BasicState.h"
#include "atn/BlockEndState.h"
#include "atn/StarLoopEntryState.h"

#include "atn/AtomTransition.h"
#include "atn/StarBlockStartState.h"
#include "atn/RangeTransition.h"
#include "atn/PredicateTransition.h"
#include "atn/PrecedencePredicateTransition.h"
#include "atn/ActionTransition.h"
#include "atn/SetTransition.h"
#include "atn/NotSetTransition.h"
#include "atn/WildcardTransition.h"
#include "Token.h"

#include "misc/IntervalSet.h"
#include "Exceptions.h"
#include "support/CPPUtils.h"
#include "support/StringUtils.h"

#include "atn/LexerCustomAction.h"
#include "atn/LexerChannelAction.h"
#include "atn/LexerModeAction.h"
#include "atn/LexerMoreAction.h"
#include "atn/LexerPopModeAction.h"
#include "atn/LexerPushModeAction.h"
#include "atn/LexerSkipAction.h"
#include "atn/LexerTypeAction.h"

#include "atn/ATNDeserializer.h"

#include <string>

using namespace antlr4;
using namespace antlr4::atn;
using namespace antlrcpp;

const size_t ATNDeserializer::SERIALIZED_VERSION = 3;

namespace {

	uint32_t deserializeInt32(const std::vector<uint16_t>& data, size_t offset) noexcept
	{
		return (uint32_t)data[offset] | ((uint32_t)data[offset + 1] << 16);
	}

	ssize_t readUnicodeInt(const std::vector<uint16_t>& data, int& p) noexcept
	{
		return static_cast<ssize_t>(data[p++]);
	}

	ssize_t readUnicodeInt32(const std::vector<uint16_t>& data, int& p)
	{
		auto const result = deserializeInt32(data, p);
		p += 2;
		return gsl::narrow<ssize_t>( result);
	}

	// We templatize this on the function type so the optimizer can inline
	// the 16- or 32-bit readUnicodeInt/readUnicodeInt32 as needed.
	template <typename F>
	void deserializeSets(
		const std::vector<uint16_t>& data,
		int& p,
		std::vector<misc::IntervalSet>& sets,
		F readUnicode) {
		auto const nsets = data[p++];
		for (int i = 0; i < nsets; i++) {
			auto const nintervals = data[p++];
			misc::IntervalSet set;

			auto const containsEof = data[p++] != 0;
			if (containsEof) {
				set.add(-1);
			}

			for (int j = 0; j < nintervals; j++) {
				auto const a = readUnicode(data, p);
				auto const b = readUnicode(data, p);
				set.add(a, b);
			}
			sets.push_back(set);
		}
	}

}

ATNDeserializer::ATNDeserializer() noexcept : ATNDeserializer(ATNDeserializationOptions::getDefaultOptions()) {
}

ATNDeserializer::ATNDeserializer(const ATNDeserializationOptions& dso) noexcept : deserializationOptions(dso) {
}

/**
 * This value should never change. Updates following this version are
 * reflected as change in the unique ID SERIALIZED_UUID.
 */
Guid ATNDeserializer::ADDED_PRECEDENCE_TRANSITIONS() {
	return Guid("1DA0C57D-6C06-438A-9B27-10BCB3CE0F61");
}

Guid ATNDeserializer::ADDED_LEXER_ACTIONS() {
	return Guid("AADB8D7E-AEEF-4415-AD2B-8204D6CF042E");
}

Guid ATNDeserializer::ADDED_UNICODE_SMP() {
	return Guid("59627784-3BE5-417A-B9EB-8131A7286089");
}

Guid ATNDeserializer::SERIALIZED_UUID() {
	return ADDED_UNICODE_SMP();
}

Guid ATNDeserializer::BASE_SERIALIZED_UUID() {
	return Guid("33761B2D-78BB-4A43-8B0B-4F5BEE8AACF3");
}

std::vector<Guid>& ATNDeserializer::SUPPORTED_UUIDS() {
	static std::vector<Guid> singleton = { BASE_SERIALIZED_UUID(), ADDED_PRECEDENCE_TRANSITIONS(), ADDED_LEXER_ACTIONS(), ADDED_UNICODE_SMP() };
	return singleton;
}

bool ATNDeserializer::isFeatureSupported(const Guid& feature, const Guid& actualUuid) {
	auto featureIterator = std::find(SUPPORTED_UUIDS().begin(), SUPPORTED_UUIDS().end(), feature);
	if (featureIterator == SUPPORTED_UUIDS().end()) {
		return false;
	}
	auto actualIterator = std::find(SUPPORTED_UUIDS().begin(), SUPPORTED_UUIDS().end(), actualUuid);
	if (actualIterator == SUPPORTED_UUIDS().end()) {
		return false;
	}

	return std::distance(featureIterator, actualIterator) >= 0;
}

ATN ATNDeserializer::deserialize(const std::vector<uint16_t>& input) {
	// Don't adjust the first value since that's the version number.
	std::vector<uint16_t> data(input.size());
	data[0] = input[0];
	for (size_t i = 1; i < input.size(); ++i) {
		data[i] = input[i] - 2;
	}

	int p = 0;
	auto const version = data[p++];
	if (version != SERIALIZED_VERSION) {
		std::string reason = "Could not deserialize ATN with version" + std::to_string(version) + "(expected " + std::to_string(SERIALIZED_VERSION) + ").";

		throw UnsupportedOperationException(reason);
	}

	Guid uuid = toUUID(data.data(), p);
	p += 8;
	auto uuidIterator = std::find(SUPPORTED_UUIDS().begin(), SUPPORTED_UUIDS().end(), uuid);
	if (uuidIterator == SUPPORTED_UUIDS().end()) {
		std::string reason = "Could not deserialize ATN with UUID " + uuid.toString() + " (expected " +
			SERIALIZED_UUID().toString() + " or a legacy UUID).";

		throw UnsupportedOperationException(reason);
	}

	bool supportsPrecedencePredicates = isFeatureSupported(ADDED_PRECEDENCE_TRANSITIONS(), uuid);
	bool supportsLexerActions = isFeatureSupported(ADDED_LEXER_ACTIONS(), uuid);

	ATNType const grammarType = (ATNType)data[p++];
	size_t const maxTokenType = data[p++];
	ATN atn(grammarType, maxTokenType);

	//
	// STATES
	//
	std::vector<std::pair<LoopEndState*, size_t>> loopBackStateNumbers;
	std::vector<std::pair<BlockStartState*, size_t>> endStateNumbers;
	size_t const nstates = data[p++];
	for (size_t i = 0; i < nstates; i++) {
		size_t const stype = data[p++];
		// ignore bad type of states
		if (stype == ATNState::ATN_INVALID_TYPE) {
			atn.addState(nullptr);
			continue;
		}

		size_t ruleIndex = data[p++];
		if (ruleIndex == 0xFFFF) {
			ruleIndex = INVALID_INDEX;
		}

		auto s = stateFactory(stype, ruleIndex);
		if (stype == ATNState::LOOP_END) { // special case
			int loopBackStateNumber = data[p++];
			loopBackStateNumbers.push_back({ (LoopEndState*)s.get(),  loopBackStateNumber });
		}
		else if (is<BlockStartState*>(s.get())) {
			int endStateNumber = data[p++];
			endStateNumbers.push_back({ (BlockStartState*)s.get(), endStateNumber });
		}
		atn.addState(std::move(s));
	}

	// delay the assignment of loop back and end states until we know all the state instances have been initialized
	for (auto& pair : loopBackStateNumbers) {
		pair.first->loopBackState = atn.states[pair.second].get();
	}

	for (auto& pair : endStateNumbers)
		pair.first->endState = dynamic_cast<BlockEndState*>(atn.states[pair.second].get());

	size_t const numNonGreedyStates = data[p++];
	for (size_t i = 0; i < numNonGreedyStates; i++) {
		size_t const stateNumber = data[p++];
		// The serialized ATN must be specifying the right states, so that the
		// cast below is correct.
		((DecisionState*)atn.states[stateNumber].get())->nonGreedy = true;
	}

	if (supportsPrecedencePredicates) {
		size_t const numPrecedenceStates = data[p++];
		for (size_t i = 0; i < numPrecedenceStates; i++) {
			size_t const stateNumber = data[p++];
			((RuleStartState*)atn.states[stateNumber].get())->isLeftRecursiveRule = true;
		}
	}

	//
	// RULES
	//
	size_t const nrules = data[p++];
	for (size_t i = 0; i < nrules; i++) {
		size_t const s = data[p++];
		// Also here, the serialized atn must ensure to point to the correct class type.
		RuleStartState* startState = (RuleStartState*)atn.states[s].get();
		atn.ruleToStartState.push_back(startState);
		if (atn.grammarType == ATNType::LEXER) {
			size_t tokenType = data[p++];
			if (tokenType == 0xFFFF) {
				tokenType = Token::EOF;
			}

			atn.ruleToTokenType.push_back(tokenType);

			if (!isFeatureSupported(ADDED_LEXER_ACTIONS(), uuid)) {
				// this piece of unused metadata was serialized prior to the
				// addition of LexerAction
				//int actionIndexIgnored = data[p++];
				p++;
			}
		}
	}

	atn.ruleToStopState.resize(nrules);
	for (auto& state : atn.states) {
		auto const stopState = dynamic_cast<RuleStopState*>(state.get());
		if (stopState != nullptr)
		{
			RuleStopState* stopState = dynamic_cast<RuleStopState*>(state.get());
			atn.ruleToStopState[state->ruleIndex] = stopState;
			atn.ruleToStartState[state->ruleIndex]->stopState = stopState;
		}
	}

	//
	// MODES
	//
	size_t const nmodes = data[p++];
	for (size_t i = 0; i < nmodes; i++) {
		size_t const s = data[p++];
		atn.modeToStartState.push_back(static_cast<TokensStartState*>(atn.states[s].get()));
	}

	//
	// SETS
	//
	std::vector<misc::IntervalSet> sets;

	// First, deserialize sets with 16-bit arguments <= U+FFFF.
	deserializeSets(data, p, sets, readUnicodeInt);

	// Next, if the ATN was serialized with the Unicode SMP feature,
	// deserialize sets with 32-bit arguments <= U+10FFFF.
	if (isFeatureSupported(ADDED_UNICODE_SMP(), uuid)) {
		deserializeSets(data, p, sets, readUnicodeInt32);
	}

	//
	// EDGES
	//
	int const nedges = data[p++];
	for (int i = 0; i < nedges; i++) {
		size_t const src = data[p];
		size_t const trg = data[p + 1];
		size_t const ttype = data[p + 2];
		size_t const arg1 = data[p + 3];
		size_t const arg2 = data[p + 4];
		size_t const arg3 = data[p + 5];
		Transition* trans = edgeFactory(atn, ttype, src, trg, arg1, arg2, arg3, sets);
		ATNState* srcState = atn.states[src].get();
		srcState->addTransition(trans);
		p += 6;
	}

	// edges for rule stop states can be derived, so they aren't serialized
	for (auto& state : atn.states) {
		for (size_t i = 0; i < state->transitions.size(); i++) {
			Transition* t = state->transitions[i];
			if (!is<RuleTransition*>(t))
				continue;

			RuleTransition* ruleTransition = dynamic_cast<RuleTransition*>(t);
			size_t outermostPrecedenceReturn = INVALID_INDEX;
			if (atn.ruleToStartState[ruleTransition->target->ruleIndex]->isLeftRecursiveRule)
				if (ruleTransition->precedence == 0)
					outermostPrecedenceReturn = ruleTransition->target->ruleIndex;

			EpsilonTransition* returnTransition = new EpsilonTransition(ruleTransition->followState, outermostPrecedenceReturn); /* mem check: freed in ANTState d-tor */
			atn.ruleToStopState[ruleTransition->target->ruleIndex]->addTransition(returnTransition);
		}
	}

	for (auto& state : atn.states) {
		if (is<BlockStartState*>(state.get())) {
			BlockStartState* startState = dynamic_cast<BlockStartState*>(state.get());

			// we need to know the end state to set its start state
			if (startState->endState == nullptr) {
				throw IllegalStateException();
			}

			// block end states can only be associated to a single block start state
			if (startState->endState->startState != nullptr) {
				throw IllegalStateException();
			}

			startState->endState->startState = dynamic_cast<BlockStartState*>(state.get());
		}

		PlusLoopbackState* loopbackState = dynamic_cast<PlusLoopbackState*>(state.get());

		if (loopbackState != nullptr)
			for (size_t i = 0; i < loopbackState->transitions.size(); i++) {
				ATNState* target = loopbackState->transitions[i]->target;
				auto plusBlock = dynamic_cast<PlusBlockStartState*>(target);
				if (plusBlock != nullptr)
					plusBlock->loopBackState = loopbackState;
			}
		else
		{
			StarLoopbackState* loopbackState = dynamic_cast<StarLoopbackState*>(state.get());
			if (loopbackState != nullptr)
				for (size_t i = 0; i < loopbackState->transitions.size(); i++) {
					ATNState* target = loopbackState->transitions[i]->target;
					auto starLoop = dynamic_cast<StarLoopEntryState*>(target);
					if (starLoop != nullptr)
						starLoop->loopBackState = loopbackState;
				}
		}
	}

	//
	// DECISIONS
	//
	size_t const ndecisions = data[p++];
	for (size_t i = 1; i <= ndecisions; i++) {
		size_t const s = data[p++];
		DecisionState* decState = dynamic_cast<DecisionState*>(atn.states[s].get());
		if (decState == nullptr)
			throw IllegalStateException();

		atn.decisionToState.push_back(decState);
		decState->decision = (int)i - 1;
	}

	//
	// LEXER ACTIONS
	//
	if (atn.grammarType == ATNType::LEXER) {
		if (supportsLexerActions) {
			atn.lexerActions.resize(data[p++]);
			for (size_t i = 0; i < atn.lexerActions.size(); i++) {
				LexerActionType const actionType = (LexerActionType)data[p++];
				int data1 = data[p++];
				if (data1 == 0xFFFF) {
					data1 = -1;
				}

				int data2 = data[p++];
				if (data2 == 0xFFFF) {
					data2 = -1;
				}

				atn.lexerActions[i] = lexerActionFactory(actionType, data1, data2);
			}
		}
		else {
			// for compatibility with older serialized ATNs, convert the old
			// serialized action index for action transitions to the new
			// form, which is the index of a LexerCustomAction
			for (auto& state : atn.states) {
				for (size_t i = 0; i < state->transitions.size(); i++) {
					Transition* transition = state->transitions[i];
					if (!is<ActionTransition*>(transition)) {
						continue;
					}

					size_t ruleIndex = dynamic_cast<ActionTransition*>(transition)->ruleIndex;
					size_t actionIndex = dynamic_cast<ActionTransition*>(transition)->actionIndex;
					Ref<LexerCustomAction> lexerAction = std::make_shared<LexerCustomAction>(ruleIndex, actionIndex);
					state->transitions[i] = new ActionTransition(transition->target, ruleIndex, atn.lexerActions.size(), false); /* mem-check freed in ATNState d-tor */
					delete transition; // ml: no longer needed since we just replaced it.
					atn.lexerActions.push_back(lexerAction);
				}
			}
		}
	}

	markPrecedenceDecisions(atn);

	if (deserializationOptions.isVerifyATN()) {
		verifyATN(atn);
	}

	if (deserializationOptions.isGenerateRuleBypassTransitions() && atn.grammarType == ATNType::PARSER) {
		atn.ruleToTokenType.resize(atn.ruleToStartState.size());
		for (size_t i = 0; i < atn.ruleToStartState.size(); i++) {
			atn.ruleToTokenType[i] = int(atn.maxTokenType + i + 1);
		}

		for (std::vector<RuleStartState*>::size_type i = 0; i < atn.ruleToStartState.size(); i++) {
			auto bs = std::make_unique<BasicBlockStartState>();
			bs->ruleIndex = (int)i;
			auto bypassStart = bs.get();
			atn.addState(std::move(bs));

			auto bst = std::make_unique<BlockEndState>(); /* mem check: freed in ATN d-tor */
			bst->ruleIndex = (int)i;
			auto bypassStop = bst.get();
			bypassStart->endState = bst.get();
			atn.defineDecisionState(bypassStart);

			bypassStop->startState = bypassStart;
			atn.addState(std::move(bst));

			ATNState* endState = nullptr;
			Transition* excludeTransition = nullptr;
			if (atn.ruleToStartState[i]->isLeftRecursiveRule) {
				// wrap from the beginning of the rule to the StarLoopEntryState
				endState = nullptr;
				for (auto& state : atn.states)
				{
					if (state->ruleIndex != i)
						continue;

					if (!is<StarLoopEntryState*>(state.get()))
						continue;

					ATNState* maybeLoopEndState = state->transitions[state->transitions.size() - 1]->target;
					if (!is<LoopEndState*>(maybeLoopEndState))
						continue;

					if (maybeLoopEndState->epsilonOnlyTransitions && is<RuleStopState*>(maybeLoopEndState->transitions[0]->target)) {
						endState = state.get();
						break;
					}
				}

				if (endState == nullptr)
					throw UnsupportedOperationException("Couldn't identify final state of the precedence rule prefix section.");

				excludeTransition = (dynamic_cast<StarLoopEntryState*>(endState))->loopBackState->transitions[0];
			}
			else
				endState = atn.ruleToStopState[i];

			// all non-excluded transitions that currently target end state need to target blockEnd instead
			for (auto& state : atn.states)
				for (Transition* transition : state->transitions) {
					if (transition == excludeTransition)
						continue;

					if (transition->target == endState)
						transition->target = bypassStop;
				}

			// all transitions leaving the rule start state need to leave blockStart instead
			while (atn.ruleToStartState[i]->transitions.size() > 0) {
				Transition* transition = atn.ruleToStartState[i]->removeTransition(atn.ruleToStartState[i]->transitions.size() - 1);
				bypassStart->addTransition(transition);
			}

			// link the new states
			atn.ruleToStartState[i]->addTransition(new EpsilonTransition(bypassStart));  /* mem check: freed in ATNState d-tor */
			bypassStop->addTransition(new EpsilonTransition(endState)); /* mem check: freed in ATNState d-tor */

			auto matchState = std::make_unique<BasicState>();
			auto x = matchState.get();
			atn.addState(std::move(matchState));
			x->addTransition(new AtomTransition(bypassStop, atn.ruleToTokenType[i])); /* mem check: freed in ATNState d-tor */
			bypassStart->addTransition(new EpsilonTransition(x)); /* mem check: freed in ATNState d-tor */
		}

		if (deserializationOptions.isVerifyATN()) {
			// reverify after modification
			verifyATN(atn);
		}
	}

	return atn;
}

/**
 * Analyze the {@link StarLoopEntryState} states in the specified ATN to set
 * the {@link StarLoopEntryState#isPrecedenceDecision} field to the
 * correct value.
 *
 * @param atn The ATN.
 */
void ATNDeserializer::markPrecedenceDecisions(const ATN& atn) {
	for (auto& state : atn.states) {
		if (!is<StarLoopEntryState*>(state.get())) {
			continue;
		}

		/* We analyze the ATN to determine if this ATN decision state is the
		 * decision for the closure block that determines whether a
		 * precedence rule should continue or complete.
		 */
		if (atn.ruleToStartState[state->ruleIndex]->isLeftRecursiveRule) {
			ATNState* maybeLoopEndState = state->transitions[state->transitions.size() - 1]->target;
			if (is<LoopEndState*>(maybeLoopEndState)) {
				if (maybeLoopEndState->epsilonOnlyTransitions && is<RuleStopState*>(maybeLoopEndState->transitions[0]->target)) {
					static_cast<StarLoopEntryState*>(state.get())->isPrecedenceDecision = true;
				}
			}
		}
	}
}

void ATNDeserializer::verifyATN(const ATN& atn) {
	// verify assumptions
	for (auto& state : atn.states) {
		if (state == nullptr) {
			continue;
		}

		checkCondition(state->epsilonOnlyTransitions || state->transitions.size() <= 1);
		auto const plusBlock = dynamic_cast<PlusBlockStartState*>(state.get());
		if (plusBlock != nullptr)
			checkCondition((plusBlock->loopBackState != nullptr));

		auto starLoop = dynamic_cast<StarLoopEntryState*>(state.get());
		if (starLoop != nullptr)
		{
			checkCondition(starLoop->loopBackState != nullptr);
			checkCondition(starLoop->transitions.size() == 2);

			auto const starBlock = dynamic_cast<StarBlockStartState*>(starLoop->transitions[0]->target);
			if (starBlock != nullptr)
			{
				checkCondition(starBlock != nullptr);
				checkCondition(!starLoop->nonGreedy);
			}
			else
				if (is<LoopEndState*>(starLoop->transitions[0]->target)) {
					checkCondition(is<StarBlockStartState*>(starLoop->transitions[1]->target));
					checkCondition(starLoop->nonGreedy);
				}
				else
					throw IllegalStateException();
		}

		if (is<StarLoopbackState*>(state.get())) {
			checkCondition(state->transitions.size() == 1);
			checkCondition(is<StarLoopEntryState*>(state->transitions[0]->target));
		}

		if (is<LoopEndState*>(state.get())) {
			checkCondition((static_cast<LoopEndState*>(state.get()))->loopBackState != nullptr);
		}

		if (is<RuleStartState*>(state.get())) {
			checkCondition((static_cast<RuleStartState*>(state.get()))->stopState != nullptr);
		}

		if (is<BlockStartState*>(state.get())) {
			checkCondition((static_cast<BlockStartState*>(state.get()))->endState != nullptr);
		}

		if (is<BlockEndState*>(state.get())) {
			checkCondition((static_cast<BlockEndState*>(state.get()))->startState != nullptr);
		}

		if (is<DecisionState*>(state.get())) {
			DecisionState* decisionState = static_cast<DecisionState*>(state.get());
			checkCondition(decisionState->transitions.size() <= 1 || decisionState->decision >= 0);
		}
		else {
			checkCondition(state->transitions.size() <= 1 || is<RuleStopState*>(state.get()));
		}
	}
}

void ATNDeserializer::checkCondition(bool condition) {
	checkCondition(condition, "");
}

void ATNDeserializer::checkCondition(bool condition, const std::string& message) {
	if (!condition) {
		throw IllegalStateException(message);
	}
}

Guid ATNDeserializer::toUUID(const unsigned short* data, size_t offset) {
	return Guid((uint16_t*)data + offset, true);
}

/* mem check: all created instances are freed in the d-tor of the ATNState they are added to. */
Transition* ATNDeserializer::edgeFactory(const ATN& atn, size_t type, size_t /*src*/, size_t trg, size_t arg1,
	size_t arg2, size_t arg3,
	const std::vector<misc::IntervalSet>& sets) {

	auto target = atn.states[trg].get();
	switch (type) {
	case Transition::EPSILON:
		return new EpsilonTransition(target);
	case Transition::RANGE:
		if (arg3 != 0)
			return new RangeTransition(target, Token::EOF, arg2);
		else
			return new RangeTransition(target, arg1, arg2);
	case Transition::RULE:
		return new RuleTransition(static_cast<RuleStartState*>(atn.states[arg1].get()), arg2, (int)arg3, target);
	case Transition::PREDICATE:
		return new PredicateTransition(target, arg1, arg2, arg3 != 0);
	case Transition::PRECEDENCE:
		return new PrecedencePredicateTransition(target, (int)arg1);
	case Transition::ATOM:
		if (arg3 != 0) {
			return new AtomTransition(target, Token::EOF);
		}
		else {
			return new AtomTransition(target, arg1);
		}
	case Transition::ACTION:
		return new ActionTransition(target, arg1, arg2, arg3 != 0);
	case Transition::SET:
		return new SetTransition(target, sets[arg1]);
	case Transition::NOT_SET:
		return new NotSetTransition(target, sets[arg1]);
	case Transition::WILDCARD:
		return new WildcardTransition(target);
	}

	throw IllegalArgumentException("The specified transition type is not valid.");
}

/* mem check: all created instances are freed in the d-tor of the ATN. */
std::unique_ptr<ATNState> ATNDeserializer::stateFactory(size_t type, size_t ruleIndex) {
	std::unique_ptr<ATNState> s;
	switch (type) {
	case ATNState::ATN_INVALID_TYPE:
		return nullptr;
	case ATNState::BASIC:
		s = std::make_unique<BasicState>();
		break;
	case ATNState::RULE_START:
		s = std::make_unique<RuleStartState>();
		break;
	case ATNState::BLOCK_START:
		s = std::make_unique<BasicBlockStartState>();
		break;
	case ATNState::PLUS_BLOCK_START:
		s = std::make_unique<PlusBlockStartState>();
		break;
	case ATNState::STAR_BLOCK_START:
		s = std::make_unique<StarBlockStartState>();
		break;
	case ATNState::TOKEN_START:
		s = std::make_unique<TokensStartState>();
		break;
	case ATNState::RULE_STOP:
		s = std::make_unique<RuleStopState>();
		break;
	case ATNState::BLOCK_END:
		s = std::make_unique<BlockEndState>();
		break;
	case ATNState::STAR_LOOP_BACK:
		s = std::make_unique<StarLoopbackState>();
		break;
	case ATNState::STAR_LOOP_ENTRY:
		s = std::make_unique<StarLoopEntryState>();
		break;
	case ATNState::PLUS_LOOP_BACK:
		s = std::make_unique<PlusLoopbackState>();
		break;
	case ATNState::LOOP_END:
		s = std::make_unique<LoopEndState>();
		break;
	default:
		std::string message = "The specified state type " + std::to_string(type) + " is not valid.";
		throw IllegalArgumentException(message);
	}

	s->ruleIndex = ruleIndex;
	return s;
}

Ref<LexerAction> ATNDeserializer::lexerActionFactory(LexerActionType type, int data1, int data2) {
	switch (type) {
	case LexerActionType::CHANNEL:
		return std::make_shared<LexerChannelAction>(data1);

	case LexerActionType::CUSTOM:
		return std::make_shared<LexerCustomAction>(data1, data2);

	case LexerActionType::MODE:
		return std::make_shared< LexerModeAction>(data1);

	case LexerActionType::MORE:
		return LexerMoreAction::getInstance();

	case LexerActionType::POP_MODE:
		return LexerPopModeAction::getInstance();

	case LexerActionType::PUSH_MODE:
		return std::make_shared<LexerPushModeAction>(data1);

	case LexerActionType::SKIP:
		return LexerSkipAction::getInstance();

	case LexerActionType::TYPE:
		return std::make_shared<LexerTypeAction>(data1);

	default:
		throw IllegalArgumentException("The specified lexer action type " + std::to_string(static_cast<size_t>(type)) +
			" is not valid.");
	}
}
