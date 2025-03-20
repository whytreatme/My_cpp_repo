#include<iostream>
#include"sales.h"

int main()
{
	using namespace SALES;
	using std::cout;
	using std::endl;

	Sales ps;
	double ar[] = { 12.56,13.98,12.34,10.16,11,56 };
	setSales(ps, ar, 5);
	showSales(ps);

	Sales pd;
	setSales(pd);
	showSales(pd);

	return 0;
}