#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>
using namespace std;

/*  
 *  Coroutines were added to C++20.  Unfortunately the support is limited to very low level framework
 *  and the idea is to add high level library support, presumably in C++23.  At present coroutines are
 *  probably too complicated for common use and we should probably wait for what arrives with C++23.
 * 
 *  In the meantime we can study tutorials provided by David Mazières as recommended by cppreference.com:
 *      https://www.scs.stanford.edu/~dm/blog/c++-coroutines.html
 * 
 *  Alternatively, Lewis Baker has produced a very nice library:
 *      https://github.com/lewissbaker/cppcoro
 * 
 *  and some very good tutorials:
 *      https://lewissbaker.github.io/ 
 *
 *  Another useful set of tutorials (in 5 parts) by Gajendra Gulgulia starts with:
 *      https://ggulgulia.medium.com/painless-c-coroutines-part-1-ba90dd101adb
 *
 *  The examples given here are taken directly from David Mazières tutorials.
 */

struct ReturnObject {
    struct promise_type 
    {
        ReturnObject get_return_object() 
        { 
            cout << "get_return_object()" << endl;
            return {}; 
        }
        std::suspend_never initial_suspend() 
        { 
            cout << "initial_suspend()" << endl;
            return {}; 
        }
        std::suspend_never final_suspend() noexcept 
        { 
            cout << "final_suspend()" << endl;
            return {}; 
        }
        void unhandled_exception() {}
    };
};

struct Awaiter 
{
    std::coroutine_handle<> *hp_;
    /* constexpr */ bool await_ready() const noexcept 
    { 
        /* await_ready is an optimization. If it returns true, then co_await does not suspend the function. 
         * Of course, you could achieve the same effect in await_suspend, by resuming (or not suspending) 
         * the current coroutine, but before calling await_suspend, the compiler must bundle all 
         * state into the heap object referenced by the coroutine handle, which is potentially expensive.
         */

        cout << "await_ready()" << endl;
        return false; 
    }
    void await_suspend(std::coroutine_handle<> h) 
    { 
        // For simplicity, we store the coroutine handle in the Awaiter object every time 
        // await_suspend is called, but the handle does not change across invocations.
        cout << "await_suspend()" << endl;
        *hp_ = h; 
    }
    /* constexpr */ auto await_resume() const noexcept 
    {
        /* await_resume can return a value which will be the value of the co_await expression */
        cout << "await_resume()" << endl;
        return 99.99;
    }
};

ReturnObject counter(std::coroutine_handle<> *continuation_out)
{
    /* the return type of a coroutine (call it R) must be an object type with a nested type
     * R::promise_type.  R::promise_type must include a method R get_return_object() that returns
     * an instance of the outer type R.  The result of get_return_object() is the return value of 
     * the coroutine function, in this case counter().  R is often called a "future".
     */

    Awaiter a{continuation_out};
    for (unsigned i = 0;; ++i) 
    {
        auto response = co_await a;
        cout << "response from Awaiter::await_resume: " << response << endl;
        cout << "counter: " << i << endl;
    }
}

/*
 *  Now let’s look more specifically at what co_await does. When you evaluate the expression 
 *  co_await a, the compiler creates a coroutine handle and passes it to the method a.await_suspend
 *  (coroutine_handle).1 The type of a must support certain methods, and is sometimes referred to as 
 *  an “awaitable” object or an “awaiter.”
 */

int main()
{
    /* the new co_await operator ensures the current state of a function is bundled up somewhere 
     * on the heap and creates a callable object whose invocation continues execution of the 
     * current function. The callable object is of type std::coroutine_handle<>.  A coroutine
     * handle behaves a lot like a C pointer. It can be easily copied, but it doesn’t have a 
     * destructor to free the memory associated with coroutine state.  To avoid leaking memory, 
     * you must generally destroy coroutine state by calling the coroutine_handle::destroy method.
     */
    std::coroutine_handle<> h;
    counter(&h);
    for (int i = 0; i < 3; ++i) 
    {
        cout << "In main function" << endl;
        h();
    }
    h.destroy();
}
