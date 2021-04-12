#pragma once
#include <ostream>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler
{
	class IntermidiateRepresentationEmmiter
	{
		using json = dataStructures::execution::json;
		json emmitPackageMetadata(
			dataStructures::PackageDatabase const& package,
			std::vector<gsl::not_null<dataStructures::PackageDatabase*>> dependencies
		);
		
	public:
		void emmit(std::ostream& stream, dataStructures::PackageDatabase& package, std::vector<gsl::not_null<dataStructures::PackageDatabase*>> dependencies);
	};
}
