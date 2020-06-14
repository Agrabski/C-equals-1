#include "NamespaceBuilder.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language;

Namespace* NamespaceBuilder::buildNamespace(QualifiedName name, Namespace* currentNamespace)
{
	while (name.size()>0)
	{
		auto nextName = name.peek();
		name = name.next();
		auto namespaces = currentNamespace->namespaces();
		auto found = std::find_if(namespaces.begin(), namespaces.end(), [&](auto const e) {return e->name() == nextName; });
		if (found != end(namespaces))
			currentNamespace = *found;
		else
			currentNamespace = currentNamespace->appendNamespace(nextName);
	}
	return currentNamespace;
}
