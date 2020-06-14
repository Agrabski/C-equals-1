#pragma once
#include "Namespace.hpp"

namespace cMCompiler::dataStructures
{
	class PackageDatabase
	{
		Namespace rootNamespace_;
		std::string name_;
	public:
		Namespace* rootNamespace() noexcept { return &rootNamespace_; }
		PackageDatabase(std::string name) : name_(std::move(name_)), rootNamespace_("",nullptr) {}
	};
}
