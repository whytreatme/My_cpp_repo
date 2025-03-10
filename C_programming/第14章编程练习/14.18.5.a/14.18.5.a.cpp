// 14.18.5.a.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define CSIZE 4

struct name {
    char fname[20];
    char lname[20];
};
typedef struct student {
    struct  {
        char fname[20];
        char lname[20];
    };
    float grade[3];
    float aver;
}STUDENT;
void eatline();
void personal_aver(STUDENT[]);
void print(STUDENT[]);

int main()
{
    float score[3];
    int i;
    char fline[25]={'\0'}, lline[25]={'\0'};
    STUDENT pul[CSIZE] = {
        {{"Stephen","Prata"}},
        {{"Kenneth","Rosen"}},
        {{"Ilon","Mask"}},
        {{"Arthur","Lee"}}
    };
    for (i = 0; i < 4; i++)
    {
        printf_s("Enter the student's name and grade:"
            "(like Hellen Kaller 12 23 45):\n");
        scanf_s("%s %s %f %f %f", fline,(unsigned)_countof(fline),
            lline,(unsigned)_countof(lline),
            &score[0], &score[1], &score[2]);
        eatline();
        for (int j = 0; j < CSIZE; j++)
        {
            if (strcmp(fline, pul[j].fname) == 0 && strcmp(lline, pul[j].lname) == 0)
            {
                pul[j].grade[0] = score[0]; pul[j].grade[1] = score[1];
                pul[j].grade[2] = score[2];
                break;
            }
         }
    }
    printf_s("---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    personal_aver(pul);
    print(pul);
    return 0;
}
void eatline()
{
    while (getchar() != '\n')
        continue;
}
void personal_aver(STUDENT ps[])
{
    int i;
    
    for (i = 0; i < CSIZE; i++)
    {
        ps[i].aver = (ps[i].grade[0] + ps[i].grade[1] + ps[i].grade[2]) / 3.0;
    }
}
void print(STUDENT ps[])
{
    float result=0;
    int i;
    for (i = 0; i < CSIZE; i++)
    {
        printf_s("%s %s's scores are: %.2f %.2f %.2f\n"
            "His or Her average is %.2f\n",
            ps[i].fname, ps[i].lname, ps[i].grade[0], ps[i].grade[1], ps[i].grade[2]
        ,ps[i].aver);
        result  += ps[i].grade[0] + ps[i].grade[1] + ps[i].grade[2];
        
    }
    printf_s("The whole average is %.2f", result / 12);
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
