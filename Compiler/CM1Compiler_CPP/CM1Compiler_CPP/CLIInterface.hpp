#pragma once
#include <boost/program_options.hpp>
#include <optional>
#include "../DataStructures/CompilationContext.hpp"

namespace cMCompiler
{
	using OptionDescription = boost::program_options::options_description;

	OptionDescription prepareOptions() noexcept
	{
		using boost::program_options::value;
		auto result = OptionDescription();
		result.add_options()
			("help", "print program help")
			("operation", value<std::string>())
			("path", value<std::filesystem::path>());
		return result;
	}

	std::optional<dataStructures::CompilationContext> getCompilationContext(int argc, char* argv[], OptionDescription options)
	{
		using namespace boost::program_options;
		auto result = dataStructures::CompilationContext();
		variables_map vm;
		store(parse_command_line(argc, argv, options), vm);
		if (vm.contains("help"))
			return std::optional<dataStructures::CompilationContext>();

		result.file = vm["path"].as<std::filesystem::path>();

		return result;
	}


}
