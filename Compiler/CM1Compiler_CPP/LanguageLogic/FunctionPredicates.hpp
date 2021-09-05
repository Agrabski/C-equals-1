#pragma once
#include <functional>
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	bool isExecutable(not_null<dataStructures::Function const*> function) noexcept;
	bool isCompiletimeExecutable(not_null<dataStructures::Function const*> function) noexcept;
	bool isRuntimeExecutable(not_null<dataStructures::Function const*> function) noexcept;
	std::function<bool(not_null<dataStructures::Function const*> function)> 
		getFunctionPredicate(bool forceCompileTime = false, bool forceRuntime = false);

}