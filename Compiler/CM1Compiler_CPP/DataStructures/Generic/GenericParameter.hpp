#pragma once
#include <string>
#include <gsl.h>

using gsl::not_null;

namespace cMCompiler::dataStructures::generic
{
	class Type;
	struct GenericParameter
	{
		std::string const name_;
		GenericParameter(std::string name) : name_(name) {}
	};
}