#pragma once
#include <vector>
#include <filesystem>
#include <string>
#include "File.hpp"

namespace cMCompiler::fileSystem
{
	std::vector<File> loadFiles(std::filesystem::path const& path, std::string const& extension);
}