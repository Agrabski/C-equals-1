#include "Namespace.hpp"
using namespace cMCompiler::dataStructures;

std::vector<Namespace*> cMCompiler::dataStructures::Namespace::namespaces()
{
	auto result =  std::vector<Namespace*>();
	for (auto& ns : namespaces_)
		result.push_back(ns.get());
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
