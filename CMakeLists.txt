cmake_minimum_required(VERSION 3.27)

project(computer)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(tests)