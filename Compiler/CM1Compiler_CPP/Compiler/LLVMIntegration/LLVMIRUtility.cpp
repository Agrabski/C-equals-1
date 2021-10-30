#include "LLVMIRUtility.hpp"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/IR/Module.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/FormatVariadicDetails.h>
#include <llvm/IR/LegacyPassManager.h>
#include <clang/Driver/Driver.h>
#include <clang/Driver/Compilation.h>
#include <clang/Driver/Action.h>
#include "../ExceptionHandling.hpp"
#include "../IntermidiateRepresentationEmmiter.hpp"
#include "../compilerInterfaceUtility.hpp"
#include "../FunctionExecutionUtility.hpp"
#include "../../LanguageLogic/MetatypeUility.hpp"
#include "../../LanguageLogic/CompilerInterface.hpp"
#include "../../LanguageLogic/LLVMBindings/LLVMBindings.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/RuntimeException.hpp"
#include <llvm/IR/Verifier.h>

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler::llvmIntegration;


std::unique_ptr<CompilationResult> cMCompiler::compiler::llvmIntegration::compileToLLVMIr(
	dataStructures::PackageDatabase& compilerInterface,
	std::vector<not_null<dataStructures::PackageDatabase*>> const& packages,
	llvm::LLVMContext& context)
{
	auto entryPoint = getCompilerInterfaceEntryPoint(compilerInterface);
	auto result = std::make_unique<CompilationResult>();

	std::vector<language::runtime_value> args;
	std::vector<not_null<dataStructures::PackageDatabase*>> p;
	for (auto& pa : packages)
		p.push_back(pa.get());
	p.push_back(language::getDefaultPackage());
	args.push_back(language::getValueFor(p));
	args.push_back(language::getValueFor(result.get()));
	auto emiter = cMCompiler::compiler::IntermidiateRepresentationEmmiter();
	runWithHandling([&]()
		{
			try
			{
				execute(entryPoint, std::move(args));
			}

			catch (...)
			{
				for (auto& mod : result->modules)
				{
					mod->dump();
					std::cout << std::endl;
				}
				throw;
			}
		});
	return result;
}

void cMCompiler::compiler::llvmIntegration::compileToBinary(
	not_null<dataStructures::CompilationResult*> result,
	std::filesystem::path outputDirectory,
	std::string const& triplet)
{
	llvm::SMDiagnostic error;
	auto CPU = "generic";
	auto Features = "";
	llvm::InitializeAllTargetInfos();
	llvm::InitializeAllTargets();
	llvm::InitializeAllTargetMCs();
	llvm::InitializeAllAsmParsers();
	llvm::InitializeAllAsmPrinters();
	std::string er;

	not_null target = llvm::TargetRegistry::lookupTarget(triplet, er);
	llvm::TargetOptions opt;
	auto RM = llvm::Optional<llvm::Reloc::Model>();
	not_null machine = target->createTargetMachine(triplet, CPU, Features, opt, RM);
	for (auto& module : result->modules)
		module->dump();
	for (auto& module : result->modules)
	{
		if (!llvm::verifyModule(*module, &llvm::outs()))
		{
			module->setDataLayout(machine->createDataLayout());
			module->setTargetTriple(triplet);

			auto pass = llvm::legacy::PassManager();

			std::error_code ec;
			auto path = std::filesystem::path(module->getModuleIdentifier()).replace_extension(".o").filename();
			llvm::raw_fd_ostream dest(
				(outputDirectory / path).string(),
				ec,
				llvm::sys::fs::OpenFlags::OF_None);

			if (machine->addPassesToEmitFile(pass, dest, nullptr, llvm::CodeGenFileType::CGFT_ObjectFile))
			{
				std::cerr << "TargetMachine can't emit a file of this type";
				std::terminate();
			}
			pass.run(*module);
			dest.flush();
		}
		else
		{
			llvm::outs().flush();
			exit(1);
		}
	}

}
