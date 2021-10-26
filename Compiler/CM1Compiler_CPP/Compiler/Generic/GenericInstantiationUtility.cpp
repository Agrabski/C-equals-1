#include "GenericInstantiationUtility.hpp"
#include <ranges>
#include <algorithm>
#include "../../ParserAdapter/ParserAdapter.hpp"
#include "../FunctionUtility.hpp"
#include "../../LanguageLogic/GenericUtility.hpp"
#include "../FunctionBodyBuilder.hpp"
#include "../Preprocessor.hpp"
#include "../AttributeUtility.hpp"
#include "../TypeUtility.hpp"
#include "../../LanguageLogic/FunctionPredicates.hpp"
#include "../../LanguageLogic/OverloadResolutionUtility.hpp"
#include "../Preprocessor.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler;

not_null<dataStructures::Function*> cMCompiler::compiler::instantiate
(
	dataStructures::Generic<Function>& function,
	std::vector<dataStructures::TypeReference> const& genericParameters,
	language::NameResolver& resolver,
	language::NameResolutionContext const& c,
	std::filesystem::path const& file
)
{
	static std::vector<GenericKey<Function>> instantiations;
	auto existing = std::ranges::find_if(begin(instantiations), end(instantiations), [&](const auto& e) noexcept
		{
			if (e.prototype != &function)
				return false;
			else
				for (int i = 0; i < e.parameters.size(); i++)
					if (genericParameters[i] != e.parameters[i])
						return false;
			return true;
		});
	if (existing != instantiations.end())
		return existing->value;
	if (function.isSpecial())
		return function.fillSpecial(genericParameters);
	auto tree = function.fillGeneric(genericParameters);
	auto x = tree->getText();
	not_null functionTree = dynamic_cast<CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext*>(tree.get());
	not_null f = createFunction(c.package_->rootNamespace(), function.name());
	instantiations.emplace_back(&function, genericParameters, f);
	f->name() = language::getGenericMangledName(function, genericParameters);
	language::setOverloadResolutionInformation(f, genericParameters);
	auto context = NameResolutionContext::merge(function.context(), c);


	auto ep = ExpressionBuilder(function.path(), resolver, context, [](const auto&) { return nullptr; });
	if (functionTree->attributeSequence())
		for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : functionTree->attributeSequence()->attribute())
			attachAttribute(f, attribute, resolver, context, ep);

	for (not_null<AttributeInstance*> attribute : f->attributes())
		executeAttachmentFunction(f, attribute, resolver, context);

	if (language::isExecutable(f))
	{
		confirmFunction(resolver, context, f, functionTree, function.path());
		finalizeFunction(resolver, context, f, functionTree, function.path());
	}
	if (context.objectMap_.contains(function.name()))
		context.objectMap_[function.name()].push_back(f);
	f->setInstantiationData({
		&function,
		genericParameters
		});
	if (functionTree->attributeSequence())
	{
		for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : functionTree->attributeSequence()->attribute())
			attachAttribute(f, attribute, resolver, context, ep);

	}
	return f;
}

not_null<dataStructures::Type*> cMCompiler::compiler::instantiate
(
	dataStructures::Generic<Type>& genericType,
	std::vector<dataStructures::TypeReference> const& genericParameters,
	language::NameResolver& resolver,
	language::NameResolutionContext const& c,
	std::filesystem::path const& file
)
{
	static std::vector<GenericKey<Type>> instantiations;
	auto existing = std::find_if(begin(instantiations), end(instantiations), [&](const auto& e)
		{
			if (e.prototype != &genericType)
				return false;
			else
				for (int i = 0; i < e.parameters.size(); i++)
					if (genericParameters[i] != e.parameters[i])
						return false;
			return true;
		});
	if (existing != instantiations.end())
		return existing->value;
	if (genericType.isSpecial())
		return genericType.fillSpecial(genericParameters);
	auto context = NameResolutionContext::merge(genericType.context(), c);
	auto x = genericType.fillGeneric(genericParameters);
	not_null ast = dynamic_cast<CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext*>(x.get());
	not_null type = createType(
		c.package_->rootNamespace(),
		resolver,
		context,
		ast,
		genericType.path()
	);
	language::setOverloadResolutionInformation(type, genericParameters);
	type->name() = language::getGenericMangledName(genericType, genericParameters);

	instantiations.emplace_back(&genericType, genericParameters, type);
	confirmType(
		resolver,
		context,
		type,
		ast,
		genericType.path()
	);
	finalizeType(
		resolver,
		context,
		type,
		ast,
		genericType.path()
	);
	auto ep = ExpressionBuilder(file, resolver, context, [](const auto&) { return nullptr; });
	if (ast->attributeSequence())
		for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : ast->attributeSequence()->attribute())
			attachAttribute(type, attribute, resolver, context, ep);

	for (not_null<AttributeInstance*> attribute : type->attributes())
		executeAttachmentFunction(type, attribute, resolver, context);
	if (context.objectMap_.contains(type->name()))
		context.objectMap_[type->name()].push_back(type);
	type->setInstantiationData({
		&genericType,
		genericParameters
		});
	for (auto f : ast->classContentSequence()->functionDeclaration())
		if (f->attributeSequence())
		{
			auto methods = type->methods();
			auto method = std::ranges::find_if(methods, [&](auto const& e)
				{
					// todo: parameter match
					return
						e->name() == f->functionName()->getText() &&
						std::ranges::count_if(e->attributes(), [](auto const&) {return true; }) == 0;
				});
			for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : f->attributeSequence()->attribute())
				attachAttribute(*method, attribute, resolver, context, ep);

		}
	return type;
}