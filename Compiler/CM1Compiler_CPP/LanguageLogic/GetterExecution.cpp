#include "GetterExecution.hpp"
cMCompiler::language::runtime_value 
cMCompiler::language::executeBasicGetter(
	std::unique_ptr<dataStructures::execution::IRuntimeValue>& object, 
	std::string const& name)
{
	std::unique_ptr<dataStructures::execution::IRuntimeValue> self;
	if (dynamic_cast<dataStructures::execution::ReferenceValue*>(object.get()) == nullptr)
		self = dataStructures::execution::ReferenceValue::make(&object, object->type());
	else
		self = object->copy();
	assert(self->type().referenceCount == 1);
	std::vector<runtime_value> params;
	params.push_back(std::move(self));
	auto methods = dereference(object.get())->type().type->methods();
	auto function = std::find_if(
		methods.begin(),
		methods.end(),
		[&](auto const& e) {return e->name() == name; });
	return compiler::execute(*function, std::move(params));
}
