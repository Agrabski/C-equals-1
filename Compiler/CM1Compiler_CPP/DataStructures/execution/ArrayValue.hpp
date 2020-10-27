#pragma once
#include <list>
#include "IRuntimeValue.h"
#include "IComplexRuntimeValue.hpp"

namespace cMCompiler::dataStructures::execution
{
	class ArrayValue : public IRuntimeValue, public IComplexRuntimeValue
	{
		std::list<std::unique_ptr<IRuntimeValue>> allocated_;

		// Inherited via IComplexRuntimeValue
		virtual std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) override;
		virtual Type* getMemberType(std::string const& name) override;
		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) override;
	};
}