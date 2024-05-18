## header-only library
add_library(logging)
## alias
add_library(source-inspector::logging ALIAS logging)

target_sources(logging
        PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/ConsoleLogger.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/FileLogger.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/Logger.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/logging.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/LogManager.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/LogManagerImplementation.h
        ${CMAKE_CURRENT_LIST_DIR}/include/logging/LogMessage.h
        ${CMAKE_CURRENT_LIST_DIR}/src/ConsoleLogger.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/FileLogger.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/Logger.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/LogManager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/LogManagerImplementation.cpp
)
target_include_directories(logging
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/logging
)

## Dependencies
##
target_link_libraries(logging INTERFACE enable_compiler_warnings)

## Testing
##
include(CTest)
if (BUILD_TESTING) # option is created by CTest
    add_subdirectory(tests)
endif ()
