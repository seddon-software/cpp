///////////////////////////////////////////////////////////////
//
//		Builder
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/////
// 
/////

class Builder
{
public:
	virtual void BuildPartA() = 0;
	virtual void BuildPartB() = 0;
	virtual void BuildPartC() = 0;
	virtual vector<string> GetPart() = 0;
	virtual ~Builder() {};
};

class BuilderUpper : public Builder
{
private:
	vector<string> data;
public:
	virtual void BuildPartA() { data.push_back("A"); };
	virtual void BuildPartB() { data.push_back("B"); };
	virtual void BuildPartC() { data.push_back("C"); };
	virtual vector<string> GetPart() { return data; }
	virtual ~BuilderUpper() {};
};

class BuilderLower : public Builder
{
private:
	vector<string> data;
public:
	virtual void BuildPartA() { data.push_back("a"); };
	virtual void BuildPartB() { data.push_back("b"); };
	virtual void BuildPartC() { data.push_back("c"); };
	virtual vector<string> GetPart() { return data; }
	virtual ~BuilderLower() {};
};

class BuilderNumeric : public Builder
{
private:
	vector<string> data;
public:
	virtual void BuildPartA() { data.push_back("1"); };
	virtual void BuildPartB() { data.push_back("2"); };
	virtual void BuildPartC() { data.push_back("3"); };
	virtual vector<string> GetPart() { return data; }
	virtual ~BuilderNumeric() {};
};

class Director
{
private:
	vector<Builder*> parts;
	vector<string> product;
public:
	void Add(Builder& b)
	{
		parts.push_back(&b);
	}
	
	vector<string> Construct()
	{
		for(unsigned i = 0; i < parts.size(); i++)
		{
			parts[i]->BuildPartA();
			parts[i]->BuildPartB();
			parts[i]->BuildPartC();
		}

		vector<string> temp;
		for(unsigned i = 0; i < parts.size(); i++)
		{
			temp = parts[i]->GetPart();
			for(unsigned k = 0; k < temp.size(); k++)
			{
				product.push_back(temp[k]);
			}
		}
		return product;
	}

};
/////

int main()
{
	Director d;
	BuilderUpper b1, b4;
	BuilderLower b2, b6;
	BuilderNumeric b3,b5;
	d.Add(b1);
	d.Add(b2);
	d.Add(b3);
	d.Add(b4);
	d.Add(b5);
	d.Add(b6);
	vector<string> product = d.Construct();
	
	for(unsigned i = 0; i < product.size(); i++)
	{
		cout << product[i];
	}
	cout << endl;
	
}
