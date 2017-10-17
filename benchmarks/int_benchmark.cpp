#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void BM_StringAppend(benchmark::State& state)
{
  	while (state.KeepRunning())
  	{
  		std::string str = "";
  		for(auto i = 0; i < 20000; i++)
  		{
    		str += std::to_string(i);
    	}
  	}
}
BENCHMARK(BM_StringAppend);

static void BM_StringstreamAppend(benchmark::State& state)
{

  	while (state.KeepRunning())
  	{
		std::stringstream ss;
    	for(auto i = 0; i < 20000; i++)
  		{
    		ss << i;
    	}
  	}
}
BENCHMARK(BM_StringstreamAppend);

static void BM_OstringstreamAppend(benchmark::State& state)
{

  	while (state.KeepRunning())
  	{
  		std::ostringstream ss;
    	for(auto i = 0; i < 20000; i++)
  		{
    		ss << i;
    	}
  	}
}
BENCHMARK(BM_OstringstreamAppend);



BENCHMARK_MAIN()
