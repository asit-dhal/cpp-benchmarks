#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void PrettyPrintInt_ToString(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            str += std::to_string(i);
        }
        return str;
    };
    
    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintInt_StringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintInt_OstringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}


BENCHMARK(PrettyPrintInt_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(PrettyPrintInt_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(PrettyPrintInt_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);


BENCHMARK_MAIN()
