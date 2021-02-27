#pragma once
#include "../DataStructures/Type.hpp"

namespace cMCompiler::language
{
	using value_map = std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>;
	using generic_parameters = std::map<std::string, not_null<dataStructures::Type*>>;

	gsl::not_null<dataStructures::Function*> createGetter(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type);

	gsl::not_null<dataStructures::Function*> createCustomFunction(
		gsl::not_null<dataStructures::Function*> function,
		gsl::not_null<dataStructures::Type*> type,
		std::function< 
			std::unique_ptr<dataStructures::execution::IRuntimeValue>(
				value_map&& valueMap,
				generic_parameters genericParameters)> body
	);

	void createIndexer(gsl::not_null<dataStructures::Function*> function, gsl::not_null<dataStructures::Type*> type, gsl::not_null<dataStructures::Type*> returnType);
}