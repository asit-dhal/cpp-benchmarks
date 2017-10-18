#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void Int_StringAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < 200000; i++)
        {
            str += std::to_string(i);
        }
        return str;
    };
    
    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Int_StringAppend);

static void Int_StringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < 20000; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Int_StringstreamAppend);

static void Int_OstringstreamAppend(benchmark::State& state)
{
    auto benchmark = []() -> std::string
    {
        std::ostringstream ss;
        for(auto i = 0; i < 20000; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}
BENCHMARK(Int_OstringstreamAppend);

BENCHMARK_MAIN()
