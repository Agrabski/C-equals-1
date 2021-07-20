#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
#include "CreateGetter.hpp"
#include "MetatypeUility.hpp"
#include "RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "GetterExecution.hpp"
#include "../Parser/antlr4-runtime.h"
#include "LiteralUtility.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
using namespace cMCompiler::dataStructures::execution;

using namespace cMCompiler::dataStructures;

int cMCompiler::language::getLineNumber(antlr4::tree::ParseTree* tree)
{
	auto current = tree;
	while (current != nullptr && dynamic_cast<antlr4::tree::TerminalNode*>(current) == nullptr)
		current = current->children.front().get();
	assert(current != nullptr);
	return dynamic_cast<antlr4::tree::TerminalNodeImpl*>(current)->getSymbol()->getLine();

}

void implementStatementInterface(not_null<cMCompiler::dataStructures::Type*>type)
{
	using namespace cMCompiler::language;
	createGetter(type->append<Function>("pointerToSource"), type)->setReturnType({ getPointerToSource(), 0 });

}

bool cMCompiler::language::isOfType(gsl::not_null<cMCompiler::dataStructures::execution::IRuntimeValue*> value, gsl::not_null<dataStructures::Type*> type)
{
	auto concreteValue = dereference(value);
	return concreteValue->type().type == type;
}

