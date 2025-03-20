// 14.18.7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<stdlib.h>
#include"mybook.h"


int main()
{
    book library_f[MAXBKS] = { },library_s[MAXBKS]={ };
    int count = 0;
    int filecount = 0;
    int real = 0;
    char choice;
    int size = sizeof(book);
    FILE *pbooks;
    

    if (fopen_s(&pbooks, "newbook.dat", "r+b"))
    {
        fputs("Can't open newbook.dat file\n", stderr);
        exit(1);
    }

    rewind(pbooks);//回到文件开头

    while (fread(&library_f[real], size, 1, pbooks) == 1)
    {
        if (real == 0)
            puts("Current contents of books.dat:");

        if (library_f[real].delete_flag != 1)
        {
            printf_s("%s by %s: $%.2f\n", library_f[real].title,
                library_f[real].author, library_f[real].value);
            library_s[count] = library_f[real];
            count++;
        }
        real++;
    }

    printf_s("\n");
    filecount = count;
    do
    {
        printf_s("Enter your choice to operate with books(enter q to leave):\n"
            "a.To add the new record.      d.To delete a record.\n"
            "c.To change a record.         p.print\n");
        switch ((choice = get_char()))
        {
        case 'a':rewind(pbooks);
            input(library_s, pbooks,filecount,real);
            break;
        case 'd':rewind(pbooks);
             delete_record( pbooks,library_s,filecount);
            break;
        case 'c':
            break;
        case 'p':rewind(pbooks);
            print(library_s, filecount, pbooks,real);
            break;
        case 'q':printf_s("Bye!\n");
            break;
        }
    } while (choice != 'q');
    if (pbooks != 0)
        fclose(pbooks);
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
