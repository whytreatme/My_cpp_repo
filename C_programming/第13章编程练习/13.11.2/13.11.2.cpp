// 13.11.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#define LEN 100
int main(int argc,char *argv[])
{
    FILE* fp, * gp;
    char line[LEN];
    if (argc != 3)
    {
        fprintf_s(stderr, "error!");
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&fp, argv[1], "rb") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&gp, argv[2], "wb") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.", argv[2]);
        exit(EXIT_FAILURE);
    }
    size_t bytes;
    while ((bytes=fread(line, sizeof(char), LEN, fp)) > 0)
        fwrite(line, sizeof(char), bytes, gp);
    if (fp != 0)
        fclose(fp);
    if (gp != 0)
        fclose(gp);
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
