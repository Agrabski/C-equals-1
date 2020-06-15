#include "Function.hpp"


using namespace cMCompiler::dataStructures;
Variable* Function::appendVariable(std::string name, Type* type)
{
	auto tmp = std::make_unique<Variable>(name, type);
	auto result = tmp.get();
	parameters_.push_back(std::move(tmp));
	return result;
}

std::vector<Variable*> cMCompiler::dataStructures::Function::parameters()
{
	auto result = std::vector<Variable*>();
	for (auto& x : parameters_)
		result.push_back(x.get());
	return result;
}
