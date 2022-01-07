#include <iostream>
#include <deque>

using namespace std;

/*  
 * The STL has many collection classes.  Here is an example with a double ended queue 
 */

int main()
{
    // Create a deque containing integers
    deque<int> d = {8, 13, 21, 34};
 
    // push to beginning and end of deque
    d.push_front(5);
    d.push_back(55);
 
    // print deque
    for(int n : d) 
    {
        std::cout << n << ", ";
    }
    cout << endl;
}

