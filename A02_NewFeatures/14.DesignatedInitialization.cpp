#include <iostream>

/*
 *  Aggregation can now be initialized using the {} syntax shown below.  The idea is to make the
 *  initialization more succinct and readable for C like entities.  However, note, you can only 
 *  use this form of initialization if the aggregate has NO private attributes.
 */

struct Point  // everything is public (necessary condition to use designated initialization)
{
    int x;
    int y;
};

struct Point3D  // everything is public (necessary condition to use designated initialization)
{
    int x;
    int y;
    int z;
};

using namespace std;

int main()
{
    Point p1 {.x = 20, .y = 30};
    cout << p1.x << ", " << p1.y << endl;

    // Point p2 {.y = 30, .x = 20};    // fails to compile (order incorrect)
    // cout << p2.x << ", " << p2.y << endl;
    
    Point3D q {.x = 20, .z = 40};        // q.y gets set to 0
    cout << q.x << ", " << q.y << ", " << q.z << endl;
}