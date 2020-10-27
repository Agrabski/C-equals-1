#include "IntermidiateRepresentationEmmiter.hpp"
#include <gsl.h>
#include <sstream>
#include "../DataStructures/IntermidiateRepresentation/INameGetter.hpp"

using namespace cMCompiler::compiler;
using namespace cMCompiler::dataStructures;
using gsl::not_null;


void emmitAttribute(std::ostream& stream, AttributeInstance& attribute, cMCompiler::dataStructures::ir::INameGetter& nameGetter)
{
	stream << "{@attribute type = " << attribute.basedOn()->qualifiedName() << " instance = ";
	attribute.objectInstance()->emmit(stream, nameGetter);
	stream << " }";
}

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
	auto const* const package = findPackage(dependencies, v.type());
	s << '{' << v.name() << "| ";
	if (package != nullptr)
		s << package->name();
	s << v.type()->qualifiedName() << "} ";
}

void emmitField(std::ostream& s, Field& v, cMCompiler::dataStructures::ir::INameGetter& ng)
{
	s << '{' << v.name() << "| ";
	s << ng.get(v.type()) << " attributes = [ ";
	for (auto a : v.attributes())
		emmitAttribute(s, *a, ng);
	s << "] }";
}

void emmitFunctionHeader(std::ostream& stream, Function& function, std::vector<not_null<PackageDatabase*>>& dependencies)
{
	stream << '{' << function.qualifiedName() << ", " << (int)function.accessibility() << ", parameters = [";
	for (not_null parameter : function.parameters())
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

void indent(std::ostream& stream, int n)
{
	while (n-- > 0)
		stream << '\t';
}
void emmitFunctions(
	std::vector<gsl::not_null<Function*>> const& functions,
	std::ostream& stream, cMCompiler::dataStructures::ir::INameGetter& ng,
	int indentationLevel);

void emmitType(
	gsl::not_null<Type*> type,
	std::ostream& stream, cMCompiler::dataStructures::ir::INameGetter& ng,
	int indentationLevel)
{
	indent(stream, indentationLevel);
	stream << "{\r\n";
	{
		indent(stream, indentationLevel + 1);
		stream << "'" << type->qualifiedName() << "'\r\n";
		indent(stream, indentationLevel + 1);
		stream << "attributes = \r\n";
		indent(stream, indentationLevel + 1);
		stream << "[";
		for (not_null<AttributeInstance*> attribute : type->attributes())
		{
			stream << "\r\n";
			indent(stream, indentationLevel + 2);
			emmitAttribute(stream, *attribute, ng);
		}
		stream << "\r\n";
		indent(stream, indentationLevel + 1);
		stream << "]\r\n";
		indent(stream, indentationLevel + 1);
		stream << "fields = \r\n";
		indent(stream, indentationLevel + 1);
		stream << "[";
		for (auto field : type->fields())
		{
			stream << "\r\n";
			indent(stream, indentationLevel + 2);
			emmitField(stream, *field, ng);
		}
		stream << "\r\n";
		indent(stream, indentationLevel + 1);
		stream << "]\r\n";
		emmitFunctions(type->methods(), stream, ng, indentationLevel + 1);

	}
	indent(stream, indentationLevel);
	stream << "]\r\n";
}

void emmitFunctions(
	std::vector<gsl::not_null<Function*>> const& functions,
	std::ostream& stream, cMCompiler::dataStructures::ir::INameGetter& ng,
	int indentationLevel)
{
	indent(stream, indentationLevel);
	stream << "functions = \r\n";
	indent(stream, indentationLevel);
	stream << "[\r\n";
	{
		for (auto function : functions)
		{
			indent(stream, indentationLevel + 1);
			stream << "{\r\n";
			{
				indent(stream, indentationLevel + 2);
				stream << "'" << function->qualifiedName() << "'\r\n";

				indent(stream, indentationLevel + 2);
				stream << "attributes = \r\n";
				indent(stream, indentationLevel + 2);
				stream << '[';
				for (not_null<AttributeInstance*> attribute : function->attributes())
				{
					stream << "\r\n";
					indent(stream, indentationLevel + 3);
					emmitAttribute(stream, *attribute, ng);
				}
				stream << "\r\n";
				indent(stream, indentationLevel + 2);
				stream << "]\r\n";

				indent(stream, indentationLevel + 2);
				stream << "parametrs = \r\n";
				indent(stream, indentationLevel + 2);
				stream << "[\r\n";
				for (auto parameter : function->parameters())
				{
					indent(stream, indentationLevel + 3);
					stream << "{";
					stream << ng.get(parameter->type()) << ", ";
					stream << "attributes = [";
					for (auto attribute : parameter->attributes())
						emmitAttribute(stream, *attribute, ng);
					stream << "] }\r\n";
				}
				indent(stream, indentationLevel + 2);
				stream << "]\r\n";
				auto const* const returnType = function->returnType();
				indent(stream, indentationLevel + 2);
				stream << "return_type = ";
				if (returnType != nullptr)
					stream << ng.get(returnType);
				else
					stream << "void";
				stream << "\r\n";

				indent(stream, indentationLevel + 2);
				stream << "code = \r\n";
				indent(stream, indentationLevel + 2);
				stream << "[\r\n";
				{
					for (auto& instruction : function->code())
					{
						instruction->emmit(stream, ng, indentationLevel + 3);
						stream << "\r\n";
					}
				}
				indent(stream, indentationLevel + 2);
				stream << "]\r\n";
			}
			indent(stream, indentationLevel + 1);
			stream << "}\r\n";
		}
	}
	indent(stream, indentationLevel);
	stream << "]\r\n";

}

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
			emmitType(type, stream, nl, 0);
	}
	stream << "]\r\n";

	stream << "attributes = [\r\n";
	{
		for (not_null attribute : getAttributes(package))
		{
			stream << "\t{\r\n";
			{
				stream << "\t\t'" << attribute->qualifiedName() << "'\r\n";
				stream << "\t\tbacking_type = {\r\n";
				emmitType(attribute->describingType(), stream, nl, 2);
			}
			stream << "\t}\r\n";
		}
	}
	stream << "]\r\n";
	emmitFunctions(functions, stream, nl, 0);
}