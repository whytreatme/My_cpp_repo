// 13.11.7.book.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define LINE_SIZE 256
int main(int argc ,char * argv[])
{
    char* line_one = (char*)malloc(LINE_SIZE * sizeof(char));
    char* line_two = (char*)malloc(LINE_SIZE * sizeof(char));
    
    if (argc != 3)
    {
        fprintf_s(stderr, "Usage:%s filename", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* fp1, * fp2;
    if (fopen_s(&fp1, argv[1], "r") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.",argv[1]);
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&fp2, argv[2], "r") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.", argv[2]);
        exit(EXIT_FAILURE);
    }
    printf_s("Print the line one by one.\n");
    int i = 1;
    while (fgets(line_one, LINE_SIZE, fp1) != NULL)
    {//第一个文件读一行
        if (fgets(line_two, LINE_SIZE, fp2) != NULL)
        {//使用条件判读不循环，每次只读第二个文件的一行
            printf_s("File 1  LINE  NO. %d:  %s", i, line_one);
            printf_s("File 2  LINE  NO. %d:  %s", i, line_two);
            i++;
        }
        else {//如果第一文件还有，那继续循环只读第一个文件
            printf_s("File 1  LINE  NO. %d:  %s", i, line_one);
            i++;
        }
    }
    //如果第二个文件还有，就继续读
    while (fgets(line_two, LINE_SIZE, fp2) != NULL)
        printf_s("File 2  LINE  NO. %d:  %s", i++, line_two);
    printf_s("\nPrint the combine line.\n");
    rewind(fp1);//不关闭文件，是指针回到文件开头
    rewind(fp2);
    i = 1;
    while (fgets(line_one, LINE_SIZE, fp1) != NULL)
    {
        if (fgets(line_two, LINE_SIZE, fp2) != NULL)
        {
            printf_s("LINE NO. %d:", i);
            while (*line_one != '\n')//第一个文件把除换行符打印出来
                putchar(*line_one++);//只是打印出来，没必要再申请缓冲区
            putchar('+');
            printf_s("%s", line_two);
            i++;
        }
        else
        {
            printf_s("LINE NO.%d : %s", i, line_one);
            i++;
        }
    }
    while (fgets(line_two, LINE_SIZE, fp2) != NULL)
        printf_s("LINE NO.%d :%s",i++, line_two);
    fclose(fp1);
    fclose(fp2);
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
