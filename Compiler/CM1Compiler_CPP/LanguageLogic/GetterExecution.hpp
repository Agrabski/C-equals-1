#pragma once
#include <gsl.h>
#include <string>
#include "runtime_values.hpp"
#include "NameResolver.hpp"
#include "RuntimeTypesConversionUtility.hpp"
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
	inline gsl::not_null<dataStructures::Type*> convert(runtime_value&& value)
	{
		not_null v = dereference(value.get());
		not_null typeReference = dynamic_cast<dataStructures::execution::RuntimeTypeDescriptor*>(v.get());
		return typeReference->value();
	}

	template<typename T>
	gsl::not_null<T*> executeGetter(std::unique_ptr<dataStructures::execution::IRuntimeValue>& object, std::string const& name)
	{
		std::unique_ptr<dataStructures::execution::IRuntimeValue> self;
		if (dynamic_cast<dataStructures::execution::ReferenceValue*>(object.get()) == nullptr)
			self = dataStructures::execution::ReferenceValue::make(&object, object->type());
		else
			self = object->copy();
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