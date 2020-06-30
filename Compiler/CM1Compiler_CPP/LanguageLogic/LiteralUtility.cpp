#include "LiteralUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language;

std::unique_ptr<execution::IntegerValue> cMCompiler::language::buildIntegerValue(dataStructures::Type* ofType)
{
	if (ofType == getUsize() || ofType == nullptr)
		return std::make_unique<execution::IntegerValue>(8, false, getUsize());
	std::terminate(); // todo: handle custom integer types
}

std::unique_ptr<execution::StringValue> cMCompiler::language::buildStringValue()
{
	auto string = getDefaultPackage()->rootNamespace()->get<Type>("string");
	return std::make_unique<execution::StringValue>(string);
}
