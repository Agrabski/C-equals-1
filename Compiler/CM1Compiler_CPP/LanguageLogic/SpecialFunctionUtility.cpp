#include "SpecialFunctionUtility.hpp"
#include "BuiltInPackageBuildUtility.hpp"
using namespace std::string_literals;
auto const attachment_function_name__ = "attach"s;

cMCompiler::dataStructures::Function* cMCompiler::language::getFinalizer(std::vector<gsl::not_null<dataStructures::Function*>> methods)
{
	auto result = std::find_if(methods.begin(), methods.end(), [](auto const& e) {return e->name() == "finalize"; });
	if (result != methods.end())
		return *result;
	return nullptr;
}

std::vector<gsl::not_null<cMCompiler::dataStructures::Function*>> cMCompiler::language::getConstructors(std::vector<gsl::not_null<dataStructures::Function*>> methods)
{
	auto result = std::vector<gsl::not_null<cMCompiler::dataStructures::Function*>>();
	for (auto f : methods)
		if (isConstructor(f))
			result.push_back(f);
	return result;
}

bool cMCompiler::language::isConstructor(dataStructures::Function* f)
{
	if (f == nullptr)
		return false;
	return f->name() == "construct";
}

gsl::not_null<cMCompiler::dataStructures::Function*> cMCompiler::language::getAtachmentFunction(
	dataStructures::AttributeTarget* target,
	dataStructures::AttributeInstance* attribute)
{
	static std::map<dataStructures::Target, dataStructures::Type*> targetMap =
	{
		{ dataStructures::Target::Class | dataStructures::Target::Interface | dataStructures::Target::Struct ,getTypeDescriptor()},
		{dataStructures::Target::Function, getFunctionDescriptor()},
		{dataStructures::Target::Variable, nullptr}
	};
	auto allowedTarget = target->allowedTarget();
	dataStructures::Type* descriptor = nullptr;
	for (auto const& kv : targetMap)
		if ((kv.first & allowedTarget) != dataStructures::Target::None)
		{
			descriptor = kv.second;
			break;
		}
	for (auto f : attribute->basedOn()->methods())
		if (f->name() == attachment_function_name__ && f->parameters().size() == 2 && f->parameters().back()->type().type == descriptor)
			return f;
	std::terminate();
}
