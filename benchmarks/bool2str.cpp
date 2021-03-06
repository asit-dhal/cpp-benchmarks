#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>

static void Bool_ToString(benchmark::State& state)
{

    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            str += std::to_string(false);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Bool_StringStream(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            ss << false;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Bool_OstringStream(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            ss << false;
        }
        return ss.str();

    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);

    }
}

static void Bool_BoostLexicalCast(benchmark::State& state)
{
    auto bennchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            str += boost::lexical_cast<bool>(false);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(Bool_ToString)->RangeMultiplier(2)->Range(8, 8<<6);
BENCHMARK(Bool_BoostLexicalCast)->RangeMultiplier(2)->Range(8, 8<<6);
BENCHMARK(Bool_StringStream)->RangeMultiplier(2)->Range(8, 8<<6);
BENCHMARK(Bool_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6);

BENCHMARK_MAIN()
