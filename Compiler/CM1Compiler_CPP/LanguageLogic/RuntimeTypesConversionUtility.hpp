#pragma once
#include <string>
#include <gsl.h>
#include "../DataStructures/SourcePointer.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"

namespace cMCompiler::language
{
	using gsl::not_null;

	[[nodiscard]]
	dataStructures::SourcePointer convertToSourcePointer(dataStructures::execution::IRuntimeValue& value);

	[[nodiscard]]
	std::string convertToString(dataStructures::execution::IRuntimeValue& value);

	template<typename T>
	[[nodiscard]]
	T convertToIntegral(dataStructures::execution::IRuntimeValue& value)
	{
		auto* integerValue = dynamic_cast<dataStructures::execution::IntegerValue*>(&value);
		if (integerValue == nullptr)
		{
			not_null reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(&value);
			integerValue = dynamic_cast<dataStructures::execution::IntegerValue*>(reference->value()->get());
			if (integerValue == nullptr)
				std::terminate();
		}
		return *reinterpret_cast<T*>(integerValue->rawNumber().get());
	}
}
