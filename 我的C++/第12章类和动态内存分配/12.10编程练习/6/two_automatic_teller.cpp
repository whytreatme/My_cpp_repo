#include<iostream>
#include<cstdlib>
#include<ctime>
#include"queue.h"

const int MIN_PER_HR = 60;
const int MIN_SIM_HOURS = 150;

bool newcustomer(double x);

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs);
	Queue line2(qs);
	cout << "The number of simulation hours >=100. " << endl;

	//cout << "Enter the number of simulation hours: ";
	//int hours;
	//cin >> hours;
	int hours = MIN_SIM_HOURS;
	int jishuqi = 0;

	long cyclelimit = MIN_PER_HR * hours;

	//cout << "Enter the average number of customers per hour: ";
	double perhour = 0;
	//cin >> perhour;
	Item temp;
	double average_wait = 0;
	while (average_wait < 1)
	{
		double min_per_cust;
		//min_per_cust = MIN_PER_HR / perhour;

		//Item temp;
		long turnaways = 0;
		long customers = 0;
		long served = 0;
		long sum_line1 = 0;
		long sum_line2 = 0;
		int wait_time_line1 = 0;
		int wait_time_line2 = 0;
		long line_wait = 0;
		perhour++;
		if (!line1.isempty())
		{
			if(line1.queuecount()>1)
			cout << "好你妈好你妈" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			while (line1.queuecount() != 0)
			{
				line1.dequeue(temp);
			}
			jishuqi++;
		}

		if (!line2.isempty())
		{
			if(line2.queuecount()>1)
			cout << "好你妈好你妈" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
			while (line2.queuecount() != 0)
			{
				line2.dequeue(temp);
				
			}
			jishuqi++;
		}
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			min_per_cust = MIN_PER_HR / perhour;
			if (newcustomer(min_per_cust))
			{
				if (line1.isfull()&&line2.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle);
					if (line1.queuecount() <= line2.queuecount())
						line1.enqueue(temp);
					else 
						line2.enqueue(temp);
				}
			}
			if (wait_time_line1 <= 0 && !line1.isempty())
			{
				line1.dequeue(temp);
				wait_time_line1 = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}

			if (wait_time_line2 <= 0 && !line2.isempty())
			{
				line2.dequeue(temp);
				wait_time_line2 = temp.ptime();
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time_line1 > 0)
				wait_time_line1--;
			
			if (wait_time_line2 > 0)
				wait_time_line2--;
			sum_line1 += line1.queuecount();
			sum_line2 += line2.queuecount();
		}
		average_wait = (double)line_wait / served;
		if (average_wait < 1)
		{
			if (customers > 0)
			{
				cout << "customers accepted: " << customers << endl;
				cout << " customers served: " << served << endl;
				cout << "     turnaways: " << turnaways << endl;
				cout << "average queue size of line1: ";
				cout.precision(2);
				cout.setf(ios_base::fixed, ios_base::floatfield);
				cout << (double)sum_line1 / cyclelimit << endl;
				cout << "average queue size of line2: ";
				cout << (double)sum_line2 / cyclelimit << endl;
				cout << " average wait time: "
					<< (double)line_wait / served << " minutes\n";
			}
			else
				cout << "No customers!\n";
			cout << "The average " << perhour << " of arrival per hour, and average wait time is"
				<< average_wait << endl;

			if (served > customers)
				cout <<"我的老爸是蠢材" << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		}

	}
	cout << "Done!\n";
	
	
	return 0;
}

bool newcustomer(double x)
{
	return(std::rand() * x / RAND_MAX < 1);
}