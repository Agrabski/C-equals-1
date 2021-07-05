#include "AttributeUtility.hpp"
#include "FunctionUtility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "../DataStructures/execution/ObjectValue.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/TypeInstantiationUtility.hpp"
#include "ExpressionEvaluator.hpp"
#include "ExpressionBuilder.hpp"
#include "TypeUtility.hpp"
using cMCompiler::compiler::ExpressionEvaluator;
using namespace cMCompiler::dataStructures::execution;

using namespace cMCompiler;

void cMCompiler::compiler::createAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent,
	language::NameResolutionContext const& context)
{
	auto name = ctx->identifier()->getText();
	not_null attribute = parent->append<dataStructures::Attribute>(name);
	attribute->setAccessibility(dataStructures::parse(ctx->AccessSpecifier()->getText()));
	auto targets = std::vector<std::string>();
	for (not_null c : ctx->attributeTarget())
		targets.push_back(c->getText());
	attribute->addAttributeTarget(dataStructures::parseTarget(targets));

	for (not_null member : ctx->classContentSequence()->functionDeclaration())
		createFunction<dataStructures::Attribute>(attribute, member, context);


}

void cMCompiler::compiler::confirmAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent,
	language::NameResolver resolver,
	language::NameResolutionContext context,
	std::filesystem::path const& file)
{
	not_null attribute = parent->get<dataStructures::Attribute>(ctx->identifier()->getText());
	for (not_null member : ctx->classContentSequence()->fieldDeclaration())
	{
		auto type = getType(
			resolver,
			context,
			member->typeSpecifier(),
			file);
		auto var = attribute->appendField(member->identifier()->getText(), type);
		auto access = dataStructures::parse(member->AccessSpecifier()->getText());
		var->setAccessibility(access);
	}

	auto functions = attribute->methods();
	for (not_null member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto function) noexcept
			{
				return function->state() == dataStructures::ObjectState::Cretated;
			});
		confirmFunction(resolver, context, f, member, file);
	}

	attribute->confirm();
}

void cMCompiler::compiler::finalizeAttribute(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
	gsl::not_null<dataStructures::Namespace*> parent,
	language::NameResolver resolver,
	language::NameResolutionContext context,
	std::filesystem::path const& file)
{
	auto name = ctx->identifier()->getText();
	not_null attribute = parent->get<dataStructures::Attribute>(name);

	auto functions = attribute->methods();
	for (not_null member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto function) noexcept
			{
				return function->state() == dataStructures::ObjectState::Confirmed;
			});
		finalizeFunction(resolver, context, f, member, file);
	}
	attribute->finalize();
}

std::unique_ptr<dataStructures::AttributeInstance> cMCompiler::compiler::createAttributeInstance
(
	dataStructures::AttributeTarget const& target,
	gsl::not_null<dataStructures::Attribute*> attribute,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& values
)
{
	auto t = language::instantiate({ attribute->describingType(), 0 });
	std::unique_ptr<dataStructures::execution::IRuntimeValue> self = std::move(t);
	if (auto constructors = language::getConstructors(attribute->methods()); !constructors.empty())
	{
		auto function = language::resolveOverloadForExecution(constructors, values, true, true);
		values.insert(values.begin(), dataStructures::execution::ReferenceValue::make(&self, self->type()));
		execute(function, std::move(values));
	}

	return std::make_unique<dataStructures::AttributeInstance>(attribute, std::move(self));
}

void cMCompiler::compiler::attachAttribute(not_null<dataStructures::Function*> f,
	not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	ExpressionBuilder& ep)
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> dummyValue;
	auto attributeName = attribute->functionCall()->identifier()->getText();
	not_null attributeType = resolver.resolve<dataStructures::Attribute>(attributeName, context);
	auto parameters = std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
	for (auto p : attribute->functionCall()->functionCallParameter())
	{
		auto evaluator = ExpressionEvaluator([&dummyValue](const auto&) -> std::unique_ptr<dataStructures::execution::IRuntimeValue>&
			{
				return dummyValue;
			});
		auto expression = ep.buildExpression(p);
		parameters.push_back(evaluator.evaluate(*expression));
	}
	auto instance = cMCompiler::compiler::createAttributeInstance(*f, attributeType, std::move(parameters));
	f->appendAttribute(std::move(instance));
}

void cMCompiler::compiler::attachAttribute(not_null<dataStructures::Type*> type,
	not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	ExpressionBuilder& ep)
{
	//todo: todo
}
