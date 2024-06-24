/*
 * Create a class that represents a bank account.
 * Add methods to allow a customer to deposit() and withdraw() money
 * and provide a method getBalance().
 */

#include <iostream>
using namespace std;

class BankAccount
{
public:
    BankAccount(const string& accountName): accountName(accountName), balance(0.0) {}
    
    void deposit(double amount)
    {
        balance += amount;
    }
        
    void withdraw(double amount)
    {
        balance -= amount;
    }
    
    double getBalance()
    {
        return balance;
    }
private:
    string accountName;
    double balance;
};

int main()
{
	BankAccount johnsAccount = BankAccount("johns");
	johnsAccount.deposit(350.00);
	johnsAccount.deposit(250.00);
	johnsAccount.deposit(500.00);
	johnsAccount.withdraw(100.00);
	cout << johnsAccount.getBalance() << endl;
}



