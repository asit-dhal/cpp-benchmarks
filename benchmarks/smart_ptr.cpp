#include <benchmark/benchmark.h>
#include <string>
#include <memory>

class A
{
public:
    A() = default;
    A(const A&) = delete;
    A& operator=(const A&) = delete;
    void set_a(int i) { a = i; }
    void set_b(int i) { b = i; }
    void set_c(std::string s) { c = s; }
    int get_a() const { return a; }
    int get_b() const { return b; }
    std::string get_c() const { return c; }
private:
    int a;
    int b;
    std::string c;
};

A* takeAndReturn(A *a)
{
    a->set_a(10);
    a->set_b(20);
    return a;
}

std::unique_ptr<A> takeAndReturn(std::unique_ptr<A> ptr)
{
    ptr->set_a(10);
    ptr->set_b(20);
    return ptr;
}

std::shared_ptr<A> takeAndReturn(std::shared_ptr<A> ptr)
{
    ptr->set_a(10);
    ptr->set_b(20);
    return ptr;
}

static void RawPointer_Creation(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        A *ob = new A();
        delete ob;
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void UniquePtr_Creation(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        std::unique_ptr<A> ob(new A());
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void SharedPtr_Creation(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        std::shared_ptr<A> ob(new A());
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void RawPointer_Access(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        A *ob = new A();
        state.ResumeTiming();
        ob->set_a(10);
        ob->set_b(20);
        ob->set_c(std::string("test"));
        state.PauseTiming();
        delete ob;
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void UniquePtr_Access(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        std::unique_ptr<A> ob(new A());
        state.ResumeTiming();
        ob->set_a(10);
        ob->set_b(20);
        ob->set_c(std::string("test"));
        state.PauseTiming();
        ob.release();
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void SharedPtr_Access(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        std::shared_ptr<A> ob(new A());
        state.ResumeTiming();
        ob->set_a(10);
        ob->set_b(20);
        ob->set_c(std::string("test"));
        state.PauseTiming();
        ob.reset();
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void RawPointer_Param(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        A *ob = new A();
        state.ResumeTiming();
        A *ob1 = takeAndReturn(ob);
        state.PauseTiming();
        delete ob;
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void UniquePtr_Param(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        std::unique_ptr<A> ob(new A());
        state.ResumeTiming();
        auto ob1 = takeAndReturn(std::move(ob));
        state.PauseTiming();
        ob1.release();
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

static void SharedPtr_Param(benchmark::State& state)
{
    auto benchmark = [&]()
    {
        state.PauseTiming();
        std::shared_ptr<A> ob(new A());
        state.ResumeTiming();
        auto ob1 = takeAndReturn(ob);
        state.PauseTiming();
        ob1.reset();
        state.ResumeTiming();
    };

    while (state.KeepRunning())
    {
        benchmark();
    }
}

BENCHMARK(RawPointer_Creation);
BENCHMARK(UniquePtr_Creation);
BENCHMARK(SharedPtr_Creation);
BENCHMARK(RawPointer_Access);
BENCHMARK(UniquePtr_Access);
BENCHMARK(SharedPtr_Access);
BENCHMARK(RawPointer_Param);
BENCHMARK(UniquePtr_Param);
BENCHMARK(SharedPtr_Param);
BENCHMARK_MAIN()
