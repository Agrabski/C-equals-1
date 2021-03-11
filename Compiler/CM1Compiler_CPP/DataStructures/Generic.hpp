#pragma once
#include <string>
#include <memory>
#include "../Utilities/pointer_cast.hpp"
#include "../Utilities/algorithm.hpp"
#include "../antlr_runtime/src/antlr4-runtime.h"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "../ParserAdapter/ParserAdapter.hpp"
#include "Type.hpp"
#include "NameResolutionContext.hpp"


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

	struct GenericParameter
	{
		not_null<Type*> value_;
		unsigned char referenceLevel_;
	};

	template<typename TargetType>
	class Generic : public INamedObject
	{
	public:
		using TreeType = typename antlr4::tree::ParseTree;
		Generic(
			std::vector<std::string>&& parameterNames,
			std::unique_ptr<TreeType>&& parseTree,
			std::string name,
			not_null<INamedObject*> parent,
			NameResolutionContext const& context) :
			parameterNames_(std::move(parameterNames)), parseTree_(std::move(parseTree)),
			INamedObject(name, parent), context_(context)
		{}

		std::unique_ptr<TreeType> fillGeneric(std::vector<GenericParameter> const& parameters)
		{
			auto result = parseTree_->clone(nullptr);
			struct Visitor : public CMinusEqualsMinus1Revision0BaseVisitor
			{
				std::vector<std::string>& parameterNames_;
				std::vector<GenericParameter> const& parameters_;
				Visitor(std::vector<std::string>& parameterNames, std::vector<GenericParameter> const& parameters) :
					parameterNames_(parameterNames), parameters_(parameters) {}

				antlrcpp::Any visitTypeSpecifier(CMinusEqualsMinus1Revision0Parser::TypeSpecifierContext* ctx) final
				{
					auto name = ctx->identifier()->getText();
					auto paramName = std::find(parameterNames_.begin(), parameterNames_.end(), name);
					if (paramName != parameterNames_.end())
					{
						auto type = parameters_[std::distance(parameterNames_.begin(), paramName)];
						auto refLevel = gsl::narrow<unsigned char>(ctx->ref().size() + type.referenceLevel_);
						auto stream = std::stringstream(type.value_->name() + std::string(refLevel, '*'));
						auto identifier = Parser::ParserAdapter().parseType(stream);

						*std::find_if(ctx->parent->children.begin(), ctx->parent->children.end(), [ctx](const auto& e) -> bool {return e.get() == ctx; }) = std::move(identifier);
					}
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
			Visitor(parameterNames_, parameters).visit(not_null(result.get()));
			return std::unique_ptr<TreeType>(result.release());
		}

		std::vector<validation::ValidationError> validateContent() const final
		{
			return {};
		}

		std::vector<INamedObject*> children() final
		{
			return {};
		}

		NameResolutionContext& context() { return context_; }

	private:
		std::vector<std::string> parameterNames_;
		std::unique_ptr<TreeType> parseTree_;
		NameResolutionContext context_;

	};
}