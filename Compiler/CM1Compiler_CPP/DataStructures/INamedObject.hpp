#pragma once
#include <string>
#include <vector>

namespace cMCompiler::dataStructures
{
	class INamedObject
	{
		std::string name_;
		INamedObject* parent_;
		INamedObject(INamedObject&&) = delete;
	protected:
		INamedObject(std::string name, INamedObject* parent) : name_(name), parent_(parent) {}
	public:
		virtual ~INamedObject() = default;
		std::string const& name() const noexcept { return name_; }
		INamedObject* parent() const noexcept { return parent_; }
		virtual std::vector<INamedObject*> children() = 0;
	};
}