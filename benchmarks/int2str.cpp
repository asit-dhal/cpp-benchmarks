#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

#include <boost/lexical_cast.hpp>

static void Int_ToString(benchmark::State& state)
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

static void Int_StringStream(benchmark::State& state)
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

static void Int_OstringStream(benchmark::State& state)
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

static void Int_BoostLexicalCast(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            str += boost::lexical_cast< std::string >(i);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(Int_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Int_BoostLexicalCast)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Int_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Int_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);


BENCHMARK_MAIN()
