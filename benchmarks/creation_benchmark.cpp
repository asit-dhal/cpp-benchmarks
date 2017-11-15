#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void String_Creation(benchmark::State& state)
{

    auto benchmark = []() -> std::string
    {
        std::string str = std::to_string(1);
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark();
        static_cast<void>(ret);
    }
}

static void StringStream_Creation(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::stringstream ss;
		ss << 1;
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark();
        static_cast<void>(ret);
    }
}

static void OstringStream_Creation(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::ostringstream ss;
		ss << 1;
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark();
        static_cast<void>(ret);

    }
}

BENCHMARK(String_Creation);
BENCHMARK(StringStream_Creation);
BENCHMARK(OstringStream_Creation);

BENCHMARK_MAIN()
