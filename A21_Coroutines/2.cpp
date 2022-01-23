// g++ -ocoroutine -g -O0 -Wall -Werror -Wextra
// -std=c++20 -fcoroutines -fno-exceptions coroutine.cpp

#include <stdio.h>
#include <coroutine>

using namespace std;

template<int N>
struct Generator {
  struct Promise;

// compiler looks for promise_type
  using promise_type=Promise;
  coroutine_handle<Promise> h_;

  Generator(coroutine_handle<Promise> h): h_(h) {}

  ~Generator() {
    if(h_)
      h_.destroy();
  }

// get current value of coroutine
  int value() {
    return h_.promise().val;
  }

// advance coroutine past suspension
  bool next() {
    h_.resume();
    return !h_.done();
  }

  struct Promise {
// current value of suspended coroutine
    int val;

// called by compiler first thing to get coroutine result
    Generator get_return_object() {
      return Generator<N>{coroutine_handle<Promise>::from_promise(*this)};
    }

// called by compiler first time co_yield occurs
    suspend_always initial_suspend() {
      return {};
    }

// required for co_yield
    // suspend_always yield_value(int x) {
    //   val=x;
    //   return {};
    // }

// called by compiler for coroutine without return
    suspend_never return_void() {
      return {};
    }

// called by compiler last thing to await final result
// coroutine cannot be resumed after this is called
    suspend_always final_suspend() {
      return {};
    }
  };
};
template <int N>
Generator<N>::Promise::suspend_always yield_value(int x) {
    val=x;
    return {};
}

template <int N>
Generator<N> generator0(int n) {

  for(int i = 0; i < n; ++i) {
    co_yield i;
  }

}

int main ()
{
  int n=10;

  Generator<0> myCoroutineResult = generator0(n);

  for(int i=0; i < n; ++i) {
    myCoroutineResult.next();
    printf("---\n");
    printf("%d \n", myCoroutineResult.value());
  }
}

