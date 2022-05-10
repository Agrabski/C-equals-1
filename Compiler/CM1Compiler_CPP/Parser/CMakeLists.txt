set(PROJECT_NAME Parser)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "antlr4-runtime.h"
    "CMinusEqualsMinus1Revision0BaseListener.h"
    "CMinusEqualsMinus1Revision0BaseVisitor.h"
    "CMinusEqualsMinus1Revision0Lexer.h"
    "CMinusEqualsMinus1Revision0Listener.h"
    "CMinusEqualsMinus1Revision0Parser.h"
    "CMinusEqualsMinus1Revision0Visitor.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Source_Files
    "CMinusEqualsMinus1Revision0BaseListener.cpp"
    "CMinusEqualsMinus1Revision0BaseVisitor.cpp"
    "CMinusEqualsMinus1Revision0Lexer.cpp"
    "CMinusEqualsMinus1Revision0Listener.cpp"
    "CMinusEqualsMinus1Revision0Parser.cpp"
    "CMinusEqualsMinus1Revision0Visitor.cpp"
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
set(ROOT_NAMESPACE Parser)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Dependencies
################################################################################
# Link with other targets.
target_link_libraries(${PROJECT_NAME} PUBLIC
    antlr_runtime
)
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)

