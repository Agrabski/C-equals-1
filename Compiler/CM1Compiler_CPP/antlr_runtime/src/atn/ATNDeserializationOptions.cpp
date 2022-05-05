/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "ATNDeserializationOptions.h"

using namespace antlr4::atn;

ATNDeserializationOptions ATNDeserializationOptions::defaultOptions;

ATNDeserializationOptions::ATNDeserializationOptions(ATNDeserializationOptions* options) : ATNDeserializationOptions() {
	this->verifyATN = options->verifyATN;
	this->generateRuleBypassTransitions = options->generateRuleBypassTransitions;
}

ATNDeserializationOptions::~ATNDeserializationOptions() {
}

const ATNDeserializationOptions& ATNDeserializationOptions::getDefaultOptions() noexcept {
	return defaultOptions;
}


void ATNDeserializationOptions::makeReadOnly() {
	readOnly = true;
}

void ATNDeserializationOptions::setVerifyATN(bool verify) {
	throwIfReadOnly();
	verifyATN = verify;
}

void ATNDeserializationOptions::setGenerateRuleBypassTransitions(bool generate) {
	throwIfReadOnly();
	generateRuleBypassTransitions = generate;
}

void ATNDeserializationOptions::throwIfReadOnly() {
	if (isReadOnly()) {
		throw "The object is read only.";
	}
}
