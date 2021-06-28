#pragma once
#include <string>
#include <vector>
#include <llvm/IR/Module.h>

namespace cMCompiler::dataStructures
{
	struct CompilationResult
	{
		std::string intermidiateRepresentation;
		std::vector<std::unique_ptr<llvm::Module>> modules;
		std::vector<std::string> linkerFlags;
		llvm::LLVMContext llvmContext;
	};
}
