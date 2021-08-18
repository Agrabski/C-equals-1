#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildModuleDescriptor(
		gsl::not_null<dataStructures::Namespace*> backendns,
		gsl::not_null<dataStructures::Type*> llvmFunction,
		gsl::not_null<dataStructures::Type*> llvmType);
}
