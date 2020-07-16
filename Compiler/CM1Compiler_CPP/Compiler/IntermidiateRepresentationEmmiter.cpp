#include "IntermidiateRepresentationEmmiter.hpp"
#include <gsl.h>
#include <sstream>
#include "../DataStructures/IntermidiateRepresentation/INameGetter.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using gsl::not_null;

PackageDatabase* findPackage(std::vector<not_null<PackageDatabase*>>& packages, Type* type)
{
	for (auto package : packages)
	{
		auto types = package->getAllTypes();
		auto found = std::find(types.begin(), types.end(), type);
		if (found != types.end())
			return package;
	}
	return nullptr;
}

void emmitFunctionParameter(std::ostream& s, Variable& v, std::vector<not_null<PackageDatabase*>>& dependencies)
{
	auto package = findPackage(dependencies, v.type());
	s << '{' << v.name() << "| ";
	if (package != nullptr)
		s << package->name();
	s << v.type()->qualifiedName() << "} ";
}

void emmitFunctionHeader(std::ostream& stream, Function& function, std::vector<not_null<PackageDatabase*>>& dependencies)
{
	stream << '{' << function.qualifiedName() << ", " << (int)function.accessibility() << ", parameters = [";
	for (auto parameter : function.parameters())
		emmitFunctionParameter(stream, *parameter, dependencies);
	stream << "]" << "} ";
}

void getAttributes(Namespace* ns, std::vector<gsl::not_null<Attribute*>>& result)
{
	for (auto child : ns->get<Namespace>())
		getAttributes(child, result);
	for (auto t : ns->get<Attribute>())
		result.push_back(t);
}


std::vector<gsl::not_null<Attribute*>> getAttributes(PackageDatabase& package)
{
	auto result = std::vector<gsl::not_null<Attribute*>>();
	getAttributes(package.rootNamespace(), result);
	return result;
}

void emmitAttribute(std::ostream& stream, AttributeInstance& attribute, cMCompiler::dataStructures::ir::INameGetter& nameGetter)
{
	stream << "{@attribute type = " << attribute.basedOn()->qualifiedName() << " instance = ";
	attribute.objectInstance()->emmit(stream, nameGetter); 
	stream << " }";
}

class NameLookuper : public cMCompiler::dataStructures::ir::INameGetter
{
	std::vector<std::pair<PackageDatabase*, std::vector<not_null<Type*>>>> types_;
	std::vector<std::pair<PackageDatabase*, std::vector<not_null<Function*>>>> functions_;
	std::vector<std::pair<PackageDatabase*, std::vector<not_null<Attribute*>>>> attributes_;
	std::string packageName(gsl::not_null<Type const*> t) const
	{
		for (auto& p : types_)
			if (std::find(p.second.begin(), p.second.end(), t) != p.second.end())
				return p.first->name();
		return "";
	}
	std::string packageName(gsl::not_null<Function const*> t) const
	{
		for (auto& p : functions_)
			if (std::find(p.second.begin(), p.second.end(), t) != p.second.end())
				return p.first->name();
		return "";
	}
public:
	NameLookuper(std::vector< not_null<PackageDatabase*>> packages)
	{
		for (auto package : packages)
		{
			types_.push_back({ package, package->getAllTypes() });
		}
	}

	std::string get(cMCompiler::dataStructures::Type const* t) const final
	{
		assert(t != nullptr);
		std::stringstream stream;
		stream << packageName(t);
		stream << t->qualifiedName();
		return stream.str();
	}
	std::string get(cMCompiler::dataStructures::Function const* t) const final
	{
		assert(t != nullptr);
		std::stringstream stream;
		stream << packageName(t);
		stream << t->qualifiedName();
		return stream.str();
	}
};

void IntermidiateRepresentationEmmiter::emmit(std::ostream& stream, PackageDatabase& package, std::vector<not_null<PackageDatabase*>> dependencies)
{
	stream << "package = [ name = \'" << package.name() << "\' dependencies = [";
	for (auto dependency : dependencies)
		stream << "\'" << dependency->name() << "\' ";
	stream << "]\r\n";

	auto nl = NameLookuper(dependencies);
	auto types = package.getAllTypes();
	auto functions = package.getAllFunctions();
	auto attributes = getAttributes(package);

	stream << "headers = [\r\n";
	{
		stream << "\ttypes = [";
		for (not_null<Type*> type : types)
			stream << '{' << type->qualifiedName() << ", " << (int)type->accessibility() << '}' << " ";
		stream << "]\r\n";

		stream << "\tfunctions = [";
		for (not_null<Function*> function : functions)
			emmitFunctionHeader(stream, *function, dependencies);
		stream << "]\r\n";

		stream << "\tattributes = [";
		for (not_null<Attribute*> attribute : getAttributes(package))
			stream << '{' << attribute->qualifiedName() << ", " << (int)attribute->accessibility() << '}' << " ";
		stream << "]\r\n";
	}
	stream << "]\r\n";

	stream << "types = [\r\n";
	{
		for (auto type : package.getAllTypes())
		{
			stream << "\t{\r\n";
			{
				stream << "\t\t'" << type->qualifiedName() << "'\r\n";
				stream << "\t\tattributes = \r\n\t\t[";
				for (not_null<AttributeInstance*> attribute : type->attributes())
				{
					stream << "\r\n\t\t\t";
					emmitAttribute(stream, *attribute, nl);
				}
				stream << "\r\n\t\t]\r\n";
				stream << "\t\tfields = \r\n\t\t[";
				for (auto field : type->fields())
				{
					stream << "\r\n\t\t\t";
					emmitField(stream, *field, nl);
				}
				stream << "\r\n\t\t]\r\n";

			}
			stream << "\t}\r\n";
		}
	}
	stream << "]\r\n";

	stream << "functions = [\r\n";
	{
		for (auto function : functions)
		{
			stream << "\t{\r\n";
			{
				stream << "\t\t'" << function->qualifiedName() << "'\r\n";

				stream << "\t\tattributes = \r\n\t\t[";
				for (not_null<AttributeInstance*> attribute : function->attributes())
				{
					stream << "\r\n\t\t\t";
					emmitAttribute(stream, *attribute, nl);
				}
				stream << "\r\n\t\t]\r\n";

				stream << "\t\tparametrs = \r\n\t\t[\r\n";
				for (auto parameter : function->parameters())
				{
					stream << "\t\t\t{";
					stream << parameter->name() << ", ";
					auto const* const package = findPackage(dependencies, parameter->type());
					if (package != nullptr)
						stream << package->name();
					stream << parameter->type()->qualifiedName() << ", ";
					stream << "attributes = [";
					for (auto attribute : parameter->attributes())
						emmitAttribute(stream, *attribute, nl);
					stream << "] }\r\n";
				}
				stream << "\t\t]\r\n";
				auto returnType = function->returnType();
				stream << "\t\treturn_type = ";
				if (returnType != nullptr)
				{
					auto const* const package = findPackage(dependencies, returnType);
					if (package != nullptr)
						stream << package->name();
					stream << returnType->qualifiedName();
				}
				else
					stream << "void";
				stream << "\r\n";

				stream << "\t\tcode = \r\n\t\t[\r\n";
				{
					for (auto& instruction : function->code())
					{
						instruction->emmit(stream, nl, 3);
						stream << "\r\n";
					}
				}
				stream << "\t\t]\r\n";
			}
			stream << "\t}\r\n";
		}
	}
	stream << "]\r\n";
}