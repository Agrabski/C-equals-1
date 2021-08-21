#include "Function.hpp"


using namespace cMCompiler::dataStructures;
not_null<Variable*> Function::appendVariable(std::string name, TypeReference type)
{
	auto tmp = std::make_unique<Variable>(name, type, this, package());
	auto result = tmp.get();
	parameters_.push_back(std::move(tmp));
	return result;
}

not_null<Variable*> cMCompiler::dataStructures::Function::appendLocalVariable(std::string name, TypeReference type)
{
	auto tmp = std::make_unique<Variable>(name, type, this, package());
	auto result = tmp.get();
	localVariables_.push_back(std::move(tmp));
	return result;
}

std::vector<not_null<Variable*>> cMCompiler::dataStructures::Function::parameters()
{
	auto result = std::vector<not_null<Variable*>>();
	for (auto const& x : parameters_)
		result.push_back(x.get());
	return result;
}

std::vector<not_null<Variable*>> cMCompiler::dataStructures::Function::variables() const
{
	auto result = std::vector<not_null<Variable*>>();
	for (auto const& x : localVariables_)
		result.push_back(x.get());
	return result;
}

std::vector<not_null<Variable const*>> cMCompiler::dataStructures::Function::parameters() const
{
	auto result = std::vector<not_null<Variable const*>>();
	for (auto& x : parameters_)
		result.push_back(x.get());
	return result;
}
std::vector<validation::ValidationError> cMCompiler::dataStructures::Function::validateContent() const
{
	return std::vector<validation::ValidationError>();
}

execution::json cMCompiler::dataStructures::Function::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"name", name()},
		{"attributes", emmitAttributes(nameLookupFunction, manager)},
		{"parameters", execution::serializeArray(parameters_, nameLookupFunction, manager)},
		{"locals", execution::serializeArray(localVariables_, nameLookupFunction, manager)},
		{"body", intermidiateRepresentation_->emmit(nameLookupFunction, manager)},
		{"return_type", nameLookupFunction.get(returnType_)}
	};
}


FunctionFlags cMCompiler::dataStructures::operator|(FunctionFlags lhs, FunctionFlags rhs)
{
	return static_cast<FunctionFlags>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));
}

FunctionFlags cMCompiler::dataStructures::operator&(FunctionFlags lhs, FunctionFlags rhs)
{
	return static_cast<FunctionFlags>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));
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
