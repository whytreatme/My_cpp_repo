// 自制strcmp函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <stdio.h>
int main()
{
    int Mystrcmp(char* p1, char* p2), a;
    char* str1, * str2,cx[60],dx[60];
    str1 = cx; str2 = dx;
    printf_s("please input the first string:\n");
    gets_s(cx);
    printf_s("please input the second string:\n");
    gets_s(dx);
    printf_s("\n");
    a = Mystrcmp(str1, str2);
    printf_s("result:%d", a);
}
int Mystrcmp(char* p1, char* p2)
{
    int i=0, d=0;
    while ((*(p1 + i) != '\0') && (*(p2 + i) != '\0'))
    {
        d = *(p1 + i) - *(p2 + i);
        if (d > 0)
            break;
        else if (d < 0)
            break;
        i++;
    }
    return d;
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
