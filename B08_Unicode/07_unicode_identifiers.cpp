#include <iostream>
#include <cmath>
using namespace std;

/*
 *  A restricted set of Unicode characters are allowed in identifiers.  In this example, we are using Greek 
 *  letters to formulate mathematical expressions.  This facility is somewhat controversial but is nevertheless 
 *  now part of the C++ standard.
 */

void convert_to_cartesian(double r, double θ, double 𝜙)
{
    double x = r*sin(𝜙)*cos(θ);
    double y = r*sin(𝜙)*sin(θ);
    double z = r*cos(𝜙);
    cout << "x=" << x << ", y=" << y << ", z=" << z << endl;
}

int main()
{
    double π = 4 * atan(1.0);
    convert_to_cartesian(5, 3*π/5, π/3);
}
