#pragma once
#include <string>

namespace cMCompiler::dataStructures
{
	struct SourcePointer
	{
		SourcePointer(std::string const& file, unsigned long long line)
			: filePath_(file), lineNumber_(line)
		{}
		std::string filePath_;
		unsigned long long lineNumber_;
	};
}