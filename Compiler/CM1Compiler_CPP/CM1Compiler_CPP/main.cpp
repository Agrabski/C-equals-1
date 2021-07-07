#include <iostream>
#include <fstream>
#include <ranges>
#include <llvm/Support/Host.h>
#include "CLIInterface.hpp"
#include "../FileSystem/File.hpp"
#include "../Compiler/PackageBuildUtility.hpp"
#include "../DataStructures/RuntimeException.hpp"
#include "../Compiler/IntermidiateRepresentationEmmiter.hpp"
#include "../Compiler/PackageDiscoveryUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../Compiler/compilerInterfaceUtility.hpp"
#include "../Compiler/LLVMIntegration/LLVMIRUtility.hpp"

void runWithHandling(std::function<void()> const& f)
{
	try
	{
		f();
	}
	catch (cMCompiler::dataStructures::RuntimeException const& e)
	{
		std::cerr << "exception occured: " << e.what() << std::endl;
		for (auto const& frame : std::views::reverse(e.trace()))
			std::cerr
			<< "[ "
			<< frame.function->qualifiedName()
			<< " ]: "
			<< frame.currentInstruction.lineNumber_
			<< " ("
			<< frame.currentInstruction.filePath_
			<< " )"
			<< std::endl;
		exit(-1);
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what();
	}
}


int main(int argc, char* argv[])
{
	using namespace std::literals;

	auto context = cMCompiler::getCompilationContext(argc, argv);
	if (context)
	{
		using namespace cMCompiler::dataStructures;
		using namespace std::filesystem;
		auto packages = cMCompiler::compiler::buildByManifest({ context->manifestFile });
		auto emiter = cMCompiler::compiler::IntermidiateRepresentationEmmiter();

		std::filesystem::create_directory("out");
		for (auto& package : packages)
		{
			auto outputFile = std::ofstream(path("out") / (package->name() + ".json"));
			emiter.emmit(outputFile, *package);
			outputFile.close();
		}

		auto compiler = cMCompiler::compiler::loadCompilerInterfacePackage(*context);

		auto context = llvm::LLVMContext();
		runWithHandling([&]()
			{
				auto llvmIr = cMCompiler::compiler::llvmIntegration::compileToLLVMIr(*compiler.front(), packages, context);

				auto tripple = llvm::sys::getDefaultTargetTriple();
				cMCompiler::compiler::llvmIntegration::compileToBinary(llvmIr.get(), "out", tripple);

				llvmIr.release();
			});

	}

	return 0;
}

