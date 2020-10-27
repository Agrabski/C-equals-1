#pragma once
#include <string>
#include "../Type.hpp"
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class StringValue : public IRuntimeValue
	{
		std::string value_;
		// Inherited via IRuntimeValue
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
	public:
		std::string toString() const final;
		StringValue(Type* type) noexcept : IRuntimeValue(type) {}
		std::string const& value() const noexcept { return value_; }
		void setValue(std::string const& value) { value_ = value; }

		// Inherited via IRuntimeValue
		virtual std::unique_ptr<IRuntimeValue> copy() const override;
	};
};