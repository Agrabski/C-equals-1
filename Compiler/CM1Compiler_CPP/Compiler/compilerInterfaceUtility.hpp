#pragma once
#include <memory>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/CompilationContext.hpp"


namespace cMCompiler::compiler
{
	std::vector<std::unique_ptr<dataStructures::PackageDatabase>> loadCompilerInterfacePackage(dataStructures::CompilationContext const&);
	gsl::not_null<dataStructures::Function*> getCompilerInterfaceEntryPoint(dataStructures::PackageDatabase& interfacePackage);
}