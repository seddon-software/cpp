#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Create a deque containing integers
    deque<int> d = {8, 13, 21, 34};
 
    // push to beginning and end of deque
    d.push_front(5);
    d.push_back(55);
 
    // print deque
    for(int n : d) {
        std::cout << n << ", ";
    }
    cout << endl;
}

