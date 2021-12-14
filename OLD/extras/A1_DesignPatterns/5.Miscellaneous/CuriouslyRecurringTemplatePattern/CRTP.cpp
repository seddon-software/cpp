////////////////////////////////////////////////////////////
//
//		NVI
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;


template <typename T>
class Count
{
private:
	static int alive;
public:
    Count() { ++alive; }
    ~Count() { --alive; }
    static int getAlive() { return alive; }
};
template <typename T>
int Count<T>::alive = 0;


class One : public Count<One>
{

};

class Two : public Count<Two>
{

};

/////

int main()
{
	One a, b, c;
	Two t[10];

	cout << a.getAlive() << endl;
	cout << Two::getAlive() << endl;
}
