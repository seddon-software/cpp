#ifndef HAND_H
#define HAND_H

using namespace std;

#include <vector>
#include <array>
#include <numeric>
#include <random>
#include <algorithm>
#include <iostream>
#include <initializer_list>

class Hand
{
private:
    vector<Card> hand;
public:
    Hand(initializer_list<Card> l) : hand(l) {}
    Card& operator[](int i);
    void dealHand();
};

#endif
