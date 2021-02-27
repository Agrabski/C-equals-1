#include "StatementEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"

using namespace cMCompiler::dataStructures::execution;

void cMCompiler::compiler::StatementEvaluator::evaluate(language::runtime_value& instruction)
{
	using language::isOfType;
	auto inst = language::dereferenceAs<ObjectValue>(instruction.get());
	if (isOfType(inst, cMCompiler::language::getFunctionCallStatementDescriptor()))
	{
		call(*inst);
		return;
	}
	if (isOfType(inst, cMCompiler::language::getAssigmentStatementDescriptor()))
	{
		assign(*inst);
		return;
	}
	if (isOfType(inst, language::getScopeTerminationStatementDescriptor()))
	{
		terminate(*inst);
		return;
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
	ev_.evaluateLeftExpression(*lExpression)->performAssigment(ev_.evaluate(*rExpression));
}

void cMCompiler::compiler::StatementEvaluator::terminate(dataStructures::execution::IRuntimeValue& instruction)
{
	not_null variables = language::dereferenceAs<ArrayValue>(language::dereferenceAs<ObjectValue>(&instruction)->getMemberValue("_variables").get());
	for (auto& var : *variables)
	{
		auto variable = language::dereferenceAs<RuntimeVariableDescriptor>(var.get())->value();
		auto finalizer = language::getFinalizer(variable->type()->methods());
		std::vector<language::runtime_value> arguments;
		arguments.push_back(ReferenceValue::make(&variables_[variable->name()], variable->type()));
		if (finalizer != nullptr)
			execute(finalizer, std::move(arguments));
	}
}
