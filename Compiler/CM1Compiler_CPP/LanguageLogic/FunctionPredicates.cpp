#include "FunctionPredicates.hpp"

using namespace cMCompiler::dataStructures;

bool cMCompiler::language::isExecutable(not_null<dataStructures::Function const*> function) noexcept
{
	return isCompiletimeExecutable(function) || isRuntimeExecutable(function);
}

bool cMCompiler::language::isCompiletimeExecutable(not_null<Function const*> function) noexcept
{
	return !function->metadata().hasFlag(FunctionFlags::ExcludeAtCompileTime);
}

bool cMCompiler::language::isRuntimeExecutable(not_null<Function const*> function) noexcept
{
	return !function->metadata().hasFlag(FunctionFlags::ExcludeAtRuntime);
}

std::function<bool(not_null<Function const*>function)> cMCompiler::language::getFunctionPredicate(bool forceCompileTime, bool forceRuntime)
{
	return [=](not_null<Function const*> f) -> bool
	{
		auto result = true;
		if (forceCompileTime)
			result = result && isCompiletimeExecutable(f);
		if (forceRuntime)
			result = result && isRuntimeExecutable(f);
		return result;
	};
}
