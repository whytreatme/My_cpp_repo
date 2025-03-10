// 我重新开始了1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
	void inv(int * x, int n);
	int i, a[9] = { 3,7,9,8,0,6,7,5,4 },*d;
	printf_s("the original array:\n");
	for (i = 0; i < 9; i++)
		printf_s("%d", a[i]);
	printf_s("\n");
	inv(a, 9);
	printf_s("The array has been inverted:\n");
	for (d = a; d < a + 9; d++)
	{
		printf_s("%d", *d);
	}
	printf_s("\n");
}

void inv(int *x, int n)
{
	int *i,*j, temp,*p;
	i = x; j = x + n - 1; p = x + int((n - 1) / 2);
	for (;i<=p;i++,j--)
	{
		temp = *i;
		*i = *j;
		*j = temp;
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

//  
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
