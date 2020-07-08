#pragma once
#include "IRuntimeValue.h"
#include "../Function.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"


namespace cMCompiler::dataStructures::execution
{
	class RuntimeFunctionDescriptor : public IRuntimeValue
	{
		Function* value_;
		// Inherited via IRuntimeValue
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
		std::string toString() const final;
	public:
		RuntimeFunctionDescriptor(Type* descriptorType, Function* value) noexcept : IRuntimeValue(descriptorType), value_(value) {}
		Function* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}
