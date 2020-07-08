#include "StatementEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
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
	auto* const boolean = dynamic_cast<dataStructures::execution::BooleanValue*>(expressionValue.get());
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
		auto* const type = variable->type();
		auto* const finalizer = language::getFinalizer(type->methods());
		if (finalizer != nullptr)
		{
			auto value = std::vector{ variables_[variable->name()].get() };
			execute(finalizer, value, resolver_, context_);
		}
		variables_.erase(variable->name());
	}
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::IInstruction& instruction)
{
	instruction.accept(*this);
}

void cMCompiler::compiler::StatementEvaluator::visit(dataStructures::ir::AssigmentStatement& statement)
{
	ev_.evaluateLValue(statement.lexpression())->performAssigment(ev_.evaluate(statement.rexpression()));
}
