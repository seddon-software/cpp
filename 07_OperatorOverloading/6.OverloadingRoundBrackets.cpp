/*
 * Overloading () can be used to represent multi-dimensional arrays
 * If you try to use [] things get complicated, so its better to use ().
 * 
 */

#include <vector>
#include <iostream>
#include <string>
using namespace std;

class MyContainer
{
public:
    MyContainer(int rows) 
    {
        for(int i = 0; i < rows; i++)
        {
            vector<string> row;
            names.push_back(row);
        }
    }
    void add(const string& name, int row)
    {
        names[row].push_back(name);
    }
    string& operator()(int row, int col)
    {
        return names[row][col];
    }
private:
    vector<vector<string>> names;
};

int main()
{
    MyContainer m(2);  // create 2 rows with variable length columns
    m.add("Peter", 0); // add to row 0 etc
    m.add("Paul", 0);
    m.add("Mary", 0);
    m.add("Adil", 1);
    m.add("Suzy", 1);
    m.add("Thomas", 1);
    // overloading as an r-value
    cout << m(1, 0) << endl;
    // overloading as an l-value (necessitates reference return)
    m(0, 2) = "Jim";
    cout << m(0, 2) << endl;
}
