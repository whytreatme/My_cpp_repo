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
#define MAX_OP 7
    Node* head = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int pos = rand() % (i + 1);
        int val = rand() % 100;
        head = insert(head, pos, val);
        printf_s("insert %d at %d to Node\n",
            val, pos);
        outputNode(head);
    }

    clear(head);

    return 0;
}
