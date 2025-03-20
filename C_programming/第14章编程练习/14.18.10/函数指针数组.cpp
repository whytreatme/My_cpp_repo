#include<stdio.h>
#include<string.h>

double add(double x, double y);
double times(double x, double y);
void get_num(double *,double *);
char get_char(void);


int main()
{
	double a=0, b=0,c=0;
	char choice;
	double (*p[2])(double, double);
	p[0] = add; p[1] = times;
	do
	{
		puts("Please input two nums to operate:");
		get_num(&a, &b);
		printf_s("Choose an operation you want to make:(q to quit):\n");
		printf_s("a.to add two numbers to product the sum      b.to time two numbers to product the ji\n"
		"q.to quit\n");
		choice = get_char();
		
		switch (choice)
		{
		case 'a':c=p[0](a, b);
			break;
		case 'b':c=p[1](a, b);
			break;
		default:
			break;
		}
		printf_s("\n");
	} while(choice!='q');
}

void get_num(double* first, double* second)
{
	
	scanf_s("%lf %lf", first, second);
	while (getchar() != '\n')
		continue;
}
char get_char()
{
	char c=0;
	c = getchar();
	while (getchar() != '\n')
		continue;
	return c;
}

double add(double x, double y)
{
	double z = 0;
	z = x + y;
	printf_s("The sum is %.2lf", z);
	return z;
}

double times(double x, double y)
{
	double z = 0;
	z = x * y;
	printf_s("The ji is %.2lf", z);
	return z;
}

