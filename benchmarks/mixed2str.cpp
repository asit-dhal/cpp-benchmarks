#include <benchmark/benchmark.h>
#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>
#include <algorithm>

static void Mixed_ToString(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();

		for(auto i = 0; i < count; i++)
		{
			str += std::to_string(10);
			str += "a simple string";
			str += std::to_string(10.3);
		}
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Mixed_StringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::stringstream ss;
        state.ResumeTiming();

		for(auto i = 0; i < count; i++)
		{
			ss << 10;
			ss << "a simple string";
			ss << 10.3;
		}
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Mixed_OstringStream(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::ostringstream ss;
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
		{
			ss << 10;
			ss << "a simple string";
			ss << 10.3;
		}
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void Mixed_BoostLexicalCast(benchmark::State& state)
{
    auto benchmark = [&](int count) -> std::string
    {
        state.PauseTiming();
        std::string str = "";
        state.ResumeTiming();

        for(auto i = 0; i < count; i++)
        {
            str += boost::lexical_cast<std::string>(10);
            str += "a simple string";
            str += boost::lexical_cast<std::string>(10.3);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(Mixed_ToString)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Mixed_BoostLexicalCast)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Mixed_StringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);
BENCHMARK(Mixed_OstringStream)->RangeMultiplier(2)->Range(8, 8<<6)->Arg(10000000);

BENCHMARK_MAIN()
