// 13.11.10.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>

int main()
{
    char ch;
    FILE *fp=NULL ;
    char fname[100] = { '\0' };
    //char buffer[256];
    int i;
    printf_s("Enter the file's name:\n");
    scanf_s("%s", fname, (unsigned)_countof(fname));
    if (fopen_s(&fp, fname, "r") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.", fname);
        exit(EXIT_FAILURE);
    }
    printf_s("Enter a location(Enter a negtive num or char to quit):\n");
    while (scanf_s("%d", &i) == 1 && i >= 0)
    {
        fseek(fp, i * 1L, SEEK_SET);
        while ((ch = getc(fp)) != '\n')//也可以使用fgets输出
            putchar(ch);//if(fgets(buffer,256*sizeof(char),fp)!=NULL)
        printf_s("\n");// printf_s("Content is :%s",buffer);
        printf_s("Enter a location(Enter a negtive num or char to quit):\n");
    }
   
    if (fp != 0)
        fclose(fp);
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
