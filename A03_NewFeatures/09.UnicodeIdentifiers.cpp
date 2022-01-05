#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*  Inline with C++ supporting Unicode, it is now possible to use Unicode identifiers in code.
 *  Not everyone is happy with this facility, but it does allow, for instance the use of greek
 *  letters familiar to Mathematicians when defining formulae.
 * 
 *  The actaul code in this example is unimportant (it performs a rotatation in 3D space), but 
 *  rather the use of the variables θ and 𝜙 and the constant π in the code.
 */

using V = vector<double>;
using M = vector<vector<double>>;

auto zip(V t1, V t2) -> vector<pair<double,double>>
{
    vector<pair<double,double>> zipped;
    for(unsigned i = 0; i < t1.size(); i++)
    {
        pair p = pair(t1[i], t2[i]);
        zipped.push_back(p);
    }
    return zipped;
}

V rotate(auto& cartesians, double θ, double 𝜙)
{
    M m = {V{sin(θ)*cos(𝜙), cos(θ)*cos(𝜙), -sin(𝜙)},
           V{sin(θ)*sin(𝜙), cos(θ)*sin(𝜙),  cos(𝜙)}, 
           V{       cos(θ),       -sin(θ),      0 }};
    V v(3);
    for(unsigned i = 0; i < 3; i++)
    {
        for(auto a : zip(cartesians,m[i]))
        {
            v[i] += a.first*a.second;
        }
    }
    return v;
}

int main()
{
    auto π = 4 * atan(1.0);
    vector cartesians{10.0, 10.0, 10.0};
    V v = rotate(cartesians, π/3, π/4);
    for(auto d : v)
    {
        cout << d << ",";
    }
    cout << endl;
}
