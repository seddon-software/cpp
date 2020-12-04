#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <string>
using namespace std;




class Account
{
private:
	string name;
public:	
    Account(){}
    Account(const string& n): name(n) {}	

    // normal interface
    virtual void get_balance() = 0;
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
};


#endif
