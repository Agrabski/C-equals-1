#include "SpecialFunctionUtility.hpp"

cMCompiler::dataStructures::Function* cMCompiler::language::getFinalizer(gsl::not_null<dataStructures::Type*> type)
{
	auto functions = type->methods();
	auto result = std::find_if(functions.begin(), functions.end(), [](auto const& e) {return e->name() == "finalize"; });
	if (result != functions.end())
		return *result;
	return nullptr;
}
