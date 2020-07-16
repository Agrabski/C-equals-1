#pragma once
#include <vector>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/INamedObject.hpp"
#include "../DataStructures/Function.hpp"

namespace cMCompiler::dataStructures
{
	class PackageDatabase;
	class INamedObject;
}


namespace cMCompiler::language
{
	struct NameResolutionContext
	{
		std::map<std::string, std::vector<dataStructures::INamedObject*>> objectMap_;
		std::map<std::string, dataStructures::Namespace*> unconfirmedNames_;
		std::vector<not_null<dataStructures::Namespace*>> namespaceStack_;
	};

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
				auto result = unconfirmedResult->second->append<T>(name);
				return result;
			}

			auto const& currentNamespace = context.namespaceStack_.back();
			return currentNamespace->get<T>(name);
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

		void addImport(std::string const& name, dataStructures::QualifiedName ns, dataStructures::PackageDatabase* currentPackage, NameResolutionContext& context)
		{
			dataStructures::PackageDatabase* package = nullptr;
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
				//todo: report error
			}
			context.objectMap_[name];
			auto children = current->children();
			for (auto child : children)
				if (child->name() == name)
					context.objectMap_[name].push_back(child);
		}
	};

}