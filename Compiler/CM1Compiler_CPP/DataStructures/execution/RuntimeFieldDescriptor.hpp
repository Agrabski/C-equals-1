#pragma once
#include "IRuntimeValue.h"
#include "../Field.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"


namespace cMCompiler::dataStructures::execution
{
	class RuntimeFieldDescriptor : public IRuntimeValue
	{
		Field* value_;
		// Inherited via IRuntimeValue
		std::string typeName() const final
		{
			return "runtime_type";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		std::string toString() const final;
	public:
		RuntimeFieldDescriptor(Type* descriptorType, Field* value) noexcept : IRuntimeValue(descriptorType), value_(value) {}
		Field* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}
