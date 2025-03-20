
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX 1000
//typedef struct Stack
//{
//	char** str;
//	int size, top;
//}stack;
//
//stack* init_stack(int val)
//{
//	stack* st = (stack*)malloc(sizeof(stack));
//	st->str = (char**)malloc(sizeof(char*) * val);
//	st->size = val;
//	st->top = -1;
//	return st;
//}
//int empty(stack* st) {
//	return st->top == -1;
//}
//
//char* top(stack* st) {
//	if (empty(st))return NULL;
//	return st->str[st->top];
//}
//
//int push(stack* st, char* str1) {
//	if (st->top + 1 == st->size)return 0;
//	int len = 0;
//	len = strlen(str1);
//	st->top += 1;
//	st->str[st->top] = (char*)malloc(sizeof(char) * (len + 1));
//	strcpy_s(st->str[st->top],len+1,str1);
//	return 1;
//}
//
//int pop(stack* st) {
//	if (empty(st))return 0;
//	free(st->str[st->top]);
//	st->top -= 1;
//	return 1;
//}
//
//void clear_string(stack* st)
//{
//	for (int i = 0; i <= st->top; i++)
//		free(st->str[i]);
//}
//void clear_stack(stack* st)
//{
//	if (st == NULL)return;
//	clear_string(st);
//	free(st);
//	return;
//}
//
//void fun_call() {
//	int sum = 0;
//	scanf_s("%d", &sum);
//	getchar();
//	stack* st = init_stack(sum);
//	char str1[MAX];
//	const char* sr = "return";
//
//	for (int i = 0; i < sum; i++) {
//		scanf_s("%s", str1, (unsigned)_countof(str1));
//		if (strcmp(str1, sr) == 0)
//		{
//			pop(st);
//			continue;
//		}
//		push(st, str1);
//	}
//
//	scanf_s("%s", str1,(unsigned)_countof(str1));
//	int flag = 0;
//	while (!empty(st)) {
//		if (strcmp(str1, top(st)) == 0) {
//			flag = 1;
//			for (int i = 0; i < st->top; i++)
//			{
//				printf_s("%s->", st->str[i]);
//			}
//			break;
//		}
//		pop(st);
//	}
//	if (flag == 1)
//		printf_s("%s", str1);
//	else
//	printf_s("NOT REFERENCED");
//	clear_stack(st);
//}
//
//int main()
//{
//	fun_call();
//	return 0;
//}
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#define MAX_OPSIZE 1000 //指令最大长度
//#define INCREAMENT 500
//#define MAX_SIZE  100000
// 
//typedef struct Stack
//{
//	char** str;
//	int size, top;
//}stack;
//
//char** gets_commands(int n)
//{//读入n条指令
//	char** p = (char**)malloc(n * sizeof(char*));
//	if (!p) return NULL;
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = (char*)malloc(MAX_OPSIZE * sizeof(char));
//		scanf("%s", p[i]);
//	}
//	return p;
//}
//
//stack* init_stack(int val)
//{
//	stack* st = (stack*)malloc(sizeof(stack));
//	st->str = (char**)malloc(sizeof(char*) * val);
//	st->size = val;
//	st->top = -1;
//	return st;
//}
//
//char** string_init(char** s, int val)
//{
//	s = (char**)malloc(val * sizeof(char*));
//	if (!s)return 0;
//	for (int i = 0; i < val; i++)
//	{
//		s[i] = (char*)malloc(MAX_SIZE * sizeof(char));
//	}
//	return s;
//}
//
//int empty(stack* st) {
//	return st->top == -1;
//}
//
//char* top(stack* st) {
//	if (empty(st))return NULL;
//	return st->str[st->top];
//}
//
//int push(stack* st, char* str1) {
//	if (st->top + 1 == st->size)return 0;
//	int len = 0;
//	len = strlen(str1);
//	st->top += 1;
//	st->str[st->top] = (char*)malloc(sizeof(char) * (len + 1));
//	strcpy(st->str[st->top], str1);
//	return 1;
//}
//
//int pop(stack* st) {
//	if (empty(st))return 0;
//	free(st->str[st->top]);
//	st->top -= 1;
//	return 1;
//}
//
//void clear_string(stack* st)
//{
//	for (int i = 0; i <= st->top; i++)
//		free(st->str[i]);
//}
//
//
//int main()
//{
//	int n, flag = 0;
//	scanf("%d", &n);	char** ops = gets_commands(n);
//	if (!ops)return -1;
//	char target[MAX_OPSIZE];//目标指令
//	scanf("%s", target);
//
//	stack* st = init_stack(n);
//	
//	for (int i = 0; i < n; i++)
//	{
//		if (strcmp(ops[i], target) == 0)
//		{
//			push(st, target); flag = 1;
//			break;
//		}
//		if (strcmp(ops[i], "return") == 0)
//		{
//			pop(st);
//		}
//		else
//		{
//	      push(st, ops[i]);
//		}
//
//	}
//
//	if (flag)
//	{
//		for (int i = 0; i <=st->top ; i++)
//		{
//			if (i)printf("->");
//			printf("%s", st->str[i]);
//		}
//		printf("\n");
//	}
//	else printf("NOT REFERENCED\n");
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
typedef struct Stack
{
	char** str;
	int size, top;
}stack;

stack* init_stack(int val)
{
	stack* st = (stack*)malloc(sizeof(stack));
	st->str = (char**)malloc(sizeof(char*) * val);
	st->size = val;
	st->top = -1;
	return st;
}

char** string_init(char** s, int val)
{
	s = (char**)malloc(val * sizeof(char*));
	if (!s)return 0;
	for (int i = 0; i < val; i++)
	{
		s[i] = (char*)malloc(MAX_SIZE * sizeof(char));
	}
	return s;
}

int empty(stack* st) {
	return st->top == -1;
}

char* top(stack* st) {
	if (empty(st))return NULL;
	return st->str[st->top];
}

int push(stack* st, char* str1) {
	if (st->top + 1 == st->size)return 0;
	int len = 0;
	len = strlen(str1);
	st->top += 1;
	st->str[st->top] = (char*)malloc(sizeof(char) * (len + 1));
	strcpy(st->str[st->top], str1);
	return 1;
}

int pop(stack* st) {
	if (empty(st))return 0;
	free(st->str[st->top]);
	st->top -= 1;
	return 1;
}

void clear_string(stack* st)
{
	for (int i = 0; i <= st->top; i++)
		free(st->str[i]);
}

void fun_call() {
	int flag = 0;
	unsigned int sum = 0;
	scanf("%d", &sum);
	stack* st = init_stack(sum);
	char** str1;
	char target[1000];
	str1 = string_init(str1, sum);
	const char* sr = "return";

	for (int i = 0; i < sum; i++) {
		scanf("%s", str1[i]);
	}
	scanf("%s", target);
	for (int i = 0; i < sum; i++)
	{
		if (strcmp(str1[i], sr) == 0)
		{
			pop(st);

		}
		push(st, str1[i]);
		if (strcmp(str1[i], target) == 0) {
			flag = 1;
			push(st, str1[i]);
			break;
		}
		else {
			push(st, str1[i]);
		}
	}
	if (flag == 1) {

		for (int i = 0; i < st->top; i++)
		{
			if (i)printf("->");
			printf("%s", st->str[i]);
		}


	}


	else
		printf("NOT REFERENCED");

}

int main()
{
	fun_call();
	return 0;
}