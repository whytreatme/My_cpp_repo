#include<iostream>
#include"bank_account.h"

Bank_Account::Bank_Account(const std::string fuln ,
	const std::string ac , double bal )
{
	fullname = fuln;
	accid = ac;
	balance = bal;
}

Bank_Account::~Bank_Account()
{

}

void Bank_Account::show_account() const
{
	using namespace std;
	using std::ios_base;

	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	cout << "Name: " << fullname << "\n"
		<< "Accid: " << accid << "\n"
		<< "Balance: " << balance << endl;
	cout << "\n";
}

void Bank_Account::deposit(double cash)
{
	using std::cout;
	if (cash < 0)
	{
		cout << "Error! The cash can't be negative!" << "\n";
		return;
	}
	cout << "Deposit $:" << cash << "\n";
	balance += cash;
}

void Bank_Account::withdraw(double cash)
{
	using std::cout;
	if (cash < 0)
	{
		cout << "Error! The cash can't be negative!" << "\n";
		return;
	}
	else if (cash > balance)
	{
		cout << "Error! You can't take out the money more than you have!" << "\n";
		return;
	}
	cout << "Withdraw $:" << cash << "\n";
	balance -= cash;
}