void cMCompiler::language::implementExpressionInterface(not_null<dataStructures::Type*> type)
{
	type->appendField("_type", { getTypeDescriptor(), 0 });
	type->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	type->appendField("_pointerToSource", { getPointerToSource(), 0 });

	createGetter(type->append<Function>("type"), type);
	createGetter(type->append<Function>("parentExpression"), type);
	createGetter(type->append<Function>("pointerToSource"), type);
	type->appendInterface(getExpressionDescriptor());
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IExpression"s);
	interface->append<Function>("pointerToSource")->setReturnType({ getPointerToSource(), 0 });
	interface->append<Function>("parentExpression")->setReturnType({ interface, 1 });
	interface->append<Function>("type")->setReturnType({ getTypeDescriptor(),1 });
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buidStatementDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IInstruction"s);
	interface->append<Function>("pointerToSource")->setReturnType({ getPointerToSource(), 0 });
	interface->append<Function>("parentStatement")->setReturnType({ interface, 1 });
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildReturnDescriptor(gsl::not_null<dataStructures::Namespace*> irNs, gsl::not_null<dataStructures::Type*> baseStatement, gsl::not_null<dataStructures::Type*> expression)
{
	auto impl = irNs->append<Type>("returnStatement");
	impl->appendInterface(baseStatement);
	impl->appendField("_pointerToSource", { getPointerToSource(), 0 });
	impl->appendField("_expression", { expression, 1 });
	impl->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	implementStatementInterface(impl);
	return impl;
}

gsl::not_null<Type*> cMCompiler::language::buildIfDescriptor(gsl::not_null<Namespace*> irNs, gsl::not_null<Type*> baseStatement, gsl::not_null<Type*> expression)
{
	auto interface = irNs->append<Type>("IIfStatement"s);
	interface->appendInterface(baseStatement);

	auto impl = irNs->append<Type>("ifStatement");
	impl->appendInterface(interface);
	impl->appendField("_pointerToSource", { getPointerToSource(), 0 });
	impl->appendField("_expression", { expression, 1 });
	impl->appendField("_ifBranch", { getCollectionTypeFor({getIInstruction(),1}), 0 });
	impl->appendField("_elseBranch", { getCollectionTypeFor({getIInstruction(),1}), 0 });
	impl->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	implementStatementInterface(impl);

	return interface;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildWhileDescriptor(gsl::not_null<dataStructures::Namespace*> irNs, gsl::not_null<dataStructures::Type*> baseStatement, gsl::not_null<dataStructures::Type*> expression)
{
	auto interface = irNs->append<Type>("IWhileStatement"s);
	interface->appendInterface(baseStatement);

	auto impl = irNs->append<Type>("whileStatement");
	impl->appendInterface(interface);
	impl->appendField("_pointerToSource", { getPointerToSource(), 0 });
	impl->appendField("_expression", { expression, 1 });
	impl->appendField("_body", { getCollectionTypeFor({baseStatement, 1}), 0 });
	impl->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	implementStatementInterface(impl);

	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableDescriptor"s);
	createCustomFunction(
		result
		->append<Function>("name"s)
		->setReturnType({ getString(), 0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeVariableDescriptor>(a["self"].get())->value();
			return buildStringValue(self->name());
		}
	)->setAccessibility(Accessibility::Public);
	createCustomFunction(
		result
		->append<Function>("type"s)
		->setReturnType({ getTypeDescriptor(), 0 }),
		result,
		[](auto&& a, auto b)
		{
			auto self = dereferenceAs<RuntimeVariableDescriptor>(a["self"].get())->value();
			return getValueFor(self->type());
		}
	)->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFieldDescriptor(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto result = compilerNs->append<Type>("fieldDescriptor"s);
	createCustomFunction(
		result->append<Function>("name"s)
		->setReturnType({ getString(), 0 }),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<dataStructures::execution::RuntimeFieldDescriptor>(a["self"].get())->value();
			return buildStringValue(self->name());
		}
	)->setAccessibility(Accessibility::Public);
	createCustomFunction(
		result->append<Function>("type"s)
		->setReturnType({ getTypeDescriptor(), 0 }),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<dataStructures::execution::RuntimeFieldDescriptor>(a["self"].get())->value();
			return getValueFor(self->type());
		}
	)->setAccessibility(Accessibility::Public);
	createCustomFunction(
		result->append<Function>("typeReferenceCount"s)
		->setReturnType({ getUsize(), 0 }),
		result,
		[](auto&& a, auto)
		{
			auto self = dereferenceAs<dataStructures::execution::RuntimeFieldDescriptor>(a["self"].get())->value();
			return buildIntegerValue(getUsize(), self->type().referenceCount);
		}
	)->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableReferenceExpression(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableReferenceExpression"s);
	auto f = result->append<Function>("variable"s)->setReturnType({ getVariableDescriptor(), 0 });
	f->setAccessibility(Accessibility::Public);
	createGetter(f, result);
	result->appendField("_variable"s, { getVariableDescriptor(), 0 });
	auto t = result->append<Function>("type"s)->setReturnType({ getTypeDescriptor(), 0 });
	t->setAccessibility(Accessibility::Public);
	createGetter(t, result);

	result->appendField("_type", { getTypeDescriptor(), 0 });

	implementExpressionInterface(result);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFieldAccessExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	using namespace cMCompiler::dataStructures::execution;
	auto t = irNs->append<Type>("fieldAccessExpression");
	t->appendInterface(getExpressionDescriptor());
	t->appendField("_expression", { getExpressionDescriptor(), 1 });
	t->appendField("_field", { getFieldDescriptor(), 0 });
	createGetter(t->append<Function>("expression"), t);
	createGetter(t->append<Function>("field"), t);
	t->appendField("_type", { getTypeDescriptor(), 0 });
	t->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	t->appendField("_pointerToSource", { getPointerToSource(), 0 });

	t->append<Function>("parentExpression")->setReturnType({ getExpressionDescriptor(), 1 });

	createCustomFunction(t->append<Function>("type"), t, [](value_map&& a, generic_parameters) -> runtime_value
		{
			auto type = dynamic_cast<RuntimeFieldDescriptor&>(
				*dereference(
					dynamic_cast<ObjectValue*>(
						dereference(not_null(a["self"].get())))->getMemberValue("_field").get())).value()->type();
			return createTypeDescriptor(type);
		})->setReturnType({ getTypeDescriptor(), 0 });
		createGetter(t->append<Function>("pointerToSource"), t);
		t->appendInterface(getExpressionDescriptor());
		return t;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildBinaryOperatorExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("binaryOperatorExpression");

	result->appendField("_compiletimeFunction", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeFunction", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_arg1", { getExpressionDescriptor(), 1 });
	result->appendField("_arg2", { getExpressionDescriptor(), 1 });

	result->appendField("_pointerToSource", { getPointerToSource(), 0 });
	createGetter(result->append<Function>("pointerToSource"), result);

	createCustomFunction(result->append<Function>("type")->setReturnType({ getTypeDescriptor(), 0 }), result, [](value_map&& a, generic_parameters)->runtime_value
		{
			auto fr = dereferenceAs<RuntimeFunctionDescriptor>(utilities::pointer_cast<dataStructures::execution::IRuntimeValue>(dereferenceAs<dataStructures::execution::ObjectValue>(a["self"].get())->getMemberValue("_runtimeFunction")).get());
			auto fc = dereferenceAs<RuntimeFunctionDescriptor>(utilities::pointer_cast<dataStructures::execution::IRuntimeValue>(dereferenceAs<dataStructures::execution::ObjectValue>(a["self"].get())->getMemberValue("_compiletimeFunction")).get());
			if (fr != nullptr)
				return getValueFor(fr->value()->returnType());
			else
				return getValueFor(fc->value()->returnType());
		})->setAccessibility(Accessibility::Public);
		result->appendInterface(getExpressionDescriptor());
		result->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
		createGetter(result->append<Function>("parentExpression"), result);

		return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildConstructorInvocationExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("constructorInvocationExpression");
	result->appendInterface(getExpressionDescriptor());
	createGetter(result->append<Function>("compiletimeConstructor")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("runtimetimeConstructor")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("arguments")->setReturnType({ getCollectionTypeFor({getExpressionDescriptor(), 1}), 1 }), result)->setAccessibility(Accessibility::Public);
	result->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });

	createCustomFunction(result->append<Function>("type"), result,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto self = dereferenceAs<ObjectValue>(a["self"].get());
			return getValueFor(dynamic_cast<Type*>(dereferenceAs<RuntimeFunctionDescriptor>(self->getMemberValue("_runtimeConstructor").get())->value()->parent()));
		}
	);
	createGetter(result->append<Function>("parentExpression"), result);
	createGetter(result->append<Function>("pointerToSource"), result);
	result->appendInterface(getExpressionDescriptor());

	result->appendField("_compiletimeConstructor", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeConstructor", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_arguments", { getCollectionTypeFor({getExpressionDescriptor(), 1}), 0 })->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildAssigmentStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irns)
{
	auto result = irns->append<Type>("assigmentStatement");
	result->appendInterface(getIInstruction());
	result->appendField("_lExpression", { getExpressionDescriptor(), 1 });
	result->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	createGetter(result->append<Function>("lExpression"), result);
	result->appendField("_rExpression", { getExpressionDescriptor(), 1 });
	createGetter(result->append<Function>("rExpression"), result);
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });
	createGetter(result->append<Function>("pointerToSource"), result);
	return result;
}


gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	using namespace cMCompiler::dataStructures::execution;
	auto t = irNs->append<Type>("literalExpression");
	t->appendField("_value", { nullptr, 1 });
	createGetter(t->append<Function>("value"), t);
	t->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	t->appendField("_pointerToSource", { getPointerToSource(), 0 });
	t->appendInterface(getExpressionDescriptor());

	createCustomFunction(t->append<Function>("type"), t, [](value_map&& a, generic_parameters) -> runtime_value
		{
			auto value = dereference(dereferenceAs<ObjectValue>(not_null(a["self"].get()))->getMemberValue("_value").get());
			return getValueFor(value->type());
		})->setReturnType({ getTypeDescriptor(), 1 });
		createGetter(t->append<Function>("parentExpression"), t);
		createGetter(t->append<Function>("pointerToSource"), t);
		t->appendInterface(getExpressionDescriptor());
		return t;
}

gsl::not_null<Type*> cMCompiler::language::buildArrayLiteralExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	using namespace cMCompiler::dataStructures::execution;
	auto t = irNs->append<Type>("arrayLiteralExpression");
	t->appendField("_value", { nullptr, 1 });
	t->appendField("_type", { getTypeDescriptor(), 0 });
	t->appendField("_elementType", { getTypeDescriptor(), 0 });
	createGetter(t->append<Function>("value"), t);
	t->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	t->appendField("_pointerToSource", { getPointerToSource(), 0 });
	t->appendInterface(getExpressionDescriptor());

	createCustomFunction(t->append<Function>("type"), t, [](value_map&& a, generic_parameters) -> runtime_value
		{
			auto value = dereferenceAs<RuntimeTypeDescriptor>(dereferenceAs<ObjectValue>(not_null(a["self"].get()))->getMemberValue("_type").get());
			return value->copy();
		})->setReturnType({ getTypeDescriptor(), 1 });
		createGetter(t->append<Function>("parentExpression"), t);
		createGetter(t->append<Function>("pointerToSource"), t);
		t->appendInterface(getExpressionDescriptor());
		return t;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildAdressofExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("adressofExpression"s);
	auto f = result->append<Function>("expression"s)->setReturnType({ getExpressionDescriptor(), 1 });
	f->setAccessibility(Accessibility::Public);
	createGetter(f, result);
	result->appendField("_expression"s, { getExpressionDescriptor(), 1 });
	auto t = result->append<Function>("type"s)->setReturnType({ getTypeDescriptor(), 0 });
	t->setAccessibility(Accessibility::Public);
	createCustomFunction(
		t,
		result,
		[](auto&& a, auto b) -> runtime_value
		{
			auto self = dereferenceAs<ObjectValue>(a["self"].get());
			auto expression = utilities::pointer_cast<dataStructures::execution::IRuntimeValue>((*self->getMemberValue("_expression")->value())->copy());
			auto result = executeGetter<TypeReference>(expression, "type");
			result.referenceCount += 1;
			return getValueFor(result);
		}
	);


	result->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });

	createGetter(result->append<Function>("parentExpression"), result);
	createGetter(result->append<Function>("pointerToSource"), result);
	result->appendInterface(getExpressionDescriptor());
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFunctionCallDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	//todo: finish;
	auto result = irNs->append<Type>("functionCallExpression");
	createGetter(result->append<Function>("compiletimeFunction")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("runtimetimeFunction")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("arguments")->setReturnType({ getCollectionTypeFor({getExpressionDescriptor(), 1}),1 }), result)->setAccessibility(Accessibility::Public);
	result->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });

	createCustomFunction(result->append<Function>("type"), result,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto self = dereferenceAs<ObjectValue>(a["self"].get());
			auto f = dereferenceAs<RuntimeFunctionDescriptor>(self->getMemberValue("_runtimeFunction").get());
			if (f == nullptr || f->value() == nullptr)
				f = dereferenceAs<RuntimeFunctionDescriptor>(self->getMemberValue("_compiletimeFunction").get());
			return getValueFor(f->value()->returnType());
		}
	);
	createGetter(result->append<Function>("parentExpression"), result);
	createGetter(result->append<Function>("pointerToSource"), result);
	result->appendInterface(getExpressionDescriptor());

	result->appendField("_compiletimeFunction", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeFunction", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_arguments", { getCollectionTypeFor({getExpressionDescriptor(),1}), 0 })->setAccessibility(Accessibility::Private);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildFunctionCallStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IFunctionCallStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("functionCallStatement");
	result->appendInterface(interface);
	result->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	result->appendField("_function", { getFunctionCallExpressionDescriptor(), 1 })->setAccessibility(Accessibility::Private);
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });

	implementStatementInterface(result);

	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildScopeTerminationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IScopeTerminationStatement");
	interface->appendInterface(getIInstruction());
	auto result = irNs->append<Type>("scopeTerminationStatement");
	result->appendInterface(interface);
	result->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	result->appendField("_variables", { getCollectionTypeFor({getVariableDescriptor(),0}), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_pointerToSource", { getPointerToSource(), 0 })->setAccessibility(Accessibility::Private);
	implementStatementInterface(result);
	return result;
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::buildVariableDeclarationStatementDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("variableDeclarationStatement");
	result->appendInterface(getIInstruction());
	result->appendField("_parent", { getIInstruction(), 1 })->setAccessibility(Accessibility::Private);
	result->appendField("_variable", { getVariableDescriptor(), 0 });
	createGetter(result->append<Function>("variable"), result);
	result->appendField("_expression", { getExpressionDescriptor(), 1 });
	createGetter(result->append<Function>("expression"), result);
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });
	implementStatementInterface(result);
	return result;
}

