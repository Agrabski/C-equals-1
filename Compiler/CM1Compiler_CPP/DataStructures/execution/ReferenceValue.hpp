#pragma once
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class ReferenceValue : public IRuntimeValue
	{
		std::unique_ptr<IRuntimeValue>* value_;
		std::function<void(ReferenceValue&)> dealocator_;
	public:
		ReferenceValue(std::unique_ptr<IRuntimeValue>* value, Type* type, std::function<void(ReferenceValue&)> dealocator) noexcept :
			IRuntimeValue(type),
			value_(value),
			dealocator_(dealocator) {}
		template<typename T>
		ReferenceValue(std::unique_ptr<T>* value, Type type) : IRuntimeValue(type)
		{
			value_ = static_cast<std::unique_ptr<IRuntimeValue>*>(value);
		}
		std::unique_ptr<IRuntimeValue>* value() const noexcept { return value_; }
		static std::unique_ptr<ReferenceValue> make(std::unique_ptr<IRuntimeValue>* value, Type* type)
		{
			return std::make_unique<ReferenceValue>(value, type, std::function<void(ReferenceValue&)>());
		}


		// Inherited via IRuntimeValue
		std::string typeName() const final;
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;

		virtual std::string toString() const override;

		virtual std::unique_ptr<IRuntimeValue> copy() const override;
		void performAssigment(std::unique_ptr<IRuntimeValue>&& newValue);

		~ReferenceValue()
		{
			if (dealocator_)
				dealocator_(*this);
		}

	};
}