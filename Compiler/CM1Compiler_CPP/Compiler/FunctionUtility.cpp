#include "FunctionUtility.hpp"
#include "FunctionBodyBuilder.hpp"
#include "TypeUtility.hpp"
#include "Generic/GenericInstantiationUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"

std::string cMCompiler::compiler::getName(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
{
	using namespace std::string_literals;
	if (ctx->functionName()->identifier() != nullptr)
		return ctx->functionName()->identifier()->getText();
	auto name = ctx->functionName()->specialFunctionIdentifier();
	auto result = "operator_"s;
	auto x = name->getText();
	if (name->New() != nullptr)
		result += "new_";
	if (name->Shared() != nullptr)
		result += "shared";
	if (name->Unique())
		return result + "unique";
	if (name->Operator())
		return result + name->binaryOperator()->getText();
}

cMCompiler::dataStructures::TypeReference cMCompiler::compiler::returnType(
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	std::filesystem::path file
)
{
	auto* const id = ctx->typeSpecifier();
	if (id != nullptr)
		return getType(
			resolver,
			context,
			id,
			file
		);
	return {};
}

cMCompiler::dataStructures::Function* cMCompiler::compiler::getCompatibleFunction(
	std::string const& name,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path file,
	std::optional<dataStructures::ObjectState> state)
{
	auto parameters = getParameterTypes(resolver, context, ctx, file);
	auto allFunctions = resolver.resolveOverloadSet(name, context);
	auto result = std::find_if(allFunctions.begin(), allFunctions.end(), [&](auto const f)
		{
			if (state && f->state() != *state)
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

std::vector<cMCompiler::dataStructures::TypeReference> cMCompiler::compiler::getParameterTypes(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path file)
{
	auto result = std::vector<cMCompiler::dataStructures::TypeReference>();
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
		result.push_back(getType(
			resolver,
			context,
			variable->typeSpecifier(),
			file));
	return result;
}

void cMCompiler::compiler::confirmFunction(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<dataStructures::Function*> f,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path file)

{
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto name = variable->identifier()->getText();
		f->appendVariable(
			name,
			getType(
				resolver,
				context,
				variable->typeSpecifier(),
				file)
		);
	}
	auto type = returnType(ctx, resolver, context, file);
	f->setReturnType(type);
	f->confirm();
}

using namespace cMCompiler;

void cMCompiler::compiler::appendSpecialVariable(not_null<dataStructures::Type*> target, not_null<dataStructures::Function*> f)
{
	f->appendVariable("self", { target, 1 });
}

dataStructures::Function* cMCompiler::compiler::createFunction(not_null<dataStructures::Type*> target, std::string const& name)
{
	return target->append<dataStructures::Function>(name);
}

dataStructures::Function* cMCompiler::compiler::createFunction(not_null<dataStructures::Namespace*> target, std::string const& name)
{
	return target->append<dataStructures::Function>(name);
}

dataStructures::Function* cMCompiler::compiler::createFunction(not_null<dataStructures::Attribute*> target, std::string const& name)
{
	return target->appendFunction(name);
}


void cMCompiler::compiler::appendSpecialVariable(not_null<dataStructures::Attribute*> target, not_null<dataStructures::Function*> f)
{
	f->appendVariable("self", { target->describingType(), 1 });
}

void cMCompiler::compiler::appendSpecialVariable(not_null<dataStructures::Namespace*> target, not_null<dataStructures::Function*> f) noexcept
{
}

void cMCompiler::compiler::confirmFunction(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path file)
{
	if (ctx->genericSpecifier() != nullptr)
		return;
	auto name = getName(ctx);
	auto functions = resolver.resolveOverloadSet(name, context);
	auto freeDeclaration = std::find_if(functions.begin(), functions.end(), [](auto const f) noexcept { return f->state() == dataStructures::ObjectState::Cretated; });
	if (freeDeclaration == functions.end())
		std::terminate(); //todo: report error
	not_null function = *freeDeclaration;
	confirmFunction(resolver, context, function, ctx, file);
}

void cMCompiler::compiler::finalizeFunction(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path const& file)
{
	if (ctx->genericSpecifier() != nullptr)
		return;
	auto name = getName(ctx);
	auto* const function = getCompatibleFunction(
		name,
		resolver,
		context,
		ctx,
		file,
		dataStructures::ObjectState::Confirmed);
	if (function == nullptr)
		std::terminate(); //todo: report error
	finalizeFunction(resolver, context, function, ctx, file);
}

void cMCompiler::compiler::finalizeFunction(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<dataStructures::Function*> f,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
	std::filesystem::path const& file)
{
	auto parametrs = f->parameters();
	for (not_null<CMinusEqualsMinus1Revision0Parser::ParameterContext*> variable : ctx->parameterList()->parameter())
	{
		auto param = std::find_if(parametrs.begin(), parametrs.end(), [=](const auto p) { return p->name() == variable->identifier()->getText(); });
		assert(param != parametrs.end());
		//todo: attributes
	}
	//todo: function attributes
	if (!f->metadata().ignoreBody && ctx->functionBody())
	{
		auto builder = FunctionBodyBuilder(f, resolver, context, file);
		ctx->functionBody()->accept(&builder);
	}
	f->setSourceLocation(language::buildSourcePointer(file.string(), *ctx));
	f->finalize();
}
