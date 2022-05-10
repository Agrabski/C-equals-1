set(PROJECT_NAME CM1Compiler_CPP)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "CLIInterface.hpp"
)
source_group("Header Files" FILES ${Header_Files})

configure_file("compiler-interface/manifest.mn" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/manifest.mn" COPYONLY)
configure_file("compiler-interface/src/boolean.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/boolean.cm" COPYONLY)
configure_file("compiler-interface/src/build_expression.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/build_expression.cm" COPYONLY)
configure_file("compiler-interface/src/build_function.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/build_function.cm" COPYONLY)
configure_file("compiler-interface/src/entry_point.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/entry_point.cm" COPYONLY)
configure_file("compiler-interface/src/fileintrinsics.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/fileintrinsics.cm" COPYONLY)
configure_file("compiler-interface/src/function_body.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/function_body.cm" COPYONLY)
configure_file("compiler-interface/src/operator.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/operator.cm" COPYONLY)
configure_file("compiler-interface/src/package_registry.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/package_registry.cm" COPYONLY)
configure_file("compiler-interface/src/string.cm" "${CMAKE_CURRENT_BINARY_DIR}/compiler-interface/src/string.cm" COPYONLY)


set(Source_Files
    "main.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Resource_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_executable(${PROJECT_NAME} ${ALL_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    TARGET_NAME_DEBUGSTATIC   "cm1c"
    TARGET_NAME_DEBUG         "cm1c"
    TARGET_NAME_RELEASESTATIC "cm1c"
    TARGET_NAME_RELEASE       "cm1c"
)

################################################################################
# Dependencies
################################################################################
# Link with other targets.
target_link_libraries(${PROJECT_NAME} PRIVATE
    Compiler
    DataStructures
    LanguageLogic
    antlr_runtime

)

find_package(Boost 1.76.0 COMPONENTS program_options REQUIRED )
target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIRS})
install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_BINARY_DIR}/bin)
link_directories(${Boost_LIBRARY_DIRS})
link_directories(${Boost_LIBRARY_DIR})
find_package(ZLIB REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)

TARGET_LINK_LIBRARIES( ${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES} )

find_package(LLVM CONFIG REQUIRED)

list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(HandleLLVMOptions)
add_definitions(${LLVM_DEFINITIONS})

target_include_directories(${PROJECT_NAME} PRIVATE ${LLVM_INCLUDE_DIRS})

# Find the libraries that correspond to the LLVM components that we wish to use
llvm_map_components_to_libnames(llvm_libs all)

# Link against LLVM libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${llvm_libs})

find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)























