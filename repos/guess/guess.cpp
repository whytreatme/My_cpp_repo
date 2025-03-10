// guess.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    char response;
    int guess = 1;
    printf_s("Pick an integer from 1 to 100.I will try to guess");
    printf_s("it.\nRespond with a y if my guess is right and with");
    printf_s("\nan n if it is wrong.\n");
    printf_s("Uh...is your number%d?\n", guess);
    while ((response=getchar() )!= 'y')
    {
        if (response == 'n')
            printf_s("Well, then, is it %d?\n", ++guess);
        else
            printf_s("sorry, I don't understand only y or n.\n");
        while (getchar() != '\n')//就是while里再套一个while循环
            continue;              //并用这个循环把除第一个字符外的同一行字符
    }                              // 吃掉，包括换行符 
    printf_s("I knew I could do it !\n");
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
