#pragma once
#include <vector>
#include "../FileSystem/File.hpp"
#include "../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler
{
	std::unique_ptr<dataStructures::PackageDatabase> getPackageDefinitionAndFileSet(
		std::filesystem::path const&pathToPackageDefinition,
		std::vector<fileSystem::File>&,
		std::vector<std::string>& dependencyNames);
}
