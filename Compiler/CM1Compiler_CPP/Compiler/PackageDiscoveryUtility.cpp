#include "PackageDiscoveryUtility.hpp"
#include <fstream>
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../FileSystem/FileDiscovery.hpp"


struct PackageData
{
	std::string name;
	std::vector<std::string> dependencyNames;
};

PackageData parsePackageDefinition(std::filesystem::path const& manifestPath)
{
	auto stream = std::ifstream(manifestPath);
	auto json = nlohmann::json::parse(stream);
	return {
		.name = json["name"],
		.dependencyNames = json["dependencies"]
	};
}

std::unique_ptr<cMCompiler::dataStructures::PackageDatabase> cMCompiler::compiler::getPackageDefinitionAndFileSet(
	std::filesystem::path const& pathToPackageDefinition,
	std::vector<fileSystem::File>& files,
	std::vector<std::string>& dependencyNames)
{
	auto definition = parsePackageDefinition(pathToPackageDefinition);
	dependencyNames = definition.dependencyNames;
	auto result = std::make_unique<dataStructures::PackageDatabase>(definition.name);
	auto path = pathToPackageDefinition.parent_path() / "src";
	files = fileSystem::loadFiles(path, ".cm");
	return result;
}
