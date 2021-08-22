#pragma once
#include <gsl/gsl>
#include <llvm/IR/Type.h>
#include "../runtime_values.hpp"
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/execution/GenericRuntimeWrapper.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> getLlvmType();
	gsl::not_null<dataStructures::Type*> buildTypeDescriptor(gsl::not_null<dataStructures::Namespace*> backendns);
	runtime_value getValueFor(llvm::Type* v);
}
