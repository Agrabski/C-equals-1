

set(PROJECT_NAME Utilities)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "algorithm.hpp"
    "collections.hpp"
    "framework.h"
    "json.hpp"
    "pch.h"
    "pointer_cast.hpp"
    "range.hpp"
    "typedRange.hpp"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "pch.cpp"
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
set(ROOT_NAMESPACE Utilities)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)

 find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
