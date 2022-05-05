set(PROJECT_NAME antlr_runtime)

################################################################################
# Source groups
################################################################################
set(Header_Files
    "src/antlr4-common.h"
    "src/antlr4-runtime.h"
    "src/ANTLRErrorListener.h"
    "src/ANTLRErrorStrategy.h"
    "src/ANTLRFileStream.h"
    "src/ANTLRInputStream.h"
    "src/BaseErrorListener.h"
    "src/BufferedTokenStream.h"
    "src/CharStream.h"
    "src/CommonToken.h"
    "src/CommonTokenFactory.h"
    "src/CommonTokenStream.h"
    "src/ConsoleErrorListener.h"
    "src/DefaultErrorStrategy.h"
    "src/DiagnosticErrorListener.h"
    "src/Exceptions.h"
    "src/FailedPredicateException.h"
    "src/InputMismatchException.h"
    "src/InterpreterRuleContext.h"
    "src/IntStream.h"
    "src/Lexer.h"
    "src/LexerInterpreter.h"
    "src/LexerNoViableAltException.h"
    "src/ListTokenSource.h"
    "src/misc/InterpreterDataReader.h"
    "src/NoViableAltException.h"
    "src/Parser.h"
    "src/ParserRuleContext.h"
    "src/ProxyErrorListener.h"
    "src/RecognitionException.h"
    "src/Recognizer.h"
    "src/RuleContext.h"
    "src/RuleContextWithAltNum.h"
    "src/RuntimeMetaData.h"
    "src/Token.h"
    "src/TokenFactory.h"
    "src/TokenSource.h"
    "src/TokenStream.h"
    "src/TokenStreamRewriter.h"
    "src/UnbufferedCharStream.h"
    "src/UnbufferedTokenStream.h"
    "src/Vocabulary.h"
)
source_group("Header Files" FILES ${Header_Files})

set(Header_Files__atn
    "src/atn/AbstractPredicateTransition.h"
    "src/atn/ActionTransition.h"
    "src/atn/AmbiguityInfo.h"
    "src/atn/ArrayPredictionContext.h"
    "src/atn/ATN.h"
    "src/atn/ATNConfig.h"
    "src/atn/ATNConfigSet.h"
    "src/atn/ATNDeserializationOptions.h"
    "src/atn/ATNDeserializer.h"
    "src/atn/ATNSerializer.h"
    "src/atn/ATNSimulator.h"
    "src/atn/ATNState.h"
    "src/atn/ATNType.h"
    "src/atn/AtomTransition.h"
    "src/atn/BasicBlockStartState.h"
    "src/atn/BasicState.h"
    "src/atn/BlockEndState.h"
    "src/atn/BlockStartState.h"
    "src/atn/ContextSensitivityInfo.h"
    "src/atn/DecisionEventInfo.h"
    "src/atn/DecisionInfo.h"
    "src/atn/DecisionState.h"
    "src/atn/EmptyPredictionContext.h"
    "src/atn/EpsilonTransition.h"
    "src/atn/ErrorInfo.h"
    "src/atn/LexerAction.h"
    "src/atn/LexerActionExecutor.h"
    "src/atn/LexerActionType.h"
    "src/atn/LexerATNConfig.h"
    "src/atn/LexerATNSimulator.h"
    "src/atn/LexerChannelAction.h"
    "src/atn/LexerCustomAction.h"
    "src/atn/LexerIndexedCustomAction.h"
    "src/atn/LexerModeAction.h"
    "src/atn/LexerMoreAction.h"
    "src/atn/LexerPopModeAction.h"
    "src/atn/LexerPushModeAction.h"
    "src/atn/LexerSkipAction.h"
    "src/atn/LexerTypeAction.h"
    "src/atn/LL1Analyzer.h"
    "src/atn/LookaheadEventInfo.h"
    "src/atn/LoopEndState.h"
    "src/atn/NotSetTransition.h"
    "src/atn/OrderedATNConfigSet.h"
    "src/atn/ParseInfo.h"
    "src/atn/ParserATNSimulator.h"
    "src/atn/PlusBlockStartState.h"
    "src/atn/PlusLoopbackState.h"
    "src/atn/PrecedencePredicateTransition.h"
    "src/atn/PredicateEvalInfo.h"
    "src/atn/PredicateTransition.h"
    "src/atn/PredictionContext.h"
    "src/atn/PredictionMode.h"
    "src/atn/ProfilingATNSimulator.h"
    "src/atn/RangeTransition.h"
    "src/atn/RuleStartState.h"
    "src/atn/RuleStopState.h"
    "src/atn/RuleTransition.h"
    "src/atn/SemanticContext.h"
    "src/atn/SetTransition.h"
    "src/atn/SingletonPredictionContext.h"
    "src/atn/StarBlockStartState.h"
    "src/atn/StarLoopbackState.h"
    "src/atn/StarLoopEntryState.h"
    "src/atn/TokensStartState.h"
    "src/atn/Transition.h"
    "src/atn/WildcardTransition.h"
)
source_group("Header Files\\atn" FILES ${Header_Files__atn})

