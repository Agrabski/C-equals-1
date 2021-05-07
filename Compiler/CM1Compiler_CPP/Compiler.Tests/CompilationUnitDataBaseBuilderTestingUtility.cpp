#include "pch.h"
#include "CompilationUnitDataBaseBuilderTestingUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::compiler;

std::unique_ptr<cMCompiler::dataStructures::PackageDatabase> compile(std::filesystem::path const& filename, std::istream& contentStream)
{
	auto adapter = cMCompiler::Parser::ParserAdapter();
	auto tree = adapter.parse(contentStream);
	auto package = std::make_unique<cMCompiler::dataStructures::PackageDatabase>("a");
	auto nr = cMCompiler::language::NameResolver({ cMCompiler::language::getDefaultPackage() });
	auto builder = CompilationUnitDataBaseBuilder(*package, nr);
	builder.setFile(filename);
	do {
		builder.buildDatabase(*tree);
	} while (builder.advance());
	builder.finishAttributes();
	do {
		builder.buildDatabase(*tree);
	} while (builder.advance());
	return package;
}
