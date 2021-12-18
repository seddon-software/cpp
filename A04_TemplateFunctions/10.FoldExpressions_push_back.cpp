#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
template<typename T, typename... Args>
void PushBack(vector<T>& v, Args&&... args)
{
    (v.push_back(args), ...);   // fold using comma operator
}

int main()
{
    vector<int> v;
	PushBack(v, 1, 1, 2, 3, 5, 8, 13, 21);
	
	for (auto &i : v)
		cout << i << ", ";
	cout << endl;
}
