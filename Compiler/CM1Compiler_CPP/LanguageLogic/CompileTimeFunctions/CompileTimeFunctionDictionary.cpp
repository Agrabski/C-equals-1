#include "CompileTimeFunctionDictionary.hpp"
using namespace cMCompiler::language::compileTimeFunctions;
#include "Print.hpp"

std::map<std::string, compileTimeFunction> cMCompiler::language::compileTimeFunctions::functionMap =
{
	{"print", print}
};
