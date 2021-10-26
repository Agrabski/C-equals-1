#include "FunctionExecutionUtility.hpp"
#include "ExpressionEvaluator.hpp"
#include "StatementEvaluator.hpp"
#include "../DataStructures/SourcePointer.hpp"
#include "../DataStructures/RuntimeException.hpp"
#include "../LanguageLogic/CompileTimeFunctions/FunctionLibrary.hpp"
#include "../Utilities/algorithm.hpp"
#include "../LanguageLogic/IRUtility.hpp"
#include "../Utilities/range.hpp"
#include "../LanguageLogic/TypeCoercionUtility.hpp"
#include "../LanguageLogic/RuntimeTypesConversionUtility.hpp"
#include <Windows.h>
#include <excpt.h>
#include <winnt.h>
using namespace cMCompiler::dataStructures::execution;
using namespace cMCompiler::dataStructures::execution;

auto FilterFunction(long long x)
{
	if (x == EXCEPTION_ACCESS_VIOLATION)
		return EXCEPTION_EXECUTE_HANDLER;
	return EXCEPTION_CONTINUE_SEARCH;
}

struct exceptionData
{

};

cMCompiler::language::runtime_value runWithExceptionHandling(
	std::function<cMCompiler::language::runtime_value()>const& function,
	std::function<void(exceptionData const&)> const& exceptionThrower)
{
	cMCompiler::language::runtime_value ret;
	//todo: jesus fucking christ, windows why are you doing this to me?
	[&]
	{
		__try
		{
			[&]() {
				ret = function();
			}();
		}
		__except (FilterFunction(GetExceptionCode()))
		{
			exceptionThrower({});
		}
	}();
	return ret;
}

std::unique_ptr<IRuntimeValue> cMCompiler::compiler::execute(
	gsl::not_null<dataStructures::Function*> functionDefinition,
	std::vector<std::unique_ptr<dataStructures::execution::IRuntimeValue>>&& valueMap)
{
	dataStructures::SourcePointer lastInstruction;
	std::unique_ptr<IRuntimeValue> returnValue = nullptr;

	//for (auto const i : utilities::range(valueMap.size()))
	//{
	//	auto const& valueType = valueMap[i]->type();
	//	auto parameterType = functionDefinition->parameters()[i]->type();
	//	assert(language::coerce(valueType, parameterType));
	//}


	auto f = language::compileTimeFunctions::FuntionLibrary::instance().getFunction(functionDefinition);
	if (f)
	{
		auto values = std::map<std::string, std::unique_ptr<dataStructures::execution::IRuntimeValue>>();
		int i = 0;
		for (not_null const var : functionDefinition->parameters())
			values[var->name()] = std::move(valueMap[i++]);
		return (*f)(std::move(values), std::map<std::string, not_null<dataStructures::Type*>>());
	}
	
	if (functionDefinition->code() == nullptr)
	{
		auto& self = valueMap.front();
		auto s = language::dereference(self.get());
		auto methods = s->type().type->methods();
		auto method = std::find_if(methods.begin(), methods.end(), [=](auto& e)
			{
				//todo: non exhaustive predicate
				return e->name() == functionDefinition->name() && e->parameters().size() == functionDefinition->parameters().size();
			});
		if (method != end(methods))
			functionDefinition = *method;
	}

	auto function = [&]()
	{
		std::map<std::string, std::unique_ptr<IRuntimeValue>> locals;
		auto& instructions = functionDefinition->code();
		auto const variableLookup = [functionDefinition, &locals, &valueMap](auto const& name) -> std::unique_ptr<IRuntimeValue>&
		{
			auto local = locals.find(name);
			if (local != locals.end())
				return local->second;
			auto parameters = functionDefinition->parameters();
			auto parameter = utilities::find_if(parameters, [&](auto const& e) noexcept {return e->name() == name; });
			if (parameter != parameters.end())
				return valueMap[parameter - begin(parameters)];
		};
		auto eval = ExpressionEvaluator(variableLookup);
		auto statementEvaluator = StatementEvaluator(*functionDefinition, eval, locals);
		// todo: do finalisation
		for (auto& instruction : *instructions)
		{
			lastInstruction = language::getSourcePointerFromInstruction(instruction);
			if (auto result = statementEvaluator.evaluate(instruction); result)
				return std::move(*result);
		}

		return std::move(returnValue);
	};

	auto thrower = [&](auto const&)
	{
		auto exception = dataStructures::RuntimeException();
		exception.push({ functionDefinition, lastInstruction });
		throw exception;
	};
	try
	{
		return runWithExceptionHandling(function, thrower);
	}
	catch (dataStructures::RuntimeException& e)
	{
		e.push({ functionDefinition, lastInstruction });
		throw;
	}
	catch (std::exception const& e)
	{
		auto exception = dataStructures::RuntimeException(e.what());
		exception.push({ functionDefinition, lastInstruction });
		throw exception;

	}

}
