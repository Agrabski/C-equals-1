#include "AttributeSpecialFunctionsExecution.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../DataStructures/execution/RuntimeFieldDescriptor.hpp"

using cMCompiler::dataStructures::AttributeInstance;
using cMCompiler::dataStructures::Function;
using cMCompiler::dataStructures::Variable;
using cMCompiler::dataStructures::Field;
using namespace cMCompiler::dataStructures::execution;
using cMCompiler::language::dereferenceAs;
using cMCompiler::language::runtime_value;
using namespace cMCompiler::compiler;

auto getAttributesAndSpecialFunctions(cMCompiler::dataStructures::AttributeTarget& target, std::string const& name)
{
	return target.attributes()
		| std::views::transform([&name](auto const& att)
			{
				return std::pair{ att, att->basedOn()->describingType()->getMethod(name) };
			})
		| std::views::filter([](auto const& pair)
			{
				return pair.second != nullptr;
			});
}

void executeAttachmentFunction(not_null<AttributeInstance*> attribute, not_null<Function*> function, not_null<IRuntimeValue*> arg)
{
	std::vector<runtime_value> args;
	args.push_back(ReferenceValue::make(&attribute->objectInstance(), { attribute->basedOn()->describingType(), 0 }));
	args.push_back(arg->copy());

	execute(function, std::move(args));
}

template<typename T>
void executeFunctions(T attributeFunctionPairs, not_null<IRuntimeValue*> arg)
{
	for (auto [instance, function] : attributeFunctionPairs)
		executeAttachmentFunction(instance, function, arg);
}


void executeAttachmentFunctionsForVariableDeclaration(cMCompiler::language::runtime_value& statement)
{
	using cMCompiler::dataStructures::Variable;
	not_null object = dereferenceAs<ObjectValue>(statement.get());
	auto variable = dereferenceAs<RuntimeVariableDescriptor>(object->getMemberValue("_variable").get())->value();

	auto expression = object->getRawValue("_expression");
	cMCompiler::compiler::executeAttachmentFunctionForExpression(expression);

	executeFunctions(getAttributesAndSpecialFunctions(*variable, Variable::onDeclare), statement.get());
}

void executeAttachmentFunctionsForFunctionCallStatement(cMCompiler::language::runtime_value& statement)
{
	not_null object = dereferenceAs<ObjectValue>(statement.get());

	auto function = object->getRawValue("_function");
	executeAttachmentFunctionForExpression(function);
}

void executeAttachmentFunctionsForReturn(not_null<IRuntimeValue*> statement)
{
	not_null object = dereferenceAs<ObjectValue>(statement);
	if (object->hasValue("_expression"))
		executeAttachmentFunctionForExpression(object->getRawValue("_expression"));
}

void executeAttachmentFunctionsForAssigment(cMCompiler::language::runtime_value& statement)
{
	using cMCompiler::dataStructures::Variable;
	not_null object = dereferenceAs<ObjectValue>(statement.get());
	auto rexpression = object->getRawValue("_rExpression");
	auto lexpression = object->getRawValue("_lExpression");

	cMCompiler::compiler::executeAttachmentFunctionForExpression(rexpression);
	cMCompiler::compiler::executeAttachmentFunctionForExpression(lexpression);
}

void cMCompiler::compiler::executeAttributeFunctionsForStatement(language::runtime_value& statement)
{
	not_null stmnt = statement.get();
	using language::isOfType;
	if (isOfType(stmnt, language::getVariableDeclarationStatementDescriptor()))
		return executeAttachmentFunctionsForVariableDeclaration(statement);
	if (isOfType(stmnt, language::getAssigmentStatementDescriptor()))
		return executeAttachmentFunctionsForAssigment(statement);
	if (isOfType(stmnt, language::getFunctionCallStatementDescriptor()))
		return executeAttachmentFunctionsForFunctionCallStatement(statement);
	if (isOfType(stmnt, language::getScopeTerminationStatementDescriptor()))
		return;
	if (isOfType(stmnt, language::getReturnStatementDescriptor()))
		return executeAttachmentFunctionsForReturn(stmnt);
	// todo: while statement
	// todo: if statement
	//std::terminate();
}

