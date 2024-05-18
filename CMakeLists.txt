cmake_minimum_required(VERSION 3.8)
include(projectVersion.cmake)
project(source-inspector VERSION ${projectVersion})

include(CMakePrintHelpers)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(PreventInSourceBuilds)
include(CompilerWarnings)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

## Link to this 'library' in order to use the warnings specified in CompilerWarnings.cmake
##
add_library(enable_compiler_warnings INTERFACE)
enable_warnings(enable_compiler_warnings)

# TODO: find a good solution for this approch
# if (WIN32)
#    set(PLATFORM_INCLUDE "includesWindows.h")
#elseif (APPLE)
#    set(PLATFORM_INCLUDE "includesMac.h")
#else ()
#    set(PLATFORM_INCLUDE "includesLinux.h")
#endif ()

# TODO: find all usages and remove them
set(BUILD_CXX_LANGUAGE_PACKAGE ON CACHE BOOL "Add C and C++ support to the indexer.")
set(BUILD_JAVA_LANGUAGE_PACKAGE OFF CACHE BOOL "Add Java support to the indexer.")
set(BUILD_PYTHON_LANGUAGE_PACKAGE OFF CACHE BOOL "Add Python support to the indexer.")


include(CTest)
if (BUILD_TESTING) # option is created by CTest
    enable_testing()
endif ()

# TODO: is this extra directory level really helpful?
add_subdirectory(src)
