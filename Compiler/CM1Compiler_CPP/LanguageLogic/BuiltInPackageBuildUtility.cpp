#include "BuiltInPackageBuildUtility.hpp"
using namespace cMCompiler::dataStructures;
auto const bool__ = "bool";
auto const unsigned_size__ = "usize";

std::unique_ptr<PackageDatabase> buildPackage()
{
	using namespace std::string_literals;
	auto result = std::make_unique<PackageDatabase>("Cm1mLang"s);
	result->rootNamespace()->append<Type>(unsigned_size__)->setAccessibility(Accessibility::Public);
	result->rootNamespace()->append<Type>(bool__)->setAccessibility(Accessibility::Public);
	return result;
}

gsl::not_null<PackageDatabase*> cMCompiler::language::getDefaultPackage()
{
	static auto result = buildPackage();
	return result.get();
}

gsl::not_null<Type*> cMCompiler::language::getBool()
{
	using namespace std::string_literals;
	return getDefaultPackage()->rootNamespace()->get<Type>(bool__);
}

