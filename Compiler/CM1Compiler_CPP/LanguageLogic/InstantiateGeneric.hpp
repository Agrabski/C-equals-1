#pragma once
#include "../DataStructures/Function.hpp"


namespace cMCompiler::language
{
	not_null<dataStructures::Function*> instantiate(
		dataStructures::Generic<dataStructures::Function> function,
		std::vector<not_null<dataStructures::Type*>> const& genericParameters);

	not_null<dataStructures::Type*> instantiate(
		dataStructures::Generic<dataStructures::Type>& type,
		std::vector<not_null<dataStructures::Type*>> const& genericParameters);
}