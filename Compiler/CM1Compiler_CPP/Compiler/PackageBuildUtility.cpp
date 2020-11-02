#include "PackageBuildUtility.hpp"
#include "CompilationUnitDatabaseBuilder.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"

std::unique_ptr<cMCompiler::Parser::CompilationUnit> parse(std::filesystem::path const& path)
{
	auto adapter = cMCompiler::Parser::ParserAdapter();
	std::ifstream stream;
	stream.open(path);
	return adapter.parse(stream);
}

void runThroughFiles(cMCompiler::compiler::CompilationUnitDataBaseBuilder& builder, std::vector<std::filesystem::path> const& files)
{
	do
		for (auto& file : files)
		{
			auto parseTree = parse(file);
			builder.setFile(file);
			builder.buildDatabase(*parseTree);
		}
	while (builder.advance());
}

void cMCompiler::compiler::buildAndFillPackage(dataStructures::PackageDatabase& package, std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& dependencies, std::vector<std::filesystem::path> const& files)
{

	cMCompiler::language::NameResolver nameResolver(dependencies);
	cMCompiler::compiler::CompilationUnitDataBaseBuilder dbBuilder(package, nameResolver);
	runThroughFiles(dbBuilder, files);
	dbBuilder.finishAttributes();
	runThroughFiles(dbBuilder, files);
}
