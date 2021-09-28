#pragma once
#include <gsl/gsl>
#include "../DataStructures/Function.hpp"

using gsl::not_null;
namespace cMCompiler::compiler
{
	void inlineIr(not_null<dataStructures::Function*> function);
}
