#pragma once
#include <vector>
#include <gsl.h>
#include "LLVMIR.hpp"
#include "../../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler::llvmIntegration
{
	LLVMPackageIR compileToLLVMIr(
		dataStructures::PackageDatabase& compiled, 
		dataStructures::PackageDatabase& compilerInterface,
		std::vector<gsl::not_null<dataStructures::PackageDatabase*>>const& dependencies
	);
}
