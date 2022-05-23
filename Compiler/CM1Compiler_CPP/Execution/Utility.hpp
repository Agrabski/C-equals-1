#pragma once

#define MAP_TO_TYPE_DESCRIPTOR(cppType, cm1Type, referenceCount)namespace cMCompiler::execution\
{\
	export template<>\
	::cMCompiler::dataStructures::TypeReference getTypeFor<cppType>()\
	{\
		return { cm1Type(), referenceCount };\
	}\
}\
