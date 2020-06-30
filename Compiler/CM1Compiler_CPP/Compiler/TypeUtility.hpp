#pragma once
#include "../DataStructures/Namespace.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../LanguageLogic/NameResolver.hpp"
namespace cMCompiler::compiler
{
	void createType(
		dataStructures::Namespace* target,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx);

	void confirmType(language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx);
	void finalizeType(language::NameResolver& resolver,
		language::NameResolutionContext& context,
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*> ctx);

}