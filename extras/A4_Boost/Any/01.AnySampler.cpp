////////////////////////////////////////////////////////////
//
//		Any-Sampler
//
////////////////////////////////////////////////////////////

// A ValueType is CopyConstructible
// A ValueType is optionally Assignable
// The strong exception-safety guarantee is required for all forms of assignment
// The destructor for a ValueType upholds the no-throw exception-safety guarantee

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <boost/any.hpp>
using namespace std;

typedef std::list<boost::any> LIST_OF_ANY;
using boost::any_cast;


void DetermineType(boost::any& operand)
{
	try 
	{
		if(any_cast<int>(operand)) cout << "int" << endl;
	}
	catch(const boost::bad_any_cast &) {}

	if(operand.type() == typeid(double)) 
		cout << "double" << endl;
		
	if(operand.type() == typeid(string)) 
		cout << "string" << endl;
		
	if(operand.type() == typeid(const char*))
		cout << "const char*" << endl;
}

/////

int main()
{
// declarations of sample data
	int i = 100;
	double d = 4.53;
	string myString("mystring");
	const char* myCharArray = "charArray";
	
// build list of mixed types
	LIST_OF_ANY myList;
	myList.push_back(i);
	myList.push_back(d);
	myList.push_back(myString);
	myList.push_back(myCharArray);
	
// iterate through list to determine type
	for_each(myList.begin(), myList.end(), DetermineType);

	return 0;
}
