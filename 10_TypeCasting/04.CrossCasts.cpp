////////////////////////////////////////////////////////////
//
//		Cross Casts
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

/*
 * This example uses a cross cast to select all objects that are in LX or derived from LX
 * The inheritance hierachy is:
 *
 *                    LX <-- LY <-- LZ
 *                   /
 *                 Base
 *                   \
 *                    RX <-- RY <-- RZ
 */

struct Base             { virtual void f()  { cout << "Base" << endl; }  virtual ~Base(){} };
struct LX : public Base { virtual void lf() { cout << "LX" << endl; } virtual ~LX(){} };
struct LY : public LX   { virtual void lf() { cout << "LY" << endl; } virtual ~LY(){} };
struct LZ : public LY   { virtual void lf() { cout << "LZ" << endl; } virtual ~LZ(){} };
struct RX : public Base { virtual void rf() { cout << "RX" << endl; } virtual ~RX(){} };
struct RY : public RX   { virtual void rf() { cout << "RY" << endl; } virtual ~RY(){} };
struct RZ : public RY   { virtual void rf() { cout << "RZ" << endl; } virtual ~RZ(){} };

//////

int main()
{
	vector<Base*> theList;

	theList.push_back(new Base);
	theList.push_back(new LX);
	theList.push_back(new LY);
	theList.push_back(new LZ);
	theList.push_back(new RX);
	theList.push_back(new RY);
	theList.push_back(new RZ);
    
	for(auto object : theList)
	{
		// dynamic_cast acts as a filter
	    LX* p = dynamic_cast<LX*>(object);
		if(p) p->lf();
	}
}

