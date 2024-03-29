#include "IntegerValue.hpp"
#include <sstream>
#include <gsl/gsl>

using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures;

number_component elementAtOr0(std::vector<number_component>& n, size_t index)
{
	if (index > n.size())
		return number_component(0);
	return n[index];
}

cMCompiler::dataStructures::execution::json cMCompiler::dataStructures::execution::IntegerValue::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager&) const
{
	return {
		{"signed", isSigned_},
		{"value", number_}
	};
}

IntegerValue cMCompiler::dataStructures::execution::IntegerValue::operator+(IntegerValue& rhs)
{
	auto result = negotiateSize(*this, rhs);
	auto overflow = number_component(0);
	for (auto i = 0; i < result.number_.size(); i++)
	{
		auto l = elementAtOr0(number_, i);
		auto r = elementAtOr0(rhs.number_, i);
		result.setValue(i, l + r + overflow);
		unsigned char result = l + r + overflow;
		if (result < l + r + overflow)
			overflow = 1;
		overflow = 0;
	}
	return result;
}

cMCompiler::dataStructures::execution::IntegerValue cMCompiler::dataStructures::execution::IntegerValue::negotiateSize(IntegerValue& l, IntegerValue& r)
{
	if (l.number_.size() > r.number_.size())
		return IntegerValue(l.number_.size(), l.isSigned_, l.type());
	return IntegerValue(r.number_.size(), r.isSigned_, l.type());
}

void cMCompiler::dataStructures::execution::IntegerValue::setValue(usize componentIndex, number_component value)
{
	assert(number_.size() > componentIndex);
	number_[componentIndex] = value;
}

void cMCompiler::dataStructures::execution::IntegerValue::fromString(std::string const& s)
{
	// usize optimisation
	if(number_.size() == 8)
		if (!isSigned_)
		{
			usize result = 0;
			std::stringstream stream(s);
			stream >> result;
			*(usize*)number_.data() = result;
		}
		else
		{

		}
}

void cMCompiler::dataStructures::execution::IntegerValue::setValue(number_component* value, size_t size)
{
	number_.reserve(size);
	for (auto i = 0; i < size; i++)
		setValue(i, value[i]);
}

std::string cMCompiler::dataStructures::execution::IntegerValue::toString() const
{
	if (number_.size() == 8)
		if (!isSigned_)
		{
			usize result = *(usize*)number_.data();
			return std::to_string(result);
		}
	std::terminate();
}

std::unique_ptr<IRuntimeValue> cMCompiler::dataStructures::execution::IntegerValue::copy() const
{
	auto result = std::make_unique<IntegerValue>(number_.size(), isSigned_, type());
	result->number_ = number_;
	return result;
}
