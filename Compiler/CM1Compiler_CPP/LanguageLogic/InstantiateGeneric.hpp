#pragma once
#include "../DataStructures/Function.hpp"


namespace cMCompiler::language
{
	not_null<dataStructures::Function*> instantiate(
		dataStructures::Generic<dataStructures::Function> function,
		std::vector<cMCompiler::dataStructures::TypeReference> const& genericParameters);

	not_null<dataStructures::Type*> instantiate(
		dataStructures::Generic<dataStructures::Type> const& type,
		std::vector<cMCompiler::dataStructures::TypeReference> const& genericParameters);
}