#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "CreateGetter.hpp"
#include "MetatypeUility.hpp"

using namespace cMCompiler::dataStructures;

bool cMCompiler::language::isOfType(gsl::not_null<cMCompiler::dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type)
{
	return value->type() == type;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IExpression"s);
	interface->append<Function>("pointerToSource")->setReturnType(getPointerToSource());
	interface->append<Function>("parentExpression")->setReturnType(interface);
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buidStatementDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IInstruction"s);
	interface->append<Function>("pointerToSource")->setReturnType(getPointerToSource());
	interface->append<Function>("parentStatement")->setReturnType(interface);
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildIfDescriptor(gsl::not_null<Namespace*> irNs, gsl::not_null<Type*> baseStatement, gsl::not_null<Type*> expression)
{
	auto interface = irNs->append<Type>("IIfStatement"s);
	interface->appendInterface(baseStatement);

	auto impl = irNs->append<Type>("ifStatement");
	impl->appendInterface(interface);
	impl->appendField("_pointerToSource", getPointerToSource());
	impl->appendField("_expression", expression);
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableDescriptor"s);
	result->append<Function>("_name"s)->setReturnType(getString())->setAccessibility(Accessibility::Public);
	result->append<Function>("_type"s)->setReturnType(getTypeDescriptor())->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFieldDescriptor(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("fieldDescriptor"s);
	result->append<Function>("_name"s)->setReturnType(getString())->setAccessibility(Accessibility::Public);
	result->append<Function>("_type"s)->setReturnType(getTypeDescriptor())->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableReferenceExpression(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableReferenceExpression"s);
	auto f = result->append<Function>("variable"s)->setReturnType(getVariableDescriptor());
	f->setAccessibility(Accessibility::Public);
	createGetter(f, result);
	result->appendField("_variable"s, getVariableDescriptor());
	auto t = result->append<Function>("type"s)->setReturnType(getTypeDescriptor());
	t->setAccessibility(Accessibility::Public);
	createGetter(t, result);

	result->appendField("_type", getTypeDescriptor());

	result->appendInterface(getExpressionDescriptor());
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFieldAccessExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto t = irNs->append<Type>("fieldAccessExpression");
	t->appendInterface(getExpressionDescriptor());
	t->appendField("_expression", getExpressionDescriptor());
	t->appendField("_field", getFieldDescriptor());
	createGetter(t->append<Function>("expression"), t);
	createGetter(t->append<Function>("field"), t);
	return t;
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
	//todo: finish;
	auto result = irNs->append<Type>("functionCallExpression");
	createGetter(result->append<Function>("compileTimeFunction")->setReturnType(getFunctionDescriptor()), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("runtimeTimeFunction")->setReturnType(getFunctionDescriptor()), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("arguments")->setReturnType(getCollectionTypeFor(getExpressionDescriptor())), result)->setAccessibility(Accessibility::Public);

	result->appendField("_compileTimeFunction", getFunctionDescriptor())->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeTimeFunction", getFunctionDescriptor())->setAccessibility(Accessibility::Private);
	result->appendField("_arguments", getCollectionTypeFor(getExpressionDescriptor()))->setAccessibility(Accessibility::Private);
	result->appendField("_pointerToSource", getPointerToSource())->setAccessibility(Accessibility::Private);
	result->appendField("_parent", getExpressionDescriptor())->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFunctionCallStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IFunctionCallStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("functionCallStatement");
	result->appendInterface(interface);
	result->appendField("_parent", getIInstruction())->setAccessibility(Accessibility::Private);
	result->appendField("_function", getFunctionCallExpressionDescriptor())->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildScopeTerminationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IScopeTerminationStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("scopeTerminationStatement");
	result->appendInterface(interface);
	result->appendField("_parent", getIInstruction())->setAccessibility(Accessibility::Private);
	result->appendField("_variables", getCollectionTypeFor(getVariableDescriptor()))->setAccessibility(Accessibility::Private);
	result->appendField("_pointerToSource", getPointerToSource())->setAccessibility(Accessibility::Private);
	return result;
}

void cMCompiler::language::buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Namespace>("ir"s);
	auto statement = buidStatementDescriptor(ns);
	auto expression = buildExpressionDescriptor(ns);
	buildVariableDescriptor(ns);
	buildIfDescriptor(ns, statement, expression);
	buildVariableReferenceExpression(ns);
	buildFunctionCallDescriptor(ns);
	buildFunctionCallStatementDescriptor(ns);
	buildScopeTerminationStatementDescriptor(ns);
	buildFieldAccessExpressionDescriptor(ns);
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getVariableDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("variableDescriptor");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getLiteralExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("literalExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getVariableReferenceExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("variableReferenceExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIfDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("ifStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getAssigmentStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("assigmentStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getFunctionCallExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("functionCallExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getFieldAccessExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("fieldAccessExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getScopeTerminationStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("scopeTerminationStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getFunctionCallStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("functionCallStatement");
}

cMCompiler::language::runtime_value cMCompiler::language::buildSourcePointer(std::string const& filename, antlr4::tree::ParseTree& tree)
{
	auto* current = &tree;
	while (current != nullptr && dynamic_cast<antlr4::Token*>(current) == nullptr)
		current = current->children.front().get();
	assert(current != nullptr);
	return buildPointerToSource(filename, dynamic_cast<antlr4::Token*>(current)->getLine());
}


gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIInstruction()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IInstruction");
}
