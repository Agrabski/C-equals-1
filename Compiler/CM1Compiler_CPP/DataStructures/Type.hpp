#pragma once
#include <string>
#include <vector>
#include "INamedObject.hpp"
#include "Namespace.hpp"
#include "Function.hpp"
#include "Interface.hpp"

namespace cMCompiler::dataStructures
{
	class Namespace;
	class Type : public INamedObject
	{
		std::vector<Function> methods_;
		std::vector<Interface*> implementedInterfaces_;
	public:
		Type(std::string name, Namespace* parent, std::vector<Interface*>& implementedInterfaces): 
			INamedObject(name, (INamedObject*)parent), implementedInterfaces_(implementedInterfaces)
		{}
	};
}