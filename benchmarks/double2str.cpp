#include <benchmark/benchmark.h>
#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>

static void Double_ToString(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            state.PauseTiming();
            auto d = static_cast<double>(i);
            state.ResumeTiming();
            str += std::to_string(d);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Double_StringStream(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            state.PauseTiming();
            auto d = static_cast<double>(i);
            state.ResumeTiming();
            ss << d;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);

    }
}

static void Double_OstringStream(benchmark::State& state)
{
    auto bennchmark = [&](int count)-> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            state.PauseTiming();
            auto d = static_cast<double>(i);
            state.ResumeTiming();
            ss << d;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Double_BoostLexicalCast(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            state.PauseTiming();
            auto d = static_cast<double>(i);
            state.ResumeTiming();
            str += boost::lexical_cast<double>(d);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(Double_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Double_BoostLexicalCast)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Double_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Double_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);

BENCHMARK_MAIN()
