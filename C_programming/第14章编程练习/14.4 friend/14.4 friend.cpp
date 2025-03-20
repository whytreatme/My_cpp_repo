// 14.4 friend.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#define LEN 20

struct names {
    char first[LEN];
    char last[LEN];
};
struct guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main()
{
    struct guy fellow[2] = {
        { { "Ewen","Villard",},
        "grilled salmon",
        "personality coach",
        68112.00
    },
    {
        { "Rodney","Swillbelly"},
         "Tripe",
         "tabloid editor",
         432400.00
    }
};
    struct guy* him;
    printf_s("address#1: %p #2: %p\n", &fellow[0], &fellow[1]);
    him = &fellow[0];
    printf_s("pointer #1: %p #2: %p\n", him, him + 1);
    printf_s("him->income is $%.2f: (*him).income is $%.2f\n",
        him->income, (*him).income);
    him++;
    printf_s("him->favfood is %s: him->handle.last  is %s\n", him->favfood,
        him->handle.last);
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
