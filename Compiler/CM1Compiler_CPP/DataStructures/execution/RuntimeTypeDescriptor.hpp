#pragma once
#include "IRuntimeValue.h"
#include "../Type.hpp"
#include "../IntermidiateRepresentation/INameGetter.hpp"

namespace cMCompiler::dataStructures::execution
{
	class RuntimeTypeDescriptor : IRuntimeValue
	{
		Type* value_;
		// Inherited via IRuntimeValue
		void emmit(std::ostream& stream, ir::INameGetter const& nameLookupFunction) const final;
		std::string toString() const final;
	};
}
