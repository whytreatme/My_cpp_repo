// 简单排序1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>

int main()
{
    void exchange(int *q1,int *q2,int *q3);
    int a, b, c,i, * p1, * p2, * p3;
    for (i = 0; i<6; ++i) 
    {
        printf_s("Please enter the num:\n");
        scanf_s("%d,%d,%d", &a, &b, &c);
        p1 = &a, p2 = &b, p3 = &c;
        exchange(p1, p2, p3);
        printf_s("The order is:%d,%d,%d\n", a, b, c);
    }
}
void exchange(int* q1, int* q2, int* q3) {
    void swap(int* c1, int* c2);
   
        if (*q1 < *q3) swap(q1, q3);
        if (*q2 < *q3) swap(q2, q3);
        if (*q1 < *q2) swap(q1, q2);
   
   
}

void swap(int* c1, int* c2) {
    int temp;
    temp = *c1;
    *c1 = *c2;
    *c2 = temp;
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
