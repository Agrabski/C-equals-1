#pragma once
#include <vector>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/INamedObject.hpp"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/NameResolutionContext.hpp"
#include "NamespaceBuilder.hpp"

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

			auto const& currentNamespace = context.namespaceStack_.back();
			return currentNamespace->get<T>(name);
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
				auto ns = context.namespaceStack_.back();
				auto objects = ns->children();
				for (auto o : objects)
				{
					auto f = dynamic_cast<dataStructures::Generic<dataStructures::Function>*>(o);
					if (f != nullptr && f->name() == name)
						functions.push_back(f);
				}
			}
			return functions;
		}

		std::vector<not_null<dataStructures::Function*>> resolveOverloadSet(std::string const& name, NameResolutionContext& context)
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
				auto ns = context.namespaceStack_.back();
				auto objects = ns->children();
				for (auto o : objects)
				{
					auto f = dynamic_cast<dataStructures::Function*>(o);
					if (f != nullptr && f->name() == name)
						functions.push_back(f);
				}
			}
			return functions;
		}

		std::vector<not_null<dataStructures::Function*>> resolveOperatorOverloadSet(std::string const& op, not_null<dataStructures::Type*> arg1, not_null<dataStructures::Type*> arg2, NameResolutionContext const& context)
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

		void addImport(std::string const& name, dataStructures::QualifiedName ns, dataStructures::PackageDatabase* currentPackage, NameResolutionContext& context)
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
			context.objectMap_[name];
			auto children = current->children();
			for (not_null const child : children)
				if (child->name() == name)
					context.objectMap_[name].push_back(child);
		}

	};

}