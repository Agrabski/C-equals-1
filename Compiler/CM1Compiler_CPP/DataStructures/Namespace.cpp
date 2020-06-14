#include "Namespace.hpp"
using namespace cMCompiler::dataStructures;

std::vector<Namespace*> cMCompiler::dataStructures::Namespace::namespaces()
{
	auto result =  std::vector<Namespace*>();
	for (auto& ns : namespaces_)
		result.push_back(ns.get());
	return result;
}

Function* cMCompiler::dataStructures::Namespace::appendFunction(std::string name, Accessibility accessibility)
{
	auto tmp = std::make_unique<Function>(accessibility,name, this);
	auto const result = tmp.get();
	functions_.push_back(std::move(tmp));
	return result;

}

Namespace* cMCompiler::dataStructures::Namespace::appendNamespace(std::string name)
{
	auto tmp = std::make_unique<Namespace>(name, this);
	auto const result = tmp.get();
	namespaces_.push_back(std::move(tmp));
	return result;
}
std::vector<INamedObject*> Namespace::children()
{
	std::vector<INamedObject*> result;
	for (auto &f : functions_)
		result.push_back(f.get());
	for (auto& ns : namespaces_)
		result.push_back(ns.get());
	for (auto& t : types_)
		result.push_back(t.get());
	return result;
}
