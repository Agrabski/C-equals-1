#include "TypeClassifier.hpp"
#include <map>

cMCompiler::dataStructures::TypeClassifier cMCompiler::dataStructures::parseType(std::string const& s)
{
	static auto const map_ = std::map<std::string, TypeClassifier>
	{
		{"class", TypeClassifier::Class},
		{"struct", TypeClassifier::Struct},
		{"interface", TypeClassifier::Interface},
	};
	return map_.find(s)->second;
}