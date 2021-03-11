#include "ExpressionBuilder.hpp"
#include "../LanguageLogic/ExpressionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "Generic/GenericInstantiationUtility.cpp"

using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;


cMCompiler::language::runtime_value ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallParameterContext*> ctx)
{
	if (ctx->expression() != nullptr)
		return buildExpression(ctx->expression(), nullptr);
	std::terminate();
}

bool cMCompiler::compiler::ExpressionBuilder::hasBinaryOperator(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx) const
{
	return ctx->binaryOperator() != nullptr;
}

std::optional<language::runtime_value> cMCompiler::compiler::ExpressionBuilder::buildSpecialFunction(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, std::string const& functionName)
{
	// todo: awful KYS
	if (functionName == "nameof")
	{
		return language::buildValueLiteralExpression(
			language::buildStringValue(ctx->functionCallParameter(0)->getText()),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	return {};

}

std::vector<cMCompiler::language::runtime_value> cMCompiler::compiler::ExpressionBuilder::buildParameters(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx)
{
	auto result = std::vector<language::runtime_value>();

	for (auto param : ctx->functionCallParameter())
		result.push_back(buildExpression(param->expression(), nullptr));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	if (ctx->Period() != nullptr)
		return buildAccessExpression(ctx, std::move(referenceToParent));
	if (ctx->functionCall() != nullptr)
		return buildExpression(ctx->functionCall(), std::move(referenceToParent));
	if (ctx->throwExpression() != nullptr)
		return buildExpression(ctx->throwExpression(), std::move(referenceToParent));
	if (ctx->newExpression() != nullptr)
		return buildExpression(ctx->newExpression(), std::move(referenceToParent));
	if (hasBinaryOperator(ctx))
		return buildBinaryOperatorExpression(ctx, std::move(referenceToParent));
	if (ctx->identifier() != nullptr)
	{
		auto variableName = ctx->identifier()->getText();
		auto variable = variableLookupFunction_(variableName);
		if (variable == nullptr)
			std::terminate();
		return language::buildVariableReferenceExpressionDescriptor(variable);
	}
	if (ctx->STRING())
	{
		auto text = ctx->STRING()->getText();
		text.erase(text.begin());
		text.erase(text.end() - 1);
		auto value = language::buildStringValue();
		value->setValue(text);
		// todo: parent
		auto result = language::buildValueLiteralExpression(
			std::move(value),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return result;
	}
	if (ctx->IntegerLiteral() != nullptr)
	{
		using namespace dataStructures::execution;
		if (ctx->IntegerLiteral())
		{
			auto lit = language::buildIntegerValue(language::getUsize());
			lit->fromString(ctx->IntegerLiteral()->getText());
			auto result = language::buildValueLiteralExpression(
				std::move(lit),
				language::buildSourcePointer(filepath_.string(), *ctx)
			);
			language::setParent(result.get(), std::move(referenceToParent));
			return result;
		}
	}
	if (ctx->ParamOpen())
		return buildExpression(ctx->expression(0), std::move(referenceToParent));
	std::terminate();//todo: index expression
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildBinaryOperatorExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto op = ctx->binaryOperator()->getText();
	auto expr1 = buildExpression(ctx->expression(0), nullptr);
	auto expr2 = buildExpression(ctx->expression(1), nullptr);

	auto candidates = nameResolver_.resolveOperatorOverloadSet(op, language::getExpressionType(expr1), language::getExpressionType(expr2), context_);
	std::vector<language::runtime_value> args;
	args.push_back(std::move(expr1));
	args.push_back(std::move(expr2));
	auto compileTime = language::resolveOverload(candidates, args, true, false);
	auto runTime = language::resolveOverload(candidates, args, false, true);
	auto result = language::buildBinaryOperatorExpression(
		language::getValueFor(compileTime),
		language::getValueFor(runTime),
		std::move(args[0]),
		std::move(args[1]),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
	language::setParent(result.get(), std::move(referenceToParent));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildAccessExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto expression = buildExpression(ctx->expression(0), nullptr);
	not_null type = language::getExpressionType(expression);
	if (ctx->functionCall() != nullptr)
	{
		auto methodName = ctx->functionCall()->identifier()->getText();

		auto parameters = buildParameters(ctx->functionCall());

		auto result = language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return result;
	}
	else
	{
		assert(ctx->identifier() != nullptr);
		auto fieldName = ctx->identifier()->getText();
		auto fields = type->fields();
		auto field = std::find_if(fields.begin(), fields.end(), [&](auto const e) noexcept {return e->name() == fieldName; });
		assert(field != fields.end());
		auto result = language::buildFieldAccessExpression(
			std::move(expression),
			*field,
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return result;
	}
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto name = ctx->identifier()->getText();
	auto special = buildSpecialFunction(ctx, name);
	if (special)
	{
		language::setParent(special->get(), std::move(referenceToParent));
		return std::move(*special);
	}
	auto arguments = buildParameters(ctx);
	// todo: generics
	// todo: operators
	std::vector<not_null<dataStructures::Function*>> candidates;
	if (ctx->genericUsage() != nullptr)
	{
		auto genericParameters = std::vector<dataStructures::GenericParameter>();
		for (auto g : ctx->genericUsage()->typeSpecifier())
			genericParameters.push_back(
				{
					.value_ = nameResolver_.resolve<dataStructures::Type>(g->identifier()->getText(), context_),
					.referenceLevel_ = gsl::narrow<unsigned char>(g->ref().size())
				}
		);

		auto genericCandidates = nameResolver_.resolveGenericOverloadSet(name, context_);
		for (auto gen : genericCandidates)
			candidates.push_back(instantiate(
				*gen,
				genericParameters,
				nameResolver_,
				context_,
				filepath_
			));
		auto genericType = nameResolver_.resolve<Generic<Type>>(name, context_);
		if (genericType != nullptr)
			for (auto c : instantiate(
				*genericType,
				genericParameters,
				nameResolver_,
				context_,
				filepath_)->methods())
				if (language::isConstructor(c))
					candidates.push_back(c);
	}
	else
	{
		candidates = nameResolver_.resolveOverloadSet(ctx->identifier()->getText(), context_);
		auto type = nameResolver_.resolve<Type>(name, context_);
		if (type != nullptr)
			for (auto c : type->methods())
				if (language::isConstructor(c))
					candidates.push_back(c);
	}
	auto compileTime = language::resolveOverload(candidates, arguments, true, false);
	auto runtime = language::resolveOverload(candidates, arguments, false, true);
	if (language::isConstructor(compileTime) || language::isConstructor(runtime))
	{
		assert((compileTime == nullptr || language::isConstructor(compileTime)) && (runtime == nullptr || language::isConstructor(runtime)));
		return language::buildConstructorInvocationExpression(
			language::getValueFor(compileTime),
			language::getValueFor(runtime),
			language::convertCollection(std::move(arguments), language::getExpressionDescriptor(), 1),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	return language::buildFunctionCallExpression(
		language::getValueFor(compileTime),
		language::getValueFor(runtime),
		language::convertCollection(std::move(arguments), language::getExpressionDescriptor(), 1),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::MemberAccessExpressionContext*> ctx, language::runtime_value&& referenceToParent)
//{
//	if (ctx->Identifier() != nullptr)
//		return language::buildMemberAccessExpression(variableLookupFunction_(ctx->Identifier()->getText()), buildExpression(ctx->expression()));
//	else
//		return language::buildMemberAccessExpression(buildExpression(ctx->functionCall()), buildExpression(ctx->expression()));
//}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ArithmeticExpressionContext*> ctx, dataStructures::Type* requestedType)
//{
//	using namespace dataStructures::execution;
//	if (ctx->IntegerLiteral())
//	{
//		auto lit = language::buildIntegerValue(requestedType);
//		lit->fromString(ctx->IntegerLiteral()->getText());
//		auto result = language::buildValueLiteralExpression(std::move(lit));
//		return std::move(result);
//	}
//}

//cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LExpressionContext*> ctx, language::runtime_value&& referenceToParent)
//{
//	using namespace cMCompiler::dataStructures::ir;
//	auto const identifierChain = ctx->Identifier();
//	auto variableAccess = language::buildVariableReferenceExpression(variableLookupFunction_(identifierChain[0]->getText()));
//	auto strings = std::vector<std::string>();
//	for (not_null id : identifierChain)
//		strings.push_back(id->getText());
//	strings.erase(strings.begin());
//	return language::buildValueMemberAccessExpression(std::move(variableAccess), language::convertToCollection(strings));
//}
