cmake_minimum_required (VERSION 2.8.12)

project (Google-Benchmark)

find_package(Threads REQUIRED)

file(GLOB SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
)

add_library(benchmark STATIC ${SOURCE_FILES})

target_include_directories(
	benchmark PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

find_library(LIBRT rt)
if(LIBRT)
	target_link_libraries(benchmark ${LIBRT} ${CMAKE_THREAD_LIBS_INIT})
endif()

set_target_properties(benchmark
	PROPERTIES POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(benchmark)
