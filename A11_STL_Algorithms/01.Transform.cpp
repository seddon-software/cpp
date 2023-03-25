#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

/* 
 *  In this example we use the transform algorithm to generate a new sequence from the original, by
 *  applying a function to each item in the original sequence.  This is very similar to Python's
 *  comprehension construct.
 */

int main()
{
	{
        int z{11};
		vector v = { 2, 4, 6, 8, z };
		vector<int> v2(v.size());
		transform(v.begin(), v.end(),
				  v2.begin(),
				  [](int x){ return x * x * x; });
		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	{
        double z{11.0};
		vector v = { 2.5, 3.5, 4.5, 5.5, 6.5, z };
		vector<double> v2(v.size());

		transform(v.begin(), v.end(),
				  v2.begin(),
				  [](double x){ return x * x;});
		copy(v2.begin(), v2.end(), ostream_iterator<double>(cout, " "));
		cout << endl;
	}
}

