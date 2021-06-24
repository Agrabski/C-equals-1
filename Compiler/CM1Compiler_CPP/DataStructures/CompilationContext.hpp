#pragma once
#include <filesystem>

namespace cMCompiler::dataStructures
{
	struct CompilationContext
	{
		std::filesystem::path manifestFile;
		std::filesystem::path executablePath;
		std::optional<std::filesystem::path> compilerInterfaceManifestFile;
	};
}