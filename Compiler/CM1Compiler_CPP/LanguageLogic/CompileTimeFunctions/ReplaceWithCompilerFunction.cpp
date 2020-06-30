#include "ReplaceWithCompilerFunction.hpp"
#include "CompileTimeFunctionDictionary.hpp"
#include "FunctionLibrary.hpp"
#include "../../DataStructures/execution/RuntimeFunctionDescriptor.hpp"

using namespace cMCompiler::language::compileTimeFunctions;

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>
cMCompiler::language::compileTimeFunctions::replaceWithCompilerFunction(std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap)
{
	auto name = valueMap["name"];
	auto function = dynamic_cast<dataStructures::execution::RuntimeFunctionDescriptor*>( valueMap["function"]);
	auto compileTimeFunction = functionMap[name->toString()];
	FuntionLibrary::instance().addFunctionDefinition(function->value(), compileTimeFunction);
	return nullptr;
}
