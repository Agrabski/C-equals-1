#include "StatementEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../DataStructures/execution/IRuntimeValue.h"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"

using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::language;

std::optional<runtime_value> cMCompiler::compiler::StatementEvaluator::evaluate(language::runtime_value& instruction)
{
	using language::isOfType;
	auto inst = language::dereferenceAs<ObjectValue>(instruction.get());
	if (isOfType(inst, cMCompiler::language::getFunctionCallStatementDescriptor()))
	{
		call(*inst);
		return {};
	}
	if (isOfType(inst, cMCompiler::language::getAssigmentStatementDescriptor()))
	{
		assign(*inst);
		return {};
	}
	if (isOfType(inst, language::getScopeTerminationStatementDescriptor()))
	{
		terminate(*inst);
		return {};
	}
	if (isOfType(inst, language::getVariableDeclarationStatementDescriptor()))
	{
		declareVariable(*inst);
		return {};
	}
	if (isOfType(inst, language::getReturnStatementDescriptor()))
	{
		auto expression = inst->getMemberValue("_expression")->value();
		return ev_.evaluate(**expression);
	}
	if (isOfType(inst, language::getIfDescriptor()))
	{
		auto expression = inst->getMemberValue("_expression")->value();
		auto value = ev_.evaluate(**expression);
		ArrayValue* code = nullptr;
		if (language::dereferenceAs<BooleanValue>(value.get())->value())
			code = dereferenceAs<ArrayValue>(inst->getMemberValue("_ifBranch")->value()->get());
		else
			code = dereferenceAs<ArrayValue>(inst->getMemberValue("_elseBranch")->value()->get());
		for (auto& i : *code)
			if (auto r = evaluate(i))
				return r;
		return {};
	}
	if (isOfType(inst, language::getWhileDescriptor()))
	{
		auto expression = inst->getMemberValue("_expression")->value();
		auto code = dereferenceAs<ArrayValue>(inst->getMemberValue("_body")->value()->get());
		auto expressionValue = ev_.evaluate(**expression);
		while (dereferenceAs<BooleanValue>(expressionValue.get())->value())
		{
			for (auto& i : *code)
				if (auto r = evaluate(i))
					return r;
			expressionValue = ev_.evaluate(**expression);
		}
		return {};
	}
	std::terminate();
}

void cMCompiler::compiler::StatementEvaluator::call(IRuntimeValue& instruction)
{
	ev_.evaluate(*language::dereferenceAs<ObjectValue>(&instruction)->getMemberValue("_function"));
}

void cMCompiler::compiler::StatementEvaluator::assign(dataStructures::execution::IRuntimeValue& instruction)
{
	using utilities::pointer_cast;
	auto lExpression = pointer_cast<IRuntimeValue>(language::dereferenceAs<ObjectValue>(&instruction)->getMemberValue("_lExpression"));
	auto rExpression = pointer_cast<IRuntimeValue>(language::dereferenceAs<ObjectValue>(&instruction)->getMemberValue("_rExpression"));
	auto lvalue = ev_.evaluateLeftExpression(*lExpression);
	auto rvalue = ev_.evaluate(*rExpression);
	lvalue->performAssigment(std::move( rvalue));
}

void cMCompiler::compiler::StatementEvaluator::declareVariable(dataStructures::execution::IRuntimeValue& instruction)
{
	using language::dereferenceAs;
	using language::dereferenceOnce;
	using dataStructures::execution::RuntimeVariableDescriptor;
	not_null i = dereferenceAs<ObjectValue>(&instruction);
	not_null variable = dereferenceAs<RuntimeVariableDescriptor>(i->getMemberValue("_variable").get())->value();
	auto expression = i->getMemberValue("_expression");
	auto value = ev_.evaluate(*expression);
	this->variables_[variable->name()] = dereferenceOnce(value.get())->copy();
}

void cMCompiler::compiler::StatementEvaluator::terminate(dataStructures::execution::IRuntimeValue& instruction)
{
	not_null variables = language::dereferenceAs<ArrayValue>(language::dereferenceAs<ObjectValue>(&instruction)->getMemberValue("_variables").get());
	for (auto& var : *variables)
	{
		auto variable = language::dereferenceAs<RuntimeVariableDescriptor>(var.get())->value();
		if (variable->type().referenceCount == 0)
		{
			auto finalizer = language::getFinalizer(variable->type().type->methods());
			std::vector<language::runtime_value> arguments;
			arguments.push_back(ReferenceValue::make(&variables_[variable->name()], variable->type()));
			if (finalizer != nullptr)
				execute(finalizer, std::move(arguments));
		}
	}
}
