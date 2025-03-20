#include<string>
#ifndef BANK_ACCOUNT_H_
#define BANK_ACCOUNT_H_

class Bank_Account
{
private:
	std::string fullname;
	std::string accid;
	double balance;

public:
	Bank_Account(const std::string fuln = "No Name",
		const std::string ac = "000", double bal = 0.0);
	~Bank_Account();
	void show_account() const;
	void deposit(double cash);
	void withdraw(double cash);
};



#endif // !BANK_ACCOUNT_H_

