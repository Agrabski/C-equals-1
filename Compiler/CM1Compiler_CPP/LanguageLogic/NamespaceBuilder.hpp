#pragma once
#include "../DataStructures/PackageDatabase.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../DataStructures/Namespace.hpp"


namespace cMCompiler::language
{
	class NamespaceBuilder
	{
	public:
		static dataStructures::Namespace* buildNamespace(dataStructures::QualifiedName name, dataStructures::Namespace* currentNamespace);
	};
}