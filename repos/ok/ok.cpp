// ok.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    char ch;
    FILE* fp = NULL;
    if (argc != 2)
    {
        fprintf_s(stderr, "Can't open %s.file.\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&fp, argv[1], "r"))//路径写入要用双斜杠，如果文件放在
        printf_s("文件打开失败！\n");
    else
        printf_s("文件打开成功！\n");
    if (fp != 0)                 //和项目文件同一个文件夹使用相对路径也可以
        while ((ch = getc(fp)) != EOF)
            putc(ch, stdout);
    if (fp != 0)
        fclose(fp);

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
