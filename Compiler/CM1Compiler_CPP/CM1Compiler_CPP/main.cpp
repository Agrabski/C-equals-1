#include <iostream>
#include <fstream>
#include "CLIInterface.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"

int main(int argc, char* argv[])
{
	auto options = cMCompiler::prepareOptions();
	auto context = cMCompiler::getCompilationContext(argc, argv, options);
	if (context)
	{
		cMCompiler::Parser::ParserAdapter adapter;
		std::ifstream stream;
		stream.open(context->file);
		auto parseTree = adapter.parse(stream);
	}
	else
		options.print(std::cout);
}

