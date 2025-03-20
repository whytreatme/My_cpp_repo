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
	Stock();
	Stock(const std::string& co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show()const;
	const Stock& topval(const Stock& s)const;

};

#endif // !STOCK_H_