#ifndef HEADER_H
#define HEADER_H

#include <algorithm>
#include <array>
#include <functional>
#include <map>
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef std::function<bool(int, int)> FN;
typedef std::function<bool()> FN0;
typedef std::tuple<std::string, int, FN0> T;

using Card = int;
typedef std::array<Card, 13> HAND;

int points();
int points(const HAND&);
int suitLength(char suit);
int suitLength(const HAND&, char suit);
extern HAND north;
extern HAND east;
extern HAND south;
extern HAND west;
extern std::map<int, int> partnershipPts;
extern std::vector<T> v;
extern int M;

std::tuple<HAND, HAND, HAND, HAND> deal();
void Register(const std::string& message, FN fn, std::vector<int> range1 = {0}, std::vector<int> range2 = {0});
void progress(int i);
std::vector<int> range(int lo, int hi);


#endif

