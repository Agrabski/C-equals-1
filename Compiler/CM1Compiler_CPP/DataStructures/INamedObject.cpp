#include "INamedObject.hpp"

using namespace cMCompiler::dataStructures;

QualifiedName INamedObject::qualifiedName()
{
	if (parent() != nullptr)
		return parent()->qualifiedName() + name_;
	return QualifiedName();
}
