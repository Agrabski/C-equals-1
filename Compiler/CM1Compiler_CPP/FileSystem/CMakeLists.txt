set(PROJECT_NAME FileSystem)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "File.hpp"
    "FileDiscovery.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "File.cpp"
    "FileDiscovery.cpp"
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
set(ROOT_NAMESPACE FileSystem)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)























