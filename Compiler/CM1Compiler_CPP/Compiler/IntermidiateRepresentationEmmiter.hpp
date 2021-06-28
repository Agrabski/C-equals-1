#pragma once
#include <ostream>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler
{
	class IntermidiateRepresentationEmmiter
	{
		using json = dataStructures::execution::json;
		json emmitPackageMetadata(dataStructures::PackageDatabase const& package);
		
	public:
		void emmit(std::ostream& stream, dataStructures::PackageDatabase& package);
	};
}
