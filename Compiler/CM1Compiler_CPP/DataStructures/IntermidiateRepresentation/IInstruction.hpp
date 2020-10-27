#pragma once
#include <string>
#include <functional>
#include <memory>
#include <gsl.h>
#include "../execution/IRuntimeValue.h"
#include "../QualifiedName.hpp"
#include "INameGetter.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
}

namespace cMCompiler::dataStructures::ir
{
	class IInstructionVisitor;
	class IInstruction
	{
		std::unique_ptr<execution::IRuntimeValue> pointerToSource_;
	public:
		IInstruction(std::unique_ptr<execution::IRuntimeValue>&&pointer) : pointerToSource_(std::move(pointer))
		{}
		gsl::not_null<execution::IRuntimeValue*> pointerToSource() noexcept { return pointerToSource_.get(); }
		virtual void emmit(std::ostream& stream, INameGetter const& nameLookupFunction, unsigned int indentationLevel) const = 0;
		virtual bool compileTimeExecutable() const noexcept = 0;
		virtual void accept(IInstructionVisitor& visitor) = 0;
	};
}