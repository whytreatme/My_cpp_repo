// reducto.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40
int main(int argc,char* argv[])
{
    FILE* in, * out;
    int ch;
    char name[LEN];
    int count = 0;
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&in, argv[1], "r")!=0)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    strncpy_s(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat_s(name, ".bed");
    if (fopen_s(&out, name, "w")!=0)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }
    while ((ch=getc(in))!=EOF)
    {
        if (count++ % 3 == 0)
            putc(ch, out);
        if (fclose(in) != 0 || fclose(out) != 0)
            fprintf(stderr, "Erroe in closing files\n");
        return 0;  
    }
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
