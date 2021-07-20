#pragma once
#include <gsl.h>
#include "../runtime_values.hpp"
#include "../../DataStructures/Type.hpp"
#include "../../DataStructures/Namespace.hpp"
#include <llvm/IR/Value.h>

namespace cMCompiler::language
{
	runtime_value getValueFor(llvm::Value* v);
	gsl::not_null<dataStructures::Type*> getValue();
	gsl::not_null<dataStructures::Type*> buildValue(
		gsl::not_null<dataStructures::Namespace*> backendns,
		gsl::not_null<dataStructures::Type*> llvmType);

}