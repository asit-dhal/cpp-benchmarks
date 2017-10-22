#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

#define LARGE_STRING "Use of static_assert in the body of a function will not lead to a substitution failure in template instantiation, thus making it impossible to create a trait that can distinguish between the intended and unintended use of the function. This paper discusses the current situation and possible solutions to allow custom diagnostics while at the same time enabling traits to test for usability of a function. The suggestion of this paper is to extend the syntax of deleted functions to allow custom diagnostics."

static void SmallString_ToString(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            str += "one";
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void SmallString_StringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void SmallString_OstringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            ss << "one";
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void LargeString_ToString(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            str += LARGE_STRING;
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void LargeString_StringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            ss << LARGE_STRING;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void LargeString_OstringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();
        for(auto i = 0; i < count; i++)
        {
            ss << LARGE_STRING;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(SmallString_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(SmallString_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(SmallString_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);

BENCHMARK(LargeString_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(1000000);
BENCHMARK(LargeString_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(1000000);
BENCHMARK(LargeString_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(1000000);

BENCHMARK_MAIN()
