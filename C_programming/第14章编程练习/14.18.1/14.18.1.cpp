// 14.18.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#define N 15
struct months {
	char month[18];
	char abbr[4];
	int days;
	int num;
};
struct months year[12] = {
	{"January","Jan",31,1},
	{"February","Feb",28,2},
	{"March","Mar",31,3},
	{"April","Apr",30,4},
	{"May","May",31,5},
	{"June","Jun",30,6},
	{"July","Jul",31,7},
	{"August","Aug",31,8},
	{"September","Sep",30,9},
	{"October","Oct",31,10},
	{"November","Nov",30,11},
	{"December","Dec",31,12}
};
char* s_gets(char* st, int n);
int count_days(char*);
int main()
{
	char monthname[N];
	
	printf_s("Enter a capitalize month name: (empty a line to quit)\n");
	s_gets(monthname, N);
	while (monthname[0]!='\0')
	{
		printf_s("The total to %s is %d \n", monthname, count_days(monthname));
		printf_s("Enter a capitalize month name: (empty a line to quit)\n");
		s_gets(monthname, N);
	}
	printf_s("Done.");
	return 0;
}
int count_days(char*pa)
{
	int i,total=0;
	for (i = 0; i < 12; i++)
	{
		if (strcmp(pa, year[i].month) == 0)
		{
			for (int n = 0; n < i + 1; n++)
				total += year[n].days;
			return total;
		}
	}
	return -1;
	
	
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n,stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
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
