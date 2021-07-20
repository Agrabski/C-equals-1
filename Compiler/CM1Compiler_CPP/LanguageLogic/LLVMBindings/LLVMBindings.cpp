#include "LLVMBindings.hpp"
#include"Module.hpp"
#include "../CreateGetter.hpp"
#include "../BuiltInPackageBuildUtility.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../TypeInstantiationUtility.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/CompilationResult.hpp"
#include "Function.hpp"
#include "Type.hpp"
#include "Types.hpp"
#include "Value.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::language;

not_null<Type*> buildCompilationResultDescriptor(
	gsl::not_null<Namespace*> backendNs,
	gsl::not_null<Type*> moduleDescriptor
)
{
	auto result = backendNs->append<Type>("compilationResult");
	auto f = createCustomFunction(
		result->append<Function>("appendModule"),
		result,
		[result, moduleDescriptor](auto&& parameters, auto) -> runtime_value
		{
			auto compilationResult = dereferenceAs<GenericRuntimeWrapper<CompilationResult>>(parameters["self"].get())->value();

			auto m = std::make_unique<llvm::Module>(
				dereferenceAs<StringValue>(parameters["moduleName"].get())->value(),
				compilationResult->llvmContext);

			auto resultModule = m.get();
			compilationResult->modules.push_back(std::move(m));
			return std::make_unique<GenericRuntimeWrapper<llvm::Module>>(resultModule, TypeReference{ moduleDescriptor, 0 });
		}
	);
	f->appendVariable("moduleName", { getString(), 0 });
	f->setReturnType({ moduleDescriptor, 0 });

	return result;
}

void cMCompiler::language::buildLLVMBindings(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	not_null backendNs = compilerNs->append<Namespace>("backend");

	auto type = buildTypeDescriptor(backendNs);

	auto llvmValue = buildValue(backendNs, type);

	auto function = buildFunctionDescriptor(backendNs, type, llvmValue);

	auto llvmModule = buildModuleDescriptor(backendNs, function, type);
	
	buildCompilationResultDescriptor(backendNs, llvmModule);
	buildTypeFunctions(backendNs, type, getCompilationResult());
}

runtime_value cMCompiler::language::getValueFor(llvm::Module* value)
{
	return std::make_unique<GenericRuntimeWrapper<llvm::Module>>(value, TypeReference{ getLLVMModuleDescriptor(), 0 });
}

runtime_value cMCompiler::language::getValueFor(dataStructures::CompilationResult*value)
{
	return std::make_unique<GenericRuntimeWrapper<dataStructures::CompilationResult>>(value, TypeReference{ getCompilationResult(), 0 });
}

not_null<Type*> cMCompiler::language::getLLVMModuleDescriptor()
{
	return getDefaultPackage()->rootNamespace()
		->get<Namespace>("compiler")
		->get<Namespace>("backend")
		->get<Type>("llvmModule");
}

not_null<Type*> cMCompiler::language::getCompilationResult()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("backend")->get<Type>("compilationResult");
}
