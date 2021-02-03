#pragma once
#include <memory>
#include "LLVMIR.hpp"
#include "../DataStructures/PackageDatabase.hpp"


namespace cMCompiler::compiler
{
	std::unique_ptr<dataStructures::PackageDatabase> loadCompilerInterfacePackage();
	gsl::not_null<dataStructures::Function*> getCompilerInterfaceEntryPoint(dataStructures::PackageDatabase& interfacePackage);
	LLVMPackageIR transalte(dataStructures::PackageDatabase& interfacePackage, dataStructures::PackageDatabase& packageToTranslate);
}