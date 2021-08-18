#include "Environment.hpp"
#include <stdlib.h>
#include <gsl/gsl>

std::string cMCompiler::compiler::getEnvironmentVariable(std::string const& name)
{
	gsl::not_null result = std::getenv(name.c_str());
	return std::string{ result };
}

std::filesystem::path cMCompiler::compiler::getCmLibraryPath()
{
	return getEnvironmentVariable("cm1_library_path");
}
