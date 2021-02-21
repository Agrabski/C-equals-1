#pragma once
#include <filesystem>
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "../DataStructures/PackageDatabase.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "ExpressionEvaluator.hpp"

namespace cMCompiler::compiler
{
	class Preprocessor : public CMinusEqualsMinus1Revision0BaseVisitor
	{

		std::filesystem::path filePath_;
		dataStructures::PackageDatabase& database_;
		language::NameResolver& nameResolver_;
		language::NameResolutionContext& context_;
		antlrcpp::Any visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx) final;
		antlrcpp::Any visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx) final;
	public:
		void executeAttachmentFunctions();
		void executeAttributeSpecialFunctions();
		Preprocessor(dataStructures::PackageDatabase& database, std::filesystem::path const& filePath, language::NameResolver& nameResolver, language::NameResolutionContext& context) noexcept :
			database_(database), nameResolver_(nameResolver), context_(context), filePath_(filePath)
		{
		}
		void preprocess(Parser::CompilationUnit& compilationUnit);
	};
}
