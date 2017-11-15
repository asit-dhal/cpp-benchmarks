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

add_executable(string_benchmark string_benchmark.cpp)
target_link_libraries(string_benchmark
  benchmark::benchmark
)

add_executable(int_benchmark int_benchmark.cpp)
target_link_libraries(int_benchmark
  benchmark::benchmark
)

add_executable(double_benchmark double_benchmark.cpp)
target_link_libraries(double_benchmark
  benchmark::benchmark
)

add_executable(bool_benchmark bool_benchmark.cpp)
target_link_libraries(bool_benchmark
  benchmark::benchmark
)

add_executable(mixed_benchmark mixed_benchmark.cpp)
target_link_libraries(mixed_benchmark
  benchmark::benchmark
)

add_executable(vector_array_benchmark vector_array_benchmark.cpp)
target_link_libraries(vector_array_benchmark
  benchmark::benchmark
)

add_executable(creation_benchmark creation_benchmark.cpp)
target_link_libraries(creation_benchmark
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
