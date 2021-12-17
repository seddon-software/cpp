////////////////////////////////////////////////////////////
//
//      Non Type Parameters
//
////////////////////////////////////////////////////////////


#include <iostream>
#include <string>
using namespace std;


template<int SIZE>
class Bitset
{
public:
    void print()
    {
        for(int i = 0; i < SIZE; i++)
        {
            cout << bits[i] << endl;
        }
    }

    void set(int i, int value)
    {
        if (i <  0)    throw "Underflow";
        if (i >= SIZE) throw "Overflow";
        bits[i] = value;
    }

private:
    int bits[SIZE];
};

/////

int main()
{
    Bitset<5> b5;

    try
    {
        b5.set(0, 1);
        b5.set(1, 2);
        b5.set(2, 4);
        b5.set(3, 8);
        b5.set(4, 16);
        b5.set(5, 32);
    }
    catch(const char* message)
    {
        cout << message << endl;
    }

    b5.print();

    return 0;
}
