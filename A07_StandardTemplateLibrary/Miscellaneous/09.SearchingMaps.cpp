////////////////////////////////////////////////////////////
//
//      Map
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Point
{
friend ostream& operator<<(ostream& os, const Point& p);
public:
	Point(int x, int y) : x(x), y(y) {}
	Point() : x(0), y(0) {}
	bool operator<(const Point& rhs) const
	{
		int lhsSquare = x * x + y * y;
		int rhsSquare = rhs.x * rhs.x + rhs.y * rhs.y;
		return lhsSquare < rhsSquare;
	}

private:
	int x;
	int y;
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << "[" << p.x << "," << p.y << "]";
	return os;
}

map<Point, string, less<Point>> mymap;


class Query
{
public:
	Query(string name) : name(name) {}
	bool operator() (const pair<Point, string>& p)
	{
		return (p.second == name);
	}
private:
	string name;
};

int main()
{
	// define set of right angled Points
	mymap[Point(8,15)] = "8-15-17";
	mymap[Point(5,12)] = "5-12-13";
	mymap[Point(3,4)]  = "3-4-5";
	mymap[Point(9,40)] = "9-40-41";
	mymap[Point(7,24)] = "7-24-25";

	// search for Point using functor
	auto i = find_if(mymap.begin(), mymap.end(), Query("7-24-25"));
	if(i != mymap.end())
		cout << "Found: " << i->first << "," << i->second << endl;
	else
		cout << "Entry not found" << endl;


	// search for Point using lambda
	i = find_if(mymap.begin(), mymap.end(), 
	            [](const auto& p){ return (p.second == "7-24-25"); });
	if(i != mymap.end())
		cout << "Found: " << i->first << "," << i->second << endl;
	else
		cout << "Entry not found" << endl;


	// iterate over map
	for(i = mymap.begin(); i != mymap.end(); ++i)
	{
		cout << i->first << "," << i->second << endl;
	}

	// iterate over map using new for loop
	for(auto& item: mymap)
	{
		cout << item.first << "," << item.second << endl;
	}
}
