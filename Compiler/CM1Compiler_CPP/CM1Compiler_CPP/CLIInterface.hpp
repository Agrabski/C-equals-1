#pragma once
#include <boost/program_options.hpp>
#include <optional>
#include "../DataStructures/CompilationContext.hpp"

namespace cMCompiler
{

	std::optional<dataStructures::CompilationContext> getCompilationContext(int argc, char* argv[])
	{
		using namespace boost::program_options;
		auto options = options_description();
		options.add_options()
			("help", "print program help")
			("operation", value<std::string>())
			("compiler-interface", value<std::string>())
			("input", value<std::string>(), "Path to file to be compiled.");
		variables_map vm;
		
		store(command_line_parser(argc, argv).options(options).run(), vm);

		if (vm.contains("help"))
		{
			options.print(std::cout);
			return std::optional<dataStructures::CompilationContext>();
		}

		auto result = dataStructures::CompilationContext();
		result.executablePath = std::filesystem::path(argv[0]).parent_path();
		result.manifestFile = std::filesystem::path(vm["input"].as<std::string>()) / "manifest.mn";
		if (vm.contains("compiler-interface"))
			result.compilerInterfaceManifestFile = vm["compiler-interface"].as<std::string>();

		return result;
	}


}
