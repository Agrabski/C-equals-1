#include "Function.hpp"


using namespace cMCompiler::dataStructures;
Variable* Function::appendVariable(std::string name, Type* type)
{
	auto tmp = std::make_unique<Variable>(name, type);
	auto result = tmp.get();
	parameters_.push_back(std::move(tmp));
	return result;
}

Variable* cMCompiler::dataStructures::Function::appendLocalVariable(std::string name, Type* type)
{
	auto tmp = std::make_unique<Variable>(name, type);
	auto result = tmp.get();
	localVariables_.push_back(std::move(tmp));
	return result;
}

std::vector<Variable*> cMCompiler::dataStructures::Function::parameters()
{
	auto result = std::vector<Variable*>();
	for (auto& x : parameters_)
		result.push_back(x.get());
	return result;
}

std::vector<ir::IInstruction*> cMCompiler::dataStructures::Function::code()
{
	auto result = std::vector<ir::IInstruction*>();
	for (auto& instruction : intermidiateRepresentation_)
		result.push_back(instruction.get());
	return result;
}

std::vector<validation::ValidationError> cMCompiler::dataStructures::Function::validateContent() const
{
	return std::vector<validation::ValidationError>();
}
