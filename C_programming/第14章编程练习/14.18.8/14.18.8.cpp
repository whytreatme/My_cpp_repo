// 14.18.8.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#define NA 40
typedef struct {
    char sit_num[NA];
    int book;
    char fname[NA];
    char llname[NA];
}passger;
void show_menu();
char get_choice();
int main()
{
    show_menu();
    return 0;
}
void show_menu()
{
    int choice;
    do {
        puts("To choose a function, enter its letter label:");
        printf_s("a) Show number of empty seats\n"
            "b) Show list of empty seats\n"
            "c) Show alphabetical list of seats\n"
            "d) Assign a customer to a seat assignment\n"
            "e) Delete a seat assigment\n"
            "f) Quit");
        switch (choice = get_choice())
        {

        }
    } while (choice != 'f');
}
char get_choice()
{
    char c;
    c = getchar();
    while (getchar() != '\n')
        continue;
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
