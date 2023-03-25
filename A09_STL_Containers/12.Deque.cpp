/*
 *  The deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion 
 *  at both its beginning and its end.  The elements of a deque are not stored contiguously: typical 
 *  implementations are considerab;le more complex than a vector.  Hence the deque is less efficient than
 *  the vector.  
 * 
 *  This example shows how to use a deque. 
 */


#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Create a deque containing integers
    deque<int> d = {8, 13, 21, 34};
 
    // push to front of deque
    d.push_front(5);
    d.push_front(3);
    d.push_front(2);
    d.push_front(1);
    d.push_front(1);

    // push to back of deque
    d.push_back(55);
    d.push_back(89);
    d.push_back(144);
 
    // print deque
    for(int n : d) 
    {
        cout << n << ", ";
    }
    cout << endl;
}

