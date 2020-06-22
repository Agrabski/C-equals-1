#include "FunctionLibrary.hpp"
#include "../AttributeUtility.hpp"
using namespace cMCompiler::language::compileTimeFunctions;

FuntionLibrary& cMCompiler::language::compileTimeFunctions::FuntionLibrary::instance()
{
	static FuntionLibrary result;
	return result;
}

std::optional<compileTimeFunction> cMCompiler::language::compileTimeFunctions::FuntionLibrary::getFunction(gsl::not_null<dataStructures::Function*> functionDefinition)
{
	assert(isCompileTime(*functionDefinition));
	auto function = functions_.find(functionDefinition);
	if (function != functions_.end())
		return function->second;
	return std::optional<compileTimeFunction>();
}

void cMCompiler::language::compileTimeFunctions::FuntionLibrary::addFunctionDefinition(gsl::not_null<dataStructures::Function*> definition, compileTimeFunction function)
{
	assert(isCompileTime(*definition));
	assert(!functions_.contains(definition));
	functions_[definition] = function;
}
