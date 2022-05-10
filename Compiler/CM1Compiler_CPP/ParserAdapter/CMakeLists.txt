

add_library(parser_adapter STATIC 
	"ParserAdapter.cpp"
	"ParserAdapter.hpp")
set_target_properties(parser_adapter PROPERTIES LINKER_LANGUAGE CXX)


set(LIB_OUTPUT_DIR "${CMAKE_HOME_DIRECTORY}/dist") # put generated libraries here.
message(STATUS "Output libraries to ${LIB_OUTPUT_DIR}")
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(parser_adapter PRIVATE Microsoft.GSL::GSL)
target_link_libraries(parser_adapter PRIVATE parser)



























set(PROJECT_NAME ParserAdapter)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "ParserAdapter.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "ParserAdapter.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE ParserAdapter)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    Parser
)
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)

