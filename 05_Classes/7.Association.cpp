/*
 *  Association is where an object is linked to another object of a different class by way of usage.  In this example, the
 *  Person object is associated with the Car object.  We say
 *              A Person HAS A Car
 */

#include <string>
using namespace std;

class Car
{
public:
    string GetType();
    Car(const string& theType);
private:
    string type;
};

/////

class Person
{
public:
    Person(const string& theName);
    void Buy(Car& theCar);
    void Sell();
    string WhatCar();
private:
    string name;
    Car*   pCar;
};

/////

Car::Car(const string& theType)
:
    type(theType)
{
}

string Car::GetType()
{
    return type;
}

Person::Person(const string& theName)
:
    name(theName),
    pCar(0)
{
}

void Person::Buy(Car& theCar)
{
    pCar = &theCar;
}

void Person::Sell()
{
    if (pCar == 0) throw "No car to sell";
    pCar = 0;
}

string Person::WhatCar()
{
    return (*pCar).GetType();
}

/////

int main()
{
    Person john("John");
    Person mary("Mary");
    Car    peugeot("Peugeot");
    Car    porsche("Porsche");
    
    john.Buy(peugeot);
    mary.Buy(porsche); 
    john.Sell();

    string aCar;
    aCar = mary.WhatCar();
}


