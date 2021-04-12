#pragma once
#include <string>
#include "../../DataStructures/IntermidiateRepresentation/INameGetter.hpp"

namespace cMCompiler::compiler::serialization
{
	class NameGetter : public  dataStructures::ir::INameGetter
	{
		std::string get(dataStructures::Type const* t) const final;
		std::string get(dataStructures::TypeReference const& t) const final;
		std::string get(dataStructures::Function const* t) const final;
		std::string get(dataStructures::Field const* t) const final;
		std::string get(dataStructures::Variable const* t) const final;
	};
}