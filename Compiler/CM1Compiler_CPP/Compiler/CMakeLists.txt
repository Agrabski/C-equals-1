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
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DebugStatic>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:ReleaseStatic>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING;"
        "_LIB;"
        "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DebugStatic>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG"
        ">"
        "$<$<CONFIG:ReleaseStatic>:"
            "NDEBUG"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG"
        ">"
        "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING;"
        "WIN32;"
        "_LIB;"
        "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS;"
        "UNICODE;"
        "_UNICODE"
    )
endif()

################################################################################
# Compile and link options
################################################################################
if(MSVC)
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:ReleaseStatic>:
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;

            /sdl-;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:ReleaseStatic>:
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /Oi;
                /Gy
            >
            /permissive-;

            /sdl-;
            /W3;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            ${DEFAULT_CXX_EXCEPTION_HANDLING};
            /Y-
        )
    endif()
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:ReleaseStatic>:
                /OPT:REF;
                /OPT:ICF
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_link_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:ReleaseStatic>:
                /OPT:REF;
                /OPT:ICF
            >
            $<$<CONFIG:Release>:
                /OPT:REF;
                /OPT:ICF
            >
        )
    endif()
endif()

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

use_package(${PROJECT_NAME} boost 1.76.0.0)
use_package(${PROJECT_NAME} boost_regex-vc141 1.76.0.0)
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
