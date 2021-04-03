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
		TypeReference value_;
		// Inherited via IRuntimeValue
		std::string typeName() const final;
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		std::string toString() const final;
	public:
		RuntimeTypeDescriptor(TypeReference typeDescriptorType, TypeReference value) noexcept: IRuntimeValue(typeDescriptorType), value_(value) {}
		TypeReference const& value() const noexcept { return value_; }

		// Inherited via IRuntimeValue
		virtual std::unique_ptr<IRuntimeValue> copy() const override;

		// Inherited via IComplexRuntimeValue
		std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) final;
		TypeReference& getMemberType(std::string const& name) const final
		{
			std::terminate();
		}
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	};
}
