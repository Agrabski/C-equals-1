#include "compilerInterfaceUtility.hpp"
#include "PackageBuildUtility.hpp"
#include "../LanguageLogic/BuiltInPackageBuildUtility.hpp"

using namespace cMCompiler;

std::unique_ptr<dataStructures::PackageDatabase> cMCompiler::compiler::loadCompilerInterfacePackage(
	dataStructures::CompilationContext const& context)
{
	std::vector<gsl::not_null<dataStructures::PackageDatabase*>> _;
	if (context.compilerInterfaceManifestFile)
		return buildByManifest(*context.compilerInterfaceManifestFile, _);
	return buildByManifest(context.executablePath / "compiler-interface/compilerInterface.mn", _);
}

gsl::not_null<dataStructures::Function*> cMCompiler::compiler::getCompilerInterfaceEntryPoint(dataStructures::PackageDatabase& interfacePackage)
{
	auto functions = interfacePackage.getAllFunctions();
	auto attribute = language::getCompilerEntryPointAttribute();
	auto result = std::find_if(functions.begin(), functions.end(), [attribute](const auto& e)
		{
			auto attributes = e->attributes();
			return std::ranges::find_if(attributes.begin(), attributes.end(), [attribute](const auto& a) noexcept
				{
					return a->basedOn() == attribute.get();
				}) != attributes.end();
		});
	assert(result != functions.end());
	return *result;
}
