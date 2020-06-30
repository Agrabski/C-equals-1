#pragma once
#include <map>
#include "CompileTimeFunction.hpp"

namespace cMCompiler::language::compileTimeFunctions
{
	extern std::map<std::string, compileTimeFunction> functionMap;
}