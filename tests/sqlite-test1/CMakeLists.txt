set(TEST_PROGRAM_NAME sqlite-test1)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

add_executable(${TEST_PROGRAM_NAME} sqlite-test1.cpp)

target_link_libraries(${TEST_PROGRAM_NAME} PRIVATE unofficial::sqlite3::sqlite3)