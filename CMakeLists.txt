cmake_minimum_required(VERSION 2.8.10)

project(cpp-benchmarks)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CheckCXXCompilerFlag)
include(AddCXXCompilerFlag)
include(CXXFeatureCheck)

cxx_feature_check(STD_REGEX)
cxx_feature_check(GNU_POSIX_REGEX)
cxx_feature_check(POSIX_REGEX)

if(NOT HAVE_STD_REGEX AND NOT HAVE_GNU_POSIX_REGEX AND NOT HAVE_POSIX_REGEX)
    message(FATAL_ERROR "Failed to determine the source files for the regular expression backend")
endif()

cxx_feature_check(STEADY_CLOCK)


add_cxx_compiler_flag(-std=c++11)
if (NOT HAVE_CXX_FLAG_STD_CXX11)
    add_cxx_compiler_flag(-std=c++0x)
endif()

#add_cxx_compiler_flag(-Wall)
add_cxx_compiler_flag(-Wextra)
add_cxx_compiler_flag(-Wshadow)
add_cxx_compiler_flag(-Werror RELEASE)
add_cxx_compiler_flag(-Werror RELWITHDEBINFO)
add_cxx_compiler_flag(-Werror MINSIZEREL)
add_cxx_compiler_flag(-pedantic)
add_cxx_compiler_flag(-pedantic-errors)
add_cxx_compiler_flag(-Wshorten-64-to-32)
add_cxx_compiler_flag(-Wfloat-equal)
add_cxx_compiler_flag(-fstrict-aliasing)
add_cxx_compiler_flag(-flto)
add_cxx_compiler_flag(-O3)

if ("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
    find_program(GCC_AR gcc-ar)
    if (GCC_AR)
        set(CMAKE_AR ${GCC_AR})
    endif()
    find_program(GCC_RANLIB gcc-ranlib)
    if (GCC_RANLIB)
        set(CMAKE_RANLIB ${GCC_RANLIB})
     endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(lib)

add_subdirectory(benchmarks)
