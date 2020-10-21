#include "TypeUtility.hpp"
#include "FunctionUtility.hpp"
#include "../DataStructures/Accessibility.hpp"

std::string name(gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	return ctx->Identifier()->getText();
}

void cMCompiler::compiler::createType(
	dataStructures::Namespace* target,
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	assert(target != nullptr);
	auto name = ::name(ctx);
	auto type = target->get<dataStructures::Type>(name);
	if (type == nullptr)
		type = target->append<dataStructures::Type>(name);

	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
		createFunction(not_null(type), member);
	type->setTypeClassifier(dataStructures::parseType(ctx->classTypeSpecifier()->getText()));
}

void cMCompiler::compiler::confirmType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	assert(ctx != nullptr);
	auto name = ::name(ctx);
	auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
	assert(type != nullptr);

	if (ctx->implementedInterfacesSequence() != nullptr)
		for (not_null interface : ctx->implementedInterfacesSequence()->Identifier())
		{
			auto implementedType = resolver.resolve<dataStructures::Type>(interface->getText(), context);
			if (implementedType == nullptr)
				std::terminate(); //todo: report error
			type->appendInterface(implementedType);
		}

	for (not_null<CMinusEqualsMinus1Revision0Parser::FieldDeclarationContext*> member : ctx->classContentSequence()->fieldDeclaration())
	{
		auto t = resolver.resolve<dataStructures::Type>(member->typeSpecifier()->Identifier()->getText(), context);
		auto var = type->appendField(member->Identifier()->getText(), t);
		auto access = dataStructures::parse(member->AccessSpecifier()->getText());
		var->setAccessibility(access);
	}

	//todo: attributes
	auto functions = type->methods();
	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f) noexcept
		{
			return f->state() == dataStructures::ObjectState::Cretated;
		});
		confirmFunction(resolver, context, f, member);
	}
	type->confirm();
}

void cMCompiler::compiler::finalizeType(
	language::NameResolver& resolver,
	language::NameResolutionContext& context,
	gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx)
{
	assert(ctx != nullptr);
	auto name = ::name(ctx);
	auto type = context.namespaceStack_.back()->get<dataStructures::Type>(name);
	assert(type != nullptr);

	auto functions = type->methods();
	for (not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> member : ctx->classContentSequence()->functionDeclaration())
	{
		not_null f = *std::find_if(functions.begin(), functions.end(), [&](const auto f) noexcept
		{
			return f->state() == dataStructures::ObjectState::Confirmed;
		});
		finalizeFunction(resolver, context, f, member);
	}
	type->finalize();
}
