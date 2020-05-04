/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

#pragma once

#include "atn/AbstractPredicateTransition.h"
#include "SemanticContext.h"

namespace antlr4 {
namespace atn {

  class ANTLR4CPP_PUBLIC PrecedencePredicateTransition final : public AbstractPredicateTransition {
  public:
    const int precedence;

    PrecedencePredicateTransition(ATNState *target, int precedence);

    SerializationType getSerializationType() const noexcept override;
    bool isEpsilon() const override;
    bool matches(size_t symbol, size_t minVocabSymbol, size_t maxVocabSymbol) const override;
    Ref<SemanticContext::PrecedencePredicate> getPredicate() const;
    std::string toString() const override;

  };

} // namespace atn
} // namespace antlr4
