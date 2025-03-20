#include<iostream>
#include<cstdlib>
#include<ctime>
#include"vector.h"

int main()
{
	using namespace std;
	using namespace VECTOR;
	
	
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	int num = 0;
	unsigned long wholesteps = 0, highest = 0, lowest = 0;
	
	

	cout << "Enter target distance (q to quit): ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		cout << "Target Distance: " << target << ", Step Size: " << dstep << endl;

		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;

		//为了统计最终的步骤
	
		wholesteps += steps;
		if (num == 0)
			highest = lowest = steps;	
		
		if (steps > highest)
			highest = steps;
		
		if (steps < lowest)
			lowest = steps;
		
		num++;

	
		
		//为统计最终的步骤

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}

	cout << "Your input " << num << " times, and statistic info :" << endl;
	cout << "Max Step = " << highest << endl;
	cout << "Min Step = " << lowest << endl;
	cout << "Average Step = " << wholesteps / num << endl;

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;


	return 0;
}