#pragma once
#include <cstddef>
#include <ostream>
#include <string>
#include <gsl.h>
#include "IRuntimeValue.h"
#include "../IntermidiateRepresentation/INameGetter.hpp"

namespace cMCompiler::dataStructures::execution
{
	using number_component = unsigned char;
	using usize = unsigned long long int;

	/// <summary>
	/// arbitrary sized integer. if signed: it is a 2's compliment intiger otherwise it is natural binary
	/// </summary>
	class IntegerValue : public IRuntimeValue
	{
		std::vector<number_component> number_;
		bool isSigned_;
		std::string typeName() const final
		{
			return "integer_value";
		}
		json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final;

	public:
		IntegerValue operator+(IntegerValue& lhs);
		IntegerValue operator-(IntegerValue& lhs);
		IntegerValue operator*(IntegerValue& lhs);
		IntegerValue operator/(IntegerValue& lhs);
		static IntegerValue negotiateSize(IntegerValue& l, IntegerValue& r);
		void setValue(usize componentIndex, number_component value);
		void setValue(number_component* value, size_t size);
		void fromString(std::string const& s);
		IntegerValue(usize size, bool isSigned, Type* type) : IRuntimeValue(type), isSigned_(isSigned)
		{
			number_.resize(size, number_component(0));
		}

		// Inherited via IRuntimeValue
		std::string toString() const final;

		// Inherited via IRuntimeValue
		std::unique_ptr<IRuntimeValue> copy() const final;

		gsl::not_null<number_component*> rawNumber() { return number_.data(); }
	};
}
