////////////////////////////////////////////////////////////
//
//		Strategy
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
	void setUp(string name)
	{
		this->balance = 0;
		this->name = name;
	}
	void deposit(int amount)  // all account types can deposit
	{
		balance += amount;
	}
	void withdraw(int amount) // all account types can withdraw
	{
		balance -= amount;	// no restriction on overdrafts
	}
	void display()
	{
		cout << "Account: name=" << name << " balance=" << balance << endl;
	}
private:
	string name;
	int balance;
};

class CurrentAccount : public Account
{
};

class SavingsAccount : public Account
{
	// need to restrict withdrawals
};

class BondAccount : public Account
{
	// no deposits or withdrawals allowed until end of term
};

int main()
{
	CurrentAccount current;
	SavingsAccount savings;
	BondAccount bond;

	current.setUp("John");
	current.deposit(200);
	current.withdraw(300);
	current.display();

	savings.setUp("Susan");
	savings.deposit(100);
	savings.withdraw(300);
	savings.display();

	bond.setUp("Adil");
	bond.deposit(500);
	bond.withdraw(300);
	bond.display();
}
