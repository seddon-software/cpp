#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Card
{
private:
    char suit;
    char pip;
    bool played;
    int rank;
public:
    friend ostream& operator<<(ostream& os, Card& card);
//    Card& operator[](int i);
    Card(int rank);
    string id();
};

#endif