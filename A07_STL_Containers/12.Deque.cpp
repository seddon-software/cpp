#include <iostream>
#include <deque>

using namespace std;

/*
 *  The deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion 
 *  at both its beginning and its end.  The elements of a deque are not stored contiguously: typical 
 * 
 *  This example shows how to use a deque. 
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

