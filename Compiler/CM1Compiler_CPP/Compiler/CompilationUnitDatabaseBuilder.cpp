#include "CompilationUnitDatabaseBuilder.hpp"
#include "../antlr_runtime/src/tree/ParseTreeWalker.h"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "FunctionBodyBuilder.hpp"

using namespace cMCompiler::dataStructures;

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::processDeclaration(CMinusEqualsMinus1Revision0Parser::DeclarationContext* declaration)
{
	declaration->children.front()->accept(this);
}

void cMCompiler::compiler::CompilationUnitDataBaseBuilder::buildDatabase(Parser::CompilationUnit& compilationUnit)
{
	namespaceStack_.push_back(database_.rootNamespace());
	for (auto declaration : compilationUnit.declarationSequence()->declaration())
		processDeclaration(declaration);
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context)
{
	assert(context != nullptr);
	auto name = QualifiedName(context->qualifiedIdentifier()->getText());
	auto newNamespace = language::NamespaceBuilder::buildNamespace(name, namespaceStack_.back());
	namespaceStack_.push_back(newNamespace);
	for (auto declaration : context->declarationSequence()->declaration())
		processDeclaration(declaration);
	namespaceStack_.pop_back();
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::CompilationUnitDataBaseBuilder::visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx)
{
	assert(ctx != nullptr);
	dataStructures::Accessibility accessibility = Accessibility::Private;
	if (ctx->AccessSpecifier() != nullptr)
		accessibility = parse(ctx->AccessSpecifier()->getText());
	not_null function = namespaceStack_.back()->append<Function>(ctx->Identifier(0)->getText());
	function->setAccessibility(accessibility);

	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto const type = nameResolver_.resolve<Type>(variable->Identifier(1)->getText(), resolutionContext_);
		auto const var = function->appendVariable(variable->Identifier(0)->getText(), type);
		// todo: attribute support
	}
	auto builder = FunctionBodyBuilder(function, nameResolver_, resolutionContext_);
	ctx->functionBody()->accept(&builder);

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
