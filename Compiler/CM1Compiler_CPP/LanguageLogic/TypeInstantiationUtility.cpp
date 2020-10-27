#include "TypeInstantiationUtility.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::language::instantiate(gsl::not_null<cMCompiler::dataStructures::Type*>t)
{
	//todo: finish
	return std::make_unique<dataStructures::execution::ObjectValue>(t);
}
