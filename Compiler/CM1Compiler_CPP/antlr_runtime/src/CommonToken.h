/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "Token.h"
#include "support/CPPUtils.h"

namespace antlr4
{

	class ANTLR4CPP_PUBLIC CommonToken : public Token {
	protected:
		/**
		 * This is the backing field for {@link #getType} and {@link #setType}.
		 */
		size_t _type = INVALID_TYPE;

		/**
		 * This is the backing field for {@link #getLine} and {@link #setLine}.
		 */
		size_t _line = 0ULL;

		/**
		 * This is the backing field for {@link #getCharPositionInLine} and
		 * {@link #setCharPositionInLine}.
		 */
		size_t _charPositionInLine = 0ULL; // set to invalid position

		/**
		 * This is the backing field for {@link #getChannel} and
		 * {@link #setChannel}.
		 */
		size_t _channel = DEFAULT_CHANNEL;

		/**
		 * This is the backing field for {@link #getText} when the token text is
		 * explicitly set in the constructor or via {@link #setText}.
		 *
		 * @see #getText()
		 */
		std::string _text;

		/**
		 * This is the backing field for {@link #getTokenIndex} and
		 * {@link #setTokenIndex}.
		 */
		size_t _index = INVALID_INDEX;

		/**
		 * This is the backing field for {@link #getStartIndex} and
		 * {@link #setStartIndex}.
		 */
		size_t _start = 0ULL;

		/**
		 * This is the backing field for {@link #getStopIndex} and
		 * {@link #setStopIndex}.
		 */
		size_t _stop = 0ULL;

	public:
		/**
		 * Constructs a new {@link CommonToken} with the specified token type.
		 *
		 * @param type The token type.
		 */
		CommonToken(size_t type) noexcept;
		CommonToken(size_t type, size_t channel, size_t start, size_t stop, size_t line, size_t charPositionInLine) noexcept;

		/**
		 * Constructs a new {@link CommonToken} with the specified token type and
		 * text.
		 *
		 * @param type The token type.
		 * @param text The text of the token.
		 */
		CommonToken(size_t type, const std::string& text);

		/**
		 * Constructs a new {@link CommonToken} as a copy of another {@link Token}.
		 *
		 * <p>
		 * If {@code oldToken} is also a {@link CommonToken} instance, the newly
		 * constructed token will share a reference to the {@link #text} field and
		 * the {@link Pair} stored in {@link #source}. Otherwise, {@link #text} will
		 * be assigned the result of calling {@link #getText}, and {@link #source}
		 * will be constructed from the result of {@link Token#getTokenSource} and
		 * {@link Token#getInputStream}.</p>
		 *
		 * @param oldToken The token to copy.
		 */
		CommonToken(not_null<Token*> oldToken);

		size_t getType() const override;

		/**
		 * Explicitly set the text for this token. If {code text} is not
		 * {@code null}, then {@link #getText} will return this value rather than
		 * extracting the text from the input.
		 *
		 * @param text The explicit text of the token, or {@code null} if the text
		 * should be obtained from the input along with the start and stop indexes
		 * of the token.
		 */
		void setText(const std::string& text);
		std::string getText() const override;
		std::string& getText() final;

		size_t getLine() const noexcept override;

		size_t getCharPositionInLine() const override;

		size_t getChannel() const noexcept override;

		size_t getStartIndex() const noexcept override;

		size_t getStopIndex() const noexcept override;

		size_t getTokenIndex() const noexcept override;

		std::string toString() const override;

		virtual std::string toString(Recognizer* r) const;
		std::unique_ptr<Token> clone() const override;

	private:
	};

} // namespace antlr4
