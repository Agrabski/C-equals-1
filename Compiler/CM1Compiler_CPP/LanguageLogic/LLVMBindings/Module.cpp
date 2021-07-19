#include "Module.hpp"
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include "../BuiltInPackageBuildUtility.hpp"
#include "../CreateGetter.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "Function.hpp"
#include "../LiteralUtility.hpp"

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
			auto arg = fu->arg_begin();
			for (auto& name : *names)
			{
				auto n = dereferenceAs<StringValue>(name.get())->value();
				arg->setName(n);
				arg++;
			}
			return std::make_unique<GenericRuntimeWrapper<llvm::Function>>(fu, TypeReference{ getLLVMFunctionDescriptor(), 0 });
		})
		->setReturnType({ llvmFunction, 0 });
		f->appendVariable("functionName", {getString(), 0});
		f->appendVariable("parameterTypes", { getCollectionTypeFor({llvmType, 0}), 0 });
		f->appendVariable("parameterNames", { getCollectionTypeFor({getString(), 0}), 0 });
		f->appendVariable("returnType", { llvmType, 0 });
}

void appendType(
	not_null<Type*> mod,
	not_null<Type*> llvmType
)
{
	auto f = mod->append<Function>("appendStruct");
	createCustomFunction(f, mod, [llvmType](auto&& params, auto)->runtime_value
		{
			auto name = dereferenceAs<StringValue>(params["name"].get())->value();
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Module>>(params["self"].get())->value();

			auto ty = llvm::StructType::create(self->getContext(), name);
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(ty, TypeReference{ llvmType, 0 });
		})
		->setReturnType({ llvmType, 0 });
		f->appendVariable("name", { getString(), 0 });
}

void getPointer(
	not_null<Type*> mod,
	not_null<Type*> llvmType
)
{
	auto f = mod->append<Function>("getPointer");
	createCustomFunction(f, mod, [llvmType](auto&& params, auto)->runtime_value
		{
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(params["type"].get())->value();
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Module>>(params["self"].get())->value();

			auto ty = llvm::PointerType::getUnqual(type);
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(ty, TypeReference{ llvmType, 0 });
		})
		->setReturnType({ llvmType, 0 });
		f->appendVariable("type", { llvmType, 0 });
}

void appendArrayType(
	not_null<Type*> mod,
	not_null<Type*> llvmType
)
{
/*	auto f = mod->append<Function>("appendArray");
	createCustomFunction(f, mod, [llvmType](auto&& params, auto)->runtime_value
		{
			auto name = dereferenceAs<llvm::Type>(params["type"].get())->value();
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Module>>(params["self"].get())->value();

			auto ty = llvm::ArrayType::create(self->getContext(), name);
			return std::make_unique<GenericRuntimeWrapper<llvm::Type>>(ty, TypeReference{ llvmType, 0 });
		})
		->setReturnType({ llvmType, 0 });
		f->appendVariable("type", { llvmType, 0 })*/;
}

void appendName(
	not_null<Type*> mod)
{
	auto result = mod->append<Function>("name");
	result->setReturnType({ getString(), 0 });
	createCustomFunction(result, mod, [](auto&& params, auto)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Module>>(params["self"].get())->value();

			return buildStringValue(self->getModuleIdentifier());
		});
}

gsl::not_null<Type*> cMCompiler::language::buildModuleDescriptor(
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmFunction,
	gsl::not_null<Type*> llvmType
)
{
	auto result = backendns->append<Type>("llvmModule");
	appendFunction(result, llvmFunction, llvmType);
	appendType(result, llvmType);
	getPointer(result, llvmType);



	return result;
}