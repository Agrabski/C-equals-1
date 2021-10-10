#include "PackageBuildUtility.hpp"
#include "PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler;
static auto globalPackageCache = std::map<std::string, std::unique_ptr<dataStructures::PackageDatabase>>();

std::vector<not_null<dataStructures::PackageDatabase*>> cMCompiler::compiler::buildByManifest(std::vector<std::filesystem::path> const& pathToManifest)
{
	auto r = std::vector<not_null<dataStructures::PackageDatabase*>>();
	auto directoryPackageMap = std::map<dataStructures::PackageDatabase*, std::filesystem::path>();
	auto dependencyMap = std::map<dataStructures::PackageDatabase*, std::vector<std::string>>();
	auto packageFileMap = std::map<dataStructures::PackageDatabase*, std::vector<fileSystem::File>>();
	for (auto const& path : pathToManifest)
	{
		std::vector<cMCompiler::fileSystem::File> files;
		std::vector<std::string> dependencyNames;
		auto result = getPackageDefinitionAndFileSet(path, files, dependencyNames);
		dependencyMap[result.get()] = dependencyNames;
		directoryPackageMap[result.get()] = path.parent_path() / "src";
		packageFileMap[result.get()] = files;
		r.push_back(result.get());
		globalPackageCache[result->name()] = std::move(result);
	}
	supplyDependencies(r, dependencyMap);
	for (auto const& package : r)
	{
		auto path = std::filesystem::absolute(std::filesystem::current_path());
		std::filesystem::current_path(directoryPackageMap[package.get()]);
		buildAndFillPackage(*package, packageFileMap[package.get()]);
		std::filesystem::current_path(path); //setting path
	}
	return r;
}

void cMCompiler::compiler::supplyDependencies(
	gsl::not_null<dataStructures::PackageDatabase*> package,
	std::vector<not_null<dataStructures::PackageDatabase*>> const& packages,
	std::map<dataStructures::PackageDatabase*, std::vector<std::string>> const& depNames)
{
	auto const& names = depNames.at(package);
	for (auto const& name : names)
	{
		if (name == "cm1mLang")
			package->appendDependency(language::getDefaultPackage());
		else
		{
			auto dependency = std::find_if(packages.begin(), packages.end(), [&name](auto const& e)
				{
					return e->name() == name;
				});
			if (dependency != packages.end())
				package->appendDependency(*dependency);
			else
				if (auto p = getGlobalPackage(name); p != nullptr)
					package->appendDependency(p);
				else
					std::terminate();
		}

	}
}

void cMCompiler::compiler::supplyDependencies(
	std::vector<not_null<dataStructures::PackageDatabase*>>& packages,
	std::map<dataStructures::PackageDatabase*, std::vector<std::string>> const& depNames)
{
	for (auto const& package : packages)
		supplyDependencies(package, packages, depNames);
}

dataStructures::PackageDatabase* cMCompiler::compiler::getGlobalPackage(std::string const& name)
{
	if (auto result = globalPackageCache.find(name); result != globalPackageCache.end())
		return result->second.get();
	auto path = std::filesystem::path("D:\\Programming\\C-equals-1\\Libraries") / name / "manifest.mn";
	if (std::filesystem::exists(path))
		return buildByManifest({ path }).front();
	return nullptr;
}

