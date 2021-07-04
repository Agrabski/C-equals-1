#include "Function.hpp"
#include "../CreateGetter.hpp"
#include <llvm/IR/Instructions.h>
#include "../BuiltInPackageBuildUtility.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include <llvm/IR/IRBuilder.h>
using namespace cMCompiler::dataStructures;


void appendBodyBuilding(not_null<Type*> functionType, not_null<Type*> llvmType)
{
	using cMCompiler::language::createCustomFunction;
	using cMCompiler::language::dereferenceAs;
	using namespace cMCompiler::dataStructures::execution;
	createCustomFunction(
		functionType->append<Function>("appendAlloca"),
		functionType,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Function>>(a["self"].get())->value();
			auto varType = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();
			auto block = llvm::BasicBlock::Create(self->getContext(), "x", self);
			auto builder = llvm::IRBuilder<>(block);
			builder.CreateAlloca(varType, nullptr, "test");
			return nullptr;
		}
	)->appendVariable("type", { llvmType,0 });
}

gsl::not_null<Type*> cMCompiler::language::buildFunctionDescriptor(gsl::not_null<dataStructures::Namespace*> backendns, gsl::not_null<dataStructures::Type*> llvmType)
{
	auto result = backendns->append<Type>("llvmFunction");
	appendBodyBuilding(result, llvmType);
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