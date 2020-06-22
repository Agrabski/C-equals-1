#pragma once
#include <memory>
#include "../execution/IRuntimeValue.h"
#include "IExpression.hpp"

namespace cMCompiler::dataStructures::ir
{
	class ValueLiteralExpression : public IExpression
	{
		std::unique_ptr<execution::IRuntimeValue> value_;
	public:
		ValueLiteralExpression(std::unique_ptr<execution::IRuntimeValue>&& value) noexcept : value_(std::move(value)) {}
		void emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const final;
		bool compileTimeExecutable() const noexcept final;
		Type* evaluateType() const noexcept final;
	};
}
