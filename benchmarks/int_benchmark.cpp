#include "common.h"
#include <string>
#include <sstream>

static void PrettyPrintInt_ToString(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < count; i++)
        {
            str += std::to_string(i);
        }
        return str;
    };
    
    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintInt_StringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintInt_OstringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::ostringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << i;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = benchmark(state.range(0));
        static_cast<void>(ret);
    }
}


BENCHMARK(PrettyPrintInt_ToString)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintInt_StringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintInt_OstringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);


BENCHMARK_MAIN()
