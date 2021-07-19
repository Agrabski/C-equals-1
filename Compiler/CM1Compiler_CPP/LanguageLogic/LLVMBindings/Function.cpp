#include "Function.hpp"
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
using cMCompiler::language::createCustomFunction;
using cMCompiler::language::dereferenceAs;


not_null<Type*> appendBodyBuilder(not_null<Type*> functionType, not_null<Type*> llvmType, not_null<Namespace*> backendNs)
{
	auto builder = backendNs->append<Type>("llvmIrBodyBuilder");
	auto f = createCustomFunction(
		builder->append<Function>("appendAlloca"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericOwningRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto varType = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();
			auto varName = dereferenceAs<StringValue>(a["name"].get())->value();
			if (!varType->isSized())
			{
				std::string exceptionMessage = "Type cannot be allocated on stack beacose it is unsized. Type was: ";
				llvm::raw_string_ostream rso = llvm::raw_string_ostream(exceptionMessage);
				varType->print(rso);
				// todo: fucking dangling pointer. Too bad!
				throw std::exception(exceptionMessage.c_str());
			}
			auto alloc = self->CreateAlloca(varType, nullptr, varName);
			self->CreateRet(alloc);
			return nullptr;
		}
	);
	f->appendVariable("type", { llvmType,0 });
	f->appendVariable("name", { cMCompiler::language::getString(), 0 });
	return builder;
}

void appendBodyBuilding(not_null<Type*> functionType, not_null<Type*> llvmType, not_null<Namespace*> backendNs)
{
	auto builderType = appendBodyBuilder(functionType, llvmType, backendNs);
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

gsl::not_null<Type*> cMCompiler::language::buildFunctionDescriptor(gsl::not_null<dataStructures::Namespace*> backendns, gsl::not_null<dataStructures::Type*> llvmType)
{
	auto result = backendns->append<Type>("llvmFunction");
	appendBodyBuilding(result, llvmType, backendns);
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