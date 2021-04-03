#pragma once
#include <list>
#include <gsl.h>
#include <memory>
#include "IRuntimeValue.h"
#include "IComplexRuntimeValue.hpp"

namespace cMCompiler::dataStructures::execution
{
	class ArrayValue : public IRuntimeValue, public IComplexRuntimeValue
	{
		TypeReference elementType_;

		std::list<std::unique_ptr<IRuntimeValue>> allocated_;

		// Inherited via IComplexRuntimeValue
		virtual std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) override;
		TypeReference const& getMemberType(std::string const& name) const final;
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	public:
		ArrayValue(TypeReference type, TypeReference elementType) :
			IRuntimeValue(type),
			elementType_(elementType)
		{}
		void push(std::unique_ptr<IRuntimeValue>&& value);
		std::unique_ptr<ReferenceValue> get(size_t index)
		{

			for (auto& e : allocated_)
			{
				if ((--index) == 0)
					return ReferenceValue::make(&(e), e->type());
			}
			std::terminate();
		}

		auto begin() noexcept
		{
			return allocated_.begin();
		}

		auto end() noexcept
		{
			return allocated_.end();
		}

		// Inherited via IRuntimeValue
		std::string typeName() const final
		{
			return "array_value";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
		std::string toString() const final;
		std::unique_ptr<IRuntimeValue> copy() const final;
	};
}