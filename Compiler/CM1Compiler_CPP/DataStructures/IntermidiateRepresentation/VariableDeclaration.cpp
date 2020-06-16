#include "VariableDeclaration.hpp"

cMCompiler::dataStructures::ir::VariableDeclaration::VariableDeclaration(std::string name, std::unique_ptr<IExpression>&& exp, Type* type) :
	variableName_(name), expression_(std::move(exp)), type_(type)
{
	if (expression_ == nullptr && type == nullptr)
		throw std::exception(); //todo: better exception
	if (type_ == nullptr)
		type_ = expression_->evaluateType();
}

bool cMCompiler::dataStructures::ir::VariableDeclaration::compileTimeExecutable() const noexcept
{
	return expression_->compileTimeExecutable();
}

void cMCompiler::dataStructures::ir::VariableDeclaration::emmit(std::ostream& stream, std::function<std::string(Type*)> const& nameLookupFunction, unsigned int indentationLevel) const
{
	for (auto i = 0U; i < indentationLevel; i++)
		stream << "\t";
	stream << "{@declare " << variableName_;
	stream << " | " << nameLookupFunction(type_);
	stream << ", expression = ";
	if (expression_ != nullptr)
		expression_->emmit(stream, nameLookupFunction);
	else
		stream << "{}";
	stream << "}";
}
