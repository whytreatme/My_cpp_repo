// 13.11.9.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41
int get_number(FILE*);
int main()
{
	int counter=0;
	FILE* fp;
	char words[MAX];
	words[MAX - 1] = '\0';//字符串存在数组中，一定要加'\0'，接下来要用fscanf输入
	if (fopen_s(&fp, "wordy.txt", "a+"))//判断是否安全打开
	{
		fprintf(stderr, "Can't open\"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	counter = get_number(fp);
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");//按#结束
	while ((fscanf_s(stdin, "%40s", words, (unsigned)_countof(words)) == 1) && (words[0] != '#'))
		fprintf(fp, "%d.%s\n", ++counter,words);//从键盘读入，存放在words数组中
								   //%40使用words前40个单元，如果成功分配字段
								   //用fprintf写到文件中，因为fscanf无法读入空格
	puts("File contents:");
	rewind(fp);//返回文件开始处
	while (fscanf_s(fp, "%40s", words, (unsigned)_countof(words)) == 1)
		puts(words);//从文件读入，存在words 中,并输出,puts会自动加换行符
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0;
}
int get_number (FILE* fp)//要加序号，首先要知道文件中有多少个单词
{
	char num[MAX];
	int i = 0;
	rewind(fp);
	while (fgets(num, MAX, fp) != NULL)//在本题中一个单词占一行，用fgets来读
		i++;
	return i;
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
