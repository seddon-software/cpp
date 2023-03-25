#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

/*  
 *  An interesting variation on the previous example is to pass a lambda to async and store all
 *  the prospective calculations in a vector.  To do this we first create a vector of asyncs:
 *          	vector<future<int>> v;
 *
 *  and then proceed to add lambdas to the vector.  These asyncs will begin executing immediately they
 *  are added to the vector.  Later we can retrieve all the results using get() in a for loop.
 */

int fetch_int(int lo, int hi)
{
	int sum = 0;
	for (int i = lo; i < hi; i++)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		sum += i*i;
	}
	return sum;
}

int main()
{
	vector<future<int>> v;
	v.push_back(async([]{ return fetch_int(1,10); }));
	v.push_back(async([]{ return fetch_int(11,40); }));
	v.push_back(async([]{ return fetch_int(41,100); }));

	int result = 0;
	for (auto& e : v)
	{
		result += e.get();
		cout << result << " ..." << endl;
	}
	cout << "sum of squares = " << result << endl;
}
