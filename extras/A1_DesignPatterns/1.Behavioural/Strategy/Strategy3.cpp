////////////////////////////////////////////////////////////
//
//		Strategy
//
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// behaviour interfaces
class WithdrawBehaviour
{
public:
	virtual void withdraw(int& balance, int amount, int limit = 0) = 0;
};

class HasOverdraft
{
public:
	virtual void setOverdraftLimit(int overdraftLimit) = 0;
};

// behaviour implementations
class WithdrawToOverdraftLimit : public WithdrawBehaviour
{
public:
	virtual void withdraw(int& balance, int amount, int limit)
	{
		if(amount > balance + limit)
			throw runtime_error("not enough funds");
		balance -= amount;
	}
};

class UnlimitedWithdrawal : public WithdrawBehaviour
{
public:
	virtual void withdraw(int& balance, int amount, int = 0)
	{
		balance -= amount;
	}
};

class NoWithdrawalsAllowed : public WithdrawBehaviour
{
public:
	virtual void withdraw(int& = *(int*)0, int = 0, int = 0)
	{
		throw runtime_error("no withdraws are allowed");
	}
};


// interface : closed for code changes
class Account
{
public:
	virtual void deposit(int amount) = 0;
	virtual void withdraw(int amount) = 0;
	virtual void display() = 0;
};


// implementations
class UnlimitedWithdrawalAccount :
	public Account,
	public UnlimitedWithdrawal
{
public:
	UnlimitedWithdrawalAccount(const string& name) : name(name), balance(0) {}

	virtual void deposit(int amount)
	{
		balance += amount;
	}
	virtual void withdraw(int amount)
	{
		UnlimitedWithdrawal::withdraw(balance, amount);
	}
	void display()
	{
		cout << "name=" << name << " balance=" << balance << endl;
	}
private:
	string name;
	int balance;
};

class LimitedWithdrawalAccount :
		public Account,
		public WithdrawToOverdraftLimit,
		public HasOverdraft
{
public:
	LimitedWithdrawalAccount(const string& name) : name(name), balance(0), overdraftLimit(0) {}

	virtual void deposit(int amount)
	{
		balance += amount;
	}
	virtual void withdraw(int amount)
	{
		WithdrawToOverdraftLimit::withdraw(balance, amount, overdraftLimit);
	}
	void display()
	{
		cout << "name=" << name << " balance=" << balance << endl;
	}
	virtual void setOverdraftLimit(int overdraftLimit)
	{
		this->overdraftLimit = overdraftLimit;
	}
private:
	string name;
	int balance;
	int overdraftLimit;
};


class NoWithdrawalAccount :
		public Account,
		public NoWithdrawalsAllowed
{
public:
	NoWithdrawalAccount(const string& name) : name(name), balance(0) {}

	virtual void deposit(int amount)
	{
		balance += amount;
	}
	virtual void withdraw(int amount)
	{
		NoWithdrawalsAllowed::withdraw(balance, amount);
	}
	void display()
	{
		cout << "name=" << name << " balance=" << balance << endl;
	}
private:
	string name;
	int balance;
};


void useAccount(Account& account, const string& name, int deposit, int withdraw)
{
	try
	{
		account.deposit(deposit);
		account.withdraw(withdraw);
		account.display();
	}
	catch(const exception& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	UnlimitedWithdrawalAccount john("John");
	LimitedWithdrawalAccount susan("Susan");
	susan.setOverdraftLimit(50);
	NoWithdrawalAccount adil("Adil");

	useAccount(john, "John", 200, 300);
	useAccount(susan, "Susan", 100, 300);
	useAccount(adil, "Adil", 500, 300);
}
