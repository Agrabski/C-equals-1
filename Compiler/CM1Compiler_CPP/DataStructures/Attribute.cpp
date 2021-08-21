#include "Attribute.hpp"

using namespace cMCompiler::dataStructures;


cMCompiler::dataStructures::Attribute::Attribute(std::string name, Namespace* parent, not_null<PackageDatabase*> p) :
	INamedObject(name, (INamedObject*)parent, p), describingType_(std::make_unique<Type>(name, parent, p)) {}

std::vector<cMCompiler::dataStructures::INamedObject*> cMCompiler::dataStructures::Attribute::children()
{
	auto result = std::vector<INamedObject*>();
	for (auto& f : describingType_->methods())
		result.push_back((INamedObject*)f.get());
	return result;
}

not_null<Field*> cMCompiler::dataStructures::Attribute::appendField(std::string const& name, TypeReference type)
{
	return describingType_->appendField(name, type);
}

Function* cMCompiler::dataStructures::Attribute::appendFunction(std::string const& name)
{
	return describingType()->append<Function>(name);
}

std::vector<gsl::not_null<Function*>> cMCompiler::dataStructures::Attribute::methods()
{
	return describingType_->methods();
}

execution::json cMCompiler::dataStructures::Attribute::emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const
{
	return {
		{"name", name()},
		{"type", describingType_->emmit(nameLookupFunction, manager)},
		{"target", attributeTarget_}
	};
}
