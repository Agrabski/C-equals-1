#pragma once
#include "Namespace.hpp"

namespace cMCompiler::dataStructures
{
	class PackageDatabase
	{
		Namespace rootNamespace_;
		std::vector<not_null<PackageDatabase*>> dependencies_;
		std::string name_;
		void getTypes(gsl::not_null<Namespace*> ns, std::vector<gsl::not_null<Type*>>& result) const
		{
			for (auto child : ns->get<Namespace>())
				getTypes(child, result);
			for (auto t : ns->get<Type>())
				result.push_back(t);
		}


		std::vector<gsl::not_null<Type*>> getTypes(PackageDatabase& package)
		{
			auto result = std::vector<gsl::not_null<Type*>>();
			getTypes(package.rootNamespace(), result);
			return result;
		}

		void getFunctions(gsl::not_null<Type*> ns, std::vector<gsl::not_null<Function*>>& result)
		{
			for (auto t : ns->children())
			{
				auto x = dynamic_cast<Function*>(t);
				if (x != nullptr)
					result.push_back(x);
			}
		}

		void getFunctions(gsl::not_null<Namespace*> ns, std::vector<gsl::not_null<Function*>>& result)
		{
			for (auto child : ns->get<Namespace>())
				getFunctions(child, result);
			for (auto t : ns->get<Type>())
				getFunctions(t, result);
			for (auto f : ns->get<Function>())
				result.push_back(f);
		}

		std::vector<gsl::not_null<Function*>> getFunctions(PackageDatabase& package)
		{
			auto result = std::vector<gsl::not_null<Function*>>();
			getFunctions(package.rootNamespace(), result);
			return result;
		}
	public:
		std::string const& name() const noexcept { return name_; }
		gsl::not_null<Namespace*> rootNamespace() noexcept { return &rootNamespace_; }
		PackageDatabase(std::string name) : name_(std::move(name)), rootNamespace_("",nullptr) {}
		PackageDatabase(PackageDatabase&&) = default;
		std::vector<not_null<PackageDatabase*>>const& dependencies() const noexcept { return dependencies_; }
		void appendDependency(not_null<PackageDatabase*> dep) { dependencies_.push_back(dep); }
		std::vector<gsl::not_null<Type*>> getAllTypes()
		{
			auto result = std::vector<gsl::not_null<Type*>>();
			getTypes(gsl::not_null(&rootNamespace_), result);
			return result;
		}

		std::vector<gsl::not_null<Function*>> getAllFunctions()
		{
			auto result = std::vector<gsl::not_null<Function*>>();
			getFunctions(gsl::not_null(&rootNamespace_), result);
			return result;
		}
	};
}
