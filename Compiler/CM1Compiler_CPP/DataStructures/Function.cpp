#include "Function.hpp"


using namespace cMCompiler::dataStructures;
Variable* Function::appendVariable(std::string name, not_null<Type*> type)
{
	auto tmp = std::make_unique<Variable>(name, type);
	auto result = tmp.get();
	parameters_.push_back(std::move(tmp));
	return result;
}

Variable* cMCompiler::dataStructures::Function::appendLocalVariable(std::string name, not_null<Type*> type)
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

std::vector<validation::ValidationError> cMCompiler::dataStructures::Function::validateContent() const
{
	return std::vector<validation::ValidationError>();
}

FunctionFlags cMCompiler::dataStructures::operator|(FunctionFlags lhs, FunctionFlags rhs)
{
	return static_cast<FunctionFlags>(static_cast<char>(lhs) | static_cast<char>(rhs));
}

FunctionFlags cMCompiler::dataStructures::operator&(FunctionFlags lhs, FunctionFlags rhs)
{
	return static_cast<FunctionFlags>(static_cast<char>(lhs) & static_cast<char>(rhs));
}

std::ostream& cMCompiler::dataStructures::operator<<(std::ostream& stream, FunctionFlags flags)
{
	return stream << static_cast<unsigned long long>(flags);
}

std::istream& cMCompiler::dataStructures::operator>>(std::istream& stream, FunctionFlags& flags)
{
	unsigned long long tmp = 0;
	stream >> tmp;
	flags = static_cast<FunctionFlags>(tmp);
	return stream;
}
