#include "Function.hpp"
#include "BodyBuilder.hpp"
#include <llvm/IR/Instructions.h>
#include <llvm/IR/IRBuilder.h>
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/execution/GenericOwningRuntimeWrapper.h"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../CreateGetter.hpp"
#include "../BuiltInPackageBuildUtility.hpp"
#include "../RuntimeTypesConversionUtility.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::language;


void appendBodyBuilding(not_null<Type*> functionType, not_null<Type*> llvmType, not_null<Namespace*> backendNs, not_null<Type*> llvmValue)
{
	auto builderType = buildBodyBuilder(backendNs, llvmType, llvmValue);
	auto f = createCustomFunction(
		functionType->append<Function>("getBuilder"),
		functionType,
		[builderType](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Function>>(a["self"].get())->value();
			auto block = llvm::BasicBlock::Create(self->getContext(), "entry_point", self);
			auto builder = std::make_shared<llvm::IRBuilder<>>(block);
			return std::make_unique<GenericOwningRuntimeWrapper<llvm::IRBuilder<>>>(builder, TypeReference{ builderType, 0 });
		}
	);
	f->setReturnType({ builderType, 0 });

}

gsl::not_null<Type*> cMCompiler::language::buildFunctionDescriptor(gsl::not_null<dataStructures::Namespace*> backendns, gsl::not_null<dataStructures::Type*> llvmType, not_null<Type*> llvmValue)
{
	auto result = backendns->append<Type>("llvmFunction");
	appendBodyBuilding(result, llvmType, backendns, llvmValue);
	//todo: do
	return result;
}

gsl::not_null<Type*> cMCompiler::language::getLLVMFunctionDescriptor()
{
	return getDefaultPackage()->rootNamespace()
		->get<Namespace>("compiler")
		->get<Namespace>("backend")
		->get<Type>("llvmFunction");
}