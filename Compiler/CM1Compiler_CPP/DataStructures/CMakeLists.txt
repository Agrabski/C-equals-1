set(PROJECT_NAME DataStructures)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "Accessibility.hpp"
    "Attribute.hpp"
    "AttributeInstance.hpp"
    "AttributeTarget.hpp"
    "CompilationContext.hpp"
    "CompilationResult.hpp"
    "Enum.hpp"
    "Field.hpp"
    "Function.hpp"
    "Generic.hpp"
    "GenericInstantiationData.hpp"
    "INamedObject.hpp"
    "InvalidTypeException.hpp"
    "ISerializationManager.hpp"
    "IValueHolder.hpp"
    "MetadataObject.hpp"
    "NameResolutionContext.hpp"
    "Namespace.hpp"
    "NullValueException.hpp"
    "ObjectWithAccessibility.hpp"
    "ObjectWithMetadata.hpp"
    "PackageDatabase.hpp"
    "printStackTrace.hpp"
    "QualifiedName.hpp"
    "RuntimeException.hpp"
    "SourcePointer.hpp"
    "Target.hpp"
    "Type.hpp"
    "TypeClassifier.hpp"
    "TypeReference.hpp"
    "Variable.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__Execution
    "execution/ArrayValue.hpp"
    "execution/BooleanValue.hpp"
    "execution/GenericOwningRuntimeWrapper.h"
    "execution/GenericRuntimeWrapper.hpp"
    "execution/IComplexRuntimeValue.hpp"
    "execution/InstructionCode.hpp"
    "execution/IntegerValue.hpp"
    "execution/IRuntimeValue.h"
    "execution/ObjectValue.hpp"
    "execution/ReferenceValue.hpp"
    "execution/RuntimeFieldDescriptor.hpp"
    "execution/RuntimeFunctionDescriptor.hpp"
    "execution/RuntimePackageDescriptor.hpp"
    "execution/RuntimeTypeDescriptor.hpp"
    "execution/RuntimeVariableDescriptor.hpp"
    "execution/StringValue.hpp"
    "execution/WrapperTypeTranslation.hpp"
)
source_group("Header Files\\Execution" FILES ${Header_Files__Execution})

set(Header_Files__Generics
    "Generic/GenericObject.hpp"
    "Generic/GenericParameter.hpp"
    "Generic/GenericVariable.hpp"
    "Generic/TypePointer.hpp"
)
source_group("Header Files\\Generics" FILES ${Header_Files__Generics})

set(Header_Files__Validation
    "Validation/SemanticModelValidationException.h"
    "Validation/ValidationError.hpp"
    "Validation/ValidationUtility.hpp"
)
source_group("Header Files\\Validation" FILES ${Header_Files__Validation})

set(Source_Files
    "Accessibility.cpp"
    "Attribute.cpp"
    "AttributeTarget.cpp"
    "execution/ArrayValue.cpp"
    "execution/BooleanValue.cpp"
    "execution/IntegerValue.cpp"
    "execution/IRuntimeValue.cpp"
    "execution/ObjectValue.cpp"
    "execution/ReferenceValue.cpp"
    "execution/RuntimeFieldDescriptor.cpp"
    "execution/RuntimeFunctionDescriptor.cpp"
    "execution/RuntimePackageDescriptor.cpp"
    "execution/RuntimeTypeDescriptor.cpp"
    "execution/RuntimeVariableDescriptor.cpp"
    "execution/StringValue.cpp"
    "Field.cpp"
    "Function.cpp"
    "Generic/GenericObject.cpp"
    "INamedObject.cpp"
    "NameResolutionContext.cpp"
    "Namespace.cpp"
    "printStackTrace.cpp"
    "QualifiedName.cpp"
    "RuntimeException.cpp"
    "Target.cpp"
    "Type.cpp"
    "TypeClassifier.cpp"
    "TypeReference.cpp"
    "Validation/SemanticModelValidationException.cpp"
    "Validation/ValidationError.cpp"
    "Validation/ValidationUtility.cpp"
    "Variable.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Header_Files__Execution}
    ${Header_Files__Generics}
    ${Header_Files__Validation}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE DataStructures)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "$<$<CONFIG:DebugStatic>:"
            "_DEBUG;"
            "_LIB;"
            "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"
        ">"
        "$<$<CONFIG:Debug>:"
            "_DEBUG;"
            "_LIB;"
            "_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS"
        ">"
        "$<$<CONFIG:ReleaseStatic>:"
            "NDEBUG;"
            "_CONSOLE"
        ">"
        "$<$<CONFIG:Release>:"
            "NDEBUG;"
            "_CONSOLE"
        ">"
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
            $<$<CONFIG:DebugStatic>:
                /Y-
            >
            $<$<CONFIG:Debug>:
                /Y-
            >
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
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
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
    if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
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
    antlr_runtime
    Parser
    Utilities

)
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)
