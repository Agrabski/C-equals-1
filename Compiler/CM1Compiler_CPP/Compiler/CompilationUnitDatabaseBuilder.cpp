#include "CompilationUnitDatabaseBuilder.hpp"
#include "../antlr_runtime/src/tree/ParseTreeWalker.h"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "FunctionBodyBuilder.hpp"
#include "FunctionUtility.hpp"

using namespace cMCompiler::dataStructures;

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::processDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext* declaration)
{
	declaration->children.front()->accept(this);
}

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::buildDatabase(Parser::CompilationUnit& compilationUnit)
{
	resolutionContext_ = language::NameResolutionContext();
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
	switch (state_)
	{
	case cMCompiler::compiler::Create:
		createFunction(resolutionContext_.namespaceStack_.back(), ctx);
		break;
	case cMCompiler::compiler::Confirm:
		confirmFunction(nameResolver_, resolutionContext_, ctx);
		break;
	case cMCompiler::compiler::Finalize:
		finalizeFunction(nameResolver_, resolutionContext_, ctx);
		break;
	default:
		std::terminate();
		break;
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx)
{
	assert(ctx != nullptr);
	QualifiedName newNamespace = ctx->qualifiedIdentifier()->getText();
	for (not_null<antlr4::tree::TerminalNode*> unconfirmedName : ctx->Identifier())
	{
		nameResolver_.addImport(unconfirmedName->getText(), newNamespace, &database_, resolutionContext_);
	}
	return antlrcpp::Any();
}
