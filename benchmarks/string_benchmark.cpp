#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void BM_StringAppend(benchmark::State& state)
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
BENCHMARK(BM_StringAppend);

static void BM_StringstreamAppend(benchmark::State& state)
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
BENCHMARK(BM_StringstreamAppend);

static void BM_OstringstreamAppend(benchmark::State& state)
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
BENCHMARK(BM_OstringstreamAppend);



BENCHMARK_MAIN()
