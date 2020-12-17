////////////////////////////////////////////////////////////
//
//		Virtual Construction using Exemplars
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <list>
#include <map>
#include <string>
using namespace std;


class Exemplar{};

class Account
{
protected:
	string name;
	virtual Account* build(const string&, const string&) = 0;
public:	
	Account(){}
	Account(const string& n) : name(n) {}
	static void Register(Account* e, string id)
	{
		if(!exemplars) exemplars = new map<string, Account*>();
		(*exemplars)[id] = e;
	}
	
	virtual ~Account() {}
	virtual void get_balance() = 0;
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
	
	// virtual CTOR
	static Account* make(const string& id, const string& name)	// calls build to do the real work
	{
		Account* e = (*exemplars)[id];
		Account* p = e->build(id, name);
		return p;
	}
private:
	static map<string, Account*>* exemplars;
};
map<string, Account*>* Account::exemplars;

class Deposit : public Account
{
public:
	Deposit(const Exemplar&, const string& id)
	{ 
		Account::Register(this, id);
	}
	Deposit(const string& n) : Account(n) {}
	virtual ~Deposit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Deposit account" << endl; }

	// virtual CTOR
	virtual Deposit* build(const string& type, const string& name)
	{
        return new Deposit(name);
	}
};

class Credit : public Account
{
public:
	Credit(const Exemplar&, const string& id)
	{ 
		Account::Register(this, id);
	}
	Credit(const string& n) : Account(n) {}

	virtual ~Credit() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Credit account" << endl; }

	// virtual CTOR
	virtual Credit* build(const string& type, const string& name)
	{
        return new Credit(name);
	}
};

class Saver : public Account
{
public:
	Saver(const Exemplar&, const string& id)
	{
		Account::Register(this, id);
	}
	Saver(const string& n) : Account(n)
	{}

	virtual void r() {}
	virtual ~Saver() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { cout << name << " is withdrawing from Saver account" << endl; }

	// virtual CTOR
	virtual Saver* build(const string& type, const string& name)
	{
        return new Saver(name);
	}
};

static Credit CreditFactory(Exemplar(), "Current");
static Deposit DepositFactory(Exemplar(), "Deposit");
static Saver SaverFactory(Exemplar(), "Term Deposit");

/////

void takeMoney(Account *a)
{
	a->withdraw();
}

/////

int main()
{
	// complete decoupling
	Account* bruce = Account::make("Deposit", "Bruce");
	takeMoney(bruce);
	
	Account* dave = Account::make("Current", "Dave");
	takeMoney(dave);

	Account* bridget = Account::make("Term Deposit", "Bridget");
	takeMoney(bridget);
}
