#pragma once
#include <string>
#include <vector>
#include "INamedObject.hpp"
#include "Namespace.hpp"
#include "Function.hpp"
#include "Interface.hpp"
#include "ObjectWithAccessibility.hpp"

namespace cMCompiler::dataStructures
{
	class Namespace;
	class Type : public INamedObject, public ObjectWithAccessbility
	{
		std::vector<std::unique_ptr<Function>> methods_;
		std::vector<Interface*> implementedInterfaces_;
	public:
		Type(std::string name, Namespace* parent, std::vector<Interface*>& implementedInterfaces): 
			INamedObject(name, (INamedObject*)parent), implementedInterfaces_(implementedInterfaces)
		{}
		Type(std::string name, Namespace* parent) :
			INamedObject(name, (INamedObject*)parent)
		{}

		std::vector<INamedObject*> children() final
		{
			auto result = std::vector<INamedObject*>();
			for (auto& c : methods_)
				result.push_back((INamedObject*)c.get());
			return result;
		}
	};
}