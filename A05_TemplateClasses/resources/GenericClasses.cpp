////////////////////////////////////////////////////////////
//
//      Classes using templates
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class ArrayOfInts
{
private:
    int array[3];
public:
    ArrayOfInts(int);
    void Print();
};

ArrayOfInts::ArrayOfInts(int x)
{
    for(int i = 0; i < 3; i++)
        array[i] = x;
}

void ArrayOfInts::Print()
{
    for(int i = 0; i < 3; i++)
        cout << array[i] << "\t";
    cout << endl;
}

/////

class ArrayOfDoubles
{
private:
    double array[3];
public:
    ArrayOfDoubles(double);
    void Print();
};

ArrayOfDoubles::ArrayOfDoubles(double x)
{
    for(int i = 0; i < 3; i++)
        array[i] = x;
}

void ArrayOfDoubles::Print()
{
    for(int i = 0; i < 3; i++)
        cout << array[i] << "\t";
    cout << endl;
}

/////


int main()
{
	ArrayOfInts a(15);
	ArrayOfDoubles b(27.96);

    a.Print();
    b.Print();
}

