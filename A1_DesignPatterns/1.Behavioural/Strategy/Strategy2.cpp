////////////////////////////////////////////////////////////
//
//		Strategy
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Subclasses will vary the behaviour of some of these methods
// first attempt is to use polymorphism and override behaviour in subclasses
// what if we create lots of Account types - we will need to override in lots of cases

// make methods virtual (for polymorphism)
class Account
{
public:
	void setUp(string name)
	{
		this->balance = 0;
		this->name = name;
	}
	// override in specific classes to provide different behaviour
	virtual void deposit(int amount)
	{
		balance += amount;
	}
	// override in specific classes to provide different behaviour
	virtual void withdraw(int amount)
	{
		balance -= amount;
	}
	virtual void display()
	{
		cout << "Account: name=" << name << " balance=" << balance << endl;
	}
private:
	string name;
protected:	// is this OK?
	int balance;
};

class CurrentAccount : public Account
{
public:
	CurrentAccount() : Account(), overdraftLimit(0) {}
	// need to consider overdrafts
	virtual void withdraw(int amount)
	{
		if(balance < amount + overdraftLimit)
			throw runtime_error("Not enough funds for this account");
		Account::withdraw(amount);
	}
	virtual void setOverdraftLimit(int overdraftLimit)
	{
		this->overdraftLimit = overdraftLimit;
	}
private:
	int overdraftLimit;
};

class SavingsAccount : public Account
{
public:
	// need to restrict withdrawals
	virtual void withdraw(int amount)
	{
		if(balance < amount)
			throw runtime_error("No overdraft for this account");
		Account::withdraw(amount);
	}
};

class BondAccount : public Account
{
public:
	// no deposits or withdrawals allowed until end of term
	virtual void deposit(int amount)
	{
		throw runtime_error("Can't deposit or withdraw with this account");
	}
	virtual void withdraw(int amount)
	{
		throw runtime_error("Can't deposit or withdraw with this account");
	}
};

void useAccount(Account& account, const string& name, int deposit_, int withdraw_)
{
	try
	{
		account.setUp(name);
		account.deposit(deposit_);
		account.withdraw(withdraw_);
		account.display();
	}
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	CurrentAccount current;
	SavingsAccount savings;
	BondAccount bond;

	current.setOverdraftLimit(50);
	useAccount(current, "John", 200, 300);
	useAccount(savings, "Susan", 100, 300);
	useAccount(bond, "Adil", 500, 300);
}
