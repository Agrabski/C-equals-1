/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "atn/Transition.h"

namespace antlr4 {
namespace atn {

  /// <summary>
  /// A transition containing a set of values. </summary>
  class ANTLR4CPP_PUBLIC SetTransition : public Transition {
  public:
    const misc::IntervalSet set;

    SetTransition(ATNState *target, const misc::IntervalSet &set);

    SerializationType getSerializationType() const noexcept override;

    misc::IntervalSet label() const override;
    bool matches(size_t symbol, size_t minVocabSymbol, size_t maxVocabSymbol) const override;

    std::string toString() const override;
  };

} // namespace atn
} // namespace antlr4
