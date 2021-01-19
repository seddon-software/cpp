/*
 *  Create a class that represents a bank account.
 *  Add methods to allow a customer to deposit() and withdraw() money
 *  and provide a method getBalance().
 */

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class BankAccount
{
public:
	BankAccount(const string& accountName):
        accountName(accountName), balance(0.0), overdraft(0.0) {}
    
    void deposit(double amount)
    {
        balance += amount;
    }
        
    void withdraw(double amount)
    {
        double newBalance = balance - amount;
        if(newBalance < overdraft) throw out_of_range("overdrawn");
    }

    void setOverdraft(double amount)
    {
        overdraft = amount;
    }
        
    double getBalance()
    {
        return balance;
    }
private:
    string accountName;
    double balance;
    double overdraft;
};


int main()
{
	try
	{
		BankAccount johnsAccount("johns");
		johnsAccount.deposit(350.00);
		johnsAccount.deposit(250.00);
		johnsAccount.deposit(500.00);
		johnsAccount.withdraw(100.00);

		cout << johnsAccount.getBalance() << endl;

		johnsAccount.withdraw(2000.00);
	} catch(const out_of_range& e) {
		cerr << e.what() << endl;
	}
}



