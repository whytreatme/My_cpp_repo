// 定积分1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include<math.h>
int main()
{
    void integral(double(*p)(double x), double a1, double a2);
    double fsin(double x);
    double fcos(double y);
    double fexp(double z);
    int k, g;
    double c1, c2;
    for (k = 0; k < 3; k++)
    {
        printf_s("Please choose 1,2or3 to integ:");
        scanf_s("%d", &g);
        printf_s("Enter the two limits:");
        scanf_s("%lf,%lf", &c1, &c2);
        if (g == 1)
        {
            printf_s("The integral of sin(x)is:\n");
            integral(fsin, c1, c2);
        }
        else if (g == 2)
        {
            printf_s("The integral of cos(x)is:\n");
            integral(fcos, c1, c2);
        }
        else {
            printf_s("The integral of exp(x)is:\n");
            integral(fexp, c1, c2);
        }
    }
}
int n = 200000;
void integral(double(*p)(double x), double a1, double a2)
{
    double s1,sum=0,i;
    s1 = (a2 - a1) / n;
    for (i = 0; i < n; i++)
    {
        a1 += s1;
        sum += (*p)(a1) * s1;
    }
    printf_s("%lf\n", sum);
}
double fsin(double x)
{
    return sin(x);
}
double fcos(double y)
{
    return cos(y);
}
double fexp(double z)
{
    return exp(z);
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
