#include "NameGetter.hpp"
#include "../../DataStructures/Type.hpp"
#include "../../DataStructures/TypeReference.hpp"
#include "../../DataStructures/Field.hpp"
#include "../../DataStructures/Namespace.hpp"
#include "../../DataStructures/Attribute.hpp"
#include "../../DataStructures/Variable.hpp"


std::string cMCompiler::compiler::serialization::NameGetter::get(dataStructures::Type const* t) const
{
	if (t == nullptr)
		return "null";
	return (std::string) t->qualifiedName();
}

std::string cMCompiler::compiler::serialization::NameGetter::get(dataStructures::TypeReference const& t) const
{
	if (t.type == nullptr)
		return "null";
	std::stringstream ss;
	ss << t;
	return ss.str();
}

std::string cMCompiler::compiler::serialization::NameGetter::get(dataStructures::Function const* f) const
{
	if (f == nullptr)
		return "null";
	std::stringstream ss;
	ss << f->qualifiedName();
	ss << '|';
	for (auto param : f->parameters())
		ss << param->type() << " ";
	ss << "|";
	return ss.str();
}

std::string cMCompiler::compiler::serialization::NameGetter::get(dataStructures::Field const* t) const
{
	if (t == nullptr)
		return "null";
	return (std::string)t->name();
}

std::string cMCompiler::compiler::serialization::NameGetter::get(dataStructures::Variable const* t) const
{
	if (t == nullptr)
		return "null";
	return (std::string) t->qualifiedName();
}
