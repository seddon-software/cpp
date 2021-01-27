////////////////////////////////////////////////////////////
//
//      Test harness
//
////////////////////////////////////////////////////////////

#include "Point.h"

int main()
{
    Triangle p1;
    Triangle p2;
    Triangle p3;

    p1.Initialise(700, 100);
    p2.Initialise(100, 300);
    p3.Initialise(600, 600);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();

    p1.MoveBy(10, 10);
    p2.MoveBy(10, 10);
    p3.MoveBy(10, 10);

    p1.WhereAreYou();
    p2.WhereAreYou();
    p3.WhereAreYou();
}

