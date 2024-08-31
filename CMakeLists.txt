cmake_minimum_required(VERSION 3.5.0)
project(qq-message-recorder VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)

find_package(unofficial-sqlite3 CONFIG REQUIRED)

add_executable(qq-message-recorder main.cpp)

target_link_libraries(qq-message-recorder PRIVATE unofficial::sqlite3::sqlite3)