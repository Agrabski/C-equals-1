#include "InstantiateGeneric.hpp"
#include "GenericUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "MetatypeUility.hpp"
#include "CreateGetter.hpp"
#include "LiteralUtility.hpp"


//gsl::not_null<cMCompiler::dataStructures::Type*> buildArrayIterator(cMCompiler::dataStructures::TypeReference type)
//{
//
//}
//
//gsl::not_null<cMCompiler::dataStructures::Type*> buildArrayRange(cMCompiler::dataStructures::TypeReference type)
//{
//	using namespace cMCompiler::dataStructures;
//	using namespace cMCompiler::language;
//	auto gen = cMCompiler::language::getDefaultPackage()->rootNamespace()->get<Generic<Type>>("arrayIterator");
//	auto name = getGenericMangledName(*gen, { type });
//
//	auto newType = getDefaultPackage()->rootNamespace()->append<Type>(name);
//	newType->setAccessibility(Accessibility::Public);
//
//	auto iterator = TypeReference{ buildArrayIterator(type), 0 };
//
//}

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
		auto newType = getDefaultPackage()->rootNamespace()->append<dataStructures::Type>(name);
		newType->setSourceLocation(buildPointerToSource("C-=-1_library_internals.cm", 0));
		newType->setAccessibility(dataStructures::Accessibility::Public);
		auto indexOperator = newType->append<dataStructures::Function>("operator_[]");
		createIndexer(indexOperator, newType, genericParameters[0]);

		createCustomFunction(
			newType->append<dataStructures::Function>("push"),
			newType,
			[](auto&& args, auto)
			{
				auto self = dereferenceAs<dataStructures::execution::ArrayValue>(args["self"].get());
				self->push(args["value"]->copy());
				return nullptr;
			}
		)->appendVariable("value", genericParameters[0]);
		createCustomFunction(
			newType->append<dataStructures::Function>("length"),
			newType,
			[](auto&& args, auto)
			{
				auto self = dereferenceAs<dataStructures::execution::ArrayValue>(args["self"].get());
				return buildIntegerValue(getUsize(), self->size());
			}
		)->setReturnType({ getUsize(), 0 });
		newType
			->append<dataStructures::Function>("length")
			->setReturnType({ getUsize(), 0 })
			->metadata().appendFlag(dataStructures::FunctionFlags::ExcludeAtCompileTime);
		newType->setInstantiationData({ getArray(), genericParameters });
		return newType;

	}
}
