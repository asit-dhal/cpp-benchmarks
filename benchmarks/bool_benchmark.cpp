#include "common.h"
#include <string>
#include <sstream>

static void PrettyPrintBool_ToString(benchmark::State& state)
{

    auto bennchmark = [](int count) -> std::string
    {
        std::string str = "";
        for(auto i = 0; i < count; i++)
        {
            str += std::to_string(false);
        }
        return str;
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintBool_StringStream(benchmark::State& state)
{
    auto bennchmark = [](int count) -> std::string
    {
        std::stringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << false;
        }
        return ss.str();
    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);
    }
}

static void PrettyPrintBool_OstringStream(benchmark::State& state)
{
    auto bennchmark = [](int count) -> std::string
    {
        std::ostringstream ss;
        for(auto i = 0; i < count; i++)
        {
            ss << false;
        }
        return ss.str();

    };

    while (state.KeepRunning())
    {
        std::string ret = bennchmark(state.range(0));
        static_cast<void>(ret);

    }
}

BENCHMARK(PrettyPrintBool_ToString)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintBool_StringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintBool_OstringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);

BENCHMARK_MAIN()
