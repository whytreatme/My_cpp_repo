#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct string {
	char** s;
	int size;
	int maxlenth;
	int top;
}string;
#define MAX_OPSIZE 1000 //指令最大长度
#define INCREAMENT 500
#define MAX_SIZE  100000
char** gets_commands(int n)
{//读入n条指令
	char** p = (char**)malloc(n * sizeof(char*));
	if (!p) return NULL;
	for (int i = 0; i < n; i++)
	{
		p[i] = (char*)malloc(MAX_OPSIZE * sizeof(char));
		scanf_s("%s", p[i]);
	}
	return p;
};


int string_init(string* s)
{
	s->s = (char**)malloc(MAX_SIZE * sizeof(char*));
	if (!s->s)return 0;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		s->s[i] = (char*)malloc(MAX_OPSIZE * sizeof(char));
	}
	s->size = 0; s->maxlenth = MAX_SIZE; s->top = -1;
	return 1;
};
int string_push(string* s, char* target)
{
	if (s->size >= s->maxlenth)
	{
		char** p = (char**)realloc(s->s, (s->maxlenth + INCREAMENT) * sizeof(char*));
		if (!p)return 0;
		s->s = p; s->maxlenth += INCREAMENT;
	}
	strcpy(s->s[++s->top], target);
	s->size++;
	return 1;
};

int string_pop(string* s)
{
	if (s->size == 0) return 0;
	s->top--;
	s->size--;
	return 1;
}




int main()
{
	int n, flag = 0;
	scanf_s("%d", &n);	char** ops = gets_commands(n);
	if (!ops)return -1;
	char target[MAX_OPSIZE];//目标指令
	scanf_s("%s", target);

	string s;
	string_init(&s);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ops[i], target) == 0)
		{
			string_push(&s, target); flag = 1;
			break;
		}
		if (strcmp(ops[i], "return") == 0)
		{
			string_pop(&s);
		}
		else
		{
			string_push(&s, ops[i]);
		}

	}

	if (flag)
	{
		for (int i = 0; i < s.size; i++)
		{
			if (i)printf_s("->");
			printf_s("%s", s.s[i]);
		}
		printf_s("\n");
	}
	else printf_s("NOT REFERENCED\n");
}