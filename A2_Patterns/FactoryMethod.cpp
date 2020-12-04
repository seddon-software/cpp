///////////////////////////////////////////////////////////////
//
//		Factory Method
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/////
// graphic hierarchy
/////

class graphic 
{
public:
	virtual void display() = 0;
};

class rectangle : public graphic 
{
public:
	virtual void display() { cout << "rectangle" << endl; };
};

class ellipse: public graphic 
{
public:
	virtual void display() { cout << "ellipse" << endl; };
};


class button
{
public:
	// Factory Method
	graphic* create(string type) const
	{
		if(type == "rectangle") return new rectangle;
		if(type == "ellipse")   return new ellipse;
        throw 0;
	}
};


/////

int main()
{
	button b;
	vector<graphic*> theList;
    string choice;

    try
    {
	    while(true)
	    {
		    cout << "Choose: rectangle, ellipse OR quit: ";
		    cin >> choice;
		    theList.push_back(b.create(choice));
	    }
    }
    catch(int) {}


	for(int i = 0; i < (int)theList.size(); i++)
	{
		theList[i]->display();	 
	}

	return 0;
}
