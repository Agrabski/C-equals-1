#pragma once
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../DataStructures/PackageDatabase.hpp"

namespace cMCompiler::compiler
{
	class Preprocessor
	{
	public:
		void preprocess(Parser::CompilationUnit& compilationUnit, dataStructures::PackageDatabase& database);
	};
}
