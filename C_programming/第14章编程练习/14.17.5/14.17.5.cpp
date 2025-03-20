// 14.17.5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

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
int main()
{
	int i, num, total = 0;
	printf_s("Enter the number of month:\n");
	scanf_s("%d", &num);
	for (i = 0; i < num; i++)
		total += year[i].days;
	if (num > 0)
	{
		printf_s("The total days form beginning to %s is %d"
			, year[num - 1].month, total);
	}
	return 0;
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
