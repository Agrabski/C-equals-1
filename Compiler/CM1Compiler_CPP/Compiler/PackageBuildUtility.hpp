#pragma once
#include "../DataStructures/PackageDatabase.hpp"
#include <filesystem>

namespace cMCompiler::compiler
{
	void buildAndFillPackage
	(
		dataStructures::PackageDatabase& package,
		std::vector<gsl::not_null<dataStructures::PackageDatabase*>> const& dependencies,
		std::vector<std::filesystem::path> const& files
	);

}
