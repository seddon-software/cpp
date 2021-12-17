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
    for (int i = 0; i < 10; i++)
    {
        array[i] = 2 * i;
    }
}

int Array::operator[] (int index)
{
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
        catch(const range_error& e)
        {
            cout << e.what() << endl;
        }
    }
}


