#pragma once
#include "CompilationUnitDatabaseBuilder.hpp"
#include "../DataStructures/PackageDatabase.hpp"
#include "../FileSystem/File.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"


namespace cMCompiler::compiler
{
	template<fileSystem::file FileType>
	std::unique_ptr<cMCompiler::Parser::CompilationUnit> parse(FileType const& file)
	{
		auto adapter = cMCompiler::Parser::ParserAdapter();
		auto stream = file.open();
		return adapter.parse(*stream);
	}

	template<fileSystem::file FileType>
	void runThroughFiles(cMCompiler::compiler::CompilationUnitDataBaseBuilder& builder, std::vector<FileType> const& files)
	{
		do
			for (auto& file : files)
			{
				auto parseTree = parse(file);
				builder.setFile(std::filesystem::relative(file.path()));
				builder.buildDatabase(*parseTree);
			}
		while (builder.advance());
	}

	template<fileSystem::file FileType>
	void buildAndFillPackage
	(
		dataStructures::PackageDatabase& package,
		std::vector<FileType> const& files
	)
	{

		cMCompiler::language::NameResolver nameResolver(package.dependencies());
		cMCompiler::compiler::CompilationUnitDataBaseBuilder dbBuilder(package, nameResolver);
		runThroughFiles(dbBuilder, files);
		dbBuilder.finishAttributes();
		runThroughFiles(dbBuilder, files);
	}

	std::vector<not_null<dataStructures::PackageDatabase*>> buildByManifest(std::vector<std::filesystem::path> const& pathToManifest);

	void supplyDependencies(
		gsl::not_null<dataStructures::PackageDatabase*>package,
		std::vector<not_null<dataStructures::PackageDatabase*>> const& packages,
		std::map<dataStructures::PackageDatabase*, std::vector<std::string>>const& depNames);

	void supplyDependencies(
		std::vector<not_null<dataStructures::PackageDatabase*>>& packages,
		std::map<dataStructures::PackageDatabase*, std::vector<std::string>>const& depNames);

	dataStructures::PackageDatabase* getGlobalPackage(std::string const& name);
}
