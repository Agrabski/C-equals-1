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
	T convert(runtime_value&& value) = delete;
	template<>
	inline dataStructures::TypeReference convert(runtime_value&& value)
	{
		not_null v = dereference(value.get());
		not_null typeReference = dynamic_cast<dataStructures::execution::RuntimeTypeDescriptor*>(v.get());
		return typeReference->value();
	}

	template<typename T>
	T executeGetter(std::unique_ptr<dataStructures::execution::IRuntimeValue>& object, std::string const& name)
	{
		std::unique_ptr<dataStructures::execution::IRuntimeValue> self;
		if (dynamic_cast<dataStructures::execution::ReferenceValue*>(object.get()) == nullptr)
			self = dataStructures::execution::ReferenceValue::make(&object, object->type());
		else
			self = object->copy();
		assert(self->type().referenceCount == 1);
		std::vector<runtime_value> params;
		params.push_back(std::move(self));
		auto methods = dereference(object.get())->type().type->methods();
		auto function = std::find_if(
			methods.begin(),
			methods.end(),
			[&](auto const& e) {return e->name() == name; });
		return convert<T>(compiler::execute(*function, std::move(params)));
	}
}