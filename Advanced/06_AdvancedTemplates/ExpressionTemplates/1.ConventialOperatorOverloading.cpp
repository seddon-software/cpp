////////////////////////////////////////////////////////////
//
//      Expession Templates
//
////////////////////////////////////////////////////////////


// Compare the output of this program with the example that doesn't use expression templates

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <int N=8>
struct Array
{
public:
	Array(const string& name, std::initializer_list<double> list): name(name)
    {
        for(auto i = list.begin(); i != list.end(); ++i)
        {
        	array.push_back(*i);
        }
    }
	Array(const string& name = "temp") : name(name)
	{
		for(unsigned i = 0; i < N; i++)
		{
			array.push_back(0.0);
		}
	}
	Array operator+(Array& r)
	{
		Array result;

		for(unsigned i = 0; i < r.array.size(); i++)
		{
			trace("+", i, r);
			result[i] = array[i] + r.array[i];
		}
		return result;
	}
	Array operator-(Array& r)
	{
		Array result;

		for(unsigned i = 0; i < r.array.size(); i++)
		{
			trace("-", i, r);
			result[i] = array[i] - r.array[i];
		}
		return result;
	}
	double& operator[](unsigned index)
	{
		return array[index];
	}
private:
	void trace(const string& op, int index, const Array& r)
	{
		cout << name << "[" << index << "]";
		cout << op;
		cout << r.name << "[" << index << "]" << endl;
	}
private:
  	vector<double> array;
  	string name;
};
  
int main()
{
	Array a{"a", { 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8 }};
	Array b{"b", { 5.1, 5.2, 5.3, 5.4, 5.5, 5.6, 5.7, 5.8 }};
	Array c{"c", { 10.1, 10.2, 10.3, 10.4, 10.5, 10.6, 10.7, 10.8 }};
	Array d{"d", { 20.1, 20.2, 20.3, 20.4, 20.5, 20.6, 20.7, 20.8 }};

	// This example doesn't use expression templates and hence the folowing
	// expression is evaluated for each array index, even though we are
	// only interested in index 2.
	double element = (a + b + d - c)[2];

	cout << endl << element << endl;
}

