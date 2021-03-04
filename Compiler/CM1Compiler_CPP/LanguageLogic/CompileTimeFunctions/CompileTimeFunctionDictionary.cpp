#include "CompileTimeFunctionDictionary.hpp"
#include "Print.hpp"
#include "ReadAllFile.hpp"
using namespace cMCompiler::language::compileTimeFunctions;

std::map<std::string, compileTimeFunction> cMCompiler::language::compileTimeFunctions::functionMap =
{
	{"print", print},
	{"read_all_file", readAllFile}
};
