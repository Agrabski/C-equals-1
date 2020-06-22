#pragma once
#include <optional>
#include "CompileTimeFunction.hpp"
#include "../../DataStructures/Function.hpp"

namespace cMCompiler::language::compileTimeFunctions
{
	class FuntionLibrary
	{
		FuntionLibrary() = default;
		std::map<dataStructures::Function*, compileTimeFunction> functions_;
	public:
		static FuntionLibrary& instance();
		std::optional<compileTimeFunction> getFunction(gsl::not_null<dataStructures::Function*> functionDefinition);
		void addFunctionDefinition(gsl::not_null<dataStructures::Function*> definition, compileTimeFunction function);
	};
}