set(Header_Files__dfa
    "src/dfa/DFA.h"
    "src/dfa/DFASerializer.h"
    "src/dfa/DFAState.h"
    "src/dfa/LexerDFASerializer.h"
)
source_group("Header Files\\dfa" FILES ${Header_Files__dfa})

set(Header_Files__misc
    "src/misc/Interval.h"
    "src/misc/IntervalSet.h"
    "src/misc/MurmurHash.h"
    "src/misc/Predicate.h"
)
source_group("Header Files\\misc" FILES ${Header_Files__misc})

set(Header_Files__support
    "src/support/Arrays.h"
    "src/support/BitSet.h"
    "src/support/CPPUtils.h"
    "src/support/Declarations.h"
    "src/support/guid.h"
    "src/support/StringUtils.h"
)
source_group("Header Files\\support" FILES ${Header_Files__support})

set(Header_Files__tree
    "src/tree/AbstractParseTreeVisitor.h"
    "src/tree/ErrorNode.h"
    "src/tree/ErrorNodeImpl.h"
    "src/tree/IterativeParseTreeWalker.h"
    "src/tree/ParseTree.h"
    "src/tree/ParseTreeListener.h"
    "src/tree/ParseTreeProperty.h"
    "src/tree/ParseTreeVisitor.h"
    "src/tree/ParseTreeWalker.h"
    "src/tree/TerminalNode.h"
    "src/tree/TerminalNodeImpl.h"
    "src/tree/Trees.h"
)
source_group("Header Files\\tree" FILES ${Header_Files__tree})

set(Header_Files__tree__xpath
    "src/tree/xpath/XPath.h"
    "src/tree/xpath/XPathElement.h"
    "src/tree/xpath/XPathLexer.h"
    "src/tree/xpath/XPathLexerErrorListener.h"
    "src/tree/xpath/XPathRuleAnywhereElement.h"
    "src/tree/xpath/XPathRuleElement.h"
    "src/tree/xpath/XPathTokenAnywhereElement.h"
    "src/tree/xpath/XPathTokenElement.h"
    "src/tree/xpath/XPathWildcardAnywhereElement.h"
    "src/tree/xpath/XPathWildcardElement.h"
)
source_group("Header Files\\tree\\xpath" FILES ${Header_Files__tree__xpath})

set(Source_Files
    "src/ANTLRErrorListener.cpp"
    "src/ANTLRErrorStrategy.cpp"
    "src/ANTLRFileStream.cpp"
    "src/ANTLRInputStream.cpp"
    "src/BaseErrorListener.cpp"
    "src/BufferedTokenStream.cpp"
    "src/CharStream.cpp"
    "src/CommonToken.cpp"
    "src/CommonTokenFactory.cpp"
    "src/CommonTokenStream.cpp"
    "src/ConsoleErrorListener.cpp"
    "src/DefaultErrorStrategy.cpp"
    "src/DiagnosticErrorListener.cpp"
    "src/Exceptions.cpp"
    "src/FailedPredicateException.cpp"
    "src/InputMismatchException.cpp"
    "src/InterpreterRuleContext.cpp"
    "src/IntStream.cpp"
    "src/Lexer.cpp"
    "src/LexerInterpreter.cpp"
    "src/LexerNoViableAltException.cpp"
    "src/ListTokenSource.cpp"
    "src/NoViableAltException.cpp"
    "src/Parser.cpp"
    "src/ParserRuleContext.cpp"
    "src/ProxyErrorListener.cpp"
    "src/RecognitionException.cpp"
    "src/Recognizer.cpp"
    "src/RuleContext.cpp"
    "src/RuleContextWithAltNum.cpp"
    "src/RuntimeMetaData.cpp"
    "src/Token.cpp"
    "src/TokenSource.cpp"
    "src/TokenStream.cpp"
    "src/TokenStreamRewriter.cpp"
    "src/UnbufferedCharStream.cpp"
    "src/UnbufferedTokenStream.cpp"
    "src/Vocabulary.cpp"
)
source_group("Source Files" FILES ${Source_Files})

