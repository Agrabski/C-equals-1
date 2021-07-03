#include "GenericInstantiationUtility.hpp"
#include "../../ParserAdapter/ParserAdapter.hpp"
#include "../FunctionUtility.hpp"
#include "../../LanguageLogic/GenericUtility.hpp"
#include "../FunctionBodyBuilder.hpp"
#include "../Preprocessor.hpp"
#include "../AttributeUtility.hpp"
#include "../TypeUtility.hpp"

using namespace cMCompiler;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::compiler;

not_null<dataStructures::Function*> cMCompiler::compiler::instantiate
(
	dataStructures::Generic<Function>& function,
	std::vector<dataStructures::TypeReference> const& genericParameters,
	language::NameResolver& resolver,
	dataStructures::NameResolutionContext const& c,
	std::filesystem::path const& file
)
{
	static std::vector<GenericKey<Function>> instantiations;
	auto existing = std::find_if(begin(instantiations), end(instantiations), [&](const auto& e)
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
	not_null f = createFunction(dynamic_cast<Namespace*>(function.parent()), function.name());
	instantiations.emplace_back(&function, genericParameters, f);
	f->name() = language::getGenericMangledName(function, genericParameters);
	auto context = NameResolutionContext::merge(function.context(), c);
	confirmFunction(resolver, context, f, functionTree, file);
	finalizeFunction(resolver, context, f, functionTree, file);
	auto ep = ExpressionBuilder(file, resolver, context, [](const auto&) {return nullptr; });

	if (functionTree->attributeSequence())
		for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : functionTree->attributeSequence()->attribute())
			attachAttribute(f, attribute, resolver, context, ep);

	for (not_null<AttributeInstance*> attribute : f->attributes())
		executeAttachmentFunction(f, attribute, resolver, context);
	if (context.objectMap_.contains(function.name()))
		context.objectMap_[function.name()].push_back(f);
	return f;
}

not_null<dataStructures::Type*> cMCompiler::compiler::instantiate
(
	dataStructures::Generic<Type>& genericType,
	std::vector<dataStructures::TypeReference> const& genericParameters,
	language::NameResolver& resolver,
	dataStructures::NameResolutionContext const& c,
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
		dynamic_cast<Namespace*>(genericType.parent()),
		resolver,
		context,
		ast
	);
	type->name() = language::getGenericMangledName(genericType, genericParameters);

	instantiations.emplace_back(&genericType, genericParameters, type);
	confirmType(
		resolver,
		context,
		type,
		ast,
		file
	);
	finalizeType(
		resolver,
		context,
		type,
		ast,
		file
	);
	auto ep = ExpressionBuilder(file, resolver, context, [](const auto&) {return nullptr; });
	if (ast->attributeSequence())
		for (not_null<CMinusEqualsMinus1Revision0Parser::AttributeContext*> attribute : ast->attributeSequence()->attribute())
			attachAttribute(type, attribute, resolver, context, ep);

	for (not_null<AttributeInstance*> attribute : type->attributes())
		executeAttachmentFunction(type, attribute, resolver, context);
	if (context.objectMap_.contains(type->name()))
		context.objectMap_[type->name()].push_back(type);
	return type;
}