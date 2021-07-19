#pragma once
#include <filesystem>
#include <string>

namespace cMCompiler::compiler
{
	std::string getEnvironmentVariable(std::string const& name);
	std::filesystem::path getCmLibraryPath();
}
