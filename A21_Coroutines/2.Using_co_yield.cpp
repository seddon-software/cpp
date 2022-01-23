#include <coroutine>
#include <exception>
#include <iostream>
using namespace std;

struct ReturnObject {
    // nested type
    struct promise_type {
        unsigned value_;

        // mandatory method
        ReturnObject get_return_object() 
        {
            // return a brace initialized ReturnObject
            return 
            {
                // initialize the solitary data member of the returned ReturnObject 
               .h_ = coroutine_handle<promise_type>::from_promise(*this)
            };
        }
        // more mandatory methods
        suspend_never initial_suspend() 
        { 
            cout << "initial_suspend()" << endl;
            return {};  // return by brace initialization
        } // this never suspends coroutine

        suspend_never final_suspend() noexcept 
        { 
            cout << "final_suspend()" << endl;
            return {};  // return by brace initialization
        } // this never suspends coroutine

        void unhandled_exception() {}

        suspend_always yield_value(unsigned value) 
        {
            cout << "yield_value(" << value << ")" << endl;
            value_ = value;
            cout << "about to suspend coroutine" << endl;
            return {};      // return by brace initialization
        } // this always suspends coroutine
    };
    /*  
     *  We store the coroutine handle inside the return object.  A coroutine_handle<T> for any type T 
     *  can be implicitly converted to a coroutine_handle<void> and either type can be invoked to resume
     *  the coroutine with the same effect.  We will store a coroutine_handle<promise_type> handle, 
     *  because this allows you to retrieve the coroutine handle using the static method 
     *  std::coroutine_handle::from_promise() - see above
     */
    std::coroutine_handle<promise_type> h_;
};

ReturnObject counter()
{
    for (unsigned i = 0;; i += 10)
        co_yield i;       // co yield i => co_await promise.yield_value(i)
}

int main()
{
    /*  
     *  counter returns to coroutine handle.  Subsequently calling this handle resumes execution 
     *  of the coroutine
     */
    auto h = counter().h_;

    // coroutine_handle<promise_type>.promise() is a method in the coroutine library
    auto &promise = h.promise();
    for (int i = 0; i < 3; ++i) 
    {
        cout << "counter: " << promise.value_ << endl; // promise.value_ gets set in yield_value()
        h();            // resume execution of coroutine
    }
    h.destroy();
}
