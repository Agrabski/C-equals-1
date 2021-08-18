#include "pch.h"
#include "CppUnitTest.h"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"
#include "../LanguageLogic/OverloadResolutionUtility.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cMCompiler::language;

namespace LanguageLogicTests
{
	TEST_CLASS(BuiltInPackageTests)
	{
	public:

		TEST_METHOD(String_LengthIsCompileTimeExecutable)
		{
			getDefaultPackage();
			auto string = getString();
			auto methods = string->methods();
			auto remove = std::ranges::remove_if(methods, [&](auto const e) { return e->name() != "length"; });
			if (remove.begin() != remove.end())
				methods.erase(remove.begin(), remove.end());
			auto params = std::vector< Parameter>();
			params.push_back({ {string, 1}, {} });
			auto compile = resolveOverload(methods, params, true, false);
			auto run = resolveOverload(methods, params, false, true);
			Assert::IsNotNull(compile);
			Assert::IsNotNull(run);

		}
	};
}
