/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#include "TokenSource.h"
#include "CharStream.h"
#include "Recognizer.h"
#include "Vocabulary.h"

#include "misc/Interval.h"

#include "support/StringUtils.h"
#include "support/CPPUtils.h"

#include "CommonToken.h"

using namespace antlr4;
using namespace antlr4::misc;

using namespace antlrcpp;

CommonToken::CommonToken(size_t type) noexcept
{
	_type = type;
}

CommonToken::CommonToken(size_t type, size_t channel, size_t start, size_t stop, size_t line, size_t charPositionInLine) noexcept
{
	_type = type;
	_channel = channel;
	_start = start;
	_stop = stop;
	_line = line;
	_charPositionInLine = charPositionInLine;
}

CommonToken::CommonToken(size_t type, const std::string& text)
{
	_type = type;
	_channel = DEFAULT_CHANNEL;
	_text = text;
}

CommonToken::CommonToken(not_null<Token*>  oldToken) {
	_type = oldToken->getType();
	_line = oldToken->getLine();
	_index = oldToken->getTokenIndex();
	_charPositionInLine = oldToken->getCharPositionInLine();
	_channel = oldToken->getChannel();
	_start = oldToken->getStartIndex();
	_stop = oldToken->getStopIndex();

	if (is<CommonToken*>(oldToken)) {
		_text = (static_cast<CommonToken*>(oldToken.get()))->_text;
	}
}

size_t CommonToken::getType() const {
	return _type;
}

std::string CommonToken::getText() const
{
	return _text;
}

void CommonToken::setText(const std::string& text)
{
	_text = text;
}

size_t CommonToken::getLine() const noexcept
{
	return _line;
}

size_t CommonToken::getCharPositionInLine() const
{
	return _charPositionInLine;
}

size_t CommonToken::getChannel() const noexcept
{
	return _channel;
}

size_t CommonToken::getStartIndex() const noexcept
{
	return _start;
}

size_t CommonToken::getStopIndex() const noexcept
{
	return _stop;
}

size_t CommonToken::getTokenIndex() const noexcept
{
	return _index;
}

std::string CommonToken::toString() const {
	return toString(nullptr);
}

std::string CommonToken::toString(Recognizer* r) const {
	std::stringstream ss;

	std::string channelStr;
	if (_channel > 0) {
		channelStr = ",channel=" + std::to_string(_channel);
	}
	std::string txt = getText();
	if (!txt.empty()) {
		antlrcpp::replaceAll(txt, "\n", "\\n");
		antlrcpp::replaceAll(txt, "\r", "\\r");
		antlrcpp::replaceAll(txt, "\t", "\\t");
	}
	else {
		txt = "<no text>";
	}

	std::string typeString = std::to_string(symbolToNumeric(_type));
	if (r != nullptr)
		typeString = r->getVocabulary().getDisplayName(_type);

	ss << "[@" << symbolToNumeric(getTokenIndex()) << "," << symbolToNumeric(_start) << ":" << symbolToNumeric(_stop)
		<< "='" << txt << "',<" << typeString << ">" << channelStr << "," << _line << ":"
		<< getCharPositionInLine() << "]";

	return ss.str();
}

std::unique_ptr<Token> antlr4::CommonToken::clone() const
{
	return std::make_unique<CommonToken>(*this);
}
