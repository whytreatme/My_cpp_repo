// 15.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#define N 5
int main()
{
    void firstaverage(int* pt[4]);
    void find(int* pt[4]);
    void excllent(int* pt[4]);
    int* score[4],i,j,n;
    void (*p)(int* pt[4]);
    for (i = 0; i < 4; i++)
    {
        score[i] = (int*)malloc(5 * sizeof(int));
        printf_s("Please input the scores:\n");
        for (j = 0; j < 5; j++)
            scanf_s("%d", (score[i] + j));
    }
    for (i = 0; i < N; i++)
    {
        printf_s("choose 1,2or3:\n");
        scanf_s("%d", &n);
        switch (n)
        {
        case 1:p = firstaverage; p(score); break;
        case 2:p = find; p(score); break;
        case 3:p = excllent; p(score); break;
        }
    }
    for (i = 0; i < 4; i++)
    {
        free(score[i]);
    }
}
void excllent(int* pt[4])
{
    int i,d=0,j,*q,av,s;
    for (i = 0; i < 4; i++)
    {
        for (s=0,j=0,q=pt[i]+j; j < 5; j++)
        {
            if (*q < 85)d++;
            s += *q;
        }
        av = s/ 5;
        if ((d == 0 )|| (av >= 90))printf_s("No.%d is excllent\n", i + 1);
        d = 0;
    }
}
void find(int* pt[4])
{
    int i, j,k,d,sum=0,aver;
    for (i = 0; i < 4; i++)
    {
        for (d=0,j = 0; j < 5; j++)
        {
            if (*(pt[i] + j) < 60)
            {
                d++;
            }
            if (d >= 2) {
                printf_s("No.%d has two scores failed\n All of his scores are:\n", i + 1);
                for (k = 0; k < 5; k++)
                {
                    printf_s("%d  ", *(pt[i] + k));
                    sum += *(pt[i] + k);
                }
                printf_s("\n");
                aver = sum / 5;
                printf_s("His aver score are:%d\n",  aver);
                break;
            }
        }
    }
}
void firstaverage(int* pt[4])
{
    int k,sum=0,aver;
    for (k = 0; k < 4; k++)
    {
        sum += *pt[k];
    }
    aver = sum / 4;
    printf_s("The first course's average score is:%d\n", aver);
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
