#include<iostream>
#include"sales.h"

namespace SALES
{
	Sales::Sales(const double ar[], int n)
	{

		double total = 0.0;
		int i;
		max = ar[0];
		min = ar[0];

		for (i = 0; (i < n) && (i < 4); i++)
		{
			if (ar[i] > max)
				max = ar[i];
			if (ar[i] < min)
				min = ar[i];
			sales[i] = ar[i];
			total += ar[i];
		}

		average = total / i;
	}

	Sales::Sales()
	{
		using namespace std;

		double ar[QUARTERS] = { };
		int i = 0;
		do
		{
			cout << "Enter a number: ";
			if (!(cin >> ar[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Bad input; Enter a value:\n";
			}
			i++;
		} while (i < QUARTERS);
		*this=Sales(ar, 4);
	}


	void Sales::showSales() const
	{
		using namespace std;

		cout << "Four quarters are: \n";
		for (int i = 0; i < 4; i++)
			cout <<sales[i] << " ";
		cout << "\nThe maximun is: " << max << endl;
		cout << "The minimun is: " << min << endl;
		cout << "The average is: " << average << endl;
	}
}