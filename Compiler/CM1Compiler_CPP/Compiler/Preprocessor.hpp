#pragma once
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../DataStructures/PackageDatabase.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "ExpressionEvaluator.hpp"

namespace cMCompiler::compiler
{
	class Preprocessor : protected CMinusEqualsMinus1Revision0BaseVisitor
	{
		dataStructures::PackageDatabase& database_;
		language::NameResolver& nameResolver_;
		language::NameResolutionContext context_;
		antlrcpp::Any visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* context) final;
		antlrcpp::Any visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context) final;
		antlrcpp::Any visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx) final;
		antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx) final;
	public:
		void evaluateCompiletimeCode();
		Preprocessor(dataStructures::PackageDatabase& database, language::NameResolver& nameResolver) :
			database_(database), nameResolver_(nameResolver) 
		{
			context_.namespaceStack_.push_back(database.rootNamespace());
		}
		void preprocess(Parser::CompilationUnit& compilationUnit);
	};
}
