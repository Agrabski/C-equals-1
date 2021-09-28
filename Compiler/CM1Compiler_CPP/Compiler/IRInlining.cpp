#include "IRInlining.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include "../LanguageLogic/runtime_values.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../LanguageLogic/IRPredicates.hpp"
#include "../DataStructures/execution/RuntimeVariableDescriptor.hpp"
#include "../Utilities/pointer_cast.hpp"
#include "ExpressionEvaluator.hpp"
#include "../DataStructures/execution/BooleanValue.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::language;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::dataStructures::execution;

void replaceInstructionWithBlock(ArrayValue& parentBlock, size_t instructionIndex, ArrayValue& blockToInline)
{
	parentBlock.insert(instructionIndex, blockToInline);
	parentBlock.erase(instructionIndex);
}

void inlineBlock(ArrayValue& block, std::map<not_null<Variable*>, runtime_value>& knownConstants)
{
	auto maxIndex = block.size();
	for (
		size_t index = 0;
		index < maxIndex;
		++index
		)
	{
		using cMCompiler::utilities::pointer_cast;
		not_null instruction = dereferenceAs<ObjectValue>(block.get(index).get());
		if (isOfType(instruction, getVariableDeclarationStatementDescriptor()))
		{
			auto const variable = dereferenceAs<RuntimeVariableDescriptor>(instruction->getMemberValue("_variable").get())->value();
			auto exp = pointer_cast<IRuntimeValue>(instruction->getMemberValue("_expression"));
			if (expressionIsCompileTimeExecutable(exp.get(), knownConstants))
				knownConstants[variable] = evaluate(exp, false, knownConstants);
		}

		if (isOfType(instruction, getIfDescriptor()))
		{
			auto exp = pointer_cast<IRuntimeValue>(instruction->getMemberValue("_expression"));
			if (expressionIsCompileTimeExecutable(exp.get(), knownConstants))
			{
				auto value = evaluate(exp, false, knownConstants);
				not_null<ArrayValue*> const blockToInline =
					dereferenceAs<BooleanValue>(value.get())->value() ?
					dereferenceAs<ArrayValue>(instruction->getMemberValue("_ifBranch").get())
					:
					dereferenceAs<ArrayValue>(instruction->getMemberValue("_elseBranch").get());
				replaceInstructionWithBlock(block, index, *blockToInline);
				index--;
				maxIndex = block.size();
			}
		}
		if (isOfType(instruction, getAssigmentStatementDescriptor()))
		{
			// todo: if references variable in lexpression, remove from constants
			// else, update constant value
		}

	}
}


void cMCompiler::compiler::inlineIr(not_null<Function*> function)
{
	auto knownConstants = std::map<not_null<dataStructures::Variable*>, language::runtime_value>();
	auto& code = function->code();
	inlineBlock(*code, knownConstants);
}
