#include "Types.hpp"
#include <llvm/IR/Type.h>
#include <llvm/IR/Module.h>
#include "../RuntimeTypesConversionUtility.hpp"
#include "../CompileTimeFunctions/FunctionLibrary.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/CompilationResult.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;

void cMCompiler::language::buildTypeFunctions(not_null<Namespace*> backendNs, not_null<Type*> llvmType, not_null<Type*> compilationResult)
{
	auto f = backendNs->append<Function>("llvmVoidType");
	f->setReturnType({ llvmType, 0 });
	f->appendVariable("compilationResult", { compilationResult, 0 });

	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(f, [llvmType](auto&&params, auto)
		{
			auto cr = dereferenceAs<GenericRuntimeWrapper<CompilationResult>>(params["compilationResult"].get())->value();
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(llvm::Type::getVoidTy(cr->llvmContext), TypeReference{ llvmType, 0 });
		});

	auto g = backendNs->append<Function>("llvmInt32Type");
	g->setReturnType({ llvmType, 0 });
	g->appendVariable("compilationResult", { compilationResult, 0 });

	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(g, [llvmType](auto&& params, auto)
		{
			auto cr = dereferenceAs<GenericRuntimeWrapper<CompilationResult>>(params["compilationResult"].get())->value();
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(llvm::Type::getInt32Ty(cr->llvmContext), TypeReference{ llvmType, 0 });
		});

	g = backendNs->append<Function>("llvmCstringType");
	g->setReturnType({ llvmType, 0 });
	g->appendVariable("compilationResult", { compilationResult, 0 });

	compileTimeFunctions::FuntionLibrary::instance().addFunctionDefinition(g, [llvmType](auto&& params, auto)
		{
			auto cr = dereferenceAs<GenericRuntimeWrapper<CompilationResult>>(params["compilationResult"].get())->value();
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(llvm::Type::getInt8PtrTy(cr->llvmContext), TypeReference{ llvmType, 0 });
		});
}
