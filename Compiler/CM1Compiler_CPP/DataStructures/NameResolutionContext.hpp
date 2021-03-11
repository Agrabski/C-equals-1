#pragma once
#include <map>
#include <vector>
#include <gsl.h>
#include <string>

namespace cMCompiler::dataStructures
{
	class INamedObject;
	class PackageDatabase;
	class Namespace;
	struct NameResolutionContext
	{
		std::map<std::string, std::vector<INamedObject*>> objectMap_;
		std::map<std::string, dataStructures::Namespace*> unconfirmedNames_;
		std::vector<gsl::not_null<dataStructures::Namespace*>> namespaceStack_;
		gsl::not_null<dataStructures::PackageDatabase*> package_;
		NameResolutionContext(gsl::not_null<dataStructures::PackageDatabase*> package) :package_(package) {}
		static NameResolutionContext merge(NameResolutionContext const& a, NameResolutionContext const& b);
	};
}