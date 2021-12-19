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
    thread t{[]{ cout << "thread is here" << endl; }};    
    cout << "t.joinable(): " << t.joinable() << endl;
    // we must either call join or detach on the thread
    // failure to do so will cause the program to terminate (hence the handler)
    //   try uncommenting the following to get the program to exit without aborting
    // t.join();
    //t.detach();
}
