#include "FunctionUtility.hpp"
#include "FunctionBodyBuilder.hpp"

std::string cMCompiler::compiler::getName(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	return ctx->Identifier(0)->getText();
}

std::string cMCompiler::compiler::returnType(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	return ctx->Identifier(1)->getText();
}

cMCompiler::dataStructures::Function* cMCompiler::compiler::getCompatibleFunction(
	std::string const& name,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	dataStructures::ObjectState state)
{
	auto parameters = getParameterTypes(resolver, context, ctx);
	auto allFunctions = resolver.resolveOverloadSet(name, context);
	auto result = std::find_if(allFunctions.begin(), allFunctions.end(), [&](auto const f)
	{
		if (f->state() != state)
			return false;
		auto params = f->parameters();
		if (params.size() != parameters.size())
			return false;
		for (int i = 0; i < params.size(); i++)
			if (params[i]->type() != parameters[i])
				return false;
		return true;
	});
	if (result != allFunctions.end())
		return *result;
	return nullptr;
}

std::vector<cMCompiler::dataStructures::Type*> cMCompiler::compiler::getParameterTypes(language::NameResolver& resolver, language::NameResolutionContext& context, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	auto result = std::vector<cMCompiler::dataStructures::Type*>();
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
		result.push_back(resolver.resolve<dataStructures::Type>(variable->Identifier(1)->getText(), context));
	return result;
}

void cMCompiler::compiler::confirmFunction(language::NameResolver& resolver, language::NameResolutionContext& context, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	auto name = getName(ctx);
	auto functions = resolver.resolveOverloadSet(name, context);
	auto freeDeclaration = std::find_if(functions.begin(), functions.end(), [](auto const f) noexcept {return f->state() == dataStructures::ObjectState::Cretated; });
	if (freeDeclaration == functions.end())
		std::terminate(); //todo: report error
	not_null function = *freeDeclaration;
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto const type = resolver.resolve<dataStructures::Type>(variable->Identifier(1)->getText(), context);
		function->appendVariable(variable->Identifier(0)->getText(), type);
	}
	function->setReturnType(resolver.resolve<dataStructures::Type>(returnType(ctx), context));
	function->confirm();
}

void cMCompiler::compiler::finalizeFunction(language::NameResolver& resolver, language::NameResolutionContext& context, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	auto name = getName(ctx);
	auto * const function = getCompatibleFunction(name, resolver, context, ctx, dataStructures::ObjectState::Confirmed);
	if (function == nullptr)
		std::terminate(); //todo: report error
	auto parametrs = function->parameters();
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto param = std::find_if(parametrs.begin(), parametrs.end(), [=](const auto p) {return p->name() == variable->Identifier(0)->getText(); });
		assert(param != parametrs.end());
		//todo: attributes
	}
	//todo: function attributes
	auto builder = FunctionBodyBuilder(function, resolver, context);
	ctx->accept(&builder);
	function->finalize();
}
