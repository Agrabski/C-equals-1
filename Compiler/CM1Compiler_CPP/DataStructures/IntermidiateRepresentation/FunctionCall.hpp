#pragma once
#include "IInstruction.hpp"
#include "IExpression.hpp"
#include "../Function.hpp"

namespace cMCompiler::dataStructures::ir
{
	class FunctionCall : IInstruction, IExpression
	{
		Function* function_;
	public:
		bool compileTimeExecutable() const noexcept final;
		Type* evaluateType() const noexcept final;
	};
}
