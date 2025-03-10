// 14.18.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
int input(struct book *ps[100]);
void output(struct book *ps[100],const int count);
void letter(struct book *ps[100], const int count);
void price(struct book *ps[100], const int count);

int main()
{
	int i,num = 0;
	struct book library[MAXBKS],* pf[100];
	for (i = 0; i < 100; i++)
		pf[i] = &library[i];
	num=input(pf);
	output(pf,num);
	letter(pf, num);
	price(pf, num);
	return 0;
}
int input(struct book* ps[100])
{
	int count = 0;
	printf_s("Please enter the book title.\n");
	printf_s("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets((* ps)[count].title, MAXTITL) != NULL
		&& (* ps)[count].title[0] != '\0')
	{
		printf_s("Now enter the author.\n");
		s_gets((*ps)[count].author, MAXAUTL);
		printf_s("Now enter the value.\n");
		scanf_s("%f", &(*ps)[count++].value);
		while (getchar() != '\n')
			continue;
		if (count < MAXBKS)
			printf_s("Enter the next title.\n");
	}
	return count;
}
void letter(struct book *ps[100], const int count)
{
	int i, j;
	struct book temp;
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (strcmp((* ps)[i].title, (* ps)[j].title)>0)
			{
				temp = (* ps)[i]; (* ps)[i] = (* ps)[j];
				(* ps)[j] = temp;
			}
		}
	}
	output(ps, count);
}
void price(struct book *ps[100], const int count)
{
	int i,j;
	struct book temp;
	for (i = 0; i < count-1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if ((*ps)[i].value > (*ps)[j].value)
			{
				temp = (*ps)[i]; (*ps)[i] = (*ps)[j];
				(*ps)[j] = temp;
			}
		}
	}
	output(ps, count);

}

void output(struct book *ps[100],const int count)
{
	int index;
	if (count > 0)
	{
		printf_s("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf_s("%s by %s:$%.2f\n", (*ps)[index].title,
				(*ps)[index].author,(*ps)[index].value);
	}
	else
		printf_s("No books? Too bad.\n");
	printf_s("\n");
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
