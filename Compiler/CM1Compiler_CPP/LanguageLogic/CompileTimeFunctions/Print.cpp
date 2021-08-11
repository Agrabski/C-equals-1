#include "Print.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include <iostream>

using namespace cMCompiler::dataStructures::execution;

std::unique_ptr<IRuntimeValue> cMCompiler::language::compileTimeFunctions::print(
	std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap,
	std::map<std::string, gsl::not_null<dataStructures::Type*>> genericParameters
)
{
	if (valueMap.size() != 1)
		throw std::exception(); //todo: better exception
	auto v = valueMap["value"].get();
	while (dereferenceOnce(v) != nullptr && dereferenceOnce(v) != v)
	{
		std::cout << "*";
		v = dereferenceOnce(v);
	}
	std::cout << v->toString() << std::endl;
	return nullptr;
}
