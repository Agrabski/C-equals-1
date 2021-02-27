#include "InstantiateGeneric.hpp"
#include "GenericUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "MetatypeUility.hpp"
#include "CreateGetter.hpp"

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::instantiate(dataStructures::Generic<dataStructures::Type> const& type, std::vector<not_null<dataStructures::Type*>> const& genericParameters)
{
	auto name = getGenericMangledName(type, genericParameters);
	auto found = getDefaultPackage()->rootNamespace()->get<dataStructures::Type>(name);
	if (found != nullptr)
		return found;
	// todo: fucking disgusting
	if (type.name() == "array")
	{
		auto newType = getDefaultPackage()->rootNamespace()->append<dataStructures::Type>(name);
		newType->setAccessibility(dataStructures::Accessibility::Public);
		auto indexOperator = newType->append<dataStructures::Function>("operator[]");
		createIndexer(indexOperator, newType, genericParameters[0]);
		// todo: finish

		return newType;

	}
}
