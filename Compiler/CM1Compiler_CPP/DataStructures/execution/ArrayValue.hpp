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
		gsl::not_null<Type*> elementType_;

		std::list<std::unique_ptr<IRuntimeValue>> allocated_;
		unsigned const char elementReferenceLevel_;

		// Inherited via IComplexRuntimeValue
		virtual std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) override;
		virtual Type* getMemberType(std::string const& name) override;
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	public:
		ArrayValue(gsl::not_null<Type*> type, gsl::not_null<Type*> elementType, unsigned char elementReferenceLevel) :
			IRuntimeValue(type),
			elementType_(elementType),
			elementReferenceLevel_(elementReferenceLevel)
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