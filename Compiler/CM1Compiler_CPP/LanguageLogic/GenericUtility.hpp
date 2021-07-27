#pragma once
#include <concepts>
#include "../DataStructures/Generic.hpp"
#include "../DataStructures/INamedObject.hpp"

namespace cMCompiler::language
{
	std::string getGenericMangledName(std::string const& name, std::vector<cMCompiler::dataStructures::TypeReference> const& parameters);


	template<typename T>
	std::string getGenericMangledName(
		dataStructures::Generic<T> const& g,
		std::vector<cMCompiler::dataStructures::TypeReference> const& parameters) requires std::derived_from<T, dataStructures::INamedObject>
	{
		return getGenericMangledName(g.name(), parameters);

	}

}