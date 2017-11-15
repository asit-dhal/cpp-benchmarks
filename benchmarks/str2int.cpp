#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>

static void Str2Int_std(benchmark::State& state)
{
    auto benchmark = [&]() -> int
    {
        state.PauseTiming();
        std::string str = "232";
        state.ResumeTiming();
        int a = std::stoi(str);
        return a;
    };

    while (state.KeepRunning())
    {
        int ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Int_Stringstream(benchmark::State& state)
{
    auto benchmark = [&]() -> int
    {
        state.PauseTiming();
        std::string str = "232";
        state.ResumeTiming();
        std::stringstream ss(str);
        int a =0;
        ss >> a;
        return a;
    };

    while (state.KeepRunning())
    {
        int ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Int_Itringstream(benchmark::State& state)
{
    auto benchmark = [&]() -> int
    {
        state.PauseTiming();
        std::string str = "232";
        state.ResumeTiming();
        std::istringstream iss(str);
        int a =0;
        iss >> a;
        return a;

    };

    while (state.KeepRunning())
    {
        int ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Int_BoostLexicalCast(benchmark::State& state)
{
    auto benchmark = [&]() -> int
    {
        state.PauseTiming();
        std::string str = "232";
        state.ResumeTiming();
        int a = boost::lexical_cast<int>(str);
        return a;
    };

    while (state.KeepRunning())
    {
        int ret = benchmark();
        static_cast<void>(ret);
    }
}

BENCHMARK(Str2Int_std);
BENCHMARK(Str2Int_Stringstream);
BENCHMARK(Str2Int_Itringstream);
BENCHMARK(Str2Int_BoostLexicalCast);

BENCHMARK_MAIN()
