#pragma once
#include "IRuntimeValue.h"
#include "../InvalidTypeException.hpp"

namespace cMCompiler::dataStructures::execution
{
	class ReferenceValue : public IRuntimeValue
	{
		std::unique_ptr<IRuntimeValue>* value_;
		std::function<void(ReferenceValue&)> dealocator_;
	public:
		ReferenceValue(std::unique_ptr<IRuntimeValue>* value, TypeReference type, std::function<void(ReferenceValue&)> dealocator) :
			IRuntimeValue(type),
			value_(value),
			dealocator_(dealocator)
		{
			if ((
				value != nullptr &&
				value->get() != nullptr &&
				value->get()->type().referenceCount != (type.referenceCount - 1)))
				throw InvalidTypeException({ type.type, type.referenceCount - 1 }, value->get()->type());
		}
		template<typename T>
		ReferenceValue(std::unique_ptr<T>* value, TypeReference type) : IRuntimeValue(type)
		{
			assert(
				value == nullptr ||
				value->get() == nullptr ||
				value->get()->type().referenceCount == (type.referenceCount - 1));
			value_ = static_cast<std::unique_ptr<IRuntimeValue>*>(value);
		}
		std::unique_ptr<IRuntimeValue>* value() const noexcept { return value_; }
		static std::unique_ptr<ReferenceValue> make(std::unique_ptr<IRuntimeValue>* value, TypeReference type)
		{
			type.referenceCount += 1;
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