/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "misc/Interval.h"
#include "CommonToken.h"
#include "CharStream.h"

#include "CommonTokenFactory.h"

using namespace antlr4;

const Ref<TokenFactory<CommonToken>> CommonTokenFactory::DEFAULT = std::make_shared<CommonTokenFactory>();

CommonTokenFactory::CommonTokenFactory(bool copyText_) : copyText(copyText_) {
}

CommonTokenFactory::CommonTokenFactory() : CommonTokenFactory(false) {
}

std::unique_ptr<CommonToken> CommonTokenFactory::create(size_t type,
	const std::string& text, size_t channel, size_t start, size_t stop, size_t line, size_t charPositionInLine) {

	auto t = std::make_unique<CommonToken>(type, channel, start, stop, line, charPositionInLine);
	if (text != "")
	{
		t->setText(text);
	}
	return t;
}

std::unique_ptr<CommonToken> CommonTokenFactory::create(size_t type, const std::string& text) {
	return std::make_unique<CommonToken>(type, text);
}
