// 14.17.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<string.h>
#define N 20
typedef struct lens {
	float folen;
	float fstop;
	char brand[30];
}LENS;
char* s_gets(char* st, int n);
int main()
{
	LENS cam[10];
	/*char lines[N];
	printf_s("Enter the brand of camera:\n");
	s_gets(lines, N);
	strcpy_s(cam[2].brand, lines);
	cam[2].folen = 500.0;
	cam[2].fstop =  2.0;
	printf_s("So camera N0.3 is %s cam. And"
		" folen is %.1f,fstop is %.1f", cam[2].brand,
		cam[2].folen, cam[2].fstop);*/
	
	return 0;
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
