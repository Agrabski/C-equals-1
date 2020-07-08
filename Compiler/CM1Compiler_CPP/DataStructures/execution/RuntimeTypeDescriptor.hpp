#pragma once
#include "IRuntimeValue.h"
#include "../Type.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"

namespace cMCompiler::dataStructures::execution
{
	class RuntimeTypeDescriptor : public IRuntimeValue
	{
		Type* value_;
		// Inherited via IRuntimeValue
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
		std::string toString() const final;
	public:
		RuntimeTypeDescriptor(Type* typeDescriptorType, Type* value) : IRuntimeValue(typeDescriptorType), value_(value) {}
		Type* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		virtual std::unique_ptr<IRuntimeValue> copy() const override;
	};
}
