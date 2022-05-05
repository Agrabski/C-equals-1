set(PROJECT_NAME LanguageLogic)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "AttributeUtility.hpp"
    "BuiltInPackageBuildUtility.hpp"
    "CompilerInterface.hpp"
    "CompileTimeFunctions/Boobs.hpp"
    "CreateGetter.hpp"
    "ExpressionUtility.hpp"
    "GenericUtility.hpp"
    "GetterExecution.hpp"
    "InstantiateGeneric.hpp"
    "IRUtility.hpp"
    "LiteralUtility.hpp"
    "MetadataHolderBindings.hpp"
    "MetatypeUility.hpp"
    "NameResolver.hpp"
    "NamespaceBuilder.hpp"
    "OverloadResolutionUtility.hpp"
    "runtime_values.hpp"
    "RuntimeTypesConversionUtility.hpp"
    "SpecialFunctionUtility.hpp"
    "TypeCoercionUtility.hpp"
    "TypeInstantiationUtility.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__CompileTimeFunctions
    "CompileTimeFunctions/CompileTimeAllocate.hpp"
    "CompileTimeFunctions/CompileTimeFunction.hpp"
    "CompileTimeFunctions/CompileTimeFunctionDictionary.hpp"
    "CompileTimeFunctions/FunctionLibrary.hpp"
    "CompileTimeFunctions/MarkCompileTimeOnly.hpp"
    "CompileTimeFunctions/Print.hpp"
    "CompileTimeFunctions/RaiseError.hpp"
    "CompileTimeFunctions/ReadAllFile.hpp"
    "CompileTimeFunctions/ReplaceWithCompilerFunction.hpp"
    "CompileTimeFunctions/ReplaceWithCompilerType.hpp"
    "CompileTimeFunctions/ReplaceWithExternalSymbol.hpp"
)
source_group("Header Files\\CompileTimeFunctions" FILES ${Header_Files__CompileTimeFunctions})

set(Header_Files__CompileTimeInfrastrucutre
    "CompileTimeInfrastrucutre/CompilationOptions.hpp"
    "CompileTimeInfrastrucutre/CompileTimeHeap.hpp"
)
source_group("Header Files\\CompileTimeInfrastrucutre" FILES ${Header_Files__CompileTimeInfrastrucutre})

set(Header_Files__LLVMBindings
    "LLVMBindings/BodyBuilder.hpp"
    "LLVMBindings/Function.hpp"
    "LLVMBindings/LLVMBindings.hpp"
    "LLVMBindings/Module.hpp"
    "LLVMBindings/Type.hpp"
    "LLVMBindings/Types.hpp"
    "LLVMBindings/Value.hpp"
)
source_group("Header Files\\LLVMBindings" FILES ${Header_Files__LLVMBindings})

set(Header_Files__Libraries
    "Libraries/FilesystemLibrary.hpp"
    "Libraries/Libraries.hpp"
)
source_group("Header Files\\Libraries" FILES ${Header_Files__Libraries})

set(Header_Files__SpecialTypes
    "SpecialTypes/SpecialTypeLibrary.hpp"
)
source_group("Header Files\\SpecialTypes" FILES ${Header_Files__SpecialTypes})

set(Source_Files
    "AttributeUtility.cpp"
    "BuiltInPackageBuildUtility.cpp"
    "CompilerInterface.cpp"
    "CompileTimeFunctions/CompileTimeAllocate.cpp"
    "CompileTimeFunctions/CompileTimeFunctionDictionary.cpp"
    "CompileTimeFunctions/FunctionLibrary.cpp"
    "CompileTimeFunctions/MarkCompileTimeOnly.cpp"
    "CompileTimeFunctions/Print.cpp"
    "CompileTimeFunctions/RaiseError.cpp"
    "CompileTimeFunctions/ReadAllFile.cpp"
    "CompileTimeFunctions/ReplaceWithCompilerFunction.cpp"
    "CompileTimeFunctions/ReplaceWithCompilerType.cpp"
    "CompileTimeFunctions/ReplaceWithExternalSymbol.cpp"
    "CompileTimeInfrastrucutre/CompileTimeHeap.cpp"
    "CreateGetter.cpp"
    "ExpressionUtility.cpp"
    "FunctionPredicates.cpp"
    "GenericUtility.cpp"
    "GetterExecution.cpp"
    "InstantiateGeneric.cpp"
    "IRUtility.cpp"
    "Libraries/FilesystemLibrary.cpp"
    "Libraries/Libraries.cpp"
    "LiteralUtility.cpp"
    "LLVMBindings/BodyBuilder.cpp"
    "LLVMBindings/Function.cpp"
    "LLVMBindings/LLVMBindings.cpp"
    "LLVMBindings/Module.cpp"
    "LLVMBindings/Type.cpp"
    "LLVMBindings/Types.cpp"
    "LLVMBindings/Value.cpp"
    "MetatypeUility.cpp"
    "NameResolver.cpp"
    "NamespaceBuilder.cpp"
    "OverloadResolutionUtility.cpp"
    "RuntimeTypesConversionUtility.cpp"
    "SpecialFunctionUtility.cpp"
    "SpecialTypes/SpecialTypeLibrary.cpp"
    "TypeCoercionUtility.cpp"
    "TypeInstantiationUtility.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Header_Files__CompileTimeFunctions}
    ${Header_Files__CompileTimeInfrastrucutre}
    ${Header_Files__LLVMBindings}
    ${Header_Files__Libraries}
    ${Header_Files__SpecialTypes}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE LanguageLogic)

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
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "_LIB;"
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
        "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING;"
        "WIN32;"
        "_LIB;"
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

            /Gm-;
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

            /Gm-;
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
)

use_package(${PROJECT_NAME} boost 1.76.0.0)
find_package(Boost 1.79.0 COMPONENTS)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::headers)
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)


find_package(LLVM CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

target_include_directories(${PROJECT_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})

# Find the libraries that correspond to the LLVM components that we wish to use
llvm_map_components_to_libnames(llvm_libs all codegen core irreader)

# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})




