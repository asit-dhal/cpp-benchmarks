#include <benchmark/benchmark.h>
#include <string>
#include <sstream>
#include <boost/lexical_cast.hpp>

static void Str2Double_std(benchmark::State& state)
{
    auto benchmark = [&]() -> double
    {
        state.PauseTiming();
        std::string str = "232.45";
        state.ResumeTiming();
        int a = std::stod(str);
        return a;
    };

    while (state.KeepRunning())
    {
        double ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Double_Stringstream(benchmark::State& state)
{
    auto benchmark = [&]() -> double
    {
        state.PauseTiming();
        std::string str = "232.45";
        state.ResumeTiming();
        std::stringstream ss(str);
        double a =0;
        ss >> a;
        return a;
    };

    while (state.KeepRunning())
    {
        double ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Double_Itringstream(benchmark::State& state)
{
    auto benchmark = [&]() -> double
    {
        state.PauseTiming();
        std::string str = "232.45";
        state.ResumeTiming();
        std::istringstream iss(str);
        double a =0;
        iss >> a;
        return a;

    };

    while (state.KeepRunning())
    {
        double ret = benchmark();
        static_cast<void>(ret);
    }
}

static void Str2Double_BoostLexicalCast(benchmark::State& state)
{
    auto benchmark = [&]() -> double
    {
        state.PauseTiming();
        std::string str = "232.45";
        state.ResumeTiming();
        double a = boost::lexical_cast<double>(str);
        return a;
    };

    while (state.KeepRunning())
    {
        double ret = benchmark();
        static_cast<void>(ret);
    }
}

BENCHMARK(Str2Double_std);
BENCHMARK(Str2Double_Stringstream);
BENCHMARK(Str2Double_Itringstream);
BENCHMARK(Str2Double_BoostLexicalCast);

BENCHMARK_MAIN()
