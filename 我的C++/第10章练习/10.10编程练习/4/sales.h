#ifndef SALES_H_
#define SALES_H_




namespace SALES
{
	const int QUARTERS = 4;

	class Sales
	{
	private:
		double sales[QUARTERS];
		double average;
		double max;
		double min;

	public:
		Sales(const double ar[], int n);
		Sales();
		~Sales() {};
		void showSales() const;

	};
}


#endif // !SALES_H_
