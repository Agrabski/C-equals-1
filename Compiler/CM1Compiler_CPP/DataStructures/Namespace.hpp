#pragma once
#include <string>
#include <memory>
#include "INamedObject.hpp"
#include "Type.hpp"
#include "Function.hpp"
#include "Accessibility.hpp"

namespace cMCompiler::dataStructures
{
	class Type;
	class Function;
	class Namespace : public INamedObject
	{
		std::vector<std::unique_ptr<Type>> types_;
		std::vector<std::unique_ptr<Function>> functions_;
		std::vector<std::unique_ptr<Namespace>> namespaces_;
	public:
		std::vector<Namespace*> namespaces();
		Namespace(std::string name, Namespace*parent) : INamedObject(name, parent) {}
		Type* appendType(std::string name, Accessibility accessibility);
		Function* appendFunction(std::string name, Accessibility accessibility);
		Namespace* appendNamespace(std::string name);
		std::vector<INamedObject*> children() final;

	};
}
