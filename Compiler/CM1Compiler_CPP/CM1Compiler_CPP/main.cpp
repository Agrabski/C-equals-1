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
#include "../Compiler/ExceptionHandling.hpp"
#include "../Compiler/LLVMIntegration/LLVMIRUtility.hpp"
#include "../LanguageLogic/CompileTimeInfrastrucutre/CompilationOptions.hpp"
#include "../LanguageLogic/CompilerInterface.hpp"

using cMCompiler::language::compileTimeInfrastructure::CompilationOptions;
class CompilerInterface : cMCompiler::language::CompilerInterface
{
public:
	CompilerInterface() : cMCompiler::language::CompilerInterface() {}
	std::vector< cMCompiler::dataStructures::validationError> errors;
	virtual void raiseError(std::string const& text, cMCompiler::dataStructures::SourcePointer const& source, unsigned long long const code) override
	{
		errors.push_back({ text, source, code });
		std::cout << "error " << code << ": " << text << " " << source.filePath_ << " line: " << source.lineNumber_ << std::endl;
	}
};

int main(int argc, char* argv[])
{
	using namespace std::literals;
	CompilerInterface interf{};

	auto context = cMCompiler::getCompilationContext(argc, argv);
	if (context)
	{
		using namespace cMCompiler::dataStructures;
		using namespace std::filesystem;
		auto packages = cMCompiler::compiler::buildByManifest({ context->manifestFile });
		auto emiter = cMCompiler::compiler::IntermidiateRepresentationEmmiter();
		CompilationOptions::instance = std::make_unique<CompilationOptions>(
			std::filesystem::absolute("out")
			);
		std::filesystem::create_directory("out");
		try
		{
			for (auto& package : packages)
			{
				auto outputFile = std::ofstream(path("out") / (package->name() + ".json"));
				emiter.emmit(outputFile, *package);
				outputFile.close();
			}

			auto compiler = cMCompiler::compiler::loadCompilerInterfacePackage(*context);

			auto context = llvm::LLVMContext();
			cMCompiler::compiler::runWithHandling([&]()
				{
					auto llvmIr = cMCompiler::compiler::llvmIntegration::compileToLLVMIr(*compiler.front(), packages, context);

					if (interf.errors.empty())
					{
						auto tripple = llvm::sys::getDefaultTargetTriple();
						cMCompiler::compiler::llvmIntegration::compileToBinary(llvmIr.get(), "out", tripple);

						llvmIr.release();
					}
					else
					{
						for(auto error : interf.errors)
							std::cout << "error " << error.code << ": " << error.text << " " << error.source.filePath_ << " line: " << error.source.lineNumber_ << std::endl;
						std::cout << interf.errors.size() << " errors occured. Compilation terminated"<<std::endl;
						return -1;
					}
				});
		}
		catch (std::exception const& e)
		{
			std::cerr << e.what();
			return -1;
		}
	}

	return 0;
}

