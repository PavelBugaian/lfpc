cmake_minimum_required(VERSION 3.15)
project(lfpc)

set(CMAKE_CXX_STANDARD 20)
set(GCC_COVERAGE_LINK_FLAGS    "-lm")

add_executable(lfpc lab2/main.c)
target_link_libraries(lfpc m)
