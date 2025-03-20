// 16.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <stdio.h>
int main()
{
    char str[50],*pstr;
    int i, j, k, m, e10, digit, ndigit, a[10], * pa;
    printf_s("input a string:\n");
    gets_s(str);
    pstr = &str[0];
    pa = &a[0];
    ndigit = 0;//代表有多少个整数
    i = 0;
    j = 0;//j用来计数截取的一小段字符
    while (*(pstr + i) != '\0')
    {
        if((*(pstr+i)>='0')&&(*(pstr+i)<='9'))
            j++;
        else//和我一样，先遍历，以碰到的下一个非数字字符为条件读取数字
        {
            if (j > 0)
            {
                digit = *(pstr + i - 1) - 48;//强转类型赋给变量digit,输入个位
                k = 1;
                while (k < j)//
                {
                    e10 = 1;
                    for (m = 1; m <= k; m++)
                        e10 = e10 * 10;//数位器
                    digit = digit + (*(pstr + i - 1 - k) - 48) * e10;//每次取的数字都与数位对应
                    k++;
                }
                *pa = digit;
                ndigit++;//
                pa++;
                j = 0;
        }
        }
        i++;
    }
    if (j > 0)//以数字结尾字符串的最后一个数据
    {
        digit = *(pstr + i - 1) - 48;
        k = 1;
        while (k < j)
        {
            e10 = 1;
            for (m = 1; m <= k; m++)
                e10 = e10 * 10;
            digit = digit + (*(pstr + i - 1 - k) - 48) * e10;
            k++;
        }
        *pa = digit;
        ndigit++;
        j = 0;
    }
    printf_s("There are %d numbers in the line,they are:\n", ndigit);
    j = 0;
    pa = &a[0];
    for (j = 0; j < ndigit; j++)
        printf_s("%d ", *(pa + j));
    printf_s("\n");
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
