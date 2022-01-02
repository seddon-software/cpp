#include <iostream>
#include <algorithm>
using namespace std;

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
    
	// use an initializer with the loop
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

    using namespace std::string_literals;  // for operator""s 
    for (auto str = "Hello World"s; auto c: str)  // string literal type = std::string not const char* 
    {
        cout << c << ".";
    }
    cout << endl;
}
