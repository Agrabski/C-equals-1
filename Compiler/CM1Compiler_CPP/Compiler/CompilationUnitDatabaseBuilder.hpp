#pragma once
#include <vector>
#include "../DataStructures/Namespace.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/PackageDatabase.hpp"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	class CompilationUnitDataBaseBuilder : CMinusEqualsMinus1Revision0BaseVisitor
	{
		language::NameResolutionContext resolutionContext_;
		std::vector<dataStructures::Namespace*> namespaceStack_;
		dataStructures::PackageDatabase& database_;
		language::NameResolver& nameResolver_;
		void processDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext* declaration);
	public:
		CompilationUnitDataBaseBuilder(dataStructures::PackageDatabase& database, language::NameResolver& nameResolver) noexcept : 
			database_(database), nameResolver_(nameResolver){}
		void buildDatabase(Parser::CompilationUnit& compilationUnit);
		antlrcpp::Any visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context) final;
		antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx) final;
		antlrcpp::Any visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx) final;

	};
}