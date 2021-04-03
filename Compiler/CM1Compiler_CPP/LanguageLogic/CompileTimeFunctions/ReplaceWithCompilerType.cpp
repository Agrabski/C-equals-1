#include "ReplaceWithCompilerType.hpp"
#include "../../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../SpecialTypes/SpecialTypeLibrary.hpp"

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>
cMCompiler::language::compileTimeFunctions::replaceWithCompilerType
(
	std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
	std::map<std::string, not_null<dataStructures::Type*>> genericParameters
)
{
	auto& name = valueMap["name"];
	auto type = dynamic_cast<dataStructures::execution::RuntimeTypeDescriptor*>(valueMap["type"].get());
	specialTypes::SpecialTypeLibrary::instance().append(type->value().type, name->toString());
	return nullptr;
}
