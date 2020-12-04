#include <iostream>
#include <vector>
#include <list>

/*
 * This example show how to use a template-template parameter for a function template
 * In the example we pass an STL container to a template as
 * a template-template parameter.  Note that vector and list templates
 * always take 2 template parameters (the allocater parameter is often defaulted)
 */

using namespace std;

template <template<typename,typename> class V, class T, class A>
void f(V<T,A> v)
{
	for(auto a:v)
	{
		cout << a << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v1 = {2,4,6};
	list<string> v2 = {"aaa", "bbb", "ccc"};

	f(v1);
	f(v2);
}
