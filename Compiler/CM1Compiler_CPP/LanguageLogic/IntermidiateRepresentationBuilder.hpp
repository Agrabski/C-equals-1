#pragma once
#include <vector>
#include <memory>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../DataStructures/IntermidiateRepresentation/IInstruction.hpp"
#include "../DataStructures/Function.hpp"

namespace cMCompiler::language
{
	class IntermidiateRepresentationBuilder
	{
	public:
		std::vector<std::unique_ptr<dataStructures::ir::IInstruction>>
			buildIr(
				std::vector<not_null<CMinusEqualsMinus1Revision0Parser::StatementContext*>> statements,
				dataStructures::Function& function);
	};
}