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

Node* insert(Node* head, int pos, int val)
{
    Node new_head, * p = &new_head, * node = getNewNode(val);
    new_head.next = head;
    for (int i = 0; i < pos; i++)
        p = p->next;
    node->next = p->next;
    p->next = node;
    return new_head.next;
}

//超级笨办法实现链表反转
//Node* reverseList(Node* head) 
//{
//    if (head == NULL) return head;
//    Node* p = head;
//    int i = 0, count = 0;
//    for (i = 0; p; p = p->next)
//        i++;
//    count = i;
//    Node* reverse_head, new_head, * q = &new_head;
//    new_head.next = head;
//    for (int i = 0; i < count; i++)
//    {
//        q = q->next;
//    }
//    reverse_head = q;
//    q = &new_head;
//    for (int j = 0;j<count-1;j++)
//    {
//        for (int i = 0; i < count -1 - j; i++)
//        {
//            q = q->next;
//        }
//        q->next->next = q;
//        q = &new_head;
//    }
//    new_head.next->next = NULL;
//    return reverse_head;
//}

//使用递归形式实现链表反转
//Node* reverseList(Node* head) {
//    if (head == NULL || head->next == NULL) return head;
//    Node* tail = head->next, * new_head;
//    new_head = reverseList(head->next);
//    head->next = tail->next;
//    tail->next = head;
//    return new_head;
//}

//使用链表头插法实现链表反转
Node* reverseList(Node* head) {
    Node* p = head, * q, new_head;
    new_head.next = NULL;
    while (p)
    {
        q = p->next;
        p->next = new_head.next;
        new_head.next = p;
        p = q;
    }
    return new_head.next;
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
    if (head == NULL)return;
    for (Node* p = head, *q; p; p = q)
    {
        q = p->next;
        free(p);
    }
}

int main()
{
    srand(time(0));
    Node* head = NULL;
    for (int i = 0; i < 8; i++)
    {
        int val = rand() % 100;
        head = insert(head, i, val);
    }
    outputNode(head);
    head = reverseList(head);
    outputNode(head);

    clear(head);
    return 0;
}
