#include "TypeUtility.hpp"
#include "FunctionUtility.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "Generic/GenericInstantiationUtility.hpp"

std::string name(gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	return ctx->identifier()->getText();
}

cMCompiler::dataStructures::Type* cMCompiler::compiler::createType(
	dataStructures::Namespace* target,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	assert(target != nullptr);
	auto name = ::name(ctx);
	auto generic = ctx->genericSpecifier();
	auto type = target->get<dataStructures::Type>(name);
	if (generic != nullptr)
	{
		std::vector<std::string> parameters{};
		for (not_null param : generic->identifier())
			parameters.push_back(param->getText());
		auto x = target->appendGeneric<dataStructures::Type>(std::move(parameters), ctx->clone(nullptr), name, context);
		return nullptr;
	}
	else
	{
		if (type == nullptr)
			type = target->append<dataStructures::Type>(name);
		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
				createFunction(not_null(type), member, context);
		type->setTypeClassifier(dataStructures::parseType(ctx->classTypeSpecifier()->getText()));
	}
	return type;
}

void cMCompiler::compiler::confirmType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx,
	std::filesystem::path file)
{
	assert(ctx != nullptr);
	auto name = ::name(ctx);
	auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
	auto const generic = ctx->genericSpecifier();
	if (generic == nullptr)
	{
		assert(type != nullptr);

		if (ctx->implementedInterfacesSequence() != nullptr)
			for (not_null interface : ctx->implementedInterfacesSequence()->identifier())
			{
				auto implementedType = resolver.resolve<dataStructures::Type>(interface->getText(), context);
				if (implementedType == nullptr)
					std::terminate(); //todo: report error
				type->appendInterface(implementedType);
			}

		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext*> member : ctx->classContentSequence()->fieldDeclaration())
			{
				auto t = getType(
					resolver,
					context,
					member->typeSpecifier(),
					file
				);
				auto var = type->appendField(member->identifier()->getText(), t);
				auto access = dataStructures::parse(member->AccessSpecifier()->getText());
				var->setAccessibility(access);
			}

		//todo: attributes
		auto functions = type->methods();
		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
			{
				not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f) noexcept
					{
						return f->state() == dataStructures::ObjectState::Cretated;
					});
				confirmFunction(resolver, context, f, member, file);
			}
		type->confirm();
	}
}

void cMCompiler::compiler::finalizeType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx,
	std::filesystem::path const& file)
{
	assert(ctx != nullptr);
	auto const * const generic = ctx->genericSpecifier();
	if (generic == nullptr)
	{
		auto name = ::name(ctx);
		auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
		assert(type != nullptr);

		auto functions = type->methods();
		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
			{
				not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f) noexcept
					{
						return f->state() == dataStructures::ObjectState::Confirmed;
					});
				finalizeFunction(resolver, context, f, member, file);
			}
		type->finalize();
	}
}

cMCompiler::dataStructures::TypeReference cMCompiler::compiler::getType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext*> ctx,
	std::filesystem::path file)
{
	auto name = ctx->identifier()->getText();
	std::cout << ctx->getText() << std::endl;
	// todo: arrays
	if (ctx->genericUsage())
	{
		std::vector<dataStructures::TypeReference> parameters;
		for (not_null p : ctx->genericUsage()->typeSpecifier())
		{
			auto name = p->getText();
			parameters.push_back(
				getType(
					resolver,
					context,
					p,
					file
				));
		}
		not_null g = resolver.resolve<dataStructures::Generic<dataStructures::Type>>(name, context);
		return { instantiate(*g, parameters, resolver, context, file), ctx->ref().size() };
	}
	return {resolver.resolve<dataStructures::Type>(name, context), ctx->ref().size() };
}