set(Source_Files__atn
    "src/atn/AbstractPredicateTransition.cpp"
    "src/atn/ActionTransition.cpp"
    "src/atn/AmbiguityInfo.cpp"
    "src/atn/ArrayPredictionContext.cpp"
    "src/atn/ATN.cpp"
    "src/atn/ATNConfig.cpp"
    "src/atn/ATNConfigSet.cpp"
    "src/atn/ATNDeserializationOptions.cpp"
    "src/atn/ATNDeserializer.cpp"
    "src/atn/ATNSerializer.cpp"
    "src/atn/ATNSimulator.cpp"
    "src/atn/ATNState.cpp"
    "src/atn/AtomTransition.cpp"
    "src/atn/BasicBlockStartState.cpp"
    "src/atn/BasicState.cpp"
    "src/atn/BlockEndState.cpp"
    "src/atn/BlockStartState.cpp"
    "src/atn/ContextSensitivityInfo.cpp"
    "src/atn/DecisionEventInfo.cpp"
    "src/atn/DecisionInfo.cpp"
    "src/atn/DecisionState.cpp"
    "src/atn/EmptyPredictionContext.cpp"
    "src/atn/EpsilonTransition.cpp"
    "src/atn/ErrorInfo.cpp"
    "src/atn/LexerAction.cpp"
    "src/atn/LexerActionExecutor.cpp"
    "src/atn/LexerATNConfig.cpp"
    "src/atn/LexerATNSimulator.cpp"
    "src/atn/LexerChannelAction.cpp"
    "src/atn/LexerCustomAction.cpp"
    "src/atn/LexerIndexedCustomAction.cpp"
    "src/atn/LexerModeAction.cpp"
    "src/atn/LexerMoreAction.cpp"
    "src/atn/LexerPopModeAction.cpp"
    "src/atn/LexerPushModeAction.cpp"
    "src/atn/LexerSkipAction.cpp"
    "src/atn/LexerTypeAction.cpp"
    "src/atn/LL1Analyzer.cpp"
    "src/atn/LookaheadEventInfo.cpp"
    "src/atn/LoopEndState.cpp"
    "src/atn/NotSetTransition.cpp"
    "src/atn/OrderedATNConfigSet.cpp"
    "src/atn/ParseInfo.cpp"
    "src/atn/ParserATNSimulator.cpp"
    "src/atn/PlusBlockStartState.cpp"
    "src/atn/PlusLoopbackState.cpp"
    "src/atn/PrecedencePredicateTransition.cpp"
    "src/atn/PredicateEvalInfo.cpp"
    "src/atn/PredicateTransition.cpp"
    "src/atn/PredictionContext.cpp"
    "src/atn/PredictionMode.cpp"
    "src/atn/ProfilingATNSimulator.cpp"
    "src/atn/RangeTransition.cpp"
    "src/atn/RuleStartState.cpp"
    "src/atn/RuleStopState.cpp"
    "src/atn/RuleTransition.cpp"
    "src/atn/SemanticContext.cpp"
    "src/atn/SetTransition.cpp"
    "src/atn/SingletonPredictionContext.cpp"
    "src/atn/StarBlockStartState.cpp"
    "src/atn/StarLoopbackState.cpp"
    "src/atn/StarLoopEntryState.cpp"
    "src/atn/TokensStartState.cpp"
    "src/atn/Transition.cpp"
    "src/atn/WildcardTransition.cpp"
)
source_group("Source Files\\atn" FILES ${Source_Files__atn})

set(Source_Files__dfa
    "src/dfa/DFA.cpp"
    "src/dfa/DFASerializer.cpp"
    "src/dfa/DFAState.cpp"
    "src/dfa/LexerDFASerializer.cpp"
)
source_group("Source Files\\dfa" FILES ${Source_Files__dfa})

set(Source_Files__misc
    "src/misc/Interval.cpp"
    "src/misc/IntervalSet.cpp"
    "src/misc/MurmurHash.cpp"
    "src/misc/Predicate.cpp"
)
source_group("Source Files\\misc" FILES ${Source_Files__misc})

set(Source_Files__support
    "src/support/Any.cpp"
    "src/support/Any.h"
    "src/support/Arrays.cpp"
    "src/support/CPPUtils.cpp"
    "src/support/guid.cpp"
    "src/support/StringUtils.cpp"
)
source_group("Source Files\\support" FILES ${Source_Files__support})

set(Source_Files__tree
    "src/tree/ErrorNode.cpp"
    "src/tree/ErrorNodeImpl.cpp"
    "src/tree/IterativeParseTreeWalker.cpp"
    "src/tree/ParseTree.cpp"
    "src/tree/ParseTreeListener.cpp"
    "src/tree/ParseTreeVisitor.cpp"
    "src/tree/ParseTreeWalker.cpp"
    "src/tree/TerminalNode.cpp"
    "src/tree/TerminalNodeImpl.cpp"
    "src/tree/Trees.cpp"
)
source_group("Source Files\\tree" FILES ${Source_Files__tree})

