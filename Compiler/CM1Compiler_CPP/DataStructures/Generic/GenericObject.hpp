#pragma once
#include <memory>
#include <vector>
#include <string>
#include "GenericParameter.hpp"

namespace cMCompiler::dataStructures::generic
{
	class GenericObject
	{
		std::vector<std::unique_ptr<GenericParameter>> genericParameters_;
	public:
		not_null<GenericParameter*> pushParameter(std::string name);
		not_null<GenericParameter*> getParameter(std::string name);
		std::vector<not_null<GenericParameter*>> getParameters();

	};
}