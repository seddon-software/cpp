/*
 *  The solution to our dilemma is to introduce a functor (stateful function).  A functor is an object
 *  that behaves like a function pointer, but being an object rather than a function pointer, it can possess
 *  attributes.  We can take advantage of this to pass the salary as an attribute to the functor.
 * 
 *  Any class that overloads the () operator is a functor class.  Here we define a class defining operator()
 *  that provides the callback for find_if.  Recall the callback gets passed a single parameter; in this
 *  case a "pair" object containg the item's key and value.
 * 
 *  So we create and object of the functor class (Query), pass in the required salary to its constructor and 
 *  use this value in the callback: 
 *              bool operator()(const pair<string, int>& item)
 *              {
 *                  return item.second > salary;
 *              }
 * 
 *  You'll notice the operator() code is almost identical to the callback function in the previous example.
 *  We can create as many functor objects as we like, one for each salary we wish to query.  The functor
 *  object is passed to find_if instead of a function pointer:
 *              Query q(35000);
 *              auto i = find_if(salary.begin(), salary.end(), q);
 * 
 *  Functors proved so useful that in C++11 the standards commitee decided to introduce "lambda" functions.
 *  These are essentially compiler generated functors.  The code:
 *              int s = 31000;
 *              auto mylambda = [s](const pair<string, int>& item) { return item.second > s; };
 * 
 *  defines a lambda that captures a salary, s (equivalent to the functor constructor):
 *              [s]
 * 
 *  and defines an anonymous function
 *              anon(const pair<string, int>& item) { return item.second > s; }
 * 
 *  This example compares all 3 techniques: function pointer, functor, lambda. 
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Query
{
public:
    bool operator()(const pair<string, int>& item)
    {
        return item.second > salary;
    }
    Query(int s): salary(s) {}
private:
    int salary;
};

bool moreThan35K(const pair<string, int>& item)
{
    return item.second > 35000;
}

int main()
{
    map<string, int> salary;
    
    salary["Steven"] = 25000;
    salary["Mary"] = 18000;
    salary["John"] = 20000;
    salary["Susan"] = 36500;
    salary["Rose"] = 17500;
    {   // use a function pointer
        auto i = find_if(salary.begin(), salary.end(), moreThan35K);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
    {
        // use a functor
        Query q(31000);
        auto i = find_if(salary.begin(), salary.end(), q);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
    {
        // use a lambda
        // C++11 introduced lambdas of the form: [captures](parameters){function body}
        // lambdas are equivalent to functors    
        int s = 31000;
        auto mylambda = [s](const pair<string, int>& item) { return item.second > s; };
        auto i = find_if(salary.begin(), salary.end(), mylambda);
        if(i != salary.end())
            cout << i->first << ", " << i->second << endl;
    }
}
