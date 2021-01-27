#include <iostream>
using namespace std;

auto f(int i);	// prottype return type is unknown at this time


// auto can be used if return type can be deduced by the compiler
auto f(int i)
{
  if (i == 1)
    return i;         // return type deduced here
  else
    return f(i-1)+i;  // ok to call it now
}


int main()
{
    cout << f(4) << endl;
}
