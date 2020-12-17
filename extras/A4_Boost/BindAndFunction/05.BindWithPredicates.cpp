////////////////////////////////////////////////////////////
//
//		Bind and Function
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <boost/bind.hpp>
using namespace std;


class Person
{
private:
	string name;
	string address;
	int age;
public:
	Person(string name, string address, int age)
		:name(name), address(address), age(age) {}
	
	string getName()    const	{ return name; }
	string getAddress() const	{ return address; }
	int    getAge()     const	{ return age; }
	void print() const
	{
		cout << "[" << name << "," 
		            << address << "," 
		            << age << "]" << endl;
	}
};


//////

void printList(vector<Person> list)
{
	// call Person::print(p1);
    for_each(list.begin(), list.end(),
    		boost::bind(&Person::print, _1));
    cout << endl;
}

int main()
{
	vector<Person> theList;
	
    theList.push_back(Person("Smith", "London", 43));	
    theList.push_back(Person("Jones", "Cardiff", 51));	
    theList.push_back(Person("Lee",   "New York", 24));	

    // sort(begin, end, comparator)
    //     where comparator is:
    // less<int>(Person::getAge(p1),Person::getAge(p2));

    // sort on age
    sort(theList.begin(), 
         theList.end(),
         boost::bind(
             less<int>(),
             boost::bind(&Person::getAge, _1),  
             boost::bind(&Person::getAge, _2)
         )   
    );  
    printList(theList);
    
    // sort on name
    sort(theList.begin(), 
         theList.end(),
         boost::bind(
             less<string>(),
             boost::bind(&Person::getName, _1),  
             boost::bind(&Person::getName, _2)
         )   
     );  
    printList(theList);
        
    // sort on address
    sort(theList.begin(), 
         theList.end(),
         boost::bind(
             less<string>(),
             boost::bind(&Person::getAddress, _1),  
             boost::bind(&Person::getAddress, _2)
         )   
    );  
    printList(theList);
}

