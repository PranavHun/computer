cmake_minimum_required(VERSION 3.20)

set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})
project(computer)

add_subdirectory(src)
add_subdirectory(tests)