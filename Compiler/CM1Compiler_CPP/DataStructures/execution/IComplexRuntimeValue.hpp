#pragma once
#include <memory>
#include <string>
#include <map>
#include <functional>
#include "ReferenceValue.hpp"


namespace cMCompiler::dataStructures::execution
{
	class IComplexRuntimeValue
	{
	public:
		virtual std::unique_ptr<ReferenceValue> getMemberValue(std::string const& name) = 0;

		virtual Type* getMemberType(std::string const& name) = 0;

		virtual void setValue(std::string const& name, std::unique_ptr<IRuntimeValue>&& value) = 0;
	};
}