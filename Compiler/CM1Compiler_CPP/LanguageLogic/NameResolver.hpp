#pragma once
#include <vector>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/INamedObject.hpp"

namespace cMCompiler::dataStructures
{
	class PackageDatabase;
	class INamedObject;
}


namespace cMCompiler::language
{
	struct NameResolutionContext
	{
		std::map<std::string, dataStructures::INamedObject*> objectMap_;
		std::map<std::string, dataStructures::Namespace*> unconfirmedNames_;
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
		NameResolver(std::vector<gsl::not_null<dataStructures::PackageDatabase*>>& dependencies) :
			dependencies_(dependencies) {}

		template<typename T>
		T* resolve(std::string name, NameResolutionContext& context)
		{
			auto res = context.objectMap_.find(name);
			if (res != context.objectMap_.end())
			{
				auto result = dynamic_cast<T*>(res->second);
				if (result != nullptr)
					return result;
			}
			auto unconfirmedResult = context.unconfirmedNames_.find(name);
			if (unconfirmedResult != context.unconfirmedNames_.end())
			{
				auto result = unconfirmedResult->second->append<T>(name);
				return result;
			}
			return nullptr;
		}

		void addImport(std::string name, dataStructures::QualifiedName ns, dataStructures::PackageDatabase* currentPackage, NameResolutionContext& context)
		{
			dataStructures::PackageDatabase* package;
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

			}
			auto children = current->children();
			context.objectMap_[name] = *std::find_if(children.begin(), children.end(), [&](auto const& e) noexcept {return e->name() == name; });

		}
	};

}