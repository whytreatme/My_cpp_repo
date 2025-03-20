// countc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int ch;
    FILE* fp=NULL;//在本程序里没有打开任何文件，后续使用fopen，只是必要
    unsigned long count = 0;//传个参数，fp如果不为空则fclose(fp)无法正常关闭文件
    if (argc != 2)
    {
        printf_s("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (( fopen_s(&fp,argv[1], "r")) == NULL)
    {
        printf_s("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((ch = getchar()) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    if(fp!=NULL)//空指针无法关闭，判断必不可少
    fclose(fp);
    printf_s("File %s has %lu characters\n", argv[1], count);
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
