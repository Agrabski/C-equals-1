#include "ExpressionUtility.hpp"
#include "TypeInstantiationUtility.hpp"
#include "IRUtility.hpp"

cMCompiler::language::runtime_value cMCompiler::language::buildValueLiteralExpression(runtime_value&& value)
{
	auto result = instantiate(getLiteralExpressionDescriptor());
	not_null object = dynamic_cast<dataStructures::execution::ObjectValue*>(result.get());
	object->setValue("value", std::move(value));
	return result;
}
