#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void Bool_StringAppend(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        std::string str = "";
        for(auto i = 0; i < 20000; i++)
        {

            str += std::to_string(false);
        }
    }
}
BENCHMARK(Bool_StringAppend);

static void Bool_StringstreamAppend(benchmark::State& state)
{

    while (state.KeepRunning())
    {
        std::stringstream ss;
        for(auto i = 0; i < 20000; i++)
        {
            ss << false;
        }
    }
}
BENCHMARK(Bool_StringstreamAppend);

static void Bool_OstringstreamAppend(benchmark::State& state)
{

    while (state.KeepRunning())
    {
        std::ostringstream ss;
        for(auto i = 0; i < 20000; i++)
        {
            ss << false;
        }
    }
}
BENCHMARK(Bool_OstringstreamAppend);



BENCHMARK_MAIN()
