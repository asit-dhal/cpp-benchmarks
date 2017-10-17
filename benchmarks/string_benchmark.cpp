#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void String_StringAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < 200000; i++)
        {
            str += "one";
        }
        return str;
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(String_StringAppend);

static void String_StringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < 200000; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(String_StringstreamAppend);

static void String_OstringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::ostringstream ss;
        for(auto i = 0; i < 200000; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(String_OstringstreamAppend);



BENCHMARK_MAIN()
