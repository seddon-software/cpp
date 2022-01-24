#include <unistd.h>  // for sleep
#include <iostream>
#include <coroutine>

/*  
 *  Corotines allow you to run functions concurrently without recourse to threading.  In this example
 *  we create 3 coroutines and cycle between them.  The 3 coroutines differ in template parameter N;
 *  we define specializations for the Promise::yield_value() method:
 *          suspend_always Generator<1>::Promise::yield_value(int x);    // computes squares  
 *          suspend_always Generator<2>::Promise::yield_value(int x);    // computes cubes 
 *          suspend_always Generator<3>::Promise::yield_value(int x);    // computes quads
 */

using namespace std;

template<int N>
struct Generator 
{
    struct Promise;
    // compiler looks for promise_type
    using promise_type=Promise;
    coroutine_handle<Promise> h_;

    Generator(coroutine_handle<Promise> h): h_(h) {}

    ~Generator() 
    {
        if(h_) h_.destroy();
    }

    // get current value of coroutine
    int value() 
    {
        return h_.promise().val;
    }

    // advance coroutine past suspension
    bool next() 
    {
        h_.resume();
        return !h_.done();
    }

    struct Promise 
    {
        // current value of suspended coroutine
        int val;

        // called by compiler first thing to get coroutine result
        Generator get_return_object() 
        {
            return Generator<N>{coroutine_handle<Promise>::from_promise(*this)};
        }

        // called by compiler first time co_yield occurs
        suspend_always initial_suspend() 
        {
            return {};
        }

        // required for co_yield
        suspend_always yield_value(int x);  // specialized below

        // called by compiler for coroutine without return
        suspend_never return_void() 
        {
            return {};
        }

        // called by compiler last thing to await final result
        // coroutine cannot be resumed after this is called
        suspend_always final_suspend() 
        {
            return {};
        }
    };
};

// specializations of yield_value
template <>
suspend_always Generator<1>::Promise::yield_value(int x) 
{
    val=x*x;
    return {};
}
template <>
suspend_always Generator<2>::Promise::yield_value(int x) 
{
    val=x*x*x;
    return {};
}
template <>
suspend_always Generator<3>::Promise::yield_value(int x) 
{
    val=x*x*x*x;
    return {};
}

// define generic coroutine
template <int N>
Generator<N> generator(int n) 
{
    for(int i = 1; i <= n; ++i) {
        co_yield i;
    }
}

int main ()
{
    int n=10;

    // create 3 coroutines
    Generator<1> square = generator<1>(n);
    Generator<2> cube = generator<2>(n);
    Generator<3> quad = generator<3>(n);

    for(int i=1; i <= n; ++i) {
        sleep(1);
        square.next();
        cube.next();
        quad.next();
        cout << "---" << endl;
        cout << "square: " << square.value() << endl;
        cout << "cube:   " << cube.value() << endl;
        cout << "quad:   " << quad.value() << endl;
    }
}

