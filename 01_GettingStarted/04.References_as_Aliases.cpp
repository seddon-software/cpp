
/*
 *
 *
 */

#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<vector<int>> myTwoDVector = {{10, 11, 12}, {20, 21, 22}, {30, 31, 32}};

    auto& v12 = myTwoDVector[1][2];
    auto& v21 = myTwoDVector[2][1];

    cout << myTwoDVector[1][2] * myTwoDVector[2][1] + 
            myTwoDVector[1][2] * myTwoDVector[1][2] + 
            myTwoDVector[2][1] * myTwoDVector[2][1] << endl; 
    cout << v12 * v21 + v12 * v12 + v21 * v21 << endl; 
}
