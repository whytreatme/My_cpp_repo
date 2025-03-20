// 14.12 flexmemb.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>

struct flex {
	size_t count;
	double average;
	double score[];//伸缩型数组成员
};
void showFlex(const struct flex* p);
int main()
{
	struct flex* pf1, * pf2;
	size_t n = 5;
	int i;
	double tot = 0;
	pf1 =(struct flex*) malloc(sizeof(struct flex) + n * sizeof(double));
	pf1->count = n;
	for (i = 0; i < n; i++)
	{
		pf1->score[i] = 20.0 - i;
		tot += pf1->score[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);
	n = 9;
	tot = 0;
	pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; i++)
	{
		pf2->score[i] = 20.0 - i/2.0;
		tot += pf2->score[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
	return 0;
}
void showFlex(const struct flex* p)
{
	int i;
	printf_s("Scores: ");
	for (i = 0; i < p->count; i++)
		printf_s("%g ", p->score[i]);
		printf_s("\nAverage: %g\n", p->average);
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
