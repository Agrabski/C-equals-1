#pragma once
#include "GenericRuntimeWrapper.hpp"


namespace cMCompiler::dataStructures::execution
{
	template<typename T>
	class GenericOwningRuntimeWrapper : public GenericRuntimeWrapper<T>
	{
		std::shared_ptr<T> ownedValue_;
	public:
		GenericOwningRuntimeWrapper(std::shared_ptr<T> value, TypeReference type) : GenericRuntimeWrapper<T>(value.get(), type), ownedValue_(value) {}
		virtual std::unique_ptr<IRuntimeValue> copy() const override
		{
			return std::make_unique<GenericOwningRuntimeWrapper<T>>(ownedValue_, IRuntimeValue::type());
		}

	};
}
