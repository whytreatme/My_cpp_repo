// 14.18.6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define NA 25
#define TN 19
struct name
{
	char fname[NA];
	char lname[NA];
};
typedef struct {
  struct{
		char fname[NA];
		char lname[NA];
	};
  int match;
  int bat;
  int run;
  int hit;
  float safehit;
}player;
player team[TN] = { };//可以使用空的花括号使结构所有成员初始化为0
void eatline(FILE*);
void aversafe();
void print();
int main()
{
	char fline[NA]={'\0'}, lline[NA]={'\0'};
	int data[5],i=0;
	FILE* fp;
	if (fopen_s(&fp, "C:\\Users\\h\\Desktop\\bat.txt", "r") != 0)
	{
		fprintf_s(stderr, "Can't open bat.txt");
		exit(EXIT_FAILURE);
	}
	while (feof(fp) == 0)
	{
		fscanf_s(fp,"%d %s %s %d %d %d %d", &data[0], fline, (unsigned)_countof(fline),
			lline, (unsigned)_countof(lline), &data[1], &data[2], &data[3], &data[4]);
		if (feof(fp) != 0)
			break;
		eatline(fp);
		strcpy_s(team[data[0]].fname,sizeof(team[data[0]].fname), fline);
		strcpy_s(team[data[0]].lname,sizeof(team[data[0]].lname), lline);
		team[data[0]].match += data[1];
		team[data[0]].bat += data[2];
		team[data[0]].run += data[3];
		team[data[0]].hit += data[4];
		i++;
	}
	aversafe();
	print();
	if (fp != 0)
		fclose(fp);
	return 0;
}
void eatline(FILE*fp)
{
	char c;
	while ((c=getc(fp)) != '\n')
		continue;
	
}
void aversafe()
{
	int i;
	for (i = 0; i < TN; i++)
		team[i].safehit = (float)team[i].bat / (float)team[i].match;
}
void print()
{
	int i;
	for (i = 0; i < TN; i++)
		printf_s("%d %s %s %d %d %d %d %.2f\n", i, team[i].fname, team[i].lname,
			team[i].match, team[i].bat, team[i].run, team[i].hit, team[i].safehit);
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
