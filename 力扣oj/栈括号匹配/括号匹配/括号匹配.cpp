// 括号匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack
{
    char* data;
    int size, top;
}stack;

stack* init_stack(int val)
{
    stack* st = (stack*)malloc(sizeof(stack));
    st->data = (char*)malloc(sizeof(char) * val);
    st->top = -1;
    st->size = val;
    return st;
}

int empty(stack* st)
{
    return st->top == -1;
}

int push(stack* st, char ch)
{
    if (st->top + 1 == st->size)return 0;
    st->top += 1;
    st->data[st->top] = ch;
    return 1;
}
char top(stack* st)
{
    if (empty(st))return -1;
    return st->data[st->top];
}

int pop(stack* st)
{
    if (empty(st))return 0;
    st->top -= 1;
    return 1;
}
void clear_stack(stack* s)
{
    if (s == NULL)return;
    free(s->data);
    free(s);
    return;
}

bool isValid(const char* s) {
    int i = 0;
    while (s[i])i++;
    stack* st = init_stack(i);
    int j = 0;
    while (s[j])
    {
        switch (s[j])
        {
        case '(':
            push(st, s[j]);
            break;

        case '{':
            push(st, s[j]);
            break;

        case '[':
            push(st, s[j]);
            break;

        case ')':
            if (s[j] == top(st))
                pop(st);
            break;

        case '}':
            if (s[j] == top(st))
                pop(st);
            break;

        case ']':
            if (s[j] == top(st))
                pop(st);
            break;
        }
        j++;
    }
    if (empty(st))return true;
    else
        return false;
    clear_stack(st);
}
int main()
{
    bool tried = false;
    const char* s = "()";
    tried = isValid(s);
    printf_s("我的人生好悲哀\n");
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
