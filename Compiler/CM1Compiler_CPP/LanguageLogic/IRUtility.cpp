#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "CreateGetter.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"

using namespace cMCompiler::dataStructures;

bool cMCompiler::language::isOfType(gsl::not_null<cMCompiler::dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type)
{
	return value->type() == type;
}

void cMCompiler::language::implementExpressionInterface(not_null<dataStructures::Type*> type)
{
	type->appendField("_type", getTypeDescriptor(), 0);
	type->appendField("_parentExpression", getExpressionDescriptor(), 1);
	type->appendField("_pointerToSource", getPointerToSource(), 0);

	createGetter(type->append<Function>("type"), type);
	createGetter(type->append<Function>("parentExpression"), type);
	createGetter(type->append<Function>("pointerToSource"), type);
	type->appendInterface(getExpressionDescriptor());
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IExpression"s);
	interface->append<Function>("pointerToSource")->setReturnType(getPointerToSource());
	interface->append<Function>("parentExpression")->setReturnType(interface);
	interface->append<Function>("type")->setReturnType(getTypeDescriptor());
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
	impl->appendField("_pointerToSource", getPointerToSource(), 0);
	impl->appendField("_expression", expression, 1);
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
	result->append<Function>("name"s)->setReturnType(getString())->setAccessibility(Accessibility::Public);
	result->append<Function>("type"s)->setReturnType(getTypeDescriptor())->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableReferenceExpression(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableReferenceExpression"s);
	auto f = result->append<Function>("variable"s)->setReturnType(getVariableDescriptor());
	f->setAccessibility(Accessibility::Public);
	createGetter(f, result);
	result->appendField("_variable"s, getVariableDescriptor(), 0);
	auto t = result->append<Function>("type"s)->setReturnType(getTypeDescriptor());
	t->setAccessibility(Accessibility::Public);
	createGetter(t, result);

	result->appendField("_type", getTypeDescriptor(), 0);

	implementExpressionInterface(result);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFieldAccessExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	using namespace cMCompiler::dataStructures::execution;
	auto t = irNs->append<Type>("fieldAccessExpression");
	t->appendInterface(getExpressionDescriptor());
	t->appendField("_expression", getExpressionDescriptor(), 1);
	t->appendField("_field", getFieldDescriptor(), 0);
	createGetter(t->append<Function>("expression"), t);
	createGetter(t->append<Function>("field"), t);
	t->appendField("_type", getTypeDescriptor(), 0);
	t->appendField("_parentExpression", getExpressionDescriptor(), 1);
	t->appendField("_pointerToSource", getPointerToSource(), 0);

	t->append<Function>("parentExpression")->setReturnType(getExpressionDescriptor());

	createCustomFunction(t->append<Function>("type"), t, [](value_map&& a, generic_parameters) -> runtime_value
		{
			auto type = dynamic_cast<RuntimeFieldDescriptor&>(
				*dereference(
					dynamic_cast<ObjectValue*>(
						dereference(not_null(a["self"].get())))->getMemberValue("_field").get())).value()->type();
			return createTypeDescriptor(type);
		})->setReturnType(getTypeDescriptor());
	createGetter(t->append<Function>("pointerToSource"), t);
	t->appendInterface(getExpressionDescriptor());
	return t;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildAssigmentStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irns)
{
	auto result = irns->append<Type>("assigmentStatement");
	result->appendInterface(getIInstruction());
	result->appendField("_lExpression", getExpressionDescriptor(), 1);
	createGetter(result->append<Function>("lExpression"), result);
	result->appendField("_rExpression", getExpressionDescriptor(), 1);
	createGetter(result->append<Function>("rExpression"), result);
	result->appendField("_pointerToSource", getPointerToSource(), 0);
	createGetter(result->append<Function>("pointerToSource"), result);
	return result;
}


gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	using namespace cMCompiler::dataStructures::execution;
	auto t = irNs->append<Type>("literalExpression");
	t->appendField("_value", nullptr, 1);
	createGetter(t->append<Function>("value"), t);
	t->appendField("_parentExpression", getExpressionDescriptor(), 1);
	t->appendField("_pointerToSource", getPointerToSource(), 0);

	createCustomFunction(t->append<Function>("type"), t, [](value_map&& a, generic_parameters) -> runtime_value
		{
			auto value = dereference(dereferenceAs<ObjectValue>(not_null(a["self"].get()))->getMemberValue("_value").get());
			return getValueFor(value->type());
		})->setReturnType(getTypeDescriptor());
	createGetter(t->append<Function>("parentExpression"), t);
	createGetter(t->append<Function>("pointerToSource"), t);
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
	implementExpressionInterface(result);

	result->appendField("_compileTimeFunction", getFunctionDescriptor(), 0)->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeTimeFunction", getFunctionDescriptor(), 0)->setAccessibility(Accessibility::Private);
	result->appendField("_arguments", getCollectionTypeFor(getExpressionDescriptor()), 0)->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFunctionCallStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IFunctionCallStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("functionCallStatement");
	result->appendInterface(interface);
	result->appendField("_parent", getIInstruction(), 1)->setAccessibility(Accessibility::Private);
	result->appendField("_function", getFunctionCallExpressionDescriptor(), 1)->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildScopeTerminationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IScopeTerminationStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("scopeTerminationStatement");
	result->appendInterface(interface);
	result->appendField("_parent", getIInstruction(), 1)->setAccessibility(Accessibility::Private);
	result->appendField("_variables", getCollectionTypeFor(getVariableDescriptor()), 0)->setAccessibility(Accessibility::Private);
	result->appendField("_pointerToSource", getPointerToSource(), 0)->setAccessibility(Accessibility::Private);
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
	buildAssigmentStatementDescriptor(ns);
	buildLiteralExpressionDescriptor(ns);
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
	while (current != nullptr && dynamic_cast<antlr4::tree::TerminalNode*>(current) == nullptr)
		current = current->children.front().get();
	assert(current != nullptr);
	return buildPointerToSource(filename, dynamic_cast<antlr4::tree::TerminalNodeImpl*>(current)->getSymbol()->getLine());
}


gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIInstruction()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IInstruction");
}
