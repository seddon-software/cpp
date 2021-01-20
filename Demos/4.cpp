#include <iostream>
#include <cstring>
using namespace std;

class Person
{
public:
    Person() 
    {
        text1 = new char[1];
        text2 = new char[1];
        *text1 = 0;
        *text2 = 0;
    }
    Person(const char* t1, const char* t2)
    {
        text1 = new char[strlen(t1)+1];
        text2 = new char[strlen(t2)+1];
        strcpy(text1, t1);
        strcpy(text2, t2);
    }
    ~Person()
    {
        cout << this << endl;
        delete[] text1;
        delete[] text2;
    }
    void operator=(const Person& rhs)
    {
        if(text1) delete[] text1;
        if(text2) delete[] text2;
        text1 = new char[strlen(rhs.text1)];
        text2 = new char[strlen(rhs.text2)];
        strcpy(text1, rhs.text1);
        strcpy(text2, rhs.text2);
    }
private:
    char* text1;
    char* text2;
};

int main()
{
    Person* ptr = new Person[3];
    ptr[0] = Person("John", "Black");
    ptr[1] = Person("Susan", "Green");
    ptr[2] = Person("Chris", "White");
    delete ptr;
}