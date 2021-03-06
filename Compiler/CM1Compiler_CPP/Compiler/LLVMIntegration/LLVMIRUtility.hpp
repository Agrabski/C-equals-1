#pragma once
#include <vector>
#include <gsl.h>
#include <llvm/IR/LLVMContext.h>
#include "../../DataStructures/CompilationResult.hpp"
#include "../../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler::llvmIntegration
{
	std::unique_ptr<cMCompiler::dataStructures::CompilationResult> compileToLLVMIr(
		dataStructures::PackageDatabase& compilerInterface,
		std::vector<std::unique_ptr<dataStructures::PackageDatabase>>const& packages,
		llvm::LLVMContext& context
	);

	void compileToBinary(
		not_null<dataStructures::CompilationResult*> result, 
		std::filesystem::path outputDirectory,
		std::string const& triplet);
}
