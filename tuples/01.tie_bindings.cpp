#include <iostream>
#include <tuple>
#include <string>

using namespace std; 

/*  
 */


auto get_data()
{
    int a;
    double b;
    string c;
    cout << "Enter data (int, double, string): " << flush;
    cin >> a >> b >> c;
    return tuple{a, b, c};      // return 3 items
}  


int main() 
{
    int x; 
    double y; 
    string z;
    std::tie (x, y, z) = get_data(); // unpack the tied tuple  
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
} 

