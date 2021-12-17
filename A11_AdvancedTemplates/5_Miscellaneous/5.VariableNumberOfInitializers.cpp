////////////////////////////////////////////////////////////
//
//      initializer lists
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MyVector
{
	MyVector(initializer_list<double> list)
    {
        for(auto i = list.begin(); i != list.end(); ++i)
        {
        	array.push_back(*i);
        }
    }
  	vector<double> array;
};
  
int main()
{
	MyVector v{ 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8 };
	for(auto n : v.array) cout << n << ", ";
	cout << endl;
}

