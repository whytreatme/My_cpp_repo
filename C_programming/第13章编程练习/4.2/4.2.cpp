// 4.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    
    float num,sum = 0.0, aver;
    int counter= 0;
    FILE* fp = NULL;

#ifdef DEBUG
    if (argc != 2)
    {
        fprintf_s(stderr, "Can't open %s file.", argv[0]);
        exit(EXIT_FAILURE);
    }
    else if (fopen_s(&fp, argv[1], "wb") != 0)
    {
        fprintf_s(stderr, "Can't open the %s file.", argv[1]);
        exit(EXIT_FAILURE);
    }
    else {
        while (fscanf_s(stdin, "%f", &num) == 1)
            fwrite(&num, sizeof(float), 1, fp);
    }
    if (fp == 0)
        fclose(fp);
    return 0;
#endif // DEBUG

   if (argc == 1)
    {
        fp = stdin;
        printf_s("Enter the number(EOF to end input):\n");
    }
    else if (argc == 2)
    {
        if (fopen_s(&fp, argv[1], "rb") != 0)
        {
            fprintf_s(stderr, "Can't open the %s file.", argv[1]);
            exit(EXIT_FAILURE);
        }
        
    }
    else {
       printf_s("Usage:%s filename\n", argv[0]);
       exit(EXIT_FAILURE);
   }
    if(fp!=0)
    while (fread(&num, sizeof(float),1, fp) != 0 && !feof(fp))
    {
        printf_s("%.3f ", num);
        sum += num;
        counter++;
    }
    printf_s("\n");
    if (counter > 0)
        aver = sum / counter;
    else
        aver = 0;
    printf_s("average of data is %.3f", aver);
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
