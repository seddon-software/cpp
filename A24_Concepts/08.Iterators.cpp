#include <concepts>
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>
using namespace std;


template<std::forward_iterator I>
void advance(I& iter, int n)
{
    for(int i = 0; i < n; i++) iter++;
    cout << "forward_iterator" << endl;
}

template<std::bidirectional_iterator I>
void advance(I& iter, int n)
{
    for(int i = 0; i < n; i++) iter++;
    std::cout << "bidirectional_iterator" << endl;
}

template<std::random_access_iterator I>
void advance(I& iter, int n)
{
    for(int i = 0; i < n; i++) iter++;
    cout << "random_access_iterator" << endl;
}

int main()
{
    forward_list singlyLinkedList{10, 20, 30, 40, 50};
    forward_list<int>::iterator forward = singlyLinkedList.begin();
    advance(forward, 2);
    cout << *forward << endl;
    
    list<int> doublyLinkedList{10, 20, 30, 40, 50};
    list<int>::iterator forwardAndbackwards = doublyLinkedList.begin();
    advance(forwardAndbackwards, 4);
    cout << *forwardAndbackwards << endl;

    vector<int> dynamicArray{10, 20, 30, 40, 50};
    vector<int>::iterator randomAccessIterator = dynamicArray.begin();
    advance(randomAccessIterator, 3);
    cout << *randomAccessIterator << endl;
}
