// 14.18.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

typedef struct date {
	int year_s;
	int day_s;
	char month_s[N];
	int num;

}DATE;
const struct months year[13] = {
	{},
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
int count_days(const DATE*);
void get_date(DATE*);
void eatline(void);
int main()
{   
	int ai;
	DATE *my_choice,opg;
	my_choice= &opg;
     get_date(my_choice);
	ai=count_days(my_choice);
	printf_s("Total to %d D %s M %d Y is % d", my_choice->day_s,
		my_choice->month_s, my_choice->year_s, ai);
	return 0;
}
void get_date(DATE*pf)
{   
	
	puts("Enter the year (like 2018):");
	scanf_s("%d", &pf->year_s);
	eatline();
	puts("Enter the month (can be name,num or abbr):");
	s_gets(pf->month_s, N);
	if (strlen(pf->month_s) < 3) {
		if(strlen(pf->month_s)==1)
		pf->num = pf->month_s[0] - 48;
	else if (strlen(pf->month_s) == 2)
		pf->num = (pf->month_s[0] - 48) + (pf->month_s[1] - 48) * 10;
	}
	puts("Enter the days:");
	scanf_s("%d", &pf->day_s);
	if( (pf->day_s > 31)
		|| (pf->day_s < 0))
	{
		printf_s("The days are betwen 0 and 31, or maybe there haven't"
			"got 31 days in this month, so try again:\n");
	}
}
void eatline()
{
	while (getchar() != '\n')
		continue;
}
int count_days(const DATE*pf)
{
	int i, total = 0;
	
	for (i = 1; i <=12; i++)
	{
		if ((pf->num == year[i].num) || (strcmp(pf->month_s, year[i].month) == 0)
			|| strcmp(pf->month_s, year[i].abbr) == 0)
		{//使用判断三者有其一与设置月份相同
			if (pf->day_s > year[i].days)return -1;//如果输入天数超过该月天数，出错
			return total + pf->day_s;//在该情况下加入输入天数
		}
		else
			total += year[i].days;//非所选月份即累加
	}
	return -1;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
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
