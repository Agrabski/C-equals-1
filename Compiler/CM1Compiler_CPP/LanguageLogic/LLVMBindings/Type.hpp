#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildTypeDescriptor(gsl::not_null<dataStructures::Namespace*> backendns);
}
