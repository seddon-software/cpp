////////////////////////////////////////////////////////////
//
//		Virtual Construction using Cloning
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;


class Account
{
protected:
	string name;
public:
	Account(string name) { this->name = name; }
	virtual ~Account() {}
	void set_name(string name) { this->name = name; }
	virtual void get_balance() = 0;
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
	virtual Account* clone(string name) = 0;
};

void Account::withdraw() { cout << name + " is withdrawing money "; }

class Business : public Account
{
public:
	Business(string name) : Account(name) { }
	virtual ~Business() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { this->Account::withdraw(); cout << "from Business account" << endl; }
	
	// virtual CTOR
	Account* clone(string name)
	{
		Account* account = new Business(*this);
		account->set_name(name);
		return account;
	}
};

class Personal : public Account
{
public:
	Personal(string name) : Account(name) { }
	virtual ~Personal() {}
	virtual void get_balance() {}
	virtual void deposit() {}
	virtual void withdraw() { this->Account::withdraw(); cout << "from Personal account" << endl; }

	// virtual CTOR
	Account* clone(string name)
	{
		Account* account = new Personal(*this);
		account->set_name(name);
		return account;
	}
};

Account* Account::clone(string name)
{
	// dynamic_cast is an improvement, but still using a switch
	Account *copy = 0;
	if (dynamic_cast<Business*>(this)) copy = new Business(name);
	if (dynamic_cast<Personal*>(this)) copy = new Personal(name);
	return copy;
}

// global factory method
Account* CreateAccount(string name, string accountType)
{
	Account *pAccount = 0;
	if (accountType == "Business")
		pAccount = new Business(name);
	if (accountType == "Personal")
		pAccount = new Personal(name);
	return pAccount;
}


/////

void takeMoney(Account *a)
{
	a->withdraw();
}

int main()
{
	// All accounts are decoupled, but factory uses a switch!!!
	Account* bruce = CreateAccount("Bruce", "Personal");
	Account* dave = CreateAccount("Dave", "Business");
	takeMoney(bruce);
	takeMoney(dave);
	
	Account* zoe = bruce->clone("Zoe");
	takeMoney(zoe);
	
	Account* susan = dave->clone("Susan");
	takeMoney(susan);
	
	return 0;
}
