#pragma once
#include <string>

namespace cMCompiler::dataStructures::ir
{
	class IInstruction
	{
	public:
		virtual std::string toString() const = 0;
		virtual bool compileTimeExecutable() const noexcept = 0;
	};
}