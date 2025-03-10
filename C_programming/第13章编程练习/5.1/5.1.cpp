// 5.1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 256
int main(int argc,char *argv[])
{
    FILE* fp = NULL;
    char line[SIZE];
    char seeker;
    if (argc != 3)
    {
        fprintf_s(stderr, "Usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    else {
        if (strlen(argv[1]) != 1)
        {
            printf_s("The second parameter should be a char.\n");
            exit(EXIT_FAILURE);
        }
        if (fopen_s(&fp, argv[2], "r") != 0)
        {
            printf_s("Can't open file %s.\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        
        seeker = argv[1][0];
            while (fgets(line, SIZE, fp) != NULL)//每次读一行
            {
                char* p = line;//指向一行开头
                while(*p!='\0')
                if (*p++ == seeker)
                {
                    printf_s("FOUND %c IN LINE :%s", seeker, line);
                    break;
                }

            }
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
