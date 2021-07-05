#pragma once
#include <vector>
#include <gsl.h>
#include <ranges>
#include <filesystem>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/INamedObject.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/NameResolutionContext.hpp"
#include "NamespaceBuilder.hpp"

namespace cMCompiler::language
{
	using NameResolutionContext = dataStructures::NameResolutionContext;

	class NameResolver;
}
namespace cMCompiler::compiler
{
	extern not_null<dataStructures::Function*> instantiate(
		dataStructures::Generic<dataStructures::Function>& function,
		std::vector<dataStructures::TypeReference> const& genericParameters,
		language::NameResolver& resolver,
		dataStructures::NameResolutionContext const& context,
		std::filesystem::path const& file
	);
}
namespace cMCompiler::dataStructures
{
	class PackageDatabase;
	class INamedObject;
}


namespace cMCompiler::language
{
	using NameResolutionContext = dataStructures::NameResolutionContext;

	class NameResolver
	{
		std::vector<gsl::not_null<dataStructures::PackageDatabase*>> dependencies_;
		cMCompiler::dataStructures::INamedObject* advanceOne(std::string const& name, gsl::not_null<cMCompiler::dataStructures::INamedObject*> context)
		{
			auto children = context->children();
			auto found = std::find_if(children.begin(), children.end(), [=](auto const element) noexcept {return element->name() == name; });
			if (found != children.end())
				return *found;
			return nullptr;
		}
	public:
		NameResolver(std::vector<gsl::not_null<dataStructures::PackageDatabase*>>const& dependencies) :
			dependencies_(dependencies) {}

		template<typename T>
		T* resolve(std::string const& name, NameResolutionContext& context)
		{
			auto res = context.objectMap_.find(name);
			if (res != context.objectMap_.end())
			{
				auto result = dynamic_cast<T*>(res->second.front());
				if (result != nullptr)
					return result;
			}
			auto unconfirmedResult = context.unconfirmedNames_.find(name);
			if (unconfirmedResult != context.unconfirmedNames_.end())
			{
				auto result = unconfirmedResult->second->get<T>(name);
				context.objectMap_[name].push_back(result);
				context.unconfirmedNames_.erase(name);
				return result;
			}

			for (auto const currentNamespace : context.namespaceStack_)
			{
				auto result = currentNamespace->get<T>(name);
				if (result != nullptr)
					return result;
			}
			return nullptr;
		}

		std::vector<not_null<dataStructures::Generic<dataStructures::Function>*>> resolveGenericOverloadSet(std::string const& name, NameResolutionContext& context)
		{
			auto r = context.objectMap_.find(name);
			auto functions = std::vector<not_null<dataStructures::Generic<dataStructures::Function>*>>();
			if (r != context.objectMap_.end()) //packages or other namespaces
			{
				auto objects = r->second;
				for (auto o : objects)
				{
					auto f = dynamic_cast<dataStructures::Generic<dataStructures::Function>*>(o);
					if (f != nullptr)
						functions.push_back(f);
				}
			}
			else //local function
			{
				for (auto ns : context.namespaceStack_)
				{
					auto objects = ns->children();
					for (auto o : objects)
					{
						auto f = dynamic_cast<dataStructures::Generic<dataStructures::Function>*>(o);
						if (f != nullptr && f->name() == name)
							functions.push_back(f);
					}
				}
			}
			return functions;
		}

		std::vector<not_null<dataStructures::Function*>> resolveOverloadSet(std::string const& name, NameResolutionContext const& context) const
		{
			//todo: fucking disgusting
			auto r = context.objectMap_.find(name);
			auto functions = std::vector<not_null<dataStructures::Function*>>();
			if (r != context.objectMap_.end()) //packages or other namespaces
			{
				auto objects = r->second;
				for (auto o : objects)
				{
					auto f = dynamic_cast<dataStructures::Function*>(o);
					if (f != nullptr)
						functions.push_back(f);
				}
			}
			else //local function
			{
				for (auto ns : context.namespaceStack_)
				{
					auto objects = ns->children();
					for (auto o : objects)
					{
						auto f = dynamic_cast<dataStructures::Function*>(o);
						if (f != nullptr && f->name() == name)
							functions.push_back(f);
					}
				}
			}
			return functions;
		}

		std::vector<not_null<dataStructures::Function*>> resolveOperatorOverloadSet(std::string const& op, dataStructures::TypeReference arg1, dataStructures::TypeReference arg2, NameResolutionContext const& context)
		{
			auto result = std::vector<not_null<dataStructures::Function*>>();
			auto name = "operator_" + op;
			for (not_null f : context.package_->rootNamespace()->get<dataStructures::Function>())
				if (f->name() == name)
					result.push_back(f);
			for (auto package : dependencies_)
			{
				auto functions = package->rootNamespace()->get<dataStructures::Function>();
				for (not_null f : functions)
					if (f->name() == name)
						result.push_back(f);
			}
			return result;

		}

		dataStructures::Function* resolveOperatorNewUnique(
			NameResolutionContext const& context,
			dataStructures::TypeReference type
			)
		{
			for (auto d : this->dependencies_)
				if (d->name() == "std")
				{
					auto g = d->rootNamespace()->get<dataStructures::Generic<dataStructures::Function>>("operator_new_unique");
					return compiler::instantiate(
						*g,
						{ type },
						*this,
						context,
						std::filesystem::path());
				}
		}

		void addImport(
			std::string const& aliasName,
			std::string const& name,
			dataStructures::QualifiedName ns,
			dataStructures::PackageDatabase* currentPackage,
			NameResolutionContext& context) const
		{
			dataStructures::PackageDatabase* package = nullptr;
			dataStructures::QualifiedName const n = ns;
			auto found = std::find_if(dependencies_.begin(), dependencies_.end(), [&](auto const& e) noexcept {return e->name() == ns.peek(); });
			if (found != dependencies_.end())
			{
				package = *found;
				ns = ns.next();
			}
			else
				package = currentPackage;
			if (package == nullptr)
			{
				// todo: report error
			}
			dataStructures::Namespace* current = package->rootNamespace();
			while (ns.size() > 0)
			{
				if (current == nullptr) break;
				auto n = ns.peek();
				ns = ns.next();
				current = current->get<dataStructures::Namespace>(n);
			}
			if (ns.size() != 0)
			{
				//std::terminate();
				//todo: report error
			}
			if (current == nullptr)
			{
				auto unconfirmedNamespace = NamespaceBuilder::buildNamespace(n, currentPackage->rootNamespace());
				context.unconfirmedNames_[name] = unconfirmedNamespace;
				return;
			}
			context.objectMap_[aliasName];
			auto children = current->children();
			for (not_null const child : children)
				if (child->name() == name)
					context.objectMap_[aliasName].push_back(child);
		}

	};

}