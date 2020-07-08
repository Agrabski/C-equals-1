#include "Preprocessor.hpp"
#include "../DataStructures/QualifiedName.cpp"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "AttributeUtility.hpp"
#include "ExpressionBuilder.hpp"

antlrcpp::Any cMCompiler::compiler::Preprocessor::visitImportDeclaration(CMinusEqualsMinus1Revision0Parser::ImportDeclarationContext* ctx)
{
	QualifiedName newNamespace = ctx->qualifiedIdentifier()->getText();
	for (not_null<antlr4::tree::TerminalNode*> unconfirmedName : ctx->Identifier())
	{
		nameResolver_.addImport(unconfirmedName->getText(), newNamespace, &database_, context_);
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::Preprocessor::visitNamespaceDeclaration(CMinusEqualsMinus1Revision0Parser::NamespaceDeclarationContext* context)
{
	assert(context != nullptr);
	auto name = QualifiedName(context->qualifiedIdentifier()->getText());
	auto newNamespace = language::NamespaceBuilder::buildNamespace(name, context_.namespaceStack_.back());
	context_.namespaceStack_.push_back(newNamespace);
	for (auto declaration : context->declarationSequence()->declaration())
		declaration->accept(this);
	context_.namespaceStack_.pop_back();
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::Preprocessor::visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx)
{
	auto ep = ExpressionBuilder([](const auto&) {return nullptr; });
	not_null type = context_.namespaceStack_.back()->get<dataStructures::Type>(ctx->Identifier()->getText());
	for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : ctx->attributeSequence()->attribute())
	{
		not_null attributeType = nameResolver_.resolve<dataStructures::Attribute>(attribute->functionCall()->Identifier()->getText(), context_);
		auto parameters = std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
		for (auto p : attribute->functionCall()->functionCallParameter())
		{
			auto evaluator = ExpressionEvaluator(nameResolver_, context_, [](const auto&) {return nullptr; });
			auto expression = ep.buildExpression(p);
			parameters.push_back(evaluator.evaluate(expression.get()));
		}
		auto nonOwningParameters = std::vector<dataStructures::execution::IRuntimeValue* >();
		for (auto& p : parameters)
			nonOwningParameters.push_back(p.get());
		auto instance = createAttributeInstance(*type, attributeType, nonOwningParameters, nameResolver_, context_);
		type->appendAttribute(std::move(instance));
	}
	return antlrcpp::Any();
}

void cMCompiler::compiler::Preprocessor::evaluateCompiletimeCode()
{
	using dataStructures::AttributeInstance;
	for (auto f : database_.getAllFunctions())
		for (not_null<AttributeInstance*> attribute : f->attributes())
			executeAttachmentFunction(f, attribute, nameResolver_, context_);

	for (auto t : database_.getAllTypes())
	{
		for (auto attribute : t->attributes())
			executeAttachmentFunction(t, attribute, nameResolver_, context_);
		for (auto f : t->methods())
			for (not_null<AttributeInstance*> attribute : f->attributes())
				executeAttachmentFunction(f, attribute, nameResolver_, context_);
		for (auto field : t->fields())
			for (auto a : field->attributes())
				executeAttachmentFunction(field, a, nameResolver_, context_);
	}
}

void cMCompiler::compiler::Preprocessor::preprocess(Parser::CompilationUnit& compilationUnit)
{
	compilationUnit.accept(this);
	evaluateCompiletimeCode();
}
