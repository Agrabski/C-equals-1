#include "GenericInstantiationUtility.hpp"
#include "../../ParserAdapter/ParserAdapter.hpp"
#include "../FunctionUtility.hpp"
#include "../FunctionBodyBuilder.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler;

not_null<dataStructures::Function*> cMCompiler::compiler::instantiate
(
	dataStructures::Generic<Function>& function,
	std::vector<dataStructures::GenericParameter> const& genericParameters,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	std::filesystem::path const& file
)
{
	auto tree = function.fillGeneric(genericParameters);
	auto f = createFunction(dynamic_cast<Namespace*>(function.parent()), function.name());
	auto builder = FunctionBodyBuilder(f, resolver, context, file);
	tree->accept(&builder);
	if (context.objectMap_.contains(function.name()))
		context.objectMap_[function.name()].push_back(f);
	return f;
}
