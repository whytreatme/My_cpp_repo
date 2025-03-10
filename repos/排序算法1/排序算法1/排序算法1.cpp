// 排序算法1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
	void sort(int *x, int n);
	int a[10], * p, i;
	printf_s("Please enter the nums:\n");
	p = a;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", p++);
	}
	p = a;
	sort(p, 10);
	for (; p < a + 10;)
		printf_s("%d ", *p++);
	printf_s("\n");
}
/*void sort(int* x, int n)
{
	int i, j, t;
	for (i = 0; i < n - 1; i++)
	{
	
		for (j = i + 1; j < n; j++)
		{
			if (x[i] < x[j])
			{
				t=x[i],x[i]=x[j],x[j]=t;
			}
		}
	}
}*/
void sort(int* x, int n)
{
	int * i, * j, k;
	j = x + 1;
	for (i = x; i < x + n - 1; i++)
	{
		for (j=i+1; j < x + n ;j++)
		{
			if (*i < *j)
			{
				k = *i; *i = *j; *j = k;
			}
			
		}
	}
}/**/













// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
