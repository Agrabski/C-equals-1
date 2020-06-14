#pragma once
#include <vector>
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../DataStructures/PackageDatabase.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "../DataStructures/INamedObject.hpp"

namespace cMCompiler::compiler
{
	class PackageDatabaseManager
	{
		struct unconfirmedReference
		{
			cMCompiler::dataStructures::INamedObject* const context_;
			cMCompiler::dataStructures::QualifiedName const name_;
		};
		std::vector<unconfirmedReference> unconfirmedReferences_;
	public:
		void appendUnconfirmedReference(cMCompiler::dataStructures::INamedObject* context, cMCompiler::dataStructures::QualifiedName name);
		void buildDatabase(Parser::CompilationUnit& compilationUnit, language::NameResolver& nameResolver, dataStructures::PackageDatabase& builtDatabase);
	};
}
