#pragma once
#include <string>
#include <memory>
#include "Function.hpp"
#include "INamedObject.hpp"
#include "ObjectWithAccessibility.hpp"
#include "Field.hpp"

namespace cMCompiler::dataStructures
{
	class Function;
	class Attribute : public INamedObject, public ObjectWithAccessbility
	{
		std::vector<std::unique_ptr<Field>> fields_;
		std::vector<std::unique_ptr<Function>> constructors_;
		std::vector<std::unique_ptr<Function>> functions_;
	public:
		Attribute(std::string name, INamedObject* parent) : INamedObject(name, parent){}
		std::vector<INamedObject*> children() final
		{
			auto result = std::vector<INamedObject*>();
			for (auto& c : constructors_)
				result.push_back((INamedObject*)c.get());
			for (auto &f : functions_)
				result.push_back((INamedObject*)f.get());
			return result;
		}

	};
}
