#include "InstantiateGeneric.hpp"
#include "GenericUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "MetatypeUility.hpp"
#include "CreateGetter.hpp"
#include "LiteralUtility.hpp"
#include "OverloadResolutionUtility.hpp"


void setSourceLocation(not_null<cMCompiler::dataStructures::INamedObject*> obj)
{
	obj->setSourceLocation(cMCompiler::language::buildPointerToSource("C-=-1_library_internals.cm", 0));

}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::instantiate(
	dataStructures::Generic<dataStructures::Type> const& type,
	std::vector<cMCompiler::dataStructures::TypeReference> const& genericParameters)
{
	auto name = getGenericMangledName(type, genericParameters);
	auto found = getDefaultPackage()->rootNamespace()->get<dataStructures::Type>(name);
	if (found != nullptr)
		return found;
	// todo: fucking disgusting
	if (type.name() == "array")
	{
		auto f = type.fillSpecial(genericParameters);
		setOverloadResolutionInformation(f, genericParameters);
		for (auto m : f->methods())
			setOverloadResolutionInformation(m, genericParameters);
		return f;

	}
}
