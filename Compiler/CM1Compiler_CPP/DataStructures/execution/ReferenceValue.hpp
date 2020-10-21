#pragma once
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class ReferenceValue : public IRuntimeValue
	{
		std::unique_ptr<IRuntimeValue>* value_;
	public:
		ReferenceValue(std::unique_ptr<IRuntimeValue>* value, Type* type) noexcept : IRuntimeValue(type), value_(value) {}
		std::unique_ptr<IRuntimeValue>* value() const noexcept { return value_; }


		// Inherited via IRuntimeValue
		virtual void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const override;

		virtual std::string toString() const override;

		virtual std::unique_ptr<IRuntimeValue> copy() const override;
		void performAssigment(std::unique_ptr<IRuntimeValue>&& newValue);

	};
}