#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildFunctionDescriptor(
		not_null<dataStructures::Namespace*> backendns,
		not_null<dataStructures::Type*> llvmType,
		not_null<dataStructures:: Type*> llvmValue);

	gsl::not_null<dataStructures::Type*> getLLVMFunctionDescriptor();
}
