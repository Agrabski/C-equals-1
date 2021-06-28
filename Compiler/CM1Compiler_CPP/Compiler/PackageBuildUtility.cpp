#include "PackageBuildUtility.hpp"
#include "PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler;

std::vector<std::unique_ptr<dataStructures::PackageDatabase>> cMCompiler::compiler::buildByManifest(std::filesystem::path const& pathToManifest)
{
	std::vector<cMCompiler::fileSystem::File> files;
	std::vector<std::string> dependencyNames;
	auto result = getPackageDefinitionAndFileSet(pathToManifest, files, dependencyNames);
	auto dependencies = { cMCompiler::language::getDefaultPackage() };
	buildAndFillPackage(*result, dependencies, files);
	auto r = std::vector<std::unique_ptr<dataStructures::PackageDatabase>>();
	r.push_back(std::move(result));
	return r;
}