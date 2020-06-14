#pragma once
#include "Variable.hpp"
#include "Type.hpp"
#include "INamedObject.hpp"
#include "Accessibility.hpp"

namespace cMCompiler::dataStructures
{
	class Function : public INamedObject
	{
		Accessibility accessibility_;
	public:
		virtual ~Function() = default;
		Function(Accessibility accessibility, std::string name, INamedObject* parent) : INamedObject(name, parent), accessibility_(accessibility) {}
		Variable* appendVariable(std::string name, Type* type);
		std::vector<INamedObject*> children() noexcept final
		{
			return std::vector<INamedObject*>();
		};
	};
}
