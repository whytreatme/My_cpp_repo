﻿// 14.2manybook.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>

char* s_gets(char* st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main()
{
	struct book library[MAXBKS];
	int count = 0;
	int index;
	printf_s("Please enter the book title.\n");
	printf_s("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf_s("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf_s("Now enter the value.\n");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf_s("Enter the next title.\n");
	}
	if (count > 0)
	{
		printf_s("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf_s("%s by %s:$%.2f\n", library[index].title,
				library[index].author, library[index].value);
	}
	else
		printf_s("No books? Too bad.\n");
	return 0;
}
char* s_gets(char* st, int n)
{
	char *ret_val;
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
