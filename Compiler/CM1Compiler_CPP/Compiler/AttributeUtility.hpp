#pragma once
#include "../DataStructures/AttributeInstance.hpp"
#include "../DataStructures/execution/ReferenceValue.hpp"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../DataStructures/Namespace.hpp"
#include "../LanguageLogic/NameResolver.hpp"
#include "../LanguageLogic/SpecialFunctionUtility.hpp"
#include "../LanguageLogic/MetatypeUility.hpp"
#include "FunctionExecutionUtility.hpp"
#include "ExpressionBuilder.hpp"

namespace cMCompiler::compiler
{
	void createAttribute(
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
		gsl::not_null<dataStructures::Namespace*> parent, 
		language::NameResolutionContext const& context);

	void confirmAttribute(
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
		gsl::not_null<dataStructures::Namespace*> parent,
		language::NameResolver resolver,
		language::NameResolutionContext context,
		std::filesystem::path const& file);

	void finalizeAttribute(
		gsl::not_null<CMinusEqualsMinus1Revision0Parser::AttributeDeclarationContext*> ctx,
		gsl::not_null<dataStructures::Namespace*> parent,
		language::NameResolver resolver,
		language::NameResolutionContext context,
		std::filesystem::path const& file);

	std::unique_ptr<dataStructures::AttributeInstance> createAttributeInstance
	(
		dataStructures::AttributeTarget const& target,
		gsl::not_null<dataStructures::Attribute*> attribute,
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& values
	);

	void attachAttribute(
		not_null<dataStructures::Function*>f,
		not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		ExpressionBuilder& ep);

	void attachAttribute(
		not_null<dataStructures::Type*>t,
		not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute,
		language::NameResolver& resolver,
		language::NameResolutionContext& context,
		ExpressionBuilder& ep);

	template<typename T>
	void executeAttachmentFunction(
		not_null<T*> target,
		not_null<dataStructures::AttributeInstance*> instance,
		language::NameResolver& resolver,
		language::NameResolutionContext& context)
	{
		auto attachmentFunction = language::getAtachmentFunction(target, instance);
		auto descriptor = language::getValueFor(target);
		auto& thisObject = instance->objectInstance();
		std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>> params;
		params.push_back(dataStructures::execution::ReferenceValue::make(&thisObject, thisObject->type()));
		params.push_back(std::move(descriptor));
		execute(attachmentFunction, std::move(params));
	}
}
