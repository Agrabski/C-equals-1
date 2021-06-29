#pragma once
#include <gsl.h>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language
{
	gsl::not_null<dataStructures::Type*> buildTypeDescriptor(gsl::not_null<dataStructures::Namespace*> backendns);
}
