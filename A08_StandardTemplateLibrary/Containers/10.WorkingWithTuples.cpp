#include <vector>
#include <string>
#include <tuple>
#include <iostream>
using namespace std;

void makingTuples()
{
	int x = 1;
	int y = 2;
	int z = 3;
	auto t = make_tuple(x, y, z); // uses copies
	get<0>(t)++;
	get<1>(t)++;
	get<2>(t)++;
	// x, y, z unchanged
	cout << "using make_tuple: " << x << " " << y << " " << z << endl;
}

void tieingTuples()
{
	int x = 1;
	int y = 2;
	int z = 3;
	auto t = tie(x, y, z); // uses references
	get<0>(t)++;
	get<1>(t)++;
	get<2>(t)++;
	// x, y, z are changed
	cout << "using tie: " << x << " " << y << " " << z << endl;
}

void concatinatingTuples()
{
	auto t1 = make_tuple(3, 4.4, "five");
	auto t2 = make_tuple(6, 7.7, "eight");
	auto t = tuple_cat(t1, t2);
	cout << "using tuple_cat: ";
	cout << get<0>(t) << " ";
	cout << get<1>(t) << " ";
	cout << get<2>(t) << " ";
	cout << get<3>(t) << " ";
	cout << get<4>(t) << " ";
	cout << get<5>(t) << " ";
	cout << endl;
}

void unpackingTuples()
{
	tuple<int,int,int> tuple_of_ints(5, 6, 7);
	auto mixed_tuple = make_tuple(25, string("hello"), tuple_of_ints);
	int i;
	tuple<int,int,int> t;
	string s;
	cout << "unpacking tuple using tie: ";
	tie(i, s, t) = mixed_tuple;
	cout << i << " ";
	cout << s << " ";
	cout << get<0>(t) << " ";
	cout << get<1>(t) << " ";
	cout << get<2>(t) << " ";
	cout << endl;
}

int main()
{
	makingTuples();
	tieingTuples();
	concatinatingTuples();
	unpackingTuples();
}
