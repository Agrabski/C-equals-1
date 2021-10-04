#include "AttributeSpecialFunctionsExecution.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "../DataStructures/execution/RuntimeFunctionDescriptor.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "FunctionExecutionUtility.hpp"

using cMCompiler::dataStructures::AttributeInstance;
using cMCompiler::dataStructures::Function;
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
		executeAttachmentFunctionsForVariableDeclaration(statement);
	if (isOfType(stmnt, language::getAssigmentStatementDescriptor()))
		executeAttachmentFunctionsForAssigment(statement);
	if (isOfType(stmnt, language::getFunctionCallStatementDescriptor()))
		executeAttachmentFunctionsForFunctionCallStatement(statement);
	std::terminate();
}

void executeAttibuteFunctionForFunctionCallExpression(not_null<IRuntimeValue*> expresion)
{
	not_null object = dereferenceAs<ObjectValue>(expresion);
	not_null cFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_compiletimeFunction"))->value();
	not_null rFunction = dereferenceAs<RuntimeFunctionDescriptor>(object->getRawValue("_runtimetimeFunction"))->value();

	executeFunctions(getAttributesAndSpecialFunctions(*cFunction, Function::onCall), expresion);
	executeFunctions(getAttributesAndSpecialFunctions(*rFunction, Function::onCall), expresion);
	// todo: arguments
	std::terminate();
}


void cMCompiler::compiler::executeAttachmentFunctionForExpression(not_null<IRuntimeValue*> expression)
{
	not_null exp = expression.get();

	using language::isOfType;
	if (isOfType(exp, language::getFunctionCallExpressionDescriptor()))
		executeAttibuteFunctionForFunctionCallExpression(expression);
	std::terminate();
}
