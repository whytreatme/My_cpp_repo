// 链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

Node* getNewNode(int val)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = val;
    p->next = NULL;
    return p;
}

Node* insert(Node* head,int pos,int val)
{
    if (pos==0)
    {
        Node* p = (Node*)malloc(sizeof(Node));
        p->data = val;
        p->next = head;
        return p;
    }
    Node* p;
    int i = 1;
    for (p = head; i < pos; p=p->next,i++);
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = val;
    q->next = p->next;
    p->next = q;
    return head;
}

void outputNode(Node* head)
{
    int i = 0;
    for (Node* p = head; p; p = p->next, i++)
    {
        printf_s("%3d", i);
        printf_s("  ");
    }
    printf_s("\n");
    for (Node* p = head; p; p = p->next)
    {
        printf_s("%3d", p->data);
        printf_s("->");
    }
    printf_s("\n\n\n");
}

void clear(Node* head)
{
    if (head == NULL)return ;
    for (Node* p = head, *q; p; p = q)
    {
        q = p->next;
        free(p);
    }
}

int main()
{
    srand(time(0));
    #define MAX_OP 7
    Node* head = getNewNode(12);
    for (int i = 0; i < MAX_OP; i++)
    {
        int pos = rand() % (i + 2);
        int val = rand() % 100;
        head = insert(head, pos, val);
        printf_s("insert %d at %d to Node\n",
            val, pos);
        outputNode(head);
    }
    
    clear(head);

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
