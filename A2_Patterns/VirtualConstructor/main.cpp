////////////////////////////////////////////////////////////
//
//		Virtual Construction using Exemplars
//
////////////////////////////////////////////////////////////

#include "Account.hpp"
#include "AccountFactory.hpp"

void takeMoney(Account& a)
{
	a.withdraw();
	a.get_balance();
	a.deposit();
}

/////

int main()
{
    Account& sue = AccountFactory::make("Credit", "Sue");
    Account& dave = AccountFactory::make("HiInterest", "Dave");
    Account& bruce = AccountFactory::make("Deposit", "Bruce");

    takeMoney(sue);
    takeMoney(dave);
    takeMoney(bruce);

	Account& adil = AccountFactory::clone(sue, "adil");
	Account& zoe = AccountFactory::clone(dave, "zoe");
	Account& zak = AccountFactory::clone(bruce, "zak");

    takeMoney(adil);
    takeMoney(zoe);
    takeMoney(zak);
}
