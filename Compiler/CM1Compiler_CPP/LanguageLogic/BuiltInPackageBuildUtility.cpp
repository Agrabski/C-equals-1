#include "BuiltInPackageBuildUtility.hpp"
using namespace cMCompiler::dataStructures;

std::unique_ptr<PackageDatabase> buildPackage()
{
	using namespace std::string_literals;
	auto result = std::make_unique<PackageDatabase>("Cm1mLang"s);
	result->rootNamespace()->append<Type>("usize"s)->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<PackageDatabase*> cMCompiler::language::buildDefaultPackage()
{
	static auto result = buildPackage();
	return result.get();
}