gsl::not_null<Type*> cMCompiler::language::buildNewExpressionDescriptor(gsl::not_null<dataStructures::Namespace*> irNs)
{
	auto result = irNs->append<Type>("newExpression");
	createGetter(result->append<Function>("newOperator")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("compiletimeConstructor")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("runtimeConstructor")->setReturnType({ getFunctionDescriptor(), 0 }), result)->setAccessibility(Accessibility::Public);
	createGetter(result->append<Function>("arguments")->setReturnType({ getCollectionTypeFor({getExpressionDescriptor(), 1}),1 }), result)->setAccessibility(Accessibility::Public);
	result->appendField("_parentExpression", { getExpressionDescriptor(), 1 });
	result->appendField("_pointerToSource", { getPointerToSource(), 0 });

	createCustomFunction(result->append<Function>("type"), result,
		[](value_map&& a, generic_parameters)->runtime_value
		{
			auto self = dereferenceAs<ObjectValue>(a["self"].get());
			auto f = dereferenceAs<RuntimeFunctionDescriptor>(self->getMemberValue("_compiletimeNewOperator").get());
			if (f == nullptr)
			{
				f = dereferenceAs<RuntimeFunctionDescriptor>(self->getMemberValue("_runtimeNewOperator").get());
			}
			else
				return getValueFor(f->value()->returnType());
		}
	);
	createGetter(result->append<Function>("parentExpression"), result);
	createGetter(result->append<Function>("pointerToSource"), result);
	result->appendInterface(getExpressionDescriptor());

	result->appendField("_runtimeNewOperator", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_compiletimeNewOperator", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_compiletimeConstructor", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_runtimeConstructor", { getFunctionDescriptor(), 0 })->setAccessibility(Accessibility::Private);
	result->appendField("_sourcePointer", { getPointerToSource(), 0 });
	result->appendField("_arguments", { getCollectionTypeFor({getExpressionDescriptor(),1}), 0 })->setAccessibility(Accessibility::Private);
	return result;
}

void cMCompiler::language::buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Namespace>("ir"s);
	buildVariableDescriptor(ns);
	auto statement = buidStatementDescriptor(ns);
	auto expression = buildExpressionDescriptor(ns);
	buildIfDescriptor(ns, statement, expression);
	buildReturnDescriptor(ns, statement, expression);
	buildVariableReferenceExpression(ns);
	buildFunctionCallDescriptor(ns);
	buildFunctionCallStatementDescriptor(ns);
	buildScopeTerminationStatementDescriptor(ns);
	buildFieldAccessExpressionDescriptor(ns);
	buildAssigmentStatementDescriptor(ns);
	buildLiteralExpressionDescriptor(ns);
	buildArrayLiteralExpressionDescriptor(ns);
	buildVariableDeclarationStatementDescriptor(ns);
	buildBinaryOperatorExpressionDescriptor(ns);
	buildConstructorInvocationExpressionDescriptor(ns);
	buildWhileDescriptor(ns, statement, expression);
	buildAdressofExpressionDescriptor(ns);
	buildNewExpressionDescriptor(ns);
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

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getWhileDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("whileStatement");
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

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getBinaryOperatorExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("binaryOperatorExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getConstructorInvocationExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("constructorInvocationExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getAdressofExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("adressofExpression");
}

gsl::not_null<Type*> cMCompiler::language::getNewExpressionDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("newExpression");
}

