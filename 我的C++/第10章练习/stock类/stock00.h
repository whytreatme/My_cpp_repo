#ifndef STOCK_H_
#define STOCK_H_

#include<string>

class Stock
{
private:
	std::string m_company;
	long m_shares;
	double m_share_val;
	double total_val;
	void set_tot()
	{
		total_val = m_shares * m_share_val;
	}
public:
	void acquire(const std::string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();
	Stock(const std::string& co, long n = 0, double pr = 0.0);
	Stock();
};

#endif // !STOCK_H_

