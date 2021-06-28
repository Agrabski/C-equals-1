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
#include "../compilerInterfaceUtility.hpp"
#include "../FunctionExecutionUtility.hpp"
#include "../../LanguageLogic/MetatypeUility.hpp"
#include "../../LanguageLogic/LLVMBindings.hpp"
#include "../../DataStructures/execution/StringValue.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler::llvmIntegration;

std::unique_ptr<CompilationResult> cMCompiler::compiler::llvmIntegration::compileToLLVMIr(
	dataStructures::PackageDatabase& compilerInterface,
	std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& packages)
{
	auto entryPoint = getCompilerInterfaceEntryPoint(compilerInterface);
	auto result = std::make_unique<CompilationResult>();
	auto context = llvm::LLVMContext{};

	std::vector<language::runtime_value> args;
	args.push_back(language::getValueFor(packages));
	args.push_back(language::getValueFor(result.get()));
	execute(entryPoint, std::move(args));
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

	auto target = llvm::TargetRegistry::lookupTarget(triplet, er);
	llvm::TargetOptions opt;
	auto RM = llvm::Optional<llvm::Reloc::Model>();
	auto machine = target->createTargetMachine(triplet, CPU, Features, opt, RM);
	for (auto& module : result->modules)
	{
		module->setDataLayout(machine->createDataLayout());
		module->setTargetTriple(triplet);


		auto pass = llvm::legacy::PassManager();

		std::error_code ec;
		llvm::raw_fd_ostream dest(
			(outputDirectory / (module->getModuleIdentifier() + ".o")).string(),
			ec,
			llvm::sys::fs::OpenFlags::OF_None);

		if (machine->addPassesToEmitFile(pass, dest, nullptr, llvm::CodeGenFileType::CGFT_ObjectFile)) {
			std::cerr << "TargetMachine can't emit a file of this type";
			std::terminate();
		}

		pass.run(*module);
		dest.flush();
	}

}
