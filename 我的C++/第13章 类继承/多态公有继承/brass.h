#ifndef BARASS_H_
#define BRASS_H_

#include<string>

class Brass
{
	std::string fullname;
	long acctNum;
	double balance;

public:
	Brass(const std::string& s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdrawl(double amt);
	double Balance()const;
	virtual void ViewAcct() const;
	virtual ~Brass(){}
};

class BrassPlus :public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;

public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1, double bal = 0.0, double m1 = 500,
		 double r = 0.11125);
	BrassPlus(const Brass& ba, double m1 = 500, double r = 0.11125);

	virtual void ViewAcct() const;
	virtual void Withdrawl(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
};
#endif // !BARASS_H_
