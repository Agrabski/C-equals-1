#include "ExpressionBuilder.hpp"
#include <boost/regex.hpp>
#include <ranges>
#include "../LanguageLogic/ExpressionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/LiteralUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/TypeInstantiationUtility.hpp"
#include "Generic/GenericInstantiationUtility.hpp"
#include "TypeUtility.hpp"


using namespace cMCompiler::dataStructures::ir;
using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;


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

std::optional<cMCompiler::language::runtime_value> cMCompiler::compiler::ExpressionBuilder::buildSpecialFunction(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionCallContext*> ctx, std::string const& functionName)
{
	// todo: awful KYS
	if (functionName == "nameof")
	{
		return language::buildValueLiteralExpression(
			language::moveToHeap(language::buildStringValue(ctx->functionCallParameter(0)->getText())),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	if (functionName == "typeof")
	{
		std::stringstream ss{ ctx->functionCallParameter(0)->getText() };
		auto type = Parser::ParserAdapter().parseType(ss);
		return language::buildValueLiteralExpression(
			language::moveToHeap(language::getValueFor(
				getType(
					nameResolver_,
					context_,
					type.get(),
					filepath_
				))),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	if (functionName == "genericTypeof")
	{
		auto name = ctx->functionCallParameter(0)->getText();
		auto value = nameResolver_.resolve<Generic<Type>>(name, context_);
		return language::buildValueLiteralExpression(
			language::moveToHeap(language::getValueFor(
				value
			)),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	if (functionName == "genericFunctionof")
	{
		auto name = ctx->functionCallParameter(0)->getText();
		auto value = nameResolver_.resolve<Generic<Function>>(name, context_);
		return language::buildValueLiteralExpression(
			language::moveToHeap(language::getValueFor(
				value
			)),
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

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::LiteralFunctionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::stringstream ss{ ctx->typeSpecifier()->getText() };
	auto type = Parser::ParserAdapter().parseType(ss);
	return language::buildValueLiteralExpression(
		language::moveToHeap(language::getValueFor(
			getType(
				nameResolver_,
				context_,
				type.get(),
				filepath_
			))),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}


cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::DereferenceExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	return language::buildDereferenceExpression(
		buildExpression(ctx->expression(), nullptr),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ArrayLiteralContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::vector< cMCompiler::language::runtime_value> expressions;

	for (auto expr : ctx->expression())
		expressions.push_back(buildExpression(expr, nullptr));

	auto result = language::buildArrayLiteralExpression(
		language::moveToHeap(
			language::convertCollection(std::move(expressions), { language::getExpressionDescriptor(),1 })
		),
		getType(
			nameResolver_,
			context_,
			ctx->typeReference(),
			filepath_),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::AdressOfExpressionContext*> ctx,
	language::runtime_value&& referenceToParent)
{
	return language::buildAdressofExpression(buildExpression(ctx->expression(), nullptr), std::move(referenceToParent));
}


cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	if (ctx->adressOfExpression() != nullptr)
		return buildExpression(ctx->adressOfExpression(), std::move(referenceToParent));
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
	if (ctx->arrayLiteral())
		return buildExpression(ctx->arrayLiteral(), std::move(referenceToParent));
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
		auto value = language::moveToHeap(
			utilities::pointer_cast<dataStructures::execution::IRuntimeValue>(
				language::buildStringValue(boost::regex_replace(text, boost::regex("\\\\(.|\\s)"), "$1"))
				)
		);
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
			auto ref = language::moveToHeap(
				utilities::pointer_cast<dataStructures::execution::IRuntimeValue>(
					std::move(lit)
					)
			);
			auto result = language::buildValueLiteralExpression(
				std::move(ref),
				language::buildSourcePointer(filepath_.string(), *ctx)
			);
			language::setParent(result.get(), std::move(referenceToParent));
			return result;
		}
	}
	if (ctx->ParamOpen())
		return buildExpression(ctx->expression(0), std::move(referenceToParent));
	if (ctx->indexExpression())
	{
		auto expression = buildExpression(ctx->expression(0), nullptr);
		auto type = language::getExpressionType(expression);
		std::vector<language::runtime_value> expressions;
		for (auto exp : ctx->indexExpression()->expression())
			expressions.push_back(buildExpression(exp, nullptr));
		auto result = language::buildIndexOperatorExpression(
			std::move(expression),
			type,
			std::move(expressions),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return std::move(result);
	}
	if (ctx->dereferenceExpression())
		return buildExpression(ctx->dereferenceExpression(), nullptr);
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildBinaryOperatorExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto op = ctx->binaryOperator()->getText();
	auto expr1 = buildExpression(ctx->expression(0), nullptr);
	auto expr2 = buildExpression(ctx->expression(1), nullptr);

	auto result = language::buildBinaryOperatorExpression(
		nameResolver_,
		context_,
		op,
		std::move(expr1),
		std::move(expr2),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
	language::setParent(result.get(), std::move(referenceToParent));
	return result;
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildAccessExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	auto expression = buildExpression(ctx->expression(0), nullptr);
	auto type = language::getExpressionType(expression);
	if (ctx->functionCall() != nullptr)
	{
		auto methodName = ctx->functionCall()->identifier()->getText();

		auto parameters = buildParameters(ctx->functionCall());
		auto genericParameters = std::vector<dataStructures::TypeReference>();
		if (ctx->functionCall()->genericUsage() != nullptr)
		{
			// todo: expression parameters
			for (auto g : ctx->functionCall()->genericUsage()->genericParameter())
				genericParameters.push_back(getType(
					nameResolver_,
					context_,
					g->typeSpecifier(),
					filepath_
				));
		}

		auto result = language::buildMethodCallExpression(
			std::move(expression),
			type,
			std::move(parameters),
			methodName,
			genericParameters,
			language::buildSourcePointer(filepath_.string(), *ctx),
			nameResolver_,
			context_,
			filepath_
		);
		language::setParent(result.get(), std::move(referenceToParent));
		return result;
	}
	else
	{
		assert(ctx->identifier() != nullptr);
		auto fieldName = ctx->identifier()->getText();
		auto fields = type.type->fields();
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
	if (ctx->literalFunction() != nullptr)
		return buildExpression(ctx->literalFunction(), std::move(referenceToParent));

	auto name = ctx->identifier()->getText();
	auto special = buildSpecialFunction(ctx, name);
	if (special)
	{
		language::setParent(special->get(), std::move(referenceToParent));
		return std::move(*special);
	}
	auto arguments = buildParameters(ctx);
	std::vector<not_null<dataStructures::Function*>> candidates;
	if (ctx->genericUsage() != nullptr)
	{
		// todo: expression parameters
		auto genericParameters = std::vector<dataStructures::TypeReference>();
		for (auto g : ctx->genericUsage()->genericParameter())
			genericParameters.push_back(getType(
				nameResolver_,
				context_,
				g->typeSpecifier(),
				filepath_
			));

		for (auto gen : nameResolver_.resolveGenericOverloadSet(name, context_))
			candidates.push_back(instantiate(
				*gen,
				genericParameters,
				nameResolver_,
				context_,
				filepath_
			));
		auto genericType = nameResolver_.resolve<dataStructures::Generic<dataStructures::Type>>(name, context_);
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
			language::convertCollection(std::move(arguments), { language::getExpressionDescriptor(), 1 }),
			language::buildSourcePointer(filepath_.string(), *ctx)
		);
	}
	if (compileTime == nullptr && runtime == nullptr)
 		std::cerr << "Function " << name << " does not exist";
	assert((compileTime != nullptr) || (runtime != nullptr));

	return language::buildFunctionCallExpression(
		language::getValueFor(compileTime),
		language::getValueFor(runtime),
		language::convertCollection(std::move(arguments), { language::getExpressionDescriptor(), 1 }),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(gsl::not_null<CMinusEqualsMinus1Revision0Parser::ThrowExpressionContext*> ctx, language::runtime_value&& referenceToParent)
{
	std::terminate();
}

cMCompiler::language::runtime_value cMCompiler::compiler::ExpressionBuilder::buildExpression(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::NewExpressionContext*> ctx,
	language::runtime_value&& referenceToParent)
{
	auto type = getType(nameResolver_, context_, ctx->typeReference(), filepath_);
	auto methods = type.type->methods();
	auto e = std::remove_if(methods.begin(), methods.end(), [](auto const& e) {return !language::isConstructor(e); });
	if (e != methods.end())
		methods.erase(e);
	auto params = std::vector<language::runtime_value>();

	for (auto param : ctx->functionCallParameter())
		params.push_back(buildExpression(param->expression(), nullptr));

	auto compileTime = language::resolveOverload(methods, params, true, false);
	auto runTime = language::resolveOverload(methods, params, false, true);
	auto compileNewOperator = nameResolver_.resolveOperatorNewUnique(context_, type, true, false);
	auto runNewOperator = nameResolver_.resolveOperatorNewUnique(context_, type, false, true);
	return language::buildNewExpression(
		language::getValueFor(runNewOperator),
		language::getValueFor(compileNewOperator),
		language::getValueFor(runTime),
		language::getValueFor(compileTime),
		language::convertCollection(std::move(params), { language::getExpressionDescriptor(), 1 }),
		language::buildSourcePointer(filepath_.string(), *ctx)
	);
}

