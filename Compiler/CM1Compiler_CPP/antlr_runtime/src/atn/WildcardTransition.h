/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "atn/Transition.h"

namespace antlr4 {
namespace atn {

  class ANTLR4CPP_PUBLIC WildcardTransition final : public Transition {
  public:
    WildcardTransition(ATNState *target);

    SerializationType getSerializationType() const noexcept override;

    bool matches(size_t symbol, size_t minVocabSymbol, size_t maxVocabSymbol) const override;

    std::string toString() const override;
  };

} // namespace atn
} // namespace antlr4
