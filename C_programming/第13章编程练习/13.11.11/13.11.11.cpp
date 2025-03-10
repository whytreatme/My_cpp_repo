// 13.11.11.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256

int string_in(char* st, char* sub);
int main(int argc,char*argv[])
{
    FILE* fp;
    char buffer[SIZE];
    char* seek_string;
   if (argc < 3)
    {
        fprintf_s(stderr, "Usage %s string file_name...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    seek_string = argv[1];
    if (fopen_s(&fp, argv[2], "r") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.",argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, SIZE, fp) != NULL)
    {
        //if (strstr(buffer, seek_string))
           if (string_in(buffer, seek_string))
                puts(buffer);
    }
    return 0;
}
int string_in(char* st, char* sub)
{
    size_t count = 0;
    size_t src_len = strlen(sub);
    while (*st != '\0' && count < src_len)
    {
        if (*(st + count) == *(sub + count))
            count++;
        else
        {
            count=0;
            st++;
        }
    }
    if (count == src_len)return 1;
    else return 0;
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
