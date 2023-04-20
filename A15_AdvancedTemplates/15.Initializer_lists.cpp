////////////////////////////////////////////////////////////
//
//      initializer lists
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
using namespace std;

/*  The template "initializer_list" is used to allow a CTOR to accept a variable number of initialisers.
 *  Here we deine a wrapper class for a vector and pass in a group of doubles to initialise an instance
 *  of our class.  
 * 
 *  Note the use of the for loop requires a range to be define (begin() and end() methods).
 */

class MyVector
{
public:
	MyVector(initializer_list<double> list)
    {
        for(auto i = list.begin(); i != list.end(); ++i)
        {
        	array.push_back(*i * 10.0);
        }
    }
	auto begin() { return array.begin(); }
	auto end()   { return array.end(); } 
private:
  	vector<double> array;
};
  
int main()
{
	MyVector v{ 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8 };
	for(auto n : v) cout << n << ", ";
	cout << endl;
}

