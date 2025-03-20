// 19.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#define NEWSIZE 1000
char newbuf[NEWSIZE];
char* newp = newbuf;
int main()
{
    char* Mynew(int n);
    void free(char* p);
    char* str = NULL,arr[60]={'\0'};
    int i;
    str = Mynew(50);
    printf_s("input a string:\n");
    scanf_s("%s", arr,(unsigned)_countof(arr));
    for (i = 0; arr[i] != '\0'; i++)
        *(str + i) = arr[i];
    *(str + i + 1) = '\0';
    printf_s("%s", str);
    free(str);
}
char *Mynew(int n)
{
    if (newp + n <= newbuf + NEWSIZE)
    {
        newp += n;
        return(newp - n);
    }
    else return(NULL);  
}
void free(char* p)
{
    if (p >= newbuf && p <= newbuf + NEWSIZE)
    {
        newp = p;
    }
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
