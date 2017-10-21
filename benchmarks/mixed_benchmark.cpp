#include "common.h"
#include <string>
#include <sstream>
#include <algorithm>

static void PrettyPrintMixed_ToString(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::string str = "";
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

static void PrettyPrintMixed_StringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::stringstream ss;
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

static void PrettyPrintMixed_OstringStream(benchmark::State& state)
{
    auto benchmark = [](int count) -> std::string
    {
        std::ostringstream ss;
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

BENCHMARK(PrettyPrintMixed_ToString)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintMixed_StringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);
BENCHMARK(PrettyPrintMixed_OstringStream)->Apply(SmallArguments)->Apply(MediumArguments)->Apply(LargeArguments);

BENCHMARK_MAIN()
