find_package(Threads REQUIRED)

add_library(benchmark::benchmark ALIAS benchmark)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.58.0)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message("Failed to find boost in the system, build may fail")
endif()

add_executable(string_concat string_concat.cpp)
target_link_libraries(string_concat
  benchmark::benchmark
)

add_executable(int2str int2str.cpp)
target_link_libraries(int2str
  benchmark::benchmark
)

add_executable(double2str double2str.cpp)
target_link_libraries(double2str
  benchmark::benchmark
)

add_executable(bool2str bool2str.cpp)
target_link_libraries(bool2str
  benchmark::benchmark
)

add_executable(mixed2str mixed2str.cpp)
target_link_libraries(mixed2str
  benchmark::benchmark
)

add_executable(vector_array vector_array.cpp)
target_link_libraries(vector_array
  benchmark::benchmark
)

add_executable(creation creation.cpp)
target_link_libraries(creation
  benchmark::benchmark
)

add_executable(str2int str2int.cpp)
target_link_libraries(str2int
  benchmark::benchmark
)

add_executable(str2double str2double.cpp)
target_link_libraries(str2double
  benchmark::benchmark
)
