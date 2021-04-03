#pragma once
#include "../DataStructures/Generic.hpp"
namespace cMCompiler::language
{
	template<typename T>
	std::string getGenericMangledName(dataStructures::Generic<T> const& g, std::vector<cMCompiler::dataStructures::TypeReference> const& parameters)
	{
		std::stringstream stream;
		stream << g.qualifiedName() << "<";
		for (auto const param : parameters)
			stream << param << ",";
		auto result = stream.str();
		if (parameters.size() > 0)
			result.erase(result.end() - 1);
		return result + ">";

	}
}