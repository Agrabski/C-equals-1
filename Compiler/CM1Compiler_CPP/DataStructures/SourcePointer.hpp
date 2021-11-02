#pragma once
#include <string>

namespace cMCompiler::dataStructures
{
	struct SourcePointer
	{
		SourcePointer(std::string const& file, unsigned long long line)
			: filePath_(file), lineNumber_(line)
		{}
		SourcePointer(std::string && file, unsigned long long line) noexcept
			: filePath_(std::move(file)), lineNumber_(line)
		{}
		SourcePointer() = default;

		std::string filePath_;
		unsigned long long lineNumber_;
	};
}