#include "IRUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler::dataStructures;

gsl::not_null<Type*> cMCompiler::language::buidStatementDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto interface = irNs->append<Type>("IStatement"s);
	interface->append<Function>("pointerToSource")->setReturnType(getPointerToSource());
	interface->append<Function>("parentStatement")->setReturnType(interface);
	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildIfDescriptor(gsl::not_null<Namespace*> irNs, gsl::not_null<Type*> baseStatement)
{
	auto interface = irNs->append<Type>("IIfStatement"s);
	interface->appendInterface(baseStatement);

	auto impl = irNs->append<Type>("ifStatement");
	impl->appendInterface(interface);

	return interface;
}

gsl::not_null<Type*> cMCompiler::language::buildVariableDescriptor(gsl::not_null<Namespace*> irNs)
{
	auto result = irNs->append<Type>("IVariableDescriptor"s);
	result->append<Function>("name"s)->setReturnType(getString())->setAccessibility(Accessibility::Public);
	result->append<Function>("type"s)->setReturnType(getTypeDescriptor())->setAccessibility(Accessibility::Public);
	return result;
}

void cMCompiler::language::buildIrNamespace(gsl::not_null<dataStructures::Namespace*> compilerNs)
{
	auto ns = compilerNs->append<Namespace>("ir"s);
	auto statement = buidStatementDescriptor(ns);
	buildIfDescriptor(ns, statement);
}
