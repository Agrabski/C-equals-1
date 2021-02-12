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
		std::string typeName() const final
		{
			return "runtime_function_descriptor";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		std::string toString() const final;
	public:
		RuntimeFunctionDescriptor(Type* descriptorType, Function* value) noexcept : IRuntimeValue(descriptorType), value_(value) {}
		Function* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}
