#include<stdio.h>
#include<string.h>
#include "okmy.h"

void getNames(names* pn)
{
	printf_s("Enter the first name.\n");
	s_gets(pn->first, SLEN);
	printf_s("Enter the last name.\n");
	s_gets(pn->last, SLEN);
}

void show(const names* pn)
{
	printf_s("%s %s is a nice person.", pn->first, pn->last);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}