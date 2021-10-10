#pragma once
#include <vector>
#include <gsl/gsl>
#include <llvm/IR/LLVMContext.h>
#include "../../DataStructures/CompilationResult.hpp"
#include "../../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler::llvmIntegration
{
	std::unique_ptr<cMCompiler::dataStructures::CompilationResult> compileToLLVMIr(
		dataStructures::PackageDatabase& compilerInterface,
		std::vector<not_null<dataStructures::PackageDatabase*>> const& packages,
		llvm::LLVMContext& context
	);

	void compileToBinary(
		not_null<dataStructures::CompilationResult*> result, 
		std::filesystem::path outputDirectory,
		std::string const& triplet);
}
