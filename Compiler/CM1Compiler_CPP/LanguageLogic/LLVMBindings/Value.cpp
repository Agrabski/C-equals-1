#include "Value.hpp"
#include "Type.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"
#include "../CreateGetter.hpp"
#include "../RuntimeTypesConversionUtility.hpp"

using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;

Type* value;

runtime_value cMCompiler::language::getValueFor(llvm::Value* v)
{
	return std::make_unique<GenericRuntimeWrapper<llvm::Value>>(v, TypeReference{ getValue(), 0 });
}

gsl::not_null<Type*> cMCompiler::language::getValue()
{
	return value;
}

gsl::not_null<Type*> cMCompiler::language::buildValue(gsl::not_null<dataStructures::Namespace*> backendns, gsl::not_null<dataStructures::Type*> llvmType)
{
	assert(value == nullptr);
	value = backendns->append<Type>("llvmValue");
	createCustomFunction(
		value->append<Function>("type"),
		value,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<GenericRuntimeWrapper<llvm::Value>>(a["self"].get())->value();
			return getValueFor(self->getType());
		}
	)->setReturnType({ llvmType, 0 });
	return value;
}


