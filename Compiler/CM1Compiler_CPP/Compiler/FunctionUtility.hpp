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

	template<typename T>
	void createFunction(T* target, gsl::not_null<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*> ctx)
	{
		using dataStructures::Function;
		using dataStructures::Accessibility;
		using dataStructures::parse;
		auto name = getName(ctx);
		dataStructures::Accessibility accessibility = Accessibility::Private;
		if (ctx->AccessSpecifier() != nullptr)
			accessibility = parse(ctx->AccessSpecifier()->getText());
		not_null function = target->append<Function>(name);
		function->setAccessibility(accessibility);
		if (std::is_same<T, dataStructures::Type>::value)
		{
			function->appendVariable("self", (dataStructures::Type*)target);
		}
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