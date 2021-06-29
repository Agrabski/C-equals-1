#include "Module.hpp"
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include "../BuiltInPackageBuildUtility.hpp"
#include "../CreateGetter.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "Function.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::language;

void appendFunction(
	not_null<Type*> mod,
	gsl::not_null<Type*> llvmFunction,
	gsl::not_null<Type*> llvmType)
{
	auto f = mod->append<Function>("appendFunction");

	createCustomFunction(f, mod, [](auto&& params, auto)->runtime_value
		{
			auto rt = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(params["returnType"].get());
			llvm::Type* returnType = nullptr;
			if (rt)
				returnType = rt->value();
			auto types = dereferenceAs<ArrayValue>(params["parameterTypes"].get());
			auto names = dereferenceAs<ArrayValue>(params["parameterNames"].get());
			assert(types->size() == names->size());

			auto name = dereferenceAs<StringValue>(params["functionName"].get())->value();
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Module>>(params["self"].get())->value();

			std::vector <llvm::Type*> parameterTypes;
			for (auto& t : *types)
				parameterTypes.push_back(dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(t.get())->value());


			// todo: linkage
			auto fu = llvm::Function::Create(
				llvm::FunctionType::get(returnType, parameterTypes, false),
				llvm::Function::ExternalLinkage,
				llvm::Twine(name),
				*self);
			auto block = llvm::BasicBlock::Create(self->getContext(), "entry", fu);
			auto builder = llvm::IRBuilder(block);
			builder.CreateRet(llvm::ConstantInt::get(returnType, 5));
			return std::make_unique<GenericRuntimeWrapper<llvm::Function>>(fu, TypeReference{ getLLVMFunctionDescriptor(), 0 });
		})
		->setReturnType({ llvmFunction, 0 });
		f->appendVariable("functionName", {getString(), 0});
		f->appendVariable("parameterTypes", { getCollectionTypeFor({llvmType, 0}), 0 });
		f->appendVariable("parameterNames", { getCollectionTypeFor({getString(), 0}), 0 });
		f->appendVariable("returnType", { llvmType, 0 });
}


gsl::not_null<Type*> cMCompiler::language::buildModuleDescriptor(
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmFunction,
	gsl::not_null<Type*> llvmType
)
{
	auto result = backendns->append<Type>("llvmModule");
	appendFunction(result, llvmFunction, llvmType);



	return result;
}