#pragma once
#include <string>
#include <gsl/gsl>
#include "runtime_values.hpp"
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

	[[nodiscard]]
	runtime_value convertToCollection(std::vector<std::string> const& strings);

	[[nodiscard]]
	runtime_value convertToCollection(std::vector<runtime_value>&& values, dataStructures::TypeReference type);

	[[nodiscard]]
	runtime_value convertCollection(std::vector<runtime_value>&& collection, dataStructures::TypeReference elementType);


	[[nodiscard]]
	bool canCastReference(gsl::not_null<dataStructures::Type*> from, gsl::not_null<dataStructures::Type*> to);

	[[nodiscard]]
	dataStructures::execution::IRuntimeValue* dereference(not_null<dataStructures::execution::IRuntimeValue*>reference);

	[[nodiscard]]
	dataStructures::execution::IRuntimeValue* dereferenceOnce(not_null<dataStructures::execution::IRuntimeValue*>reference);


	template<typename T>
	[[nodiscard]]
	T* dereferenceAs(not_null<dataStructures::execution::IRuntimeValue*>reference)
	{
		auto v = dereference(reference);
		return dynamic_cast<T*>(v);
	}

	template<typename T>
	[[nodiscard]]
	T convertToIntegral(dataStructures::execution::IRuntimeValue& value)
	{
		not_null integerValue = dereferenceAs<dataStructures::execution::IntegerValue>(&value);
		return *reinterpret_cast<T*>(integerValue->rawNumber().get());
	}
}
