#pragma once
#include <string>
#include <functional>
#include "../QualifiedName.hpp"
#include "INameGetter.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
}

namespace cMCompiler::dataStructures::ir
{
	class IInstruction
	{
	public:
		virtual void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const = 0;
		virtual bool compileTimeExecutable() const noexcept = 0;
	};
}