#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void PrettyPrintDouble_ToString(benchmark::State& state)
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

static void PrettyPrintDouble_StringStream(benchmark::State& state)
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

static void PrettyPrintDouble_OstringStream(benchmark::State& state)
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

BENCHMARK(PrettyPrintDouble_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(PrettyPrintDouble_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(PrettyPrintDouble_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);

BENCHMARK_MAIN()
