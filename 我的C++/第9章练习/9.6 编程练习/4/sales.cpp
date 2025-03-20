#include<iostream>
#include"sales.h"

namespace SALES
{
	void setSales(Sales& s, const double ar[], int n)
	{
		s = { };

		double total = 0.0;
		int i;
		s.max = ar[0];
		s.min = ar[0];

		for (i = 0; (i < n)&&(i<4); i++)
		{
			if (ar[i] > s.max)
				s.max = ar[i];
			if (ar[i] < s.min)
				s.min = ar[i];
			s.sales[i] = ar[i];
			total += ar[i];
		}
		
		s.average = total / i;
	}

	void setSales(Sales& s)
	{
		using namespace std;

		/*double total = 0.0;
		
		for (int i = 0; i < 4; i++)
		{
			cout << "Please enter a double values:\n";
			while (!(cin >> s.sales[i]))
			{
				cin.clear();
				while (cin.get() != '\n')
					continue;
				cout << "Bad input; Please enter a double value lie 12.08\n";
			}
			
			total += s.sales[i];
		}

		s.max = s.sales[0];
		s.min = s.sales[0];

		for (int i = 0; i < 4; i++)
		{
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}
		s.average = total / 4;*/
		
		double ar[QUARTERS]={ };
		int i=0;
		do
		{
		cout<<"Enter a number: ";
		if(!(cin>>ar[i]))
		{
		 cin.clear();
		 while(cin.get()!='\n')
		 continue;
		 cout<<"Bad input; Enter a value:\n";
		}
		i++;
		} while (i < QUARTERS);
		setSales(s,ar,4);
	}


	void showSales(const Sales& s)
	{
		using namespace std;

		cout << "Four quarters are: \n";
		for (int i = 0; i < 4; i++)
			cout << s.sales[i] << " ";
		cout << "\nThe maximun is: " << s.max << endl;
		cout << "The minimun is: " << s.min << endl;
		cout << "The average is: " << s.average << endl;
	}
}