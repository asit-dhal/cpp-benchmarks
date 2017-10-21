#pragma once

#include <benchmark/benchmark.h>


static void SmallArguments(benchmark::internal::Benchmark* b)
{
    for (int i = 2; i <= 1024; i+= 32)
    {
        b->Args({i,});
    }
}

static void MediumArguments(benchmark::internal::Benchmark* b)
{
    for (int i = 1025; i <= 10024; i+= 1000)
    {
        b->Args({i,});
    }
}

static void LargeArguments(benchmark::internal::Benchmark* b)
{
    for (int i = 10025; i <= 64000; i+= 5000)
    {
        b->Args({i,});
    }
}
