#pragma once
#include <memory>
#include <filesystem>

namespace cMCompiler::language::compileTimeInfrastructure
{
	//todo: jesus fucking christ, why is this a singleton?
	struct CompilationOptions
	{
		static inline std::unique_ptr<CompilationOptions> instance = nullptr;
		std::filesystem::path outputDirectory;
	};
}
