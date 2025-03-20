// 指向函数的指针1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    int max(int, int);
    int  min(int, int);
    int a, b, c, n,(*p)(int,int);
    printf_s("Please enter a and b:\n");
    scanf_s("%d,%d", &a, &b);
    printf_s("Please choose 1 or 2:\n");
    scanf_s("%d", &n);
    if(n==1)
    {
        p = max;
        c = (*p)(a, b);
        printf_s("a=%d,b=%d,max=%d",a,b,c);
    }
    else {
        p = min;
        c = (*p)(a, b);
        printf_s("a=%d,b=%d,min=%d", a, b, c);
    }
}
int max(int x, int y)
{    
    int z;
    if (x > y)z = x;
    else z = y;
    return z;
}
int min(int a, int b)
{
    int k;
    if (a < b)k = a;
    else k = b;
    return k;
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
