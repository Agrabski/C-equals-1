#include "GenericUtility.hpp"
#include <sstream>

std::string cMCompiler::language::getGenericMangledName(std::string const& name, std::vector<cMCompiler::dataStructures::TypeReference> const& parameters)
{
	std::stringstream stream;
	stream << name << "<";
	for (auto const param : parameters)
		stream << param << ",";
	auto result = stream.str();
	if (parameters.size() > 0)
		result.erase(result.end() - 1);
	return result + ">";

}