cmake_minimum_required(VERSION 3.16.0 FATAL_ERROR)

enable_language(C)

set(CMAKE_SYSTEM_VERSION 10.0 CACHE STRING "" FORCE)
set (CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP, 1)
SET (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
# cancer but there is a bug in cmake/msvc
add_compile_definitions(_CPPUNWIND)

project(CM1Compiler_CPP CXX)

####### #########################################################################
# Set target arch type if empty. Visual studio solution generator provides it.
################################################################################
if(NOT CMAKE_VS_PLATFORM_NAME)
    set(CMAKE_VS_PLATFORM_NAME "x64")
endif()
message("${CMAKE_VS_PLATFORM_NAME} architecture in use")

if(NOT ("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64"
     OR "${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86"))
    message(FATAL_ERROR "${CMAKE_VS_PLATFORM_NAME} arch is not supported!")
endif()

################################################################################
# Global configuration types
################################################################################
set(CMAKE_CONFIGURATION_TYPES
    "Debug"
    "Release"
    CACHE STRING "" FORCE
)

################################################################################
# Common utils
################################################################################
include(CMake/Utils.cmake)

################################################################################
# Additional Global Settings(add specific info there)
################################################################################
include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

################################################################################
# Use solution folders feature
################################################################################
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

################################################################################
# Sub-projects
################################################################################

add_subdirectory(antlr_runtime)
add_subdirectory(CM1Compiler_CPP)
add_subdirectory(Compiler)
add_subdirectory(DataStructures)
add_subdirectory(Execution)
add_subdirectory(FileSystem)
add_subdirectory(LanguageLogic)
add_subdirectory(Parser)
add_subdirectory(ParserAdapter)
add_subdirectory(Utilities)

