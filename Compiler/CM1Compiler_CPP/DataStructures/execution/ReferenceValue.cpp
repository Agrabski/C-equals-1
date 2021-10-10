#include "ReferenceValue.hpp"
#include <sstream>

std::string cMCompiler::dataStructures::execution::ReferenceValue::typeName() const
{
	return "reference_value";
}

std::string cMCompiler::dataStructures::execution::ReferenceValue::toString() const
{
	using namespace std::string_literals;
	std::stringstream ss;
	if (value_ == nullptr)
		return "null";
	ss << "[object at: " << value_->get() << "]"s;
	return ss.str();
}

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue> cMCompiler::dataStructures::execution::ReferenceValue::copy() const
{
	auto t = type();
	t.referenceCount -= 1;
	return make(value_, t);
}

void cMCompiler::dataStructures::execution::ReferenceValue::performAssigment(std::unique_ptr<IRuntimeValue>&& newValue)
{
	if (value_ != nullptr && newValue != nullptr && (type().referenceCount - 1 != newValue->type().referenceCount))
		throw InvalidTypeException({ type().type, type().referenceCount - 1 }, newValue->type());
	*value_ = std::move(newValue);
}
cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::ReferenceValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"value", manager.serializeReference(*value_)}
	};
}