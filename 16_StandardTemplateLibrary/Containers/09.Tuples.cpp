#include <tuple>
#include <string>
#include <iostream>
using namespace std;


template<class Tuple, int N>
class TuplePrinter
{
	void print(const Tuple& t)
	{
		cout << get<N>(t) << ",";
	}
};


int main()
{
	tuple<string, int> t1, t2;
	t1 = tuple<string, int>("abc<->abc", 6);
	t2 = make_tuple("xyz", 54);
	string s("---");
	auto t = tuple_cat(t1, t2, tie(s));
	s = "123456";
	cout << get<4>(t) << endl;
	cout << "end";
	string x1, x3, x5;
	int x2, x4;
	tie(x1, x2, x3, x4, x5) = t;
	for(size_t i = 0; i < tuple_size<decltype(t)>::value; i++)
	{
		cout << get<0>(t) << endl;
	}
}
