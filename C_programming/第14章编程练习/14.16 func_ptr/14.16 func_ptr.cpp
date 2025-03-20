// 14.16 func_ptr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
void eatline(void);
void show(void(*fp)(char*), char* str);
void ToUpper(char*);
void ToLower(char*);
void Transpose(char*);
void Dummy(char*);

int main()
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void(*pfun)(char*);
	pfun = NULL;  
	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u':pfun = ToUpper; break;
			case 'l':pfun = ToLower; break;
			case 't':pfun = Transpose; break;
			case 'o':pfun = Dummy; break;
			}
			strcpy_s(copy, line);
			show(pfun, copy);
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");
	return 0;
}
char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u) uppercase       l) lowercase");
	puts("t) transposed case o) original case");
	puts("n) next string");
	ans = getchar();
	ans = tolower(ans);
	eatline();
	while (strchr("ulton", ans) == NULL)
	{
		puts("Please enter a u, l, t, o, or n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}
void Dummy(char* st)
{

}
void show(void(*fp)(char*), char* str)
{
	(*fp)(str);
	puts(str);
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
