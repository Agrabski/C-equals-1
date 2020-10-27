#include "GenericInstantiationUtility.hpp"
#include "../../ParserAdapter/ParserAdapter.hpp"
#include "../FunctionUtility.hpp"
#include "../FunctionBodyBuilder.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures::generic;

not_null<dataStructures::Function*> cMCompiler::compiler::instantiate
(
	dataStructures::generic::GenericFunction& function,
	std::vector<not_null<dataStructures::Type*>> const& genericParameters,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	not_null<dataStructures::INamedObject*> parent,
	std::filesystem::path const& file
)
{
	assert(function.getParameters().size() == genericParameters.size());
	auto localContext = context;
	auto const& params = function.getParameters();
	for (int i = 0; i < genericParameters.size(); ++i)
		localContext.objectMap_[params[i]->name_].push_back(genericParameters[i]);
	auto sstream = std::stringstream(function.body());
	auto body = Parser::ParserAdapter().parseBody(sstream);
	auto f = createFunction(dynamic_cast<Namespace*>(function.parent()), function.name());
	auto builder = FunctionBodyBuilder(f, resolver, localContext, file);
	if (context.objectMap_.contains(function.name()))
		context.objectMap_[function.name()].push_back(f);
	return f;
}
