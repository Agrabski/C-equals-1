#pragma once
#include "IRuntimeValue.h"
#include "IComplexRuntimeValue.hpp"
#include "../Type.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"
#include "ObjectValue.hpp"

namespace cMCompiler::dataStructures::execution
{
	class RuntimeTypeDescriptor : public IRuntimeValue, public IComplexRuntimeValue
	{
		Type* value_;
		// Inherited via IRuntimeValue
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
		std::string toString() const final;
	public:
		RuntimeTypeDescriptor(Type* typeDescriptorType, Type* value) noexcept: IRuntimeValue(typeDescriptorType), value_(value) {}
		Type* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		virtual std::unique_ptr<IRuntimeValue> copy() const override;

		// Inherited via IComplexRuntimeValue
		std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) final;
		virtual Type* getMemberType(std::string const& name) override;
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	};
}
