///////////////////////////////////////////////////////////////
//
//		Composite
//
///////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

class Component
{
public:
	Component(string name) :
			name(name)
	{
	}
	virtual void Add(Component* pc) = 0;
	virtual void Remove(Component* pc) = 0;
	virtual void Display(int depth) = 0;
	virtual ~Component()
	{
	}
	bool operator==(Component const& rhs)
	{
		return name == rhs.name;
	}
protected:
	string name;
};

class Composite: public Component
{
public:
	Composite(const string& name) :
			Component(name)
	{
	}

	virtual void Add(Component* pc)
	{
		children.insert(pc);
	}
	void Remove(Component* pc)
	{
		set<Component*>::iterator i;
		i = find_if(children.begin(), children.end(),
				[pc](Component* const& p) -> bool
				{
					if(*pc == *p) return true;
					return false;
				});
		if (i != children.end())
		{
			Component* const & pc = *i;
			delete pc;
			children.erase(pc);
		}
	}

	virtual void Display(int depth)
	{
		cout << setw(depth) << "-" << name << endl;
		set<Component*>::iterator i;
		for (i = children.begin(); i != children.end(); ++i)
		{
			Component* const & pc = *i;
			pc->Display(depth+2);
		}
	}
private:
	set<Component*> children;
};

class Leaf: public Component
{
public:
	Leaf(string name) :
			Component(name)
	{
	}

	void Add(Component* pc)
	{
		cout << "Cannot add to a leaf" << endl;
	}

	void Remove(Component* pc)
	{
		cout << "Cannot remove from a leaf" << endl;
	}

	void Display(int depth)
	{
		cout << setw(depth) << "-" << name << endl;
	}
};
/////

int main()
{
	Composite root("root");
	root.Add(new Leaf("Leaf A"));
	root.Add(new Leaf("Leaf B"));
	Composite* pComp = new Composite("Composite X");
	pComp->Add(new Leaf("Leaf XA"));
	pComp->Add(new Leaf("Leaf XB"));
	root.Add(pComp);
	root.Add(new Leaf("Leaf C"));

// Add and remove a leaf
	Leaf* leaf = new Leaf("Leaf D");
	root.Add(leaf);
	root.Remove(leaf);

// Recursively display tree
	root.Display(1);
}

