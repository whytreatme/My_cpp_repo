// menu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 
#include <stdio.h>
float get_float(void);
char get_choice(void);
char get_first(void);
int main()
{
	float result,a1,a2;
    int choice;
	while ((choice = get_choice()) != 'q')//每次循环不断读取，遇到q退出
	{
		printf_s("Enter first number:");//输入第一个参数
		a1 = get_float();
		printf("Enter second number:");
		a2 = get_float();
		switch (choice)
		{
		case 'a':result = a1 + a2;//结构一致switch中执行运算
			printf_s("%.1f + %.1f = %.1f\n", a1, a2, result);
			break;
		case 's':result = a1 - a2;
			printf_s("%.1f - %.1f = %.1f\n", a1, a2, result);
			break;
		case 'm':result = a1 * a2;
			printf_s("%.1f * %.1f = %.1f\n", a1, a2, result);
			break;
		case 'd':
			if (0 == a2)//特殊情况
			{
				printf_s("Enter a number other than 0:");
				a2 = get_float();//重新输入
			}
			result = a1 / a2;
			printf_s("%.1f / %.1f = %.1f\n", a1, a2, result);
			break;
		}
	}
	printf_s("Bye.\n");
	return 0;
}
char get_choice(void)
{
	int ch;
	printf_s("Enter the operation of your choice:\n");
	printf_s("a. add            s. subtract\nm. multiply       d. divide\n");
	printf_s("q. quit\n");
	ch = get_first();
	while ((ch != 'a') && (ch != 's') && (ch != 'd') && (ch != 'm') && (ch != 'q'))
	{
		printf_s("Please respond with a, s, m, d, q.\n");
		ch = get_first();
	}//错误输入验证
	return ch;
}
char get_first(void)
{
	int ch;
	while ((ch = getchar()) == '\n')//舍弃换行，但是只能输入一个字符
		continue;
	while (getchar() != '\n');//把剩下字符舍弃
	return ch;
}
float get_float(void)
{
	int ch;
	float num;
	while ((scanf_s("%f", &num)) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf_s(" is not an number.\nPlease enter a number, such as 2.5, -1.78E8, or 3:");
		continue;
	}//错误输入验证
	return num;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
