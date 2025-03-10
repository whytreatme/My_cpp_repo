// 13.11.7.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 200
#define SIZE 600
void print_a(FILE*, FILE*);
void print_b(FILE*, FILE*);
char* deal(char*);
int main(int argc,char *argv[])
{
    
    char ch,d;
    FILE* fp = NULL, * gp = NULL;
 if (argc != 3)
    {
        fprintf_s(stderr, "Error!");
        exit(EXIT_FAILURE);
    }
    else
    {
    if (fopen_s(&fp, argv[1], "r") != 0)
    {
        fprintf_s(stderr, "Can't open %s file.",argv[1]);
        exit(EXIT_FAILURE);
    }
    else if (fopen_s(&gp, argv[2], "r") != 0)
    {//处理字符文件还是以文本模式打开，使用"rb"有"\r\n"要处理两个
        fprintf_s(stderr, "Can't open %s file.", argv[2]);
        exit(EXIT_FAILURE);
    }
    else
    {
        printf_s("Which ways you want to print the file?(choose a or b,q to quit):\n");
        while (((scanf_s("%c", &ch, 1)) == 1) && (ch != 'q'))
        {
            while (getchar() != '\n')
                continue;
            if ('a' == ch)print_a(fp, gp);
            else if ('b' == ch)print_b(fp, gp);
            else
                printf_s("try again!\n");
             
            printf_s("Which ways you want to print the file?(choose a or b,q to quit):\n");
        }

    }
       }
    if(fp!=0)
    fclose(fp);
    if(gp!=0)
    fclose(gp);
        return 0;
    
    
    }
void print_a(FILE* fp, FILE* gp)
{
    char line[LEN]={'\0'}, lines[LEN]={'\0'};
    int f1=0, g1=0;
    while ((f1=feof(fp))==0&&(g1=feof(gp))==0)//以文件结尾为测试条件
    {   
        fgets(line, LEN, fp);//第一个文件读一行
        fputs(line, stdout);//打印
        if ((f1=feof(fp)) != 0)//判断第一个文件是否读完
            printf_s("\n");
        fgets(lines, LEN, gp);//第二个文件读一行
        fputs(lines, stdout);
    }
    printf_s("\n");
    if(f1==0)//第一个文件没有读完
        while (fgets(line, LEN, fp) != NULL)
            fputs(line, stdout);
        
    if (g1 == 0)//第二个文件没有读完
        while (fgets(lines, LEN, gp) != NULL)
            fputs(lines, stdout);
        
    rewind(fp);
    rewind(gp);
    printf_s("\n");
}
void print_b(FILE* fp, FILE* gp)
{
    char line[LEN] = { '\0' };
    char onlyline[SIZE]={'\0'};
    int f1 = 0, g1 = 0;
    while ((f1 = feof(fp)) == 0 && (g1 = feof(gp)) == 0)
    {
        fgets(onlyline,SIZE,fp);
        fgets(line, LEN,gp);
        strcat_s(onlyline, line);//合并两个字符串
        deal(onlyline);//字符串处理
        fputs(onlyline,stdout);
    
    }
    printf_s("\n");
    if (f1 == 0)
        while (fgets(line, LEN, fp) != NULL)
            fputs(line, stdout);

    if (g1 == 0)
        while (fgets(line, LEN, gp) != NULL)
            fputs(line, stdout);
  
        rewind(fp);
   
        rewind(gp);
        printf_s("\n");
}
char* deal(char* p)
{
    char* ret_val=p;
    int i = 0;
    if (ret_val)
    {
        while (p[i] != '\0' && p[i] != '\n')
            i++;//找到字符串中的换行符，把它换成空格
        if (p[i] == '\n')
            p[i] = ' ';
       
    }
    return ret_val;
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
