
/* addword.cpp --使用fprintf()、fscanf和rewind()*/
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 41

int main()
{
	FILE* fp;
	char words[MAX];
	words[MAX - 1] = '\0';//字符串存在数组中，一定要加'\0'，接下来要用fscanf输入
	if (fopen_s(&fp, "wordy.txt", "a+"))//判断是否安全打开
	{
		fprintf(stderr, "Can't open\"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}
	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");//按#结束
	while ((fscanf_s(stdin, "%40s", words,(unsigned)_countof(words)) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);//从键盘读入，存放在words数组中
                                   //%40使用words前40个单元，如果成功分配字段
	                               //用fprintf写到文件中，因为fscanf无法读入空格
	puts("File contents:");
	rewind(fp);//返回文件开始处
	while (fscanf_s(fp, "%40s", words,(unsigned)_countof(words)) == 1)
		puts(words);//从文件读入，存在words 中,并输出,puts会自动加换行符
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");
	return 0; 
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
