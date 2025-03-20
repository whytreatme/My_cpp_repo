// append.cpp -- 把文件附加到另一个文件的末尾
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 4096
# define SLEN 81
void append(FILE* source, FILE* dest);
char* s_gets(char* st, int n); 
int main()
{
	FILE* fa, * fs;//fa指向目标文件，fs指向源文件
	int files = 0;    //附加文件数量
	char file_app[SLEN];   //目标文件名
	char file_src[SLEN];   //源文件名
	int ch;

	puts("Enter name of destination file:");
	s_gets(file_app, SLEN);
	if (fopen_s(&fa, file_app, "a+") != 0)
	{
		fprintf_s(stderr, "Can't open %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can't create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter the name of first source file (empty line to quit):");
	while (s_gets(file_src,SLEN)&&file_src[0]!='\0')
	{
		if (strcmp(file_src, file_app) == 0)
			fputs("Can't append file to itself\n", stderr);
		else if (fopen_s(&fs, file_src, "r") != 0)
			fprintf_s(stderr, "Can't open %s file.\n", file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZ) != 0)
			{
				fputs("Can't create input buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)//末尾判断是error返回EOF,还是feof返回EOF
				fprintf_s(stderr, "Error in reading file %s.\n", file_app);
			fclose(fs);
			files++;
			printf_s("Files %s appended.\n", file_src);
			puts("Next file (empty line to quit):");
		}
		
	}
	printf_s("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf_s("%s contents:\n", file_app);
	while ((ch=getc(fa))!=EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);
	return 0;
}
void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZ];  //只分配一次
	while ((bytes = fread(temp, sizeof(char), BUFSIZ, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);



}
char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); //查找换行符
		if (find)    //如果地址不是NULL
			*find = '\0';  //在此放置一个空字符
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
