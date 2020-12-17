#include <iostream>
#include <thread>
using namespace std;


int main()
{
	int x = 5;
	int y = 8;
    std::thread myThread(
    		[x, y]()
		{
    			cout << x * y << endl;
		}
	);
    myThread.join();
}
