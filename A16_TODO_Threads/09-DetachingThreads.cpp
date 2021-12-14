#include <iostream>
#include <thread>
#include <algorithm>
using namespace std;

class WorkerThread
{
public:
    void operator()()
    {
        cout <<"Worker Thread" << endl;
    }
};

int main()
{
	// we should either detach or join all threads spawned
    std::thread t{ WorkerThread() };
    t.detach();		// undefined behavior if this removed

    // Program will terminate as we haven't called either join or detach with the std::thread object.
    // Hence std::thread's object destructor will terminate the program
	std::this_thread::sleep_for(std::chrono::milliseconds(10*1000));
	cout << "main exiting ..." << endl;
	return 0;
}
