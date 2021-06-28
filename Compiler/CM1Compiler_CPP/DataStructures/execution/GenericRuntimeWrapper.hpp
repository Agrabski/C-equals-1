#pragma once
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	template<typename T>
	class GenericRuntimeWrapper : public IRuntimeValue
	{
		T* value_;
		// Inherited via IRuntimeValue
		virtual std::string typeName() const override
		{
			// todo: maybe implement?
			std::terminate();
		}
		virtual json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const override
		{
			// todo: maybe implement?
			std::terminate();
		}
		virtual std::string toString() const override
		{
			std::stringstream result;
			result << "[native object at: ";
			result << value_;
			result << "]";
			return result.str();
		}
		virtual std::unique_ptr<IRuntimeValue> copy() const override
		{
			return std::make_unique<GenericRuntimeWrapper<T>>(value_, type());
		}
	public:
		GenericRuntimeWrapper(T* value, TypeReference type) : value_(value), IRuntimeValue(type) {}
		T* value() const noexcept { return value_; }

	};
}