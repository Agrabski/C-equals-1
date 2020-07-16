#include "AttributeUtility.hpp"
#include "FunctionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"

using namespace cMCompiler;

void cMCompiler::compiler::createAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent)
{
	auto name = ctx->Identifier()->getText();
	not_null attribute = parent->append<dataStructures::Attribute>(name);
	attribute->setAccessibility(dataStructures::parse(ctx->AccessSpecifier()->getText()));
	auto targets = std::vector<std::string>();
	for (not_null c : ctx->attributeTarget())
		targets.push_back(c->getText());
	attribute->addAttributeTarget(dataStructures::parseTarget(targets));

	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
		createFunction<dataStructures::Attribute>(attribute, member);


}

void cMCompiler::compiler::confirmAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent,
	language::NameResolver resolver,
	language::NameResolutionContext context)
{
	not_null attribute = parent->get<dataStructures::Attribute>(ctx->Identifier()->getText());
	for (not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext*> member : ctx->classContentSequence()->fieldDeclaration())
	{
		auto type = resolver.resolve<dataStructures::Type>(member->Identifier(1)->getText(), context);
		auto var = attribute->appendField(member->Identifier(0)->getText(), type);
		auto access = dataStructures::parse(member->AccessSpecifier()->getText());
		var->setAccessibility(access);
	}

	auto functions = attribute->methods();
	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f)
		{
			return f->state() == dataStructures::ObjectState::Cretated;
		});
		confirmFunction(resolver, context, f, member);
	}

	attribute->confirm();
}

void cMCompiler::compiler::finalizeAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent,
	language::NameResolver resolver,
	language::NameResolutionContext context)
{
	auto name = ctx->Identifier()->getText();
	not_null attribute = parent->get<dataStructures::Attribute>(name);

	auto functions = attribute->methods();
	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f)
		{
			return f->state() == dataStructures::ObjectState::Confirmed;
		});
		finalizeFunction(resolver, context, f, member);
	}
	attribute->finalize();
}

std::unique_ptr<dataStructures::AttributeInstance> cMCompiler::compiler::createAttributeInstance
(
	dataStructures::AttributeTarget& target,
	gsl::not_null<dataStructures::Attribute*> attribute,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& values,
	language::NameResolver& resolver,
	language::NameResolutionContext& context
)
{
	auto t = std::make_unique<dataStructures::execution::ObjectValue>(attribute->describingType());
	std::unique_ptr<dataStructures::execution::IRuntimeValue> self = std::move(t);
	values.insert(values.begin(), std::make_unique<dataStructures::execution::ReferenceValue>(&self, self->type()));
	auto function = language::resolveOverload(language::getConstructors(attribute->methods()), values, true, true);
	execute(function, std::move(values), resolver, context);

	return std::make_unique<dataStructures::AttributeInstance>(attribute, std::move(self));
}

