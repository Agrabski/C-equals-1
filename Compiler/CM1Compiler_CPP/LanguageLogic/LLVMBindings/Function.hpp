#pragma once
#include <gsl/gsl>
#include <llvm/IR/Function.h>
#include "../runtime_values.hpp"
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildFunctionDescriptor(
		not_null<dataStructures::Namespace*> backendns,
		not_null<dataStructures::Type*> llvmType,
		not_null<dataStructures:: Type*> llvmValue);

	gsl::not_null<dataStructures::Type*> getLLVMFunctionDescriptor();

	runtime_value getValueFor(not_null<llvm::Function*> function);
}
