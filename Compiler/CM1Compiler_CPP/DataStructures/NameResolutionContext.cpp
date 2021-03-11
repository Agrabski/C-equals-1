#include "NameResolutionContext.hpp"

cMCompiler::dataStructures::NameResolutionContext cMCompiler::dataStructures::NameResolutionContext::merge(NameResolutionContext const& a, NameResolutionContext const& b)
{
	auto map = a.objectMap_;
	for (auto x : b.objectMap_)
		map[x.first] = x.second;
	auto stack = a.namespaceStack_;
	for (auto x : b.namespaceStack_)
		stack.push_back(x);
	auto result = NameResolutionContext(a.package_);
	result.objectMap_ = map;
	result.namespaceStack_ = stack;
	return result;
}
