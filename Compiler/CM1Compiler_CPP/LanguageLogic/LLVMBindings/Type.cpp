#include "Type.hpp"
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/DataLayout.h>
#include "../CreateGetter.hpp"
#include "../BuiltInPackageBuildUtility.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../LiteralUtility.hpp"
#include "../MetatypeUility.hpp"

using namespace cMCompiler::dataStructures;
Type* llvmType;

gsl::not_null<Type*> cMCompiler::language::getLlvmType()
{
	return llvmType;
}

gsl::not_null<Type*> cMCompiler::language::buildTypeDescriptor(gsl::not_null<dataStructures::Namespace*> backendns)
{
	auto result = backendns->append<Type>("llvmType");
	result->metadata().appendFlag(TypeFlags::ExcludeAtRuntime);
	createCustomFunction(
		result->append<Function>("setFields"),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<execution::GenericRuntimeWrapper<llvm::Type>>(a["self"].get())->value();
			auto types = dereferenceAs<execution::ArrayValue>(a["fieldTypes"].get());
			if (types->begin() == types->end())
				return nullptr;
			assert(self->isStructTy());
			not_null selfStruct = llvm::cast<llvm::StructType>(self);
			assert(selfStruct->isOpaque());
			std::vector<llvm::Type*> llvmTypes;
			for (auto& t : *types)
				llvmTypes.push_back(dereferenceAs<execution::GenericRuntimeWrapper<llvm::Type>>(t.get())->value());
			selfStruct->setBody(llvmTypes);
			return nullptr;
		}
	)->appendVariable("fieldTypes", { getCollectionTypeFor({result, 0}), 0 });
	createCustomFunction(
		result->append<Function>("isStructType"),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<execution::GenericRuntimeWrapper<llvm::Type>>(a["self"].get())->value();
			return buildBooleanValue(self->isStructTy());
		}
	)->setReturnType({ getBool(), 0 });
	createCustomFunction(
		result->append<Function>("isPointerType"),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<execution::GenericRuntimeWrapper<llvm::Type>>(a["self"].get())->value();
			return buildBooleanValue(self->isPointerTy());
		}
	)->setReturnType({ getBool(), 0 });
	createCustomFunction(
		result->append<Function>("fields"),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<execution::GenericRuntimeWrapper<llvm::Type>>(a["self"].get())->value();
			auto s = llvm::cast<llvm::StructType>(self);
			auto result = std::vector<not_null<llvm::Type*>>{};
			for (auto e : s->elements())
				result.push_back(e);
			return getValueFor(result);
		}
	)->setReturnType({ getCollectionTypeFor({result, 0}), 0 });
	//todo: do
	llvmType = result;
	return result;
}

std::unique_ptr<execution::IRuntimeValue> cMCompiler::language::getValueFor(llvm::Type* v)
{
	return std::make_unique<execution::GenericRuntimeWrapper<llvm::Type>>(v, dataStructures::TypeReference{ getLlvmType(), 0 });
}

