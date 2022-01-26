module;

//using namespace std;
//import <iostream>; 
import <vector>; 

export module mylib;  // name our module and export

export double average(std::vector<double>& v)
{
    double sum = 0.0;
    for(auto i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    return sum;
}