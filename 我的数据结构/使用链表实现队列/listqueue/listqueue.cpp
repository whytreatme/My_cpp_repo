// listqueue.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node
{
	int data;
	Node* next;
}Node;

typedef struct Linklist
{
	Node head, * tail;
}Linklist;

typedef struct Queue
{
	Linklist* l;
	int count;
}Queue;

Node* initNode(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
		node->data = val;
	node->next = NULL;
	return node;
}

Linklist* initLinklist(Linklist* l)
{
	l = (Linklist*)malloc(sizeof(Linklist));
	l->tail = &(l->head);
	l->head.next = NULL;
	return l;
}

Queue* initQueue()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->l = initLinklist(q->l);
	q->count = 0;
	return q;
}

int emptyQueue(Queue* q)
{
	return q->count == 0;
}

int emptyLinklist(Linklist* l)
{
	return l->head.next == NULL;
}

void insertTail(Linklist* l,int val)
{
	Node* node = initNode(val);
	l->tail->next = node;
	l->tail = node;
}

void eraseHead(Linklist* l)
{
	Node* node;
	node = l->head.next;
	l->head.next = node->next;
	if (node == l->tail)
		l->tail = &(l->head);
	free(node);
}

int front(Queue* q)
{
	if (emptyLinklist(q->l))return 0;
	return q->l->head.next->data;
}

int push(Queue* q,int val)
{
	insertTail(q->l, val);
	q->count += 1;
	return 1;
}

int pop(Queue* q)
{
	if (emptyLinklist(q->l))return 0;
	eraseHead(q->l);
	q->count -= 1;
	return 1;
}

void clearLinklist(Linklist* l)
{
	Node* p = l->head.next, * q;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	free(l);
}

void outputQueue(Queue* q)
{
	Node* n = q->l->head.next;
	printf_s("Queue: ");
	for (int i = 0; i < q->count; i++,n=n->next)
		printf_s("%4d",n->data);
	printf_s("\n\n");
}

void clearQueue(Queue* q)
{
	clearLinklist(q->l);
	free(q);
	return;
}

int main()
{
	srand(time(0));
#define MAX_OP 10
	Queue* q = initQueue();
	for (int i = 0; i < MAX_OP; i++)
	{
		int op = rand() % 4, val = rand() % 100;
		switch (op)
		{
		case 0:
		case 1:
			printf_s("front of queue:%d\n", front(q));
			pop(q);
			break;
		case 2:
		case 3:
			printf_s("Push %d to queue: \n", val);
			push(q, val);
			break;
		}
		outputQueue(q);
	}
	clearQueue(q);

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
