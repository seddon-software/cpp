////////////////////////////////////////////////////////////
//
//		Lambda
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>


using namespace std;
using namespace boost::lambda;

typedef boost::function<void(const string&)> FP;

void Print(const string& s)
{
	cout << s << endl;
}


int main()
{
	vector<string> list;
	list.push_back("Monday");
	list.push_back("Tuesday");
	list.push_back("Wednesday");
	list.push_back("Thursday");
	list.push_back("Friday");
	for_each(list.begin(), list.end(), Print);
	cout << "============" << endl;

	// same thing with lambdas
	FP fp = cout << _1 << '\n';   // can't use endl
	for_each(list.begin(), list.end(), fp);
	cout << "============" << endl;

	for_each(list.begin(), list.end(), cout << _1 << '\n');


	return 0;
}
