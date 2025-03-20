#include<iostream>
#include"stock10.h"


Stock::Stock()
{
	std::cout << "Default constructor called\n";
	m_company = "no name";
	m_shares = 0;
	m_share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const std::string& co, long n, double pr)
{
	std::cout << "Constructor using" << co << " called\n";
	m_company = co;

	if (n < 0)
	{
		std::cerr << "Number of shares can't be negative; "
			<< m_company << " shares set to 0.\n";
		m_shares = 0;
	}
	else
		m_shares = n;
	m_share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout << "Bye, " << m_company << "!\n";
}

void Stock::buy(long num, double price)
{
	using std::cout;

	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. "
			<< "Transacation is aborted.\n";
	}
	else
	{
		m_shares += num;
		m_share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;

	if (num < 0)
	{
		cout << "Number of shares can't be be negative. "
			<< "Transaction is aborted.\n";
	}
	else if (num > m_shares)
	{
		cout << "You can't sell more than you have! "
			<< "Transaction is aborted.\n";
	}

	else
	{
		m_shares -= num;
		m_share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	m_share_val = price;

	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::ios_base;

	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);

	std::cout << "Company: " << m_company
		<< " Shares: " << m_shares << '\n'
		<< " share Price: $" << m_share_val;

	cout.precision(2);
	cout << " Total Worth: $" << total_val << '\n';

	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}
