#pragma once
#include "../DataStructures/Type.hpp"
#include "../DataStructures/execution/WrapperTypeTranslation.hpp"
#include "../Utilities/pointer_cast.hpp"
#include "runtime_values.hpp"

namespace cMCompiler::language
{
	using value_map = std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>;
	using generic_parameters = std::map<std::string, not_null<dataStructures::Type*>>;



	gsl::not_null<dataStructures::Function*> createGetter(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type);
	template<typename T>
	gsl::not_null<dataStructures::Function*> createNativeObjectGetter(
		std::string const& name,
		gsl::not_null<dataStructures::Type*> type,
		dataStructures::TypeReference returnType,
		std::function<runtime_value(T*)> body)
	{
		auto f = createCustomFunction(
			type
			->append<dataStructures::Function>(name)
			->setReturnType(returnType),
			type,
			[body](auto&& a, auto b) -> runtime_value
			{
				auto self = dereferenceAs<dataStructures::execution::WrapperTypeTranslation<T>::WrapperType>(a["self"].get())->value();
				return body(utilities::toPointer(self));
			}
		);
		return f;
	}

	gsl::not_null<dataStructures::Function*> createCustomFunction(
		gsl::not_null<dataStructures::Function*> function,
		gsl::not_null<dataStructures::Type*> type,
		std::function<
		std::unique_ptr<dataStructures::execution::IRuntimeValue>(
			value_map&& valueMap,
			generic_parameters genericParameters)> body
	);

	void createIndexer(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type, dataStructures::TypeReference returnType);

	void createOperator(
		gsl::not_null<dataStructures::Namespace*> ns,
		std::string const& kind,
		dataStructures::TypeReference type1,
		dataStructures::TypeReference type2,
		dataStructures::TypeReference returnType,
		std::function<runtime_value(runtime_value& arg1, runtime_value& arg2)> body);


	void createOperator(
		gsl::not_null<dataStructures::Namespace*>ns,
		std::string const& kind,
		gsl::not_null<dataStructures::Type*> type,
		unsigned char refLevel,
		std::function<language::runtime_value(language::runtime_value& arg)> body);
}