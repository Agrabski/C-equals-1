#pragma once
#include <string>
#include <memory>
#include "../Utilities/pointer_cast.hpp"
#include "../antlr_runtime/src/antlr4-runtime.h"
#include "../Parser/CMinusEqualsMinus1Revision0Parser.h"
#include "../Parser/CMinusEqualsMinus1Revision0BaseVisitor.h"
#include "Type.hpp"


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
		std::string name_;
		not_null<Type*> value_;
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
			not_null<INamedObject*> parent) :
			parameterNames_(std::move(parameterNames)), parseTree_(std::move(parseTree)),
			INamedObject(name, parent)
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
					auto name = ctx->Identifier()->getText();
					if (std::find(parameterNames_.begin(), parameterNames_.end(), name) != parameterNames_.end())
					{
						auto type = std::find_if(parameters_.begin(), parameters_.end(), [&](const auto& e) {return e.name_ == name; });
						ctx->Identifier()->getSymbol()->getText() = type->value_->name();
					}
				}
			};
			Visitor(parameterNames_, parameters).visit(not_null(result.get()));
			return utilities::pointer_cast<TreeType>(std::move(result));
		}

		std::vector<validation::ValidationError> validateContent() const final
		{
			return {};
		}

		std::vector<INamedObject*> children() final
		{
			return {};
		}

	private:
		std::vector<std::string> parameterNames_;
		std::unique_ptr<TreeType> parseTree_;

	};
}