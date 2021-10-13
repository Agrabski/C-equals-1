#include "FilesystemLibrary.hpp"
#include <fstream>
#include "../BuiltInPackageBuildUtility.hpp"
#include "../CreateGetter.hpp"
#include "../RuntimeTypesConversionUtility.hpp"
#include "../../DataStructures/execution/StringValue.hpp"
#include "../../DataStructures/execution/GenericOwningRuntimeWrapper.h"
#include "../CompileTimeInfrastrucutre/CompilationOptions.hpp"
#include "../LiteralUtility.hpp"

using gsl::not_null;
using namespace cMCompiler::dataStructures;
using namespace cMCompiler::language::libraries;
using namespace cMCompiler::language;

cMCompiler::dataStructures::Type* fileDescriptor;

not_null<Type*> createFileDescriptor(not_null<Namespace*> ns)
{
	auto result = ns->append<Type>("fileDescriptor");
	fileDescriptor = result.get();

	return result;
}

void createOpen(not_null<Type*> fd, not_null<Namespace*> ns, not_null<Type*> string)
{
	auto f = ns->append<Function>("open");
	f->appendVariable("path", { string, 1 });
	f->setReturnType({ fd, 0 });
	cMCompiler::language::createCustomFunction(
		f,
		[](auto&& a, auto b) -> cMCompiler::language::runtime_value
		{
			auto path = dereferenceAs<execution::StringValue>(a["path"].get())->value();
			auto stream = std::make_unique<std::fstream>(path, std::ios_base::in | std::ios_base::out);
			return getValueFor(std::move(stream));
		}
	);
	f = ns->append<Function>("open");
	f->appendVariable("path", { string, 1 });
	f->setReturnType({ fd, 0 });
	f->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
}

void createWriteStringToFile(not_null<Type*> fd, not_null<Namespace*> ns, not_null<Type*> string)
{
	auto f = ns->append<Function>("write");
	f->appendVariable("file", { fd, 1 });
	f->appendVariable("text", { string, 1 });
	cMCompiler::language::createCustomFunction(
		f,
		[](auto&& a, auto b) -> cMCompiler::language::runtime_value
		{
			auto text = dereferenceAs<execution::StringValue>(a["text"].get())->value();
			auto file = dereferenceAs<execution::GenericRuntimeWrapper<std::iostream>>(a["text"].get())->value();
			*file << text;
			return nullptr;
		}
	);
	f = ns->append<Function>("write");
	f->appendVariable("file", { fd, 1 });
	f->appendVariable("text", { string, 1 });
	f->metadata().appendFlag(FunctionFlags::ExcludeAtCompileTime);
}

void createFileWriteFunctions(not_null<Type*> fd, not_null<Namespace*> ns, not_null<Type*> string)
{
	createWriteStringToFile(fd, ns, string);
}

void createGetOutputDirectory(not_null<Type*> fd, not_null<Namespace*> ns, not_null<Type*> string)
{
	auto f = ns->append<Function>("getOutputDirectory");
	f->setReturnType({ string, 0 });
	cMCompiler::language::createCustomFunction(
		f,
		[](auto&& a, auto b) -> cMCompiler::language::runtime_value
		{
			return buildStringValue(compileTimeInfrastructure::CompilationOptions::instance->outputDirectory.string());
		}
	);
}

void cMCompiler::language::libraries::createFilesystemLibrary(not_null<Namespace*> ns)
{
	auto rootNs = ns->append<Namespace>("filesystem");

	auto fd = createFileDescriptor(rootNs);
	createFileWriteFunctions(fd, rootNs, getString());
}

runtime_value cMCompiler::language::getValueFor(std::unique_ptr<std::iostream>&& str)
{
	return std::make_unique<execution::GenericOwningRuntimeWrapper<std::iostream>>(
		std::shared_ptr<std::iostream>(str.release()),
		TypeReference{ fileDescriptor, 0 });
}
