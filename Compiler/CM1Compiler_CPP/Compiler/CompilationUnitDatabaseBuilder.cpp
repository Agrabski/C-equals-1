#include "CompilationUnitDatabaseBuilder.hpp"
#include "../antlr_runtime/src/tree/ParseTreeWalker.h"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "FunctionBodyBuilder.hpp"
#include "FunctionUtility.hpp"
#include "TypeUtility.hpp"
#include "AttributeUtility.hpp"
#include "Preprocessor.hpp"

using namespace cMCompiler::dataStructures;

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::processDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext* declaration)
{
	for (auto const& c : declaration->children)
		c->accept(this);
}

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::buildDatabase(Parser::CompilationUnit& compilationUnit)
{
	resolutionContext_ = language::NameResolutionContext(&this->database_);
	resolutionContext_.namespaceStack_.push_back(database_.rootNamespace());
	for (auto declaration : compilationUnit.declarationSequence()->declaration())
		processDeclaration(declaration);
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context)
{
	assert(context != nullptr);
	auto name = QualifiedName(context->qualifiedIdentifier()->getText());
	auto newNamespace = language::NamespaceBuilder::buildNamespace(name, resolutionContext_.namespaceStack_.back());
	resolutionContext_.namespaceStack_.push_back(newNamespace);
	for (auto declaration : context->declarationSequence()->declaration())
		processDeclaration(declaration);
	resolutionContext_.namespaceStack_.pop_back();
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx)
{
	assert(ctx != nullptr);
	if (processOnlyAttributes_)
		return antlrcpp::Any();
	switch (state_)
	{
	case cMCompiler::compiler::Create:
		createFunction(resolutionContext_.namespaceStack_.back(), ctx, resolutionContext_, file_);
		break;
	case cMCompiler::compiler::Confirm:
		confirmFunction(nameResolver_, resolutionContext_, ctx, file_);
		preprocessor_.visit(ctx);
		break;
	case cMCompiler::compiler::Finalize:
		finalizeFunction(nameResolver_, resolutionContext_, ctx, file_);
		break;
	default:
		std::terminate();
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx)
{
	assert(ctx != nullptr);
	QualifiedName newNamespace = ctx->qualifiedIdentifier()->getText();
	for (not_null unconfirmedName : ctx->importAliasDeclaration())
	{
		auto const identifiers = unconfirmedName->identifier();
		auto const realName = identifiers[0]->getText();
		auto aliasName = identifiers[0]->getText();
		if (identifiers.size() == 2)
			aliasName = identifiers[1]->getText();
		nameResolver_.addImport(aliasName, realName, newNamespace, &database_, resolutionContext_);
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx)
{
	assert(ctx != nullptr);
	if (processOnlyAttributes_)
		return antlrcpp::Any();
	switch (state_)
	{
	case cMCompiler::compiler::Create:
		createType(resolutionContext_.namespaceStack_.back(), nameResolver_, resolutionContext_, ctx, file_);
		break;
	case cMCompiler::compiler::Confirm:
		confirmType(nameResolver_, resolutionContext_, ctx, file_);
		preprocessor_.visit(ctx);
		break;
	case cMCompiler::compiler::Finalize:
		finalizeType(nameResolver_, resolutionContext_, ctx, file_);
		break;
	default:
		std::terminate();
		break;
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitAttributeDeclaration(CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext* ctx)
{
	if (!processOnlyAttributes_)
		return antlrcpp::Any();
	not_null parent = resolutionContext_.namespaceStack_.back();
	switch (state_)
	{
	case cMCompiler::compiler::Create:
		createAttribute(ctx, parent, resolutionContext_, file_);
		break;
	case cMCompiler::compiler::Confirm:
		confirmAttribute(ctx, parent, nameResolver_, resolutionContext_, file_);
		break;
	case cMCompiler::compiler::Finalize:
		finalizeAttribute(ctx, parent, nameResolver_, resolutionContext_, file_);
		break;
	default:
		break;
	}
	return antlrcpp::Any();
}
