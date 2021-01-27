#include <iostream>
#include <string>

using namespace std;
 
template<typename ...Args>
void Print(Args&&... args) {
    (cout <<  ... <<  forward<Args>(args));  // perfect forwarding
    cout << endl;
}

int main()
{
    Print("hello", " world ", 3.14159, ", ", 270.0);
}