gsl::not_null<Type*> cMCompiler::language::getArrayLiteralExpression()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("arrayLiteralExpression");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getScopeTerminationStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("scopeTerminationStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getFunctionCallStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("functionCallStatement");
}

gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getVariableDeclarationStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("variableDeclarationStatement");
}

gsl::not_null<Type*> cMCompiler::language::getReturnStatementDescriptor()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("returnStatement");
}

cMCompiler::language::runtime_value cMCompiler::language::buildSourcePointer(std::string const& filename, antlr4::tree::ParseTree& tree)
{
	auto* current = &tree;
	while (current != nullptr && dynamic_cast<antlr4::tree::TerminalNode*>(current) == nullptr)
		current = current->children.front().get();
	assert(current != nullptr);
	return buildPointerToSource(filename, dynamic_cast<antlr4::tree::TerminalNodeImpl*>(current)->getSymbol()->getLine());
}

cMCompiler::dataStructures::SourcePointer cMCompiler::language::getSourcePointerFromInstruction(runtime_value& instruction)
{
	return executeGetter<SourcePointer>(instruction, "pointerToSource");
}


gsl::not_null<cMCompiler::dataStructures::Type*> cMCompiler::language::getIInstruction()
{
	return getDefaultPackage()->rootNamespace()->get<Namespace>("compiler")->get<Namespace>("ir")->get<Type>("IInstruction");
}
