#pragma once
#include "Namespace.hpp"

namespace cMCompiler::dataStructures
{
	class PackageDatabase
	{
		Namespace rootNamespace_;
		std::string name_;
	public:
		std::string const& name() const noexcept { return name_; }
		Namespace* rootNamespace() noexcept { return &rootNamespace_; }
		PackageDatabase(std::string name) : name_(std::move(name)), rootNamespace_("",nullptr) {}
		PackageDatabase(PackageDatabase&&) = default;
	};
}
