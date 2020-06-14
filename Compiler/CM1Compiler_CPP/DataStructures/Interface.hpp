#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Namespace.hpp"
#include "Function.hpp"

namespace cMCompiler::dataStructures
{
	class Namespace;
	class Interface
	{
		std::string name_;
		Namespace* parent_;
		std::vector<std::unique_ptr<Function>> methods_;
		std::vector<Interface*> implementedInterfaces_;

	};
}