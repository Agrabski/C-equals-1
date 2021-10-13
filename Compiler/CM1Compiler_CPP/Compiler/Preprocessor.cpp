#include "Preprocessor.hpp"
#include "../DataStructures/QualifiedName.hpp"
#include "../LanguageLogic/NamespaceBuilder.hpp"
#include "AttributeUtility.hpp"
#include "FunctionUtility.hpp"
#include "ExpressionBuilder.hpp"
#include "AttributeSpecialFunctionsExecution.hpp"

antlrcpp::Any cMCompiler::compiler::Preprocessor::visitTypeDeclaration(CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext* ctx)
{
	auto ep = ExpressionBuilder(filePath_, nameResolver_, context_, [](const auto&) {return nullptr; });
	std::unique_ptr<dataStructures::execution::IRuntimeValue> dummyValue = nullptr;
	if (ctx->genericSpecifier() == nullptr) {
		auto name = ctx->identifier()->getText();
		not_null type = context_.namespaceStack_.back()->get<dataStructures::Type>(name);
		if (ctx->attributeSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : ctx->attributeSequence()->attribute())
			{
				not_null attributeType = nameResolver_.resolve<dataStructures::Attribute>(attribute->functionCall()->identifier()->getText(), context_);
				auto parameters = std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
				for (auto p : attribute->functionCall()->functionCallParameter())
				{
					auto evaluator = ExpressionEvaluator([&](const auto&) -> std::unique_ptr<dataStructures::execution::IRuntimeValue>&
						{
							return dummyValue;
						});
					auto expression = ep.buildExpression(p);
					parameters.push_back(evaluator.evaluate(expression, false));
				}
				auto instance = createAttributeInstance(*type, attributeType, std::move(parameters));
				type->appendAttribute(std::move(instance));
			}
	}
	return antlrcpp::Any();
}

antlrcpp::Any cMCompiler::compiler::Preprocessor::visitFunctionDeclaration(CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext* ctx)
{
	if (ctx->genericSpecifier() == nullptr || !ignoreGenerics_)
	{
		auto ep = ExpressionBuilder(filePath_, nameResolver_, context_, [](const auto&) {return nullptr; });
		std::unique_ptr<dataStructures::execution::IRuntimeValue> dummyValue = nullptr;
		auto name = getName(ctx);
		not_null const function = getCompatibleFunction(name, nameResolver_, context_, ctx, filePath_);
		if (ctx->attributeSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : ctx->attributeSequence()->attribute())
				attachAttribute(function, attribute, nameResolver_, context_, ep);

	}
	return antlrcpp::Any();
}

void cMCompiler::compiler::Preprocessor::executeAttachmentFunctions()
{
	using dataStructures::AttributeInstance;
	for (not_null f : database_.getAllFunctions())
		for (not_null<AttributeInstance*> attribute : f->attributes())
			executeAttachmentFunction(f, attribute, nameResolver_, context_);

	for (not_null t : database_.getAllTypes())
	{
		for (not_null attribute : t->attributes())
			executeAttachmentFunction(t, attribute, nameResolver_, context_);
		for (not_null f : t->methods())
			for (not_null<AttributeInstance*> attribute : f->attributes())
				executeAttachmentFunction(f, attribute, nameResolver_, context_);
		for (not_null field : t->fields())
			for (not_null a : field->attributes())
				executeAttachmentFunction(field, a, nameResolver_, context_);
	}
}

void cMCompiler::compiler::Preprocessor::executeAttributeSpecialFunctions()
{
	for (not_null f : database_.getAllFunctions())
		if (f->code())
			for (auto& statement : *f->code())
				executeAttributeFunctionsForStatement(statement);
}

void cMCompiler::compiler::Preprocessor::preprocess(Parser::CompilationUnit& compilationUnit)
{
	compilationUnit.accept(this);
}
