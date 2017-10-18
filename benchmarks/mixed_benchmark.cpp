#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <algorithm>

static void Mixed_StringAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::string str = "";
        str += std::to_string(10);
        str += "a simple string";
        str += std::to_string(10.3);
        return str;
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Mixed_StringAppend)->ComputeStatistics("max",
  [](const std::vector<double>& v) -> double {
    return *(std::max_element(std::begin(v), std::end(v)));
  })->Arg(512);

static void Mixed_StringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::stringstream ss;
        ss << 10;
        ss << "a simple string";
        ss << 10.3;
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Mixed_StringstreamAppend);

static void Mixed_OstringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::ostringstream ss;
        ss << 10;
        ss << "a simple string";
        ss << 10.3;
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Mixed_OstringstreamAppend);

BENCHMARK_MAIN()
