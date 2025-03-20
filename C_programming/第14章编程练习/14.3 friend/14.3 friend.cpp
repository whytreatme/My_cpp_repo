// 14.3 friend.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#define LEN 20
const char* msgs[5] = {
    "  Thank you for the wonderful evening,",
    "You certainly prove that a ",
    "is a special kind of guy.We must get together",
    "over a delicious ",
    " and have a few laughs"
};
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
    struct guy fellow = {
        "Ewen","Villard",
        "grilled salmon",
        "personality coach",
        68112.00
    };
    printf_s("Dear %s, \n\n", fellow.handle.first);
    printf_s("%s%s.\n", msgs[0], fellow.handle.first);
    printf_s("%s%s\n", msgs[1], fellow.job);
    printf_s("%s\n", msgs[2]);
    printf_s("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
    if (fellow.income > 150000.0)
        puts("!!");
    else if (fellow.income > 75000.0)
        puts("!");
    else
        puts(".");
    printf_s("\n%40s%s\n", " ", "See you soon,");
    printf_s("%40s%s\n", " ", "Shalala");
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
