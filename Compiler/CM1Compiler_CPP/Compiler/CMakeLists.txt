set(PROJECT_NAME Compiler)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "AttributeSpecialFunctionsExecution.hpp"
    "AttributeUtility.hpp"
    "CompilationUnitDatabaseBuilder.hpp"
    "compilerInterfaceUtility.hpp"
    "Environment.hpp"
    "ExceptionHandling.hpp"
    "ExpressionBuilder.hpp"
    "ExpressionEvaluator.hpp"
    "FunctionBodyBuilder.hpp"
    "FunctionExecutionUtility.hpp"
    "FunctionUtility.hpp"
    "IntermidiateRepresentationEmmiter.hpp"
    "PackageBuildUtility.hpp"
    "PackageDiscoveryUtility.hpp"
    "Preprocessor.hpp"
    "StatementEvaluator.hpp"
    "TypeUtility.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__Generic
    "Generic/GenericInstantiationUtility.hpp"
)
source_group("Header Files\\Generic" FILES ${Header_Files__Generic})

set(Header_Files__LLVMIntegration
    "LLVMIntegration/LLVMIRUtility.hpp"
)
source_group("Header Files\\LLVMIntegration" FILES ${Header_Files__LLVMIntegration})

set(Header_Files__Serialization
    "Serialization/NameGetter.hpp"
    "Serialization/SerializationManager.hpp"
)
source_group("Header Files\\Serialization" FILES ${Header_Files__Serialization})

set(Source_Files
    "AttributeSpecialFunctionsExecution.cpp"
    "AttributeUtility.cpp"
    "CompilationUnitDatabaseBuilder.cpp"
    "compilerInterfaceUtility.cpp"
    "Environment.cpp"
    "ExceptionHandling.cpp"
    "ExpressionBuilder.cpp"
    "ExpressionEvaluator.cpp"
    "FunctionBodyBuilder.cpp"
    "FunctionExecutionUtility.cpp"
    "FunctionUtility.cpp"
    "Generic/GenericInstantiationUtility.cpp"
    "IntermidiateRepresentationEmmiter.cpp"
    "LLVMIntegration/LLVMIRUtility.cpp"
    "PackageBuildUtility.cpp"
    "PackageDiscoveryUtility.cpp"
    "Preprocessor.cpp"
    "Serialization/NameGetter.cpp"
    "StatementEvaluator.cpp"
    "TypeUtility.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Header_Files__Generic}
    ${Header_Files__LLVMIntegration}
    ${Header_Files__Serialization}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE Compiler)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Dependencies
################################################################################
# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    DataStructures
    FileSystem
    ParserAdapter
    Parser
)

find_package(Boost 1.76.0 COMPONENTS regex REQUIRED )
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
link_directories(${Boost_LIBRARY_DIRS})
link_directories(${Boost_LIBRARY_DIR})

find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)
find_package(LLVM CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

target_include_directories(${PROJECT_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})

# Find the libraries that correspond to the LLVM components that we wish to use
llvm_map_components_to_libnames(llvm_libs all codegen core x86CodeGen x86AsmParser)

# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})
