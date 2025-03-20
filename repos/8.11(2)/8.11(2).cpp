// 8.11(2).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    int ch, count = 0;
    printf_s("Please input words:\n");
    while ((ch = getchar()) != EOF)
    {
        if (count % 10 == 0)
            printf_s("\n");
        if (ch >= 32)
            putchar(ch);
        else if (ch == 9)
            printf_s("\\t");
        else if (ch == 10)
            printf_s("\\n");
        else
            printf_s("\^%c", ch + 64);
      
            printf_s("%d ", ch);
        count++;
    }
  /*  int counter = 0;
    char ch;
    while ((ch = getchar()) != EOF) {
        if (counter++ == 10) {
            printf_s("\n");
            counter = 1;
        }
        if (ch >= '\040') {
            printf_s("\'%c\'--%3d", ch, ch);
        }
        else if (ch == '\n') {
            printf_s("\\n--\\n\n");
            counter = 0;
        }
        else if (ch == '\t') {
            printf_s("\\t--\\t");
        }
        else
            printf_s("\'%c\'--^%c", ch, (ch + 64));
    }
    return 0;*/
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
