find_package(Threads REQUIRED)

add_library(benchmark::benchmark ALIAS benchmark)

add_executable(string_benchmark common.h string_benchmark.cpp)
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
