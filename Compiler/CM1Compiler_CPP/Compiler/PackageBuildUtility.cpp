#include "PackageBuildUtility.hpp"
#include "CompilationUnitDatabaseBuilder.hpp"
#include "Preprocessor.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"

std::unique_ptr<cMCompiler::Parser::CompilationUnit> parse(std::filesystem::path const& path)
{
	cMCompiler::Parser::ParserAdapter adapter;
	std::ifstream stream;
	stream.open(path);
	return adapter.parse(stream);
}

void cMCompiler::compiler::buildAndFillPackage(dataStructures::PackageDatabase& package, std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& dependencies, std::vector<std::filesystem::path> const& files)
{

	cMCompiler::language::NameResolver nameResolver(dependencies);
	cMCompiler::compiler::CompilationUnitDataBaseBuilder dbBuilder(package, nameResolver);
	do
		for (auto& file : files)
		{
			auto parseTree = parse(file);
			dbBuilder.setFile(file);
			dbBuilder.buildDatabase(*parseTree);
		}
	while (dbBuilder.advance());
	auto preprocessor = Preprocessor(package, nameResolver);
	for (auto& file : files)
	{
		auto parseTree = parse(file);
		preprocessor.preprocess(*parseTree);
	}
	preprocessor.evaluateCompiletimeCode();
}
