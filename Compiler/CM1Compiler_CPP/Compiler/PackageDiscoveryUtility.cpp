#include "PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../FileSystem/FileDiscovery.hpp"

std::unique_ptr<cMCompiler::dataStructures::PackageDatabase> cMCompiler::compiler::getPackageDefinitionAndFileSet(
	std::filesystem::path const& pathToPackageDefinition,
	std::vector<fileSystem::File>& files,
	std::vector<std::string>& dependencyNames)
{
	dependencyNames.push_back(language::getDefaultPackage()->name());
	auto result = std::make_unique<dataStructures::PackageDatabase>(pathToPackageDefinition.parent_path().filename().string());
	auto path = pathToPackageDefinition.parent_path() / "src";
	files = fileSystem::loadFiles(path, ".cm");
	return result;
}
