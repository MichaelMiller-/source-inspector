## header-only library
add_library(math INTERFACE)
## alias
add_library(source-inspector::math ALIAS math)

target_include_directories(math INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

target_sources(math INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math/MatrixBase.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math/Vector2.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math/Vector4.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/math/VectorBase.h
)

## Dependencies
##
target_link_libraries(math INTERFACE enable_compiler_warnings)
target_link_libraries(math INTERFACE source-inspector::logging)

## Testing
##
include(CTest)
if (BUILD_TESTING) # option is created by CTest
    add_subdirectory(tests)
endif ()
