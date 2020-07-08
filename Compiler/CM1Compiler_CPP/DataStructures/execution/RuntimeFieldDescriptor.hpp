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
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
		std::string toString() const final;
	public:
		RuntimeFieldDescriptor(Type* descriptorType, Field* value) noexcept : IRuntimeValue(descriptorType), value_(value) {}
		Field* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}
