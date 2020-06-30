#include "ReplaceWithCompilerType.hpp"
#include "../../DataStructures/execution/RuntimeTypeDescriptor.hpp"
#include "../SpecialTypes/SpecialTypeLibrary.hpp"

std::unique_ptr<cMCompiler::dataStructures::execution::IRuntimeValue>
cMCompiler::language::compileTimeFunctions::replaceWithCompilerType(std::map<std::string, dataStructures::execution::IRuntimeValue*> valueMap)
{
	auto name = valueMap["name"];
	auto type = dynamic_cast<dataStructures::execution::RuntimeTypeDescriptor*>(valueMap["function"]);
	specialTypes::SpecialTypeLibrary::instance().append(type->value(), name->toString());
	return nullptr;
}
