/*
 *  A program can throw any type of exception on detecting a problem.  However
 *  it is recommended that you only throw excepitions that are derived from the excption class.
 *  A number of exception classes are predefined in the header <stdexcept>.  In this example
 *  we overload the [] operator for our class and throw a "range_error" when the array index is 
 *  out of bounds.  
 * 
 *  Note that the base class "exception" constructor does not accept any parameters, but all
 *  classes derived from "exception" do take a "string" parameter.  THat is why its best to
 *  use a derived exception class. 
 */

#include <iostream>
#include <stdexcept>
using namespace std;
	
class Array
{
private:
    int array[10];
public:
    Array();
    int operator[] (int);
};

Array::Array ()
{
    // fill the array with even numbers
    for (int i = 0; i < 10; i++)
    {
        array[i] = 2 * i;
    }
}

int Array::operator[] (int index)
{
    // throw an exception if index out of bounds
    if (index <   0) throw range_error("array index underflow");
    if (index >= 10) throw range_error("array index overflow");

    return array[index];
}

/////


int main()
{
	Array a;
    int index;
    while(true)
    {
        try
        {
            cout << "Enter array index: ";
            cin  >> index;
            cout << a[index] << endl;
        }
        catch(const range_error& e)     // don't catch by copy (inefficient until c++20)
        {
            cout << e.what() << endl;   // what() is a virtual method
        }
    }
}


