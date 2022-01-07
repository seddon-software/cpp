#include <concepts>
#include <type_traits>
#include <iostream>
using namespace std;



template <int N, typename T = int> requires (N > 0 && N < 100) 
void f()
{
	cout << N << " is between 0 and 100" << endl;
}

template <int N, typename T = int> requires (N > 100 && N <= 1000) 
void f()
{
	std::cout << N << " is between 100 and 1000" << std::endl;
}


int main()
{
    f<44>();
    f<440>();
}
