#pragma once
#include <istream>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::Parser
{
	using CompilationUnit = CMinusEqualsMinus1Revision0Parser::CompilationUnitContext;
	using FunctionBody = CMinusEqualsMinus1Revision0Parser::FunctionBodyContext;
	class ParserAdapter
	{
	public:
		std::unique_ptr<CompilationUnit> parse(std::istream& stream);
		std::unique_ptr<FunctionBody> parseBody(std::istream& stream);
	};
}