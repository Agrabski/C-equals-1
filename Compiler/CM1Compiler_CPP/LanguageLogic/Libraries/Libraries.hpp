#pragma once
#include <gsl/gsl>
#include "../../DataStructures/Namespace.hpp"

namespace cMCompiler::language::libraries
{
	void createLibraries(gsl::not_null<dataStructures::Namespace*>ns);
}