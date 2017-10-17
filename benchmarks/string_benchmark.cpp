#include <benchmark/benchmark.h>
#include <string>
#include <sstream>

static void BM_StringAppend(benchmark::State& state)
{
  	while (state.KeepRunning())
  	{
  		std::string str = "";
  		//str.reserve(100);
  		for(auto i = 0; i < 20; i++)
  		{
    		str += "one";
    	}
  	}
}
BENCHMARK(BM_StringAppend);

static void BM_StringstreamAppend(benchmark::State& state)
{

  	while (state.KeepRunning())
  	{
		std::stringstream ss;
    	for(auto i = 0; i < 20; i++)
  		{
    		ss << "one";
    	}
  	}
}
BENCHMARK(BM_StringstreamAppend);

static void BM_OstringstreamAppend(benchmark::State& state)
{

  	while (state.KeepRunning())
  	{
  		std::ostringstream ss;
    	for(auto i = 0; i < 20; i++)
  		{
    		ss << "one";
    	}
  	}
}
BENCHMARK(BM_OstringstreamAppend);



BENCHMARK_MAIN()
