#include "TypeCohersionUtility.hpp"

bool cMCompiler::language::canBeAssignedTo(gsl::not_null<dataStructures::Type*> valueType, gsl::not_null<dataStructures::Type*> sinkType)
{
	if (valueType == sinkType)
		return true;
	auto interfaces = valueType->interfaces();
	return interfaces.end() != std::find_if(interfaces.begin(), interfaces.end(), [&](const auto e) {return canBeAssignedTo(e, sinkType); });

}
