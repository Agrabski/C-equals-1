#pragma once
#include <vector>
#include <filesystem>
#include "Preprocessor.hpp"
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
		std::filesystem::path file_;
		bool processOnlyAttributes_ = true;
		Preprocessor preprocessor_;
	public:
		void finishAttributes() noexcept
		{
			assert(state_ == DatabaseBuildingState::Finalize);
			processOnlyAttributes_ = false;
			state_ = DatabaseBuildingState::Create;
		}

		bool advance()
		{
			if (state_ == Finalize)
			{
				preprocessor_.executeAttributeSpecialFunctions();
				return false;
			}
			state_ = (DatabaseBuildingState)(state_ + 1);
			if (state_ == Finalize)
				preprocessor_.executeAttachmentFunctions();
			return true;
		}
		CompilationUnitDataBaseBuilder(dataStructures::PackageDatabase& database, language::NameResolver& nameResolver) noexcept :
			database_(database), nameResolver_(nameResolver), preprocessor_(database_, file_, nameResolver_, resolutionContext_),
			resolutionContext_(&database)
		{}
		void buildDatabase(Parser::CompilationUnit& compilationUnit);
		void setFile(std::filesystem::path const& file)
		{
			file_ = file;
		}
		antlrcpp::Any visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context) final;
		antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx) final;
		antlrcpp::Any visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx) final;
		antlrcpp::Any visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx) final;
		antlrcpp::Any visitAttributeDeclaration(CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext* ctx) final;
	};
}