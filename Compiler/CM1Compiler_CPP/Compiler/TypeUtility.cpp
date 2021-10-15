#include "TypeUtility.hpp"
#include "FunctionUtility.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/GenericUtility.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "Generic/GenericInstantiationUtility.hpp"

std::string name(gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	return ctx->identifier()->getText();
}

void appendDefaultConstructor(
	not_null<cMCompiler::dataStructures::Type*> type,
	not_null< CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> declaration,
	std::filesystem::path file)
{
	using namespace cMCompiler::dataStructures;
	using namespace cMCompiler;
	auto c = type->append<Function>("construct");
	c->setIrCollection(std::make_unique<execution::ArrayValue>(TypeReference{ language::getCollectionTypeFor(
			TypeReference{ language::getIInstruction(), 1 }), 0 },
		TypeReference{ language::getIInstruction() ,1 }
	));
	// todo: initialise fields
	c->code()->push(language::buildReturnStatement(language::buildSourcePointer(file.string(), *declaration)));
	c->setReturnType({ nullptr, 0 });
	c->setSourceLocation(language::buildSourcePointer(file.string(), *declaration));
	cMCompiler::compiler::appendSpecialVariable(type, c);
}

cMCompiler::dataStructures::Type* cMCompiler::compiler::createType(
	dataStructures::Namespace* target,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx,
	std::filesystem::path const& path)
{
	assert(target != nullptr);
	auto name = ::name(ctx);
	auto generic = ctx->genericSpecifier();
	auto type = target->get<dataStructures::Type>(name);
	if (generic != nullptr)
	{
		std::vector<std::string> parameters{};
		for (not_null param : generic->genericParameterDeclaration())
			parameters.push_back(param->identifier()->getText());
		auto x = target->appendGeneric<dataStructures::Type>(std::move(parameters), ctx->clone(nullptr), name, context, path);
		return nullptr;
	}
	else
	{
		if (type == nullptr)
			type = target->append<dataStructures::Type>(name);
		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
				createFunction(not_null(type), member, context, path);
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
	auto name = ::name(ctx);
	auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
	return confirmType(resolver, context, type, ctx, file);
}

void cMCompiler::compiler::finalizeType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx,
	std::filesystem::path const& file)
{
	auto name = ::name(ctx);
	auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
	finalizeType(resolver, context, type, ctx, file);
}

void cMCompiler::compiler::confirmType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	dataStructures::Type* type,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx,
	std::filesystem::path file)
{
	assert(ctx != nullptr);
	auto const generic = ctx->genericSpecifier();
	if (generic == nullptr)
	{
		assert(type != nullptr);

		if (ctx->implementedInterfacesSequence() != nullptr)
			for (not_null interface : ctx->implementedInterfacesSequence()->typeReference())
			{
				getType(resolver, context, interface, file);
				auto implementedType = resolver.resolve<dataStructures::Type>(interface->getText(), context);
				if (implementedType == nullptr)
					std::terminate(); //todo: report error
				type->appendInterface(implementedType);
			}

		if (ctx->classContentSequence() != nullptr)
			for (not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext*> member : ctx->classContentSequence()->fieldDeclaration())
			{
				auto typeName = member->typeSpecifier();
				auto t = getType(
					resolver,
					context,
					typeName,
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
		type->setSourceLocation(language::buildSourcePointer(file.string(), *ctx));

	}
}

void cMCompiler::compiler::finalizeType(language::NameResolver& resolver, language::NameResolutionContext& context, dataStructures::Type* type, gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx, std::filesystem::path const& file)
{
	assert(ctx != nullptr);
	auto const* const generic = ctx->genericSpecifier();
	if (generic == nullptr)
	{
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
		if (auto methods = type->methods(); !std::any_of(methods.begin(), methods.end(), language::isConstructor))
			appendDefaultConstructor(type, ctx, file);
		type->finalize();
	}
}

cMCompiler::dataStructures::TypeReference cMCompiler::compiler::getType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeReferenceContext*> ctx,
	std::filesystem::path file
)
{
	auto name = ctx->identifier()->getText();
	if (name == "void")
		return { nullptr, 0 };
	dataStructures::Type* type;
	if (ctx->genericUsage())
	{
		std::vector<dataStructures::TypeReference> parameters;
		for (not_null p : ctx->genericUsage()->genericParameter())
		{
			auto name = p->getText();
			parameters.push_back(
				getType(
					resolver,
					context,
					p->typeSpecifier(),
					file
				));
		}
		not_null g = resolver.resolve<dataStructures::Generic<dataStructures::Type>>(name, context);
		type = instantiate(*g, parameters, resolver, context, file);
	}
	else
		if (ctx->typenameReferencesAttribute() == nullptr)
			type = resolver.resolve<dataStructures::Type>(name, context);
		else
			type = resolver.resolve<dataStructures::Attribute>(name, context)->describingType();
	return dataStructures::TypeReference{ type, 0 };
}


cMCompiler::dataStructures::TypeReference cMCompiler::compiler::getType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext*> ctx,
	std::filesystem::path file)
{
	auto result = getType(resolver, context, ctx->typeReference(), file);

	return processModifier(result.type, ctx->modifier(), context);
}

cMCompiler::dataStructures::TypeReference cMCompiler::compiler::processModifier(
	dataStructures::Type* baseType,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::ModifierContext*> ctx,
	language::NameResolutionContext& context)
{
	auto referenceCount = ctx->ref().size();
	if (ctx->arraySpecifier())
	{
		if (!context.objectMap_.contains("array")) // todo: stop hardcoding shit fuckface!
			context.objectMap_["array"].push_back(language::getArray());
		return {
			language::getCollectionTypeFor(
				processModifier(
						baseType,
						ctx->arraySpecifier()->modifier(),
					context
				)
			),
			referenceCount
		};
	}

	return { baseType, referenceCount };
}
