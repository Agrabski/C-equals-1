#include <iostream>
#include <fstream>
#include "CLIInterface.hpp"
#include "../Compiler/PackageBuildUtility.hpp"
#include "../Compiler/IntermidiateRepresentationEmmiter.hpp"
#include "../Compiler/PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

int main(int argc, char* argv[])
{
	using namespace std::literals;
	auto options = cMCompiler::prepareOptions();
	auto context = cMCompiler::getCompilationContext(argc, argv, options);
	if (context)
	{
		std::vector<std::unique_ptr<cMCompiler::dataStructures::PackageDatabase>> packages;
		std::vector<std::filesystem::path> files;
		std::vector<std::string> dependencyNames;
		std::vector<gsl::not_null<cMCompiler::dataStructures::PackageDatabase*>> dependencies = { cMCompiler::language::getDefaultPackage() };
		packages.push_back(cMCompiler::compiler::getPackageDefinitionAndFileSet(context->file, files, dependencyNames));
		cMCompiler::compiler::buildAndFillPackage(*packages.back(), dependencies, files);
		auto emiter = cMCompiler::compiler::IntermidiateRepresentationEmmiter();
		
		std::filesystem::create_directory("out");
		auto outputFile = std::ofstream("out\\package.json");
		emiter.emmit(outputFile, *packages.back(), dependencies);
		outputFile.close();
	}
	else
		options.print(std::cout);
	return 0;
}

