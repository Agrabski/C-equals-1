#include "pch.h"
#include "CppUnitTest.h"
#include "CompilationUnitDataBaseBuilderTestingUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CompilerTests
{
	TEST_CLASS(CompilerTests)
	{
	public:
		
		TEST_METHOD(UnaliasedImportFunctionReturnType)
		{
			auto program = std::stringstream(R"___(
import {usize} from {cm1mLang}
fn func() -> usize {}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func")->returnType().type);

		}

		TEST_METHOD(UnaliasedImportFieldType)
		{
			auto program = std::stringstream(R"___(
import {usize} from {cm1mLang}
class T 
{
	public _field: usize;
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Type>("T")->fields()[0]->type().type);

		}

		TEST_METHOD(UnaliasedImportGenericFunctionReturnType)
		{
			auto program = std::stringstream(R"___(
import {usize} from {cm1mLang}
fn func<T>() -> T {}
fn func1() 
{
	let x = func<usize>();
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func1")->variables()[0]->type().type);

		}

		TEST_METHOD(UnaliasedImportGenericFieldType)
		{
			auto program = std::stringstream(R"___(
import {usize} from {cm1mLang}
class C<T>
{
	public _field: T;
	public fn construct() {}
}

fn func1() 
{
	let x = C<usize>();
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func1")->variables()[0]->type().type->fields()[0]->type().type);

		}

		TEST_METHOD(AliasedImportFunctionReturnType)
		{
			auto program = std::stringstream(R"___(
import {usize: int} from {cm1mLang}
fn func() -> int {}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func")->returnType().type);

		}

		TEST_METHOD(AliasedImportFieldType)
		{
			auto program = std::stringstream(R"___(
import {usize: int} from {cm1mLang}
class T 
{
	public _field: int;
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Type>("T")->fields()[0]->type().type);

		}

		TEST_METHOD(AliasedImportGenericFunctionReturnType)
		{
			auto program = std::stringstream(R"___(
import {usize: int} from {cm1mLang}
fn func<T>() -> T {}
fn func1() 
{
	let x = func<int>();
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func1")->variables()[0]->type().type);

		}

		TEST_METHOD(AliasedImportGenericFieldType)
		{
			auto program = std::stringstream(R"___(
import {usize: int} from {cm1mLang}
class C<T>
{
	public _field: T;
	public fn construct() {}
}

fn func1() 
{
	let x = C<int>();
}
)___");
			auto package = compile("file", program);
			auto usize = cMCompiler::language::getUsize();
			Assert::IsTrue(usize.get() == package->rootNamespace()->get<cMCompiler::dataStructures::Function>("func1")->variables()[0]->type().type->fields()[0]->type().type);

		}
	};
}
