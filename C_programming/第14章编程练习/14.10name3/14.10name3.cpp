// 14.10name3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#define SLEN 81
struct namect {
    char *fname;
    char *lname;
    int letters;
};
void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);
char* s_gets(char* st, int n);
int main()
{
    struct namect person;
    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);
    cleanup(&person);
    return 0;
}
void getinfo(struct namect *pst)
{
    char temp[SLEN];
    puts("Please enter your first name.");
    s_gets(temp, SLEN);
    pst->fname = (char*)malloc(strlen(temp) + 1);
    strcpy_s(pst->fname,strlen(temp)+1, temp);
    printf_s("Please enter your last name.\n");
    s_gets(temp, SLEN);
    pst->lname = (char*)malloc(strlen(temp) + 1);
    strcpy_s(pst->lname,strlen(temp)+1, temp);
 
}
void makeinfo(struct namect *pst)
{
    (* pst).letters = strlen(pst->fname) + strlen(pst->lname);
    
}
void showinfo(const struct namect* pst)
{
    printf_s("%s %s, your name contains %d letters.\n",
        pst->fname, pst->lname, pst->letters);
}
void cleanup(struct namect* pst)
{
    free(pst->fname);
    free(pst->lname);
}
char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
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
