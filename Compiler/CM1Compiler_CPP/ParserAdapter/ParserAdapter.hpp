#pragma once
#include <istream>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::Parser
{
	using CompilationUnit = CMinusEqualsMinus1Revision0Parser::CompilationUnitContext;
	class ParserAdapter
	{
	public:
		std::unique_ptr<CompilationUnit> parse(std::istream& stream);
	};
}