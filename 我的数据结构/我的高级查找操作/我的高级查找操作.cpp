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
    if (pos == 0)
    {
        Node* p = (Node*)malloc(sizeof(Node));
        p->data = val;
        p->next = head;
        return p;
    }
    Node* p;
    int i = 1;
    for (p = head; i < pos; p = p->next, i++);
    Node* q = (Node*)malloc(sizeof(Node));
    q->data = val;
    q->next = p->next;
    p->next = q;
    return head;
}

int outputNode(Node* head,int flag)
{
    int len = 0, i = 0;
    for (Node* p = head; p; p = p->next, i++)
    {
        len = printf_s("%3d", i);
        printf_s("  ");
    }
    printf_s("\n");
    for (Node* p = head; p; p = p->next)
    {
        printf_s("%3d", p->data);
        printf_s("->");
    }
    if (flag == 0)
        printf_s("\n\n\n");

    else
        printf_s("\n");
    return len;
}

int findNode(Node* head, int val)
{
    if (head == NULL)return 0;
    int len, count, i = 0;

    for (Node* p = head; p; p = p->next,i++)
    {
        if (p->data == val)
        {
            count = outputNode(head,1);
            for (int j = 0; j < 2*i+i*count ; j++)
                printf_s(" ");
            printf_s(" ↑");
            printf_s("\n\n\n");
            return 1;
        }
      
    }
    return 0;
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
#define MAX_OP 20
    Node* head = NULL;
    for (int i = 0; i < MAX_OP; i++)
    {
        int op = rand() % 4;
        int pos, val;
        switch (op)
        {
        case 0:
        case 1:
        case 2:
             pos = rand() % (i + 1);
             val = rand() %15;
            head = insert(head, pos, val);
            printf_s("insert %d at %d to Node\n",
                val, pos);
            outputNode(head,0);
            break;
        case 3:
            printf_s("Now is find\n");
            val = rand() % 15;
            printf_s("find %d at list \n", val);
            int ret = findNode(head, val);
            i -= 1;
            break;
        }
       
       
    }

    clear(head);

    return 0;
}
