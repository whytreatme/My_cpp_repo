// 13.11.12.book.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define row 20
#define col 30

int main(int argc,char*argv[])
{
    FILE* fin, * fout;
    int data[row][col];
    char file_input[] = "C:\\Users\\h\\Desktop\\picture.txt";
    char file_output[] = "graphic";
    char convert[10] = { ' ','.','\'',':','~','*','=','$','%','#' };
    if (fopen_s(&fin, file_input, "r"))//使用索引实现数值符号转换更方便
    {
        fprintf_s(stderr, "Can't open file%s", file_input);
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&fout, file_output, "w"))
    {
        fprintf_s(stderr, "Can't open file%s", file_output);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            if (fscanf_s(fin, "%d", &data[i][j]) != 1)//fscanf_s只能识别字符
                exit(EXIT_FAILURE); /*不能使用二进制数据，在精度要求不是很很准确是
    }                               /*还是使用字符文本*/
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf_s("%c", convert[data[i][j]]);//使用字符数组的索引
            fprintf_s(fout, "%c", convert[data[i][j]]);
        }
        printf_s("\n");
        fprintf_s(fout, "\n");
    }
    fclose(fin);
    fclose(fout);
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
