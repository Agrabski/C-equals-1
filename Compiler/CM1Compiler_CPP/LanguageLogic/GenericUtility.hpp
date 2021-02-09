#pragma once
#include "../DataStructures/Generic.hpp"
namespace cMCompiler::language
{
	template<typename T>
	std::string getGenericMangledName(dataStructures::Generic<T> const& g, std::vector<gsl::not_null<T*>> const& parameters)
	{
		auto result = (std::string)g.qualifiedName() + "<";
		for (auto const param : parameters)
			result += (std::string)param->qualifiedName() + ", ";
		if (parameters.size() > 0)
			result.erase(result.end() - 1);
		return result + ">";

	}
}