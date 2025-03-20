#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SLEN 1000
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
void clear_stack(stack* st)
{
	if (st == NULL)return;
	clear_string(st);
	free(st);
	return;
}
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

void fun_call() {
	unsigned int sum = 0;
	scanf_s("%d", &sum);
	stack* st = init_stack(sum);
	char str1[SLEN];
	const char* sr = "return";

	for (int i = 0; i < sum; i++) {
		s_gets(str1, SLEN);
		if (strcmp(str1, sr) == 0)
		{
			pop(st);
			continue;
		}
		push(st, str1);
	}

	s_gets(str1, SLEN);
	int flag = 0;
	while (!empty(st)) {
		if (strcmp(str1, top(st)) == 0) {
			flag = 1;
			for (int i = 0; i < st->top; i++)
			{
				printf_s("%s->", st->str[i]);
			}
			break;
		}
		pop(st);
	}
	if (flag == 1)
		printf_s("%s", str1);
	else
		printf_s("NOT REFERENCED");

}

int main()
{
	fun_call();
	return 0;
}
