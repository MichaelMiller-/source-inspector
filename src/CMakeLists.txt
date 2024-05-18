# TODO: naming

add_subdirectory(app)
add_subdirectory(external)
add_subdirectory(indexer)
add_subdirectory(logging)
add_subdirectory(math)

# TODO: should be a runtime plugin or incorporate into project, therefore the target cannot be optional BUILD_PYTHON_LANGUAGE_PACKAGE
# add_subdirectory(lib_java)
# TODO: should be a runtime plugin or incorporate into project, therefore the target cannot be optional BUILD_JAVA_LANGUAGE_PACKAGE
# add_subdirectory(lib_python)

## Tests
##
if (BUILD_TESTING) # option is created by CTest
    # TODO enable: add_subdirectory(tests)
endif ()
