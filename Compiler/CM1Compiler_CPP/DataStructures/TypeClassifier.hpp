#pragma once
#include <string>

namespace cMCompiler::dataStructures
{
	enum class TypeClassifier { Class, Struct, Interface, None };
	TypeClassifier parseType(std::string const& s);
}
