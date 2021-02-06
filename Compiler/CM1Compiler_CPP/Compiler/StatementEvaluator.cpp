#include "StatementEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "FunctionExecutionUtility.hpp"

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::FunctionCall& call)
{
	auto result = ev_.evaluate(&call);
	//todo: warn value discarded
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::VariableDeclaration& decl)
{
	//todo: validate variable name
	variables_[decl.name()] = ev_.evaluate(decl.expression());
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::IfElseStatement& statemnt)
{
	auto expressionValue = ev_.evaluate(statemnt.expression());
	auto const* const boolean = dynamic_cast<dataStructures::execution::BooleanValue*>(expressionValue.get());
	assert(boolean != nullptr);
	if (boolean->value())
		for (auto instruction : statemnt.ifBranch())
			instruction->accept(*this);
	else
		for (auto instruction : statemnt.elseBranch())
			instruction->accept(*this);
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::ScopeTermination& instruction)
{
	using dataStructures::Variable;
	auto const& variables = instruction.variablesToFinalize();
	for (not_null<Variable*> variable : variables)
	{
		auto const type = variable->type();
		auto* const finalizer = language::getFinalizer(type->methods());
		if (finalizer != nullptr)
		{
			auto value = std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
			value.push_back(std::move(variables_[variable->name()]));
			execute(finalizer, std::move(value), resolver_, context_);
		}
		variables_.erase(variable->name());
	}
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::IInstruction& instruction)
{
	instruction.accept(*this);
}

void cMCompiler::compiler::StatementEvaluator::evaluate(language::runtime_value& instruction)
{
	using language::isOfType;
	if (isOfType(instruction.get(), cMCompiler::language::getFunctionCallDescriptor()))
		call(instruction);
	std::terminate();
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::AssigmentStatement& statement)
{
	auto value = ev_.evaluate(statement.rexpression());
	if (dynamic_cast<dataStructures::execution::ReferenceValue*>(value.get()))
		value = (*dynamic_cast<dataStructures::execution::ReferenceValue*>(value.get())->value())->copy();
	ev_.evaluateLValue(statement.lexpression())->performAssigment(std::move(value));
}

void cMCompiler::compiler::StatementEvaluator::call(language::runtime_value& instruction)
{
	ev_.evaluate(*instruction.get());
}
