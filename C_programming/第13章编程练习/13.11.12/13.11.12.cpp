// 13.11.12.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
int main()
{
    FILE* fp = NULL,*gp=NULL;
    if (fopen_s(&fp, "picture.txt", "r+") )
    {
        fprintf_s(stderr, "Can't open picture.txt file.");
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&gp, "C:\\Users\\h\\Desktop\\picture.txt", "w"))
    {
        fprintf_s(stderr, "Can't open this file.");
        exit(EXIT_FAILURE);
    }
    int pic[20][30],(* p1)[30], i, j;
    char pic_a[20][31],(*p2)[31];
    p1 = pic;
    p2 = pic_a;
    for (i = 0; i < 20; i++)
    {
        j = 30;
        pic_a[i][j] = '\0';
    }
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++)
        {
            
            fread((*(p1 + i) + j), sizeof(int), 1, fp);
            fprintf_s(gp,"%c ",(char) * (*(p1 + i) + j) +48);
        }
        fprintf_s(gp,"\n");
    }
   /* for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++)
        {
            scanf_s("%d", (*(p1 + i) + j));
            fwrite((*(p1 + i) + j), sizeof(int), 1, fp);
        }
        printf_s("OK!\n ");
    }*/
    rewind(fp);
   for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 30; j++)
        {
           
            fread((*(p1 + i) + j), sizeof(int), 1, fp);
            
            switch(*(*(p1+i)+j))
            {
            case 0:*(*(p2+i)+j)=' ';
                  break;
            case 1:*(*(p2+i)+j)='.';
                   break;
            case 2:*(*(p2+i)+j)='\'';
                   break;
            case 3:*(*(p2+i)+j)=':';
                  break;
            case 4:*(*(p2+i)+j)='~';
                  break;
            case 5:*(*(p2+i)+j)='*';
                   break;
            case 6:*(*(p2+i)+j)='=';
                  break;
            case 7:*(*(p2+i)+j)='&';
                   break;
            case 8:*(*(p2+i)+j)='%';
                   break;
            case 9:*(*(p2 + i) + j) = '#';
                   break;
            default:break;

            }
        }
     
    }
    for (i = 0; i < 20; i++)
            printf_s("%s\n", *(p2 + i));
    
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
