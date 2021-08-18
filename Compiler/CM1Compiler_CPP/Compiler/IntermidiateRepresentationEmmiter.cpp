#include "IntermidiateRepresentationEmmiter.hpp"
#include <gsl/gsl>
#include <sstream>
#include <nlohmann/json.hpp>
#include "../DataStructures/IntermidiateRepresentation/INameGetter.hpp"
#include "../LanguageLogic/CompileTimeInfrastrucutre/CompileTimeHeap.hpp"
#include "Serialization/NameGetter.hpp"
#include "Serialization/SerializationManager.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using gsl::not_null;

IntermidiateRepresentationEmmiter::json IntermidiateRepresentationEmmiter::emmitPackageMetadata(PackageDatabase const& package)
{
	auto dependencyNames = std::vector<std::string>();
	for (auto d : package.dependencies())
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
	dataStructures::PackageDatabase& package)
{
	auto ng = serialization::NameGetter();
	auto manager = serialization::SerializationManager();

	auto heapContent = nlohmann::json::array();

	dataStructures::execution::json result
	{
		{"header", emmitPackageMetadata(package)},
		{"root_namespace", package.rootNamespace()->emmit(ng, manager)}
	};


	for (auto const& element : cMCompiler::language::compileTimeInfrastructure::CompileTimeHeap::instance().allocated())
		heapContent.push_back(element->get()->serialize(ng, manager));
	result["heap_content"] = heapContent;

	stream << std::setw(2) << result;
}
