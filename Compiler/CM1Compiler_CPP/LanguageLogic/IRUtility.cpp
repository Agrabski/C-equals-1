#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::dataStructures;

bool cMCompiler::language::isOfType(gsl::not_null<cMCompiler::dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type)
{
	return value->type() == type;
}

gsl::not_null<Type*> cMCompiler::language::buidStatementDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IStatement"s);
	interface->append<Function>("pointerToSource")->setReturnType(getPointerToSource());
	interface->append<Function>("parentStatement")->setReturnType(interface);
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildIfDescriptor(gsl::not_null<Namespace*> irNs, gsl::not_null<Type*> baseStatement)
{
	auto interface = irNs->append<Type>("IIfStatement"s);
	interface->appendInterface(baseStatement);

	auto impl = irNs->append<Type>("ifStatement");
	impl->appendInterface(interface);
	impl->appendField("_pointerToSource", getPointerToSource());
	impl->appendField("_expression", getExpressionDescriptor());
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto result = irNs->append<Type>("IVariableDescriptor"s);
	result->append<Function>("name"s)->setReturnType(getString())->setAccessibility(Accessibility::Public);
	result->append<Function>("type"s)->setReturnType(getTypeDescriptor())->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto t = irNs->append<Type>("literalExpression");
	t->appendField("value", nullptr);
	t->appendInterface(getExpressionDescriptor());
	return t;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFunctionCallDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("IFunctionCallDescriptor");
	result->append<Function>("compileTimeFunction")->setReturnType(getFunctionDescriptor())->setAccessibility(Accessibility::Public);
	result->append<Function>("runtimeTimeFunction")->setReturnType(getFunctionDescriptor())->setAccessibility(Accessibility::Public);
	result->append<Function>("arguments")->setReturnType(getCollectionTypeFor(getExpressionDescriptor()))->setAccessibility(Accessibility::Public);
	std::terminate();
}

void cMCompiler::language::buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Namespace>("ir"s);
	auto statement = buidStatementDescriptor(ns);
	buildIfDescriptor(ns, statement);
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getVariableDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("variableDescriptor");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getLiteralExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("literalExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getVariableReferenceExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("variableReferenceExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIfDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("ifStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getAssigmentStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("assigmentStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getFunctionCallDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("functionCallExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getScopeTerminationStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("scopeTerminationStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIInstruction()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("std")->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IInstruction");
}
