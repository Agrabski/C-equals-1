#pragma once
#include <string>
#include <memory>
#include "Type.hpp"
#include "NameResolutionContext.hpp"
#include "../Utilities/pointer_cast.hpp"
#include "../Utilities/algorithm.hpp"
#include "../antlr_runtime/src/antlr4-runtime.h"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../ParserAdapter/ParserAdapter.hpp"


namespace cMCompiler::dataStructures
{
	template<typename T>
	struct getParserContextType {};

	template<>
	struct getParserContextType<Type>
	{
		using T = CMinusEqualsMinus1Revision0Parser::TypeDeclarationContext;
	};

	template<>
	struct getParserContextType<Function>
	{
		using T = CMinusEqualsMinus1Revision0Parser::FunctionDeclarationContext;
	};


	template<typename TargetType>
	class Generic : public INamedObject
	{
	public:
		using TreeType = typename antlr4::tree::ParseTree;
		Generic(
			std::vector<std::string>&& parameterNames,
			std::function<not_null<TargetType*>(std::vector<TypeReference> const&)> customFill,
			std::string name,
			not_null<INamedObject*> parent,
			NameResolutionContext const& context) :
			parameterNames_(std::move(parameterNames)), customFill_(customFill),
			INamedObject(name, parent), context_(context)
		{
		}

		Generic(
			std::vector<std::string>&& parameterNames,
			std::unique_ptr<TreeType>&& parseTree,
			std::string name,
			not_null<INamedObject*> parent,
			NameResolutionContext const& context) :
			parameterNames_(std::move(parameterNames)), parseTree_(std::move(parseTree)),
			INamedObject(name, parent), context_(context)
		{
		}

		bool isSpecial() const noexcept { return parseTree_ == nullptr; }

		not_null<TargetType*> fillSpecial(std::vector<TypeReference> const& parameters)
		{
			return customFill_(parameters);
		}

		std::unique_ptr<TreeType> fillGeneric(std::vector<TypeReference> const& parameters)
		{
			auto result = parseTree_->clone(nullptr);
			struct Visitor : public CMinusEqualsMinus1Revision0BaseVisitor
			{
				std::vector<std::string>& parameterNames_;
				std::vector<TypeReference> const& parameters_;
				Generic& parent_;
				Visitor(std::vector<std::string>& parameterNames, std::vector<TypeReference> const& parameters, Generic& parent) noexcept :
					parameterNames_(parameterNames), parameters_(parameters), parent_(parent) {}

				antlrcpp::Any visitTypeSpecifier(CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* ctx) final
				{
					auto name = ctx->identifier()->getText();
					auto paramName = std::find(parameterNames_.begin(), parameterNames_.end(), name);
					if (paramName != parameterNames_.end())
					{
						auto type = parameters_[std::distance(parameterNames_.begin(), paramName)];
						auto stream = std::stringstream();
						stream << parent_.getAliasedType(type, ctx);
						auto identifier = Parser::ParserAdapter().parseType(stream);

						*std::find_if(ctx->parent->children.begin(), ctx->parent->children.end(), [ctx](const auto& e) -> bool {return e.get() == ctx; }) = std::move(identifier);
					}
					visitChildren(ctx);
					return {};
				}

				antlrcpp::Any visitGenericSpecifier(CMinusEqualsMinus1Revision0Parser::GenericSpecifierContext* ctx) final
				{
					ctx->parent->children.erase(utilities::find_if(ctx->parent->children, [=](const auto& e)
						{
							return e.get() == ctx;
						}));
					return {};
				}
			};
			Visitor(parameterNames_, parameters, *this).visit(not_null(result.get()));
			return std::unique_ptr<TreeType>(result.release());
		}

		std::vector<validation::ValidationError> validateContent() const final
		{
			return {};
		}

		std::vector<INamedObject*> children() noexcept final
		{
			return {};
		}

		NameResolutionContext& context() { return context_; }
		execution::json emmit(ir::INameGetter const& nameLookupFunction, ISerializationManager& manager) const final
		{
			return {};
			// todo: do
		}

	private:
		std::string buildModifier(CMinusEqualsMinus1Revision0Parser::ModifierContext* ctx, size_t refCount)
		{
			if (ctx->arraySpecifier())
				return "[" + buildModifier(ctx->arraySpecifier()->modifier(), refCount) + "]" + std::string(ctx->ref().size(), '*');
			else
				return std::string(refCount + ctx->ref().size(), '*');
		}

		std::string getAliasedType(TypeReference const& type, not_null<CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext*> ctx)
		{
			for (auto const& bucket : context_.objectMap_)
				if (std::find(bucket.second.begin(), bucket.second.end(), type.type) != bucket.second.end())
					return bucket.first + buildModifier(ctx->modifier(), type.referenceCount);
			// name comes from the same namespace
			return type.typeName() + buildModifier(ctx->modifier(), type.referenceCount);
		}
		std::vector<std::string> parameterNames_;
		std::unique_ptr<TreeType> parseTree_;
		NameResolutionContext context_;
		std::function<not_null<TargetType*>(std::vector<TypeReference> const&)> customFill_;


		// Inherited via INamedObject

	};
}