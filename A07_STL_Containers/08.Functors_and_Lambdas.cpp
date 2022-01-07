////////////////////////////////////////////////////////////
//
//      Hashes
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
 *  In older C++ code, before the advent of lamdas, functors were used to add state information
 *  to functions, since functions are not allowed to hold attributes.  Nowadays we can use lambdas
 *  to add state information to functions.  In this example we compare the two approaches.  
 * 
 *  In reality, a lambda is a compiler generated function.  Notice in the example below that the 
 *  functor captures the int: salaryAbove in the Query constructor, corresponding to the [] capture in 
 *  the lambda.  The parameters to Query::opererator() are identical to the parameters of the lambda
 *  and the code of this overload is identical to the body of the lambda.  Hence the above assertion
 *  that a lambda is nothing more than a compiler generated functor.
 * 
 *  Finally, note that after defining the functor, we pass an instance as a parameter to the find_if 
 *  algorithm.  The STL will then call back on Query::operator().  Similarly with the lambda example. 
 */

using PAIR = pair<string, int>;
using HASH = unordered_map<string, int>;


void Print(const PAIR& p)
{
    cout << p.first << ", " << p.second << endl;
}

class Query
{
public:
    Query(int s): salaryAbove(s) {}
    bool operator()(const PAIR& p)
    {
        return p.second > salaryAbove;
    };
private:
    int salaryAbove;
};

int main()
{
    HASH salary;
    salary["Steven"] = 25000;
    salary["Mary"]   = 18000;
    salary["John"]   = 20000;
    salary["Susan"]  = 36500;
    salary["Rose"]   = 17500;
	int salaryAbove = 30000;                    

    // using the find_if algorithm with functor
    {
        Query query(salaryAbove);
        auto i = find_if(salary.begin(), salary.end(), query);
        if(i != salary.end())  // check if found
            cout << i->first << ", " << i->second << endl;
        else
            cout << "not found" << endl;
    }

    // using the find_if algorithm with lambda
	{
        auto query = [salaryAbove](const PAIR& p)   // capture the salaryAbove criteria 
            {
                return p.second > salaryAbove;
            };
        auto i = find_if(salary.begin(), salary.end(), query);
        if(i != salary.end())  // check if found
            cout << i->first << ", " << i->second << endl;
        else
            cout << "not found" << endl;
    }
}
