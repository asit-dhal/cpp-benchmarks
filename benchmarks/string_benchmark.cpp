#include "common.h"
#include <string>
#include <sstream>

static void PrettyPrintString_ToString(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::string str = "";
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

static void PrettyPrintString_StringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::stringstream ss;
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

static void PrettyPrintString_OstringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::ostringstream ss;
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

BENCHMARK(PrettyPrintString_ToString)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintString_StringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintString_OstringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);

BENCHMARK_MAIN()