void executeAttibuteFunctionForVariableReferenceExpression(not_null<IRuntimeValue*> expresion)
{
	not_null object = dereferenceAs<ObjectValue>(expresion);
	auto variable = dereferenceAs<RuntimeVariableDescriptor>(object->getRawValue("_variable"))->value();

	executeFunctions(getAttributesAndSpecialFunctions(*variable, Variable::onReference), expresion);
}

void executeAttributeFunctionForFieldAccessExpression(not_null<IRuntimeValue*> expresion)
{
	not_null obj = dereferenceAs<ObjectValue>(expresion);

	auto exp = obj->getRawValue("_expression");
	auto field = dereferenceAs<RuntimeFieldDescriptor>(obj->getRawValue("_field"))->value();

	executeFunctions(getAttributesAndSpecialFunctions(*field, Field::onAccess), expresion);
	executeAttachmentFunctionForExpression(exp);
}

void executeAttributeFunctionForAddressofExpression(not_null<IRuntimeValue*> expresion)
{
	not_null object = dereferenceAs<ObjectValue>(expresion);
	executeAttachmentFunctionForExpression(object->getRawValue("_expression"));
}

void executeAttributeFunctionForBinaryOperatorExpression(not_null<IRuntimeValue*> expresion)
{
	not_null object = dereferenceAs<ObjectValue>(expresion);
	not_null cFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_compiletimeFunction"));
	not_null rFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_runtimeFunction"));

	if (cFunction->value())
		executeFunctions(getAttributesAndSpecialFunctions(*cFunction->value(), Function::onCall), expresion);
	if (rFunction->value())
		executeFunctions(getAttributesAndSpecialFunctions(*rFunction->value(), Function::onCall), expresion);
	not_null arg1 = object->getRawValue("_arg1");
	not_null arg2 = object->getRawValue("_arg2");
	executeAttachmentFunctionForExpression(arg1);
	executeAttachmentFunctionForExpression(arg2);
}

void executeAttibuteFunctionForFunctionCallExpression(not_null<IRuntimeValue*> expresion)
{
	not_null object = dereferenceAs<ObjectValue>(expresion);
	auto cFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_compiletimeFunction"));
	auto rFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_runtimeFunction"));

	if (cFunction && cFunction->value())
		executeFunctions(getAttributesAndSpecialFunctions(*cFunction->value(), Function::onCall), expresion);
	if (rFunction && rFunction->value())
		executeFunctions(getAttributesAndSpecialFunctions(*rFunction->value(), Function::onCall), expresion);
	not_null args = dereferenceAs<ArrayValue>(object->getRawValue("_arguments"));
	for (auto& arg : *args)
		executeAttachmentFunctionForExpression(arg.get());
}


void cMCompiler::compiler::executeAttachmentFunctionForExpression(not_null<IRuntimeValue*> expression)
{
	not_null exp = expression.get();

	using language::isOfType;
	if (isOfType(exp, language::getFunctionCallExpressionDescriptor()))
		return executeAttibuteFunctionForFunctionCallExpression(expression);
	if (isOfType(exp, language::getVariableReferenceExpressionDescriptor()))
		return executeAttibuteFunctionForVariableReferenceExpression(exp);
	if (isOfType(exp, language::getFieldAccessExpressionDescriptor()))
		return executeAttributeFunctionForFieldAccessExpression(exp);
	if (isOfType(exp, language::getBinaryOperatorExpressionDescriptor()))
		return executeAttributeFunctionForBinaryOperatorExpression(exp);
	if (isOfType(exp, language::getLiteralExpressionDescriptor()))
		return;
	if(isOfType(exp, language::getAdressofExpressionDescriptor()))
		return executeAttributeFunctionForAddressofExpression(exp);
	//todo: more
	//std::terminate();
}
