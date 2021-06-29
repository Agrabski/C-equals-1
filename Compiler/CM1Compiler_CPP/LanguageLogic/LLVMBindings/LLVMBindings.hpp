#pragma once
#include <gsl.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/LLVMContext.h>
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/CompilationResult.hpp"
#include "../runtime_values.hpp"


namespace cMCompiler::language
{
	void buildLLVMBindings(gsl::not_null<dataStructures::Namespace*> compilerNs);


	runtime_value getValueFor(llvm::Module*);
	runtime_value getValueFor(llvm::LLVMContext*);
	runtime_value getValueFor(dataStructures::CompilationResult*);

	not_null<dataStructures::Type*> getLLVMModuleDescriptor();
	not_null<dataStructures::Type*> getCompilationResult();
	not_null<dataStructures::Type*> getLLVMContextDescriptor();
}
