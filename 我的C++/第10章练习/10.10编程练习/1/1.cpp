#include<iostream>
#include"bank_account.h"

int main()
{
	Bank_Account stuff[4] =
	{
		Bank_Account("Arthur Lee","Ljh011288",120000.95),
		Bank_Account("Gilbert Strang","Fg1159034112",50012.18),
		Bank_Account(),
	    Bank_Account("Raymond Murphy","EG20011112",18000.54)
	};

	for (int i = 0; i < 4; i++)
		stuff[i].show_account();

	stuff[0].deposit(6666.8);
	stuff[0].show_account();

	stuff[1].withdraw(1281.97);
	stuff[1].show_account();

	stuff[2].withdraw(12.96);
	std::cout << "Bye.\n";
	return 0;
}