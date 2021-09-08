#pragma once
#include <exception>
#include <string>
#include <filesystem>
#include <gsl/gsl>

namespace cMCompiler::dataStructures
{
	class Function;
}

namespace cMCompiler::dataStructures::validation
{
	class SemanticModelValidationException : public std::exception
	{
		std::string message_;
	public:
		SemanticModelValidationException(std::string&& message) noexcept : message_(std::move(message)), std::exception(message.c_str())
		{ }
	};

	class NotAllPathsReturnAValueException : public SemanticModelValidationException
	{
		static std::string formatMessage(gsl::not_null<Function*> function, std::filesystem::path const& path);

	public:
		NotAllPathsReturnAValueException(gsl::not_null<Function*> function, std::filesystem::path const& path) noexcept : 
			SemanticModelValidationException(formatMessage(function, path))
		{
		}

	};
}
