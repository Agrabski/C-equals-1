#pragma once
#include "../Compiler/CompilationUnitDatabaseBuilder.hpp"

std::unique_ptr<cMCompiler::dataStructures::PackageDatabase> compile(
	std::filesystem::path const& filename,
	std::istream& contentStream
);

