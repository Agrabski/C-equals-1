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
				builder.setFile(file.path());
				builder.buildDatabase(*parseTree);
			}
		while (builder.advance());
	}

	template<fileSystem::file FileType>
	void buildAndFillPackage
	(
		dataStructures::PackageDatabase& package,
		std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& dependencies,
		std::vector<FileType> const& files
	)
	{

		cMCompiler::language::NameResolver nameResolver(dependencies);
		cMCompiler::compiler::CompilationUnitDataBaseBuilder dbBuilder(package, nameResolver);
		runThroughFiles(dbBuilder, files);
		dbBuilder.finishAttributes();
		runThroughFiles(dbBuilder, files);
	}

	std::unique_ptr<dataStructures::PackageDatabase> buildByManifest(
		std::filesystem::path const& pathToManifest,
		std::vector<gsl::not_null<dataStructures::PackageDatabase*>>& dependencies);

}
