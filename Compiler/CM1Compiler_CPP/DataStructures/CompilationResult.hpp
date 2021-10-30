#pragma once
#include <string>
#include <vector>
#include <llvm/IR/Module.h>
#include "SourcePointer.hpp"

namespace cMCompiler::dataStructures
{
	struct validationError
	{
		std::string const text;
		cMCompiler::dataStructures::SourcePointer const source;
		unsigned long long const code;
	};

	struct CompilationResult
	{
		std::string intermidiateRepresentation;
		std::vector<std::unique_ptr<llvm::Module>> modules;
		std::vector<std::string> linkerFlags;
		llvm::LLVMContext llvmContext;
		std::vector<validationError> errors;
	};
}
