#pragma once
#include "pch.h"
#include <gsl/gsl>
#include "CppUnitTest.h"
#include "CompilationUnitDataBaseBuilderTestingUtility.hpp"
#include "../Compiler/FunctionUtility.hpp"
#include "../Compiler/FunctionExecutionUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../DataStructures/execution/IntegerValue.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CompilerTests
{
	using namespace cMCompiler::compiler;
	using namespace cMCompiler::dataStructures;
	TEST_CLASS(FunctionBuildingTests)
	{
	public:

		gsl::not_null<Function*> compileFunction(const char* const text, std::string const& fName)
		{
			// todo: awful hack
			static std::unique_ptr<Namespace> ns = std::make_unique<Namespace>("test", nullptr, (PackageDatabase*)123);
			auto stream = std::stringstream(text);
			auto ast = cMCompiler::Parser::ParserAdapter().parseFunction(stream);
			auto context = NameResolutionContext(cMCompiler::language::getDefaultPackage());
			auto resolver = cMCompiler::language::NameResolver({});
			context.objectMap_["usize"].push_back(cMCompiler::language::getUsize());
			context.objectMap_["null"].push_back(cMCompiler::language::getNull());
			context.namespaceStack_ = { ns.get() };
			createFunction(not_null(ns.get()), not_null(ast.get()), context, std::filesystem::path(""));
			confirmFunction(resolver, context, ast.get(), "");
			finalizeFunction(resolver, context, ast.get(), "");
			return ns->get<Function>(fName);

		}

		TEST_METHOD(FunctionWithWhileStatement)
		{
			auto function = compileFunction(R"___(
public fn count_to_five() -> usize
{
	let result = 0;
	while(result < 5)
	{
		result = result + 1;
	}
	return result;
})___", "count_to_five");

			auto result = execute(function, {});
			Assert::AreEqual(cMCompiler::language::convertToIntegral<execution::usize>(*result.get()), execution::usize{ 5 });

		}

		TEST_METHOD(FunctionWithComparisonToNull)
		{
			auto function = compileFunction(R"___(
public fn check_for_null() -> usize
{
	let result = null<usize>();
	if(result != null<usize>())
		return 1;
	return 0;
})___", "check_for_null");

			auto result = execute(function, {});
			Assert::AreEqual(cMCompiler::language::convertToIntegral<execution::usize>(*result.get()), execution::usize{ 0 });

		}
	};
}

