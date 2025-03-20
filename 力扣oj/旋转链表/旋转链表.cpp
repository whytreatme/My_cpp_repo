// 旋转链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int data;
    ListNode* next;
}ListNOde;

//使用递归方法做
//ListNode* rotateRight(ListNode* head, int k) {
//    if (head == NULL)return head;
//    if (head->next == NULL)return head;
//    if (k == 0) return head;
//    struct ListNode* p, * new_head;
//    head = rotateRight(head, k - 1);
//    p = head;
//    while (p->next->next)
//        p = p->next;
//    new_head = p->next;
//    new_head->next = head;
//    p->next = NULL;
//    return new_head;
//}

ListNode* rotateRight(ListNode* head, int k)
{
    if (head == NULL)return head;
    if (head->next == NULL)return head;
    ListNode* p = head;
    int i = 1, j = 0;
    while (p->next)
    {
        p = p->next;
        i++;
    }
    k %= i;
    p->next = head;
    while (j!=(i - k))
    {
        p = p->next;
        j++;
    }
    ListNode* new_head;
    new_head = p->next;
    p->next = NULL;
    return new_head;
}

ListNode* getNewNode(int val)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

ListNode* insert(ListNode* head, int pos, int val)
{
    ListNode new_head, * p = &new_head, * node = getNewNode(val);
    new_head.next = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    node->next = p->next;
    p->next = node;

    return new_head.next;
}

void clear(ListNode* head)
{
    if (head == NULL)return;
    for (ListNode* p = head, *q; p; p = q)
    {
        q = p->next;
        free(p);
    }
}
void outputNode(ListNode* head)
{
    int i = 0;
    for (ListNode* p = head; p; p = p->next, i++)
    {
        printf_s("%3d", i);
        printf_s("  ");
    }
    printf_s("\n");
    for (ListNode* p = head; p; p = p->next)
    {
        printf_s("%3d", p->data);
        printf_s("->");
    }
    printf_s("\n\n\n");
}

int main()
{
    ListNode* head = NULL;
    int i;
         for(int i=5;i>0;i--)
        head = insert(head, 0, i);
    outputNode(head);
    head = rotateRight(head,2);
    outputNode(head);
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
