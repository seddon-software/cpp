#include <iostream>
#include <utility>
#include <array>
#include <vector>
#include <cmath>
using namespace std;

template <typename T1, typename T2>
auto zip(T1 t1, T2 t2) ->vector<pair<T1, T2>>
{
    vector<pair<T1, T2>> zipped;
    for(int i = 0; i < 3; i++)
    {
        auto p = pair(t1[i], t2[i]);
//        zipped.push_back(p);
    }
    return zipped;
}
void rotate(auto& cartesians, double θ, double 𝜙)
{
    using A = array<double, 3>;
    using M = array<array<double, 3>, 3>;
    M m = {A{sin(θ)*cos(𝜙), cos(θ)*cos(𝜙), -sin(𝜙)},
           A{sin(θ)*sin(𝜙), cos(θ)*sin(𝜙),  cos(𝜙)}, 
           A{       cos(θ),       -sin(θ),      0 }};
    for(auto row: m)
    {
        vector<double> transformedCartesians;
        auto zipped = zip(row, cartesians);
        for(auto p : zipped)
        {
            transformedCartesians.push_back(1.6);
            cout << endl;
        }
    }
    //  mattrix = np.array(matrix)
    //  return matrix @ vector     # note: @ denote matrix multiplication 
} 
int main()
{
    auto π = 4 * atan(1.0);
    cout << π << endl; 

    array cartesians{10.0, 10.0, 10.0};
    rotate(cartesians, π/3, π/4);
    //print(rotate(np.array([10, 10, 10]), π/3, π/4))
}