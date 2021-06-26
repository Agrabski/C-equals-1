#include "LLVMIRUtility.hpp"
#include "../compilerInterfaceUtility.hpp"
#include "../FunctionExecutionUtility.hpp"
#include "../../LanguageLogic/MetatypeUility.hpp"
#include "../../DataStructures/execution/StringValue.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::compiler::llvmIntegration;

LLVMPackageIR cMCompiler::compiler::llvmIntegration::compileToLLVMIr(
	dataStructures::PackageDatabase& compiled,
	dataStructures::PackageDatabase& compilerInterface,
	std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& dependencies)
{
	auto entryPoint = getCompilerInterfaceEntryPoint(compilerInterface);

	std::vector<language::runtime_value> args;
	args.push_back(language::getValueFor(&compiled));
	args.push_back(language::getValueFor(dependencies));
	auto result = execute(entryPoint, std::move(args));
	return {language::dereferenceAs<dataStructures::execution::StringValue>(result.get())->value()};
}
