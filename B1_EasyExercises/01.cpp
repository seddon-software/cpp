/*
 *  Write a program that inputs a 4 digit year and then
 *  calculates whether or not it is a leap year.
 */


#include <iostream>
using namespace std;


int isLeap(int year)
{
    bool result = false;
    if(year %   4 == 0) result = true;
    if(year % 100 == 0) result = false;
    if(year % 400 == 0) result = true;
    return result;
}

int main()
{
    cout << "Enter a year: ";
    cout.flush();

    int year;
    cin >> year;

    if(isLeap(year))
        cout << year << " is a leap year";
    else
        cout << year << " is NOT a leap year";
}

