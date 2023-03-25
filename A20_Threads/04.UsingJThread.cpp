#include <iostream>
#include <exception>
#include <thread>

/*
 *  The fact that threads that are not joined or detached can cause a program to abort is problematical.
 *  C++20 introduces jthreads to vercome this problem.   A jthread object automatically calls join in its 
 *  destructor, so terminate never called and the program exits normally.
 * 
 *  As a minor point, note that the code is not thread safe, because we allow concurrent access to cout.
 */

using namespace std;

void terminateHandler()
{
    cerr << "terminate called (abort)" << endl;
}

int main()
{
    set_terminate (terminateHandler);
    cout << boolalpha;
    // C++20 introduces jthread which is better behaved than the C++11 thread
    jthread t{ []{ cout << "thread is here: " << endl; }};    
    cout << "t.joinable(): " << t.joinable() << endl;
    // jthread automatically calls join in its destructor, so terminate not called
}
