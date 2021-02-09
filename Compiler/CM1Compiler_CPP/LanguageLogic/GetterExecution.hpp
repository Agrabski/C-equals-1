#pragma once
#include <gsl.h>
#include <string>
#include "runtime_values.hpp"
#include "NameResolver.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"

namespace cMCompiler::compiler
{
	extern 	std::unique_ptr<dataStructures::execution::IRuntimeValue> execute
	(
		gsl::not_null<dataStructures::Function*> functionDefinition,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap
	);
}

namespace cMCompiler::language
{
	template<typename T>
	gsl::not_null<T*> convert(runtime_value&& value) = delete;
	template<>
	gsl::not_null<dataStructures::Type*> convert(runtime_value&& value)
	{
		not_null reference = dynamic_cast<dataStructures::execution::ReferenceValue*>(value.get());
		not_null typeReference = dynamic_cast<dataStructures::execution::RuntimeTypeDescriptor*>(reference->value()->get());
		return typeReference->value();
	}

	template<typename T>
	gsl::not_null<T*> executeGetter(std::unique_ptr<dataStructures::execution::IRuntimeValue>& object, std::string const& name)
	{
		auto self = utilities::pointer_cast<dataStructures::execution::IRuntimeValue>(
			std::make_unique<dataStructures::execution::ReferenceValue>(&object, object->type()));
		std::vector<runtime_value> params;
		params.push_back(std::move(self));
		auto methods = object->type()->methods();
		auto function = std::find_if(
			methods.begin(),
			methods.end(),
			[&](auto const& e) {return e->name() == name; });
		return convert<T>(compiler::execute(*function, std::move(params)));
	}
}