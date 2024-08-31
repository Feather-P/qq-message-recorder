cmake_minimum_required(VERSION 3.5.0)
project(qq-message-recorder VERSION 0.1.0 LANGUAGES C CXX)

set(EXPORT_COMPILE_COMMANDS true)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

file (GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)#定义可执行文件输出目录
add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})#生成可执行文件

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE unofficial::sqlite3::sqlite3)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)#设置C++11标准

add_subdirectory(${PROJECT_SOURCE_DIR}/tests/sqlite-test1)