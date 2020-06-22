#pragma once
#include <ostream>
#include <functional>
#include "../Type.hpp"
#include "ExecutionContext.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IExpression
	{
	public:
		virtual void emmit(std::ostream& stream, INameGetter const& nameLookupFunction) const = 0;
		virtual bool compileTimeExecutable() const noexcept = 0;
		virtual Type* evaluateType() const noexcept = 0;
	};
}