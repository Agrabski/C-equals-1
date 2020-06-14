#include "CompilationUnitDatabaseBuilder.hpp"
#include "../antlr_runtime/src/tree/ParseTreeWalker.h"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "../DataStructures/Accessibility.hpp"

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
	not_null function = namespaceStack_.back()->appendFunction(ctx->Identifier()->getText(), accessibility);

	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto const type = nameResolver_.resolve<Type>(QualifiedName(variable->qualifiedIdentifier()->getText()), this->namespaceStack_.back());
		auto const var = function->appendVariable(variable->Identifier()->getText(), type);
		// todo: attribute support
	}

	return antlrcpp::Any();
}
