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
		bool value() const noexcept { return value_; }
		std::string typeName() const final;
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;
	};
}
