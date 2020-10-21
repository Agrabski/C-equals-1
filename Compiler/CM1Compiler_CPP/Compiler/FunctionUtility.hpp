#pragma once
#include <optional>
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../DataStructures/Function.hpp"
#include "../DataStructures/Accessibility.hpp"
#include "../LanguageLogic/NameResolver.hpp"

namespace cMCompiler::compiler
{
	std::string getName(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	std::optional<std::string> returnType(gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	dataStructures::Function* getCompatibleFunction(
		std::string const& name,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx,
		dataStructures::ObjectState state);

	std::vector<dataStructures::Type*> getParameterTypes(language::NameResolver& resolver, language::NameResolutionContext& context, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);
	bool compatible(dataStructures::Function* definition, std::vector<dataStructures::Type*> parametrTypes);


	void appendSpecialVariable(not_null<dataStructures::Type*> target, not_null<dataStructures::Function*>f);
	void appendSpecialVariable(not_null<dataStructures::Attribute*> target, not_null<dataStructures::Function*>f);
	void appendSpecialVariable(not_null<dataStructures::Namespace*> target, not_null<dataStructures::Function*>f) noexcept;

	dataStructures::Function* createFunction(not_null<dataStructures::Type*> target, std::string const& name);
	dataStructures::Function* createFunction(not_null<dataStructures::Attribute*> target, std::string const& name);
	dataStructures::Function* createFunction(not_null<dataStructures::Namespace*> target, std::string const& name);

	template<typename T>
	void createFunction(not_null<T*> target, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
	{
		using dataStructures::Function;
		using dataStructures::Accessibility;
		using dataStructures::parse;
		auto name = getName(ctx);
		dataStructures::Accessibility accessibility = Accessibility::Private;
		if (ctx->AccessSpecifier() != nullptr)
			accessibility = parse(ctx->AccessSpecifier()->getText());
		not_null function = createFunction(target, name);
		function->setAccessibility(accessibility);
		//todo: generics
		/*auto generic = ctx->genericSpecifier();
		if (generic != nullptr)
			for (not_null param : generic->Identifier())
				function->pushParameter(param->getText());*/
		appendSpecialVariable(target, function);
	}


	void confirmFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	void confirmFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<dataStructures::Function*> f,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	void finalizeFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

	void finalizeFunction(
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<dataStructures::Function*> f,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx);

}