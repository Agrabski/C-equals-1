#pragma once
#include <vector>
#include <gsl.h>
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/INamedObject.hpp"

namespace cMCompiler::language
{
	class NameResolver
	{
		std::vector<dataStructures::PackageDatabase*> dependencies_;
		cMCompiler::dataStructures::INamedObject* advanceOne(std::string const& name, gsl::not_null<cMCompiler::dataStructures::INamedObject*> context)
		{
			auto children = context->children();
			auto found = std::find_if(children.begin(), children.end(), [=](auto const element) noexcept {return element->name() == name; });
			if (found != children.end())
				return *found;
			return nullptr;
		}
	public:
		NameResolver(std::vector<dataStructures::PackageDatabase*>& dependencies) :
			dependencies_(dependencies) {}

		template<typename T>
		T* resolve(dataStructures::QualifiedName name, gsl::not_null<cMCompiler::dataStructures::INamedObject*> context, bool moveUp = false)
		{
			auto next = advanceOne(name.peek(), context);
			if (next == nullptr)
			{
				//todo: report error
			}
			if (name.size() == 1U)
			{
				auto x = dynamic_cast<T*>(next);
				if (x != nullptr)
					return x;
				else
					return resolve<T>(name, context->parent());
			}
			auto result = resolve<T>(name.next(), next, false);
			if (result == nullptr && context->parent() != nullptr)
				return resolve<T>(name, context->parent());
			return nullptr;
		}

	};

}