#pragma once
#include <functional>
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	bool isCompiletimeExecutable(not_null<dataStructures::Function const*> function);
	bool isRuntimeExecutable(not_null<dataStructures::Function const*> function);
	std::function<bool(not_null<dataStructures::Function const*> function)> 
		getFunctionPredicate(bool forceCompileTime = false, bool forceRuntime = false);

}