#include<stdio.h>
#include<stdbool.h>
//验证输入是一个整数
long get_long(void);
//验证范围的上下限是否有效
bool bad_limit(long begin, long end, long low, long high);
//计数a-b的整数平方和
double sum_squares(long a, long b);
int main()
{
	const long MIN = -10000000L;
	const long MAX = +10000000L;
	long start;
	long stop;
	double answer;

	printf_s("This program computes the sum of the squares of"
		"integers in a range.\nThe lower bound should not"
		"be less than -10000000 and\nthe upper bound"
		"should not be more than +10000000.\nEnter the"
		"limits(enter 0 for both limits to quit):\n"
		"lower limit:");
	start = get_long();
	printf_s("upper limit:");
	stop = get_long();
	while (start != 0 || stop != 0)
	{
		if (bad_limit(start, stop, MIN, MAX))
			printf_s("Please try again.\n");
		else
		{
			answer = sum_squares(start, stop);
			printf_s("The sum of the squares of the integers ");
			printf_s("from %ld to %ld is %g\n", start, stop, answer);
		}
		printf_s("Enter the limits(enter 0 for both limits to quit):\n");
		printf_s("lower limit: ");
		start = get_long();
		printf_s("upper limit: ");
		stop = get_long();
	}
	printf_s("Done.\n");
}
long get_long(void)
{
	long input;
	char ch;
	while (scanf_s("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf_s(" is not an integer.\nPlease enter an ");
		printf_s("integer value, such as 25, -178, 0r 3: ");
		
	}
	return input;
}
double sum_squares(long a, long b)
{
	double total = 0;
	long i;
	for (i = a; i <= b; i++)
		total += (double)i * (double)i;
	return total;
}
bool bad_limit(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf_s("%ld isn't smaller than %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf_s("Values must be %ld or greater.\n", low);
		not_good = true;
	}
	if (end > high || begin > high)
	{
		printf_s("Values must be %ld or less.\n", high);
		not_good = true;
	}
	return not_good;
}