#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void String_StringAppend(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < count; i++)
        {
            str += "one";
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string str = benchmark(state.range(0));
        (void)str;
    }
}
BENCHMARK(String_StringAppend)->RangeMultiplier(2)->Range(8, 8<<10);

static void String_StringstreamAppend(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string str = benchmark(state.range(0));
        (void)str;
    }
}
BENCHMARK(String_StringstreamAppend)->RangeMultiplier(2)->Range(8, 8<<10);

static void String_OstringstreamAppend(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::ostringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string str = benchmark(state.range(0));
        (void)str;
    }
}
BENCHMARK(String_OstringstreamAppend)->RangeMultiplier(2)->Range(8, 8<<10);

BENCHMARK_MAIN()
