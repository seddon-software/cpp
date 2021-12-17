#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

template<typename T, typename... Args>
void PushBack(vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);   // fold using comma operator
}

template <typename T, typename... Args>
void Transform(T v0, Args&& ... args)
{
	// like a Python comprehension
	vector<T> v;
	(v.push_back(args), ...);
	vector<T> v2(v.size());
	transform(v.begin(), v.end(),
			v2.begin(),
			[](T x){ return x * x * x; });
	copy(v2.begin(), v2.end(), ostream_iterator<T>(cout, " "));
	cout << endl;
}

int main()
{
	Transform<int>(2, 4, 6, 8, 10, 12);
	Transform<double>(2.5, 3.5, 4.5, 5.5, 6.5);
}

