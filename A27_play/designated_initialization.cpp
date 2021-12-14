#include <iostream>

struct Point
{
    int x;
    int y;
};

struct Point3D
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