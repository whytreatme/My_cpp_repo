#pragma once

#define SLEN 40
struct name
{
	char first[SLEN];
	char last[SLEN];
};
typedef name names;
char* s_gets(char* st, int n);
void getNames(names*);
void show(const names*);
