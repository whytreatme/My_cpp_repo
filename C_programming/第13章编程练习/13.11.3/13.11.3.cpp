// 13.11.3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define LEN 100
int main()
{
    FILE* fp = NULL;
    char file[LEN];
    file[LEN - 1] = '\0';
    char ch;
    long now=0;
    printf_s("Please enter the file name:\n");
    scanf_s("%s", file, (unsigned)_countof(file));
    if (fopen_s(&fp, file, "rb+") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.", file);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF)
    {
       if ((now = ftell(fp)) > 0)
            fseek(fp, -1L, SEEK_CUR);
        putc(toupper(ch), fp);
        fflush(fp);//刷新缓冲区极其重要
      
    }
    if (fp != 0)
        fclose(fp);
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
