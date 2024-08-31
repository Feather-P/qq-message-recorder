cmake_minimum_required(VERSION 3.5.0)
project(qq-message-recorder VERSION 0.1.0 LANGUAGES C CXX)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

file (GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE unofficial::sqlite3::sqlite3)

target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_11)