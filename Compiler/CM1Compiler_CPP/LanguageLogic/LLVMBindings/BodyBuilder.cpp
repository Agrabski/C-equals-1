#include "BodyBuilder.hpp"
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Type.h>
#include "Value.hpp"
#include "../CreateGetter.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../../DataStructures/execution/GenericOwningRuntimeWrapper.h"
#include "../BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;

Type* builder;

gsl::not_null<Type*> cMCompiler::language::getBodyBuilder() noexcept
{
	return builder;
}

void appendAlloca(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmType,
	gsl::not_null<Type*> llvmValue)
{
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
			return cMCompiler::language::getValueFor(alloc);
		}
	);
	f->appendVariable("type", { llvmType,0 });
	f->appendVariable("name", { cMCompiler::language::getString(), 0 });
	f->setReturnType({ llvmValue, 0 });
}

void appendRet(
	gsl::not_null<Type*> builder,
	gsl::not_null<Type*> llvmValue)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendRet"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["value"].get())->value();
			self->CreateRet(value);
			return nullptr;
		}
	);
	f->appendVariable("value", { llvmValue, 0 });
}

void appendRetVoid(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmType)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendRetVoid"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			self->CreateRetVoid();
			return nullptr;
		}
	);
}

gsl::not_null<Type*> cMCompiler::language::buildBodyBuilder(
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmType,
	gsl::not_null<Type*> llvmValue)
{
	builder = backendns->append<Type>("llvmIrBodyBuilder");
	
	appendAlloca(builder, backendns, llvmType, llvmValue);
	appendRet(builder, llvmValue);
	appendRetVoid(builder, backendns, llvmType);

	return builder;
}
