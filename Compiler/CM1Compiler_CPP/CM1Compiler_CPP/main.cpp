#include <iostream>
#include <fstream>
#include <ll>
#include "CLIInterface.hpp"
#include "../FileSystem/File.hpp"
#include "../Compiler/PackageBuildUtility.hpp"
#include "../Compiler/IntermidiateRepresentationEmmiter.hpp"
#include "../Compiler/PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../Compiler/compilerInterfaceUtility.hpp"
#include "../Compiler/LLVMIntegration/LLVMIRUtility.hpp"

int main(int argc, char* argv[])
{
	using namespace std::literals;
	auto context = cMCompiler::getCompilationContext(argc, argv);
	if (context)
	{
		std::vector<gsl::not_null<cMCompiler::dataStructures::PackageDatabase*>> dependencies;
		auto package = cMCompiler::compiler::buildByManifest(context->manifestFile, dependencies);
		auto emiter = cMCompiler::compiler::IntermidiateRepresentationEmmiter();
		
		std::filesystem::create_directory("out");
		auto outputFile = std::ofstream("out\\package.json");
		emiter.emmit(outputFile, *package, dependencies);
		outputFile.close();

		auto compiler = cMCompiler::compiler::loadCompilerInterfacePackage(*context);

		auto llvmIr = cMCompiler::compiler::llvmIntegration::compileToLLVMIr(*package, *compiler, dependencies);
		std::cout << llvmIr.intermidiateRepresentation << std::endl;
	}
	return 0;
}

