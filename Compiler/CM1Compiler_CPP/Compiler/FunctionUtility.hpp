#pragma once
#include <optional>
#include <filesystem>
#include <memory>
#include <string>
#include <vector>
#include <gsl.h>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	std::string getName(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	dataStructures::Type* returnType(
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		std::filesystem::path file
		);

	dataStructures::Function* getCompatibleFunction(
		std::string const& name,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		std::optional<dataStructures::ObjectState> state = std::optional<dataStructures::ObjectState>());

	std::vector<dataStructures::Type*> getParameterTypes(language::NameResolver& resolver, language::NameResolutionContext& context, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);
	bool compatible(dataStructures::Function* definition, std::vector<dataStructures::Type*> parametrTypes);


	void appendSpecialVariable(not_null<dataStructures::Type*> target, not_null<dataStructures::Function*>f);
	void appendSpecialVariable(not_null<dataStructures::Attribute*> target, not_null<dataStructures::Function*>f);
	void appendSpecialVariable(not_null<dataStructures::Namespace*> target, not_null<dataStructures::Function*>f) noexcept;

	dataStructures::Function* createFunction(not_null<dataStructures::Type*> target, std::string const& name);
	dataStructures::Function* createFunction(not_null<dataStructures::Attribute*> target, std::string const& name);
	dataStructures::Function* createFunction(not_null<dataStructures::Namespace*> target, std::string const& name);

	template<typename T>
	void createFunction(not_null<T*> target, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx, language::NameResolutionContext const&context)
	{
		using dataStructures::Function;
		using dataStructures::Accessibility;
		using dataStructures::parse;
		//todo: generics
		auto generic = ctx->genericSpecifier();
		auto name = getName(ctx);
		if (generic != nullptr)
		{
			std::vector<std::string> parameters{};
			for (not_null param : generic->identifier())
				parameters.push_back(param->getText());
			auto x = target->appendGeneric<Function>(std::move(parameters), ctx->clone(nullptr), name, context);
		}
		else
		{
			dataStructures::Accessibility accessibility = Accessibility::Private;
			if (ctx->AccessSpecifier() != nullptr)
				accessibility = parse(ctx->AccessSpecifier()->getText());
			not_null function = createFunction(target, name);
			function->setAccessibility(accessibility);
			appendSpecialVariable(target, function);
		}
	}


	void confirmFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		std::filesystem::path file);

	void confirmFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<dataStructures::Function*> f,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		std::filesystem::path file);

	void finalizeFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		std::filesystem::path const& file);

	void finalizeFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<dataStructures::Function*> f,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		std::filesystem::path const& file);

}