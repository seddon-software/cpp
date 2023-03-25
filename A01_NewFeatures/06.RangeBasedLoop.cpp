#include <iostream>
#include <algorithm>
using namespace std;

/*  
 *  The C++11 range based loop is a major addition to C++.  It makes looping through the values in a 
 *  collection a breeze.  C++20 added the capability of providing an initialization statement before
 *  the start of the loop.
 */

void print(int a[], int size)
{
	copy(a, a + size, ostream_iterator<int>(cout, ","));
	cout << endl;
}

int a[6] = { 2, 3, 5, 7, 11, 13 };

int main()
{
	// capture by value so you don't change the underlying array
	for(auto x: a)
	{
		x = x * 10;		// changes made to temporaries
	}
	print(a, 6);
	
	// capture by reference so you can change the underlying array
	for(auto& x: a)		
	{
		x = x * 10;
	}
	print(a, 6);
    
	// use an initializer with the loop (C++20)
	for (auto vec = std::vector{1, 2, 3, 4, 5, 6}; auto v : vec) 
    {
        std::cout << v << " ";
    }
    cout << endl;

	// same again
    for (auto initList = {1, 2, 3, 4, 5, 6}; auto n : initList) 
    {
        cout << n * n << " ";
    }
    cout << endl;

    for (auto str = "Hello World"s; auto c: str)  // "Hello World"s is string literal type
                                                  //  = std::string not const char* 
    {
        cout << c << ".";
    }
    cout << endl;
}
