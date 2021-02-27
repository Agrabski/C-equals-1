#include "NamespaceBuilder.hpp"
#include "MetatypeUility.hpp"

using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language;

Namespace* NamespaceBuilder::buildNamespace(QualifiedName name, Namespace* currentNamespace)
{
	while (name.size() > 0)
	{
		auto nextName = name.peek();
		name = name.next();
		auto ns = currentNamespace->get<Namespace>(nextName);
		if (ns != nullptr)
			currentNamespace = ns;
		else
			currentNamespace = currentNamespace->append<Namespace>(nextName);
	}
	return currentNamespace;
}
