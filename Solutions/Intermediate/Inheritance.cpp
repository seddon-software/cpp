/*******************************************************************
 *
 * Inheritance
 *
 ******************************************************************/

#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
using namespace std;

class InsufficientFundsException : exception {};

class Money
{
public:
	Money(int pounds=0, int pence=0): pounds(pounds), pence(pence) {}
	void operator+=(const Money& rhs)
	{
		pounds += rhs.pounds;
		pence += rhs.pence;
		if(pence >= 100)
		{
			pounds--;
			pence -= 100;
		}
	}
	void operator-=(const Money& rhs)
	{
		pounds -= rhs.pounds;
		pence -= rhs.pence;
		if(pence < 0)
		{
			pounds--;
			pence += 100;
		}
	}
	void operator*=(double rate)
	{
		int p = pounds * 100 + pence;
		p *= (1 + rate);
		pounds = p / 100;
		pence = p % 100;
	}
	friend bool operator<(const Money& lhs, const Money& rhs)
	{
		if(lhs.pounds < rhs.pounds) return true;
		if(lhs.pence < rhs.pence) return true;
		return false;
	}
	friend ostream& operator<<(ostream& os, const Money& m)
	{
		return os << m.pounds << ":" << setw(2) << setfill('0') << m.pence;
	}
private:
	int pounds;
	int pence;
};

class BankAccount
{
private:
	static int number;
public:
	BankAccount(const string& name, const Money& initialBalance) : name(name), balance(initialBalance)
	{
		accountNumber = number++;
	}
	void deposit(const Money& amount)
	{
		balance += amount;
	}
	void withdraw(const Money& amount)
	{
		balance -= amount;
	}
	Money getBalance() { return balance; }
	void setBalance(const Money& balance) { this->balance = balance; }

	void display()
	{
		cout << "Name: " << name << ", "
			 << "Account Number: " << accountNumber << ", "
			 << "Balance: " << balance << endl;
	}
private:
	string name;
	int accountNumber;
	Money balance;
};
int BankAccount::number = 1000;

class CreditAccount : public BankAccount
{
public:
	CreditAccount(const string& name, const Money& initialBalance, const Money& overdraft_limit)
		: BankAccount(name, initialBalance), overdraft_limit(overdraft_limit) {}
	void withdraw(const Money& amount)
	{
		BankAccount::withdraw(amount);
		if(getBalance() < overdraft_limit)
		{
			deposit(amount);		// undo transaction
			throw InsufficientFundsException();
		}
	}
private:
	Money overdraft_limit;
};

class SavingsAccount : public BankAccount
{
public:
	SavingsAccount(const string& name, const Money& initialBalance, double interest_rate)
		: BankAccount(name, initialBalance), interest_rate(interest_rate) {}
	void applyInterest()
	{
		Money balance = getBalance();
		balance *= (interest_rate / 100.0);
		setBalance(balance);
	}
private:
    double interest_rate;
};

int main()
{
	CreditAccount john("John", Money(100, 50), Money(250, 0));
	CreditAccount susan("Susan", Money(50, 10), Money(100, 0));
	SavingsAccount thomas("Thomas", Money(5250, 25), 1.5);
	SavingsAccount christine("Christine", Money(1000, 0), 1.0);
	john.deposit(Money(125, 15));
	john.deposit(Money(125, 40));
	john.display();
	try
	{
		susan.withdraw(Money(2, 99));
		susan.withdraw(Money(152, 25));
		susan.withdraw(Money(152, 25));
	} catch(InsufficientFundsException& e) {
		cout << "Insufficient funds, ";
		susan.display();
	}
	thomas.applyInterest();
	thomas.applyInterest();
	thomas.applyInterest();
	thomas.display();
}
