#include "ParserAdapter.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Lexer.h"

using namespace cMCompiler::Parser;

std::unique_ptr<CompilationUnit> ParserAdapter::parse(std::istream& stream)
{
	antlr4::ANTLRInputStream aStream(stream);
	auto lexer = CMinusEqualsMinus1Revision0Lexer(&aStream);
	antlr4::BufferedTokenStream tokenStream(&lexer);
	auto parser = CMinusEqualsMinus1Revision0Parser(&tokenStream);
	return parser.parseCompilationUnit();
}
