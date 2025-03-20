#include<iostream>
#include"sales.h"

int main()
{
	using namespace SALES;
	using std::cout;
	using std::endl;

	double ar[] = { 12.56,13.98,12.34,10.16,11,56 };
	Sales ps(ar, 5);
	ps.showSales();

	Sales pd;
	pd.showSales();

	return 0;
}