#pragma once
#include <map>
#include <cassert>
#include "IRuntimeValue.h"
#include "IComplexRuntimeValue.hpp"

namespace cMCompiler::dataStructures::execution
{
	class ObjectValue : public IRuntimeValue, public IComplexRuntimeValue
	{
		std::map<std::string, std::unique_ptr<IRuntimeValue>> values_;
		// Inherited via IRuntimeValue
		std::string typeName() const final
		{
			return "object";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		virtual std::string toString() const override;
		bool validate(IRuntimeValue* value, std::string const& name) const;
	public:
		ObjectValue(TypeReference t) noexcept : IRuntimeValue(t)
		{
		}

		std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) final
		{
			return ReferenceValue::make(&values_[name], getMemberType(name));
		}

		IRuntimeValue* getRawValue(std::string const& name)
		{
			return values_.at(name).get();
		}

		bool hasValue(std::string const& name)
		{
			return values_.contains(name);
		}

		TypeReference const& getMemberType(std::string const& name) const final;

		void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) final
		{
			assert(validate(value.get(), name));
			values_[name] = std::move(value);
		}

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;

		virtual ~ObjectValue() = default;
	};
}