cmake_minimum_required(VERSION 2.8.10)

project(cpp-benchmarks)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)

add_subdirectory(benchmarks)
