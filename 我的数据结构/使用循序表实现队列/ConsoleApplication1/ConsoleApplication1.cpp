// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Vector
{
	int* data;
	int size;
}Vector;


typedef struct Queue
{
	Vector* data;
	int size, head, tail, count;
}Queue;


Vector* initVector(int n)
{
	Vector* p = (Vector*)malloc(sizeof(Vector));
	p->data = (int*)malloc(sizeof(int) * n);
	p->size = n;
	return p;
}

int insertVector(Vector* v, int pos, int val)
{
	if (pos < 0 || pos >= v->size)return -1;
	v->data[pos] = val;
	return 1;
}

int vectorSeek(Vector* v, int pos)
{
	if (pos < 0 || pos >= v->size)return -1;
	return v->data[pos];
}

void clearVector(Vector* v)
{
	if (v == NULL)return;
	free(v->data);
	free(v);
	return;
}

Queue* initQueue(int n)
{
	Queue* p = (Queue*)malloc(sizeof(Queue));
	p->data = initVector(n);
	p->size = n;
	p->head = p->tail = p->count = 0;
	return p;
}

int front(Queue* q)
{
	int s = 0;
	s=vectorSeek(q->data, q->head);
	return s;
}

int empty(Queue* q)
{
	return q->count == 0;
}

int push(Queue* q, int val)
{
	if (q->count == q->size)return 0;
	insertVector(q->data, q->tail, val);
	q->count += 1;
	q->tail += 1;
	if (q->tail == q->size)q->tail = 0;
	return 1;
}

int pop(Queue* q)
{
	if (empty(q))return 0;
	q->head += 1;
	q->count -= 1;
	printf_s("Now head is %d\n", q->head);
	return 1;
}

void outputQueue(Queue* q)
{
	printf_s("Queue: ");
	for (int i = 0; i < q->count; i++)
		printf_s("%4d", vectorSeek(q->data, (q->head + i) % q->size));
	printf_s("\n\n");
}

void clearQueue(Queue* q)
{
	if (q == NULL)return;
	clearVector(q->data);
	free(q);
	return;
}

int main()
{
	srand(time(0));
#define MAX_OP 20
	Queue* q = initQueue(5);
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
