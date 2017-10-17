cmake_minimum_required(VERSION 2.8.10)

project(cpp-benchmarks)

include(CTest)
include(CMakeDependentOption)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lib)

add_subdirectory(benchmarks)


