#pragma once
#include <map>
#include <cassert>
#include "IRuntimeValue.h"

namespace cMCompiler::dataStructures::execution
{
	class BooleanValue : public IRuntimeValue
	{
		bool value_;
	public:
		BooleanValue(TypeReference type) noexcept : IRuntimeValue(type) {}
		std::string toString() const final;
		std::unique_ptr<IRuntimeValue> copy() const final;
		bool value() const noexcept { return value_; }
		bool value(bool value) noexcept { return value_ = value; }
		std::string typeName() const final;
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
	};
}
