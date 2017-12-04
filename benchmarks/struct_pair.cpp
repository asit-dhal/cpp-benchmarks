#include <benchmark/benchmark.h>
#include <boost/lexical_cast.hpp>
#include <string>
#include <sstream>
#include <tuple>

struct A
{
    int a;
    float b;
    std::string c;
};


A func(A ob)
{
    ob.b = 2.43f;
    return ob;
}

std::tuple<int, float, std::string> func2(std::tuple<int, float, std::string> ob)
{
    std::get<0>(ob) = 3;
    std::get<1>(ob) = 5.3f;
    std::get<2>(ob) = std::string("asit dhal");
    return ob;
}

static void struct_creation(benchmark::State& state)
{
    auto bennchmark = [&]()
    {
        A ob;
        ob.a = 1;
        ob.b = 2.3f;
        ob.c = "asit";
    };

    while (state.KeepRunning())
    {
        bennchmark();
    }
}

static void tuple_creation(benchmark::State& state)
{
    auto bennchmark = [&]()
    {
         std::tuple<int, float, std::string> p;
         std::get<0>(p) = 2;
         std::get<1>(p) = 4.3f;
         std::get<2>(p) = std::string("asit kumar");
    };

    while (state.KeepRunning())
    {
        bennchmark();

    }
}

static void struct_args(benchmark::State& state)
{
    auto bennchmark = [&]()
    {
        state.PauseTiming();
        A ob;
        ob.a = 1;
        ob.b = 2.3f;
        ob.c = "asit";
        state.ResumeTiming();
        A ob2 = func(ob);
    };

    while (state.KeepRunning())
    {
        bennchmark();
    }
}

static void tuple_args(benchmark::State& state)
{
    auto bennchmark = [&]()
    {
        state.PauseTiming();
        auto p = std::make_tuple<int, float, std::string>(1, 2.3f, std::string("asit"));
        state.ResumeTiming();
        auto p2 = func2(p);
    };

    while (state.KeepRunning())
    {
        bennchmark();
    }
}

BENCHMARK(struct_creation);
BENCHMARK(tuple_creation);
BENCHMARK(struct_args);
BENCHMARK(tuple_args);

BENCHMARK_MAIN()
