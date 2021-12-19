#include <iostream>
#include <thread>
using namespace std;


int main()
{
	int x = 5;
	int y = 8;
    thread myThread(
    	[&x, &y]()  // capture by reference
		{
			cout << "Hello from the thread" << endl;
			x *= 2; y*= 2;
			cout << "Thread: x = " << x << ",y = " << y << endl;
		}
	);
	// uncomment to see unsynchronized behaviour
	// cout << "Main: x = " << x << ",y = " << y << endl;
    myThread.join();  // synchronize to ensure references are alive in thread code
	cout << "Main: x = " << x << ",y = " << y << endl;
}
