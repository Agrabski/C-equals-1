#pragma once
#include "../DataStructures/Function.hpp"
#include "../DataStructures/Type.hpp"
namespace cMCompiler::language
{
	dataStructures::Function* getFinalizer(gsl::not_null<dataStructures::Type*> type);
}