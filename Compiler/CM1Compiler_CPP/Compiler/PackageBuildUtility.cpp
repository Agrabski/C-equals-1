#include "PackageBuildUtility.hpp"
#include "PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler;

std::unique_ptr<dataStructures::PackageDatabase> cMCompiler::compiler::buildByManifest(
	std::filesystem::path const& pathToManifest,
	std::vector<gsl::not_null<dataStructures::PackageDatabase*>>& dependencies)
{
	std::vector<cMCompiler::fileSystem::File> files;
	std::vector<std::string> dependencyNames;
	auto result = getPackageDefinitionAndFileSet(pathToManifest, files, dependencyNames);
	dependencies = { cMCompiler::language::getDefaultPackage() };
	buildAndFillPackage(*result, dependencies, files);
	return result;
}