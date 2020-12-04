#include <iostream>
#include <vector>
using namespace std;

/*
 * SFINAE stands for "substitution failure is not an error"
 * This code compiles which means TEMPLATE 1 is OK
 * If you uncomment SECTION 2 the code fails - no substition for SECTION 2 available
 * If you uncomment TEMPLATE 2 the code compiles - substition for SECTION 2 is now available
 */

// TEMPLATE 1
template <typename T>
void show(typename T::iterator iter1, typename T::iterator iter2)
{
    while(iter1 != iter2)
	{
    	++iter1; cout << *iter1 << endl;
	}
}

// TEMPLATE 2
//template <typename T>
//void show(T a, T b)
//{
//    cout << a << "; " << b << endl;
//}

int main()
{
// SECTION 1
//	{
//		vector<int> v = {3, 4, 6, 7};
//		show<vector<int>>(v.begin(), v.end());
//	}

// SECTION 2
//	{
//		show<int>(16, 18);
//	}
}
