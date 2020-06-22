#pragma once
#include <vector>
#include <filesystem>
#include "../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler
{
	std::unique_ptr<dataStructures::PackageDatabase> getPackageDefinitionAndFileSet(
		std::filesystem::path pathToPackageDefinition,
		std::vector<std::filesystem::path>&,
		std::vector<std::string>& dependencyNames);
}
