////////////////////////////////////////////////////////////
//
//      Point header file
//
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Point
{
public:
    void Initialise(int, int);
    void MoveBy(int, int);
    void WhereAreYou();
private:
    int x;
    int y;
};

