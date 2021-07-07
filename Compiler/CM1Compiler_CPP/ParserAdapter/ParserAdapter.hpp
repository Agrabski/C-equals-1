#pragma once
#include <istream>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"

namespace cMCompiler::Parser
{
	using CompilationUnit = CMinusEqualsMinus1Revision0Parser::CompilationUnitContext;
	using FunctionBody = CMinusEqualsMinus1Revision0Parser::FunctionBodyContext;
	using TypeSpecifier = CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext;
	using Function = CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext;
	class ParserAdapter
	{
	public:
		std::unique_ptr<CompilationUnit> parse(std::istream& stream);
		std::unique_ptr<FunctionBody> parseBody(std::istream& stream);
		std::unique_ptr<TypeSpecifier> parseType(std::istream& stream);
		std::unique_ptr<Function> parseFunction(std::istream& stream);
	};
}