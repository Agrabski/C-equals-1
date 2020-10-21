#include "GenericObject.hpp"

using namespace cMCompiler::dataStructures::generic;

not_null<GenericParameter*> cMCompiler::dataStructures::generic::GenericObject::pushParameter(std::string name)
{
	genericParameters_.push_back(std::make_unique<GenericParameter>(name));
	return genericParameters_.back().get();
}

std::vector<not_null<GenericParameter*>> cMCompiler::dataStructures::generic::GenericObject::getParameters()
{
	auto result = std::vector<not_null<GenericParameter*>>();
	for (auto const& param : genericParameters_)
		result.push_back(param.get());
	return result;
}
