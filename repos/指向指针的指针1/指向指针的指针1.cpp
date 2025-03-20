// 指向指针的指针1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLINESIZE 20
int main()
{
	void Bubble_sort(char** pt);
	void Select_sort(char** pt);
	char str[5][MAXLINESIZE], ** p, * pstr[5];
	int i;
	printf_s("input 5 strings:\n");
	for (i = 0; i < 5; i++)
		scanf_s("%s", str[i], (unsigned)_countof(str[i]));
	for (i = 0; i < 5; i++)
		pstr[i] = str[i];
	p = pstr;
	Select_sort(p);
	printf_s("the correct order is:\n");
	for (i = 0; i < 5; i++)
		printf_s("%s\n", *(p + i));
}
void Bubble_sort( char** pt)//冒泡排序
{
	int i, j,count=0;
	char *temp;
	for (i = 0; i < 4; i++)//每一轮都会有一个字符串沉底，至多是个数少一轮可以把所有的排序
	{
		for (j = 0; j < 4 - i; j++)/*每一轮沉底一个就少需要比较一个，
								   特别要注意是j和j + 1比较，所以j最大只能到3        */
		{
			if (strcmp(( * (pt + j)), ( * (pt + j + 1)))>0)//比较两个字符串
			{
				temp = *(pt + j);
				*(pt+j) = *(pt+j+1);
				*(pt + j + 1) = temp;//交换地址
				count = 1;
			}
		}
		if (count == 0)break;
	}
	printf_s("\n");
}
void Select_sort(char** pt)//选择法排序
{

	int i, j;
	char* temp;
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(*(pt + j), *(pt + i)) < 0)
			{
				temp = *(pt + i);
				*(pt + i) = *(pt + j);
				*(pt + j) = temp;
			}
		}
	}
	printf_s("\n");
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
