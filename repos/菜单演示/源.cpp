/*菜单演示.cpp--菜单程序*/
#include<stdio.h>
char get_choice(void);
void count(void);
char get_first(void);
int get_int(void);
int main()
{
	char choice;
	while ((choice=get_choice())!='q')
	{
		switch (choice)
		{
		case'a':printf_s("Buy low, sell high.\n");
			break;
		case'b':putchar('\a');
			break;
		case'c':count();
			break;
		default:printf_s("Program error!\n");
			break;
		}
	}
}

char get_choice(void)//get意味着包含错误输入的维护，确保可以正确运行
{
	int ch;
	printf_s("Enter the letter of your choice:\n");
	printf_s("a.advice               b.bell\n");
	printf_s("c.count                q.quit\n");
	ch = get_first();
	while ((ch < 'a' || ch>'c') && ch != 'q')
	{
		printf_s("Please respond with a, b, c, or q.\n");
		ch = get_first();
	}
	return ch;
}

char get_first(void)
{
	char ch;
	//while ((ch = getchar())=='\n')//凡有getchar()必考虑是否把换行符读入
	  //  continue;
	ch = getchar();
	while (getchar() != '\n')
		continue;
	return ch;
}

void count(void)
{
	int n, i;
	printf_s("Count how far? Enter an integer:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
		printf_s("%d\n", i);
#define DEBUG 1
#ifdef DEBUG
	while (getchar() != '\n')
		continue; 
#endif // DEBUG

}

int get_int(void)
{
	char cx;
	int input;
	while ((scanf_s("%d", &input)) != 1)
	{
		while ((cx = getchar()) != '\n')
			putchar(cx);
		printf_s(" is not an integer.\nPlease enter an integer like 1, -123, 90:");

	}
	return input;
}