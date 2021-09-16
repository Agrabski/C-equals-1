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
				throw cMCompiler::dataStructures::RuntimeException(rso.str());
			}
			auto alloc = self->CreateAlloca(varType);
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

			auto valueType = value->getType();
			if (!llvm::isa<llvm::PointerType>(pointer->getType()))
			{
				pointer->dump();
				value->dump();
			}
			auto pointerType = cast<llvm::PointerType>(pointer->getType())->getElementType();

			if (valueType != pointerType)
			{
				// todo: incorporate values into the exception
				std::string exceptionMessage = "Cannot store ";
				llvm::raw_string_ostream rso = llvm::raw_string_ostream(exceptionMessage);
				value->dump();
				pointer->dump();
				valueType->print(rso);
				rso << " into pointer of type ";
				pointer->getType()->print(rso);
				throw cMCompiler::dataStructures::RuntimeException(rso.str());
			}
			self->CreateStore(value, pointer);
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
			if (pointer->getType()->getTypeID() != llvm::Type::TypeID::PointerTyID)
				throw std::exception();
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

	f = createCustomFunction(
		builder->append<Function>("appendCmpNotEqual"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateCmp(llvm::CmpInst::Predicate::ICMP_NE, left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });
	f = createCustomFunction(
		builder->append<Function>("appendCmpGreater"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateCmp(llvm::CmpInst::Predicate::ICMP_UGT, left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });
	f = createCustomFunction(
		builder->append<Function>("appendCmpLess"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateCmp(llvm::CmpInst::Predicate::ICMP_ULT, left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });

}

void appendMultiply(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendIntegerMultiply"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateMul(left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });
}

void appendAdd(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendIntegerAddition"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateAdd(left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });
}

void appendSub(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendIntegerDifference"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateSub(left, right));
		}
	)->setReturnType({ llvmValue, 0 });
	f->appendVariable("left", { llvmValue, 0 });
	f->appendVariable("right", { llvmValue, 0 });
}

void appendDiv(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendIntegerDivision"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto left = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["left"].get())->value();
			auto right = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["right"].get())->value();

			return getValueFor(self->CreateUDiv(left, right));
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

	f = createCustomFunction(
		builder->append<Function>("apendGetElementPointer"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto pointer = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["pointer"].get())->value();
			auto objectIndex = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["objectIndex"].get())->value();
			auto memberIndex = convertToIntegral<usize>(*a["memberIndex"]);

			llvm::Value* indexList[] = {
				objectIndex,
				llvm::ConstantInt::get(llvm::IntegerType::getInt32Ty(self->getContext()), memberIndex)
			};
			pointer->dump();
			auto result = self->CreateGEP(pointer, indexList);
			return getValueFor(result);
		}
	);
	f->appendVariable("pointer", { llvmValue, 0 });
	f->appendVariable("objectIndex", { llvmValue, 0 });
	f->appendVariable("memberIndex", { getUsize(), 0 });

}


void appendBlock(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendBlock"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto const& name = dereferenceAs<StringValue>(a["name"].get())->value();

			auto newBlock = llvm::BasicBlock::Create(self->getContext(), name, self->GetInsertBlock()->getParent());
			return std::make_unique<GenericOwningRuntimeWrapper<llvm::IRBuilder<>>>(
				std::make_shared<llvm::IRBuilder<>>(newBlock),
				TypeReference{ getBodyBuilder(), 0 });
		}
	);
	f->appendVariable("name", { getString(), 0 });
	f->setReturnType({ getBodyBuilder(), 0 });
}

void appendBranch(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto functionCode = [](auto&& a, auto b) -> runtime_value
	{
		auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
		auto const& ifBranch = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["ifBranch"].get())->value();
		if (a.contains("condition"))
		{
			auto const& elseBranch = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["elseBranch"].get())->value();
			auto const& condition = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["condition"].get())->value();
			condition->dump();
			return getValueFor(self->CreateCondBr(condition, ifBranch->GetInsertBlock(), elseBranch->GetInsertBlock()));
		}
		else
			return getValueFor(self->CreateBr(ifBranch->GetInsertBlock()));
	};
	auto f = createCustomFunction(
		builder->append<Function>("appendBranch"),
		builder,
		functionCode
	);
	f->appendVariable("ifBranch", { builder, 0 });
	f->appendVariable("elseBranch", { builder, 0 });
	f->appendVariable("condition", { llvmValue, 0 });
	f->setReturnType({ nullptr, 0 });

	f = createCustomFunction(
		builder->append<Function>("appendBranch"),
		builder,
		functionCode
	);
	f->appendVariable("ifBranch", { builder, 0 });
	f->setReturnType({});

	f = createCustomFunction(
		builder->append<Function>("switchToNewBlock"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			self->SetInsertPoint(llvm::BasicBlock::Create(self->getContext(), "", self->GetInsertBlock()->getParent()));
			return nullptr;
		}
	);
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

void appendPtrToInt(
	gsl::not_null<Type*> builder,
	gsl::not_null<Namespace*> backendns,
	gsl::not_null<Type*> llvmValue,
	gsl::not_null<Type*> llvmType
)
{
	auto f = createCustomFunction(
		builder->append<Function>("appendPtrToInt"),
		builder,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::IRBuilder<>>>(a["self"].get())->value();
			auto value = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["value"].get())->value();
			auto type = dereferenceAs<GenericRuntimeWrapper<llvm::Type>>(a["type"].get())->value();

			return getValueFor(self->CreatePtrToInt(value, type));
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
				llvmArguments.push_back(value);
			}
			for (unsigned i = 0; i != llvmArguments.size(); ++i)
				if (!(i >= pointer->getFunctionType()->getNumParams() ||
					pointer->getFunctionType()->getParamType(i) == llvmArguments[i]->getType()))
				{
					std::string message = "while calling ";
					auto rso = llvm::raw_string_ostream(message);
					pointer->print(rso);
					rso << " could not convert ";
					llvmArguments[i]->getType()->print(rso);
					rso << " to ";
					pointer->getFunctionType()->getParamType(i)->print(rso);
					throw RuntimeException(rso.str());
				}
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
	if (builder != nullptr)
		return getBodyBuilder();
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
	appendMultiply(builder, backendns, llvmValue);
	appendAdd(builder, backendns, llvmValue);
	appendSub(builder, backendns, llvmValue);
	appendDiv(builder, backendns, llvmValue);
	appendNullConstant(builder, backendns, llvmValue, llvmType);
	appendBitcast(builder, backendns, llvmValue, llvmType);
	appendPtrToInt(builder, backendns, llvmValue, llvmType);
	appendBranch(builder, backendns, llvmValue, llvmType);
	appendBlock(builder, backendns, llvmValue, llvmType);

	return builder;
}
