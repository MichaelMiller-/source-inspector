add_library(cppsqlite3)
## alias
add_library(external::cppsqlite3 ALIAS cppsqlite3)

target_sources(cppsqlite3 PRIVATE CppSQLite3.cpp)

target_include_directories(cppsqlite3 PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>)

## Dependencies
##
find_package(unofficial-sqlite3 CONFIG REQUIRED)

target_link_libraries(cppsqlite3 PRIVATE unofficial::sqlite3::sqlite3)

