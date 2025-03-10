// 二分法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    int head = 1;
    int tail = 100;
    int guess = (head + tail) / 2;
    char ch;
    printf_s("Pick an integer from 1 to 100 . I will try to guess ");
    printf_s("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    do {
        printf_s("Uh...is your number %d?\n", guess);
        if (getchar() == 'y')break;
        printf_s("Well, then, %d is larger or smaller than yours?(l or s):", guess);
        while ((ch = getchar()) == '\n')continue;
        if (ch == 'l' || ch == 'L') {
            tail = guess - 1;
            guess = (head + tail) / 2;
            continue;
        }
        else if (ch == 's' || ch == 'S') {
            head = guess + 1;
            guess = (head + tail) / 2;
            continue;
        }
        else
            continue;
    } while (getchar() != 'y');
    printf_s("I knew I could do it!\n");
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
