#include <iostream>
#include <fstream>
#include "CLIInterface.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../Compiler/CompilationUnitDatabaseBuilder.hpp"
#include "../DataStructures/PackageDatabase.hpp"

int main(int argc, char* argv[])
{
	using namespace std::literals;
	auto options = cMCompiler::prepareOptions();
	auto context = cMCompiler::getCompilationContext(argc, argv, options);
	if (context)
	{
		cMCompiler::Parser::ParserAdapter adapter;
		std::ifstream stream;
		stream.open(context->file);
		auto parseTree = adapter.parse(stream);
		cMCompiler::dataStructures::PackageDatabase packageDatabase("test package"s);
		std::vector a = { &packageDatabase };
		cMCompiler::language::NameResolver nameResolver(a);
		cMCompiler::compiler::CompilationUnitDataBaseBuilder dbBuilder(packageDatabase, nameResolver);
		dbBuilder.buildDatabase(*parseTree);
	}
	else
		options.print(std::cout);
	return 0;
}

