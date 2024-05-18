find_package(Catch2 CONFIG REQUIRED)

function(test filename)
    set(target_name test.${filename})
    add_executable(${target_name})

    target_sources(${target_name} PRIVATE ${filename}.cpp)

    target_link_libraries(${target_name} PRIVATE Catch2::Catch2 Catch2::Catch2WithMain)
    target_link_libraries(${target_name} PRIVATE source-inspector::math)
    target_link_libraries(${target_name} PRIVATE source-inspector::logging)
    target_link_libraries(${target_name} PRIVATE enable_compiler_warnings)

    add_test(
            NAME ${target_name}
            COMMAND $<TARGET_FILE:${target_name}>)
endfunction()

## unit tests via catch (alphabetical order)
##
test("math.Vector2")
