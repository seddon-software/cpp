
/*
 *  References are usually used to extend the scope of a variable in another function.  However, since they are aliases they can also be used to simplify notation (as in this example).
 */

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<vector<int>> myTwoDVector = {{10, 11, 12}, {20, 21, 22}, {30, 31, 32}};

    cout << myTwoDVector[1][2] * myTwoDVector[2][1] + 
            myTwoDVector[1][2] * myTwoDVector[1][2] + 
            myTwoDVector[2][1] * myTwoDVector[2][1] << endl; 

    // simplified notation using references
    auto& v12 = myTwoDVector[1][2];
    auto& v21 = myTwoDVector[2][1];

    cout << v12 * v21 + v12 * v12 + v21 * v21 << endl; 
}
