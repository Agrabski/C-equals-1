#pragma once
#include "IRuntimeValue.h"
#include "IComplexRuntimeValue.hpp"
#include "../Type.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"
#include "ObjectValue.hpp"
#include "../ISerializationManager.hpp"

namespace cMCompiler::dataStructures::execution
{
	class RuntimeVariableDescriptor : public IRuntimeValue, public IComplexRuntimeValue
	{
		Variable* value_;
		// Inherited via IRuntimeValue
		std::string typeName() const final;
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		std::string toString() const final;
	public:
		RuntimeVariableDescriptor(Type* typeDescriptorType, Variable* value) noexcept : IRuntimeValue(typeDescriptorType), value_(value) {}
		Variable* value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		virtual std::unique_ptr<IRuntimeValue> copy() const override;

		// Inherited via IComplexRuntimeValue
		std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) final;
		virtual Type* getMemberType(std::string const& name) override;
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	};
}