#include "BuiltInPackageBuildUtility.hpp"
#include "LiteralUtility.hpp"
#include "CompileTimeFunctions/FunctionLibrary.hpp"
#include "CompileTimeFunctions/Print.hpp"

using namespace cMCompiler::dataStructures;
auto const bool__ = "bool";
auto const unsigned_size__ = "usize";
auto const compiler_intrinsic_attribute__ = "compilerIntrinsic";
auto const set_type_size_function__ = "setTypeSize";
auto const compiler_namespace__ = "compiler";
auto const operator_attribute__ = "operator";
auto const compile_time_function_attribute__ = "compileTime";
auto const compile_time_only_function_attribute__ = "compileTimeOnly";
auto const compile_time_type_descriptor__ = "type";

static auto defaultPackage__ = std::make_unique<PackageDatabase>("Cm1mLang");


gsl::not_null<Type*> attachCompilerIntrinsic(gsl::not_null<Type*> type)
{
	static auto attribute =
		defaultPackage__->rootNamespace()->get<Namespace>(compiler_namespace__)->get<Attribute>(compiler_intrinsic_attribute__);
	type->appendAttribute(std::make_unique<AttributeInstance>(attribute, cMCompiler::language::buildIntegerValue(nullptr)));
	return type;
}

void buildCompilerLibrary(gsl::not_null<Namespace*> rootNamespace)
{
	auto ns = rootNamespace->append<Namespace>("compiler"s);
	auto attribute = ns->append<Attribute>(compiler_intrinsic_attribute__);
	attribute->setAccessibility(Accessibility::Public);
	attribute->addAttributeTarget(Target::Any);
	auto compileTimeType = attachCompilerIntrinsic(ns->append<Type>(compile_time_type_descriptor__));

	auto setTypeSize = ns->append<Function>(set_type_size_function__);
	setTypeSize->appendVariable("size", cMCompiler::language::getUsize());
	setTypeSize->appendVariable("type", compileTimeType);
}

void buildPackage()
{
	using namespace cMCompiler::language::compileTimeFunctions;
	using namespace cMCompiler::language;
	auto functionLibrary = FuntionLibrary::instance();
	using namespace std::string_literals;
	auto result = defaultPackage__.get();
	auto usize = result->rootNamespace()->append<Type>(unsigned_size__);
	usize->setAccessibility(Accessibility::Public);
	buildCompilerLibrary(result->rootNamespace());
	attachCompilerIntrinsic(usize);
	attachCompilerIntrinsic(result->rootNamespace()->append<Type>(bool__))->setAccessibility(Accessibility::Public);
	{
		auto op = result->rootNamespace()->append<Attribute>(operator_attribute__);
		op->addAttributeTarget(Target::Function);
		op->setAccessibility(Accessibility::Public);
	}
	{
		auto compileTime = result->rootNamespace()->append<Attribute>(compile_time_function_attribute__);
		compileTime->addAttributeTarget(Target::Function);
		compileTime->setAccessibility(Accessibility::Public);
	}
	{
		auto printFunction = result->rootNamespace()->append<Function>("print");
		printFunction->setAccessibility(Accessibility::Public);
		printFunction->appendAttribute(std::make_unique<AttributeInstance>(getCompileTimeAttribute(), buildIntegerValue(nullptr)));
		printFunction->appendVariable("value", getUsize());
		functionLibrary.addFunctionDefinition(printFunction, compileTimeFunctions::print);
	}
}

gsl::not_null<PackageDatabase*> cMCompiler::language::getDefaultPackage()
{
	static bool built = false;
	if (!built)
		buildPackage();
	return defaultPackage__.get();
}

gsl::not_null<Type*> cMCompiler::language::getBool()
{
	return defaultPackage__->rootNamespace()->get<Type>(bool__);
}

gsl::not_null<Type*> cMCompiler::language::getUsize()
{
	return defaultPackage__->rootNamespace()->get<Type>(unsigned_size__);
}

gsl::not_null<cMCompiler::dataStructures::Attribute*> cMCompiler::language::getCompileTimeAttribute()
{
	return defaultPackage__->rootNamespace()->get<Attribute>(compile_time_function_attribute__);
}

bool cMCompiler::language::isCompilerIntrinsic(dataStructures::AttributeTarget* element)
{
	auto intrinsic = defaultPackage__->rootNamespace()->get<Namespace>(compiler_namespace__)->get<Attribute>(compiler_intrinsic_attribute__);
	auto attributes = element->attributes();
	auto result = std::find_if(attributes.begin(), attributes.end(), [&](const auto a) {return a->basedOn() == intrinsic; });
	return result != attributes.end();
}