set(Source_Files__tree__xpath
    "src/tree/xpath/XPath.cpp"
    "src/tree/xpath/XPathElement.cpp"
    "src/tree/xpath/XPathLexer.cpp"
    "src/tree/xpath/XPathLexerErrorListener.cpp"
    "src/tree/xpath/XPathRuleAnywhereElement.cpp"
    "src/tree/xpath/XPathRuleElement.cpp"
    "src/tree/xpath/XPathTokenAnywhereElement.cpp"
    "src/tree/xpath/XPathTokenElement.cpp"
    "src/tree/xpath/XPathWildcardAnywhereElement.cpp"
    "src/tree/xpath/XPathWildcardElement.cpp"
)
source_group("Source Files\\tree\\xpath" FILES ${Source_Files__tree__xpath})

set(ALL_FILES
    ${Header_Files}
    ${Header_Files__atn}
    ${Header_Files__dfa}
    ${Header_Files__misc}
    ${Header_Files__support}
    ${Header_Files__tree}
    ${Header_Files__tree__xpath}
    ${Source_Files}
    ${Source_Files__atn}
    ${Source_Files__dfa}
    ${Source_Files__misc}
    ${Source_Files__support}
    ${Source_Files__tree}
    ${Source_Files__tree__xpath}
)

################################################################################
# Target
################################################################################
add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

use_props(${PROJECT_NAME} "${CMAKE_CONFIGURATION_TYPES}" "${DEFAULT_CXX_PROPS}")
set(ROOT_NAMESPACE antlr4cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    VS_GLOBAL_KEYWORD "Win32Proj"
)
################################################################################
# Target name
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUGSTATIC   "antlr4-runtime"
        TARGET_NAME_DEBUG         "antlr4-runtime"
        TARGET_NAME_RELEASESTATIC "antlr4-runtime"
        TARGET_NAME_RELEASE       "antlr4-runtime"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        TARGET_NAME_DEBUGSTATIC   "antlr4-runtime"
        TARGET_NAME_DEBUG         "antlr4-runtime"
        TARGET_NAME_RELEASESTATIC "antlr4-runtime"
        TARGET_NAME_RELEASE       "antlr4-runtime"
    )
endif()
################################################################################
# Output directory
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUGSTATIC   "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_DEBUG         "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_RELEASESTATIC "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_RELEASE       "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_DIRECTORY_DEBUGSTATIC   "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_DEBUG         "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_RELEASESTATIC "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
        OUTPUT_DIRECTORY_RELEASE       "${CMAKE_SOURCE_DIR}/bin/vs-2015/$ENV{PlatformTarget}/$<CONFIG>/"
    )
endif()
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASESTATIC "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_RELEASE       "TRUE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    set_target_properties(${PROJECT_NAME} PROPERTIES
        INTERPROCEDURAL_OPTIMIZATION_RELEASESTATIC "TRUE"
        INTERPROCEDURAL_OPTIMIZATION_RELEASE       "TRUE"
    )
endif()
################################################################################
# Include directories
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_include_directories(${PROJECT_NAME} PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
    )
endif()

################################################################################
# Compile definitions
################################################################################
if("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x64")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "ANTLR4CPP_STATIC;"
        "UNICODE;"
        "_UNICODE"
    )
elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        "ANTLR4CPP_EXPORTS;"
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
                /Gm-;
                /Od
            >
            $<$<CONFIG:Debug>:
                /Gm-;
                /Od
            >
            $<$<CONFIG:ReleaseStatic>:
                /O2;
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /MP;
            /W4;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /wd4251;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
        )
    elseif("${CMAKE_VS_PLATFORM_NAME}" STREQUAL "x86")
        target_compile_options(${PROJECT_NAME} PRIVATE
            $<$<CONFIG:DebugStatic>:
                /Gm-;
                /Od
            >
            $<$<CONFIG:Debug>:
                /Gm-;
                /Od
            >
            $<$<CONFIG:ReleaseStatic>:
                /O2;
                /Oi;
                /Gy
            >
            $<$<CONFIG:Release>:
                /O2;
                /Oi;
                /Gy
            >
            /MP;
            /W4;
            ${DEFAULT_CXX_DEBUG_INFORMATION_FORMAT};
            /wd4251;
            ${DEFAULT_CXX_EXCEPTION_HANDLING}
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
            /SUBSYSTEM:WINDOWS
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
            /SUBSYSTEM:WINDOWS
        )
    endif()
endif()
find_package(Microsoft.GSL CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Microsoft.GSL::GSL)

