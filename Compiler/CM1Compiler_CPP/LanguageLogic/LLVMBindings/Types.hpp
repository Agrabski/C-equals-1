#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/Type.hpp"

namespace cMCompiler::language
{
	void buildTypeFunctions(
		not_null<dataStructures::Namespace*> backendNs,
		not_null<dataStructures::Type*> llvmType,
		not_null<dataStructures::Type*> compilationResult);
}
