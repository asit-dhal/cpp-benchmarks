#include "common.h"
#include <string>
#include <sstream>

static void PrettyPrintDouble_ToString(benchmark::State& state)
{
    auto bennchmark = [](int count) -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < count; i++)
        {
            str += std::to_string(static_cast<double>(i));
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
    auto bennchmark = [](int count) -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << static_cast<double>(i);
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
        std::ostringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << static_cast<double>(i);
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

BENCHMARK(PrettyPrintDouble_ToString)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintDouble_StringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintDouble_OstringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);

BENCHMARK_MAIN()
