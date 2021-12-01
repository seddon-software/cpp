//////////////////////////////////////////////////////////////////////
//
//		Generators
//
//////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


class FibonacciGenerator
{
private:
    int state;
    int n1, n2;
public:
    FibonacciGenerator() : state(0), n1(0), n2(1) {}

    int operator()() {
        if(state == 0)
        {
            state = 1;
            return n1;
        }
        else
        {
			int temp = n1 + n2;
			n1 = n2;
			n2 = temp;
			return n1;
		}
	}
};


int main()
{
	FibonacciGenerator g;
	for(int i = 0; i < 20; i++)
	{
		cout << g() << endl;
	}
	cout << endl;
    return 0;
}
