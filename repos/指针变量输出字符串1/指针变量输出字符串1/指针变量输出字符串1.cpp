﻿// 指针变量输出字符串1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    char a[]="I am a student.",b[20]={'\0'};
    int i;
    for (i = 0; *(a + i) != '\0'; i++)
    {
        *(b + i) = *(a + i);
    }
    *(b + i) = '\0';
    printf_s("string a is:%s\n", a);
    printf_s("string b is:%s\n", b);
   /* printf_s("string b is:\n");
    for (i = 0; *(b + i) != '\0'; i++)
        printf_s("%c", *(b + i));
    printf_s("\n");*/

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
