#pragma once
#include <vector>
#include "../DataStructures/Namespace.hpp"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../DataStructures/PackageDatabase.hpp"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	enum DatabaseBuildingState { Create = 0, Confirm = 1, Finalize = 2 };
	class CompilationUnitDataBaseBuilder : CMinusEqualsMinus1Revision0BaseVisitor
	{
		language::NameResolutionContext resolutionContext_;
		dataStructures::PackageDatabase& database_;
		language::NameResolver& nameResolver_;
		void processDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext* declaration);
		DatabaseBuildingState state_ = DatabaseBuildingState::Create;
	public:
		bool advance() noexcept 
		{
			if (state_ == Finalize)
				return false;
			state_ = (DatabaseBuildingState)(state_ + 1);
			return true;
		}
		CompilationUnitDataBaseBuilder(dataStructures::PackageDatabase& database, language::NameResolver& nameResolver) noexcept :
			database_(database), nameResolver_(nameResolver) {}
		void buildDatabase(Parser::CompilationUnit& compilationUnit);
		antlrcpp::Any visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context) final;
		antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx) final;
		antlrcpp::Any visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx) final;

	};
}