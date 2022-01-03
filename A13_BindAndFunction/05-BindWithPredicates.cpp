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
using namespace std;

/* This example uses sort from the Algorithm library:
 *
 * 		template< class RandomIt, class Compare >
 *		void sort( RandomIt first, RandomIt last, Compare comp );
 *
 */

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
	using namespace std::placeholders;

	// call Person::print(p1);
    for_each(list.begin(),
    		 list.end(),
    		 bind(&Person::print, _1));
    cout << " " << endl;
}

int main()
{
	using namespace std::placeholders;
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
         bind(
             less<int>(),
             bind(&Person::getAge, _1),
             bind(&Person::getAge, _2)
         )   
    );  
    printList(theList);
    
    // sort on name
    sort(theList.begin(), 
         theList.end(),
         bind(
             less<string>(),
             bind(&Person::getName, _1),
             bind(&Person::getName, _2)
         )   
     );  
    printList(theList);
        
    // sort on address
    sort(theList.begin(), 
         theList.end(),
         bind(
             less<string>(),
             bind(&Person::getAddress, _1),
             bind(&Person::getAddress, _2)
         )   
    );  
    printList(theList);
}

