// 14.13 funds4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#define FUNDLEN 50
#define N 2
struct funds {
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};
double sum(const struct funds money[], int n);
int main()
{
    struct funds jones[N] = {
   {    "Garlic-Melon Bank",
        4032.27,
        "Lucky's Savings and Loan",
        8543.94
    },
    {
        "Honest Jack's Bank",
        3620.88,
        "Party Time Savings",
        3802.91
    }
    };
    printf_s("The Joneses have a total of $%.2f.\n", sum(jones, N));
    return 0;
}
double sum(const struct funds money[], int n)
{
    double total;
    int i;
    for (i = 0, total = 0; i < n; i++)
        total += money[i].bankfund + money[i].savefund;
    return(total);
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
