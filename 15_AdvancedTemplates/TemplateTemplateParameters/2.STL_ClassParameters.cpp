#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

/*
 * This example show how to use a template-template parameter for a class template
 */

template <template<typename, typename> class C, class T, class A=allocator<T>>
class builder
{
public:
	builder(C<T,A> c, string name) : name(name), container(c) {}
	void print() const
	{
		cout << name << endl;
		for(const auto& item:container)
		{
			cout << item << " ";
		}
		cout << endl << endl;
	}
private:
	string name;
    C<T,A> container;
};

int main()
{
	vector<int> v = {2,4,6};
	list<string> s = {"Monday", "Tuesday", "Wednesday"};

	builder<vector, int> m1(v, "vector of int");
    m1.print();
	builder<list, string> m2(s, "list of string");
    m2.print();
}
