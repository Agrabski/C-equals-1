#include "IntermidiateRepresentationEmmiter.hpp"
#include <gsl.h>
#include <sstream>
#include "../DataStructures/IntermidiateRepresentation/INameGetter.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using gsl::not_null;

IntermidiateRepresentationEmmiter::json IntermidiateRepresentationEmmiter::emmitPackageMetadata(
	PackageDatabase const& package,
	std::vector<gsl::not_null<PackageDatabase*>> dependencies
)
{
	auto dependencyNames = std::vector<std::string>();
	for (auto d : dependencies)
		dependencyNames.push_back(d->name());
	return {
		{
			"name",
			package.name()
		},
		{
			"dependencies",
			dependencyNames
		}
	};
}

void cMCompiler::compiler::IntermidiateRepresentationEmmiter::emmit(
	std::ostream& stream,
	dataStructures::PackageDatabase& package,
	std::vector<gsl::not_null<dataStructures::PackageDatabase*>> dependencies)
{
	auto functions = std::vector<json>();
	for (auto f : package.getAllFunctions())
		;
	dataStructures::execution::json result
	{
		{"header", emmitPackageMetadata(package, dependencies)}
	};

	stream << std::setw(2) << result;
}
