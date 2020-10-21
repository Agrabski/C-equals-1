#pragma once
#include "INamedObject.hpp"
#include "AttributeTarget.hpp"
#include "Namespace.hpp"

namespace cMCompiler::dataStructures
{
	class Namespace;

	struct EnumValue
	{
		std::string name;
		size_t value;
	};

	class Enum : public INamedObject, AttributeTarget
	{
		std::vector<EnumValue> values_;
	public:
		Enum(std::string& name, gsl::not_null<Namespace*> ns) :
			INamedObject(name, (INamedObject*)ns.get()), AttributeTarget(Target::Enum)
		{}
	};
}
