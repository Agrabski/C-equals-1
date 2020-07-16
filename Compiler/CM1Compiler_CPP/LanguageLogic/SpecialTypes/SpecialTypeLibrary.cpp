#include "SpecialTypeLibrary.hpp"

cMCompiler::language::specialTypes::SpecialTypeLibrary& cMCompiler::language::specialTypes::SpecialTypeLibrary::instance()
{
	static SpecialTypeLibrary instance;
	return instance;
}

void cMCompiler::language::specialTypes::SpecialTypeLibrary::append(dataStructures::Type* type, std::string const& replaceWith)
{
	assert(!typeMap_.contains(type));
	typeMap_[type] = replaceWith;
}
