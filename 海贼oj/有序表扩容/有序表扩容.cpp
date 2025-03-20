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

int expand(vector* v)
{
	int* p;
	if (v == NULL) return 0;
	printf_s("expand v from %d to %d\n\n", v->size, 2 * v->size);
	p = (int*)realloc(v->data, sizeof(int)*2 * v->size);
	if (p == NULL)
		return 0;
	else
	{
		v->data = p;
		v->size *= 2;
	}
	return 1;
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
	if ((v->size == v->count) && !expand(v))
		return 0;
	for (int i = v->count - 1; i >= pos; i--)
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
	vector* v = getNewvector(2);
	for (int i = 0; i < MAX_OP; i++)
	{
		int pos, val,ret;
		int op = rand() % 4;
		switch (op)
		{
		case 0:
		case 1:
		case 2:
			pos = rand() % (v->count + 2);
			val = rand() % 100;
			ret = insert(v, pos, val);
			printf_s("insert %d at %d to vector = %d\n",
				val, pos, ret);
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