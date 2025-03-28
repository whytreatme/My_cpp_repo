﻿// 顺序表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector
{
	int size, count;
	int* data;
} vector;

vector* getNewvector(int n)
{
	vector* p = (vector*)malloc(sizeof(vector));
	p->size = n;
	p->count = 0;
	p->data = (int*)malloc(sizeof(int) * n);
	return p;
}

void output_vector(vector* v)
{
	
	int len = 0;
	for (int i = 0; i < v->size; i++)
	{
		len += printf_s("%3d", i); //输出等长的横线
	}
	printf_s("\n");
	for (int i = 0; i < len; i++)printf_s("-");
	printf_s("\n");
	for (int i = 0; i < v->count; i++)
	{
		printf_s("%3d", v->data[i]);
	}
	printf_s("\n\n\n");
	return;
}

void clear(vector* v)
{
	if (v == NULL)return;
	free(v->data);
	free(v);
	return;
}

int insert(vector* v, int pos, int val)
{
	if (pos < 0 || pos > v->count) return 0;
	if (v->size == v->count)return 0;
	for (int i = v->count-1 ; i >= pos; i--)
	{
		v->data[i + 1] = v->data[i];
	}//逆序遍历
	v->data[pos] = val;
	v->count += 1;
	return 1;
}

int erase(vector* v, int pos)
{
	if (pos < 0 || pos >= v->count)return 0;
	for (int i = pos + 1; i < v->count; i++)
	{
		v->data[i - 1] = v->data[i];
	}
	v->count -= 1;
	return 1;
}

int main()
{
	srand(time(0));
#define MAX_OP 20
	vector* v = getNewvector(MAX_OP);
	for (int i = 0; i < MAX_OP; i++)
	{
		int pos, val;
		int op = rand() % 4 ;
		switch (op)
		{
		case 0:
		case 1:
		case 2:
			pos = rand() % (v->count + 2);
			val = rand() % 100;
			printf_s("insert %d at %d to vector = %d\n",
				val, pos, insert(v, pos, val));
			break;
		case 3:
			pos = rand() % (v->count + 2);//测试向非法擦除是否报错
			printf_s("erase item at %d in vector = %d\n",
				pos, erase(v, pos));
			break;
		}
		output_vector(v);
	}
	clear(v);
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
