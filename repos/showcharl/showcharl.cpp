// showcharl.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
void displace(char cr, int lines, int width);
int main()
{
    int ch;
    int rows, cols;
    printf_s("Enter a character and two integers:\n");
    while ((ch = getchar()) != '\n')
    {
        if (scanf_s("%d %d", &rows, &cols) != 2)
            break;
        displace((char)ch, rows, cols);
        while (getchar() != '\n')
            continue;
        printf_s("Enter another charater and two integers:\n");
        printf_s("Enter a newline to quit.\n");
    }
    printf_s("Bye.\n");
}
void displace(char cr, int lines, int width)
{
    int row, col;
    for (row = 1; row <= lines; row++)
    {
        for (col = 1; col <= width; col++)
            putchar(cr);
        printf_s("\n");
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
