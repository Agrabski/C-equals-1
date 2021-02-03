#pragma once
namespace cMCompiler::dataStructures::execution
{
	enum class InstructionCode : size_t
	{
		ERROR_CODE = 0,
		ASSIGMENT = 1,
		VARIABLE_DECLARATION = 2,
		FUNCTION_CALL = 3,
		SCOPE_TERMINATION = 4,
		RETURN = 5
	};
}