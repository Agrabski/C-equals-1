#pragma once
#include <functional>
#include <ostream>
#include "../IntermidiateRepresentation/INameGetter.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
}

namespace cMCompiler::dataStructures::execution
{
	class IRuntimeValue
	{
		Type* type_;
	public:
		IRuntimeValue(Type* type) noexcept: type_(type)
		{}
		Type* type() const noexcept { return type_; }
		virtual void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const = 0;
		virtual std::string toString() const = 0;

	};
}
