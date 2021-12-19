#include <iostream>
#include <exception>
#include <thread>

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
    jthread t{ []{ cout << "thread is here" << endl; }};    
    cout << "t.joinable(): " << t.joinable() << endl;
    // jthread automatically calls join in its destructor, so terminate not called
}
