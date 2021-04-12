#include "PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

std::unique_ptr<cMCompiler::dataStructures::PackageDatabase> cMCompiler::compiler::getPackageDefinitionAndFileSet(
	std::filesystem::path pathToPackageDefinition, 
	std::vector<std::filesystem::path>&files,
	std::vector<std::string>& dependencyNames)
{
	dependencyNames.push_back(language::getDefaultPackage()->name());
	auto result = std::make_unique<dataStructures::PackageDatabase>(pathToPackageDefinition.parent_path().filename().string());
	auto path = pathToPackageDefinition.parent_path() / "src";
	for (auto& f : std::filesystem::recursive_directory_iterator(path))
		if (!f.is_directory() && f.path().has_extension() && f.path().extension() == ".cm")
			files.push_back(f);
	return result;
}
