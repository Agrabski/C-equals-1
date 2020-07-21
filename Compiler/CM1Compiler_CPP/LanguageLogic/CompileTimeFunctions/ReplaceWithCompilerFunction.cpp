#include "ReplaceWithCompilerFunction.hpp"
#include "CompileTimeFunctionDictionary.hpp"
#include "FunctionLibrary.hpp"
#include "../../DataStructures/execution/RuntimeFunctionDescriptor.hpp"

using namespace cMCompiler::language::compileTimeFunctions;

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>
cMCompiler::language::compileTimeFunctions::replaceWithCompilerFunction(
	std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
	std::map<std::string, not_null<dataStructures::Type*>> genericParameters
)
{
	auto& name = valueMap["name"];
	auto function = dynamic_cast<dataStructures::execution::RuntimeFunctionDescriptor*>( valueMap["function"].get());
	auto compileTimeFunction = functionMap[name->toString()];
	FuntionLibrary::instance().addFunctionDefinition(function->value(), compileTimeFunction);
	return nullptr;
}
