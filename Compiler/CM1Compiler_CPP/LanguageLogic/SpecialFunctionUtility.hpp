#pragma once
#include "../DataStructures/Function.hpp"
#include "../DataStructures/Type.hpp"
namespace cMCompiler::language
{
	dataStructures::Function* getFinalizer(std::vector<gsl::not_null<dataStructures::Function*>> methods);
	std::vector<gsl::not_null<cMCompiler::dataStructures::Function*>> getConstructors(std::vector<gsl::not_null<dataStructures::Function*>> methods);
	bool isConstructor(dataStructures::Function const* f);
	gsl::not_null<cMCompiler::dataStructures::Function*> getAtachmentFunction
	(
		dataStructures::AttributeTarget* target,
		dataStructures::AttributeInstance* attribute
	);

}