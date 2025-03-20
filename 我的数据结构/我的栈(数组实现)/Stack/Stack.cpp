// Stack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Stack
{
    int* data;
    int size, top;
}Stack;

Stack* initStack(int val)
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * val);
    s->size = val;
    s->top = -1;
    return s;
}

int empty(Stack* s)
{
    return s->top == -1;
}

int top(Stack* s)
{
    if (empty(s))return -1;
    return s->data[s->top];
}

int push(Stack* s,int val)
{
    if (s->top + 1 == s->size)return 0;
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack* s)
{
    if (empty(s))return 0;
    s->top -= 1;
    return 1;
}

void outputStack(Stack* s)
{
    printf_s("Stack is: \n");
    for (int i = s->top; i >= 0; i--)
        printf_s("%4d", s->data[i]);
    printf_s("\n\n");
}

void clearStack(Stack* s)
{
    if (s == NULL)return;
    free(s->data);
    free(s);
}

int main()
{
    srand(time(0));
#define MAX_OP 10
    Stack* st = initStack(8);
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 3, val = rand() % 100;
        switch (op)
        {
        case 0:
            printf_s("Top item is %d:\n", top(st));
            pop(st);
            break;
        case 1:
        case 2:
            printf_s("Push value %d to the Stack:\n", val);
            push(st, val);
            break;
        }
        outputStack(st);
    }
    clearStack(st);
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
