#pragma once
#include <ostream>
#include <functional>
#include "../Type.hpp"

namespace cMCompiler::dataStructures::ir
{
	class IExpression
	{
	public:
		virtual void emmit(std::ostream& stream, std::function<QualifiedName(Type*)> nameLookupFunction) const = 0;
		virtual bool compileTimeExecutable() const noexcept = 0;
		virtual Type* evaluateType() const noexcept = 0;
	};
}