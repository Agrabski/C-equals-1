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
			alloc->dump();
			return cMCompiler::language::getValueFor(alloc);
		}
	);
	f->appendVariable("type", { llvmType,0 });
	f->appendVariable("name", { cMCompiler::language::getString(), 0 });
	f->setReturnType({ llvmValue, 0 });

	f = createCustomFunction(
		builder->append<Function>("appendAlloca"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericOwningRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto varType = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();
			if (!varType->isSized())
			{
				std::string exceptionMessage = "Type cannot be allocated on stack beacose it is unsized. Type was: ";
				llvm::raw_string_ostream rso = llvm::raw_string_ostream(exceptionMessage);
				varType->print(rso);
				// todo: fucking dangling pointer. Too bad!
				throw std::exception(exceptionMessage.c_str());
			}
			auto alloc = self->CreateAlloca(varType);
			alloc->dump();
			return cMCompiler::language::getValueFor(alloc);
		}
	);
	f->appendVariable("type", { llvmType,0 });
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

void appendAssign(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendStore"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["value"].get())->value();
			auto pointer = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["pointer"].get())->value();

			value->dump();
			pointer->dump();
			if (value->getType() !=
				cast<llvm::PointerType>(pointer->getType())->getElementType())
				throw std::exception();
			self->CreateStore(value, pointer)->dump();
			return nullptr;
		}
	);
	f->appendVariable("value", { llvmValue, 0 });
	f->appendVariable("pointer", { llvmValue, 0 });

}

void appendLoad(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendLoad"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto pointer = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["pointer"].get())->value();

			return getValueFor(self->CreateLoad(pointer));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("pointer", { llvmValue, 0 });

}

void appendCompare(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendCmpEqual"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateCmp(llvm::CmpInst::Predicate::ICMP_EQ, left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });

}

void appendBitcast(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendBitcast"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["arg"].get())->value();
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();

			return getValueFor(self->CreateBitCast(value, type));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("arg", { llvmValue, 0 });
	f->appendVariable("type", { llvmType, 0 });

}

void appendGetFieldValue(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("apendGetElementPointer"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto pointer = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["pointer"].get())->value();
			auto objectIndex = convertToIntegral<usize>(*a["objectIndex"]);
			auto memberIndex = convertToIntegral<usize>(*a["memberIndex"]);
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["baseType"].get())->value();

			llvm::Value* indexList[] = {
				llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(self->getContext()), objectIndex),
				llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(self->getContext()), memberIndex)
			};

			auto result = self->CreateGEP(pointer, indexList);
			return getValueFor(result);
		}
	);
	f->appendVariable("pointer", { llvmValue, 0 });
	f->appendVariable("objectIndex", { getUsize(), 0 });
	f->appendVariable("memberIndex", { getUsize(), 0 });
	f->appendVariable("baseType", { llvmType, 0 });

}

void appendAddressOf(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendAddressof"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["value"].get())->value();
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();

			return getValueFor(self->CreateIntToPtr(value, type));
		}
	);
	f->appendVariable("value", { llvmValue, 0 });
	f->appendVariable("type", { llvmType, 0 });

}


void appendNullConstant(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendNullPointer"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();

			return getValueFor(llvm::ConstantPointerNull::get(llvm::cast<llvm::PointerType>(type)));
		}
	);
	f->appendVariable("type", { llvmType, 0 });

}

void appendLiteral(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendIntegerLiteral"),
		builder,
		[](auto&& a, auto b)
		{
			auto value = convertToIntegral<usize>(*dereferenceAs<IntegerValue>(a["value"].get()));
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();
			return getValueFor(llvm::ConstantInt::get(type, value));
		}
	);
	f->appendVariable("value", { getUsize(), 0 });
	f->appendVariable("type", { llvmType, 0 });

}

void appendFunctionCall(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType,
	gsl::not_null<Type*> llvmFunction
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendFunctionCall"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto pointer = dereferenceAs<GenericRuntimeWrapper<llvm::Function>>(a["function"].get())->value();
			auto args = dereferenceAs<ArrayValue>(a["args"].get());

			auto llvmArguments = std::vector<llvm::Value*>();
			for (auto& arg : *args)
			{
				auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(arg.get())->value();
				value->dump();
				llvmArguments.push_back(value);
			}
			pointer->dump();
			for (unsigned i = 0; i != llvmArguments.size(); ++i)
				if (!(i >= pointer->getFunctionType()->getNumParams() ||
					pointer->getFunctionType()->getParamType(i) == llvmArguments[i]->getType()))
					throw std::exception();
			auto result = self->CreateCall(pointer, llvmArguments);
			return getValueFor(result);
		}
	);
	f->appendVariable("function", { llvmFunction, 0 });
	f->appendVariable("args", { getCollectionTypeFor({ llvmValue, 0 }), 1 });
}

gsl::not_null<Type*> cMCompiler::language::buildBodyBuilder(
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmType,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmFunction
)
{
	builder = backendns->append<Type>("llvmIrBodyBuilder");

	appendAlloca(builder, backendns, llvmType, llvmValue);
	appendRet(builder, llvmValue);
	appendRetVoid(builder, backendns, llvmType);
	appendAssign(builder, backendns, llvmValue);
	appendGetFieldValue(builder, backendns, llvmValue, llvmType);
	appendFunctionCall(builder, backendns, llvmValue, llvmType, llvmFunction);
	appendAddressOf(builder, backendns, llvmValue, llvmType);
	appendLiteral(builder, backendns, llvmValue, llvmType);
	appendLoad(builder, backendns, llvmValue);
	appendCompare(builder, backendns, llvmValue);
	appendNullConstant(builder, backendns, llvmValue, llvmType);
	appendBitcast(builder, backendns, llvmValue, llvmType);

	return builder;
}
