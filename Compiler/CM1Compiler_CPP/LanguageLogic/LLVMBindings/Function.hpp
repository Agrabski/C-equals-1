#pragma once
#include <gsl.h>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildFunctionDescriptor(
		gsl::not_null<dataStructures::Namespace*> backendns,
		gsl::not_null<dataStructures::Type*> llvmType);

	gsl::not_null<dataStructures::Type*> getLLVMFunctionDescriptor();
}
