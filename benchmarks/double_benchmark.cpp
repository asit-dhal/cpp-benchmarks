#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void Double_StringAppend(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        std::string str = "";
        for(double i = 0; i < 20000.0; i++)
        {
            str += std::to_string(i);
        }
    }
}
BENCHMARK(Double_StringAppend);

static void Double_StringstreamAppend(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        std::stringstream ss;
        for(double i = 0; i < 20000.0; i++)
        {
            ss << i;
        }
    }
}
BENCHMARK(Double_StringstreamAppend);

static void Double_OstringstreamAppend(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        std::ostringstream ss;
        for(double i = 0; i < 20000.0; i++)
        {
            ss << i;
        }
    }
}
BENCHMARK(Double_OstringstreamAppend);



BENCHMARK_MAIN()
