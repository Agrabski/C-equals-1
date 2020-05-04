/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "antlr4-common.h"

namespace antlr4 {
	namespace atn {

		class ANTLR4CPP_PUBLIC ATNDeserializationOptions {
		private:
			static ATNDeserializationOptions defaultOptions;

			bool readOnly =false;
			bool verifyATN = true;
			bool generateRuleBypassTransitions = false;

		public:
			constexpr ATNDeserializationOptions() noexcept = default;
			ATNDeserializationOptions(ATNDeserializationOptions* options);
			ATNDeserializationOptions(ATNDeserializationOptions const&) = default;
			virtual ~ATNDeserializationOptions();
			ATNDeserializationOptions& operator=(ATNDeserializationOptions const&) = default;

			static const ATNDeserializationOptions& getDefaultOptions() noexcept;

			constexpr bool isReadOnly() const noexcept
			{
				return readOnly;
			}

			void makeReadOnly();

			constexpr bool isVerifyATN() const noexcept
			{
				return verifyATN;
			}

			void setVerifyATN(bool verify);

			constexpr bool isGenerateRuleBypassTransitions() const noexcept
			{
				return generateRuleBypassTransitions;
			}

			void setGenerateRuleBypassTransitions(bool generate);

		protected:
			virtual void throwIfReadOnly();

		private:
		};

	} // namespace atn
} // namespace antlr4
