#include <benchmark/benchmark.h>
#include <array>
#include <vector>
#include <algorithm>
#include <iterator>

static void VectorInsert(benchmark::State& state)
{
    auto benchmark = [](int count)
    {
        std::vector<int> v;
        for(auto i = 0; i < count; i++)
        {
            v.push_back(i);
        }
    };

    while (state.KeepRunning())
    {
        benchmark(state.range(0));
    }
}

static void VectorInsertWithReserve(benchmark::State& state)
{
    auto benchmark = [](int count)
    {
        std::vector<int> v;
        v.reserve(count);
        for(auto i = 0; i < count; i++)
        {
            v.push_back(i);
        }
    };

    while (state.KeepRunning())
    {
        benchmark(state.range(0));
    }
}


static void ArrayInsert(benchmark::State& state)
{
    auto benchmark = [](int count)
    {
        std::array<int, 200> v;
        for(auto i = 0; i < count; i++)
        {
            v[i] = i;
        }
    };

    while (state.KeepRunning())
    {
        benchmark(state.range(0));
    }
}

static void VectorSort(benchmark::State& state)
{

    while (state.KeepRunning())
    {
        state.PauseTiming();
        std::vector<int> v;
        auto init = [&]()
        {
            v.reserve(state.range(0));
            for(auto i = 0; i < state.range(0); i++)
            {
                v.push_back(i%2 == 0 ? (state.range(0)-i) : i);
            }
        };

        auto benchmark = [&]()
        {
            std::sort(v.begin(), v.end());
        };
        init();

        state.ResumeTiming();
        benchmark();
    }
}

static void ArraySort(benchmark::State& state)
{
    while (state.KeepRunning())
    {
        state.PauseTiming();
        std::array<int, 200> v;
        auto init = [&]()
        {
            for(auto i = 0; i < state.range(0); i++)
            {
                v[i] = i%2 == 0 ? (state.range(0)-i) : i;
            }
        };

        auto benchmark = [&]()
        {
            std::sort(v.begin(), v.end());
        };
        init();
        state.ResumeTiming();
        benchmark();
    }
}


BENCHMARK(VectorInsert)->Arg(200);
BENCHMARK(VectorInsertWithReserve)->Arg(200);
BENCHMARK(ArrayInsert)->Arg(200);
BENCHMARK(VectorSort)->Arg(200);
BENCHMARK(ArraySort)->Arg(200);

BENCHMARK_MAIN()
